#include <iostream>
#include <cassert>

namespace UF4
{

class UnionFind
{
private:
    int* m_parent;
    int* m_rank;
    int m_count;

public:
    UnionFind(int n) : m_count(n)
    {
        m_parent = new int[n];
        m_rank = new int[n];
        for (int i = 0; i < m_count; ++i)
        {
            m_parent[i] = i;
            m_rank[i] = 1;
        }
    }

    ~UnionFind()
    { 
        delete[] m_parent;
        delete[] m_rank;
    }
    
    int find(int p)
    {
        assert(p >= 0 && p < m_count);
        while (m_parent[p] != p)
        {
            p = m_parent[p];
        }
        return p;
    }

    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }

    void unionElements(int p, int q)
    {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot)
            return ;

        if (m_rank[pRoot] < m_rank[qRoot])
        {
            m_parent[pRoot] = qRoot;
        }
        else if (m_rank[pRoot] > m_rank[qRoot])
        {
            m_parent[qRoot] = pRoot;
        }
        else
        {
            m_parent[pRoot] = qRoot;
            m_rank[qRoot] += 1;
        }
    }

};
    
} // namespace UF2
