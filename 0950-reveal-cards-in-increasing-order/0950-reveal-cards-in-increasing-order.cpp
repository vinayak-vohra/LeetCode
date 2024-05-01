/* class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

    }
};*/
#pragma GCC optimize("03", "unroll-loops")
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n);
        sort(deck.begin(), deck.end());

        queue<int> q;
        for (int i = 0; i < n; i++)
            q.push(i);

        int k = 0;
        while (q.size()) {
            ans[q.front()] = deck[k++];
            q.pop();
            q.push(q.front());
            q.pop();
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