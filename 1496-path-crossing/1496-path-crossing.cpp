class coords
{
    int x, y;

public:
    coords() : x(0), y(0) {}
    coords(int a, int b) : x(a), y(b) {}

    friend coords operator+(const coords &, const coords &);
    friend bool operator==(const coords &, const coords &);
    friend bool operator<(const coords &, const coords &);
    friend bool operator<=(const coords &, const coords &);
    friend bool operator>(const coords &, const coords &);
    friend bool operator>=(const coords &, const coords &);
};

coords operator+(const coords &A, const coords &B)
{
    return coords(A.x + B.x, A.y + B.y);
}

bool operator==(const coords &lhs, const coords &rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator<(const coords &lhs, const coords &rhs)
{
    if (lhs.x < rhs.x)
        return true;

    else if (lhs.x > rhs.x)
        return false;

    else
        return lhs.y < rhs.y;
}

bool operator<=(const coords &lhs, const coords &rhs)
{
    return lhs == rhs ? 1 : lhs < rhs;
}

bool operator>(const coords &lhs, const coords &rhs)
{
    if (lhs.x > rhs.x)
        return true;

    else if (lhs.x < rhs.x)
        return false;

    else
        return lhs.y > rhs.y;
}

bool operator>=(const coords &lhs, const coords &rhs)
{
    return lhs == rhs ? 1 : lhs > rhs;
}

class Solution{
public: 
    bool isPathCrossing(std::string path)
    {
        std::set<coords> visited;
        std::unordered_map<char, coords> dirs{
            {'N', coords(0, 1)},
            {'E', coords(1, 0)},
            {'W', coords(-1, 0)},
            {'S', coords(0, -1)},
        };
        coords cur;
        visited.insert(cur);
        for (const char &dir : path)
        {
            cur = cur + dirs[dir];

            if (visited.find(cur) != visited.end())
                return true;

            visited.insert(cur);
        }
        return false;
    }
};