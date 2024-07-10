class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for (auto& log : logs) {
            if (log == "./")
                ;
            else if (log == "../")
                level = std::max(0, --level);
            else
                level++;
        }
        return level;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();