#include "stackClassArray.cpp"

int main(){
    int size;
    cout << "Enter size of stack: ";
    cin >> size;
    stack<int> s(size);
    int choice;
    bool flag = true;
    int elem;
    while(true){
        cout << "\n1.Push\n2.Pop\n3.Stack Top\n4.Is Empty\n5.Is Full\n6.Display\n7.Clear\n0.Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
    
    try{
        switch(choice){
            case 1: cout << "Enter element to be added: ";
                    cin >> elem;
                    s.push(elem);
                    break;
            
            case 2: elem = s.pop();
		    cout << "Element popped: " << elem << endl;
                    break;
                    
            case 3: cout << s.stackTop() << endl;
                    break;
            
            case 4: if(s.isEmpty())
                        cout << "Yes";
                    else
                        cout << "No";
                    cout << endl;
                    break;
                    
            case 5: if(s.isFull())
                        cout << "Yes";
                    else
                        cout << "No";
                    cout << endl;
                    break;
                    
            case 6: s.display();
                    break;

	    case 7: s.clear();
		    break; 
                
            case 0: flag = false;
            	    break;
            default: cout << "Wrong choice!!!" << endl;
        }
        if(!flag)
            break;
    }
    catch(const char *s){
        cout << s << endl;
    }
    }
    return 0;
}
