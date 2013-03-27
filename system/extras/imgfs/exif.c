#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <libexif/exif-data.h>
#include <string.h>

#include "exif_ops.h"

static const int BUFFER_SIZE = 1024;

static void trim_spaces(char *buf)
{
	char *s = buf - 1;
	for (; *buf; ++buf)
		if (*buf != ' ')
			s = buf;
	*++s = 0;
}

static int get_tag(char *filename, ExifIfd ifd, ExifTag tag, char *buf)
{
	char s_buf[BUFFER_SIZE];
		
	ExifData *d = exif_data_new_from_file(filename);
	if (d == NULL)
		return -1;
	
	ExifEntry *entry = exif_content_get_entry(d->ifd[ifd], tag);
	if (entry) {
		exif_entry_get_value(entry, s_buf, sizeof(s_buf));
		trim_spaces(s_buf);
		strcat(buf, s_buf);
		exif_data_unref(d);
		return 0;
	} else {
		exif_data_unref(d);
		return -1;
	}
}

int get_latitude(char *filename, char *buf)
{
	return get_tag(filename, EXIF_IFD_0, EXIF_TAG_GPS_LATITUDE, buf);
}

int get_longitude(char *filename, char *buf)
{
	return get_tag(filename, EXIF_IFD_0, EXIF_TAG_GPS_LONGITUDE, buf);
}
