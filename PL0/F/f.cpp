#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;

    queue<pair<int,int>> tarefas;
    
    for(int i = 0; i<n; i++){
        int at, pt;
        cin >> at >> pt;
        tarefas.push(make_pair(at,pt));
    }

    int current=0;
    while(!tarefas.empty()){
        auto tarefa = tarefas.front();
        current = max(current, tarefa.first) + tarefa.second;
        tarefas.pop();
    }

    cout << current << endl;
    return 0;
}