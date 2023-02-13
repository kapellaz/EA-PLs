#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    unordered_set<int> list;
    int aux;
    cin >> aux;
    int nmb;
    int i = 0;
    while(cin >> nmb){
        if(nmb != 0){
            list.insert(nmb);
        }else{
            for(unordered_set<int>::iterator itr=list.begin(); itr!= list.end() && i!=1; itr++){
                for(unordered_set<int>::iterator itr2=itr; itr2!= list.end() && i!=1; itr2++){
                    if(*itr < 0 && *itr2 < 0  && (*itr!=*itr2)){
                        if(list.count((-*itr)+(-*itr2))==1){
                            cout << "Fair"<< endl;
                            i=1;
                        }
                    }
                    if(*itr > 0 && *itr2 > 0 && (*itr!=*itr2)){
                        if(list.count(-(*itr+*itr2))==1){
                            cout << "Fair"<< endl;
                            i=1;
                        }
                    }
                }
            }
            if(i==0) cout << "Rigged"<< endl;
            list.clear();
            i = 0;
            cin >> aux;
        }
    }
    return 0;
}

