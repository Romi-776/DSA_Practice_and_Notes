/*
OPTIMIZED SOLUTION:
Using inorder traversal and a prev node to check which node is not at its corresponding
position, and also storing them in first, second, and third nodes. There'll be two cases:
1. Adjacent nodes are not at the corresponding position 
    In this case: we'll swap the values of first and second as it will store the adjacent nodes
2. Nodes on different locations are not at the corresponding position
    In this case: we'll swap the values of first and third

T.C = O(N), S.C = O(N) // only for recursive calls
*/
class Solution {
    TreeNode* first = NULL, *second = NULL, *third = NULL;
    TreeNode* prev = NULL;
    void inorder(TreeNode* curr) {
        if (curr) {
            inorder(curr->left);
            if (prev and prev->val > curr->val)
            {
                if (first) third = curr;
                else first = prev, second = curr;
            }
            prev = curr;
            inorder(curr->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        if (third)
            swap(first->val, third->val);
        else swap(first->val, second->val);
    }
};

/*
MY NAIVE SOLUTION:
Storing all the nodes by traversing the tree and then sorting the nodes in order to fill the tree
with correct nodes using inorder traversal.

T.C = O(Nlog(N) + 2N) for traversal, S.C = O(2N) for recursive calls and storing the nodes
*/
class Solution {
    vector<int> nodes;
    int i = 0;
    void traverse(TreeNode* curr) {
        if (curr) {
            traverse(curr->left);
            nodes.push_back(curr->val);
            traverse(curr->right);
        }
    }
    void fill(TreeNode* curr) {
        if (curr) {
            fill(curr->left);
            curr->val = nodes[i++];
            fill(curr->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        traverse(root);
        sort(nodes.begin(), nodes.end());
        fill(root);
    }
};