#ifndef __EXIF_H__
#define __EXIF_H__

static const int BUFFER_SIZE = 1024;

int get_exif_path(char *filename, char *buf, unsigned int len);
int get_nonexif_path(char *filename, char *buf, unsigned int len);
int get_xy_res_path(char *filename, char *buf, unsigned int len);

#endif
