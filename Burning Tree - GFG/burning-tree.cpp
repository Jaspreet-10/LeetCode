//{ Driver Code Starts
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
    int minTime(Node* root, int target) 
    {
        if(!root)
            return 0;
        Node*t = NULL;
        queue<Node*>q;
        unordered_map<Node*,Node*>m;
        unordered_map<Node*,int>visited;
        q.push(root);
        while(!q.empty()){
            Node* head = q.front();
            if(head->data == target){
                t = head;
                // cout<<t->data<<" ";
            }
            // cout<<head->data<<" ";
            q.pop();
            if(head->left){
                q.push(head->left);
                m[head->left] = head;
            }
             if(head->right){
                q.push(head->right);
                m[head->right] = head;
            }
        }
        int distance = 0;
        q.push(t);
        while(!q.empty()){
            int size = q.size();
            for(int i = size-1;i>=0;--i){
            Node* head = q.front();
            q.pop();
            if(head->left && head->left!=t && visited[head->left]!=1){
                q.push(head->left);
                visited[head->left] = 1;
            }
            if(head->right && head->right!=t && visited[head->right]!=1){
                q.push(head->right);
                visited[head->right] = 1;
            }
            if(m[head] && m[head]!=t && visited[m[head]]!=1){
                q.push(m[head]);
                visited[m[head]] = 1;
            }
            }
            ++distance;        
        }
        return distance-1;
    }
};

//{ Driver Code Starts.

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