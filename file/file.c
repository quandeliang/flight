#include"file.h"

bool my_write_file(char *buf){
      int fd,ret;
      if((fd=open("ifnoflight",O_WRONLY|O_CREAT|O_APPEND,0644))==-1){
	    perror("open_flightifno");
	    exit(EXIT_FAILURE);
      }
      if((ret==write(fd,buf,strlen(buf)))==-1){
	    perror("open_flightifno");
	    exit(EXIT_FAILURE);
      }
      close(fd);
      if(ret==strlen(buf))
	    return true;
      else 
	    return false;
}
bool my_read_file(char *buf){
      return true;
}
void sort_file(void){;}
void show_fileifno(void){;}
bool empty_fileifno(void){
      return true;
}
