#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int bubbleSort(int *list, int size)
{
    int 
        temp, // Variable to make the change of values
        order; // Key variable to tell 0 if its everything in order and 1 if still need movements

    // A for loop to pass trought all the values until the program finished
    for (int i = 0; i < size; i++)
    {
        order = 0;
        // A for loop to continue throwing the biggest value found to front in each roll
        for (int j = 0; j < size - 1 - i; j++)
        {
            // Testing if it will pass to front or not
            if (list[j] > list[j + 1])
            {
                // Making the changes
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp; 
                order = 1;
            }       
        }
        if (order == 0)
            break;
    }
    return 0;
}


int main()
{   
    int size = 10;
    int numberList[size];

    srand(time(NULL));

    for (int count = 0; count < size; count++)
    {
        numberList[count] = (rand() % 89) + 10;
        printf("[ %d ] ", numberList[count]);
    }
    
    bubbleSort(numberList, size);
    printf("\n======================================================\n");

    for (int count = 0; count < size; count++)
        printf("[ %d ] ", numberList[count]);

    return 0;
}