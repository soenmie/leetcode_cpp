/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) {
			return NULL;
		}
		queue<UndirectedGraphNode *> q;
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> graph_map;
		UndirectedGraphNode *cloned = new UndirectedGraphNode(node->label);
		UndirectedGraphNode *ret = cloned;
		q.push(node);
		graph_map[node] = cloned;
		while (!q.empty()) {
			node = q.front();
			q.pop();
			cloned = graph_map[node];
			for (int i = 0; i < node->neighbors.size(); ++i) {
				UndirectedGraphNode *neighbor = node->neighbors[i],
						*cloned_neighbor = graph_map[neighbor];
				if (!cloned_neighbor) {
					cloned_neighbor = new UndirectedGraphNode(neighbor->label);
					graph_map[neighbor] = cloned_neighbor;
					q.push(neighbor);
				}
				cloned->neighbors.push_back(cloned_neighbor);
			}
		}
		return ret;
	}
};
