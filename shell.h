#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFSIZE 10240

extern char **environ;

int _putchar(char c);
int _strcmp(char *s1, char *s2);
int _exec(char **argv);
void getpath(char **env, char **argv, char **shellName);
int exitsh(char *argv[], char *line);
char *_strcpy(char *dest, char *src)
char *_strcat(char *dest, char *src);
char *_strdup(char *src);
char *_memcpy(char *dest, char *src, unsigned int n);
int _puts(char *c);
int _putstr(char *c);
int _strlen(char *c);
char *_getLine();
void remove_Hashtag(char *str);
int _atoi(char *s);
void unsignedPrint(unsigned int num);
void numPrint(int num);
int printEcho(char **param);
int _strncmp(const char *s1, const char *s2, size_t l);
char *_getenv(char *param);
int echoSpecial(char **comm, int a);

#endif
