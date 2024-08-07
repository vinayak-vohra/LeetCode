unordered_map<int, string> toWords = {
    {0, ""},          {1, "One"},      {2, "Two"},        {3, "Three"},
    {4, "Four"},      {5, "Five"},     {6, "Six"},        {7, "Seven"},
    {8, "Eight"},     {9, "Nine"},     {10, "Ten"},

    {11, "Eleven"},   {12, "Twelve"},  {13, "Thirteen"},  {14, "Fourteen"},
    {15, "Fifteen"},  {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"},
    {19, "Nineteen"}, {20, "Twenty"},

    {30, "Thirty"},   {40, "Forty"},   {50, "Fifty"},     {60, "Sixty"},
    {70, "Seventy"},  {80, "Eighty"},  {90, "Ninety"},
};

class Solution {
    string parse(int num) {
        string ans = "";

        if (num >= 100) {
            ans += ((toWords[num / 100]) + " Hundred ");
            num %= 100;
        }

        if (num < 20) {
            ans += toWords[num];
        } else {
            ans += toWords[num / 10 * 10] + " " + toWords[num % 10];
        }

        if (ans.size() && ans.back() == ' ')
            ans.pop_back();
        return ans;
    }

public:
    string numberToWords(int num) {
        if (!num)
            return "Zero";
        unordered_map<int, string> st = {
            {1, ""}, {2, " Thousand "}, {3, " Million "}, {4, " Billion "}};

        string ans = "";
        stack<string> parsed;

        int i = 0;
        while (num) {
            parsed.push(parse(num % 1000));
            num /= 1000;
        }

        while (parsed.size()) {
            ans += parsed.top();

            if (parsed.top().size())
                ans += st[parsed.size()];
            parsed.pop();
        }
        if (ans.back() == ' ')
            ans.pop_back();
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();