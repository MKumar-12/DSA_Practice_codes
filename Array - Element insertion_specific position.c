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
        printf("\nEnter elements                          : \n");
        for(i = 0; i< size ; i++)
            scanf("%d", &a[i]);
        printf("\nArray is                                : \n");
        for(i = 0; i< size ; i++)
            printf("%d \t", a[i]);
        printf("\n\nEnter the no. n position for no. to be inserted  : ");
        scanf("%d %d", &num, &pos);
        if(pos <= 0 || pos > size+1 )
            printf("\nInvalid position");
        else
        {
            for(i = (size-1); i>= pos-1 ; i--)
                a[i+1] = a[i];
            a[i+1] = num;
            size = size + 1;
            printf("\nUpdated Array is                         : \n");
            for(int i = 0; i< size ; i++)
                printf("%d \t", a[i]);
        }
    }
}