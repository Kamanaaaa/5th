// Prim's Algorithm with Trace

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    vector<bool> visited(V, false);
    visited[0] = true;

    int totalCost = 0;

    cout << "\n--- Prim Trace ---\n";

    for (int edge = 0; edge < V - 1; edge++) {
        int min = INT_MAX, x = 0, y = 0;

        for (int i = 0; i < V; i++) {
            if (visited[i]) {
                for (int j = 0; j < V; j++) {
                    if (!visited[j] && graph[i][j]) {
                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << "Selected Edge (" << x << ", " << y
             << ") weight=" << graph[x][y] << endl;

        totalCost += graph[x][y];
        visited[y] = true;
    }

    cout << "\nTotal MST Cost (Prim) = " << totalCost << endl;

    return 0;
}