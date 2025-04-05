#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

int main(int ac, char **av); /* pour 3-cp.c */

void print_error(int code, const char *msg, const char *arg); /* si utilisée */
void safe_close(int fd); /* ou close_file, selon ton nom */
int _putchar(char c); /* obligatoire même si inutilisé */

#endif /* MAIN_H */
