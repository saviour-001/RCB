#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(){
    int a=open("input.txt",O_WRONLY|O_APPEND);
    if(a==-1){
        perror("Errro opening file");
        return 1;
    }
    char *lines[]={"\nThis is line1\n","This is line2\n","This is line3\n"};
    for(int i=0;i<3;i++){
        write(a,lines[i],strlen(lines[i]));
    }
    close(a);
    printf("\nLines are appended successfully");
    return 0;
}