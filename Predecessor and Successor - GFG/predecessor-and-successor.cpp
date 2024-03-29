//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
// void inOrder(Node* root, Node*& pre, Node*& suc,int key,int &ans1 , int &ans2){
//     if(!root)
//         return ;
//     if(root->key == key && ans1==-1){
//         if(root->left){
//             Node* tmp = root->left;
//             pre = tmp;
//             while(tmp->right){
//                 tmp = tmp->right;
//                 if(!tmp->right)
//                     break;
//             }
//             pre = tmp;
//         }else{
//             pre = NULL;
//         }
//         if(root->right){
//             Node* tmp = root->right;
//             cout<<tmp->key<<":";
//             suc = tmp;
//             while(tmp->left){
//                 tmp = tmp->left;
//                 if(!tmp->left)
//                     break;
//             }
//             suc = tmp;
//         }else{
//             suc = NULL;
//         }
//         return;
//         ans1 = root->key; 
//     }
//         inOrder(root->left,pre,suc,key,ans1,ans2);
//         inOrder(root->right,pre,suc,key,ans1,ans2);
//     return ;
// }
// int ans1 = -1 , ans2 = -1;
//     inOrder(root,pre,suc,key,ans1,ans2);
//     return;
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
        suc = NULL,pre = NULL;
        Node* tmp = root;
        while (tmp != NULL) {
            
            if (key >= tmp->key) {
                tmp = tmp->right;
            } else {
                suc = tmp;
                tmp = tmp->left;
            }
        }
        tmp = root;
        while (root != NULL) {
            
            if (key <= root->key) {
                root = root->left;
            } else {
                pre = root;
                root = root->right;
            }
        }
    return ;
}