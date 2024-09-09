class Solution {
    int gcd(int a, int b) {
        if (!b)
            return a;
        return gcd(b, a % b);
    }

public:
    string fractionAddition(string exp) {
        int num = 0, den = 1, i = exp.size();
        while (--i >= 0) {
            
            // parse den
            int p = 1, n = 0, d = 0;
            while (exp[i] != '/') {
                d += p * (exp[i--] - '0');
                p *= 10;
            }

            // parse num
            p = 1;
            while (--i >= 0 && exp[i] != '+' && exp[i] != '-') {
                n += p * (exp[i] - '0');
                p *= 10;
            }

            // handle sign
            if (i >= 0 && exp[i] == '-')
                n *= -1;

            

            // gcd
            int g = gcd(den, d);
            
            num *= (d / g);
            n *= (den / g);
            num += n;
            den = (den * d) / g;
            
        }
        int g = gcd(abs(num), den);
        num /= g;
        den /= g;
        return to_string(num) + "/" + to_string(den);
    }
};
