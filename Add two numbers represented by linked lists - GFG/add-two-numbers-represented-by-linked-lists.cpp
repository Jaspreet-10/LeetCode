// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
Node* reverse(Node* root){
    Node* cur=root,*prev=NULL;
    while(cur!=NULL){
        Node *temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    return prev;
}

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        Node* dummy=new Node(0);
        Node *temp=dummy;
        l1=reverse(l1);
        l2=reverse(l2);
        int c=0;
        while(l1!=NULL||l2!=NULL||c!=0){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->data;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->data;
                l2=l2->next;
            }
            sum+=c;
            if(sum>9){
                temp->next=new Node(sum%10);
                c=sum/10;
                temp=temp->next;
            }else{
                temp->next=new Node(sum);
                temp=temp->next;
                c=0;
            }
        }
        dummy=reverse(dummy->next);
        return dummy;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends