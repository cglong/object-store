#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include "db.h"

#define FUSE_USE_VERSION 22

sqlite3 *db = NULL;

static int imgfs_getattr(const char *path, struct stat *stbuf)
{
    int res = 0;

    memset(stbuf, 0, sizeof(struct stat));
    if(strcmp(path, "/") == 0)
    {
        stbuf->st_mode = S_IFDIR | 0755;
        stbuf->st_nlink = 2;
    }
    else
    {
        res = -ENOENT;
    }

    return res;
}

static int imgfs_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
                         off_t offset, struct fuse_file_info *fi)
{
    (void) offset;
    (void) fi;

    if(strcmp(path, "/") != 0)
        return -ENOENT;

    filler(buf, ".", NULL, 0);
    filler(buf, "..", NULL, 0);

    return 0;
}

static int imgfs_open(const char *path, struct fuse_file_info *fi)
{
    return -ENOENT;
}

static int imgfs_read(const char *path, char *buf, size_t size, off_t offset,
                      struct fuse_file_info *fi)
{
    return -ENOENT;
}

static struct fuse_operations imgfs_oper = {
    .getattr	= imgfs_getattr,
    .readdir	= imgfs_readdir,
    .open	= imgfs_open,
    .read	= imgfs_read,
};

int main(int argc, char *argv[])
{
	open_fs_db(&db);
    return fuse_main(argc, argv, &imgfs_oper);
}
