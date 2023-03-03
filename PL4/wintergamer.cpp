#include <iostream>
#include <vector>

using namespace std;


int N;

void F(vector<vector<int>> &M,vector<vector<int>> &dp);

int main(){
    int n;
    cin >> n;
    while(n>0){
        cin >> N;
        //cout << N << endl;
        vector<vector<int>> M( N , vector<int> (N,0));
        vector<vector<int>> dp( N+1 , vector<int> (N+1,0));

        for(int i = 0; i<N; i++){
            for(int j = 0; j<=i; j++){
                cin >>  M[i][j];
            }
        }
        vector<int> aux(N+1);
        dp[N]= aux;

        F(M,dp);
        cout << dp[0][0] << endl;;
        n--;
    }
    return 0;
}



void F(vector<vector<int>> &M,vector<vector<int>> &dp){
    for(int i = N-1; i>=0; i--){
        for(int j = 0; j<N; j++){
            dp[i][j]=M[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
}