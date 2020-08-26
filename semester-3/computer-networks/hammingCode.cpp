#include <bits/stdc++.h>
using namespace std;

void sending(string &dataEnc, char dataSent[], int m, int r){
    int k = m;
    int dataSize = m + r;
    for(int i = 1; i <= dataSize; i++)
        if(__builtin_popcount(i) == 1)
            dataSent[i - 1] = 'p';
        else
            dataSent[i - 1] = dataEnc[--k];
    int count;
    for(int i = 0; i < r; i++){
        count = 0;
        for(int j = 1; j <= dataSize; j++){
            if((j & (1 << i)) && dataSent[j - 1] == '1')
                count++;
        }
        if(count % 2)
            dataSent[(1 << i) - 1]= '1';
        else
            dataSent[(1 << i) - 1]= '0';
    }
    
    cout << "Data sent: ";
    for(int i = m + r - 1; i >= 0; i--)
        cout << dataSent[i];
    cout << endl;   
}

void receiving(char dataSent[], int m, int r){
    char dataReceived[m + r];
    int dataSize = m + r;
    for(int i = 0; i < dataSize; i++)
        dataReceived[i] = dataSent[i];
    
    //chance of error during transmission = ((m+ r) / 20) * 100%
    int x = rand() % 20;
    if(x < dataSize){
        if(dataReceived[x] == '1')
            dataReceived[x] = '0';
        else
            dataReceived[x] = '1';
    }
    
    /*for(int i = dataSize - 1; i >= 0; i--)
        cout << dataReceived[i];
    cout << endl;*/
    int count;
    char error[r];
    int errorBit = 0;
    for(int i = 0; i < r; i++){
        count = 0;
        for(int j = 1; j <= dataSize; j++){
            if((j & (1 << i)) && dataReceived[j - 1] == '1')
                count++;
        }
        if(count % 2){
            error[i]= '1';
            errorBit += 1 << i;
        }
        else
            error[i]= '0';
    }
    
    cout << "Data received: ";
    for(int i = dataSize - 1; i >= 0; i--)
        cout << dataReceived[i];
    cout << endl;
    
    if(errorBit)
        cout << "Error at bit(LSB) " << errorBit;
    else
        cout << "No errors";
    cout << endl;
}

int main() {
    srand(time(NULL));
    string dataEnc;
    cout << "Enter data to be encoded: ";
    cin >> dataEnc;
    cout << endl;
    int m,r = 0;
    m = dataEnc.size();
    while((1 << r) < (m + r + 1)){
        r++;
    }
    //cout << m << r << endl;
    char dataSent[m + r];
    sending(dataEnc, dataSent, m, r);
    receiving(dataSent, m, r);
    
    return 0;
}