#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    char file1[10],file2[10];
    int count = 0;
    printf("File name:");
    scanf("%s",file1);  
    FILE *f1 = fopen(file1, "r");
    if(f1 == NULL)
    {
        printf("File not found");
        return 1;
    }
    char ch,prev;
    do{
        ch = fgetc(f1);
        if(isspace(ch)|| ch == '\n' || ch == '\t'|| prev == '.'){
            count++;
            prev = ch;
            printf("%c\n",ch);
        }
    }while(ch != EOF);
    printf("No. of words = %d",++count);
    fclose(f1);
}