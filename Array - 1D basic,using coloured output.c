#include<stdio.h>
#define GREEN    "\x1b[32m"
#define RESET   "\x1b[0m"
void main()
{
    int a[5],size;
    printf(GREEN "Enter the no. of elements in the array : " RESET);
    scanf("%d", &size);
    printf("Enter elements : \n");
    for(int i = 0; i< size ; i++)
        scanf("%d", &a[i]);
    printf("\nArray is : \n");
    for(int i = 0; i< size ; i++)
        printf(GREEN "%d \t" RESET, a[i]);
}