class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        auto isPallindrome = [](string& word){
            for(int i=0, j = word.size() - 1; i < j; i++, j--)
                if(word[i] != word[j])
                    return false;
            return true;
        };

        for(string& word: words)
            if(isPallindrome(word))
                return word;
    
        return "";
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();