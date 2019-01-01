#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Undirected graph implementation in C++.
*/
class Graph
{
  private:
    int v;                   //number of vertices
    int e;                   // number of edges
    vector<vector<int>> adj; // adjacency list --list of adjacent vertices
                             //for a given vertex

  public:
    Graph(int numberOfVertices)
    {
        this->v = numberOfVertices;
        adj.resize(numberOfVertices);
        for(int i =0;i<numberOfVertices;i++)
        {
            for(vector<int>::iterator it = adj[i].begin();it!=adj[i].end();++it)
              cout<<*it<<" \t";

        }
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
        e++;
    }
    int E()
    {
        return e;
    }
    int V()
    {
        return v;
    }

    vector<int> adjacent(int vertex)
    {
        return adj[vertex];
    }
};

class DFS
{
  private:
    vector<bool> marked; // has the vertex v been visited by dfs()?
    vector<int> edgeTo;
    int s; // source vertex
    void dfs(Graph G, int s)
    {
        marked[s] = true;
        vector<int> vects = G.adjacent(s);
        for (vector<int>::iterator it = vects.begin(); it != vects.end(); ++it)
        {
            if (!marked[*it])
                dfs(G, *it);
        }
    }

  public:
    DFS(Graph g, int s)
    {
        marked.resize(g.V());
        edgeTo.resize(g.V());
        dfs(g, s);
    }

    /**
    * True if there is a path from s to v.
    * False otherwise
   */
    bool hasPathTo(int v)
    {
        return marked[v] == true;
    }
    /**
    * Returns the list of vertices in the path .
    * Returns null if path does not exist.
   */
    stack<int> pathTo(int v)
    {

        if (!hasPathTo(v))
            return {}; // empty vector

        stack<int> *path = new stack<int>();
        for (int x = v; x != s; x = edgeTo[v])

        {

            path->push(x);
        }
        path->push(s);
        return *path;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Graph *g = new Graph(8);
    g->addEdge(0, 1);
    g->addEdge(0, 2);

    g->addEdge(1, 3);
    g->addEdge(1, 4);

    g->addEdge(3, 7);
    g->addEdge(4, 7);

    g->addEdge(5, 7);
    g->addEdge(6, 7);

    g->addEdge(2, 5);
    g->addEdge(2, 6);

    g->addEdge(5, 7);
    g->addEdge(6, 7);

    for (int i = 0; i < 8; i++)
    {
        cout << "Adjacent to " + i << endl;
        for (vector<int>::iterator it = g->adjacent(i).begin(); it != g->adjacent(i).end(); ++it)
        {
            std::cout << " " << *it;
        }

    }
    DFS *d = new DFS(*g, 0);
    cout << endl;
    cout << "0 to 7" << endl;
    // stack<int> stk = d->pathTo(7);
    // while (!stk.empty())
    // {
    //     std::cout << ' ' << stk.top();
    // }
    int a;
    cin >> a;
    return 0;
}
