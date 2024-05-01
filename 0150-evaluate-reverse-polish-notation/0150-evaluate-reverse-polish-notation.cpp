#define isOp(op) (op == '+' || op == '-' || op == '*' || op == '/')

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(int i = 0; i < tokens.size(); i++)
        {
            if(*(tokens[i].end() - 1) < '0')
            {
                int a = stk.top();
                stk.pop();

                int b = stk.top();
                stk.pop();

                switch(tokens[i][0]){
                    case '+': 
                                stk.push(b + a);
                                break;
                    case '-': 
                                stk.push(b - a);
                                break;
                    case '*': 
                                stk.push(b * a);
                                break;
                    case '/': 
                                stk.push(b / a);
                                break;
                }
            }
            else
                stk.push(stoi(tokens[i]));
        }
        return stk.top();
    }
};