// Binary Tree Cameras - https://leetcode.com/problems/binary-tree-cameras/

// T.C = O(N)
class Solution
{
    // no. of cameras needed
    int count;

    // different states at different nodes regarding camera
    int needCamera = -1, haveCamera = 0, covered = 1;

    // checking that which node is at which state
    int checkCameras(TreeNode *node)
    {
        // if we have a node then
        if (node)
        {
            // checking the states of right and left childs
            int l = checkCameras(node->left);
            int r = checkCameras(node->right);

            // any of the child needs camera then
            if (l == needCamera or r == needCamera)
            {
                // I have to give a camera
                count++;
                // so now I have the camera
                return haveCamera;
            }
            // if both my child are already covered then I need a camera
            else if (l == covered and r == covered)
                return needCamera;
        }
        // otherwise we don't need anything, and assume we're covered
        return covered;
    }

public:
    int minCameraCover(TreeNode *root)
    {
        if (checkCameras(root) == needCamera)
            count++;
        return count;
    }
};