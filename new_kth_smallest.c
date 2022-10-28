#include <stdio.h>
void quicksort(int number[50], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }

        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}

void quicksort(int number[50], int first, int last);
int main()
{
    int i, count, k;

    printf("Enter number of  elements : ");
    scanf("%d", &count);
    printf("Enter value of k: ");
    scanf("%d", &k);

    int number[count];
    printf("Enter %d elements: ", count);
    for (i = 0; i < count; i++)
        scanf("%d", &number[i]);
    quicksort(number, 0, count - 1);
    printf("The Kth smallest number is  ");
    printf(" %d", number[k - 1]);

    return 0;
}