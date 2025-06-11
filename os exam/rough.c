//------ece+q4333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333



// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <ctype.h>

// // int main() {
// //     int src = open("src.txt",O_RDONLY);
// //     if(src==-1){
// //         // write(2,"error opening sf");
// //         printf("error file doesnt exists");
// //         return 1;
// //     }
// //     int dest = open("dust.txt",O_WRONLY|O_CREAT|O_TRUNC);
// //     if(dest == -1){
// //         // write(2,"error opening dest");
// //         printf("error file doesnt exists");
// //         close(src);
// //         return 1;
// //     }
// //     char ch;
// //     while(read(src,&ch,1)==1){
// //         write(dest,&ch,1);
// //     }
// //     close(src);
// //     close(dest);
// //     return 0 ;
// // }

// int main(){
//     int charecters = 0 ,words =0 , lines = 0;
//     char ch , last_char = '\0';
//     int inword = 0;
//      x= open("sourc.txt",O_RDONLY);
//     if(x == -1){
//         printf("file not found");
//         return -1;
//     }
//     while(read(x,&ch,1)==1){
//         charecters++;
//         if(ch == '\n'){
//             lines++;
//         }
//         if(isspace(ch)){
//             if(inword){
//                 words++;
//                 inword = 0;
//             }
//         }
//         else{
//             inword = 1;
//         }
//     }
//     if(inword){
//         words++;
//     }
//     if(charecters>0 && ch != '\n'){
//         lines++;
//     }
//     close(x);
//     printf("number of charecters : %d\n",charecters);
//     printf("words : %d\n",words);
//     printf("no of lines :%d",lines);
//     return 0;
// }

