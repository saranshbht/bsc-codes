#include<iostream>
#include<string>
using namespace std;
string xorfunc(string s1, string s2){
	string temp = "";
	for(int i = 0; i < s1.size(); i++){
		if((s1[i] == '1' && s2[i] == '0') || (s1[i] == '0' && s2[i] == '1'))
			temp += "1";
		else{
			if(temp == "")
				continue;
			temp += "0";
		}
	}
	
	return temp;
}

int main(){
	string data, genr, result = "";
	cout << "Data: ";
	cin >> data;
	cout << "Generator: ";
	cin >> genr;
	for(int i = 0; i < genr.size() - 1; i++)
		data += "0";
	for(int i = 0; i < data.size() - ; i++){
		string temp = "";
		for(int j = i; j < genr.size(); j++)
			temp += data[j];
		
	}
	
}
