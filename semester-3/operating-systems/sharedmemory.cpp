#include<iostream>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/wait.h>
using namespace std;

int main(){
        int segid, pid;
        char *memory;
        const int size = 2048;
        segid  = shmget(IPC_PRIVATE, size, S_IRUSR | S_IWUSR);
        if(segid == -1)
                cout << "Shared memory allocation failed\n";
        else{
                memory = (char*)shmat(segid, NULL, 0);
                pid = fork();
                if(pid == -1)
                        cout << "Fork creation failed\n";
                else if(pid == 0){
                        cout << "Child writing to shared memory\n";
                        sprintf(memory, "Hello World");
                }
                else {
                        wait(NULL);
                        cout << "Parent reading from shared memory\n";
                        cout << "Message: " << memory << "\n";
                }
                shmdt(memory);
                shmctl(segid, IPC_RMID, NULL);
        }

        return 0;
}

