#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    int frames,i = 0,r;
    srand(time(NULL));
    cout << "Enter the number of packets to be sent: ";
    cin >> frames;
    while(frames--){
        cout << "Sending packet " << ++i << "\n";
        r = rand() % 10;
        if(r % 3){
            cout << "Acknowledgement for packet " << i << " received\n\n";
        }
        else{
            cout << "Timer for packet " << i << " timed out\nRe-";
            i--;
            frames++;
        }
    }
  return 0;
}
