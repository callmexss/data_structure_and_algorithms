#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>


class SparseGraph
{
private:
    int m_n; // vertex
    int m_m; // edge
    bool m_directed;
    std::vector<std::vector<int>> m_g;

public:
    SparseGraph(int n, bool directed) : m_n(n), m_m(0), m_directed(directed)
    {
        for (int i = 0; i < m_n; ++i)
            m_g.push_back(std::vector<int>());
    }

    ~SparseGraph() {}

    int V() { return m_n; }
    int E() { return m_m;}

    bool hasEdge(int v, int w)
    {
        assert(v >= 0 && v < m_n);
        assert(w >= 0 && w < m_n);

        return (std::find(m_g[v].begin(), m_g[v].end(), w) != m_g[v].end());
    }

    void addEdge(int v, int w)
    {
        assert(v >= 0 && v < m_n);
        assert(w >= 0 && w < m_n);
        
        m_g[v].push_back(w);

        if (v != w && !m_directed)
            m_g[w].push_back(v);

        m_m++;
    }

    /**
     * Iterator to iterate the connected node of one vertex.
     */
    class AdjIterator
    {
    private:
        SparseGraph &m_G; // a reference of a graph
        int m_v; // the vertex to be iterated
        int m_index; // current index of vertex

    public:
        AdjIterator(SparseGraph &G, int v) : m_G(G), m_v(v), m_index(0) {}
        ~AdjIterator() {}

        int begin()
        {
            m_index = 0;
            if (m_G.m_g[m_v].size())
                return m_G.m_g[m_v][m_index];
            return -1;
        }

        int next()
        {
            m_index++;
            if (m_index < m_G.m_g[m_v].size())
                return m_G.m_g[m_v][m_index];
            return -1;
        }

        bool end()
        {
            return m_index >= m_G.m_g[m_v].size(); 
        }
    };

};