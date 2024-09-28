class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bw) {
        sort(bw.begin(), bw.end());
        int count = 0;
        for (string& msg : message) {
            count += binary_search(bw.begin(), bw.end(), msg);
            if (count > 1)
                return true;
        }
        return false;
    }
};