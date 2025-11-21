#include <iostream>
using namespace std;
const int TableSize = 15; 

class StudentHashTable{
    int rollNumber[TableSize]; //key
    string name[TableSize]; //value
    bool occupied[TableSize];

    int hashFunction(int key, int i){
        return (key + i*i)% TableSize;
    }

    public:
    StudentHashTable(){
        for(int i=0;i<TableSize;i++){
            rollNumber[i] = 0;
            name[i] = "";
            occupied[i] = false;
        }
    }
    
    void InsertRecord(int RollNum, string N){
        int index = hashFunction(RollNum,0);
        int startIndex = index;
        int i=0;
        while(i<TableSize){
            index = hashFunction(RollNum,i);
            if(!occupied[index]){
                rollNumber[index] = RollNum;
                name[index] =N;
                occupied[index] = true;
                return;
            }
            i++;
        }

        cout<<"All slots full";
    }

    void SearchRecord(int RollNum){
        cout<<"Search "<<RollNum<<" ";
        int index = hashFunction(RollNum,0);
        int startIndex = index;
        int i=0;
        while(i<TableSize){
            index = hashFunction(RollNum,i);
            if(occupied[index]){
                if(rollNumber[index] == RollNum){
                    cout<<"Index "<<index<<"-> name: "<<name[index]<<endl;
                    return ;
                }
                else i++;
            }
            else break;
            
        };

        cout<<"Record not found"<<endl;
    }

    void display(){
        cout<<"ALL RECORDS: "<<endl;
        for(int i=0;i<TableSize;i++){
            if(occupied[i]){
                cout<<"Index "<<i<<": \n\tname: "<<name[i]<<", roll no: "<<rollNumber[i]<<endl;
            }
        }
        cout<<endl;
    }
    
};

int main(){
    StudentHashTable h1;
    h1.InsertRecord(123, "abc");
    h1.InsertRecord(574, "neamah");
    h1.InsertRecord(456, "defg");

    h1.display();
    h1.SearchRecord(456);
    h1.SearchRecord(234);
    
   
    return 0;
}
