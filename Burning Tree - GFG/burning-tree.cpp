// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
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
    int minTime(Node* root, int target) 
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
        while(!q.empty()){
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
        return distance-1;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends