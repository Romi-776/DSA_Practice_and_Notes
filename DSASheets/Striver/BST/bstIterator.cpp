/*
OPTIMIZED APPROACH
Maintaining a stack in order to store/simulate some of the inorder traversal nodes
by going to extremeLeft of the root/curr_node and after popping trying to add nodes
in the right subtree in sorted manner. 

T.C = O(1)(approx) for operations like hasNext and next, S.C = O(H) (approx) 
*/
class BSTIterator {
    stack<TreeNode*> nodes;
    void goToExtremeLeft(TreeNode* curr) {
        while (curr)
            nodes.push(curr), curr = curr->left;
    }
public:
    BSTIterator(TreeNode* root) {
        goToExtremeLeft(root);
    }
    
    int next() {
        TreeNode* node = nodes.top();
        nodes.pop();
        goToExtremeLeft(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return nodes.size();
    }
};



/*
MY NAIVE APPROACH :
Storing all the nodes in a vector using inorder traversal and then
using basic iterator to go to next nodes. 

T.C = O(1) for operations like hasNext and next,S.C = O(N)
*/
class BSTIterator {
    vector<int> nodes;
    void inorder(TreeNode* curr) {
        if (curr) {
            inorder(curr->left);
            nodes.push_back(curr->val);
            inorder(curr->right);
        }
    }
    int i;
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
        i = -1;
    }
    
    int next() {
        return nodes[++i];
    }
    
    bool hasNext() {
        return (i < int(nodes.size()-1));
    }
};