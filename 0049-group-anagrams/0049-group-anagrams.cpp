class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> index;

        for(string& str: strs) {
            string base = "a0b0c0d0e0f0g0h0i0j0k0l0m0n0o0p0q0r0s0t0u0v0w0x0y0z0";

            for(char& ch: str) 
                ++base[2 * (ch - 'a')];

            if(index.find(base) == index.end()) {
                index[base] = result.size();
                result.push_back({str});
            }
            else {
                result[index[base]].push_back(str);
            }
        }
        return result;
    }
};