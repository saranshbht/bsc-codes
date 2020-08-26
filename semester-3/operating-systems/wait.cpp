#include<iostream>
using namespace std;

int data = 10;
int main(){
        int p = fork();
        if(p < 0)
                cout << "fork() unsuccessful";
        else if(!p){
                data += 15;
                cout <<  data << "\n";
        }
        else{
                wait(null);
                cout << data << "\n";
        }

        return 0;
}

