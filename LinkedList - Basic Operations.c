#include<stdio.h>
#include<stdlib.h>
#define BLUE    "\x1b[34m"              //for insert()
#define YELLOW  "\x1b[33m"              //for delete()    
#define RED     "\x1b[31m"              //for display()
#define GREEN   "\x1b[32m"              //for coloured statements in main() 
#define RESET   "\x1b[0m"
void create_node();
void delete_node();
void display();

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *new_node, *temp = NULL,*prev_node = NULL;
int ctr = 0;

void create_node()
{
    new_node = (struct node*) malloc(sizeof(struct node));
    printf(BLUE "\nEnter the value : " RESET);
    //scanf("%d", &new_node -> data); 
    scanf("%d", &(*new_node).data);
    new_node -> next = NULL;
    ctr++;
    if(head == NULL)
    {
        head = new_node;
        temp = new_node;
    }
    else
    {
        temp -> next = new_node;
        temp = new_node;
    }
    printf(BLUE "Node Created succcessfully!!" RESET);
}

void delete_node()
{
    if(head == NULL)
    {
        printf(RED "\nLinked List is EMPTY!!");
        printf("\nCannot remove node..." RESET);
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            prev_node = temp;
            temp = temp->next;
        }
        if (temp == head)
            head = NULL;
        else
            prev_node->next = NULL;
        
        printf(YELLOW "\nValue removed : %d", temp->data);
        ctr--;
        free(temp);
        printf("\n\nNode Deleted succcessfully!!" RESET);
    }
}

void display()
{
    if(head == NULL)
    {
        printf(YELLOW "\nLinked List is EMPTY!!");
        printf("\nNode Count : %d" RESET, ctr);
    }
    else
    {
        printf(RED "\nLinked List is as follows :\n\t");    
        temp = head;
        while(temp != NULL)
        {
            printf("%d ->  ", temp->data);
            temp = temp->next;
        }
        printf("\nNode Count : %d" RESET, ctr);
    }
}

void main()
{
    int ch,cont;
    char crr;
    while(cont)
    {
        x:
        printf(GREEN "\n\nPress :"); 
        printf("\n1. To insert element to linked list  ");
        printf("\n2. To delete element from linked list  ");
        printf("\n3. To display linked list  ");
        printf("\n4. To Exit  ");
        printf("\n\nYour choice is (1-4) : " RESET);
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: create_node();
                    break;
            case 2: delete_node();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default: 
                    fflush(stdin);
                    printf(RED "\nInvalid choice!!");
                    printf("\nPress y to exit or any other key if u wish to re-enter your choice.... " RESET);
                    scanf("%c", &crr);
                    if(crr == 'y' || crr == 'Y')
                        exit(0);
                    else
                        goto x;
        }
        fflush(stdin);
        printf(GREEN "\n\n\tDo u wish to continue? 1 for YES, 0 for NO       : " RESET);
        scanf("%d", &cont);
    } 
}