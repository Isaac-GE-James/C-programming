#include <stdio.h>
#include <dos.h>

int main(){

    sound(400);

    delay(1000);

    nosound();

    return 0;
}