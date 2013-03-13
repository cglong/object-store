#include <stdlib.h>
#include <sqlite3.h>  
#include "db.h"

int open_fs_db(sqlite3 **db)
{
   return sqlite3_open(DB_FILENAME, db);
}

int init_fs_db(sqlite3 **db)
{
}

int add_file(sqlite3 **db, char *filename, char *path)
{
}

int remove_file(sqlite3 **db, char *filename);
{
}

int check_file(sqlite3 **db, char *filename);
{
}
