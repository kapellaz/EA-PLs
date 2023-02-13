#include <iostream>
#include <set>

using namespace std;

int main(){
    multiset<int> s;
    string aux;
    int x;
    while(cin >> aux){
        if(aux == "ADD"){
            cin >> x;
            s.insert(x);
        }
        else if (aux == "REQUEST"){
            cin >> x;
            auto i = s.find(x);
            if(s.count(x)){
                cout << *i << endl;
                s.erase(i);
            }
            else{
                i = s.upper_bound(x);
                if(i == s.end()){
                    string a = "impossible\n";
                    cout << a;
                }else{
                    cout << *i << endl;
                    s.erase(i);
                }
            }
        }
    }
    /*for(auto& cena : s ){
        cout << cena << ' ';
    }*/
    return 0;
}
