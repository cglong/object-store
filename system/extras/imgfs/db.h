#ifndef __DB_H__
#define __DB_H__

#include <sqlite3.h>

static const char *DB_FILENAME = "filedata.db";

int open_fs_db(sqlite3 **db);
int add_file(sqlite3 **db, char *filename, char *path);
int remove_file(sqlite3 **db, char *filename);
int check_file(sqlite3 **db, char *filename);

#endif
