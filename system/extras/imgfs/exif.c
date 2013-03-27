#define _XOPEN_SOURCE

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <libexif/exif-data.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#include "exif_ops.h"

static const int BUFFER_SIZE = 1024;

int get_xy_res_path(char *filename, char *buf, unsigned int len)
{
   char s_buf[BUFFER_SIZE];
   s_buf[0] = '\0';
   buf[0] = '\0';
   strcat(buf, "/Resolution/");
   ExifData *edata = exif_data_new_from_file(filename);
   if(edata == NULL)
   {
      /* the file has no exif data */
      return -1;
   }
   ExifEntry *d_entry = exif_content_get_entry(edata->ifd[EXIF_IFD_0],EXIF_TAG_X_RESOLUTION);
   exif_entry_get_value(d_entry, s_buf, BUFFER_SIZE);
   strcat(buf, s_buf);
   strcat(buf, "X");
   d_entry = exif_content_get_entry(edata->ifd[EXIF_IFD_0],EXIF_TAG_Y_RESOLUTION);
  strcat(buf, s_buf);
   return 0;
}
