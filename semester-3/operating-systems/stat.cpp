#include<iostream>
#include "unistd.h"
using namespace std;

int main(int argc, char *argv[]){
	const char filename = argv[1];
	system("stat " + filename);
	return 0;
}