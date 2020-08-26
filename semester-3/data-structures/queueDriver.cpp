#include "queueClass.cpp"

int main(){
    Queue<int> queue;
    int choice;
    bool flag = true;
    int elem;
    while(true){
        cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
    
    try{
        switch(choice){
            case 1: cout << "Enter element to be added: ";
                    cin >> elem;
                    queue.enqueue(elem);
                    break;
            
            case 2: elem = queue.dequeue(); 
		    cout << "Element removed: " << elem  << endl;
                    break;
                
            case 3: queue.display();
                    break;
                                    
            case 0: flag = false;
                    break;
            
            default: cout << "Wrong choice" << endl;
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
