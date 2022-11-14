#include "bits/stdc++.h"
using namespace std;

const int N = 1e7;
int cont = 0;
bool visited[N];
vector<int> adj[N];

void dfs(int node)
{
    // preorder
    visited[node] = 1; // se coloca que fue visitado el booleano con index de un nodo

    // inorder
    for (int i : adj[node]) // se recorre todo los vecinos del nodo que esta en el index del vector
    {
        if (!visited[i]) // si no esta visitado entra a la funcion dfs para la recursividad
        {
            dfs(i);
        }
    }

    // postorder
    cout << node << " ";
}

void findcomponent(int min, int max)
{ // encuntra todos los componentes de un grafo con el booleano visited con index de un nodo
    for (int i = min; i < max; i++)
    {
        if (!visited[i])
        {
            cont++; // cuenta los componentes
            cout << "Componente: " << cont << endl;
            dfs(i);
            cout << endl;
        }
    }
}

int main()
{
    int max, min, x, y;

    cin >> min >> max; // rango de los nodos

    for (int i = min; i <= max; i++) // coloca que no ha sido visitado un booleano con index del nodo
    {
        visited[i] = false;
    }

    while (cin >> x >> y) // la entrada son dos nodos que son vecinos
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    findcomponent(min, max);
}
