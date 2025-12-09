#include "head.h"
#include <stdio.h>

int division(FDLL **head1, FDLL **tail1, FDLL **head2, FDLL **tail2, FDLL **head3, FDLL **tail3)
{

    if (*head1 == NULL || *head2 == NULL)
    {
        return FAILURE;
    }

    FDLL *tempHead = NULL, *tempTail = NULL;
    insert_value(&tempHead, &tempTail, 0);
    int count = 0;

    while (1)
    {
        FDLL *newTempHead = NULL, *newTempTail = NULL;

        addition(&tempHead, &tempTail, head2, tail2, &newTempHead, &newTempTail);
        int cmp = compare_num(newTempHead, *head1);
        // printf("CMP %d\n",cmp);

        if (cmp > 0)
        {
            
            // newTemp > dividend -> do not count this addition, free newTemp and stop
            free_list(&newTempHead, &newTempTail);
            break;
        }
        else if (cmp == 0)
        {
            // exact match: newTemp == dividend -> this addition is valid, count++ and stop
            count++;
            free_list(&tempHead, &tempTail); // free old temp
            tempHead = newTempHead;
            tempTail = newTempTail;
            break;
        }
        else
        {
            // newTemp < dividend -> accept it and continue
            count++;
            free_list(&tempHead, &tempTail); // free old temp
            tempHead = newTempHead;
            tempTail = newTempTail;
        }
    }

    printf("Result:\t%d\n", count);
    return SUCCESS;
}

void free_list(FDLL **head, FDLL **tail)
{
    FDLL *temp = *head;
    FDLL *next;

    while (temp)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL;
    *tail = NULL;
}
