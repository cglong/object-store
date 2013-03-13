#ifndef DB_OPS_H
#define DB_OPS_H

#include <sqlite3.h>

static const char *DB_FILENAME = "filedata.db";

int open_fs_db(sqlite3 **db);
int init_fs_db(sqlite3 **db);
int add_file(sqlite3 **db, char *filename, char *path);
int remove_file(sqlite3 **db, char *filename);
int check_file(sqlite3 **db, char *filename);

#endif
