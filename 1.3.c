#include "error.c"
#include <dirent.h>
#include <errno.h>    /* for definition of errno */
#include <stdarg.h>   /* ISO C variable aruments */

static void err_doit(int, int, const char *, va_list);

int
main(int argc, char *argv[])
{
     DIR               *dp;
      struct dirent     *dirp;

  if(argc!=2)
    err_quit("usage: ls directory_name");

  if ((dp = opendir(argv[1])) == NULL)
    err_sys("can't open %s", argv[1]);
  while ((dirp = readdir(dp)) != NULL)
    printf("%s\n", dirp->d_name);

  closedir(dp);
  exit(0);
}

