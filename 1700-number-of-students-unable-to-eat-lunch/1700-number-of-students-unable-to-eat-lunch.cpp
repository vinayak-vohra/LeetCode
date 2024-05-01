class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> count(2);
        int n = students.size();
        for (int& i : students)
            count[i]++;
        int i = 0;
        while (i < n && count[sandwiches[i]]-- > 0)
            i++;
        return n - i;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();