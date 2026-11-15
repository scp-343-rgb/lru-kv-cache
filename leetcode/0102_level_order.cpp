#include <queue>
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

vector<vector<int>> levelOrder(TreeNode* root)
{
    queue <TreeNode*> q;
    vector <vector<int>> result;
    vector <int> level;
    if (root == nullptr) return result;
    q.push(root);
    while (!q.empty()) {
        int cnt = q.size();
        while (cnt != 0) {
            TreeNode* curr = q.front();
            q.pop();
            level.push_back(curr->val);
            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
            cnt--;
        }
        result.push_back(level);
        level.clear();
    }
    return result;
}