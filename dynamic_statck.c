#include <stdio.h>
// structure used to implement single node of a linked list
struct node

{
    int value;
    struct node* next;
} *top=NULL;

void push()
{
    int temp;
    printf("Enter the value to be pushed\n");
    scanf("%d",&temp);
    struct node *elem;
    elem = (struct node*)malloc(sizeof(struct node));
    elem->value=temp;
    elem->next=top;
    top=elem;
}

void pop()
{
    if(top==NULL)
    {
        printf("underflow\n");
    }
    else
    {
        struct node *temp = top;
        top = temp->next;
        free(temp);
    }
}

void display()
{
      struct node *temp = top;
      while(temp!= NULL)
        {
             printf("%d  ",temp->value);
             temp = temp -> next;
        }
      printf("\n");
}


void main()
{
    int ch,y;
    do{
            system("cls");
            printf("Enter choice\n");
            printf("1.Push 2.Pop 3.Display\n");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Not a valid choice\n!!!");
                break;
            }
            printf("wanna continue (1)\n");
            scanf("%d",&y);
    }
    while(y==1);
}
