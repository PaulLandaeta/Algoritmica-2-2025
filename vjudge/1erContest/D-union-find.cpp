#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int nroNodes;
int parents[100];
int nivel[100];

void init()
{
    for (int i = 0; i < nroNodes; i++)
    {
        parents[i] = i;
        nivel[i] = 0;
    }
}

int find(int x)
{
    int parent = parents[x];
    if (parent != x)
    {
        parents[x] = find(parent);
    }
    return parents[x];
}

void unionPadres(int nodeIzq, int nodeDer)
{
    int parentIzq = find(nodeIzq);
    int parentDer = find(nodeDer);
    // CASE 3
    if (nivel[parentIzq] < nivel[parentDer])
    {
        parents[parentIzq] = parentDer;
    }
    else
    {
        // Case 4
        parents[parentDer] = parentIzq;
        // Case 1 y 2
        if (nivel[parentIzq] == nivel[parentDer])
        {
            nivel[parentIzq]++;
        }
    }
}

int main()
{
    int cases;
    scanf("%d\n\n", &cases)
    // cin >> cases;
    while (cases--)
    {
        string nroNodosString;
        getline(cin,nroNodosString);
        nroNodes = nroNodosString[0] - 'A' + 1; // 'E' - 'A' => 69 - 65 +1= 5
        init();
        int total = nroNodes;
        string arista;
        while (true){ // AB
            getline(cin,arista);
            if(arista.empty()) {
                break;
            }
            int origen, destino;
            origen = arista[0] - 'A';  // 'A' - 'A' = 65 - 65 = 0
            destino = arista[1] - 'A'; // 'B' - 'A' = 66 - 65 = 1
            int padreOrigen = find(origen);
            int padreDestino = find(destino);
            if (padreDestino != padreOrigen)
            {
                unionPadres(origen, destino);
                total--;
            }
        }
        cout<<total<<endl;
        if(cases!=0) {
            cout<<endl;
        }
    }
    return 0;
}
/*
1
E
AB
CE
DB
EC
*/
