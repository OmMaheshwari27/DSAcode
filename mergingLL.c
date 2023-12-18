#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *getnode()
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    return p;
}
void insEnd(struct node **start, int item)
{
    struct node *p, *q;
    p = getnode();
    p->data = item;
    p->next = NULL;
    q = *start;
    if (q == NULL)
    {
        *start = p;
    }
    else
    {
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}
struct node *merg(struct node *start1, struct node *start2)
{
    if (start1 == NULL)
        return start2;
    if (start2 == NULL)
        return start1;
    struct node *start3 = NULL;
    while (start1 != NULL && start2 != NULL)
    {
        if (start1->data <= start2->data)
        {
            insEnd(&start3, start1->data);
            start1 = start1->next;
        }
        else
        {
            insEnd(&start3, start2->data);
            start2 = start2->next;
        }
    }
    struct node *temp=start3;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if (start1 != NULL)
    {
        temp->next = start1;
    }
    if (start2 != NULL)
    {
        temp->next = start2;
    }
    return start3;
}
void display(struct node *start)
{
    while (start != NULL)
    {
        printf("%d->", start->data);
        start = start->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node *start1 = NULL, *start2 = NULL, *start3 = NULL;
    insEnd(&start1, 2);
    insEnd(&start1, 4);
    display(start1);
    insEnd(&start2, 1);
    insEnd(&start2, 3);
    insEnd(&start2, 5);
    display(start2);
    start3 = merg(start1, start2);
    display(start3);
    return 0;
}