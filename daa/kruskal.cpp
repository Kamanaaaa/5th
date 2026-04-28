// Kruskal's Algorithm with Trace

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

int findParent(int v, vector<int>& parent) {
    if (parent[v] == v)
        return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int u, int v, vector<int>& parent) {
    parent[findParent(u, parent)] = findParent(v, parent);
}

int main() {
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter (u v weight):\n";
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) { return a.weight < b.weight; });

    vector<int> parent(V);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0, edgeCount = 0;

    cout << "\n--- Kruskal Trace ---\n";

    for (auto e : edges) {
        cout << "Checking Edge (" << e.u << ", " << e.v
             << ") weight=" << e.weight << endl;

        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            cout << "  Added to MST\n";
            unionSet(e.u, e.v, parent);
            totalCost += e.weight;
            edgeCount++;
        } else {
            cout << "  Rejected (Cycle)\n";
        }

        if (edgeCount == V - 1)
            break;
    }

    cout << "\nTotal MST Cost (Kruskal) = " << totalCost << endl;
    return 0;
}