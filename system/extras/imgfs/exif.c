#define _XOPEN_SOURCE

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <libexif/exif-data.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#include "exif_ops.h"

int get_exif_path(char *filename, char *buf, unsigned int len)
{
   struct tm ti;
   ExifData *edata = exif_data_new_from_file(filename);
   if(edata == NULL)
   {
      /* the file has no exif data */
      return -1;
   }
   ExifEntry *d_entry = exif_content_get_entry(edata->ifd[EXIF_IFD_0],EXIF_TAG_DATE_TIME);
   exif_entry_get_value(d_entry, buf, BUFFER_SIZE);
   strptime(buf, "%Y:%m:%d %H:%M:%S", &ti);
   buf[0] = '\0';
   strftime(buf, BUFFER_SIZE, "/%Y/%B/%d", &ti);
   return 0;
}

int get_nonexif_path(char *filename, char *buf, unsigned int len)
{
   struct stat f_st;
   struct tm *time;
   stat(filename, &f_st); 
   if(&f_st == NULL)
   {
      printf("unable to get file stat\n");
   }
   time = localtime(&(f_st.st_ctime));
   strftime(buf, len, "%Y/%B/%d", time);
   return 0;
}

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
