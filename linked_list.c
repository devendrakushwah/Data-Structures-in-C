
#include<stdio.h>
struct node
{
 int item;
 struct node *next;
}*end,*start=NULL;
void insert_end()
{
    printf("***Insertion from end***\n");
    if(end==NULL)
    {
        struct node *ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("enter item");
        scanf("%d",&ptr->item);
        ptr->next=NULL;
        start=ptr;
        end=ptr;
    }
    else
    {
        struct node *ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("enter item");
        scanf("%d",&ptr->item);
        ptr->next=NULL;
        end->next=ptr;
        end=ptr;
    }
}

void insert_start()
{
    printf("***Insertion from start***\n");
    if(start==NULL)
    {
        struct node *ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("enter item");
        scanf("%d",&ptr->item);
        ptr->next=NULL;
        start=ptr;
        end=ptr;
    }
    else
    {
        struct node *ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("enter item");
        scanf("%d",&ptr->item);
        ptr->next=NULL;
        ptr->next=start;
        start=ptr;
    }
}
void insert_between()
{
    int size=get_size();
    int pos;
    printf("Enter position : ");
    scanf("%d",&pos);
    if(pos==0)
    {
        insert_start();
    }
    else if(pos>=size)
    {
        insert_end();
    }
    else
    {
        struct node *ptr,*nptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        nptr=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&nptr->item);
        nptr->next=NULL;
        ptr=start;
        int i;
        for(i=0;i<pos-1;i++)
        {
            ptr=ptr->next;
        }
        nptr->next=ptr->next;
        ptr->next=NULL;
        ptr->next=nptr;
    }
}

void delete_start()
{
    printf("***Deletion from start***\n");
    if(start==NULL)
    {
        printf("empty");
    }
    else if(start==end)
    {
        struct node *ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr=start;
        start=end=NULL;
        ptr->next=NULL;
        free(ptr);
    }
    else
    {
        struct node *ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr=start;
        start=ptr->next;
        ptr->next=NULL;
        free(ptr);
    }
}

void delete_end()
{
    printf("***Deletion from end***\n");
    if(end==NULL)
    {
        printf("empty");
    }
    else if(start==end)
    {
        struct node *ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr=end;
        start=end=NULL;
        ptr->next=NULL;
        free(ptr);
    }
    else
    {
        struct node *ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr=start;
        while(ptr->next != end)
        {
            ptr=ptr->next;
        }
        end=ptr;
        ptr=end->next;
        end->next=NULL;
        free(ptr);
    }
}
void delete_between()
{
    int size=get_size();
    int pos;
    printf("Enter position : ");
    scanf("%d",&pos);
    if(pos==1)
    {
        delete_start();
    }
    else if(pos>=size)
    {
        delete_end();
    }
    else
    {
        struct node *ptr,*nptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        nptr=(struct node*)malloc(sizeof(struct node));
        ptr=start;
        nptr=ptr->next;
        int i;
        for(i=0;i<pos-2;i++)
        {
            ptr=ptr->next;
            nptr=nptr->next;
        }
        ptr->next=nptr->next;
        nptr->next=NULL;
        free(nptr);
    }
}

void display()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr=start;
    if(start==NULL)
    {
        printf("Empty\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d ",ptr->item);
            ptr=ptr->next;
        }
    }
}

int get_size()
{
    int cnt=0;
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr=start;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        cnt++;
    }
    return cnt;
}
void main()
{
    int ch,y;
    do{
            printf("Enter choice\n");
            printf("1.Insert_end 2. Insert_start 3.Insert_between 4.Delete_start 5.Delete_end 6. Delete_middle 7.Display\n");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                insert_end();
                break;
            case 2:
                insert_start();
                break;
            case 3:
                insert_between();
                break;
            case 4:
                delete_start();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                delete_between();
                break;
            case 7:
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
