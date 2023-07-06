//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution{
    
public:
    Node * midNode(Node * head){
        Node * slow = head;
        Node * fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    Node * merge2List(Node * list1 , Node * list2){
        Node * dummy = new Node();
        Node * head1 = list1;
        Node * head2 = list2;
        Node * prev = dummy;
        while(head1 != NULL && head2 != NULL){
            if(head1->data < head2->data){
                prev->next = head1;
                head1 = head1->next;
            }else{
                prev->next = head2;
                head2 = head2->next;
            }
            prev = prev->next;
        }
        prev->next = head1 != NULL ? head1 : head2;
        return dummy->next;

    }
    Node* sortList(Node* head)
    {
        if(head == NULL || head->next == NULL) return head;
        Node * mid = midNode(head);
        Node * head1 = head;
        Node * head2 = mid->next;
        mid->next = NULL;
        Node * sortedHead1 = sortList(head1);
        Node * sortedHead2 = sortList(head2);
        return merge2List(sortedHead1 , sortedHead2);
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		// printList(head);
		
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}

// } Driver Code Ends