#include "skeleton.hpp"
#include <iostream>
#include <queue>

using namespace std;

void graph :: add_edge(int a, int b){

	if(a == b)
		return;
	else if(has_edge(a, b))
		return;

	//Occurs if the top two conditions are not met
	adjList.at(a).push_back(b);
	++edges;
	
}

bool graph :: has_edge(int a, int b){

	for(auto n : adjList.at(a)){
		if(n == b)
			return true;
		}

	return false;
	
}

int graph :: count_nodes(){
	return nodes;
}

int graph :: count_edges(){
	return edges;	
}

vector<int> graph :: bfs(int n){

	vector<int> nodeDistance(nodes, INT_MAX);

	nodeDistance.at(n) = 0;

	queue<int> queue;
	queue.push(n);


	while (!queue.empty()) {
		int n = queue.front();
		queue.pop();

		for (auto i : adjList.at(n)) {

			if (nodeDistance.at(i) == INT_MAX) { 

				nodeDistance.at(i) = nodeDistance.at(n) + 1;
				queue.push(i);
			}
		}
	}
	return nodeDistance;
}

bool graph :: is_connected(int a, int b){

	vector<int> breadthSearch = bfs(a);

	if(breadthSearch.at(b) == INT_MAX)
		return false;

	else
		return true;
	
}
