#include<iostream>
#include<pthread.h>
using namespace std;

int a = 5, b = 6;
void *swap(void *arg){
        int temp = a;
        a = b;
        b = temp;
        return NULL;
}

int main(){
        pthread_t tid;
        cout << a << "\t" << b << endl;
        pthread_create(&tid, NULL,  swap, NULL);
        pthread_join(tid, NULL);
        cout << a << "\t" << b << endl;
        return 0;
}

