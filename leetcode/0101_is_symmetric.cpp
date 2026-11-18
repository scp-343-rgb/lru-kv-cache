#include <utility>
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

/*void swapTree(TreeNode* root)
{
    if (root == nullptr) return;
    swap(root->left, root->right);
    swapTree(root->left);
    swapTree(root->right);
}

void dfs(TreeNode* root,vector<int>& result)
{
    if (root == nullptr) {
        result.push_back(1000);
        return;
    }
    result.push_back(root->val);
    dfs(root->left,result);
    dfs(root->right,result);
}

bool isSymmetric(TreeNode* root)
{
    if (root == nullptr) return true;
    swapTree(root->right);
    vector<int> left, right;
    dfs(root->left, left);
    dfs(root->right, right);
    if (left.size() != right.size()) return false;
    for (size_t i = 0;i < left.size();i++) {
        if (left[i] != right[i]) return false;
    }
    return true;
}*/

bool mirroCheck(TreeNode* a, TreeNode* b)
{
    if (a == nullptr && b == nullptr) return true;
    else if (a == nullptr || b == nullptr)return false;
    else if (a->val != b->val) return false;
    else return mirroCheck(a->left, b->right) && mirroCheck(a->right, b->left);
}

bool isSymmetric(TreeNode* root)
{
    if (root == nullptr) return true;
    return mirroCheck(root->left, root->right);
}