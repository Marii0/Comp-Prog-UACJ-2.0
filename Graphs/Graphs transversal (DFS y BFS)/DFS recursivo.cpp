#include "bits/stdc++.h"
using namespace std;

const int N = 26;
bool visited[N];
vector<int> adj[N];

void dfs(int node)
{
    // preorder
    visited[node] = 1;

    // inorder
    for (int i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    // postorder
    cout << node << " ";
}

int main()
{
    int max, x, y;

    cin >> max;

    for (int i = 0; i <= max; i++)
    {
        visited[i] = false;
    }

    while (cin >> x >> y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
}
