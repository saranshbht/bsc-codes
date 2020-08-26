#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;

int main(){
	int pid = fork();
	if(pid < 0){
		cout << "Fork call failed";
		return 1;
	}
	if(pid > 0){
		wait(NULL);
		execlp("./sum.out", "./sum.out", NULL);
	}
	else{
		int a, b;
		cout << "Enter two numbers: ";
		cin >> a >> b;
		cout << "a * b = " << (long)a * b << endl;
	}
	return 0;
}
