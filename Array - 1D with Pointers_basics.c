//1-D Arrays with Ptr.

#include<stdio.h>
void main()
{
    int m[4];
    int *p;
    p = m;
    printf("Enter 4 elements :\n");
    for(int i = 0; i <= 3; i++)
        //scanf("%d",m + i);                                //Alt. way to scan arr elements
        scanf("%d",&p[i]);
    printf("Array is : \n");
    for(int i = 0; i <= 3; i++)
        printf("%d \t",*(m + i));
    p=&m[2];
    
    printf("\n\nBase Address of m      : %p",m);            //Base addr of arr
    printf("\nBase Address of m      : %p",&m);           //Base addr of arr
    printf("\nMemory Address of ptr  : %p",&p);           //Memory addr of ptr

    printf("\n\nAddress of m[2]        : %p",&m[2]);      //addr of arr[2]
    printf("\nAddress of m[2]        : %p",p);            //addr of arr[2] 
    printf("\nValue pointed by ptr   : %d",*p);           //arr[2] 

    p--;                                                  //ptr decremented      
    printf("\n\nAfter Decrementing");
    printf("\nAddress stored in p    : %p",p);            //addr of arr[1]
    printf("\nValue pointed by ptr   : %d",*p);           //arr[1]

    printf("\n\n m[2] : %d",m[2]);
    printf("\n m[2] : %d",2[m]);                          //different ways to access arr[2]
    printf("\n m[2] : %d",*(m+2));
    printf("\n m[2] : %d",*(p+1));
    printf("\n m[2] : %d",1[p]);
    
    p = m;
    printf("\n\n%p", p);                                  //Base addr of arr or arr[0]
    printf("\n%p", p + 1);                                //addr of arr[1]
    printf("\n%p", &m[0] + 1);                            //addr of arr[1]
    printf("\n%p", &p);                                   //Memory addr of ptr
    printf("\n%p", &m + 1);                               //Base addr of arr + 1x Size of arr 
    printf("\n%p", &m + 2);                               //Base addr of arr + 2x Size of arr

    printf("\n\nm[0]     : %d",*m);
    printf("\nm[1]     : %d",*(m + 1));
    printf("\nm[0] + 1 : %d",*m + 1);                 
    
    // which is memory address for m[1]
    //incrementing/decrementing a ptr. value results in pointing to the 
    //memory location of next/previous element of its base type.
    //i.e., here its pointing a integer, thus by 4 bytes inc./dec. 

    /* 
    Some INVALID statements 
        m++             //base address of array cant be changed
        p = m[2]        //we cannot assign value to ptr,    p = &m[2] is valid

    ptr     !=  &ptr    //ptr stores address of some var. as its value 

    Accessing i-th element of element :
    arr[i]      OR      *(arr + i)         OR     i[arr]
                OR      *(ptr + i)         OR     i[ptr]        where, ptr = &arr

    Scanning of array elements :
        scanf("%d", &arr[i]);
        OR
        scanf("%d", arr + i);
    */
    }