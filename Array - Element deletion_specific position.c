#include<stdio.h>
void main()
{
    int a[10],size,num,pos,i;
    x:
    printf("Enter the no. of elements in the array  : ");
    scanf("%d", &size);
    if(size > 10)
    {
        printf("\nOverFlow condition, array bound: 10 elements\n\n");
        goto x;
    }
    else
    {
        printf("\nEnter elements    : \n");
        for(i = 0; i< size ; i++)
            scanf("%d", &a[i]);
        printf("\nArray is          : \n");
        for(i = 0; i< size ; i++)
            printf("%d \t", a[i]);
        printf("\n\nEnter the position for no. to be deleted  : ");
        scanf("%d", &pos);
        if(pos <= 0 || pos > size+1 )
            printf("\nInvalid position");
        else
        {
            num = a[pos-1];
            printf("\nElement removed   : %d \n",num);
            for(i = (pos-1); i < (size-1) ; i++)
                a[i] = a[i+1];
            size--;
            printf("\nUpdated Array     : \n");
            for(int i = 0; i< size ; i++)
                printf("%d \t", a[i]);
        }
    }
}