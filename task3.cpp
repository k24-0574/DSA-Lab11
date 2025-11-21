#include <iostream>
#include <list>
using namespace std;
const int TableSize = 7; 

class HashTable{
    list<pair<int, string>> table[TableSize];

    int hashFunction(int key){
        return key % TableSize;
    }

    public:
    HashTable(){}
    ~HashTable(){}
    
    void Insert(int key, string value){
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    void search(int key){
        cout<<"Search Key "<<key<<": ";
        int index = hashFunction(key);

        if(table[index].empty()){
            cout<<"not in list "<<endl; return;
        }

        for (auto &p : table[index]) {
            if (p.first == key) {
                cout << p.second<<endl;
                return;
            }
        }
    }

    void deleteKey(int key){
        // int index = hashFunction(key);
        // table[index].erase()
        // for(auto &p:table[index]){
        //     if(p.first==key){
                
        //     }
        // }
    }

    void Display(){
        for(int i=0;i<TableSize;i++){
            if(!table[i].empty()){
                cout<<"Index "<<i<<": ";
                for(auto &p:table[i]){
                    cout<<"("<<p.first<<", "<<p.second<<") ";
                }
                cout<<endl;
            }
        }
    }
    
};

int main(){
    HashTable myhash;
    myhash.Insert(3, "A");
    myhash.Insert(10, "B");
    myhash.Insert(2, "C");
    myhash.Insert(8, "D");

    myhash.search(2);
    myhash.search(7);


    myhash.Display();

    return 0;
}
