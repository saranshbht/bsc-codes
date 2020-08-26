#include<iostream>
#include<cmath>
using namespace std;

void allocate(int *pageTable, string *processTable,
int &noOfFrames, int &available, int &frameSize){
     string pid;
    int psize;
    cout << "Enter process id: ";
    cin >> pid;
    cout << "Enter process size: ";
    cin >> psize;
    int noOfPages = ceil((double)psize / frameSize);
    //cout << noOfPages << endl;
    if(noOfPages > available)
        throw "Not enough memory!!!";
    for(int i = 0; i < noOfPages; i++){
        int x = rand() % noOfFrames;
        if(pageTable[x] == -1){
            pageTable[x] = i;
            processTable[x] = pid;
      available--;
     }
        else
               i--;
    }
}

void deallocate(int *pageTable, string
*processTable, int &noOfFrames, int &available){
       string pid;
         cout << "Enter id of process to deallocate: ";
    cin >> pid;

    for(int i = 0; i < noOfFrames; i++){
        if(!processTable[i].compare(pid)){
            processTable[i] = "";
            pageTable[i] = -1;
        }
       }
}

void display(string *processTable, int *pageTable,
int &noOfFrames){
    cout << "Frame Number\tProcessID\tPage Number\n";
    for(int i = 0; i < noOfFrames; i++){
        if(pageTable[i] != -1)
            cout << i << "\t\t" << processTable[i] << "\t\t" << pageTable[i] << "\n";
    }
    cout << endl;
}

void findFrame(int *pageTable, string *processTable,
int &noOfFrames){
    string pid;
    int pageNumber;
    cout << "Enter process ID: ";
    cin >> pid;
    cout << "Enter page number: ";
    cin >> pageNumber;
    cout << "Frame Number: ";
    int i;
    for(i = 0; i < noOfFrames; i++){
        if(pageTable[i] != -1 &&
pid.compare(processTable[i]) == 0 && pageTable[i] ==
pageNumber){
            cout << i << endl;
            break;
        }
    }
        if(i == noOfFrames)
            throw "Invalid Process ID or Page Number";
}


int main() {
    srand(time(NULL));
    int sizeMM, noOfFrames, frameSize, noOfPages;
   cout << "Enter size of main memeory: ";
    cin >> sizeMM;
    cout << "Enter size of a frame: ";
    cin >> frameSize;
    noOfFrames = sizeMM / frameSize;
    int available = noOfFrames;
    //cout << noOfFrames << endl;
    string processTable[noOfFrames];
    int pageTable[noOfFrames];
    for(int i = 0; i < noOfFrames; i++)
        pageTable[i] = -1;

 int choice;
    bool flag = true;
    int elem;
    while(true){
        cout << "\n1.Allocate memory to Process\n2.Deallocate Process\n3.Display Frame Table\n4.Get Frame Number corresponding to the given Process and Page Number\n";                  
        cout << "Enter your choice: ";
        cin >> choice;

    try{
        switch(choice){
            case 1: allocate(pageTable,
processTable, noOfFrames, available, frameSize);
break;

            case 2: deallocate(pageTable,
processTable, noOfFrames, available);
                    break;

            case 3: display(processTable,
pageTable, noOfFrames);
                    break;

            case 4: findFrame(pageTable,
processTable, noOfFrames);
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
