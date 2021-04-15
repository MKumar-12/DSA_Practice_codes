#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define BLUE    "\x1b[34m"              //for insert()
#define YELLOW  "\x1b[33m"              //for get_length()    
#define RED     "\x1b[31m"              //for display()
#define GREEN   "\x1b[32m"              //for coloured statements in main() 
#define RESET   "\x1b[0m"
void insert();
void display();
void node_count();

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *new_node, *temp = NULL;
int ctr = 0;

void insert()
{
    srand(time(0));
    int range = rand() % 10; 
    for (int i = 0; i < range; i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = rand() % 101;
        new_node -> next = NULL;
        if(head == NULL)
        {
            head = new_node;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = new_node;
        }
        ctr++;
    }
    printf(BLUE "\nx%d Nodes inserted successfully!!" RESET,range);
}

void display()
{
    if(head == NULL)
    {
        printf(RED "\nLinked List is EMPTY!!");
        printf("\nNode Count : %d\n" RESET, ctr);
    }
    else
    {
        printf(RED "\nLinked List is as follows : \n\t");
        temp = head;
        while(temp != NULL)
        {
            printf("%d ->  ", temp->data);
            temp = temp->next;
        }
        printf("\nNode Count : %d\n" RESET, ctr);
    }
}

void node_count()
{
    int ctr = 0;
    temp = head;
    while(temp != NULL)
    {
        ctr++;
        temp = temp->next;
    }
    printf(YELLOW "\nNo. of Nodes in LL is : %d" RESET, ctr);
}

void main()
{
    char cnn = 'y';
    int ch;
    while(cnn == 'y' || cnn == 'Y')
    {
        x:
        printf(GREEN "\n\nPress :");
        printf("\n1. To insert random no. of random elements in LL");
        printf("\n2. To display LL elements");
        printf("\n3. To count no. of nodes in LL");
        printf("\n4. To Exit");
        printf("\nYour choice is : " RESET);
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: insert();
                    break;
            case 2: display();
                    break;
            case 3: node_count();
                    break;
            case 4: exit(0);
                    break;
            default: printf(RED "\nPls enter a valid choice" RESET);
                    goto x; 
        }
        fflush(stdin);
        printf(GREEN "\nDo u wish to continue? [y/n] : " RESET);
        scanf("%c", &cnn);
        fflush(stdin);
    }    
}