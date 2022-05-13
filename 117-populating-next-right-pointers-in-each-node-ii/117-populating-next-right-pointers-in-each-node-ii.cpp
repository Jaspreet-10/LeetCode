/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        	// base case
        if(root==NULL)
            return root;
			// make a queue to store the Node*
        queue<Node*> q;
		// push the root
        q.push(root);
        while(!q.empty())
        {
		// size of queue
            int n = q.size();
            for(int i=0;i<n;i++)
            {
			// pop the element
                Node* temp = q.front();
                q.pop();
				// check if their is next element then point the next pointer to it
                if(i+1<n)
                {
                    temp->next=q.front();
                }
				// if no next then point to NULL
                else
                {
                    temp->next=NULL;
                }
				// check if left or right elemnt are their or not , if their then push them in queue
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
		// return the root of tree
        return root;

    }
};