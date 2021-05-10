#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Graph
{
    int n;
    int no_edg;
    int edges[100][4], sets[100][10], top[100];

public:
    int input();
    void initialize_span_t();
    void sortedges();
    void kruskal_algo();
    int find_node(int);
};

int Graph::input()
{
    cout << "\n***************KRUSKAL'S ALGORITHM****************";
    cout << "\nEnter the no. of vertices in the graph:";
    cin >> n;
    no_edg = 0;

    cout << "\nEnter the weights of the following:\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cout << "edge " << i << " , " << j << " :";
            int w;
            cin >> w;
            if (w != 0)
            {
                no_edg++;

                edges[no_edg][1] = i;
                edges[no_edg][2] = j;
                edges[no_edg][3] = w;
            }
        }
    }

    cout << "\n\nThe edges in the given graph are::\n";
    for (int i = 1; i <= no_edg; i++)
    {
        cout << " < " << edges[i][1] << " , " << edges[i][2] << " > " << edges[i][3] << endl;
    }
}

void Graph::sortedges()
{
    for (int i = 1; i <= no_edg - 1; i++)
    {
        for (int j = 1; j <= no_edg - i; j++)
        {
            if (edges[j][3] > edges[j + 1][3])
            {
                int t = edges[j][1];
                edges[j][1] = edges[j + 1][1];
                edges[j + 1][1] = t;

                t = edges[j][2];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][2] = t;

                t = edges[j][3];
                edges[j][3] = edges[j + 1][3];
                edges[j + 1][3] = t;
            }
        }
    }

    cout << "\n\nAfter sorting the edges in the given graph are::\n";
    for (int i = 1; i <= no_edg; i++)
        cout << "" << edges[i][1] << " , " << edges[i][2] << " > ::" << edges[i][3] << endl;
}

void Graph::kruskal_algo()
{
    for (int i = 1; i <= n; i++)
    {
        sets[i][1] = i;
        top[i] = 1;
    }

    cout << "\n********* THE MINIMUM SPANNING TREE IS**************";
    for (int i = 1; i <= no_edg; i++)
    {
        int p1 = find_node(edges[i][1]);
        int p2 = find_node(edges[i][2]);

        if (p1 != p2)
        {
            cout << "The edge included in MST is ::"
                 << " < " << edges[i][1] << " , " << edges[i][2] << " > " << endl;
            for (int j = 1; j <= top[p2]; j++)
            {
                top[p1]++;
                sets[p1][top[p1]] = sets[p2][j];
            }
            top[p2] = 0;
        }
        else
        {
            cout << "Edge "
                 << " < " << edges[i][1] << " , " << edges[i][2] << " > "
                 << "is not included as it forms a cycle\n\n";
        }
    }
}

int Graph::find_node(int n)
{
    for (int i = 1; i <= no_edg; i++)
    {
        for (int j = 1; j <= top[i]; j++)
        {
            if (n == sets[i][j])
                return i;
        }
    }

    return -1;
}

int main()
{
    Graph obj;
    obj.input();
    obj.sortedges();
    obj.kruskal_algo();
    return 0;
}