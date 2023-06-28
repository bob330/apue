#include "error.c"
#include <fcntl.h>
#define FILE_SIZE 19394

char buf1[] = "a";

int
main (void)
{
	int fd;
	int i;
	if ((fd = creat("file.nohole", FILE_MODE)) < 0)
		err_sys("creat error");
	for (i = 0; i < FILE_SIZE; i ++)
	{
		if (lseek(fd, i, SEEK_SET) == -1)
			err_sys("lseek error");

		if (write(fd, buf1, 1) != 1)
			err_sys("buf1 write error");
	}

	exit(0);
}
