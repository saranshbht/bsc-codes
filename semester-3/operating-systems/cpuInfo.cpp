#include<iostream>
#include<fstream>
#include<string>
#include "unistd.h"
using namespace std;

int main(){
        system("cat /proc/cpuinfo | head -5 | cat > output.txt");
        system("cat /proc/cpuinfo | grep -m 2 MHz | cat >> output.txt");
        ifstream f("output.txt");
        if(!f){
                cout << "Cannot open file for reading" << endl;
                return 1;
        }
        string s;
        while(f){
                getline(f, s);
                if(f)
                        cout << s << endl;
        }
        f.close();
        return 0;
}

