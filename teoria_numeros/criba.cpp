#include <iostream>
#include <vector>
using namespace std;

vector<int> criba(int n) {
    vector<bool> esPrimo(n+1, true);
    esPrimo[0] = esPrimo[1] = false;
    // i < sqrt(n) // ()^2 i*i <= n 
    for(int i = 2; i*i<= n; i++ ) {
        if(esPrimo[i]) {
            for(int j = i * i; j<=n ; j+=i) {
                esPrimo[j] = false;
            }
        }
    }
    vector<int> primos;
    for(int i=2; i<=n;i++){
        if(esPrimo[i]){
            primos.push_back(i);
        }
    }
    return primos;
}
int main(){
    vector<int>  primos = criba(100);
    for(int i = 0; i< primos.size();i++) {
        cout<<"["<<primos[i]<<"]";
    }
    cout<<endl;
}