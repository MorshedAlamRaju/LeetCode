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

    
    string to_str(int n){
        string s;
        if(n == 0)return "0";
        while(n){
            s += (n % 10) + '0';
            n /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)return "";
        vector<string> res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false){
            root = q.front();
            q.pop();
            if(root == NULL){
                res.push_back("null");
                continue;
            }
            res.push_back(to_str(root->val));
            q.push(root->left);
            q.push(root->right);
        }
        char c = '[', d = ']';
        string ans;
        ans += c;
        while(res.size() && res.back() == "null")res.pop_back();
        for(auto x : res)ans += x, ans += ',';
        if(res.size())ans.pop_back();
        ans += d;
        return ans;
        
    }
    
    int to_int(string s){
        int n = 0;
        for(char c : s){
            n = n * 10 + (c - '0');
        }
        return n;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        for(int i = 0; data[i]; i++){
            if(data[i] == ',' || data[i] == '[' || data[i] == ']')
                data[i] = ' ';
        }
        
        string n;
        vector<string> tree;
        vector<TreeNode*> nodes;
        stringstream ss(data);
        while(ss >> n)tree.push_back(n);
        
        int len = tree.size();
        for(int i = 0; i < len; i++)
            if(tree[i] == "null")nodes.push_back(NULL);
            else nodes.push_back(new TreeNode(to_int(tree[i])));
        
        if(len < 1 || nodes.front() == NULL)return NULL;

        int idx = 1;
        for(int i = 0; i < len; i++){
            if(nodes[i] != NULL){
                if(idx < len)nodes[i]->left = nodes[idx++];
                if(idx < len)nodes[i]->right = nodes[idx++];
            }
        }
        
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));