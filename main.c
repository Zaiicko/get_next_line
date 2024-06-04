#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int	fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}