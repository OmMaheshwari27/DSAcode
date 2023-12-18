#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
    struct node *prev;
    // self referencial pointer
};
struct node *getnode()
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    return p;
};
void insbeg(struct node **start, int x)
{
    struct node *p;
    p = getnode();
    p->info = x;
    p->prev = NULL;
    p->next = *start;
    if (start != NULL)
        (*start)->prev = p;
    *start = p;
}
void insafter(struct node **start, struct node **q, int x)
{
    struct node *p, *r;
    p = getnode();
    r = getnode();
    p->info = x;
    if (*start == NULL)
    {
        p->next = NULL;
        p->prev = NULL;
        *start = p;
    }
    else
    {
        p->next = (*q)->next;
        r = p->next;
        (*q)->next = p;
        p->prev = *q;
        r->prev = p;
    }
}
void inBefore(struct node **start, struct node **curr, int x)
{
    struct node *new, *pre;
    new = getnode();
    pre = getnode();
    new->info = x;
    if (*start == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        *start = new;
    }
    else
    {
        pre = (*curr)->prev;
        new->prev = (*curr)->prev;
        (*curr)->prev = new;
        new->next = (*curr);
        pre->next = new;
    }
}
void insEnd(struct node **start, int item)
{
    struct node *p, *q;
    p = getnode();
    q = getnode();
    q->info = item;
    q->next = NULL;
    p = *start;
    if (p == NULL)
    {
        *start = q;
        q->prev = NULL;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = (q);
        q->prev = p;
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
        (*start)->prev= NULL;

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
        *start = p->next;
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
    struct node *p, *r;
    p = q->next;
    r = p->next;
    q->next = r;
    r->prev = q;
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
// void reverse(struct node **start)
// {
//     struct node *p, *q, *r = NULL;
//     p = *start;
//     if (start == NULL)
//     {
//         printf("List is empty\n");
//     }
//     else
//     {
//         while (p != NULL)
//         {
//             q = p->next;
//             p->next = r;
//             r = p;
//             p = q;
//         }
//         *start = r;
//     }
// }

int main()
{
    struct node *start = NULL, *p, *q;
    insEnd(&start, 0);
    insbeg(&start, 3);
    insbeg(&start, 1);
    insbeg(&start, 9);
    insbeg(&start, 16);
    insbeg(&start, 8);
    insbeg(&start, 2);
    insbeg(&start, 11);
    display(start);
    printf("\nitem deleted %d\n", delBig(&start));
    display(start);
    int x = 9;
    {
        p = start;
        while (p != NULL)
        {
            if (p->info == x)
            {
                q = p;
                break;
            }
            p = p->next;
        }
        printf("\nitem deleyted %d\n", delAfter(q));
    }
    display(start);
    int y = 9;
    {
        p = start;
        while (p != NULL)
        {
            if (p->info == y)
            {
                q = p;
                break;
            }
            p = p->next;
        }
     insafter(&start,&q,10);
     inBefore(&start,&q,10);
    }
    printf("\nafter insertion\n");
    display(start);
       printf("\nitem deleted %d\n", delEnd(&start));
    display(start);
    printf("\n%d nodes are present\n", countnode(start));
    // reverse(&start);
    // display(start);

    return 0;
}
