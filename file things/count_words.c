#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 256

int main() {
    char lines[1000][256];
    int lc=0;
    FILE *fp1;
    fp1=fopen("f1.txt","r");
    int words=0;
    int chrs=0;
    char ch,prev;    
    while((ch=fgetc(fp1))!=EOF){
        chrs++;
        if(ch=='\n' || ch==' ' || ch=='\t'){
            words++;
        }
        prev=ch;
    }
    fclose(fp1);
    if (chrs!=0 && prev!='\n'){
        printf("num of words are %d ",words+1);
    }
    else{
        printf("num of words are %d",words);
    }

    return 0;
}