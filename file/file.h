#ifndef __FILE_SEQ_H__
#define __FILS_SEQ_H__

#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include"../kernellist/doublelist.h"
#define MY_BUFSIZ 512

extern bool my_write_file(char* buf);
extern bool my_read_file(char* buf);
extern void show_fileifno(void);
extern bool search_fileifno(void);
extern bool del_fileifno(void);
extern void sort_file(void);
extern bool empty_filefino(void);
#endif
