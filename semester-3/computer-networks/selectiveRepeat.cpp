#include<iostream>
#include<cstdlib>
#include<ctime>
#include<list>
using namespace std;

//void sent(int i){
int main(){
    int frames, r, j, ws, total = 0, i = 0;
    srand(time(NULL));
    list<int> q;
    cout << "Enter the number of packets to be sent: ";
    cin >> frames;
    cout << endl;
    cout << "Enter window size: ";
    cin >> ws;
    cout << endl;
    for(int j = 0; j < ws && i < frames; j++){
    		cout << "Sending packet " << ++i << "\n";
      q.push_back(i);
    }
    		
    while(total < frames){
        	r = rand() % 10;
        	if(r % 3){
            	cout << "Acknowledgement for packet " << q.front() << " received\n";
            q.pop_front();
            total++;
           if(i < frames){
             cout << "Sending packet " << ++i << "\n";
             q.push_back(i);
           }
        	}
        	else{    
        		int x = q.front();     
            	cout << "Timer for packet " << x << " timed out\n";
            q.push_back(x);
            cout << "Sending packet " << x << "\n";
            q.pop_front();
      	  }
   	 }
   	 
  return 0;
}
