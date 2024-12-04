class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> has;

        for (int a : arr) {
            if (has.count(2 * a))
                return true;
            else if (!(a & 1) && has.count(a / 2))
                return true;
            has.insert(a);
        }
        return false;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();