#include <iostream>
using namespace std;
const int TableSize = 100; 
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
    
    void Add_Record(string key, string value){
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

    void Word_Search(string key){
        cout<<"Search Key "<<key<<": ";

        int index = hashFunction(key);
        Node*temp = table[index];
        if(temp == nullptr) cout<<"-";
        while(temp){
            cout<<temp->value;
            if(temp->next) cout<<", ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void deleteKey(string key){
        int index = hashFunction(key);
        Node*temp = table[index], *prev=nullptr;
        
        while(temp){
            if(temp->key == key){
                if(prev==nullptr){
                    table[index] = table[index]->next;
                    delete temp;
                }
                else{
                    prev->next = temp->next;
                    delete temp;
                }
                cout<<"Key "<<key<<" deleted successfully"<<endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout<<"Key "<<key<<" not in records"<<endl;
    }

    void Print_Dictionary(){
        for(int i=0;i<TableSize;i++){
            Node*temp = table[i];
            if(temp!=nullptr){ 
                cout<<"Index "<<i<<": ";
                while(temp){
                    cout<<"("<<temp->key<<", "<<temp->value<<") ";
                    temp = temp->next;
                    if(temp) cout<<", ";
                }
                cout<<endl;
            }
        }
    }
    
};

int main(){
    HashTable myhash;
    myhash.Add_Record("AB", "FASTNU");
    myhash.Add_Record("CD", "CS");
    myhash.Add_Record("EF", "GH");

    myhash.Word_Search("AB");
    myhash.deleteKey("EF");
    myhash.Print_Dictionary();

    return 0;
}
