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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        vector<int> criticalPoints;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int pos = 1;

        while (curr->next) {
            ListNode* next = curr->next;
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                criticalPoints.push_back(pos);
            }
            prev = curr;
            curr = next;
            pos++;
        }

        if (criticalPoints.size() < 2)
            return {-1, -1};

        int minDist = INT_MAX;
        int maxDist = criticalPoints.back() - criticalPoints.front();

        for (int i = 1; i < criticalPoints.size(); i++) {
            minDist = min(minDist, criticalPoints[i] - criticalPoints[i - 1]);
        }

        return {minDist, maxDist};
    }
};