#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char s;
	ifstream in("w.txt");
	ofstream out("newFile.txt");
	while (!in.eof()) {
		in >> s;
		if (s != ' ') {
			out << s;
		}
	}
	out << s;

	in.close();
	out.close();
	return 0;
}


