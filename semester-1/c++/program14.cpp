//WAP that takes the radius of a circle as input from the user,passes it to another function
//that computes the area and the circumference of the circle and displays the value of area
//and circumference from the main() function.
#include<iostream>
using namespace std;

void calc(double r, double &area, double &cf) {
	area = 3.14 * r * r;
	cf = 2 * 3.14 * r;
}
int main() {
	double rad, area, circumference;
	cout << "Enter the radius of the circle:";
	cin >> rad;
	calc(rad, area, circumference);
	cout << "Area of circle:" << area;
	cout << endl << "Circumference of circle:" << circumference;

	return 0;
}
