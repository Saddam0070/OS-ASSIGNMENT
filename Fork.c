#include<stdio.h>
#include<sys/types.h>
int main()
{
printf("Welcome to parent and child process\n");
int p=0;
pid t pid;
do
{
printf("Please Enter the Number\n");
scanf("%d",&p);
}
while(p<=0)
pid=fork();
if(pid==0)
{
printf("Child Process\n");
printf("%d\n",p);
while(p!=1)
{
if(p%2==0)
{
p=p/2;
}
else if(p%2==1)
{
p=3*(p)+1;
}
printf("%d\n",p);
}
printf("Child process is here\n");
}
else
{
printf("Here the parent is waiting for the child process\n");
wait();
printf("Parent process is completed\n");
}
return 0;
}
