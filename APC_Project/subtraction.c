#include "head.h"
#include <stdio.h>

int subtraction(FDLL **head1, FDLL **tail1, FDLL **head2, FDLL **tail2, FDLL **head3, FDLL **tail3)
{
    int dif, data1, data2;

    if (*head1 == NULL || *head2 == NULL)
    {
        return FAILURE;
    }

    int cmp = compare_num(*head1, *head2);

    if (cmp < 0)
    {
        swap_number(head1,tail1,head2,tail2);
    }
    if (cmp == 0)
    {
        insert_value(head3, tail3, 0);
        return SUCCESS;
    }

    int barrow = 0;
    FDLL *temp1 = *tail1;
    FDLL *temp2 = *tail2;

    while (temp1 != NULL || temp2 != NULL)
    {
        if (temp1 == NULL)
            data1 = 0;
        else
            data1 = temp1->data;
        if (temp2 == NULL)
            data2 = 0;
        else
        {
            data2 = temp2->data;
        }

        // previous borrow
        data1 = data1 - barrow;
        barrow = 0;

        if (data1 < data2)
        {
            data1 = data1 + 10;
            barrow = 1;
        }

        dif = data1 - data2;

        insert_value(head3, tail3, dif);

        // printf("sum= %d ", dif);
        if (temp1 != NULL)
        {
            temp1 = temp1->prev;
        }
        if (temp2 != NULL)
        {
            temp2 = temp2->prev;
        }
    }
    // print_list(*head3);
    return SUCCESS;
}

int compare_num(FDLL *head1, FDLL *head2)
{
    int len1 = 0, len2 = 0;
    FDLL *t1 = head1;
    FDLL *t2 = head2;

    while (t1)
    {
        len1++;
        t1 = t1->next;
    }
    while (t2)
    {
        len2++;
        t2 = t2->next;
    }

    if (len1 < len2)
        return -1;
    if (len1 > len2)
        return 1;

    t1 = head1;
    t2 = head2;

    while (t1 && t2)
    {
        if (t1->data < t2->data)
            return -1;
        if (t1->data > t2->data)
            return 1;

        t1 = t1->next;
        t2 = t2->next;
    }
    return 0;
}

int swap_number(FDLL **head1, FDLL **tail1, FDLL **head2, FDLL **tail2)
{
    FDLL *temp = *head1;
    *head1 = *head2;
    *head2 = temp;

    temp = *tail1;
    *tail1 = *tail2;
    *tail2 = temp;
}