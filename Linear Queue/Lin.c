#include<stdio.h>
#include<ctype.h>
#define max 2

int queue[max],front=-1,rear=-1;
void enqueue();
void dequeue();
void peek();
void display();

int main()
{
	int option;
	do
	{
		printf("\n\n*****QUEUES*****\n");
		printf("\n1. Enqueue elements:");
		printf("\n2. Dequeue elements:");
		printf("\n3. Peek");
		printf("\n4. Display elements:");
		printf("\n5. Exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				break;
			default:
				printf("Invalid choice");
				break;
		}
	}while(option!=5);
	return 0;
}

void enqueue()
{ 
	int num; 
	if(front == 0 && rear == max-1) 
	{ 
		printf("Queue is full"); 
	} 
	else 
	{ 
		printf("Enter the data to be inserted : "); 
        scanf("%d",&num); 
	    if(front==-1 && rear==-1) 
	    { 
	        front = rear = 0; 
	        queue[rear] = num; 
	    } 
	    else if(front!=0 && rear == max-1)
 	    {
	 	    rear = 0; 
		    queue[rear] = num; 
	    }    
	    else 
	    { 
		    rear++;
 		    queue[rear] = num;
	    }
	}
}

void dequeue()
{ 
    if(front==-1 && rear==-1) 
    {
        printf("Queue is Empty");
    } 
    else
    { 
        printf("The deleted element is %d", queue[front]); 
        if(front == rear) 
        { 
            front = rear = -1;
        } 
        else if(front == max-1)
        {
            front = 0;
        } 
        else 
        {
            front++; 
        }
    }
}

void peek() 
{
    if(front== -1 && rear== -1)
    { 
        printf("Queue is Empty"); 
    } 
    else
    { 
	    printf("The first element in queue is %d",queue[front]); 
    } 
} 


void display() 
{ 
	int i; 
	if(front== -1 && rear== -1) 
	{ 
		printf("Queue is Empty"); 
	} 
	else
 	{ 
		printf("The elements in the queue are : ");
		if(front<rear)
		{
		    for(i=front;i<rear;i++)
		    {
			    printf("%d\t",queue[i]);
		    }
		    printf("%d",queue[rear]);
	    }
	    else if(front>rear)
        {
	        for(i=front;i<max;i++)
	        {
		        printf("%d\t",queue[i]);
	        }
	        for(i=front;i<=rear;i++)
	        {
		        printf("%d\t",queue[i]);
	        }
	    }
	    else
	    {
		    printf("%d",queue[front]);
	    }
    }
}
