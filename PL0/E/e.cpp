#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    stack<int> pilha;
    string s;
    int n;
    cin >> n;
    while(cin >> s){
        if(s == "+"){
            int a = pilha.top();
            pilha.pop();
            int b = pilha.top();
            pilha.pop();
            pilha.push(a+b);
        }else if(s == "-"){
            int a = pilha.top();
            pilha.pop();
            int b = pilha.top();
            pilha.pop();
            pilha.push(b-a);
        }
        else{
            int p = stoi(s);
            pilha.push(p);
        };
    }
    int arr[n];
    while(!pilha.empty()){
        arr[n-1] = pilha.top();
        pilha.pop();
        --n;
    }

    for(int i: arr){
        cout << i << endl;
    }
    return 0;
}

/*

2
2 3
2 3 4
2 -1
1
1 10
1 10 82
1 -72
1 -72 12
1 -60
1 -60 -1
1 -60 -1 2
1 -60 1
1 -60 1 1
1 -60 0

*/