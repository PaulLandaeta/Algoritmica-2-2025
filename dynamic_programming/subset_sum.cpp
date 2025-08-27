#include <bits/stdc++.h>
using namespace std;

int numbers[] = {1, 2, 7 , 9 , 10};
int sum = 21;
int cantNumbers = 5;
int bup() {
    bool dp2[10][25];
    dp2[0][0] = true;
    for(int i = 1; i < cantNumber; i++) {
        for(int j = 0; < 22; j++){
            if(j < numbers[i-1]) {
                dp2[i][j] = dp2[i-1][j];
            } else {
                dp2[i][j] = dp2[i-1][j] || dp2[i-1][j-numbers[i-1]];
            }
        }
    }

    for(int i = 0; i <= cantNumbers; i++) {
        for(int j = 0; j < 22; j++) {
            cout<<"["<<<dp2[i][j]<<"]";
        }
        cout<<endl;
    }    
}


int dp[10][25];

bool f(int pos, int sum) {
    if(sum == 0) {
        return true;
    }
    if(pos > numbers.size()) {
        // return (sum==0)?true:false;
        // return (sum==0);
        // return !sum;
        if(sum==0) {
            return true;
        } else{
            return false;
        }
    }
    if(dp[pos][sum] == -1) {
        bool result = false;
        if(sum >= numbers[pos]) {
            result = f(pos+1, sum - numbers[pos]);  
        }
        result = result || f(pos+1, sum);
        dp[pos][sum] = result;
    }
    return dp[pos][sum];
}

int main() {
    bup();
    return 0;
}