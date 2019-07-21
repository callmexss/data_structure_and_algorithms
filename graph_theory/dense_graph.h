#include <iostream>
#include <vector>
#include <cassert>


class DenseGraph
{
private:
    int m_n, m_m;
    bool m_directed;
    std::vector<std::vector<bool>> m_g;

public:
    DenseGraph(int n, bool directed) : m_n(n), m_directed(directed), m_m(0)
    {
        for (int i = 0; i < m_n; ++i)
            m_g.push_back(std::vector<bool>(n, false));
    }

    ~DenseGraph() {}

    int V() { return m_n; }
    int E() { return m_m;}

    bool hasEdge(int v, int w)
    {
        assert(v >= 0 && v < m_n);
        assert(w >= 0 && w < m_n);

        return m_g[v][w];
    }

    void addEdge(int v, int w)
    {
        assert(v >= 0 && v < m_n);
        assert(w >= 0 && w < m_n);

        if (!hasEdge(v, w))
        {
            m_g[v][w] = true;
            if (!m_directed)
                m_g[w][v] = true;
            m_m++;
        }
    }

    class AdjIterator
    {
    private:
        DenseGraph &m_G;
        int m_v;
        int m_index;

    public:
        AdjIterator(DenseGraph& g, int v) : m_G(g), m_v(v), m_index(-1) {}
        // return the first v
        int begin()
        {
            m_index = -1;
            return next();
        }

        // return next v
        int next()
        {
            for (m_index += 1; m_index < m_G.V(); m_index++)
            if (m_G.m_g[m_v][m_index])
                return m_index;
            return -1;
        }

        bool end()
        {
            return m_index >= m_G.V();
        }
    };

};