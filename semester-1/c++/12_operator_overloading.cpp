#include<iostream>
using namespace std;

class Fraction {
	private:
		int numerator, denominator;

	public:
		Fraction(int num = 0, int den = 1) {
			numerator = num;
			denominator = den;
		}

		void show() {
			cout << endl << numerator << "\t" << denominator;
		}

//multiplication
		Fraction operator*(const Fraction &f)const {
			Fraction temp;
			temp.numerator = this->numerator * f.numerator;
			temp.denominator = this->denominator * f.denominator;
			return temp;
		}

//equality
		bool operator==(const Fraction &fraction)const {
			return (this->numerator * fraction.denominator == this->denominator * fraction.numerator);
		}

//pre-increment
		Fraction operator++() {
			this->numerator += this->denominator;
			return *this;
		}

//post-increment
		Fraction operator++(int temp) {
			const Fraction tempFraction = *this;
			this->numerator += this->denominator;
			return tempFraction;
		}

//indexing
		int operator[](int index) {
			if (index == 0) {
				return this->numerator;
			} else if (index == 1) {
				return this->denominator;
			} else {
				throw "Invalid index";
			}
		}

//type_casting
		operator double()const {
			return ((double)(this->numerator) / (this->denominator));
		}


};


int main() {

	Fraction f;
	f.show();
	Fraction f1(2);
	f1.show();
	Fraction f2(3, 4);
	f2.show();
	Fraction f3(f2);
	f3.show();
	Fraction f4 = f2;
	f4.show();
	cout << endl << (f1 == f2);
	cout << endl << f2++;
	cout << endl << ++f3;
	cout << endl << f4[0];
	cout << endl << (double)f4;

	Fraction f6;
	f6 = f2 * f3;
	f6.show();
	cout << endl;
	return 0;
};
