//  APC project

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "head.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("ERROR: Invalid input\n");
        printf("INFO: please give the command line arguments -> <num1> <operator> <num2>\n");
        return FAILURE;
    }
    char *num1 = argv[1];
    char *num2 = argv[3];

    int sign1, sign2;   // Signs of numbers
    int start1, start2; // Index to start after detecting sign
    int negative = 0;

    if (num1[0] == '-')
    { // num1 negative number.
        sign1 = -1;
        start1 = 1;
    }
    else if (num1[0] == '+')
    { // num1 positive number.
        sign1 = 1;
        start1 = 1;
    }
    else
    { // num1 explicitly positive number.
        sign1 = 1;
        start1 = 0;
    }

    if (num2[0] == '-')
    {
        sign2 = -1;
        start2 = 1;
    }
    else if (num2[0] == '+')
    {
        sign2 = 1;
        start2 = 1;
    }
    else
    {
        sign2 = 1;
        start2 = 0;
    }

    insert_number(num1, &head1, &tail1, start1);
    insert_number(num2, &head2, &tail2, start2);

    switch (*argv[2])
    {
    case '+':
        printf("Addition started\n");
        printf("Num1:\t");
        print_list(head1);
        printf("Num2:\t");
        print_list(head2);
        if (sign1 == sign2)
        {
            addition(&head1, &tail1, &head2, &tail2, &head3, &tail3);
        }
        else
        {
            int cmp = compare_num(head1, head2);

            if (cmp == 0) // Both numbers equal
            {
                insert_value(&head3, &tail3, 0); // Result = 0
                negative = 0;
            }
            else if (cmp > 0) // num1 > num2
            {
                subtraction(&head1, &tail1, &head2, &tail2, &head3, &tail3);
                negative = (sign1 == -1);
            }
            else // num2 > num1
            {
                swap_number(&head1, &tail1, &head2, &tail2); // Swap to subtract correctly
                subtraction(&head1, &tail1, &head2, &tail2, &head3, &tail3);
                negative = (sign2 == -1);
            }
        }
        // display(head1, head2, head3, negative);
        printf("Result:\t");
        if (negative) // Print minus sign if needed
            printf("-");
        print_list(head3);
        printf("INFO: Addition Successfully Done\n");
        break;
    case '-':

        printf("Substraction started\n");
        printf("Num1:\t");
        print_list(head1);
        printf("Num2:\t");
        print_list(head2);
        sign2 = -sign2; // Flip sign of second number

        if (sign1 == sign2) // Same sign after flipping → addition
        {
            addition(&head1, &tail1, &head2, &tail2, &head3, &tail3);
            negative = (sign1 == -1);
        }
        else // Otherwise subtraction
        {
            int cmp = compare_num(head1, head2);

            if (cmp == 0) // Equal numbers
            {
                insert_value(&head3, &tail3, 0); // Result = 0
                negative = 0;
            }
            else if (cmp > 0) // num1 > num2
            {
                subtraction(&head1, &tail1, &head2, &tail2, &head3, &tail3);
                negative = (sign1 == -1);
            }
            else // num2 > num1
            {
                swap_number(&head1, &tail1, &head2, &tail2); // Swap to subtract safely
                subtraction(&head1, &tail1, &head2, &tail2, &head3, &tail3);
                negative = (sign2 == -1);
            }
        }
        printf("Result:\t");
        if (negative) // Print minus sign if needed
            printf("-");
        print_list(head3);
        printf("INFO: Substraction Successfully Done\n");
        break;

    case 'X':
    case 'x':

        printf("Multiplication started\n");
        printf("Num1:\t");
        print_list(head1);
        printf("Num2:\t");
        print_list(head2);
        if (multioplication(&head1, &tail1, &head2, &tail2, &head3, &tail3) == SUCCESS)
        {
            printf("INFO: Addition Successfully Done\n");
        }

        break;

    case '/':
        printf("Division started\n");
        printf("Num1:\t");
        print_list(head1);
        printf("Num2:\t");
        print_list(head2);
        if (division(&head1, &tail1, &head2, &tail2, &head3, &tail3) == SUCCESS)
        {
            // print_list(head);
            printf("INFO: Division Successfully Done\n");
        }

        break;

    default:
        printf("Enter the proper input\n");

        break;
    }
}
