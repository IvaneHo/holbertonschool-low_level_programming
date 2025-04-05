#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int _putchar(char c);

int open_file_from(const char *filename);
int open_file_to(const char *filename);
void close_fd(int fd);
void copy_file(int fd_from, int fd_to, const char *file_to);

#endif /* MAIN_H */
