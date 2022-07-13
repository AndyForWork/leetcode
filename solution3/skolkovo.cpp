#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> mass;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while (q.front()!=nullptr)
        {
            vector<int> cur_level;
            while (q.front()!=nullptr)
            {
                cur_level.push_back(q.front()->val);
                if (q.front()->left != nullptr)
                    q.push(q.front()->left);
                if (q.front()->right != nullptr)
                    q.push(q.front()->right);
                q.pop();
            }
            q.pop();
            q.push(nullptr);
            mass.push_back(cur_level);
        }
        return mass;
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    s.levelOrder(root);

}