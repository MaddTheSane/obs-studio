#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_SFNT_NAMES_H
#include FT_TRUETYPE_IDS_H

#include <util/dstr.h>
#include <util/darray.h>

struct font_path_info {
	char    *face_and_style;
	size_t  full_len;
	size_t  face_len;

	bool    is_bitmap;
	size_t  num_sizes;
	int     *sizes;

	bool    bold;
	bool    italic;

	char    *path;
	FT_Long index;
};

static inline void font_path_info_free(struct font_path_info *info)
{
	bfree(info->sizes);
	bfree(info->face_and_style);
	bfree(info->path);
}

extern void build_font_path_info(FT_Face face, FT_Long idx, const char *path);
extern char *sfnt_name_to_utf8(FT_SfntName *sfnt_name);

extern void load_os_font_list(void);
extern void free_os_font_list(void);
extern const char *get_font_path(const char *family, const char *style,
		uint32_t flags, FT_Long *idx);