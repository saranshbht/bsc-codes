#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//void sent(int i){
int main(){
    int frames, r, j, ws, total = 0, i = 0;
    srand(time(NULL));
    cout << "Enter the number of packets to be sent: ";
    cin >> frames;
    cout << endl;
    cout << "Enter window size: ";
    cin >> ws;
    cout << endl;
    for(int j = 0; j < ws && i < frames; j++) 
    		cout << "Sending packet " << ++i << "\n";
    		
    while(total < frames){
        	r = rand() % 10;
        	if(r % 3){
            	cout << "Acknowledgement for packet " << ++total << " received\n";
           if(i < frames)
             cout << "Sending packet " << ++i << "\n";
        	}
        	else{           
            	cout << "Timer for packet " << total + 1 << " timed out\n";
            	i = total;
            	for(int j = 0; j < ws && i < frames; j++) 
    		cout << "Sending packet " << ++i << "\n";
      	  }
   	 }
   	 
  return 0;
}
