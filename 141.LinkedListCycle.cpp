/*
    1. Track visited nodes.
        Time complexity: O(n), Space complexity: O(n)
    2. Floyd's Cycle-Finding Algorithm.
        Time: O(n), Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
};
int main() {
    ListNode *head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(0);
    // head->next->next->next = new ListNode(-4);
    // head->next->next->next->next = head->next;
    int pos = 1;
    Solution solution;
    bool ans = solution.hasCycle(head);
    cout << "Output: " << ans<< endl;
    
    return 0;
}

/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.
*/
/*
Constraints:
    1.  The number of the nodes in the list is in the range [0, 104].
    2.  -10^5 <= Node.val <= 10^5
    3.  pos is -1 or a valid index in the linked-list.
*/