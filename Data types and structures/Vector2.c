#include <stdio.h>

typedef struct Vector2{
    int x;
    int y;
}Vector2;

Vector2 vector2(int x, int y);

Vector2 vector2(int x, int y){
    Vector2 vec;
    vec.x = x;
    vec.y = y;
    return vec;
}

int main(){

    Vector2 my_vec = vector2(12, 5); // declaring a vector2
    printf("my vec x: %d y: %d\n", my_vec.x, my_vec.y);

    my_vec.y = 12;
    printf("my vec x: %d y: %d\n", my_vec.x, my_vec.y);

    return 0;
}