#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
int main(int arg, char *arg_v[])
{
int pipefd[2];
int filelen;
char buff[100];
char childBuff[100];
if(arg!=3)
{
printf("File copied:file.exe\n");
exit(1);
}
char* srcFile=arg_v[1];
char* dstFile=arg_v[2];
if(pipe(pipeFd)<0)
{
printf("Wrong in creating the file%s\n",strerror(errno));
exit(1);
}
switch(fork())
{
case -1:
printf("Error in forking the child process%s\n"strerror(errno));
exit(1);
case 0:
close(pipeFd[1]);
ssize_t(num_bytes_child=read(pipeFd[0],childBuff,sizeof(childBuff));
close(pipeFd[0]);
int targetDesc=open(dstFile,O_CREAT | O_WRONLY);
write(targetDesc,childBuff,num_bytes_child);
default:
close(pipeFd[0]);
int fileInDesc=open(srcFile,O_RDONLY);
ssize_t num_bytes=read(fileInDesc,buffer,sizeof(buffer));
write(pipeFd[1],buffer,num_bytes);
close(pipeFd[1]);
}
return 0;
}
