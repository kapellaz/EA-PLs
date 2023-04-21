#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<vector<int>> graph;
vector<int> low, disc;
vector<bool> visited, ap;
int timer;

void dfs(int u, int parent) {
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    for (int v = 0; v < graph[u].size(); v++) {
        if (graph[u][v] == 0) continue;
        if (!visited[v]) {
            children++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= disc[u] && parent != -1) {
                ap[u] = true;
            }
        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (parent == -1 && children > 1) {
        ap[u] = true;
    }
}

int main(){
    int n;
    cin >> n; 
    string test;
    while(getline(cin, test)){
        if(n == 0) break;
        int m = 0;
        int a = 0, b;
        graph = vector<vector<int>> (n, vector<int>(n, 0));
        string line;
        while(getline(cin, line)){
            stringstream ss(line);
            int num;
            ss >> num;
            if(num == 0) break;
            a = num;
            while(ss >> num){
                b = num;
                graph[a-1][b-1] = 1;
                graph[b-1][a-1] = 1;
            }
        }


        low = vector<int>(n, -1);
        disc = vector<int>(n, -1);
        visited = vector<bool>(n, false);
        ap = vector<bool>(n, false);
        timer = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }

        int conta=0;

        for (int i = 0; i < n; i++) {
            if (ap[i]) {
                conta+=1;
            }
        }
  
        cout << conta << endl;

        cin >> n; 
        graph.clear();
        low.clear();
        disc.clear();
        visited.clear();
        ap.clear();
    }

    return 0;
}
