#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
size_t _strlen(char *string);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void f_copy(int *fd_from, int *fd_to, char *from_pth, char *to_pth);

#endif
