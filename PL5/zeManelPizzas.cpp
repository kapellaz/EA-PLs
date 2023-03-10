#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int subset(int n, int c,vector <vector<bool>> &dp, vector<int> &timePizza){
    int f=0;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=c/2;j++){
            if(j < timePizza[i]){
                dp[i][j]= dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j] || dp[i-1][j-timePizza[i]];
            }
            if(i == n){
                if(dp[i][j]==true) f = j;
            }

        }
    }

    int other = c - f;
    return abs(other-f);
}



int main(){
    int n;
    int c;
    while(cin >> n){
        vector<int> timePizza(n+1,0);
        int p = 0;
        int soma= 0;
        while(p < n){
            int k;
            cin >> k;
            timePizza[p+1]=k;
            soma += k;
            p++;
        }
        vector<vector<bool>> dp;
        dp = vector<vector<bool>>(n+1,vector<bool>(soma/2,false));
        dp[0][0]= true;
        int res = subset(n,soma, dp, timePizza);

        cout << res << endl;
    }
    return 0;
}