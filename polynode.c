#include <stdio.h>
#include <stdlib.h>
struct polynode
{
    int coff;
    int expo;
    struct polynode *next;
};
struct polynode *getnode()
{
    struct polynode *p = (struct polynode *)malloc(sizeof(struct polynode));
    return p;
};
void insEnd(struct polynode **start, int coefficient, int exponent)
{
    struct polynode *p, *q;
    q = getnode();
    q->coff = coefficient;
    q->expo = exponent;
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
void display(struct polynode *start)
{
    while (start != NULL)
    {
        printf("%dx^%d->", start->coff, start->expo);
        start = start->next;
         if(start!=NULL){
       if(start->coff>0)
          printf("+");
    }
  }
    printf("NULL\n");
}
struct polynode *Addpolynode(struct polynode **poly1, struct polynode **poly2)
{
    struct polynode *poly3 = NULL;
    poly3 = getnode();
    struct polynode *p1 = *poly1, *p2 = *poly2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->expo > p2->expo)
        {
            insEnd(&poly3, p1->coff, p1->expo);
            p1 = p1->next;
        }
        else if (p1->expo < p2->expo)
        {
            insEnd(&poly3, p2->coff, p2->expo);
            p2 = p2->next;
        }
        else
        {
            insEnd(&poly3, p2->coff + p1->coff, p2->expo);
            p2 = p2->next;
            p1 = p1->next;
        }
    }
    while (p1 != NULL)
    {
        insEnd(&poly3, p1->coff, p1->expo);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        insEnd(&poly3, p2->coff, p2->expo);
        p2 = p2->next;
    }
    return poly3;
}
int main()
{
    struct polynode *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
    poly1 = getnode();
    poly2 = getnode();
    insEnd(&poly1,10,4);
    insEnd(&poly1,1,3);
    insEnd(&poly1,11,2);
    insEnd(&poly1,9,0);
    display(poly1);
    insEnd(&poly2,1,3);
    insEnd(&poly2,18,2);
    insEnd(&poly2,2,0);
    display(poly2);
    poly3 = Addpolynode(&poly1, &poly2);
    display(poly3);
    return 0;
}