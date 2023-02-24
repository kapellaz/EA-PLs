#include <iostream>


using namespace std;

int best;
int n,m,k;
bool connected[12];
int deg[12];
int g[12][12];

void F(int v, int c){
    if(c>=best) return;
    if(v==n){
        best=c;
    }
    for(int i = 0; i<n; i++){
        if(connected[i]==true && deg[i]<k){
            for(int j = 0; j<n; j++){
                if(connected[j]==false && g[i][j]>=0){
                    deg[i]+=1;
                    deg[j]+=1;
                    connected[j]=true;
                    F(v+1,c+g[i][j]);
                    deg[i]-=1;
                    deg[j]-=1;
                    connected[j]=false;
                }
            }
        }
    }
}

int main(){
    while(cin >> n >> m >> k){

        int max = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                g[i][j]=-1;
            }
        }
        int i = 0;
        while(i<m){
            int n1,n2,cost;
            cin >> n1 >> n2 >> cost;
            max+=cost;
  //          cout << n1 << " " << n2 << " " << endl;
            g[n1-1][n2-1]=cost;
            g[n2-1][n1-1]=cost;
            connected[n2-1]=false;
            connected[n1-1]=false;
            deg[n1-1]=0;
            deg[n2-1]=0;
            i++;
        }
        max+=1;
        best = max;
        connected[0]=true;

        F(1,0);
       // cout << best << endl;
        if(best < max) cout << best << endl;
        else cout << "NO WAY!" << endl;
    }

    return 0;
}
