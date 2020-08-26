#include<iostream>
#include<climits>
using namespace std;

struct Process{
	int at, bt, st, ct, prty;
	int id;
};


void pswap(Process *a, Process *b){
	Process temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int n;
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
		cout << "Lower number has higher priority" << endl;
		cout << "Priority: ";
		cin >> p[i].prty;
	}
	
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
	
	int priority[n];
	int rt[n];
	int completed[n] = {0};
	int t = 0, complete = 0;
	int highest = 0, min = INT_MAX;
	for(int i = 0; i < n; i++){
		priority[i] = p[i].prty;
		rt[i] = p[i].bt;
		p[i].st = -1;
	}
	
	bool flag = false;
	
	cout << "\n\n";
	while(complete != n){
		for(int i = 0; i < n; i++){
			if(p[i].at <= t && priority[i] < min && rt[i] > 0){
				min = priority[i];
				if(highest != i && p[highest].st != t)
					cout << "\nProcess " << p[highest].id << " executed from " << p[highest].st << " to " << t << endl;
				if(completed[highest])
					cout << "Process " << p[highest].id << " completed" << endl;
				highest = i;
				//if(p[highest].st < 0)
				p[highest].st = t;
				flag = true;
			}
		}
		if(!flag){
			t++;
			continue;
		}
		
		rt[highest]--;
		if(!rt[highest]){
			complete++;
			p[highest].ct = t + 1;
			min = INT_MAX;
			completed[highest] = 1;
			//p[highest].st = p[highest].ct - p[highest].bt;
		}
		t++;
		//cout << rt[highest]	<< endl;
	}
	cout << "\nProcess " << p[highest].id << " executed from " << p[highest].st << " to " << t << endl;
	cout << "Process " << p[highest].id << " completed" << endl;
	
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