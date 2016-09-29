/* mime-maker.h - Create MIME structures
 * Copyright (C) 2016 g10 Code GmbH
 *
 * This file is part of GnuPG.
 *
 * GnuPG is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * GnuPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GNUPG_MIME_MAKER_H
#define GNUPG_MIME_MAKER_H

struct mime_maker_context_s;
typedef struct mime_maker_context_s *mime_maker_t;

gpg_error_t mime_maker_new (mime_maker_t *r_ctx, void *cookie);
void        mime_maker_release (mime_maker_t ctx);

void mime_maker_set_verbose (mime_maker_t ctx, int level);

void mime_maker_dump_tree (mime_maker_t ctx);

gpg_error_t mime_maker_add_header (mime_maker_t ctx,
                                   const char *name, const char *value);
gpg_error_t mime_maker_add_body (mime_maker_t ctx, const char *string);
gpg_error_t mime_maker_add_stream (mime_maker_t ctx, estream_t *stream_addr);
gpg_error_t mime_maker_add_container (mime_maker_t ctx);
gpg_error_t mime_maker_end_container (mime_maker_t ctx);

gpg_error_t mime_maker_make (mime_maker_t ctx, estream_t fp);



#endif /*GNUPG_MIME_MAKER_H*/
