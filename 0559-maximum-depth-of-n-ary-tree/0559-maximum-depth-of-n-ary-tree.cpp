/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root)
            return 0;

        queue<Node*> q;
        q.push(root);

        int lvl = 0;

        while (q.size()) {
            lvl++;
            int s = q.size();
            while (s--) {
                auto f = q.front();
                q.pop();
                for (auto x : f->children)
                    q.push(x);
            }
        }
        return lvl;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();