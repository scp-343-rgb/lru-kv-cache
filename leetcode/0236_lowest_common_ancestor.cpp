using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == nullptr)return nullptr;
    if (root == p || root == q)return root;
    TreeNode* leftResult = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightResult = lowestCommonAncestor(root->right, p, q);
    if (leftResult != nullptr && rightResult != nullptr)return root;
    else if (leftResult != nullptr)return leftResult;
    else if (rightResult != nullptr)return rightResult;
    else return nullptr;
}