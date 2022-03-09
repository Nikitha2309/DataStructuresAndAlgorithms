#include <bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};

typedef struct node* lptr;

void append(lptr prevNode, int data)
{
    lptr newNode = new(node);
    prevNode->next = newNode;
    newNode->data = data;
    newNode->next=NULL;
}

void printLinkedList(lptr head)
{
	cout<<"Linked List : ";
    while(head!=NULL)
    {
		if(head->next)
			cout<<head->data<<"->";
		else
        	cout<<head->data;
        head = head->next;
    }
    cout<<endl;
}

void printElement(lptr ref, int index)
{
    lptr temp = ref;
    for(int i=1;i<index;i++)
	{
        temp = temp->next;
        if(temp == NULL)
		{
			cout<<"Invalid index !!"<<endl;
            return;
        }
    }
	cout << "Element at the index "<<index<<" in the given linked list is "<<temp->data<<endl;
}

int searchElement(lptr ref,int target)
{
    lptr temp = ref;
    int index = 0;
    while(temp!=NULL)
	{
        if(temp->data == target)
		{
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

void insertElement(lptr *ref,int ind,int key)
{
	ind --;
    lptr temp = *ref;
    lptr new_nod = new(node);
    new_nod->data = key;
    new_nod->next = NULL;
    lptr prev = *ref;
    for(int i=0;i<ind-1;i++){
        prev = prev->next;
        if(prev==NULL){
            cout<<"Invalid index !!"<<endl;
            return;
        }
    }
    lptr curr = prev->next;
    prev->next = new_nod;
    new_nod->next = curr;
    *ref = temp;
	cout<<"Inserted element 7 at index 6."<<endl;
}

void deleteMinimumElement(lptr *ref)
{
    int min_ind = 0;
    lptr temp = *ref;
    lptr curr = *ref;
    lptr temp2 = *ref;
    int min_Val = curr->data;
    curr = curr->next;
    int i = 1;
    while(curr!=NULL){
        if(curr->data<min_Val){
            min_ind = i;
            min_Val = curr->data;
        }
        i++;
        curr = curr->next;
    }

    lptr prev = curr;
    if(min_ind == 0)
	{
        *ref = temp -> next;
    }
	else
	{
		for(int i=1;i<min_ind;i++)
		{
        	temp2 = temp2->next;
		}
		temp2->next = temp2->next->next;
		*ref = temp;
	}
    cout<<"Deleted the minimum entry."<<endl;
}

int main()
{
	// 1. Create a linked list of size 8.
    lptr head;
    head = new(node);
    head->data = 1;
    head -> next = NULL;
    lptr curr = head;
    for(int i=1;i<8;i++)
    {
        append(curr,i+1);
        curr=curr->next;
    }
	// Print the original linked list.
    printLinkedList(head);
	cout<<endl;
	
	
	// 2. Print the 3rd element.
    printElement(head,3);
	cout<<endl;
	
	
	// 3. Search for 2 in the array.
	int index = searchElement(head,2);
	if(index==-1)
		cout<<"Element 2 is not present in the given linked list."<<endl;
	else
		cout<<"Element 2 is at the index "<<index+1<<" in the given linked list."<<endl;
	cout<<endl;
	
	
	// 4. Insert 7 in the 6th position.
    insertElement(&head,6,7);
	// Print the linked list after element insertion.
	printLinkedList(head);
	cout<<endl;
	
	
	// 5. Delete the minimum entry.
    deleteMinimumElement(&head);
    // Print the linked list after deleting minimum entry.
	printLinkedList(head);
	cout<<endl;
	
    return 0;
}