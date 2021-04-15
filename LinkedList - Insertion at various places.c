#include<stdio.h>
#include<stdlib.h>
#define ANSI_COLOR_BLUE    "\x1b[34m"           //for various insertion_fn()
#define ANSI_COLOR_RED     "\x1b[31m"           //for display()
#define ANSI_COLOR_GREEN   "\x1b[32m"           //for coloured statements in main() 
#define ANSI_COLOR_RESET   "\x1b[0m"
void insert_bgn();
void insert_end();
void insert_spf();
void display();

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL,*new_node,*temp = NULL;
int ctr = 0;

void insert_bgn()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    printf(ANSI_COLOR_BLUE "\nEnter value : " ANSI_COLOR_RESET);
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    ctr++;
    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node -> next = head;
        head = new_node;
    }
    printf(ANSI_COLOR_BLUE "Node added successfully!!" ANSI_COLOR_RESET);
}

void insert_end()
{
    new_node = (struct node*)malloc(sizeof(struct node));
    printf(ANSI_COLOR_BLUE "\nEnter value : " ANSI_COLOR_RESET);
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    ctr++;
    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)               // temp != NULL, cant be applied here
                                                // because it'll move us to end of LL
                                                // n we'll wont be able to link LL with new node
                                                // i.e., temp -> next or 0 -> next is NULL
                                                // thus, we'll wont be able to link
            temp = temp->next;
        
        temp->next = new_node;
    }
    printf(ANSI_COLOR_BLUE "Node added successfully!!" ANSI_COLOR_RESET);
}

void insert_spf()
{
    int pos;
    printf(ANSI_COLOR_BLUE "\nCurrent elements in LL : %d" ANSI_COLOR_RESET, ctr);
    new_node = (struct node*)malloc(sizeof(struct node));
    printf(ANSI_COLOR_BLUE "\nEnter value : " ANSI_COLOR_RESET);
    scanf("%d", &new_node->data);
    printf(ANSI_COLOR_BLUE "Enter position for inserting element at : " ANSI_COLOR_RESET);
    scanf("%d", &pos);
    if(pos > ctr)
    {
            printf(ANSI_COLOR_BLUE "\nCant insert at Position %d since LL only contains %d elements.." ANSI_COLOR_RESET, pos,ctr);
    }
    else
    {
        temp = head;
        for(int i = 1; i < (pos-1); i++)
            temp = temp ->next;
        
        new_node -> next = temp -> next;
        temp -> next = new_node;
    }
    ctr++;
    printf(ANSI_COLOR_BLUE "\nNode added successfully!!" ANSI_COLOR_RESET);    
}

void display()
{
    if(head == NULL)
    {
        printf(ANSI_COLOR_RED "\nLinked List is EMPTY!!");
        printf("\nNode Count : %d\n" ANSI_COLOR_RESET, ctr);
    }
    else
    {
        printf(ANSI_COLOR_RED "\nLinked List is as follows : \n\t");
        temp = head;
        while(temp != NULL)
        {
            printf("%d ->  ", temp->data);
            temp = temp->next;
        }
        printf("\nNode Count : %d\n" ANSI_COLOR_RESET, ctr);
    }
}

void main()
{
    char cnn = 'y';
    int ch;
    while(cnn == 'y' || cnn == 'Y')
    {
        x:
        printf(ANSI_COLOR_GREEN "\n\nPress :");
        printf("\n1. To insert element at beginning of LL");
        printf("\n2. To insert element at end of LL");
        printf("\n3. To insert element at specific position in LL");
        printf("\n4. To display LL elements");
        printf("\n5. To Exit");
        printf("\nYour choice is : " ANSI_COLOR_RESET);
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: insert_bgn();
                    break;
            case 2: insert_end();
                    break;
            case 3: insert_spf();
                    break;
            case 4: display();
                    break;
            case 5: exit(0);
                    break;
            default: printf(ANSI_COLOR_GREEN "\nPls enter a valid choice" ANSI_COLOR_RESET);
                    goto x; 
        }
        fflush(stdin);
        printf(ANSI_COLOR_GREEN "\nDo u wish to continue? [y/n] : " ANSI_COLOR_RESET);
        scanf("%c", &cnn);
        fflush(stdin);
    }    
}