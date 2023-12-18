#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
int main()
{
    int n1,n2, i = 0;
    int digit;
    struct node *start1 = NULL;
    struct node *start2 = NULL;
    struct node *start3 = NULL;
    printf("Enter the number of digits of n1\n");
    scanf("%d", &n1);
    printf("enter the digits from left to right\n");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &digit);
        insEnd(&start1, digit);
    }
    display(start1);
    printf("Enter the number of digits of n2\n");
    scanf("%d", &n2);
    printf("enter the digits from left to right\n");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &digit);
        insEnd(&start2, digit);
    }
    display(start2);
    reverse(&start1);
    reverse(&start2);
    struct node *p=NULL;
    struct node *q=NULL;
    int sum,data,carry=0;
        p=start1;
        q=start2;
    while(p!=NULL || q!=NULL){
        data=(carry+ p->info + q->info)%10;
        carry=(carry+ p->info + q->info)/10;
        p=p->next;
        q=q->next;
        insEnd(&start3,data);
    }
    reverse(&start3);
    printf("after addition:-");
    display(start3);
    return 0;
}