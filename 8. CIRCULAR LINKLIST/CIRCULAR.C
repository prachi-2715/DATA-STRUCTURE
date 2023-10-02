#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *newnode, *head, *temp;
void insert()
{
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &newnode->data);
	newnode->next = 0;
	if (head == 0)
	{
		head = newnode;
		newnode->next = head;
	}
	else
	{
		temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = head;
	}
}
void display()
{
	int count = 0;
	temp = head;
	printf("Elements in the circular linked list are: ");
	do
	{
		printf("%d\t", temp->data);
		temp = temp->next;
		count++;
	} while (temp != head);
	printf("\nNumber of nodes: %d\n", count);
}
void delete()
{
	if (head == 0)
	{
		printf("No element to delete from the node\n");
	}
	else
	{
		temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = head->next;
		printf("Deleted node data is: %d\n", head->data);
		free(head);
		head = temp->next;
	}
}
int main()
{
	int choice;
	do
	{
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
		printf("Enter your choice\n");
		scanf("%d", &choice);
		switch (choice)
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
			case 4:
			break;
			default:
			printf("Invalid choice\n");
			break;
		}
	}while(choice!=4);
	getch();
	return 0;
}