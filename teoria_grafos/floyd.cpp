#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int INF = 100000000;
int grafo[110][110];
int nodes, aristas;
void floydWarshall() {
    for (int k = 1; k <= nodes; k++) {
        for (int i = 1; i <= nodes; i++) {
            for (int j = 1; j <= nodes; j++) {
                if(grafo[i][k] != INF && grafo[k][j]!= INF) {
                    grafo[i][j] = min(grafo[i][j],grafo[i][k] + grafo[k][j]);
                }
            }
        }
    }
}

int main() {
    
    vector<vector<int>> dist = {
        {0, 4, INF, 5, INF},
        {INF, 0, 1, INF, 6},
        {2, INF, 0, 3, INF},
        {INF, INF, 1, 0, 2},
        {1, INF, INF, 4, 0}
    };

    floydWarshall(dist);
    for(int i = 0; i<dist.size(); i++) {
        for(int j = 0; j<dist.size(); j++) {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}