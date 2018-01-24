#include<stdio.h>
#define SIZE 10

int queue[SIZE];
int rear=-1,front=-1;
void enqueue()
{
	if(rear==SIZE-1)
	{
		printf("OverFlow\n");
	}
	else if(rear==-1 && front==-1)
	{
		front=0;
		rear=0;
		printf("Enter value to insert : ");
		scanf("%d",&queue[rear]);
	}
	else
	{
		printf("Enter value to enter : ");
		scanf("%d",&queue[++rear]);
	}
}

void dequeue()
{
	if(rear==-1 && front==-1)
	{
		 printf("Underflow\n");
	}
	else if(rear==front)
	{
		printf("Deleted element : %d\n",queue[front]);
		queue[front]=0;
		front=-1;
		rear=-1;
	}
	else
	{
		queue[front++]=0;
	}
}
void display()
{
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("%d ",queue[i]);
	}
	printf("\n");
}


//main
void main()
{
	int ch,y;
	clrscr();
	do
	{
    system("cls");
		printf("1. Insert\t2. Delete\t3. Display\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enqueue();break;
			case 2:dequeue();break;
			case 3:display();break;
			default: printf("Wrong choice\n");
		}
		printf("Want to continue.. (1/0)");
		scanf("%d",&y);
		clrscr();
	}
	while(y==1);
}
