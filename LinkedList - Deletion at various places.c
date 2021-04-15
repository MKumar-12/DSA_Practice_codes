#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define BLUE    "\x1b[34m"              //for insert()
#define YELLOW  "\x1b[33m"              //for various deletion_fn()    
#define RED     "\x1b[31m"              //for display()
#define GREEN   "\x1b[32m"              //for coloured statements in main() 
#define RESET   "\x1b[0m"
void insert();
void delete_bgn();
void delete_end();
void delete_spf();
void display();

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *new_node, *temp = NULL, *prev_node = NULL;
int ctr = 0;

void insert()
{
    srand(time(0));
    for (int i = 0; i < 4; i++)
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
    printf(BLUE "\nx4 Nodes inserted successfully!!" RESET);
}

void delete_bgn()
{
    if (head == NULL)
    {
        printf(RED "\nLL is empty!!");
        printf("\nCannot perform deletion operation" RESET);
    }
    else
    {
        temp = head;
        printf(YELLOW "\nElement Removed : %d", temp->data);
        head = head->next; 
        free(temp);                 //deallocates the memory previously allocated by malloc call
        ctr--;
        printf("\nA Node was successfully deleted from beginning!!" RESET);
    }
}

void delete_end()
{
    if (head == NULL)
    {
        printf(RED "\nLL is empty!!");
        printf("\nCannot perform deletion operation" RESET);
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            prev_node = temp;
            temp = temp->next;
        }
        if(temp == head)
            head = NULL;
        else
            prev_node->next = NULL;
        
        printf(YELLOW "\nElement Removed : %d", temp->data);
        free(temp);
        ctr--;
        printf("\nA Node was successfully deleted from end!!" RESET);
    }
}

void delete_spf()
{
    int pos; 
    if (head == NULL)
    {
        printf(RED "\nLL is empty!!");
        printf("\nCannot perform deletion operation" RESET);
    }
    else
    {
        printf(YELLOW "\nCurrently, no. of elements present in LL  : %d", ctr);
        printf("\nEnter the position to delete element from : " RESET);
        scanf("%d", &pos);
        if(pos < ctr && pos > 0)
        {
            temp = head;
            for(int i = 1; i < pos ; i++)
            {
                prev_node = temp;
                temp = temp->next;
            }
            if(temp == head)
                head = head->next;
            else
                prev_node->next = temp->next;
            
            printf(YELLOW "\nElement Removed : %d", temp->data);
            free(temp);
            ctr--;
            printf("\nA Node was successfully deleted from %d'th position!!" RESET, pos);
        }
        else
            printf(RED "\nInvalid position!!" RESET);
    }
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

void main()
{
    char cnn = 'y';
    int ch;
    while(cnn == 'y' || cnn == 'Y')
    {
        x:
        printf(GREEN "\n\nPress :");
        printf("\n1. To insert x4 random elements in LL");
        printf("\n2. To delete element from beginning of LL");
        printf("\n3. To delete element from end of LL");
        printf("\n4. To delete element from specific position in LL");
        printf("\n5. To display LL elements");
        printf("\n6. To Exit");
        printf("\nYour choice is : " RESET);
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: insert();
                    break;
            case 2: delete_bgn();
                    break;
            case 3: delete_end();
                    break;
            case 4: delete_spf();
                    break;
            case 5: display();
                    break;
            case 6: exit(0);
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