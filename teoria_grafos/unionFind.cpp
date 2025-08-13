#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//int nroNodes = 100;
int parents[100];

void init() {
    for(int i = 0; i<nroNodes; i++) {
        parents[i] = i;
    }
}

int find(int x) {
    int parent = parents[x];
    if(parent != x) {
        return find(parent);
    } 
    return x;
}

void unionPadres(int nodeIzq, int nodeDer) {
    int parentIzq = find(nodeIzq);
    int parentDer = find(nodeDer);
    parents[parentDer] = parentIzq;
}

int main() {
    int nodes; 
    cin>>nodes;
    init();
    int nroUniones; 
    cin>>nroUniones;
    while(nroUniones--) {
       int nodeIzq, nodeDer;
       cin>>nodeIzq>>nodeDer;
       unionPadres(nodeIzq, nodeDer); 
       for(int i = 1; i <= nodes;i++){
            cout<<"["<<parents[i]<<"]";
       }
       cout<<endl;
    }
    return 0;
}
/*
6
5
1 2
6 4
3 4
5 1
4 2
*/
