class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s2.size()>s1.size()) 
           swap(s1,s2);

        deque<string> deq1, deq2;
        stringstream ss1(s1);
        string word;
        while(ss1>>word)
             deq1.push_back(word);
        
        stringstream ss2(s2);
        while(ss2>>word)
            deq2.push_back(word);
        
        while(!deq1.empty() && !deq2.empty() && deq1.front()==deq2.front())
        {
            deq1.pop_front();
            deq2.pop_front();
        }

        while(!deq1.empty() && !deq2.empty() && deq1.back()==deq2.back())
        {
            deq1.pop_back();
            deq2.pop_back();
        }

        return deq2.empty();
    }
};