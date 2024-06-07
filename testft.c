#include "get_next_line.h"
#include <stdio.h>

int main()
{
    char *buffer = (char *)ft_calloc(10 + 1, sizeof(char));
    if (!buffer)
        return -1;
    ft_memcpy(buffer, "ouais\ntest", 10);
    char *line = ft_next_line(buffer);
    printf("Returned line: %s", line);
    free(line);

    free(buffer);
    return 0;
}