#include<bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int> > &graph, bool *visited, int *start, int *finish, int &time){
	time++;
	visited[i] = true;
	start[i] = time;
	int n = graph[i].size();
	cout << i << " ";
	for(int j = 0; j < n; j++)
		if(!visited[graph[i][j]])
			dfs(graph[i][j], graph, visited, start, finish, time);
	time++;
	finish[i] = time;
}

void descendants(int j, int *start, int *finish, int n){
	vector<int> v; 
	for(int i = 1; i <= n; i++)
		if(i != j&& start[i] > start[j] && finish[j] > finish[i])
			v.push_back(i);
	int size = v.size();
	cout << j << "\n";
	if(size == 0)
		cout << "No descendants";
	else{
		cout << "Descendants\n";
		for(int &i : v)
			cout << i << " ";
	}
	cout << endl << endl;
	
}

void ancestors(int j, int *start, int *finish, int n){
	vector<int> v; 
	for(int i = 1; i <= n; i++)
		if(i != j && start[i] < start[j] && finish[j] < finish[i])
			v.push_back(i);
	int size = v.size();
	cout << j << "\n";
	if(size == 0)
		cout << "No ancestors";
	else{
		cout << "Ancestors\n";
		for(int &i : v)
			cout << i << " ";
	}
	cout << endl << endl;
	
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
	int start[n + 1] = {0};
	int finish[n + 1] = {0};
	cout << "DFS\n";
	dfs(source, graph, visited, start, finish, time);
	for(int i = 1; i <= n; i++)
		if(!visited[i])
			dfs(i, graph, visited, start, finish, time);
	cout << endl;
	for(int i = 1; i <= n; i++)
		ancestors(i, start, finish, n);
	for(int i = 1; i <= n; i++)
		descendants(i, start, finish, n);
	return 0;
}
