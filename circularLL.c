#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *getnode()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    return temp;
}
void insEnd(struct node **start, int item)
{
    struct node *p;
    p = getnode();
    p->data = item;
    if (start != NULL)
    {
        p->next = (*start)->next;
        (*start)->next = p;
    }
    else
    {
        p->next = p;
    }
    *start = p;
}
void insbeg(struct node **start, int item)
{
    struct node *p;
    p = getnode();
    p->data = item;
    if (*start != NULL)
    {
        p->next = (*start)->next;
        (*start)->next = p;
    }
    else
    {
        p->next = p;
        *start = p;
    }
}
void insafter(struct node *q, int item)
{
    if (q == NULL)
    {
        printf("void inserction\n");
        exit(1);
    }
    else
    {
        struct node *p;
        p = getnode();
        p->data = item;
        p->next = q->next;
        q->next = p;
    }
}
int delBig(struct node **start)
{
    if (start == NULL)
    {
        printf("void deletion\n");
    }
    else
    {
        struct node *p;
        p = (*start)->next;
        if (p->next == p)
        {
            start = NULL;
        }
        else
        {
            (*start)->next = p->next;
            int item = p->data;
            free(p);
            return item;
        }
    }
}
int delEnd(struct node **start)
{
    if (start == NULL)
    {
        printf("void deletion\n");
        return -1;
    }
    else
    {
        struct node *p, *q;
        int item;
        q = *start;
        p = (*start);
        while (p->next != (*start))
        {
            p = p->next;
        }

        item = (*start)->data;
        p->next = (*start)->next;
        (*start) = p;

        free(q);

        return item;
    }
}
int delAfter(struct node **start, struct node *q)
{
    struct node *p;
    int item;
    if (q->next == NULL || q == NULL)
    {
        printf("void deletion\n");
    }
    else
    {
        p = q->next;
        q->next = p->next;
        item = p->data;
        free(p);
        return item;
    }
}
int countnode(struct node *start)
{
    struct node *p;
    p = start;
    int count = 0;
    do
    {
        count++;
        p = p->next;
    } while (p != start);
    return count;
}
void display(struct node *start)
{
    struct node *p, *q;
    p = start->next;
    q = start;
    if (start == NULL)
    {
        printf("void display");
        exit(0);
    }
    do
    {
        printf("%d-> ", p->data);
        p = p->next;
    } while (p != q->next);
    printf("\n");
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
        printf("8. find count of nodes in LL\n");
        printf("9.quit\n");
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
            do
            {
                if (p->data == x)
                {
                    q = p;
                    m++;
                    break;
                }
                p = p->next;
            } while (p->next != start);
            if (m == 0)
            {
                printf("node not found\n");
                break;
            }
            else
            {
                printf("ENTER DATA\n");
                scanf("%d", &y);
                insafter(q, y);
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
            do
            {
                if (p->data == x)
                {
                    q = p;
                    m++;
                    break;
                }
                p = p->next;
            } while (p->next != start);
            if (m == 0)
            {
                printf("node not found\n");
                break;
            }
            else
            {
                delAfter(&start, q);
                break;
            }

        case 7:
            display(start);
            break;
        case 8:
            c = countnode(start);
            printf("number of nodes are: %d", c);
            break;
        case 9:
            exit(0);
        default:
            printf("invalid choice\n");
            break;
        }
    }
    return 0;
}
