#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
void main()
{
  int fp[2],a;
  char ch[12];
//char ch1[12]="";
  pipe(fp); //creating pipe
  a=fork(); //system call(process cration)
  if(a==0)  //child process
  {
    printf("child id=%d\n",getpid());//printing id
    fp[1]=open("d.txt",O_WRONLY); //opening file d.txt  open in write only mode
    write(fp[1],"Hello World",12);// writing in the file(through pipe) 
    close(fp[1]);//closing fp[1]
  }
  else  //parent process
  {
//wait(NULL);
    printf("parent id=%d\n",getpid());//printing id
    fp[0]=open("d.txt",O_RDONLY);// opening the file d.txt  in read only mode
    read(fp[0],ch,12); //reading from the file
    printf(" =%s",ch); //printing the content of the file
    close(fp[0]);//closing fp[0]
  }
}

