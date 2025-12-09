#include "head.h"
#include <stdio.h>

int multioplication(FDLL **head1, FDLL **tail1, FDLL **head2, FDLL **tail2, FDLL **head3, FDLL **tail3)
{
    if (*head1 == NULL || *head2 == NULL)
    {
        return FAILURE;
    }

    int carry = 0, data, shift = 0;

    FDLL *temp1 = *tail1;
    FDLL *temp2 = *tail2;
    FDLL *newTempHead = NULL;
    FDLL *newTempTail = NULL;
    FDLL *head4 = NULL;
    FDLL *tail4 = NULL;

    while (temp1 != NULL)
    {
        data = (temp2->data * temp1->data) + carry;
        carry = data / 10;

        insert_value(&head4, &tail4, data % 10);

        temp1 = temp1->prev;
    }
    if (carry > 0)
    {
        insert_value(&head4, &tail4, carry);
    }

    temp2 = temp2->prev;

    while (temp2 != NULL)
    {
        carry = 0;
        temp1 = *tail1;

        for (int i = 0; i <= shift; i++)
            insert_value(head3, tail3, 0);

        while (temp1 != NULL)
        {
            data = (temp2->data * temp1->data) + carry;

            carry = data / 10;

            insert_value(head3, tail3, data % 10);

            temp1 = temp1->prev;
        }

        if (carry > 0)
            insert_value(head3, tail3, carry);
        shift++;

        addition(&head4, &tail4, head3, tail3, &newTempHead, &newTempTail);

        free_list(head3, tail3);

        FDLL *swap = newTempHead;
        newTempHead = head4;
        head4 = swap;

        FDLL *swap1 = newTempTail;
        newTempTail = tail4;
        tail4 = swap1;

        free_list(&newTempHead, &newTempTail);

        temp2 = temp2->prev;
    }
    printf("Result:\t");
    print_list(head4);
}