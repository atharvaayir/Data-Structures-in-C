/*Program to implement all basic operations in Linked List:
1.Create a list
2.Print the list
3.Count of nodes
4.Search for element
5.Add at the beginning
6.Add at the end
7.Add after the node
8.Add before the node
9.Add at a given position
10.Delete a node
11.Reverse a linked list
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node* link;
};
struct node* addbeg(struct node*,int);
struct node* addend(struct node*,int);
struct node* create_list(struct node* start)
{
	int n;
	printf("Enter the number of elements in the linked list\n");
	scanf("%d",&n);
	if(n==0)
	return start;
	else if(n==1)
	{
		int k;
		printf("Enter data to be added\n");
		scanf("%k",&k);
		start=addbeg(start,k);
	}
	else
	{
	   int k,i;
		printf("Enter data to be added\n");
		scanf("%d",&k);
		start=addbeg(start,k);
		
		for(i=0;i<n-1;i++)
		{
			printf("Enter data to be added\n");
			scanf("%d",&k);
			start=addend(start,k);
		}
		
		
	}
	return start;
}

struct node* addbeg(struct node* start,int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node*));
	temp->info=data;
	temp->link=start;
	start=temp;
	return start;
	
	
}
struct node* addend(struct node* start,int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node*));
	struct node *p=start;
	while(p->link!=NULL)
	{
		p=p->link;
	}
	p->link=temp;
	temp->info=data;
	temp->link=NULL;
	return start;
}
void display(struct node* start)
{
	struct node* p=start;
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n");
}
struct node* addafternode(struct node* start,int node_value,int data)
{
	struct node* p=start;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
    }
	else
	{
		while(p!=NULL)
		{
			if(p->info==node_value)
			{
				struct node* temp=(struct node*)malloc(sizeof(struct node*));
				temp->info=data;
				temp->link=p->link;
				p->link=temp;
				
				return start;
			}
			p=p->link;
		}
	}
	printf("Node not found\n");
	return start;
}
struct node* addbeforenode(struct node* start,int node_value,int data)
{
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	else
	{
		struct node *p=start;
		while(p!=NULL)
		{
			if((p->link)->info==node_value)
			{
				struct node* temp=(struct node*)malloc(sizeof(struct node*));
				temp->info=data;
				temp->link=p->link;
				p->link=temp;
				return start;
			}
			p=p->link;
		}
		printf("Node not found\n");
		return start;
	}
	
	
	
}
struct node* addnodeatpos(struct node* start,int pos,int data)
{
	struct node *p=start;
	int i=1;
	if(pos==1)
	{
		struct node* temp=(struct node*)malloc(sizeof(struct node*));
	    temp->info=data;
		temp->link=start;
	    start=temp;
	    return start;
	}
	while(p!=NULL)
	{
		for(i=1;i<pos-1&&p!=NULL;i++)
		{
			
			p=p->link;
		}
		if(p==NULL)
		{
			printf("There are less than %d elements\n",pos);
		}
		else
		{
		struct node* temp=(struct node*)malloc(sizeof(struct node*));
	    temp->info=data;
		temp->link=p->link;
	    p->link=temp;	
		
		}
		return start;

	}
}
struct node* delnode(struct node* start,int data)
{
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	else if(start->info==data)
	{
		struct node * temp=start;
		start=start->link;
		free(temp);
		return start;
	}
	else
	{
		struct node* p=start;
		while(p->link!=NULL)
		{
			if((p->link)->info==data)
			{
				struct node* temp=p->link;
				p->link=temp->link;
				free(temp);
				return start;
			
			}
			p=p->link;
		}

}
	printf("Node not found\n");
	return start;

}
struct node* reverse(struct node* start)
{
	if(start==NULL)
	{
		printf("The list is empty\n");
		return start;
	}
	struct node* ptr,*next,*prev;
	prev=NULL;
	ptr=start;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;
	printf("The list has been reversed\n");
	return start;
}
void count(struct node* start)
{
	struct node* p=start;
	int i=0;
	while(p!=NULL)
	{
		p=p->link;
		i++;
	}
	printf("The number of nodes=%d\n",i);
}
void search(struct node* start)
{
	if(start==NULL)
	{
	printf("List is empty\n");return;
	}
	int k;
	printf("Enter the data to be searched\n");
	scanf("%d",&k);
	int pos=1;
	struct node *p=start;
	while(p!=NULL)
	{
		if(p->info==k)
		{
			printf("Data found at %d position\n",pos);
			return;
			
		}
		p=p->link;
		pos++;
	}
	printf("Data not found\n");
	
	
}

int main()
{
	int k,j,pos;
	struct node* start=NULL;
	while(1)
	{
		int c;
		printf("1.Create a list\n2.Print the list\n3.Count of nodes\n4.Search for element\n5.Add at the beginning\n6.Add at the end\n7.Add after the node\n8.Add before the node\n9.Add at a given position\n10.Delete a node\n11.Reverse a linked list\n12.Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			 case 1:
			 	start=create_list(start);
			 	break;
			 case 2:
			    display(start);
				break;
			case 3:
			  count(start);
			  break;
			case 4:
			  search(start);
			  break; 		
			case 5:
				//int k;
				printf("Enter data to be added at the beginning\n");
				scanf("%d",&k);
				start=addbeg(start,k);
				break;
			case 6:
				//int k;
				printf("Enter the data to be added at the end\n");
				scanf("%d",&k);
				start=addend(start,k);
				break;
			case 7:
			//	int k,j;
				printf("Enter the node data value\n");
				scanf("%d",&j);
				printf("Enter the data to be added \n");
				scanf("%d",&k);
				start=addafternode(start,j,k);
				break;
			case 8:
				printf("Enter the node data value\n");
				scanf("%d",&j);
				printf("Enter the data to be added \n");
				scanf("%d",&k);
				start=addbeforenode(start,j,k);
				break;
			case 9:
				printf("Enter the position to which new node should be added\n");
				scanf("%d",&pos);
				printf("Enter the data to be added\n");
				scanf("%d",&k);
				start=addnodeatpos(start,pos,k);
				break;
			case 10:
				printf("Enter data of node to be deleted\n");
				scanf("%d",&k);
				start=delnode(start,k);
				break;	
			case 11:
				start=reverse(start);
				break;
			case 12:
				exit(1);
			defualt:
			printf("Wrong choice!!Try again\n");		
				
		}
		
	}
	
	
	
	
}
