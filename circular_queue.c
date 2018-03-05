#include<stdio.h>
#define SIZE 5
int rear=-1,front=-1;
int q[SIZE];
void insert()
{
    if(rear==-1)
    {
        rear=0;front=0;
        scanf("%d",&q[rear]);
    }
    else if(rear==SIZE-1 && front==0)
    {
        printf("Full\n");
    }
    else if(rear-front==-1)
    {
        printf("Full\n");
    }
    else if(rear==SIZE-1 && front!=0)
    {
        rear=0;
        scanf("%d",&q[rear]);
    }
    else
    {
        scanf("%d",&q[++rear]);
    }
}

void delete()
{
    if(front==-1)
    {
        printf("Empty\n");
    }
    else if(front==rear)
    {
        q[front]=0;
        rear=-1;
        front=-1;
    }
    else if(front==SIZE-1)
    {
        q[front]=0;
        front=0;
    }
    else
    {
        q[front++]=0;
    }
}

void display()
{
    if(front==-1)
    {
        printf("Empty\n");
    }
    else
    {
        if(rear>=front)
    {
        int i;
        for(i=front;i<=rear;i++)
        {
            printf("%d ",q[i]);
        }
    }
    else
    {
        int i;
        for(i=front;i<SIZE;i++)
        {
            printf("%d ",q[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%d ",q[i]);
        }
    }

    }
}

//main
void main()
{
	int ch,y;
	do
	{
		printf("1. Insert\t2. Delete\t3. Display\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();break;
			case 2:delete();break;
			case 3:display();break;
			default: printf("Wrong choice\n");
		}
		printf("Want to continue.. (1/0)");
		scanf("%d",&y);
	}
	while(y==1);
}
