#include<iostream>
using namespace std;

struct Process{
	int at, bt,st, ct;
	int id;
};

pswap(Process *a, Process *b){
	Process temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int n, tq;
	cout << "Enter id. of processes: ";
	cin >> n;
	Process p[n];
	cout << "Enter details" << endl;
	for(int i = 0; i < n; i++){
		//cout << "\nFor process " << endl;
		cout << "\nId: ";
		cin >> p[i].id;
		cout << "Arrival time: ";
		cin >> p[i].at;
		cout << "Burst time: ";
		cin >> p[i].bt;
	}
	
	cout << "Enter time quantum: ";
	cin >> tq;
	
	int rt[n];
	for(int i = 0; i < n; i++)
		rt[i] = p[i].bt;
	
	int arr[n], t = 0, complete = 0;
	while(complete != n){
		
		for(int i = 0; i < n; i++){
			if(rt[i] > 0){
				if(rt[i] > tq){
					rt[i] -= tq;
					cout << "Process " << p[i].id << " executes from " << t << " to ";
					t += tq;
					cout << t << endl;
				}
				else{
					cout << "Process " << p[i].id << " executes from " << t << " to ";
					t += rt[i];
					cout << t << endl;
					cout << "Process " << p[i].id << " completed." << endl;
					rt[i] = 0;
					p[i].ct = t;
					complete++;
				}
			}
		}
	}
	
	int tbt = 0, tta = 0;
	
	for(int i = 0; i < n; i++){
		tta += p[i].ct - p[i].at;
		tbt += p[i].bt;
		/*cout << "\n\nProcess " << p[i].id << endl;
		cout << "Arrived at " << p[i].at << endl;
		cout << "Executed from " << p[i].st << " to " << p[i].ct;*/
	}
	
	cout << "\n\nAverage Waiting Time: " << (float)(tta - tbt)/n << endl;
	cout << "\nAverage Turnaround Time: " << (float)tta/n << endl;

	return 0;
}