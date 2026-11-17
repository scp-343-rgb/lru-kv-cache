#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void reverseTree(TreeNode* root)
{
    if (root == nullptr) return;
    swap(root->left, root->right);
    reverseTree(root->left);
    reverseTree(root->right);
}

TreeNode* invertTree(TreeNode* root)
{
    reverseTree(root);
    return root;
}