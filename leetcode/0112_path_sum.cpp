using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode* root, int& sum, int targetSum)
{
    if (root == nullptr) return false;
    sum += root->val;
    if (root->left == nullptr && root->right == nullptr && sum == targetSum)return true;
    bool isLeft = dfs(root->left,sum, targetSum);
    bool isRight = dfs(root->right,sum, targetSum);
    sum -= root->val;
    return isLeft || isRight;
}

bool hasPathSum(TreeNode* root, int targetSum)
{
    int sum = 0;
    return dfs(root, sum, targetSum);
}