#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<int>> infoPCS;


vector<int> set;
vector<int> ranks;
vector<vector<double>> edges;







int find(int a){
    if(set[a] != a){
        set[a] = find(set[a]);
    }
    return set[a];
}


void connect(int a, int b){
    if(ranks[a] < ranks[b]){
        set[a] = b;
    }else{
        set[b] = a;
    }
    if(ranks[a] == ranks[b]){
        ranks[b]++;
    }
}


double kruskal(){

        double dist = 0;

        //sorting edges in non-increasing order
        sort(edges.begin(), edges.end(), [](vector<double> aresta1, vector<double> aresta2) {
            return aresta1[0] < aresta2[0];
        });
        for(int i = 0; i < (int)edges.size(); i++){
            //Se tiverem raíz diferente
            if(find(edges[i][1]) != find(edges[i][2])){
                dist += edges[i][0];
                connect(find(edges[i][1]), find(edges[i][2]));
            
            }
        }
        return dist;
}



int main(){

    int computers;
    int c1;
    int c2;
    int nlig;
    int a, b;
    double cost;


    while(cin >> computers){

        edges = {};
        infoPCS = {};
        set = {};
        ranks = {};

        for(int i = 0; i < computers; i++){

            cin >> c1;
            cin >> c2;
            infoPCS.push_back({c1, c2});
            set.push_back(i);
            //height of the tree is initially 0
            ranks.push_back(0);
        }

        cin >> nlig;
        //connect nodes already connected
        for(int i = 0 ; i < nlig; i++){
            cin >> a;
            cin >> b;
            //Temos de ligar as raízes da árvore de cada um dos nós
            connect(find(a-1), find(b-1));
        }

        for(int i = 0; i < computers; i++){
            for(int j = i + 1; j < computers; j++){

                cost = (double) sqrt( fabs(infoPCS[i][0] - infoPCS[j][0]) * fabs(infoPCS[i][0] - infoPCS[j][0]) + fabs(infoPCS[i][1] - infoPCS[j][1]) * fabs(infoPCS[i][1] - infoPCS[j][1]));
                edges.push_back({cost, (double)i, (double)j});
            }
        }

        printf("%.2lf\n",kruskal());
	}
}