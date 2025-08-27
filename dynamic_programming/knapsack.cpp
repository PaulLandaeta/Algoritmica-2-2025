#include <bits/stdc++.h>
using namespace std;

int valores[] = {5,4,8,6};
int pesos[] = {1, 2, 4, 5};
int cantObjetos = 4;
int mochila = 5;

int bu() {
    int dp2[cantObjetos+2][mochila+2];
    memset(dp2, 0,sizeof dp2); // setear todos los elementos en 0;
    // Caso Base
    for(int i = 0; i < mochila+2; i++) {
        dp2[0][i] = 0;
    }

    for(int i = 1; i < cantObjetos; i++) {
        for(int j = 0; j < mochila+2; j++) {
            if(pesos[i-1] > j) {
                dp2[i][j] = dp2[i-1][j]; 
            }else {
                dp2[i][j] = max(
                    dp2[i-1][j], // si no tomamos el objeto i
                    valores[i-1] + dp2[i-1][j-pesos[i-1]] // si tomo el objeto i
                )
            }
        }
    }
}

int f(int pos, int pesoM) {
    if(pesoM == 0) {
        return 0;
    }
    if(pos >= cantObjetos) {
      return 0;
    }
    if(dp[pos][pesoM] == -1 ) {
        int result = f(pos+1, pesoM);// si no lo tomo
        if(pesoM >= pesos[pos]){
            result = max(result, valores[pos]+ f(pos+1, pesoM-pesos[pos]) // si lo tomo
        }
        dp[pos][pesoM] = result;
    }
    return dp[pos][pesoM];

}