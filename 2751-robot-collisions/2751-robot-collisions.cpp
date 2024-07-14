#pragma GCC optimize("03", "unroll-loops")
struct Robots {
    int idx;
    int pos;
    int health;
    char dir;
    Robots() : idx(-1), pos(-1), health(-1), dir('-') {}
    Robots(int i, int p, int h, char d) : idx(i), pos(p), health(h), dir(d) {}
};

constexpr bool byIndex(const Robots& a, const Robots& b) {
    return a.idx < b.idx;
}
constexpr bool byPosition(const Robots& a, const Robots& b) {
    return a.pos < b.pos;
}

class Solution {

public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h,
                                      string d) {
        int n = h.size();
        vector<Robots> robots(n);
        for (int i = 0; i < n; ++i)
            robots[i] = Robots(i, p[i], h[i], d[i]);

        sort(robots.begin(), robots.end(), byPosition);

        vector<Robots> stk;
        stk.reserve(n);

        for (auto& r : robots) {
            if (stk.empty()) {
                stk.emplace_back(r);
                continue;
            }

            bool push = true;
            auto top = stk.rbegin();
            while (top->dir == 'R' && r.dir == 'L' && top->health <= r.health) {
                stk.pop_back();
                if (top->health == r.health) {
                    push = false;
                    break;
                }
                --r.health;
                if (stk.size())
                    top = stk.rbegin();
                else
                    break;
            }

            if (!push)
                continue;
            if (stk.empty() || top->dir == 'L' || r.dir == 'R')
                stk.emplace_back(r);
            else
                --top->health;
        }

        sort(stk.begin(), stk.end(), byIndex);
        vector<int> ans;
        ans.reserve(stk.size());
        for (auto& r : stk)
            ans.push_back(r.health);

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
