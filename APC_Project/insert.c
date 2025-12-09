#include "head.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FDLL *head1 = NULL;
FDLL *tail1 = NULL;
FDLL *head2 = NULL;
FDLL *tail2 = NULL;
FDLL *head3 = NULL;
FDLL *tail3 = NULL;

void insert_number(char *num, FDLL **head, FDLL **tail,int start)
{
    for (int i = strlen(num) - 1; i >= start; i--)
    {
        insert_value(head, tail, num[i] - '0'); // HERE
    }

    //print_list(*head);
}

int insert_value(FDLL **head1, FDLL **tail1, int data)
{
    FDLL *new = malloc(sizeof(FDLL));

    // check memory allocation to new
    if (!new)
    {
        return FAILURE;
    }

    new->data = data;
    new->prev = NULL; // since inserting at beginning

    // If list is empty
    if (*head1 == NULL)
    {
        new->next = NULL;
        *head1 = new;
        *tail1 = new;
        return SUCCESS;
    }

    // Insert at first list is non empty
    new->next = *head1;
    (*head1)->prev = new;
    *head1 = new;

    return SUCCESS;
}

void print_list(FDLL *head1)
{
    if (head1 == NULL)
    {
        printf("INFO : List is empty\n");
    }
    else
    {
        while (head1)
        {
            printf("%d ", head1->data);
            head1 = head1->next;
        }
        printf("\n");
    }
}