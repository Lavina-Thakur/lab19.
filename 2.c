#include<stdio.h>
#include<unistd.h>
#include<string.h>
void main(){
	int p[2],i,j,pid;
	char str[10][10],temp[10];
	printf("\n");
	printf("Enter strings:");//taking strings from the user
	for(i=0;i<10;i++){
		scanf("%s",str[i]);
	}

	pipe(p);//creating pipe
	pid=fork();//system call(process cration)
	if(pid==0){      //child process
			for(i=0;i<10;i++)
			write(p[1],str[i],10); //writing the string in end of pipe(p[1])
	}
	else{//parent process
		for(i=0;i<10;i++){
		read(p[0],str[i],10);//reading the string from pipe(p[0])
	}
	//this part will sort the string in ascendind order
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(strcmp(str[j],str[j+1])>0){
				strcpy(temp,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],temp);
			}
		}
	}
	///printing the strings
	printf("\n");
	printf("strings in sorted order:");
	for(i=0;i<10;i++){
		printf("%s\n",str[i]);
	}
	printf("\n\n");
}
}
