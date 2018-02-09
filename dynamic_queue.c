#include<stdio.h>
struct node
{
  int item;
  struct node *next;
}*rear,*front=NULL;


void insert()
{
    if(front==NULL)
    {
        struct node *ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("enter item");
        scanf("%d",&ptr->item);
        ptr->next=NULL;
        front=ptr;
        rear=ptr;
    }
    else
    {
        struct node *ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("enter item");
        scanf("%d",&ptr->item);
        ptr->next=NULL;
        rear->next=ptr;
        rear=ptr;
    }
}


void delete()
{
    if(front==NULL)
    {
        printf("Empty\n");
    }
    else if(front==rear)
    {
        struct node *ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr=front;
        front=rear=NULL;
        ptr->next=NULL;
        free(ptr);
    }
    else
    {
        struct node *ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr=front;
        front=ptr->next;
        ptr->next=NULL;
        free(ptr);
    }
}


void display()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr=front;
    if(front==NULL)
    {
        printf("Empty\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d",ptr->item);
            ptr=ptr->next;
        }
    }
}

void main()
{
    int ch,y;
    do{
            printf("Enter choice\n");
            printf("1.Insert 2.Delete 3.Display\n");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                insert();
                break;
            case 2:
                delete();
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
