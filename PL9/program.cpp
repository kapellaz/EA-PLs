#include <iostream>
#include <vector>
#include <deque>

using namespace std;


vector<vector<int>> places;
vector<int> dist;
deque<int> q;

int n,t;
int maxi = 0;

int algorithm(){
    dist = vector<int>(n);
    int u;
    int min = maxi;

    //every node (except first) with distance max
    for(int i = 1; i<n; i++) dist[i]=maxi;
    dist[0]=0;

    while(q.size()!=0){
        for(int i = 0; i<n; i++){
            if(q[i]!=-10){
                if(dist[i]<min){
                    min = dist[i];
                    u=i;
                }
            }
        }
        q[u]=-10;
        //finish if it is the final node
        if(u==t-1) break;

        for(int j = 0; j<n; j++){
            if(places[u][j] != -1){
                if(dist[j]>dist[u] + places[u][j]) dist[j]=dist[u]+places[u][j];
            }
        }
        min=maxi;
    }
    return dist[t-1];
}



int main(){
    while(cin >> n >> t){
        places = vector<vector<int>> (n,vector<int>(n));
        int node;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<=n; j++){
                if(j==0)cin >> node;
                else{
                    cin >> places[node-1][j-1];
                    if(places[node-1][j-1]>0) maxi += places[node-1][j-1];
                }
            }
            q.push_back(i);
        }

        cout << algorithm() << endl;
    }
}