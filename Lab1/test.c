#include<stdio.h>
#define SUCCESS 0

int main(int argc, char **argv){
    char c;
    printf("Enter a single Character\n");
    scanf("%c", &c);
    printf("Hello World %c!\n", c);
    return (SUCCESS);
}
