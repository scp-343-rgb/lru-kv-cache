#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode* root, int& best)
{
    if (root == nullptr) return 0;
    int leftHeight = dfs(root->left, best);
    int rightHeight = dfs(root->right, best);
    best = max(best, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode* root)
{
    int best = 0;
    dfs(root, best);
    return best;
}