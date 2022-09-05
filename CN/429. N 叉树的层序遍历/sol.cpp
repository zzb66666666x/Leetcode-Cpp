// https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(Node* root) {
	if (root == nullptr)
	    return {};
	queue<Node*> q;
	q.emplace(root);
	vector<vector<int>> ret;
	while(q.size() > 0){
	    int cnt = q.size();
	    vector<int> l;
	    for (int i=0; i<cnt; i++){
		Node* head = q.front();
		q.pop();
		l.push_back(head->val);
		for (auto nodeptr : head->children){
		    if(nodeptr != nullptr){
			q.push(nodeptr);
		    }
		}
	    }
	    ret.push_back(move(l));
	}
	return ret;
    }
};
