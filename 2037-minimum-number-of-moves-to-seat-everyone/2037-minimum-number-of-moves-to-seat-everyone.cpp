class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& studs) {
        sort(seats.begin(), seats.end());
        sort(studs.begin(), studs.end());

        int ans = 0;
        for(int i = 0; i < seats.size(); ++i)
            ans += std::abs(seats[i] - studs[i]);

        return ans;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();