/*
    1. DFS (Recursive)
        Time Complexity: O(V), Space Complexity: O(h)
        log V <= h <= V
    2. BFS (Iterative)
        Time Complexity: O(V), Space Complexity: O(h)
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right)
            : val(x), left(left), right(right) {}
};

class Solution {
    public:
        int maxDepth(TreeNode *root) {
            if (!root) return 0;
            int maxLeft = maxDepth(root->left);
            int maxRight = maxDepth(root->right);
            return max(maxLeft, maxRight) + 1;
        }
        int maxDepthIterative(TreeNode *root) {
            if (!root) return 0;
            queue<TreeNode *> q;
            q.push(root);
            int depth = 0;
            while (!q.empty()) {
                ++depth;
                int size = q.size();
                for (int i = 0; i < size; ++i) {
                    TreeNode *current = q.front();
                    q.pop();
                    if (current->left) q.push(current->left);
                    if (current->right) q.push(current->right);
                }
            }
            return depth;
        }
};

int main() {
    TreeNode *head = new TreeNode(0, new TreeNode(2), new TreeNode(4));
    head->left->left = new TreeNode(1, new TreeNode(5), new TreeNode(1));
    head->right->left = new TreeNode(3, nullptr, new TreeNode(6));
    head->right->right = new TreeNode(-1, new TreeNode(8), nullptr);
    Solution solution;
    int ans = solution.maxDepth(head);
    cout << "Output: " << ans << endl;
    ans = solution.maxDepthIterative(head);
    cout << "Output: " << ans << endl;
    return 0;
}

/*
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from
the root node down to the farthest leaf node.
*/
/*
Constraints:
    1. The number of nodes in the tree is in the range [0, 10^4].
    2. -100 <= Node.val <= 100.
*/