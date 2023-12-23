// Online C compiler to run C program online
// Online C compiler to run C program online
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
}
void insbeg(struct node **start, int x)
{
    struct node *newNode;
    newNode = getnode();
    newNode->info = x;
    newNode->prev = NULL;
    newNode->next = *start;
    if (*start != NULL)
        (*start)->prev = newNode;
    *start = newNode;
}

void insEnd(struct node **start, int item)
{
    struct node *head, *newNode;
    head = *start;
    newNode = getnode();
    newNode->info = item;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL)
    {
        *start = newNode;
        newNode->prev = NULL;
    }
    else
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = (newNode);
        newNode->prev = head;
    }
}
void insafter(struct node **start, struct node **current, int x)
{
    struct node *newNode, *nextNode;
    if ((*current)->next == NULL)
    {
        insEnd(start, x);
    }
    else
    {
        newNode = getnode();
        nextNode = getnode();
        newNode->info = x;
        if (*start == NULL)
        {
            newNode->next = NULL;
            newNode->prev = NULL;
            *start = newNode;
        }
        else
        {
            nextNode = (*current)->next;
            newNode->prev = (*current);
            newNode->next = (nextNode);
            nextNode->prev = newNode;
            (*current)->next = newNode;
        }
    }
}

void inBefore(struct node **start, struct node **curr, int x)
{
    struct node *new, *previousNode;
    if ((*curr)->prev == NULL)
    {
        insbeg(start, x);
    }
    else
    {
        new = getnode();
        previousNode = getnode();
        new->info = x;
        if (*start == NULL)
        {
            new->next = NULL;
            new->prev = NULL;
            *start = new;
        }
        else
        {
            previousNode = (*curr)->prev;
            new->prev = (*curr)->prev;
            (*curr)->prev = new;
            new->next = (*curr);
            previousNode->next = new;
        }
    }
}
void display(struct node *start)
{
    while (start != NULL)
    {
        printf("%d<->", start->info);
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
    struct node *head;
    head = *start;
    if (head == NULL)
        printf("void deletion\n");
    else
    {
        int x = head->info;
        *start = head->next;
        (*start)->prev = NULL;

        free(head);
        return x;
    }
}

int delEnd(struct node **start)
{
    struct node *head, *q;
    head = *start;
    int item;
    if (head == NULL)
    {
        printf("Void Deletion\n");
    }
    else if (head->next == NULL)
    {
        *start = head->next;
        free(head);
    }
    else
    {
        while (head->next != NULL)
        {
            q = head;
            head = head->next;
        }
        q->next = NULL;
        item = head->info;
        free(head);
        return item;
    }
}
int delbefore(struct node **start,struct node *node)
{
    if (node->prev == NULL || node == NULL)
    {
        printf("void deletion\n");
        return -1;
    }
    else if ((node->prev)->prev == NULL)
    {
        struct node *p, *r;
        p = NULL;
        r = node->prev;
        node->prev = p;
        *start=node;
        printf("deleted node is %d\n", r->info);
        free(r);
    }
    else
    {
        struct node *p, *r;
        p = node->prev;
        r = p->prev;
        r->next = node;
        node->prev = r;
        int x = p->info;
        printf("deleted node is %d\n", p->info);
        free(p);
        return x;
    }
}
int delAfter(struct node **start,struct node *node)
{
    if (node == NULL || node->next == NULL)
    {
        printf("void deletion\n");
        return -1;
    }
    else if (node->next->next == NULL)
    {
        struct node *p, *r;
        r = node->next;
        p = r->next;
        node->next = p;
        int x= r->info;
        printf("deleted node is %d\n", x);
        free(r);
    }
    else
    {
        struct node *p, *r;
        p = node->next;
        r = p->next;
        node->next = r;
        r->prev = node;
        int x = p->info;
        printf("deleted node is %d\n", x);
        free(p);
        return x;
    }
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
struct node *address(struct node *start, int x)
{
    struct node *match = NULL;
    struct node *q;
    match = start;
    do
    {
        if (match->info == x)
        {
            q = match;
            break;
        }
        match = match->next;
    } while (match->next != start);
    return match;
}

int main()
{
    int choice, x, c, y, m = 0;
    struct node *start = NULL;
    struct node *q;
    struct node *p;
    struct node *addres;

    while (1)
    {
        printf("1. Insert Element at begining\n");
        printf("2. Insert Element at End\n");
        printf("3. Insert Element after given node\n");
        printf("4. Insert Element before given node\n");
        printf("5. Delete Element from begining\n");
        printf("6. Delete Element from end\n");
        printf("7. Delete Element after given node\n");
        printf("8. Delete Element before given node\n");
        printf("9. display Doubly Linked list\n");
        printf("10. find count of nodes in LL\n");
        printf("11.quit\n");
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
            addres = address(start, x);
            if (p == NULL)
            {
                printf("node not found\n");
                break;
            }
            else
            {
                printf("ENTER DATA\n");
                scanf("%d", &y);
                insafter(&start, &addres, y);
                display(start);
                break;
            }
        case 4:
            printf("enter the data to after \n");
            scanf("%d", &x);
            addres = address(start, x);
            if (p == NULL)
            {
                printf("node not found\n");
                break;
            }
            else
            {
                printf("ENTER DATA\n");
                scanf("%d", &y);
                inBefore(&start, &addres, y);
                display(start);
                break;
            }

        case 5:
            x = delBig(&start);
            printf("deleted data is %d\n", x);
            break;
        case 6:
            x = delEnd(&start);
            printf("deleted data is %d\n", x);
            break;
        case 7:
            printf("enter the data to delete next node\n");
            scanf("%d", &x);
            addres = address(start, x);
            if (addres == NULL)
            {
                printf("node not found\n");
                break;
            }
            else
            {
                delAfter(&start,addres);
                break;
            }
        case 8:
            printf("enter the data to delete before node\n");
            scanf("%d", &x);
            addres = address(start, x);
            if (addres == NULL)
            {
                printf("node not found\n");
                break;
            }
            else
            {
                delbefore(&start,addres);
                break;
            }

        case 9:
            display(start);
            break;
        case 10:
            c = countnode(start);
            printf("number of nodes are: %d", c);
            break;
        case 11:
            exit(0);
        default:
            printf("invalid choice\n");
            break;
        }
    }
    return 0;
}
// Online C compiler to run C program online
// Online C compiler to run C program online
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
}
void insbeg(struct node **start, int x)
{
    struct node *newNode;
    newNode = getnode();
    newNode->info = x;
    newNode->prev = NULL;
    newNode->next = *start;
    if (*start != NULL)
        (*start)->prev = newNode;
    *start = newNode;
}

void insEnd(struct node **start, int item)
{
    struct node *head, *newNode;
    head = *start;
    newNode = getnode();
    newNode->info = item;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL)
    {
        *start = newNode;
        newNode->prev = NULL;
    }
    else
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = (newNode);
        newNode->prev = head;
    }
}
void insafter(struct node **start, struct node **current, int x)
{
    struct node *newNode, *nextNode;
    if ((*current)->next == NULL)
    {
        insEnd(start, x);
    }
    else
    {
        newNode = getnode();
        nextNode = getnode();
        newNode->info = x;
        if (*start == NULL)
        {
            newNode->next = NULL;
            newNode->prev = NULL;
            *start = newNode;
        }
        else
        {
            nextNode = (*current)->next;
            newNode->prev = (*current);
            newNode->next = (nextNode);
            nextNode->prev = newNode;
            (*current)->next = newNode;
        }
    }
}

void inBefore(struct node **start, struct node **curr, int x)
{
    struct node *new, *previousNode;
    if ((*curr)->prev == NULL)
    {
        insbeg(start, x);
    }
    else
    {
        new = getnode();
        previousNode = getnode();
        new->info = x;
        if (*start == NULL)
        {
            new->next = NULL;
            new->prev = NULL;
            *start = new;
        }
        else
        {
            previousNode = (*curr)->prev;
            new->prev = (*curr)->prev;
            (*curr)->prev = new;
            new->next = (*curr);
            previousNode->next = new;
        }
    }
}
void display(struct node *start)
{
    while (start != NULL)
    {
        printf("%d<->", start->info);
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
    struct node *head;
    head = *start;
    if (head == NULL)
        printf("void deletion\n");
    else
    {
        int x = head->info;
        *start = head->next;
        (*start)->prev = NULL;

        free(head);
        return x;
    }
}

int delEnd(struct node **start)
{
    struct node *head, *q;
    head = *start;
    int item;
    if (head == NULL)
    {
        printf("Void Deletion\n");
    }
    else if (head->next == NULL)
    {
        *start = head->next;
        free(head);
    }
    else
    {
        while (head->next != NULL)
        {
            q = head;
            head = head->next;
        }
        q->next = NULL;
        item = head->info;
        free(head);
        return item;
    }
}
int delbefore(struct node **start,struct node *node)
{
    if (node->prev == NULL || node == NULL)
    {
        printf("void deletion\n");
        return -1;
    }
    else if ((node->prev)->prev == NULL)
    {
        struct node *p, *r;
        p = NULL;
        r = node->prev;
        node->prev = p;
        *start=node;
        printf("deleted node is %d\n", r->info);
        free(r);
    }
    else
    {
        struct node *p, *r;
        p = node->prev;
        r = p->prev;
        r->next = node;
        node->prev = r;
        int x = p->info;
        printf("deleted node is %d\n", p->info);
        free(p);
        return x;
    }
}
int delAfter(struct node **start,struct node *node)
{
    if (node == NULL || node->next == NULL)
    {
        printf("void deletion\n");
        return -1;
    }
    else if (node->next->next == NULL)
    {
        struct node *p, *r;
        r = node->next;
        p = r->next;
        node->next = p;
        int x= r->info;
        printf("deleted node is %d\n", x);
        free(r);
    }
    else
    {
        struct node *p, *r;
        p = node->next;
        r = p->next;
        node->next = r;
        r->prev = node;
        int x = p->info;
        printf("deleted node is %d\n", x);
        free(p);
        return x;
    }
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
struct node *address(struct node *start, int x)
{
    struct node *match = NULL;
    struct node *q;
    match = start;
    do
    {
        if (match->info == x)
        {
            q = match;
            break;
        }
        match = match->next;
    } while (match->next != start);
    return match;
}

int main()
{
    int choice, x, c, y, m = 0;
    struct node *start = NULL;
    struct node *q;
    struct node *p;
    struct node *addres;

    while (1)
    {
        printf("1. Insert Element at begining\n");
        printf("2. Insert Element at End\n");
        printf("3. Insert Element after given node\n");
        printf("4. Insert Element before given node\n");
        printf("5. Delete Element from begining\n");
        printf("6. Delete Element from end\n");
        printf("7. Delete Element after given node\n");
        printf("8. Delete Element before given node\n");
        printf("9. display Doubly Linked list\n");
        printf("10. find count of nodes in LL\n");
        printf("11.quit\n");
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
            addres = address(start, x);
            if (p == NULL)
            {
                printf("node not found\n");
                break;
            }
            else
            {
                printf("ENTER DATA\n");
                scanf("%d", &y);
                insafter(&start, &addres, y);
                display(start);
                break;
            }
        case 4:
            printf("enter the data to after \n");
            scanf("%d", &x);
            addres = address(start, x);
            if (p == NULL)
            {
                printf("node not found\n");
                break;
            }
            else
            {
                printf("ENTER DATA\n");
                scanf("%d", &y);
                inBefore(&start, &addres, y);
                display(start);
                break;
            }

        case 5:
            x = delBig(&start);
            printf("deleted data is %d\n", x);
            break;
        case 6:
            x = delEnd(&start);
            printf("deleted data is %d\n", x);
            break;
        case 7:
            printf("enter the data to delete next node\n");
            scanf("%d", &x);
            addres = address(start, x);
            if (addres == NULL)
            {
                printf("node not found\n");
                break;
            }
            else
            {
                delAfter(&start,addres);
                break;
            }
        case 8:
            printf("enter the data to delete before node\n");
            scanf("%d", &x);
            addres = address(start, x);
            if (addres == NULL)
            {
                printf("node not found\n");
                break;
            }
            else
            {
                delbefore(&start,addres);
                break;
            }

        case 9:
            display(start);
            break;
        case 10:
            c = countnode(start);
            printf("number of nodes are: %d", c);
            break;
        case 11:
            exit(0);
        default:
            printf("invalid choice\n");
            break;
        }
    }
    return 0;
}
