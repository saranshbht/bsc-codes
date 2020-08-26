#include<bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int> > &graph, bool *visited){
	stack<int> s;
	s.push(i);
	while(!s.empty()){
		i = s.top();
		if(!visited[i]){
			visited[i] = true;
			cout << i << " ";
		}
		s.pop();
		int n = graph[i].size();
		for(int j = 0; j < n; j++){
			if(!visited[graph[i][j]])
				s.push(graph[i][j]);
		}
	}
}
int main(){
	int n, m, u, v, source;
	cout << "Enter number of vertices(named 1...n): ";
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
	dfs(source, graph, visited);
	for(int i = 1; i <= n; i++)
		if(!visited[i])
			dfs(i, graph, visited);
	return 0;
}
