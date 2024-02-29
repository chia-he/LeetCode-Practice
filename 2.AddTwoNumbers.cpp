/*
    1.
        Time complexity: O(n), Space complexity: O(n)
    2.
        Time: O(n), Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            ListNode *head = new ListNode();
            ListNode *tail = head;
            int carry = 0;
            while (l1 || l2 || carry) {
                int digit1 = l1 ? l1->val : 0;
                int digit2 = l2 ? l2->val : 0;
                int sum = digit1 + digit2 + carry;
                int digit = sum % 10;
                carry = sum / 10;

                tail->next = new ListNode(digit);
                tail = tail->next;
                l1 = l1 ? l1->next : 0;
                l2 = l2 ? l2->next : 0;
            }
            return head->next;
        }
};
int main() {
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(2, new ListNode(6, new ListNode(6)));
    Solution solution;
    ListNode *ans = solution.addTwoNumbers(l1, l2);
    cout << "Output: " << endl;
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}

/*
You are given two non-empty linked lists representing two non-negative
integers. The digits are stored in reverse order, and each of their nodes
contains a single digit. Add the two numbers and return the sum as a linked
list. You may assume the two numbers do not contain any leading zero, except
the number 0 itself.*/
/*
Constraints:
    1.  The number of the nodes in the list is in the range [0, 100].
    2.  0 <= Node.val <= 9
    3.  It is guaranteed that the list represents a number that does not have
leading zeros.
*/