#include<iostream>
#include<climits>
using namespace std;

struct Process {
	int at, bt, pri, rt;
	int id;
};


void pswap(Process *a, Process *b) {
	Process temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int n;
	cout << "Enter no. of processes: ";
	cin >> n;
	Process p[n];
	cout << "Enter details" << endl;
	for (int i = 0; i < n; i++) {
		//cout << "\nFor process " << endl;
		cout << "\nId: ";
		cin >> p[i].id;
		cout << "Arrival time: ";
		cin >> p[i].at;
		cout << "Burst time: ";
		cin >> p[i].bt;
		cout << "Priority: ";
		cin >> p[i].pri;
	}

	/*bool swapped;
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
	}*/

	int complete = 0;
	int shortest = 0;
	int t = 0;
	int min = INT_MAX;
	int rt[n];
	for (int i = 0; i < n; i++) {
		p[i].rt = p[i].bt;
	}
	while (complete != n) {
		bool check = false;
		for (int i = 0; i < n; i++) {
			if (p[i].at <= t && p[i].pri && p[i].rt > 0) {
				min = p[i].pri;
				shortest = i;
				check = true;
			}
		}
		if (!check) {
			t++;
			continue;
		}

		p[shortest].rt--;
		cout << p[shortest].id << " ";
		if (!p[shortest].rt) {
			complete++;
		}
		t++;
	}

	return 0;
}