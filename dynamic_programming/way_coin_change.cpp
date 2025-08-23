#include <bits/stdc++.h>
using namespace std;

int coins[] = {1,3,4};
int nroCoins = 3;
int f(int pos, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (dp[pos][sum] == -1)
    {
        int result = 0;
        for (int i = nroCoins - 1; i >= 0 ; i--)
        {
            if (coins[i] <= sum)
            {
                result += f(i, sum - coins[i]));
            }
        }
        dp[pos][sum] = result;
    }
    return dp[pos][sum];
}

int bu(int sum){
    int dp2[nroCoins][sum+1];
    // caso base; 
    for(int i = 0; i < nroCoins; i++) {
        dp2[i][0] = 1;
    }
    // solo agarro la primera fila 
    for(int i = 1; i <= sum; i++) {
        if(coins[0] <= i) {
            dp2[0][i] = dp2[0][i-coins[0]];
        }
    }

    // los demas casos 

    for(int i = 1; i< nroCoins; i++) {
        for ( int j = 1; j <= sum; j++) {
            if(coins[i] > j) {
                dp2[i][j] = dp2[i-1][j];
            } else {
                dp2[i][j] = dp2[i][j-coins[i]]+ dp2[i-1][j];
            }
        }
    }

    return dp2[nroCoins-1][sum];

}
int main()
{
    return 0;
}