#include<stdlib.h>
#include<stdio.h>

struct node1
{
 int value;
 struct node1 *left, *right;
};

typedef struct node1 node;

node *head = NULL;

void AddNode(node ** n, int value)
{
    if((*n) == NULL)
    {
        (*n) = malloc(sizeof(node));
        (*n)-> value = value;
        return;
    }

    if(value < (*n)->value)
    {
        AddNode(&(*n)->left, value);
    }
    else if (value > (*n)->value)
    {
        AddNode(&(*n)->right, value);
    }
}

void Add(int value)
{
    if(head == NULL)
    {
        node *n = malloc(sizeof(node));
        n->value = value;
        head = n;
    }
    else
    {
        AddNode(&head, value);
    }
}

void print(node **n)
{
    if((*n)->left != NULL)
        print(&(*n)->left);

    printf("%i ", (*n)->value);

    if((*n)->right != NULL)
        print(&(*n)->right);
}

int main()
{

 Add(10);
 Add(15);
 Add(5);
 Add(13);
 Add(14);

 print(&head);
 return 0;
}
