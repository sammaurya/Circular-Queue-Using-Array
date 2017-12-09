#include <stdio.h>
#include <stdlib.h>

void Push();
void Pop();
void Print();

#define MAX 5

int arr[MAX],front=-1,rear=-1,choice;

int main()
{
    START:
    printf("\n\t\t  Circular Queue Using Array\n");
    printf("\t\t------------------------------\n");
    printf("\n1.PUSH\n2.POP\n3.Print\n4.Clear Screen\n5.Exit\n");
    do
    {
        printf("Enter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
                Push();
                break;
        case 2:
                Pop();
                break;
        case 3:
                Print();
                break;
        case 4:
                system("cls");
                goto START;
                break;
        case 5:
                printf("\nExiting...");
                break;
        default:
                printf("Error! Wrong Choice\n");
        }
    }while(choice!=5);
    return 0;
}

void Push()
{
    int data;
    if((rear==MAX-1&&front==0)||(front==rear+1))
    {
        printf("Overflow\n");
    }
    else if(front==-1 && rear==-1)
    {
        printf("Enter Element : ");
        scanf("%d",&data);
        front += 1;
        rear += 1;
        arr[front]=data;
    }
    else if (rear==MAX-1)
    {
        rear=0;
        printf("Enter Element : ");
        scanf("%d",&data);
        arr[rear]=data;
    }
    else
    {
        printf("Enter Element : ");
        scanf("%d",&data);
        rear++;
        arr[rear]=data;
    }
}

void Pop()
{
    if(front==-1 && rear==-1)
    {
        printf("Underflow: Queue is Empty\n");
    }
    else if(front==rear)
    {
        printf("Element Deleted : %d\n",arr[front]);
        arr[front]=NULL;
        front=rear=-1;
    }
    else if(front==(MAX-1))
    {
        printf("Element Deleted : %d\n",arr[front]);
        arr[front]=NULL;
        front=0;
    }
    else
    {
        printf("Element Deleted : %d\n",arr[front]);
        arr[front]=NULL;
        front++;
    }

}
void Print()
{
    int f=front;
    if(f==-1)
    {
        printf("Underflow: Queue is Empty\n");
    }
    else
    {
        while(f<=MAX-1)
        {
            printf(" %d",arr[f]);
            f++;
            if(arr[f]==NULL)
            {
                break;
            }
        }
        printf("\n");

    }
}
