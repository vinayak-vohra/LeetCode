/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* solve(Node* node, unordered_map<Node*, Node*>& vis) {

        if (vis.count(node))
            return vis[node];
        Node* clone = new Node(node->val);
        vis[node] = clone;
        for (Node* adj : node->neighbors) {
            clone->neighbors.push_back(solve(adj, vis));
        }
        return clone;
    }

public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        unordered_map<Node*, Node*> vis;
        return solve(node, vis);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();