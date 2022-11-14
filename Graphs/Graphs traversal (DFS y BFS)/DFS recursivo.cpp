#include "bits/stdc++.h"
using namespace std;
#define RAYA "------------------------"

const int N = 1e7;
int contcomp = 0;
int contnodos;
bool visited[N];
vector<int> adjacency_list[N];

void dfs(int node)
{
    // preorder
    contnodos++; //cuenta el numero de nodos en el componente
    visited[node] = 1; // se coloca que fue visitado el booleano con index de un nodo

    // inorder
    for (int i : adjacency_list[node]) // se recorre todo los vecinos del nodo que esta en el index del vector
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
            contnodos=0;
            contcomp++; // cuenta los componentes
            cout << "Numero de omponents: " << contcomp << endl;
            dfs(i);
            cout << endl <<"Numero de nodos en el componente: " << contnodos << endl;
            cout<<RAYA;
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
        adjacency_list[x].push_back(y);
        adjacency_list[y].push_back(x);
    }

    findcomponent(min, max);
}
