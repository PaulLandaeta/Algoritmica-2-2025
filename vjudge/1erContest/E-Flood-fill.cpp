#include <bits/stdc++.h>
using namespace std;

char color = '2';
int DX[] = {-1, 0, 1, 0};
int DY[] = {0, 1, 0, -1};
int F, C;
int total;
vector<string> grafo;
void floodFill(int x, int y)
{
    if (grafo[x][y] == '0')
    { // es valida la posicion
        total++;
        grafo[x][y] = color; // esto funciona como si fuera la matriz de visitados
        for (int i = 0; i < 4; i++)
        {
            int nx = x + DX[i];
            int ny = y + DY[i];
            if (nx >= 0 && nx <= F && ny >= 0 && ny <= C)
            { // F maximo de filas C maximo de columnas
                floodFill(nx, ny);
            }
        }
    }
}

int main()
{
    int cases;
    scanf("%d\n\n", &cases);
    cout << " cases " << cases << endl;
    while (cases--)
    {
        string puntos;
        int x, y;
        getline(cin, puntos);
        cout << puntos << endl;
        x = stoi(puntos.substr(0, 2)) - 1;
        y = stoi(puntos.substr(3, 2)) - 1;
        cout << x << " " << y << endl;
        // como puedo guardar en x y y;
        while (true)
        {
            string fila;
            getline(cin, fila);
            if (fila.empty())
            {
                break;
            }
            grafo.push_back(fila);
        }

        F = grafo.size();
        C = grafo[0].size();
        for (int i = 0; i < F; i++)
        {
            cout << grafo[i] << endl;
        }
        total = 0;
        floodFill(x, y);
        for (int i = 0; i < F; i++)
        {
            cout << grafo[i] << endl;
        }
        cout << total << endl;
        grafo.clear();
    }
    return 0;
}