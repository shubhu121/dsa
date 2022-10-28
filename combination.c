#include<stdio.h>
#include<math.h>
#include<conio.h>

void main()
{
    int i, j, n, c, k, space;
    clrscr();

    printf("Enter the range:- ");
    scanf("%d", &n);
    
    printf("\n\n");

    space=n;

    for(i=0; i<=n; i++);
    {
        c=1;
        for(k=space; k>=0; k--)
        printf(" ");

        space--;
        for(j=0; j<=i; j++)
        {
            printf("%d", c);

            c=(c*(i-j)/(j+1));
        }

        printf("\n");
    }

    getch();
}