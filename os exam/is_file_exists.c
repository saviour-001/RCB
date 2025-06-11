#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int a=open("int.txt",O_RDONLY|O_WRONLY | O_TRUNC);
    if(a==-1){
        perror("File doesnot exist");
        perror("Error truncating file");
        return 1;
    }
    printf("File exists and its length is now zero.\n");

    close(a);
    return 0;
}
