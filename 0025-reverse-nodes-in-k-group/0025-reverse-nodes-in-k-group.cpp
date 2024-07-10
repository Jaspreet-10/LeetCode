/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;
        
        // Count the number of nodes in the linked list
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        
        // Calculate the number of full groups of size k
        int numGroups = count / k;
        int totalReversals = numGroups * k; // Total nodes to be reversed
        
        ListNode dummy(0); // Dummy node to handle edge cases
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* cur = head;
        
        while (totalReversals > 0) {
            // Reverse k nodes
            ListNode* nex = cur->next;
            for (int i = 1; i < k; i++) {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            cur = pre->next;
            totalReversals -= k;
        }
        
        return dummy.next;
    }
};
