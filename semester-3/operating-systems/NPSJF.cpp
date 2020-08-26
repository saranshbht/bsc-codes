#include<iostream>
using namespace std;

struct Process{
	int at, bt,st, ct;
	int no;
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
	cout << "Enter no. of processes: ";
	cin >> n;
	Process p[n];
	cout << "Enter details" << endl;
	for(int i = 0; i < n; i++){
		//cout << "\nFor process " << endl;
		cout << "\nNumber: ";
		cin >> p[i].no;
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
	
	int current = p[0].at;
	Process **temp = new Process*[n];
	for(int i = 0; i < n; i++){
		int total = 0;
		if(i > 0)
			current += p[i - 1].ct;
		
		for(int j = i; j < n; j++)
			if(p[j].at <= current)
				temp[total++] = &p[j];
		
		if(total > 1)
			psort(temp, total);
		if(i + total >= n)
			break;
	}		
	
	double awt = 0.0, ata = 0.0;
	
	for(int i = 0; i < n; i++){
		ata += p[i].ct - p[i].at;
		awt += p[i].st - p[i].at;
		cout << "\n\nProcess " << p[i].no << endl;
		cout << "Arrived at " << p[i].at << endl;
		cout << "Executed from " << p[i].st << " to " << p[i].ct;
	}
	
	cout << "\n\nAverage Waiting Time: " << awt/n << endl;
	cout << "\nAverage Turnaround Time: " << ata/n << endl;

	return 0;
}