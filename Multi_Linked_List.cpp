#include<stdio.h>
#include<iostream>
using namespace std;

struct node
{
  struct node *next;
  int val;
};


void add(int i,node** h,node** e)
{
    printf("adding\n");
    if(*h!=NULL)
    {
        node *n = (struct node*)malloc(sizeof(node));
        n->next  = NULL;
        n->val = i;

        (*e)->next = n;
        *e = n;
    }
    else
    {
        printf("heading\n");
        *h  = (struct node*)malloc(sizeof(node));
        (*h)->next = NULL;
        (*h)->val = i;
        *e = *h;
    }

  }

  void delete_node(int i,node** h,node** e)
  {
    node* head = *h;
    node* endnode = *e;
    node *temp;
    node *n = head;
    while(n!=NULL)
    {
     if(n->val == i)
     {
        if(n==head)
        {
            head = head->next;
        }
        else if(n==endnode)
        {
            temp->next = NULL;
            endnode = temp;
        }
        else
        {
            temp->next = n->next;       
        }
        free(n);
        break;
    }
    else
    {
        temp = n;
        n = n->next;
    }
  }
}

 void display(node** h)
 {
   node* head = *h;

   node *n = head;

   while(n!=NULL)
   {
    printf("%d\n",n->val);
    n = n->next;
   }
 }



int main()
{

  node *head  = NULL;
  node *endnode  = NULL;    

  add(5,&head,&endnode);
  add(8,&head,&endnode);
  add(1,&head,&endnode);
  add(78,&head,&endnode);
  add(0,&head,&endnode);

  display(&head);
  printf("\n\n");

  system("pause");
  return 0;

}
