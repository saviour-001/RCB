#include<fcntl.h>
#include<unistd.h>
#include <stdio.h>
int main(){
    int src=open("sourc.txt",O_RDONLY);
    if(src==-1){
        // write(2,"Error opening source file",26);
        printf("error no file exists");
        return 1;
    }
    int dest=open("dust.txt",O_WRONLY|O_CREAT|O_TRUNC);
    if(dest==-1){
        // write(2,"Error writing destination file",31);
        printf("error no file exists");
        close(src);
        return 1;                   //copy contents from one to other
    }
    char ch;
    while(read(src,&ch,1)==1){
        write(dest,&ch,1);
    }
    close(src);
    close(dest);
    return 0;
}