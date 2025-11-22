#include <iostream>
using namespace std;
const int TableSize = 7; //make table size large (greater than 7) for many strings
struct Node{
    string key;
    string value;
    Node* next;
    Node(string k, string n){
        key = k;
        value= n;
        next = nullptr;
    }
};

class HashTable{
    Node* table[TableSize];

    int hashFunction(string key){
        int sum =0;
        for(int i=0;i<key.length();i++) sum+=key[i];
        return sum % TableSize;
    }

    public:
    HashTable(){
        for(int i=0;i<TableSize;i++) table[i]=nullptr;
    }
    ~HashTable(){
        Node*temp1, *temp2;
        for(int i=0;i<TableSize;i++){
            temp1 = table[i];
            while(temp1){
                temp2 = temp1->next;
                delete temp1;
                temp1 = temp2;
            }
        }
    }
    
    void insert(string key, string value){
        int index = hashFunction(key);
        
        Node* curr = table[index];
        while(curr!=nullptr){
            if(curr->key == key){
                //update value
                curr->value = value;
                return;
            }
            curr = curr->next;
        }
        //insert at head
        Node* newnode = new Node(key, value);
        newnode->next = table[index];
        table[index] = newnode;
    }

    void display(){
        for(int i=0;i<TableSize;i++){
            cout<<"Index "<<i<<endl;
            Node*temp = table[i];
            if(temp==nullptr) cout<<"\t-"<<endl;
            while(temp){
                cout<<"\tkey: "<<temp->key<<" | value: "<<temp->value<<endl;
                temp = temp->next;
            }
        }
    }
    
};

int main(){
    HashTable myhash;
    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");

    myhash.display();

    return 0;
}
