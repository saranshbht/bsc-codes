#include<iostream>
#include<queue>
using namespace std;

struct Process{
	int at, rt, ct;
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
		cin >> p[i].rt;
	}
	
	cout << "Enter time quantum: ";
	cin >> tq;
	
	bool swapped;
	for(int i = 0; i < n - 1; i++){
		swapped = false;
		for(int j = 0; j < n - i - 1; j++){
			if(p[j].at > p[j + 1].at){
				pswap(&p[j], &p[j + 1]);
				swapped = true;
			}
		}
		if(!swapped)
			break;
	}

	int t = p[0].at, complete = 0;
	int index = 0;
	queue<Process> q;
	
	for(; index < n;){
		if(p[index].at <= t){
			q.push(p[index]);
			index++;
			continue;
		}
		break;
	}
		
	while(complete != n){
			if(q.front().rt > 0){
				if(q.front().rt > tq){
					q.front().rt -= tq;
					cout << "\nProcess " << q.front().id << " executes from " << t << " to ";
					t += tq;
					cout << t << endl;
				}
				else{
					cout << "\nProcess " << q.front().id << " executes from " << t << " to ";
					t += q.front().rt;
					cout << t << endl;
					cout << "Process " << q.front().id << " completed." << endl;
					q.front().rt = 0;
					
					for(int i = 0; i < n; i++){
						if(p[i].id == q.front().id){
							p[i].ct = t;
							break;
						}
					}
					complete++;
				}
			}
			for(; index < n;){
				if(p[index].at <= t){
					q.push(p[index]);
					index++;
					continue;
				}
				break;
			}
			if(q.front().rt > 0)
				q.push(q.front());
			q.pop();
			
		}
	
	int tbt = 0, tta = 0;
	
	for(int i = 0; i < n; i++){
		tta += p[i].ct - p[i].at;
		tbt += p[i].rt;
		/*cout << "\n\nProcess " << p[i].id << endl;
		cout << "Arrived at " << p[i].at << endl;
		cout << "Executed from " << p[i].st << " to " << p[i].ct;*/
	}
	
	cout << "\n\nAverage Waiting Time: " << (float)(tta - tbt)/n << endl;
	cout << "\nAverage Turnaround Time: " << (float)tta/n << endl;

	return 0;
}