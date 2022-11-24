;; Copyright (C) 2017 g10 Code GmbH
;;
;; This file is part of GnuPG.
;;
;; GnuPG is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 3 of the License, or
;; (at your option) any later version.
;;
;; GnuPG is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.
;;
;; You should have received a copy of the GNU General Public License
;; along with this program; if not, see <http://www.gnu.org/licenses/>.

(export all-tests
 ;; Parse the Makefile.am to find all tests.

 (load (with-path "makefile.scm"))

 (define (expander filename port key)
   (parse-makefile port key))

 (define (parse filename key)
   (parse-makefile-expand filename expander key))

 (define setup
   (make-environment-cache
    (test::scm
     #f
     #f
     (path-join "tests" "gpgsm" "setup.scm")
     (in-srcdir "tests" "gpgsm" "setup.scm")
     "--" "tests" "gpg")))

 (map (lambda (name)
	(test::scm setup
                   #f
		   (path-join "tests" "gpgsm" name)
		   (in-srcdir "tests" "gpgsm" name)))
      (parse-makefile-expand (in-srcdir "tests" "gpgsm" "Makefile.am")
			     (lambda (filename port key) (parse-makefile port key))
			     "XTESTS")))
