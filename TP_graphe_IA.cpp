#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <fstream>
#include <limits>

using namespace std;

const double INF = numeric_limits<double>::infinity();

/* ===================== EDGE ===================== */

class Vertex;

class Edge {
    Vertex* to;
    double weight;

    Edge(Vertex* t, double w) : to(t), weight(w) {}

    friend class Vertex;
    friend class Graph;
};

/* ===================== VERTEX ===================== */

class Vertex {
    string name;
    vector<Edge*> edges;

    Vertex(const string& n) : name(n) {}

    ~Vertex() {
        for (Edge* e : edges)
            delete e;
    }

    friend class Graph;
};

/* ===================== MATRIX ===================== */

class Matrix {
    int n;
    vector<vector<double>> data;

    Matrix(int size) : n(size), data(size, vector<double>(size, INF)) {
        for (int i = 0; i < n; ++i)
            data[i][i] = 0.0;
    }

    friend class Graph;
};

/* ===================== GRAPH ===================== */

class Graph {
    vector<Vertex*> vertices;
    unordered_map<string, int> index;
    Matrix* adjMatrix;

public:
    Graph() : adjMatrix(nullptr) {}

    ~Graph() {
        for (Vertex* v : vertices)
            delete v;
        delete adjMatrix;
    }

    /* ----------- Ajout sommet ----------- */
    void add_vertex(const string& name) {
        if (index.find(name) != index.end())
            return;

        Vertex* v = new Vertex(name);
        index[name] = vertices.size();
        vertices.push_back(v);
    }

    /* ----------- Ajout arête ----------- */
    void add_edge(const string& from, const string& to, double value) {
        add_vertex(from);
        add_vertex(to);

        Vertex* v_from = vertices[index[from]];
        Vertex* v_to   = vertices[index[to]];

        Edge* e = new Edge(v_to, value);
        v_from->edges.push_back(e);
    }

    /* ----------- Lecture fichier ----------- */
    void read_graph(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Erreur ouverture fichier\n";
            return;
        }

        string from, to;
        double value;

        while (file >> from >> to >> value) {
            add_edge(from, to, value);
        }

        file.close();
    }

    /* ----------- DFS ----------- */
    void dfs(const string& start) {
        if (index.find(start) == index.end())
            return;

        set<string> visited;
        dfs_rec(vertices[index[start]], visited);
    }

private:
    void dfs_rec(Vertex* v, set<string>& visited) {
        if (visited.count(v->name))
            return;

        visited.insert(v->name);
        cout << v->name << endl;

        for (Edge* e : v->edges)
            dfs_rec(e->to, visited);
    }

// Je n'avais pas bien compris ce code de la dfs donc j'ai demandé à chat gpt
/* Pourquoi ce code de DFS ?

dfs
 vérifie que le sommet de départ existe
 crée une seule fois l’ensemble visited
 lance la récursion

dfs_rec
 implémente la DFS récursive

Les points clés

visited sert à éviter les boucles infinies

On teste visited au début pour ne pas revisiter un sommet

On marque le sommet avant d aller chez ses voisins

visited est passé par référence pour être partagé

La boucle :

for (Edge* e : v->edges)
    dfs_rec(e->to, visited);

je fais la DFS sur tous les voisins */


public:
    /* ----------- Matrice d'adjacence ----------- */
    void build_adjacency_matrix() {
        int n = vertices.size();
        delete adjMatrix;
        adjMatrix = new Matrix(n);

        for (int i = 0; i < n; ++i) {
            for (Edge* e : vertices[i]->edges) {
                int j = index[e->to->name];
                adjMatrix->data[i][j] = e->weight;
            }
        }
    }

    /* ----------- Floyd-Warshall ----------- */
    void floyd_warshall() {
        if (!adjMatrix)
            build_adjacency_matrix();

        int n = adjMatrix->n;
        auto& d = adjMatrix->data;

        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (d[i][k] + d[k][j] < d[i][j])
                        d[i][j] = d[i][k] + d[k][j];
    }

    /* ----------- Affichage matrice ----------- */
    void print_matrix() const {
        int n = adjMatrix->n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (adjMatrix->data[i][j] == INF)
                    cout << "INF ";
                else
                    cout << adjMatrix->data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

/* ===================== MAIN (exemple) ===================== */

int main() {
    Graph g;
    g.read_graph("graph0.gr");

    cout << "DFS depuis A:" << endl;
    g.dfs("A");

    g.build_adjacency_matrix();
    g.floyd_warshall();

    cout << "\nMatrice des plus courts chemins:" << endl;
    g.print_matrix();

    return 0;
}