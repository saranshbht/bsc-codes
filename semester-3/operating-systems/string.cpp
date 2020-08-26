#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int count = 1, i;
	string compressed = "";
	for (i = 1; i < s.size(); i++) {
		if (s[i - 1] != s[i]) {
			compressed += s[i - 1] + string :: to_string(count);
			count = 1;
		} else {
			count++;
		}
		//cout << compressed << endl;
	}
	compressed += s[i - 1] + string :: to_string(count);

	cout << compressed << endl;
	return 0;
}