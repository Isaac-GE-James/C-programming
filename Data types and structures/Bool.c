#include <stdio.h>

typedef enum Bool {
    FALSE,
    TRUE
} Bool;

int main(){

    Bool my_bool = FALSE; // declaring the bool

    printf("My bool = %d\n", my_bool);

    my_bool = TRUE;
    printf("My bool = %d\n", my_bool);

    if(my_bool == TRUE) {printf("My bool is TRUE");}
    else {printf("My bool is FALSE");}

    return 0;
}