#define len(x) x.size()
#define lb(arr, qrt, i) lower_bound(arr.begin() + qrt[i - 1], arr.begin() + qrt[i], arr[qrt[i]])
#define ub(arr, qrt, i) upper_bound(arr.begin() + qrt[i], arr.begin() + qrt[i + 1], arr[qrt[i]])

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int s = len(arr);

        if (s < 3)
            return arr[0];

        vector<int> qrt; // save pivots i.e 25% 50% 75%
        int bkt = s / 4;

        for (int i = 0; i < s - bkt; i += bkt)
        {
            if (arr[i] == arr[i + bkt]) // if 2 pivots are equal, its the answer
                return arr[i];
            qrt.push_back(i); // save indices of quarters}
        }

        qrt.push_back(s - 1); // also add last index

        for (int i = 1; i < len(qrt) - 1; i++)
            if (
                ub(arr, qrt, i) -     // find current pivot in riht subarray
                    lb(arr, qrt, i) > // find current pivot in left subarray
                bkt)                  // compare with bucket size i.e 25%
                return arr[qrt[i]];

        return arr[qrt.back()]; // won't reach here as per the question
    }
};