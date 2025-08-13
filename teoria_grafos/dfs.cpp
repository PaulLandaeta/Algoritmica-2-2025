#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
// [1,2,3,4,5]
// vector<int> v(3);
// v = [0,0,0]
// v[0]=1;
// v[1]=2;
// v[3]=3;
// v.push_back(1);
int vis[10];
// vis = [0,0,0,0,0,0,0,0,0,0]
vector<int> grafo[10];

void dfs(int nInicial) {
    // el nodo aun no ha sido visitado 
    if(vis[nInicial] == 0) {
        vis[nInicial] = 1;
        for(int j = 0; j< grafo[nInicial].size(); j++) {
            int amigo = grafo[nInicial][j];
            // que el amigo no haya sido visitado
            if(vis[amigo] == 0) {
                dfs(amigo);
            }
        }
    }
}

int main() {
	// your code goes here
	int nodes, aristas;
	cin>>nodes>>aristas;
	for(int i = 0 ; i < aristas ; i++) {
		int nInicial, nFinal;
		cin>>nInicial>>nFinal;
		grafo[nInicial].push_back(nFinal);
	}
	
	// Mostrar el Grafo 
	for(int i = 0;i<= nodes;i++){
		cout<< "["<< i << "] -> "; 
		for(int j = 0; j < grafo[i].size() ; j++) {
			cout<< "[" << grafo[i][j] << "]";
		}
		cout<<endl;
	}
	
	return 0;
}


/* 
    5 6
    1 3
    1 2
    2 3
    2 5
    5 4
    3 4
*/