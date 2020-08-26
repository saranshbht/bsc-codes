#include<iostream>
#include<climits>
using namespace std;

struct Process{
	int at, bt,st, ct;
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
	
	int rt[n];
	int completed[n] = {0};
	int t = 0, complete = 0;
	int shortest = 0, min = INT_MAX;
	for(int i = 0; i < n; i++){
		rt[i] = p[i].bt;
		p[i].st = -1;
	}
	
	bool flag = false;
	
	cout << "\n\n";
	while(complete != n){
		for(int i = 0; i < n; i++){
			if(p[i].at <= t && rt[i] < min && rt[i] > 0){
				min = rt[i];
				if(shortest != i && p[shortest].st != t)
					cout << "Process " << p[shortest].id << " executed from " << p[shortest].st << " to " << t << endl;
				if(completed[shortest])
					cout << "Process " << p[shortest].id << " completed" << endl;
				shortest = i;
				//if(p[shortest].st < 0)
				p[shortest].st = t;
				flag = true;
			}
		}
		if(!flag){
			t++;
			continue;
		}
		
		rt[shortest]--;
		min = rt[shortest];
		if(!min)
			min = INT_MAX;
		if(!rt[shortest]){
			complete++;
			p[shortest].ct = t + 1;
			completed[shortest] = 1;
			//p[shortest].st = p[shortest].ct - p[shortest].bt;
		}
		t++;
	}
	cout << "Process " << p[shortest].id << " executed from " << p[shortest].st << " to " << t << endl;
	cout << "Process " << p[shortest].id << " completed" << endl;
	
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