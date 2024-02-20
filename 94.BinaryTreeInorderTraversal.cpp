/*
    inorder: left, root, right;
    1. Recursive
    Time Complexity: O(n), Space Complexity: O(h) (logn <= h <= n)
    2. Iterative (DFS)
    Time Complexity: O(n), Space Complexity: O(h) (logn <= h <= n)
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> nodeStack;
        TreeNode* current = root;
        while(current || !nodeStack.empty()) {
            while(current) {
                nodeStack.push(current);
                current = current->left;
            }
            current = nodeStack.top();
            nodeStack.pop();
            ans.push_back(current->val);
            current = current->right;
        }
        return ans;
    }
};
int main() {
    TreeNode *root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    vector<int> ans = Solution().inorderTraversal(root);
    for(int i: ans){
        cout << i << " ";
    }
    return 0;
}

/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/
/*
Constraints:
    1.  The number of nodes in the tree is in the range [0, 100].
    2.  -100 <= Node.val <= 100.
*/