#include <iostream>
#include <stack>
#include <vector>

using namespace std;
vector<vector<int>> g;
vector<int> color;

int n, m;


bool colour(int u){
    stack<int> s;
    s.push(u);
    color[u]=1;
    while(s.size()>0){
        int k = s.top();
        s.pop();
        for(int v = 1; v<=n; v++){
            if(g[k][v]==1){
                if(color[v]==0){
                    color[v]= color[k] %2 +1;
                    s.push(v);
                }else if(color[v] == color[k] && k != v){
                    return false;
                }
            }
        }
    }
    return true;
}



bool F(int n){
    for(int i = 1; i<=n; i++){
        if(color[i]==0){
            if(colour(i)==false) return false;
        }
    }
    return true;
}




int main(){
    while(cin >> n >> m){
        color = vector<int>(n+1,0);
        g = vector<vector<int>>(n+1,vector<int>(n+1,0));
        while(m--){
            int a,b;
            cin >> a >> b;
            g[a][b] = 1;
            g[b][a] = 1;
 
        }
        bool res = F(n); 
        if(res) cout << "NOT SURE" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}