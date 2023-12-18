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
void insafter(struct node **start, struct node *q, int x)
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
        p->next = (q)->next;
        (q)->next = p;
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
int main()
{
    int choice, x, c, y, m = 0;
    struct node *start = NULL;
    struct node *q;
    struct node *p;
    while (1)
    {
        printf("1. Insert element at begining\n");
        printf("2. Insert element at End\n");
        printf("3. Insert element after given node\n");
        printf("4. delete element from begining\n");
        printf("5. delete element from end\n");
        printf("6. delete element after given node\n");
        printf("7. display Linked list\n");
        printf("8. reverse Linked list\n");
        printf("9. find count of nodes in LL\n");
        printf("10.quit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the data\n");
            scanf("%d", &x);
            insbeg(&start, x);
            break;
        case 2:
            printf("enter the data\n");
            scanf("%d", &x);
            insEnd(&start, x);
            break;
        case 3:
            printf("enter the data to after \n");
            scanf("%d", &x);
            p = start;
            while (p != NULL){
                if (p->info == x)
                {
                    q = p;
                    m++;
                    break;
                }
                p = p->next;
            } 
            if (m == 0)
            {
                printf("node not found\n");
                break;
            }
            else
            {
                printf("ENTER DATA\n");
                scanf("%d", &y);
                insafter(&start,q, y);
                display(start);
                break;
            }

        case 4:
            x = delBig(&start);
            printf("deleted data is %d\n", x);
            break;
        case 5:
            x = delEnd(&start);
            printf("deleted data is %d\n", x);
            break;
        case 6:
            printf("enter the data to delete next node\n");
            scanf("%d", &x);
            p = start;
             while (p != NULL)
            {
                if (p->info == x)
                {
                    q = p;
                    m++;
                    break;
                }
                p = p->next;
            }
            if (m == 0)
            {
                printf("node not found\n");
                break;
            }
            else
            {
                delAfter(q);
                break;
            }

        case 7:
            display(start);
            break;
        case 8:
        reverse(&start);
        display(start);
            break;
        case 9:
            c = countnode(start);
            printf("number of nodes are: %d\n", c);
            break;
        case 10:
            exit(0);
        default:
            printf("invalid choice\n");
            break;
        }
    }
    return 0;
}














// int main()
// {
//     // struct node *start = NULL, *p, *q;
//     // insEnd(&start, 0);
//     // insbeg(&start, 3);
//     // insbeg(&start, 1);
//     // insbeg(&start, 9);
//     // insbeg(&start, 5);
//     // display(start);
//     // printf("\nitem deleted %d\n", delBig(&start));
//     // display(start);
//     // int x = 0;
//     // {
//     //     p = start;
//     //     while (p != NULL)
//     //     {
//     //         if (p->info == x)
//     //         {
//     //             q = p;
//     //             break;
//     //         }
//     //         p = p->next;
//     //     }
//     //     printf("\nitem deleyted %d\n", delAfter(q));
//     // }
//     // display(start);
//     // printf("\n%d nodes are present\n", countnode(start));
//     // reverse(&start);
//     // display(start);

// }
//     return 0;
// }
