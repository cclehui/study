#ifndef _IO_H
#define _IO_H

#define BUFFER_SIZE 1024

int myOpen(char *file , int type);
int myCopy(int s_fd , int d_fd);

void showUsage(int argc, char *argv[], char *usage);

#endif
