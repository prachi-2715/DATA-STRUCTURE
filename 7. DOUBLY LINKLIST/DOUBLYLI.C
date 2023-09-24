#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
  struct Node *previous;
  int data;
  struct Node *next;
};
void linklistTraversal(struct Node *ptr)
{
  while(ptr!=NULL)
  {
    printf("Elements: %d\n",ptr->data);
    ptr = ptr->next;
  }
}
struct Node *deleteBegining(struct Node *head)
{
  struct Node *ptr = head;
  head = head->next;
  head->previous = NULL;
  free(ptr);
  return head;
}
struct Node *insertionBegining(struct Node*first)
{
  struct Node *newNode;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  printf("Enter the data");
  scanf("%d",&newNode->data);
  newNode->previous = NULL;
  newNode->next = first;
  first->previous = newNode;
  return newNode;
}
int main()
{
  int choice;
  struct Node *head;
  struct Node *first;
  struct Node *second;
  struct Node *third;
  clrscr();
  head =(struct Node *)malloc(sizeof(struct Node));
  first = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));

  head->previous = NULL;
  head->data = 24;
  head->next = first;

  first->previous = head;
  first->data = 34;
  first->next = second;

  second->previous = first;
  second->data = 57;
  second->next = third;

  third->previous = second;
  third->data = 89;
  third->next = NULL;
  printf("*******Linklist*******\n");
  printf("1.Traversal\n2.Insertion at Begining\n3.Deltion at Beigining\n4.Exit\n");
  do
  {
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      linklistTraversal(head);
      break;
      case 2:
      head = insertionBegining(head);
      linklistTraversal(head);
      break;
      case 3:
      head = deleteBegining(head);
      linklistTraversal(head);
      break;
      case 4:
      break;
      default:
      printf("Invlid option\n");
      break;
    }
  }while(choice!=4);
  getch();
  return 0;
}