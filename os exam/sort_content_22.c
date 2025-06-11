#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
void sort(char* arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                char temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main(){
int a=open("fd1.txt",O_RDONLY);
if(a==-1){
    perror("Error opening file");
    return 1;
}
char buffer[1024];
int n=read(a,buffer,sizeof(buffer)-1);
close(a);
if(n<=0){
    perror("Error reading file");
    return 1;
}
buffer[n]='\0';
sort(buffer,n);

 a=open("fd1.txt",O_WRONLY|O_TRUNC);
if(a==-1){
    perror("Error opening file");
    return 1;
}
write(a,buffer,n);
close(a);
printf("File contents are sorted");
return 0;
}   