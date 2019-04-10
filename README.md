# OS-ASSIGNMENT
Que 1]
Write a C program using the fork() system call that generates this sequence in the child
process. The starting number will be provided from the user. For example, if 8 is passed
as a parameter on the command line, the child process will output 8, 4, 2, 1. Because the
parent and child processes have their own copies of the data, it will be necessary for the
child to output the sequence. Have the parent invoke the wait() call to wait for the child
process to complete before exiting the program. Perform necessary error checking to
ensure that a positive integer is passed on the command line. 

[PROGRAM]

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
printf("welcome to parent & child process\n");
int p=0;
pid_t pid;
               
do
	{
	printf("Please enter the Number\n"); 
  			scanf("%d", &p);	
		}while (p <= 0);

		pid = fork();
		if (pid == 0)
		{
			printf("Child Process\n");
			printf("%d\n",p);
			while (p!=1)
			{
				if (p%2 == 0)
				{
					p = p/2;
				}
				else if (p%2 == 1)
				{
					p= 3 * (p) + 1;
				}	
			
				printf("%d\n",p);
			}
		
			printf("Child process is here\n");
		}
		else
		{
			printf("Here the parent is waiting for the child process\n");
			wait();
			printf("Parent  process is completed\n");
		}
	return 0; 
}


Que 2]
Design a file-copying program named filecopy using ordinary pipes. This program will
be passed two parameters: the name of the file to be copied and the name of the copied
file. The program will then create an ordinary pipe and write the contents of the file to be
copied to the pipe. The child process will read this file from the pipe and write it to the
destination file. For example, if we invoke the program as follows:
filecopy input.txt copy.txt
The file input.txt will be written to the pipe. The child process will read the contents of
this file and write it to the destination file copy.txt. 

[Program]

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h> 
#include <fcntl.h> 

int main (int arg, char *arg_v[]) {
    int pipefd[2]; 
    int filelen;
    char buff[100];
    char childBuff[100];
   
if (arg!= 3) {
      printf("File copied: file.exe\n");
      exit(1);
    }
    
    char* srcFile = arg_v[1];
    char* dstFile = arg_v[2];

 if (pipe(pipeFd) < 0) {
      printf("wrong in creating the file%s\n", strerror(errno));
      exit(1);
    }
    switch(fork()) {

      case -1:
        printf("Error in forking the child process  %s\n", strerror(errno));
        exit(1);
      
      case 0: 
        close(pipeFd[1]);                                                       
        ssize_t (num_bytes_child = read(pipeFd[0], childBuff, sizeof(childBuff));  
        close(pipeFd[0]);                               

        int targetDesc = open(dstFile, O_CREAT | O_WRONLY);                                
        write(targetDesc, childBuff, num_bytes_child);                            
        

      
default: 
        close(pipeFd[0]);                    
        int fileInDesc = open(srcFile, O_RDONLY); 
        ssize_t num_bytes = read(fileInDesc, buffer, sizeof(buffer));
        write(pipeFd[1], buffer, num_bytes);                           
        close(pipeFd[1]);                                            
}
 return 0;
}



