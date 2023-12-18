#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
    // self referencial pointer
};
struct node* getnode()
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    return p;
};
void insbeg(struct node **start, int x)
{
    struct node *p;
    p = getnode();
    p->info = x;
    p->next = *start;
    *start = p;
}
void insafter(struct node **start, struct node **q, int x)
{
    struct node *p;
    p=getnode();
    p->info = x;
    if (*start == NULL)
    {
        p->next = NULL;
        *start = p;
    }
    else
    {
        p->next = (*q)->next;
        (*q)->next = p;
    }
}
void insEnd(struct node **start, int item)
{
    struct node *p, *q;
    p = getnode();
    q=getnode();
    q->info = item;
    q->next = NULL;
    p = *start;
    if (p == NULL)
    {
        *start = q;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = (q);
    }
}
void display(struct node *start)
{
    while (start != NULL)
    {
        printf("%d->", start->info);
        start = start->next;
    }
    printf("NULL\n");
    // p=start;
    // while(p!=NULL){
    //     printf("[%d]->",p->info);
    //     p=p->next;
    // }
    // printf("null");

    // }
}
int delBig(struct node **start)
{
    struct node *p;
    p = *start;
    if (p == NULL)
        printf("void deletion\n");
    else
    {
        int x = p->info;
        *start = p->next;
        free(p);
        return x;
    }
}

int delEnd(struct node **start)
{
    struct node *p, *q;
    p = *start;
    int item;
    if (p == NULL)
    {
        printf("Void Deletion\n");
    }
    else if (p->next == NULL)
    {
        *start = (*start)->next;
        free(p);
    }
    else
    {
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        item = p->info;
        free(p);
        return item;
    }
}

int delAfter(struct node *q)
{
    if (q == NULL || q->next == NULL)
    {
        printf("\nvoid deletion");
        return -1;
    }
    struct node *p;
    p = q->next;
    q->next = p->next;
    int x = p->info;
    free(p);
    return x;
}
int countnode(struct node *start)
{
    struct node *p;
    int count = 0;
    p = start;
    if (p == NULL)
    {
        return count;
    }

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}
void reverse(struct node **start)
{
    struct node *p, *q, *r = NULL;
    p = *start;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (p != NULL)
        {
            q = p->next;
            p->next = r;
            r = p;
            p = q;
        }
        *start = r;
    }
}
