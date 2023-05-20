//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
class Solution
{
private:
public:
    vector<Node*> rootToNodePath;
    bool find(Node * root , int target){
            if(root == NULL ) return false;
            if(root->data == target){
                rootToNodePath.push_back(root);
                return true;
            }
            bool left = find(root->left , target);
            if(left) { 
                rootToNodePath.push_back(root);
                return true;
            }
            bool right = find(root->right , target);
            if(right) {
                rootToNodePath.push_back(root);
                return true;
            }
            return false;
    }
    vector<int> ans;
    void printKLevelDown(Node * root , int k , Node * blocker){
        if(root == NULL || k < 0 || root == blocker) return ;
        if(k == 0) ans.push_back(root->data);
        printKLevelDown(root->left , k - 1 , blocker);
        printKLevelDown(root->right , k - 1 , blocker);
    }


    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        rootToNodePath.clear();
        ans.clear();
        bool check = find(root , target);
        if(check == false) return {};
        for(int i = 0 ; i < rootToNodePath.size()  ; i++){
            printKLevelDown(rootToNodePath[i] , k - i , i == 0 ? NULL : rootToNodePath[i - 1]);
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends