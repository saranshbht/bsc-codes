#include<bits/stdc++.h>
using namespace std;
void firstFit(int *memory, int *p, int n, int m){
	cout << "Memory allocation according to First-Fit technique\n";
	int mem[n];
	int process[m];
	for(int i = 0; i < n; i++)
		mem[i] = memory[i];
	for(int i = 0; i < m; i++)
		process[i] = p[i];
	bool flag;
	for(int i = 0; i < m; i++){
		flag = false;
		for(int j = 0; j < n; j++){
			if(process[i] <= mem[j]){
				cout << "Process " << i + 1 << " is assigned block " << j + 1 << "(" << mem[j] << ")\n";
				mem[j] -= process[i];
				flag = true;
				break; 
			}
		}
		if(!flag)
			cout << "Process " << i + 1 << " must wait.\n";
	}
	
	int frag = 0;
	for(int i = 0; i < n; i++)
		frag += mem[i];
	cout << "Total fragmentation: " << frag << "\n\n"; 
}

void bestFit(int *memory, int *p, int n, int m){
	cout << "Memory allocation according to Best-Fit technique\n";
	int mem[n];
	int process[m];
	for(int i = 0; i < n; i++)
		mem[i] = memory[i];
	for(int i = 0; i < m; i++)
		process[i] = p[i];
	int best;
	int pos;
	for(int i = 0; i < m; i++){
		best = INT_MAX;
		pos = -1;
		for(int j = 0; j < n; j++){
			if(process[i] <= mem[j] && mem[j] < best){
					best = mem[j];
					pos = j;
			}
		}
		if(pos != -1){
			cout << "Process " << i + 1 << " is assigned block " << pos + 1 << "(" << mem[pos] << ")\n";
			mem[pos] -= process[i];
		}
		else
			cout << "Process " << i + 1 << " must wait.\n";		
	}
	
	int frag = 0;
	for(int i = 0; i < n; i++)
		frag += mem[i];
	cout << "Total fragmentation: " << frag << "\n\n";
}

void worstFit(int *memory, int *p, int n, int m){
	int worst;
	int pos;
	int mem[n];
	int process[m];
	for(int i = 0; i < n; i++)
		mem[i] = memory[i];
	for(int i = 0; i < m; i++)
		process[i] = p[i];
	cout << "Memory allocation according to Worst-Fit technique\n";
	for(int i = 0; i < m; i++){
		worst = INT_MIN;
		pos = -1;
		for(int j = 0; j < n; j++){
			if(process[i] <= mem[j] && mem[j] > worst){
					worst = mem[j];
					pos = j;
			}
		}
		if(pos != -1){
			cout << "Process " << i + 1 << " is assigned block " << pos + 1 << "(" << mem[pos] << ")\n";
			mem[pos] -= process[i];
		}
		else
			cout << "Process " << i + 1 << " must wait.\n";		
	}
	
	int frag = 0;
	for(int i = 0; i < n; i++)
		frag += mem[i];
	cout << "Total fragmentation: " << frag << "\n\n";
}

int main(){
	int n, m;
	cout << "Enter no of memory blocks available: ";
	cin >> n;
	int mem[n];
	cout << "Enter size of each block\n";
	for(int i = 0; i < n; i++)
		cin >> mem[i];
	cout << "Enter no of processes: ";
	cin >> m;
	int process[m];
	cout << "Enter memory requirement of each process\n";
	for(int i = 0; i < m; i++)
		cin >> process[i];
	firstFit(mem, process, n , m);
	bestFit(mem, process, n, m);
	worstFit(mem, process, n, m);
	
	return 0;
}
