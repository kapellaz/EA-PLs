#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int greedy(vector<int> &posicoes,vector<int> &guardado, int tam, int dist, int conta){
    for(int i = 0; i<tam; i++){
        if(guardado[i]==0){
            conta+=1;
            guardado[i]=1;
            int pos = posicoes[i];
            for(int j = i; j<tam; j++){
                if(posicoes[j]<=(pos+2*dist)){
                    guardado[j]++;
                }
            }    
        }
    }
    return conta;
}



int main(){
    int testes;
    cin >> testes;
    while(testes--){
        int nobjetos, dist;
        cin >> nobjetos >> dist;
        vector<int> posicoes(nobjetos);
        vector<int> guardado(nobjetos,0);
        vector<int> guardas;
        int i = 0;
        while(i<nobjetos){
            cin >> posicoes[i];
            i++;
        }
        sort(posicoes.begin(), posicoes.end());
        int res = greedy(posicoes, guardado,nobjetos,dist,0);
        cout << res << endl;
    }
}

