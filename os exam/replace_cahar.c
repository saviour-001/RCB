#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
    int a=open("input.txt",O_RDWR);
    if(a==-1){
        perror("Error opening file");
        return 1;
    }
    char ch,s,b='*';
    printf("Enter character to be replaced:");
    scanf(" %c",&s);
    while(read(a,&ch,1)==1){
        if(ch==s){
            lseek(a,-1,SEEK_CUR);
            write(a,&b,1);
        }
    }
    printf("\nReplaced successfully");
    close(a);
    return 0;
}