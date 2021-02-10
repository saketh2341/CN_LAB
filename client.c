#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include <sys/uio.h>
#include<string.h>
#include<errno.h>
  
int main() 
{ 


  int fd=open("sum",O_WRONLY);
  if(fd==-1){
      return 1;
  }
    char str0[10];
           char str1[10];
           struct iovec iov[2];
           ssize_t nwritten;

           iov[0].iov_base = str0;
           iov[0].iov_len = strlen(str0);
           iov[1].iov_base = str1;
           iov[1].iov_len = strlen(str1);
            
            scanf("%s\n",str0);
            scanf("%s\n",str1);
            writev(fd, iov, 2);
            printf("%s",(char *)iov[0].iov_base);
            

  close(fd);
    return 0; 
} 