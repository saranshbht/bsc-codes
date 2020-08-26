#include<bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int> > &graph, bool *visited, pair<int, int> *start, pair<int, int> *finish, int &time){
	time++;
	visited[i] = true;
	start[i].first = time;
	int n = graph[i].size();
	cout << i << " ";
	for(int j = 0; j < n; j++)
		if(!visited[graph[i][j]])
			dfs(graph[i][j], graph, visited, start, finish, time);
	time++;
	finish[i].first = time;
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
		//graph[v].push_back(u);
	}
	bool visited[n + 1] = {false};
	cout << "Enter source vertex: ";
	cin >> source;
	if(source < 1 || source > n){
		cout << "Invalid source vertex\n";
		return -1;
	}
	
	int time = 0; 
	pair<int, int> start[n + 1];
	pair<int, int> finish[n + 1];
	for(int i = 0; i <= n; i++){
		start[i].first = finish[i].first = 0;
		start[i].second = finish[i].second = i;
	}
	dfs(source, graph, visited, start, finish, time);
	for(int i = 1; i <= n; i++)
		if(!visited[i])
			dfs(i, graph, visited, start, finish, time);
	cout << endl;
	sort(finish, finish + n + 1);
	for(int i = n; i > 0; i--)
		cout << finish[i].second << " ";
	cout << endl;
	return 0;
}
