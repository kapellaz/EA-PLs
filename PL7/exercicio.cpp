#include <iostream>
#include <vector>


using namespace std;

int m,n;



vector<vector<bool>> g;

int ub(int i, vector<bool> &x,int c){
    for(int j = i; j < n;j++){
        bool b = true;
        for(int k = 0; k<i; k++){
            if(x[k] && g[j][k]){
                b = false;
                break;
            }
        }
        if(b){
            c+=1;
        }
    }
    return c;
}

int best = 0;

void F(int i, vector<bool> &x,int c){
    if(ub(i,x,c)<=best){
        return;
    }
    if(i == n){
        if(c>best){
            best = c;
        }
        return;
    }
    x[i]=false;

    F(i+1,x,c);
    bool b = true;
    for(int j = 0; j<=i-1; j++){
        if(x[j]==true && g[i][j]==true){
            b = false;
            break;
        }
    }
    if(b==true){
        x[i]=true;
        F(i+1,x,c+1);
    }
}




int main(){
    cin >> n >> m;
    g = vector<vector<bool>>(n,vector<bool>(n,false));
    vector<bool> x(n,false);


    while(m--){
        int p1, p2;
        cin >> p1 >> p2;
        g[p1][p2]=true;
        g[p2][p1]=true;
    }

    F(0,x,0);
    cout << best << endl;
    return 0;
}