#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void inOrder(TreeNode* root, vector<int>& result)
{
    if (root->left != nullptr) inOrder(root->left, result);
    result.push_back(root->val);
    if (root->right != nullptr) inOrder(root->right, result);
}

bool isValidBST(TreeNode* root)
{
    if (root == nullptr) return true;
    vector<int> result;
    inOrder(root, result);
    for (size_t i = 1;i < result.size();i++) {
        if (result[i] <= result[i - 1]) return false;
    }
    return true;
}