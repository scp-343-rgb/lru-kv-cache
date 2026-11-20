#include <algorithm>
#include <cstdlib>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int height(TreeNode* root,bool& found)
{
    if (root == nullptr)return 0;
    int leftHeight = height(root->left,found);
    int rightHeight = height(root->right, found);
    if (abs(leftHeight - rightHeight) > 1) found = false;
    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode* root)
{
    bool found = true;
    height(root, found);
    return found;
}