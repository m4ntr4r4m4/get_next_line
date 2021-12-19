#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*buf;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("\nfailed to create fd\n");
		exit(1);
	}
	printf("this is fd: %d", fd);	
	buf = get_next_line(fd);
	printf("this is my get next line : %s\n", buf);
	buf = get_next_line(fd);
	printf("this is my get next line 2: %s\n", buf);
	buf = get_next_line(fd);
	printf("this is my get next line 3: %s\n", buf);
	buf = get_next_line(fd);
	printf("this is my get next line 4: %s\n", buf);
	buf = get_next_line(fd);
	printf("this is my get next line 5: %s\n", buf);
	buf = get_next_line(fd);
	printf("this is my get next line 6: %s\n", buf);
	buf = get_next_line(fd);
	printf("this is my get next line 7: %s\n", buf);
	buf = get_next_line(fd);
	printf("this is my get next line 8: %s\n", buf);
	buf = get_next_line(fd);
	printf("this is my get next line 9: %s\n", buf);
	buf = get_next_line(fd);
	printf("this is my get next line 10: %s\n", buf);
	buf = get_next_line(fd);
	printf("this is my get next line 11: %s\n", buf);
	buf = get_next_line(fd);
	printf("this is my get next line 12: %s\n", buf);
	buf = get_next_line(fd);
	printf("this is my get next line 13: %s\n", buf);


	close(fd);
	
	return (0);
}
