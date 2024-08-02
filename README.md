# get_next_line

![Language: C](https://img.shields.io/badge/Language-C-blue.svg)
![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)

## Introduction

`get_next_line` is a custom implementation of a function that reads a line from a file descriptor. This project will not only allow you to add a very convenient function to your collection, but it will also teach you about the highly interesting concept of static variables in C programming.

## Features

- Reads a line from a file descriptor.
- Handles multiple file descriptors simultaneously.
- Returns `NULL` if there is nothing else to read or if an error occurred.

## Usage

Here is an example of using `get_next_line` in a C program:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return (0);
}
```

## Screenshot

<img width="218" alt="Capture d’écran 2024-08-02 à 02 34 22" src="https://github.com/user-attachments/assets/980c6c48-5ee2-4e4c-afc2-58dd05597696">
