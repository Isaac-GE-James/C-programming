#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *ptr;
} List;


int main(){

    List *my_list = malloc(sizeof(struct Node)); my_list->data = 5;

    struct Node *node1 = malloc(sizeof(struct Node)); node1->data = 17;
    struct Node *node2 = malloc(sizeof(struct Node)); node2->data = 18;

    my_list->ptr = node1;
    node1->ptr = node2;

    printf("%d, %d, %d", my_list->data, my_list->ptr->data, node1->ptr->data);

    return 0;
}