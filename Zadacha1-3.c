#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    srand(time(NULL));
    int arr_choice;
    float randnum1, randnum2, randnum3;
    int ind;
    printf("If you want put numbers into first array by hands input 1 or random numbers - 0: ");
    while (scanf_s("%d", &arr_choice) != 1 || arr_choice != 1 && arr_choice != 0)
    {
        printf("try again\nIf you want put numbers into first array by hands input 1 or random numbers - 0: ");
        rewind(stdin);
    }
    float array[100];
    int n_in_arr;
    printf("Enter the number of array elements[1-100]: ");
    while (scanf_s("%d", &n_in_arr) != 1 || n_in_arr > 100 || n_in_arr < 1)
    {
        printf("try again\nEnter the number of array elements[1-100]: ");
        rewind(stdin);
    }
    for (int ind = 0; ind < n_in_arr; ind++)
    {
        if (arr_choice == 0)
        {
            randnum1 = rand() % 101;
            randnum2 = rand() % 101;
            randnum3 = rand() % 10
                ;
            array[ind] = (randnum1-randnum2) / randnum3;
        }
        else
        {        
            printf("%d number: ", ind + 1);
            while (scanf_s("%f", &array[ind]) != 1)
            {
                printf("try again\n%d number: ", ind + 1);
                rewind(stdin);
            }
            
        }

    }
    printf("Input array: {");
    for (int ind = 0; ind < n_in_arr; ind++)
    {
        printf("%.3f, ", array[ind]);
    }
    printf("}");
    float max_num = array[0];
    for (ind = 1; ind < n_in_arr; ind++)
        if (max_num < array[ind])
            max_num = array[ind];
    printf("\nMaximum array element = %.3f\n", max_num);
    int flag;
    float sum = 0;
    for (ind = n_in_arr - 1; ind > 0; ind--)
    {
        if (array[ind] > 0)
        {
            flag = ind;
            break;

        }
    }
    for (ind = 0; ind < flag; ind++)
        sum = sum + array[ind];
    printf("The sum of the array elements up to the last positive element = %.3f", sum);
    return 0;
}   