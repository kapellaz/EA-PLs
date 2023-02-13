#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    list<int> lista;
    list<int>::iterator it = lista.begin();
    //cout << *it;
    string s;
    int a_inserir;
    lista.push_back(0); 
    --it;
    while(cin >> s){
        if(s == "MOVE"){
            cin >> s;
            if(s == "LEFT") --it;
            else if (s == "RIGHT") ++it;
        }else if(s == "INSERT"){
            cin >> s;
            if(s == "LEFT"){
                cin >> a_inserir;
                lista.insert(it, a_inserir);
            }
            else if (s == "RIGHT"){
                cin >> a_inserir;
                ++it;
                lista.insert(it,a_inserir);
                --it;
                --it;
            }
        }
}
    for(int i: lista) cout << i << endl;
    return 0;
}

/*
insert()	This function inserts a new item before the position the iterator points.
push_back()	This functions add a new item at the list’s end.
push_front()	It adds a new item at the list’s front.
pop_front()	It deletes the list’s first item.
size()	This function determines the number of list elements.
front()	To determines the list’s first items.
back()	To determines the list’s last item.
reverse()	It reverses the list items.
merge()	It merges two sorted lists.

*/