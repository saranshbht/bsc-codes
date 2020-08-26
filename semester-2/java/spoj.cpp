#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	string s;
	while (t--) {
		cin >> ws;
		getline(cin, s);
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s.at(i) == ')' || s.at(i) == '(') {
				s = s.replace(i, 1, "");
				i--;
			}
			if (s.at(i) == '*' || s.at(i) == '*' || s.at(i) == '/' || s.at(i) == '+' || s.at(i) == '-' || s.at(i) == '^') {
				char c = s.at(i);
				s = s.replace(i, 1, "");
				s += c;;
			}
		}
		cout << s << endl;
	}
}