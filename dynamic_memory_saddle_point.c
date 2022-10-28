#include <stdio.h>
#include <stdlib.h>
int **inputmatrix(int **a, int r, int c)
{
    int i, j;
    a = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < c; i++)
    {
        a[i] = (int *)malloc(sizeof(int));
    }
    printf("\n Input the Elements of the Matrix :");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    return a;
}
/*void showmatrix(int **a, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        printf("\n");
        for (j = 0; j < c; j++)
        {
            printf("  %d", a[i][j]);
        }
    }
}*/
int minval(int **a, int r, int c)
{
    int i, min;
    min = a[r][0];
    for (i = 0; i < c; ++i)
    {
        if (a[r][i] < min)
        {
            min = a[r][i];
        }
    }
    return min;
}

int maxval(int **a, int r, int c)
{
    int i, max;
    max = a[0][c];
    for (i = 0; i < r; ++i)
    {
        if (a[i][c] > max)
        {
            max = a[i][c];
        }
    }
    return max;
}
void saddlepoint(int **a, int r, int c)
{
    int i, j, rowposition, columnposition, flag = 0, saddlePoint;
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            if (a[i][j] == minval(a, i, c) && a[i][j] == maxval(a, r, j))
            {
                saddlePoint = a[i][j];
                flag = 1;
                rowposition = i;
                columnposition = j;
            }
        }
    }
    if (flag == 1)
    {
        printf("\n The Saddle point of the Matrix is found at position (%d,%d) value is %d ", rowposition, columnposition, saddlePoint);
    }
    else
    {
        printf("\n There is no saddle point in the Matrix ");
    }
}
int main()
{
    int **a, r1, c1, i, j;
    int **c;

    printf("\n enter the order of matrix A :");
    scanf("%d%d", &r1, &c1);
    a = inputmatrix(a, r1, c1);

    printf("\n The Matrix you Entered is :");
    for (i = 0; i < r1; i++)
    {
        printf("\n");
        for (j = 0; j < c1; j++)
        {
            printf("  %d", a[i][j]);
        }
    }
    printf("\n");
    saddlepoint(a, r1, c1);
    return 0;
}