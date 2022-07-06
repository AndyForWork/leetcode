#include <iostream>


using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void remake(TreeNode* root, int& prev)
    {
        if (root->right != nullptr)
        {
            remake(root->right, prev);
            root->val += prev;
        }
        else
            root->val += prev;
        prev = root->val;
        if (root->left != nullptr)
            remake(root->left, prev);
    }
    TreeNode* convertBST(TreeNode* root) {
        int prev = 0;
        if (root != nullptr)
            remake(root, prev);
        return root;
    }

};

int main()
{
    Solution s;
    TreeNode* tr = new TreeNode(4,
        new TreeNode(1, new TreeNode(0), new TreeNode(2, nullptr, new TreeNode(3))),
        new TreeNode(6, new TreeNode(5), new TreeNode(7, nullptr, new TreeNode(8))));
    cout << s.convertBST(tr);
}
