class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});

        char prev = '\0';
        bool dup = 0;

        string ans = "";

        while (pq.size()) {
            auto top = pq.top();
            pq.pop();

            // cannot have 3rd same letter
            if (top.second == prev && dup) {
                if (pq.empty())
                    break;
                auto next = pq.top();
                pq.pop();
                ans += next.second;
                if (--next.first)
                    pq.push(next);
                dup = 0;
                prev = next.second;
                pq.push(top);
            }

            else {
                ans += top.second;
                if (--top.first)
                    pq.push(top);

                if (top.second == prev)
                    dup = 1;
                else
                    prev = top.second;
            }
        }
        return ans;
    }
};