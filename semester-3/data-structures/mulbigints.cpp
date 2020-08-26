#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	
	int carry = 0, mul;
	int arraySize = s1.size() + s2.size();
	int *result = new int[arraySize]{0};
	int i = 0, index = -1, j;
	
	while(i < s2.size()){
		j = 0;
		carry = 0;
		index++;
		while(j < s1.size()){
			mul = carry + ((s2[i] - '0') * (s1[j] - '0'));
			result[j + index] += (mul % 10);
			carry = mul / 10;
			j++;
		}
		i++;
		if(carry > 0)
			result[j + index] += carry;
	}
	
	carry = 0;
	for(i = 0; i < arraySize; i++){
		result[i] += carry;
		carry = result[i] / 10;
		result[i] %= 10;
	}
	
	for(i = arraySize - 1; i >= 0; i--){
		if(result[i] == 0)
			arraySize--;
		else
			break;
	}
	
	vector<int> v(result, result + arraySize);
	reverse(v.begin(), v.end());
	
	for(i = 0; i < v.size(); i++)
		cout << v[i];
	cout << endl;
	
	return 0;
}