#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<int, int> s;
    string aux;
    while(cin >> aux){
        int value,key;
        if(aux == "ADD"){
            cin >> value;
            cin >> key;
            s[key] += value;
        }else if(aux == "REM"){
            cin >> value;
            cin >> key;
            if(value <= s[key]) s[key] = s[key]-value;
            else cout << "removal refused" << endl;
        }else if(aux == "QUERY"){
            cin >> key;
            cout << s[key] << endl;
        }
    }
    return 0;
}
