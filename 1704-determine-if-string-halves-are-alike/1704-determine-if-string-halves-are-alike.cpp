constexpr bool isVowel(const char &ch)
{
    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return true;

    default:
        return false;
    }
}

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        auto mid = s.begin() + s.size() / 2;
        return count_if(s.begin(), mid, isVowel) ==
               count_if(mid, s.end(), isVowel);
    }
};