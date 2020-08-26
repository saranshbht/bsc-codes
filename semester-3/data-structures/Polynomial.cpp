#include<iostream>
using namespace std;

class term{
	public:
		float coefficient;
		int exp;
		term *next;
		term(float coeff, int e){
			coefficient = coeff;
			exp = e;
			next = NULL;
		}
};

class Polynomial{
	term *first;
	term *last;
	public:
	Polynomial(){
		first = NULL;
		last = NULL;
	}
	
	void add(float, int);
	
	Polynomial operator+(const Polynomial&);
	
	Polynomial operator-(const Polynomial&);
	
	Polynomial operator*(const Polynomial&);
	
	friend ostream& operator<<(ostream&, const Polynomial&);
	
};

void Polynomial :: add(float c, int e){
	if(c == 0)
		return;
	term *temp = new term(c, e);
	if(first == NULL)
		first = last = temp;
		
	else if(first -> exp < e){
		temp -> next = first;
		first = temp;
	}
		
	else if(last -> exp > e){
		last -> next = temp;
		last = temp;
	}
		
	else{
		term *p = first;
		while(p -> next -> exp > e)
			p = p -> next;
		if(p -> next -> exp == e)
			p -> next -> coefficient += c;
		else{
			temp -> next = p -> next;
			p -> next = temp;
		}
	}
}

Polynomial Polynomial :: operator+(const Polynomial& p){
	Polynomial temp;
	term *p1 = first;
	term *p2 = p.first;
	
	while(p1 != NULL && p2 != NULL){
		if(p1 -> exp > p2 -> exp){
			temp.add(p1 -> coefficient, p1 -> exp);
			p1 = p1 -> next;
		}
		
		else if(p2 -> exp > p1 -> exp){
			temp.add(p2 -> coefficient, p2 -> exp);
			p2 = p2 -> next;
		}
		
		else{
			temp.add(p1 -> coefficient + p2 -> coefficient, p1 -> exp);
			p1 = p1 -> next;
			p2 = p2 -> next;
		}
	}
	
	while(p1 != NULL){
		temp.add(p1 -> coefficient, p1 -> exp);
		p1 = p1 -> next;
	}
	
	while(p2 != NULL){
		temp.add(p2 -> coefficient, p2 -> exp);
		p2 = p2 -> next;
	}
	
	return temp;
}

Polynomial Polynomial :: operator-(const Polynomial& p){
	Polynomial temp;
	term *p1 = first;
	term *p2 = p.first;
	
	while(p1 != NULL && p2 != NULL){
		if(p1 -> exp > p2 -> exp){
			temp.add(p1 -> coefficient, p1 -> exp);
			p1 = p1 -> next;
		}
		
		else if(p2 -> exp > p1 -> exp){
			temp.add(-p2 -> coefficient, p2 -> exp);
			p2 = p2 -> next;
		}
		
		else{
			temp.add(p1 -> coefficient - p2 -> coefficient, p1 -> exp);
			p1 = p1 -> next;
			p2 = p2 -> next;
		}
	}
	
	while(p1 != NULL){
		temp.add(p1 -> coefficient, p1 -> exp);
		p1 = p1 -> next;
	}
	
	while(p2 != NULL){
		temp.add(-p2 -> coefficient, p2 -> exp);
		p2 = p2 -> next;
	}
	
	return temp;
}

//multiplication
Polynomial Polynomial :: operator*(const Polynomial& p){
	Polynomial temp;
	term *p1 = first;
	
	while(p1 != NULL){
		term *p2 = p.first;
		while(p2 != NULL){
			temp.add(p1 -> coefficient * p2 -> coefficient, p1 -> exp + p2 -> exp);
			p2 = p2 -> next;
		}
		p1 = p1 -> next;
	}
	
	return temp;
}

ostream& operator<<(ostream& out, const Polynomial& p){
	if(p.first == NULL)
		out << "Polynomial has no terms";
	else if(p.first == p.last)
		out << p.first -> coefficient << " x^ " << p.first -> exp;
	else{
		out << p.first -> coefficient << " x^ " << p.first -> exp;
		term *temp = p.first -> next;
		while(temp != NULL){
			if(temp -> coefficient < 0)
				out << " - " << -temp -> coefficient << " x^ " << temp -> exp;
			else
				out << " + " << temp -> coefficient << " x^ " << temp -> exp;
			temp = temp -> next;
		}
	}
	out << endl;
	return out;
}

int main(){
	Polynomial p1;
	p1.add(12, 3);
	p1.add(15, 2);
	p1.add(1, 1);
	p1.add(9, 0);
	cout << p1;
	Polynomial p2;
	p2.add(13, 3);
	p2.add(10, 0);
	p2.add(11, 1);
	cout << p2;
	Polynomial p3 = p1 * p2;
	cout << p3;
	Polynomial p4;
	cout << p4;
	return 0;
}