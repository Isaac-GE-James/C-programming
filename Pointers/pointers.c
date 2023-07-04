#include <stdio.h>

typedef struct Some_Data {
    int num1;
    int num2;
} Some_Data;

int main(){

    Some_Data my_data;
    Some_Data *ptr = &my_data;

    my_data.num1 = 5; my_data.num2 = 6;
    printf("My data: %d, %d\n", my_data.num1, my_data.num2);

    Some_Data new_data;

    new_data.num2 = 17; 
    new_data.num1 = ptr->num1;
    printf("New data: %d, %d\n", new_data.num1, new_data.num2);

    return 0;
}