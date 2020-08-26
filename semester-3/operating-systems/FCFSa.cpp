#include<iostream>
using namespace std;

struct Process{
	int at, bt, st, ct;
	int id;
};

void pswap(Process *a, Process *b){
	Process temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int n;
	cout << "Enter number of processes: ";
	cin >> n;
	Process p[n];
	cout << "\nEnter details";
	for(int i = 0; i < n; i++){
		cout << "\nProcess Id: ";
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
	
	p[0].st = p[0].at;
	p[0].ct = p[0].st + p[0].bt;
	for(int i = 1; i < n; i++){
		if(p[i].at > p[i - 1].ct)
			p[i].st = p[i].at;
		else
			p[i].st = p[i - 1].ct;
		p[i].ct = p[i].st + p[i].bt;
	}
	
	double twt = 0.0, tta = 0.0;
	
	for(int i = 0; i < n; i++){
		tta += p[i].ct - p[i].at;
		twt += p[i].st - p[i].at;
		cout << "\n\nProcess Id: " << p[i].id;
		cout << "\nArrived at: " << p[i].at;
		cout << "\nExecuted from " << p[i].st << " to " << p[i].ct;
	}
	
	cout << "\n\nAverage Waiting Time: " << twt/n;
	cout << "\nAverage Turnaround Time: " << tta/n;
	
	return 0;
}
