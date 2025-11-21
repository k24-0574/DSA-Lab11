#include <iostream>
using namespace std;

const int tableSize = 100;

struct Node{
    int sum, num1, num2;
    Node*next;
    Node(int s, int n1, int n2):sum(s), num1(n1), num2(n2){}
};

class HashTable{
    Node* table[tableSize];
    int HashFunction(int key){
        return key%tableSize;
    }
    public:
    HashTable(){
        for(int i=0;i<tableSize;i++ ) table[i]=nullptr;
    }
    void insert(int a, int b, int sum){
        int index = HashFunction(sum);
        Node* newnode = new Node(sum, a, b);
        newnode->next = table[index];
        table[index]= newnode;
    }
    Node* findInHash(int a, int b, int sum){
        int index = HashFunction(sum);
        Node*temp = table[index];
        while(temp){
            if(temp->sum==sum && 
                temp->num1!=a && temp->num1!=b &&
                temp->num2!=a && temp->num2!=b) return temp;
            temp = temp->next;    
        }
        insert(a, b, sum);   
        temp = nullptr;
        return temp;  
    }

    void findPairs(int arr[], int size){
        bool found = false;
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                int sum = arr[i]+arr[j];
                Node* temp = findInHash(arr[i],arr[j], sum);
                if(temp){ 
                    found = true;
                    cout<<"("<<arr[i]<<", "<<arr[j]<<") &("<<temp->num1<<", "<<temp->num2<<")"<<endl;
                }
            }
        }
        if(!found) cout<<"No pairs found"<<endl;
    }
};

int main(){
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int arr2[]= {65, 30, 7, 90, 1, 9, 8};

    cout<<"For array 1"<<endl;
    HashTable h1;
    h1.findPairs(arr1, 7);
    cout<<endl<<"For array 2"<<endl;
    HashTable h2;
    h2.findPairs(arr2, 7);
}
