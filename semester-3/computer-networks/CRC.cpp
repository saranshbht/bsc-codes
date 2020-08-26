#include<iostream>
#include<string>
using namespace std;

string XOR(string dividend, string divisor){
	int dvndSize = dividend.size();
	int dvsrSize = divisor.size();	
	int i = 0, index = dvsrSize;

	string rem = "", temp = "";
	int xorRes;
	while((i + index) <= dvndSize){
		rem += dividend.substr(i, index);
		//cout << rem << endl;
		temp = rem;
		rem = "";
		for(int j = 0; j < dvsrSize; j++){
			xorRes = temp[j] ^ divisor[j];
			if(!xorRes && rem.size() == 0)
				continue;
			else
				rem += to_string(xorRes);
			//cout << xorRes << " " << i + index << " " << j << endl;
			//cout << rem << endl;
		}
		i += index;
		index = dvsrSize - rem.size();
	}
	for(int j = i; j < dvndSize; j++){
		if(rem.size() == 0 && dividend[j] == '0')
			continue;
		rem += dividend[j];
	}
	return rem;
}

int main(){
	string data, divisor;
	cout << "Enter data: ";
	cin >> data;
	cout << "Enter divisor: ";
	cin >> divisor;
	string zeroes(divisor.size() - 1, '0');
	string dividend = data + zeroes;
	string rem = XOR(dividend, divisor);
	string completeRem(zeroes.size() - rem.size(), '0');
	rem = completeRem + rem;
	dividend = data + rem;
	cout << "Original data: " << data << endl;
	cout << "Remainder to be appended to original data: " << rem << endl;
	cout << "Transferred data: " << dividend << endl;

	rem = XOR(dividend, divisor);
	cout << "Final remainder: "; 
	if(rem.compare("") == 0){
		cout << "000" << endl;
		cout << "No errors during data transmission";
	}	
	else{
		cout << rem << endl;
		cout << "Some error occurred during data transmission";
	}
	cout << endl;
	
	return 0;
}
