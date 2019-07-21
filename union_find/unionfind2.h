#include <iostream>
#include <cassert>

namespace UF2
{

class UnionFind
{
private:
    int* m_parent;
    int m_count;

public:
    UnionFind(int n) : m_count(n)
    {
        m_parent = new int[n];
        for (int i = 0; i < m_count; ++i)
            m_parent[i] = i;
    }

    ~UnionFind() { delete[] m_parent; }
    
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
        m_parent[pRoot] = qRoot;
    }

};
    
} // namespace UF2
