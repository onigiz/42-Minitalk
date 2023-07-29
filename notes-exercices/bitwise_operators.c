#include <stdio.h>

int main()
{
    // a = 00000101    b = 00001100 
    int a = 5; //00000101
    int b = 12; //00001100
    int c = 49; //00110001
    int d = 248; //11111000

    //printf("a: %d\nb: %d\n", a, b);

    //printf("(b >> 63): %lld\n", (b >> 63));

    //printf("(a << 5): %d\n", (a << 5));

    //printf("c = %d\n", ~c);

    //printf("(a^b: %d)\n", a ^ b); //00001001

    //printf("(a | b: %d)\n", a | b); //00001101  13

    //printf("(a & b: %d)\n", b & c); //00000000  0

    printf("~d: %d\n", ~d); //-249


    return 0;
}
