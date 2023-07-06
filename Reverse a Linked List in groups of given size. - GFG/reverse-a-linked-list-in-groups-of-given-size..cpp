//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    int length(node * head){
        if(head == NULL) return 0;
        int len = 0;
        node * curr = head;
        while(curr != NULL){
            curr = curr->next;
            len++;
        }
        return len;
    }
    node * th = NULL;
    node * tt = NULL;
    void addFirst(node * node){
        if(th == NULL){
            th = node;
            tt = node;
        }else{
            node->next = th;
            th = node;
        }
    }
    struct node *reverse (struct node *head, int k)
    { 
        if(head == NULL || head->next == NULL || k == 0) return head;
        int len = length(head);
        node * oh = NULL;
        node * ot = NULL;
        node * curr = head;
        while(len > 0){
            int tempk = k;
            while(tempk-- && len != 0){
                node * forward = curr->next;
                curr->next = NULL;
                addFirst(curr);
                curr = forward;
                len--;
            }  
            if(oh == NULL){
                oh = th;
                ot = tt;
            }else{
                ot->next = th;
                ot = tt;
            }
            th = NULL;
            tt = NULL;
        }
        
        return oh;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends