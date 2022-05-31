#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    struct Node *next;
} Node;

void createSecStructure(Node *mainStructure[], int position)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node aux;

    mainStructure[position] = newNode;
}

void insertValue(Node *position, int value)
{
    Node *current = (Node *)malloc(sizeof(Node));

    if (position == NULL)
        position->value = value;
    else
    {
        while (current->next != NULL)
        {

            current = current->next;
        }

        current->value = value;
    }
}

void main()
{
    Node *mainStructure[10];
    int size = 2, position = 0;
    int values[2] = {1,
                     2};

    for (int i = 0; i < 10; i++)
    {
        createSecStructure(mainStructure, i, size);
    }

    insertValue(mainStructure[position], values[0]);

    for (int i = 0; i < 10; i++)
    {
        printf("%d", mainStructure[i]->value);
        free(mainStructure[i]);
    }
}