

#include <stdio.h>

#define MAXC 1024   /* if you need a constant, #define one (or more) */

int main(){

int a=0;
int b=0;
int c=0;

int bufferLength = 1024;
char buffer[bufferLength];

FILE *fp = fopen("file.txt", "r");
if (!fp){
    printf("Cant open file\n");
    return -1;
}

while(fgets(buffer, bufferLength, fp)) {
    //printf("%s\n", buffer);   
    if (3==sscanf(buffer, "%d %d %d", &a,&b,&c)){
        printf("a: %d   b: %d  c: %d \n", a,b,c);
    }
}

fclose(fp);
return 0;
}