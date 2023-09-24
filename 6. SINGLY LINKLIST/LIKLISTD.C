#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
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
  free(ptr);
  return head;
}
struct Node *insertionBegining(struct Node *ptr)
{
  struct Node *newNode;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  printf("Enter the data");
  scanf("%d",&newNode->data);
  newNode->next = ptr;
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

  head->data = 24;
  head->next = first;

  first->data = 34;
  first->next = second;

  second->data = 57;
  second->next = third;

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