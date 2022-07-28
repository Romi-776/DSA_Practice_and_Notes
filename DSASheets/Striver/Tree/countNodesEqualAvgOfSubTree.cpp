// (Use PostOrder traversal and calculate the total sum and count of nodes in left and right subtree and then check for the averageOfSubtree and update the count as required)
// 13. Count Nodes Equal to Average of Subtree
class Solution
{
    int count = 0;
    pair<int, int> find_avg(TreeNode *root)
    {
        if (root)
        {
            int totalVal = root->val, visited_nodes = 1;
            pair<int, int> l = find_avg(root->left), r = find_avg(root->right);

            totalVal += l.first + r.first, visited_nodes += l.second + r.second;

            if (totalVal / visited_nodes == root->val)
                count++;
            return {totalVal, visited_nodes};
        }
        return {0, 0};
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        find_avg(root);
        return count;
    }
};
