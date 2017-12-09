#include <iostream>

using namespace std;

//Structure of Linked List
struct node
{
	int num;
	struct node *next;
};
typedef struct node *NODEPTR;

NODEPTR head=NULL;
NODEPTR head1=NULL;

//Node Creation
struct node* node_creation(int val)
{
	struct node *p;
	p=(NODEPTR)malloc(sizeof(struct node));
	p->num=val;
	p->next=NULL;
	return p;
}

//Singly Linked List Creation
struct node* createll(struct node **temp, int val)
{
	struct node *ptr;
	ptr = *temp;
	if(*temp==NULL)
	{
		*temp=node_creation(val);
	}

	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
	ptr->next=node_creation(val);
	}
}

//Singly Linked List Display
int display(struct node **temp)
{
	struct node *ptr;
	ptr=*temp;
	if(*temp==NULL)
	{
		cout << "List Empty" << endl; return 0;
	}
	
	else
	{
		while(ptr!=NULL)
		{
			cout << ptr->num << " ";
			ptr = ptr->next;
		}
	}
	cout << endl;
}

//Insertion in Singly Linked List in beginning
void insert_begning(struct node **temp, int val)
{
	struct node *p = node_creation(val);
	p->next=*temp;
	*temp= p;
}

//Count Number of elements in Singly Linked List
int get_count(struct node **head)
{
	struct node *temp;
	temp=*head;
	int count=0;
	if(*head==NULL)
	{return 0;}
	
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;	
	}
return count;
}

//Get Nth elements in Singly Linked List
int get_nth(NODEPTR head, int n)
{
	struct node *temp;
	temp=head;
	int count=1, value;
	if(head==NULL)
	{return 0;}

	if(n>get_count(&head) || n<=0)
	{cout << "value out of range"<< endl;}
	else
	{
		while(temp!=NULL && count <=n)
		{
			count++;
			value = temp->num;
			temp=temp->next;	
		}
	cout << value << endl;
	}	
}

//Get median in Singly Linked List
int get_median(NODEPTR head)
{
	int count = get_count(&head)/2;
	if(count % 2 == 0)
	{
		get_nth(head, count);
	}
	else
	{
		get_nth(head, count+1);
	}
}

//Get End Nth elements in Singly Linked List
int get_end_nth(NODEPTR head, int n)
{
	struct node *slow, *fast;
	fast=head;
	slow=head;

	for(int i=0;i<n;i++)
	{fast=fast->next;}

	while(fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
	}
	cout << slow->num << endl;
}

//Insert element at Nth position in Singly Linked List
struct node* insert_at_n_pos(struct node **temp, int n, int value)
{

	struct node *ptr = *temp;
	
	if(ptr==NULL)
	{return 0;}
	int count = get_count(&ptr);
	if(count < n)
	{cout << "n value out of range" << endl; return 0;}

	for(int i = 1;i<n-1;i++)
	{ptr=ptr->next;}

	struct node *node_ptr = node_creation(value);
	node_ptr->next = ptr->next;
	ptr->next=node_ptr;	
}

//Copy all elements from one Linked List to other
int copy_list(NODEPTR head1, NODEPTR *head2)
{
	if(head1==NULL)
	{return 0;}
	
	while(head1!=NULL)
	{	
		createll(head2, head1->num);
		head1=head1->next;
	}
}

//Insert elements in Sorted Linked List
struct node* insert_sorted(struct node **head, int val)
{
	struct node *cur=*head;
	struct node *pre;
	struct node *node_ptr = node_creation(val);

	if(cur->num > val)
	{	
		node_ptr->next = *head;
		*head = node_ptr;
		return 0;		
	}

	while(cur->next != NULL)
	{
		if(cur->num > val)
		{
			node_ptr->next = cur;
			pre->next = node_ptr;
			return 0;		
		}
		else
		{	
			pre=cur;
			cur=cur->next;
			//cout << "else cur->num " << cur->num << " and pre->num "<< pre->num << endl;
		}
	}

	cur->next = node_ptr;
}

//get middle Value in Linked List
void middle_value(struct node **temp)
{
	struct node *slow, *fast;
	slow=*temp;
	fast=*temp;

	while(fast!=NULL)
	{
		fast=fast->next;
		if(fast)
		fast=fast->next;
		if(fast)
		slow = slow->next;
	}

	cout << slow->num << endl;
}

//Split Linked List in two parts
void split(struct node **temp, struct node **head1)
{
	struct node *slow, *fast;
	slow=*temp;
	fast=*temp;

	while(fast!=NULL)
	{
		fast=fast->next;
		if(fast)
		fast=fast->next;
		if(fast)
		slow = slow->next;
	}

	*head1=slow->next;
	slow->next=NULL;
}

//Reverse the Linked List
struct node* reverse(struct node *temp)
{
	struct node *prev=NULL;
	struct node *cur = temp;
	struct node *forw;

	while(cur!=NULL)
	{
		forw = cur->next;
		cur->next=prev;
		prev = cur;
		cur = forw;
	}
	
	return prev;

}

//Reverse the Linked List (2 step method)
void reverse_2_steps(struct node *temp)
{
	struct node *cur=temp;
	
	while(cur->next!=NULL)
	{
		int v = cur->next->num;
		cur->next->num=cur->num;
		cur->num=v;
		cur=cur->next->next;
	}
		
}

//Delete node in Linked List
void deletenode(struct node **head)
{
	struct node *cur = *head;
	*head = cur->next;
	delete cur;
}

//Delete all nodes in Linked List
void deleteallnodes(struct node **head)
{
	while(*head!=NULL)
	{
		deletenode(head);
	}
}

//Delete all duplicate elements in Linked List
int deleteduplicates(struct node *head)
{
	struct node *temp = head;
	struct node *next_next;
	if(head==NULL)
	{
		return 0;
	}
	
	while(temp->next!=NULL)
	{
		if(temp->num == temp->next->num)
		{
			next_next = temp->next->next;
			free(temp->next);
			temp->next=next_next;
		}
		else
		{	
			temp=temp->next;
		}
	}	
}

// Use the above funtions over here
int main()
{

	for (int i = 0;i<=5;i++)
	{createll(&head, i);}
	insert_begning(&head, 100);
	insert_begning(&head, 200);
	int count = get_count(&head);
	cout << "count " << count << endl;
	display(&head);
	get_end_nth(head, 0);
	insert_at_n_pos(&head, 3, 300);
	display(&head);
	copy_list(head, &head1);
	display(&head1);
	insert_sorted(&head, 6);
	insert_sorted(&head, 10);
	insert_sorted(&head, 11);
	insert_sorted(&head, 0);
	display(&head);
	middle_value(&head);
	split(&head, &head1);
	display(&head);
	display(&head1);
	head1 = reverse(head1);
	display(&head1);
	reverse_2_steps(head);
	display(&head);
	createll(&head, 1);
	createll(&head, 1);
	createll(&head, 1);
	createll(&head, 2);
	createll(&head, 2);
	createll(&head, 2);
	createll(&head, 3);
	display(&head);
	deleteduplicates(head);
	display(&head);
	return 0;
}
