#include<iostream>
using namespace std;

struct Process{
	int at, bt, st, ct;
	int id;
};

void pswap(Process **a, Process **b){
	Process temp = **a;
	**a = **b;
	**b = temp;
}

void pswap(Process *a, Process *b){
	Process temp = *a;
	*a = *b;
	*b = temp;
}

void psort(Process **pro, int total){
	bool swapped;
	for(int i = 0; i < total - 1; i++){
		swapped = false;
		for(int j = 0; j < total - i - 1; j++){
			if(pro[j]->bt > pro[j + 1]->bt){
				pswap(&pro[j], &pro[j + 1]);
				swapped = true;
			}
		}
		if(!swapped)
			break;
	}
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
	
	int current = p[0].at;
	Process **temp = new Process*[n];
	for(int i = 0; i < n; i++){
		int total = 0;
		if(i > 0)
			current += p[i - 1].ct;
		for(int j = i; j < n; j++){
			if(p[j].at <= current)
				temp[total++] = &p[j];
		}
		
		if(total > 1)
			psort(temp, total);
		if(i + total >= n)
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
