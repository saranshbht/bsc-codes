#include "stackClass.cpp"

void sum(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    int max = n > m ? n : m;
    Stack<int> s;
    int carry = 0, elem;
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    while(i >= 0 && j >= 0){
        elem = carry + s1[i--] - '0' + s2[j--] - '0';
        //cout << elem << endl;
        s.push(elem % 10);
        carry = elem / 10;
    }
    
    while(i >= 0){
        elem = carry + s1[i--] - '0';
        //cout << elem << endl;
        s.push(elem % 10);
        carry = elem / 10;
    }
    while(j >= 0){
        elem = carry + s2[j--] - '0';
        //cout << elem << endl;
        s.push(elem % 10);
        carry = elem / 10;
    }
    if(carry != 0)
        s.push(carry);
    cout << "Sum: ";
    while(!s.isEmpty())
        cout << s.pop();
    cout << endl;
}

int main(){
    string s1, s2;
    cout << "Enter first number: ";
    cin >> s1;
    cout << "Enter second number: ";
    cin >> s2;
    sum(s1, s2);
    return 0;
}


