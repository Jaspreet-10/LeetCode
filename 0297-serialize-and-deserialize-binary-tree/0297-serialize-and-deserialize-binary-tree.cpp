/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
     if(!root) return "";
     string str = "";
     queue<TreeNode*>q;
     q.push(root);   
     while(!q.empty()){
            TreeNode* head = q.front();
            q.pop();
            if(head == NULL) str+="#,";
            else{
                str+=to_string(head->val)+",";
                q.push(head->left);
                q.push(head->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* head = q.front();
            q.pop();
            getline(s,str,',');
            if(str == "#")
                head->left = NULL;
            else{
                head->left = new TreeNode(stoi(str));
                q.push(head->left);
            }
             getline(s,str,',');
            if(str == "#")
                head->right = NULL;
            else{
                head->right = new TreeNode(stoi(str));
                q.push(head->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));