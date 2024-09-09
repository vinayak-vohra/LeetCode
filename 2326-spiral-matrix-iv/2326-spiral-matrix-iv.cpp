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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0, i = 0, j = -1;
        while (head) {
            int ni = i + dirs[d].first;
            int nj = j + dirs[d].second;

            if (ni < 0 || nj < 0 || ni == m || nj == n || ans[ni][nj] != -1) {
                d = (d + 1) % 4;
            } else {
                ans[ni][nj] = head->val;
                head = head->next;
                i = ni;
                j = nj;
            }
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();