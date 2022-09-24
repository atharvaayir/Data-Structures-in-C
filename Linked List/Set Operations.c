/*
Program to implement basic set operations using Linked List
*/
#include <stdio.h>
#include<stdlib.h>  
struct node
{
    int info;
    struct node *link;
};

struct node *addbeg(struct node *start, int k)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->link = NULL;
    tmp->info = k;
    start = tmp;
    return start;
}
struct node *addend(struct node *start, int k)
{
    struct node *p = start;
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    while (p->link != NULL)
    {
        p = p->link;
    }
    p->link = tmp;
    tmp->info = k;
    tmp->link = NULL;
    return start;
}
struct node *create_list(struct node *start)
{
    int n, i;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    if (n == 0)
    {
        printf("Invalid input\n");
        start = create_list(start);
    }
    printf("Enter the elements\n");
    int k;
    scanf("%d", &k);
    start = addbeg(start, k);

    for (i = 0; i < n - 1; i++)
    {
        scanf("%d", &k);
        start = addend(start, k);
    }
    return start;
}
void display(struct node *p)
{
    if (p == NULL)
        printf("The set is empty\n");
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->link;
    }
}
struct node *uni(struct node *i, struct node *j, struct node *start3)
{
    struct node *k = start3;
    int s = 0;
    for (; i != NULL; i = i->link)
    {
        for (k = start3; k != NULL; k = k->link)
        {
            if (i->info == k->info)
                break;
        }
        if (k == NULL)
        {
            if (s == 0)
            {
                start3 = addbeg(start3, i->info);
                s++;
            }
            else
            {
                start3 = addend(start3, i->info);
                s++;
            }
        }
    }
    for (; j != NULL; j = j->link)
    {
        for (k = start3; k != NULL; k = k->link)
        {
            if (j->info == k->info)
                break;
        }
        if (k == NULL)
        {
            if (s == 0)
            {
                start3 = addbeg(start3, j->info);
                s++;
            }
            else
            {
                start3 = addend(start3, j->info);
                s++;
            }
        }
    }
    return start3;
}
struct node *intersec(struct node *start1, struct node *j, struct node *start3)
{
    int s = 0;
    struct node *i = start1;
    for (; j != NULL; j = j->link)
    {
        for (i = start1; i != NULL; i = i = i->link)
        {
            if (i->info == j->info)
            {
                if (s == 0)
                {
                    start3 = addbeg(start3, i->info);
                    s++;
                }
                else
                {
                    start3 = addend(start3, i->info);
                }
            }
        }
    }
    return start3;
}
struct node* diff(struct node *i,struct node* start2,struct node * start3)
{
    struct node* j=start2;
    int s=0;
    for(;i!=NULL;i=i->link)
    {
        for(j=start2;j!=NULL;j=j->link)
        {
            if(i->info==j->info)
            break;
        }
        if(j==NULL)
        {
            if(s==0)
            {
                start3=addbeg(start3,i->info);
                s++;
            }
            else
            {
                start3=addend(start3,i->info);
            }
        }
    }
    return start3;
}    


int main()
{
    struct node *start1=NULL, *start2=NULL, *start3=NULL;
    int n;
    while (1)
    {
        printf("\n1.Enter set A and B\n2.Union\n3.Intersection\n4.Difference\n5.Display set A and B\n6.Exit\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            start1=NULL;
            start2=NULL;
            start3=NULL;
            printf("For set A\n");
            start1 = create_list(start1);
            printf("For set B\n");
            start2 = create_list(start2);
            break;

        case 2:
            start3 = NULL;
            printf("Set Union:");
            start3 = uni(start1, start2, start3);
            display(start3);
            break;
        case 3:
            start3 = NULL;
            printf("Intersection set:");
            start3 = intersec(start1, start2, start3);
            display(start3);
            break;

        case 4:
        start3=NULL;
        printf("Set Difference:");
        start3=diff(start1,start2,start3);
        display(start3);
        break;
        case 5:
            printf("Set A:");
            display(start1);
            printf("\n");
            printf("Set B:");
            display(start2);
            printf("\n");
            break;
        case 6:
        exit(1);    
        }
    }
}
