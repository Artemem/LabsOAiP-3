#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    srand(time(NULL));
    int arr1_choice;
    int randnum1, randnum2;
    int ind;
    printf("If you want put numbers into first array by hands input 1 or random numbers - 0: ");
    while (scanf_s("%d", &arr1_choice) != 1 || arr1_choice != 1 && arr1_choice != 0)
    {
        printf("Try again\nIf you want put numbers into first array input 1 else 0: ");
        rewind(stdin);
    }
    int array1[100];
    int n_in_arr1;
    printf("Enter the number of first array elements[1-100]: ");
    while (scanf_s("%d", &n_in_arr1) != 1 || n_in_arr1 > 100 || n_in_arr1 < 1)
    {
        printf("Try again\nEnter the number of first array elements[1-100]: ");
        rewind(stdin);
    }
    if (arr1_choice == 1)
        printf("Enter numbers in ascending order\n");

    if (arr1_choice == 0)
    {
        for (ind = 0; ind < n_in_arr1; ind++)
        {
            randnum1 = rand() % 101;
            randnum2 = rand() % 101;
            array1[ind] = (randnum1 - randnum2);
        }
        for (ind = 0; ind < n_in_arr1 - 1; ind++)
        {
            for (int ind1 = 0; ind1 < n_in_arr1 - ind - 1; ind1++)
            {
                if (array1[ind1] > array1[ind1 + 1])
                {
                    int flag1 = array1[ind1];
                    array1[ind1] = array1[ind1 + 1];
                    array1[ind1 + 1] = flag1;

                }
            }
        }
    }
    else
    {
        for (ind = 0; ind < n_in_arr1; ind++)
        {
            printf("%d number: ", ind + 1);
            while (scanf_s("%d", &array1[ind]) != 1 || (ind>0 && array1[ind] <= array1[ind - 1]))
            {
                printf("try again\n%d number: ", ind + 1);
                rewind(stdin);
            }
        }
    }
    printf("Input first array: {");
    for (ind = 0; ind < n_in_arr1; ind++)
    {
        printf("%d, ", array1[ind]);
    }
    printf("}");



    int arr2_choice;
    printf("\nIf you want put numbers into second array input 1 else 0: ");
    while (scanf_s("%d", &arr2_choice) != 1 || arr2_choice != 1 && arr2_choice != 0)
    {
        printf("try again\nIf you want put numbers into second array input 1 else 0: ");
        rewind(stdin);
    }
    int array2[100];
    int n_in_arr2;
    printf("Enter the number of second array elements[1-100]: ");
    while (scanf_s("%d", &n_in_arr2) != 1 || n_in_arr2 > 100 || n_in_arr2 < 1)
    {
        printf("try again\nEnter the number of second array elements[1-100]: ");
        rewind(stdin);
    }
    if (arr1_choice == 1)
        printf("Enter numbers in descending order\n");

    if (arr2_choice == 0)
    {
        for (ind = 0; ind < n_in_arr2; ind++)
        {
            randnum1 = rand() % 101;
            randnum2 = rand() % 101;
            array2[ind] = (randnum1 - randnum2);
        }
        for (ind = 0; ind < n_in_arr2 - 1; ind++)
        {
            for (int ind2 = 0; ind2 < n_in_arr2 - ind - 1; ind2++)
            {
                if (array2[ind2] < array2[ind2 + 1])
                {
                    int flag2 = array2[ind2];
                    array2[ind2] = array2[ind2 + 1];
                    array2[ind2 + 1] = flag2;

                }
            }
        }
    }
    else
    {
        for (ind = 0; ind < n_in_arr2; ind++)
        {
            printf("%d number: ", ind + 1);
            while (scanf_s("%d", &array2[ind]) != 1 || (ind>0 && array2[ind] >= array2[ind - 1]))
            {
                printf("try again\n%d number: ", ind + 1);
                rewind(stdin);
            }
        }
    }
    printf("Input second array: {");
    for (int ind = 0; ind < n_in_arr2; ind++)
    {
        printf("%d, ", array2[ind]);
    }
    printf("}\n");
    int array3[200];
    int ind1 = 0, ind2 = n_in_arr2-1, ind3 = 0;
    while (ind1 != n_in_arr1 && ind2 != -1)
    {
        if (array1[ind1] < array2[ind2])
        {
            array3[ind3] = array1[ind1];
            ind3++;
            ind1++;
        }
        else
        {
            array3[ind3] = array2[ind2];
            ind3++;
            ind2--;
        }
    }
    if (ind1 == n_in_arr1)
    {
        for (; ind2>-1; ind2--)
        {
            array3[ind3] = array2[ind2];
            ind3++;
        }

    }
    if (ind2 == -1)
    {
        for (; ind1 < n_in_arr1; ind1++)
        {
            array3[ind3] = array1[ind1];
            ind3++;
        }

    }
    printf("Final array: {");
    for (int ind3 = 0; ind3 < n_in_arr1+n_in_arr2; ind3++)
    {
        printf("%d, ", array3[ind3]);
    }
    printf("}");
    return 0;
} 
