// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* treeConstruct(int pre[],int preStart,int preEnd,int in[],int inStart,
    int inEnd,unordered_map<int,int>&m){
        if(preStart>preEnd || inStart>inEnd)
            return NULL;
        Node* root = new Node(pre[preStart]);
        int inRoot = m[pre[preStart]];
        int numsLeft = inRoot-inStart;
        root->left = treeConstruct(pre,preStart+1,preStart+numsLeft,in,inStart,
                                    inRoot-1,m);
        root->right = treeConstruct(pre,preStart+numsLeft+1,preEnd,in,inRoot+1,
                                    inEnd,m);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        unordered_map<int,int>m;
        for(int i = 0 ; i < n ; ++i){
            m[in[i]]=i;
        }
        Node* root = treeConstruct(pre,0,n-1,in,0,n-1,m);
        return root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends