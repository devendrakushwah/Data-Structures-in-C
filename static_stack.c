#include<stdio.h>
#define SIZE 10
int arr[SIZE];
int top=-1;
void push()
{
    top++;
    scanf("%d",&arr[top]);
}
void pop()
{
    arr[top]=0;
    top--;
}
void display()
{
    int t=top;
    while(t != -1)
    {
        printf("%d , ",arr[t]);
        t--;
    }
    printf("\n");
}

// main -->
void main()
{
    int ch,y;
    do{
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
