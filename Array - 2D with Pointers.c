#include<stdio.h>
void main()
{
    int a[10][10],r,c;
    int *p;
    printf("Enter the no. of Rows (max 10)  : ");
    scanf("%d", &r);
    printf("\nEnter the no. of Cols (max 10)  : ");
    scanf("%d", &c);
    printf("\nEnter elements  : \n");
    for(int i = 0; i < r ; i++)
        for(int j = 0; j < c ; j++)
            scanf("%d", &a[i][j]);
    printf("\nArray is  : \n");
    for(int i = 0; i < r ; i++)
    {
        for(int j = 0; j < c ; j++)
            printf("%d \t", a[i][j]);
        printf("\n");
    }
    p = a[0];                                           //p=a is NOT VALID
    //p = &a[0][0];                                     //it returns ptr. to a 1D arr
                                                        //(the 1st row of arr)
                                                        //while,p can contain addr of an 
                                                        //int var. only, thus, p = a[0]
                                                        //is valid
    printf("\nBase address of arr : %u", p);
    printf("\nBase address of arr : %u", a);
    printf("\nBase address of arr : %d", &a);
    printf("\nBase address of arr : %u", &a[0][0]);
    printf("\nBase address of arr : %d", a[0]);
    printf("\nBase address of arr : %d", &a[0]);
    printf("\nBase address of arr : %d", *a);           //returns addr of a[0] from memory, 
                                                        //Arr. name gives address of 1st element (1st 1-D array here)
                                                        // * a[0]   =   Base addr of arr
    printf("\nValue at arr[0]     : %d",*(*a) );
    
    //printf("\nVal of arr 00 : %d", **p);              ERROR
    printf("\nVal of arr 00 : %d", **a);
    
    printf("\nVal of arr 01 : %d", *(*a + 1) );
    

    //addr of arr[1]
    printf("\n\nBase address of arr + 1x Size of row : %u", a+1);       // = &a[1]
                                                        //points from base address of a[0] 
                                                        //to addr for nxt element of arr.   i.e.,a[1]
    printf("\nAddress of arr[1] : %u", *(a+1));
    printf("\nAddress of arr[1] : %u", a[1]);
    printf("\nAddress of arr[1] : %u", &a[1]);
    printf("\nValue at arr[1][0]   : %d",*(*(a+1)) );
    
    //addr of arr[1][2]
    printf("\n\nAddress of arr[1][2] : %u", *(a+1) + 2);
    printf("\nValue at arr[1][2]   : %d",*(*(a+1) + 2) );
    printf("\nValue at arr[1][2]   : %d",*(a[1] + 2) );
    

    printf("\n\nBase address of arr + 1x Size of arr : %u", &a+1);
    
}