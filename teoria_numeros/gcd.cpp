#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if(b == 0)  {
        return a; // case base 
    }
    return gcd(b, a%b); // paso recursivo 
}
int main(){
    
    int a,b,c;
    a = 100;
    b = 96;
    c = 48; 
    int gcd_ab = gcd(100,96);
    int gcd_ab_c = gcd(gcd_ab, 48);
    cout<<gcd_ab_c<<endl;
}