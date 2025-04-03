#ifndef IO_H
#define IO_H

#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters);

#endif /* IO_H */
