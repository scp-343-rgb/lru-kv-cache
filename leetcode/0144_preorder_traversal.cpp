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

void dfs(TreeNode* root,vector <int>& result)
{
    if (root == nullptr) return ;
    result.push_back(root->val);
    dfs(root->left,result);
    dfs(root->right,result);
}

vector<int> preorderTraversal(TreeNode* root)
{
    vector <int> result;
    dfs(root, result);
    return result;
}
