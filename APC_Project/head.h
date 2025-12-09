#ifndef HEAD_H
#define HEAD_H
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} FDLL;
extern FDLL *head1;
extern FDLL *tail1;
extern FDLL *head2;
extern FDLL *tail2;
extern FDLL *head3;
extern FDLL *tail3;

// insert the first number argv[2]
void insert_number(char *num, FDLL **head, FDLL **tail, int start);

// inserting one by one digit in nodes
int insert_value(FDLL **head1, FDLL **tail1, int num);

// print nodes
void print_list(FDLL *head1);

// addition operation
int addition(FDLL **head1, FDLL **tail1, FDLL **head2, FDLL **tail2, FDLL **head3, FDLL **tail3);

// subtraction operation
int subtraction(FDLL **head1, FDLL **tail1, FDLL **head2, FDLL **tail2, FDLL **head3, FDLL **tail3);

int compare_num(FDLL *head1, FDLL *head2);

int division(FDLL **head1, FDLL **tail1, FDLL **head2, FDLL **tail2, FDLL **head3, FDLL **tail3);

int multioplication(FDLL **head1, FDLL **tail1, FDLL **head2, FDLL **tail2, FDLL **head3, FDLL **tail3);

void free_list(FDLL **head, FDLL **tail);

int insert_at_end(FDLL **head, FDLL **tail, int data);

void reverse_list(FDLL **head, FDLL **tail);

int swap_number(FDLL **head1, FDLL **tail1, FDLL **head2, FDLL **tail2);

int display(FDLL *head1, FDLL *head2, FDLL *head3, int negative);

#endif