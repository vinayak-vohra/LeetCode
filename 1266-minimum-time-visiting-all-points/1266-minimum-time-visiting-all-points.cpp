#include <bits/stdc++.h>
using namespace std;

#define dist(pts, idx) (max(abs(pts[idx][0] - pts[idx - 1][0]), abs(pts[idx][1] - pts[idx - 1][1])))

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int time = 0;
        for (int i = 1; i < points.size(); i++)
            time += dist(points, i);
        return time;
    }
};