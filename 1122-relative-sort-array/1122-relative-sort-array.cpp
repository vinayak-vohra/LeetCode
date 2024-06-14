class Solution {
    struct Int {
        int val = 1001;
    };
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, Int> index;
        for(int i = 0; i < arr2.size(); ++i)
            index[arr2[i]] = Int(i);

        sort(arr1.begin(), arr1.end(), [&index](int a, int b){
            if(index[a].val == index[b].val)
                return a < b;
            return index[a].val < index[b].val;
        });
        return arr1;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();