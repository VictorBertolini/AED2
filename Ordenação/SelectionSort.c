#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int selectionSort(int *list, int size)
{
    int 
        temp, // Temporary variable to make the change of values in the array
        lower; // variable to get the position of the lower number in the array

    // A for loop to pass trought all the values and search for the lower value to put in the beggining of the array (in order)
    for (int i = 0; i < size - 1; i++)
    {
        lower = i;
        // A for loop to search for the position of the lower value
        for (int j = i + 1; j < size; j++)
        {
            if (list[lower] > list[j])
                lower = j;
        }

        // Doing the change of values 
        temp = list[i];
        list[i] = list[lower];
        list[lower] = temp;
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
    
    selectionSort(numberList, size);
    printf("\n======================================================\n");

    for (int count = 0; count < size; count++)
        printf("[ %d ] ", numberList[count]);

    return 0;
}