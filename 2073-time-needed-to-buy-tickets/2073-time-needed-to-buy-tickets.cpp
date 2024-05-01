class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sum = 0;
        int x = tickets[k];
        for (int i = 0; i <= k; i++)
            sum += std::min(tickets[i], x);

        for (int i = k + 1; i < tickets.size(); i++)
            sum += std::min(tickets[i], x - 1);
        return sum;
    }
};