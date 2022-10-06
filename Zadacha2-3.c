#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    srand(time(NULL));
    int arr_choice;
    float randnum1, randnum2, randnum3;
    int ind, dopind;
    printf("If you want put numbers into array input 1 else 0: ");
    while (scanf_s("%d", &arr_choice) != 1 || arr_choice != 1 && arr_choice != 0)
    {
        printf("try again\nIf you want put numbers into array input 1 else 0: ");
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
    for (int i = 0; i < n_in_arr; i++)
    {
        if (arr_choice == 0)
        {
            randnum1 = rand() % 10001;//что это
            randnum2 = rand() % 10001;
            randnum3 = rand() % 900;// что это
            array[i] = (randnum1 - randnum2) / randnum3;//что это
        }
        else
        {
            printf("%d number: ", i + 1);
            while (scanf_s("%f", &array[i]) != 1)
            {
                printf("try again\n%d number: ", i + 1);
                rewind(stdin);
            }

        }

    }
    printf("Input array: {");
    for ( ind = 0; ind < n_in_arr; ind++)
    {
        printf("%1.2f, ", array[ind]);
    }
    printf("}");
    for (dopind = 0; dopind < n_in_arr; dopind++)
    {
        if (array[dopind] < 0)
        {   
            n_in_arr++;
            for (ind = n_in_arr - 2; ind > dopind; ind--)
            {
                array[ind+1] = array[ind];
            }
            array[dopind + 1] = array[dopind];
            dopind++;
        }
    }
    printf("\nFinal array: {");
    for (ind = 0; ind < n_in_arr; ind++)
    {
        printf("%1.2f, ", array[ind]);
    }
    printf("}");
    return 0;
}