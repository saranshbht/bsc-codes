#include<bits/stdc++.h>
using namespace std;

bool findIfAdjacent(vector<int> &v, int i){
	int n = v.size();
	for(int j = 0; j < n; j++)
		if(v[j] == i)
			return true;
	return false;
}

bool isBipartite(int i, vector<vector<int> > &graph, bool *visited){
	queue<int> q;
	q.push(i);
	int dist[graph.size() + 1] = {0};
	dist[i] = 1;
	visited[i] = true;
	while(!q.empty()){
		i = q.front();
		cout << i << " ";
		int n = graph[i].size();
		for(int j = 0; j < n; j++){
			if(!visited[graph[i][j]]){
				dist[graph[i][j]] = dist[i] + 1;
				q.push(graph[i][j]);
				visited[graph[i][j]] = true;
			}
		}
		q.pop();
	}
	int n = graph.size();
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			if(dist[i] == dist[j] && (findIfAdjacent(graph[i], j) || findIfAdjacent(graph[j], i)))
				return false;
		}
	}
	return true;
}

int main(){
	int n, m, u, v, source;
	cout << "Enter number of vertices n(named 1...n): ";
	cin >> n;
	vector<vector<int> > graph(n + 1);
	cout << "Enter number of edges: ";
	cin >> m;
	cout << "Enter edges:\n";
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		if(u > n || v > n || u < 1 || v < 1){
			cout << "Invalid vertices\n";
			return -1;
		}
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bool visited[n + 1] = {false};
	cout << "Enter source vertex: ";
	cin >> source;
	if(source < 1 || source > n){
		cout << "Invalid source vertex\n";
		return -1;
	}
	
	if(isBipartite(source, graph, visited))
		cout << "\nThe graph is bipartite";
	else 
		cout << "\nThe graph is not bipartite";
	cout << endl;
	return 0;
}
