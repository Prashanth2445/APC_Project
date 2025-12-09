#include "head.h"
#include <stdio.h>

int addition(FDLL **head1, FDLL **tail1, FDLL **head2, FDLL **tail2, FDLL **head3, FDLL **tail3)
{
    int sum, data1, data2;

    if (*head1 == NULL || *head2 == NULL)
    {
        return FAILURE;
    }

    int carry = 0;
    FDLL *temp1 = *tail1;
    FDLL *temp2 = *tail2;

    while (temp1 != NULL || temp2 != NULL || carry != 0)
    {
        if (temp1 == NULL)
            data1 = 0;
        else
            data1 = temp1->data;
        if (temp2 == NULL)
            data2 = 0;
        else
            data2 = temp2->data;

        sum = data1 + data2 + carry;

        if (sum > 9)
            carry = 1;
        else
            carry = 0;

        // sum=sum%10;
        insert_value(head3, tail3, sum % 10);

        // printf("sum= %d ", sum);
        if (temp1 != NULL)
            temp1 = temp1->prev;

        if (temp2 != NULL)
            temp2 = temp2->prev;
        // printf("\n");
    }
    // print_list(*head3);
    return SUCCESS;
}