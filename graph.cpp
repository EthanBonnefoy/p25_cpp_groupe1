#include <iostream>
#include <vector>
#include <stdexcept>

struct Vertex;

struct Edge 
{
    double value;
    Vertex* begin;
    Vertex* end;

    Edge(double value, Vertex* begin, Vertex* end) : value(value), begin(begin), end(end) {};

    void print();
};

struct Vertex
{
    int name;
    std::vector<Edge*> edges;

    Vertex(int i) : name(i) {}

    void print()
    {
        std::cout << name << " : ";
        for (int i = 0; i < edges.size(); i++)
        {
            edges[i]->print();
        }
        std::cout << std::endl;
    }
};

inline void Edge::print()
{
    std::cout << "(" << end->name << ", " << value << ") ";
}


struct Graph 
{
    std::vector<Vertex*> v;

    // Graph () : v({}) {};

    void add_vertex(int a) 
    {
        if (a >= v.size())
        {
            for (int i = v.size(); i <= a; i++)
            {
                Vertex *vert = new Vertex(i);
                v.push_back(vert);
            }
        }
    }

    void add_edge(int a, int b, double val)
    {
        add_vertex(a);
        add_vertex(b);

        Edge *e = new Edge(val, v[a], v[b]);
        (v[a]->edges).push_back(e);
    }

    void print()
    {
        for (int a = 0; a < v.size(); a++)
        {
            v[a]->print();
        }
    }
};


int main()
{
    Graph g;

    g.add_edge(2, 5, 17.9);
    g.add_edge(5, 3, 23.9);
    g.add_edge(3, 4, 16.9);
    g.add_edge(4, 0, 699.9);

    g.print();

    return 0;
}
