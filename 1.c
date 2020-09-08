#include<stdio.h>
#include<unistd.h>
void main()
{
   int pid,f[2];
   char str[30]="Hello World";
   pipe(f);
   pid=fork();      //
   pipe(f);//creating pipe
   pid=fork();      //system call(process cration)
   if(pid==0)    //child process
    {
      printf("\n");
     write(f[1],"Hello",15);   //
      write(f[1],str,15);  //writing the string in end of pipe(pipe[1])
      //write(f[1],"Hello",15);   //
      write(f[1],str,15);  //writing the string in end of pipe(f[1])
    }
    else     //parent process
    {
      printf("\n");
      read(f[0],str,15);
      printf("String=%s\n",str); //reading the string from pipe[0]
      read(f[0],str,15);//reading the string from pipe(f[0])
      printf("String=%s\n",str);
    }
}
