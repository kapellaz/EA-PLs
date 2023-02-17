#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> P;
int F(int x,int  y,int m);
int main(){
    int cavalos;
    cin >> cavalos;    
    int a=0;
    while(cavalos>0){
        int x,y,m;
        cin >> x >> y >> m;
        a += F(x,y,m);
        --cavalos;
    }
    cout << a << endl;
    return 0;
}

int F(int x,int  y,int m){
    int x1,y1;
    // gerar numero unico positivo combinando x e y para guardar no unordered set
    x1 = x + 201;
    y1 = y + 201;
    int pos = (x1*x1 + 3*x1 + 2*x1*y1 + y1 + y1*y1)/2;

    if(m==0){
        if(P.find(pos)!=P.end()) return 0;
        else{
            P.insert(pos);
            return 1;
        }
    }
    else{
        int v = 0;
        if(P.find(pos)==P.end()){
            P.insert(pos);
            v=1;       
        }
        return v + F(x+1,y+2,m-1) + F(x+1,y-2,m-1) + F(x+2,y+1,m-1) + F(x+2,y-1,m-1) + F(x-1,y+2,m-1) + F(x-1,y-2,m-1) + F(x-2,y+1,m-1) + F(x-2,y-1,m-1);
    }
}