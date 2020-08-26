#include<iostream>
#include<string>
#include<unistd.h>
#include<sys/wait.h>

using namespace std;

int main(){
        int pip[2];
        char s[100];
        if(pipe(pip) == -1){
                cout << "Pipe Failed" << endl;
                return 1;
        }

        cin.getline(s, 100);

        int pid = fork();
        if(pid < 0){
                cout << "fork() failed" << endl;
                return 1;
        }

        else if(pid == 0){
                close(pip[0]);
                write(pip[1], s, strlen(s) + 1);
                close(pip[1]);
        }

        else{
                close(pip[1]);
                wait(NULL);
                char str[100];
                read(pip[0], str, 100);
                cout << str << endl;
                close(pip[0]);
        }

        return 0;
}
