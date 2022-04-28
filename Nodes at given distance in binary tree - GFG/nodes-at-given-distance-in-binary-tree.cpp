// { Driver Code Starts
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
    Node* start = NULL;
    Node* findNode(Node*root,int target){
        if(!root)
            return NULL;
        if(root->data == target){
         start = root;
         return root;   
        }
        findNode(root->left,target);
        findNode(root->right,target);
        return root;
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        queue<Node*>q;
        q.push(root);
        unordered_map<Node*,Node*>map;
        unordered_map<Node*,int>visited;
        while(!q.empty()){
            int size = q.size();
            for(int i = size-1;i>=0;--i){
                Node *head = q.front();
                q.pop();
                if(head->left){
                    map[head->left] = head;
                    q.push(head->left);   
                }
                if(head->right){
                   map[head->right] = head;
                   q.push(head->right);   
                }
            }
        }
        findNode(root,target);
        if(start!=NULL){
        q.push(start);
        visited[start] = 1;
        }
        int distance = 0;
        while(distance<k){
            int size = q.size();
            for(int i = size-1;i>=0;--i){
                Node* head = q.front();
                q.pop();
                if(map[head] and visited[map[head]]==0){
                    visited[map[head]] = 1;
                    q.push(map[head]);
                }
                if(head->left and visited[head->left]==0){
                    visited[head->left] = 1;
                    q.push(head->left);
                }
                if(head->right and visited[head->right]==0){
                    visited[head->right] = 1;
                    q.push(head->right);
                }
            }
            ++distance;
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

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