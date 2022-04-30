// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* treeConstruct(int post[],int postStart,int postEnd,int in[],int inStart,
    int inEnd,unordered_map<int,int>&m){
        if(postStart>postEnd || inStart>inEnd)
            return NULL;
        Node* root = new Node(post[postEnd]);
        int inRoot = m[post[postEnd]];
        int numsLeft = inRoot-inStart;
        root->left = treeConstruct(post,postStart,postStart+numsLeft-1,in,inStart,
                                    inRoot-1,m);
        root->right = treeConstruct(post,postStart+numsLeft,postEnd-1,in,inRoot+1,
                                    inEnd,m);
        return root;
    }
Node *buildTree(int in[], int post[], int n) {
        unordered_map<int,int>m;
        for(int i = 0 ; i < n ; ++i){
            m[in[i]]=i;
        }
        Node* root = treeConstruct(post,0,n-1,in,0,n-1,m);
        return root;
}
