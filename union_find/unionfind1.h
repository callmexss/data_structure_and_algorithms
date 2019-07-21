#include <iostream>
#include <cassert>

namespace UF1
{


class UnionFind
{
private:
    int* m_id;
    int m_count;

public:
    UnionFind(int n) : m_count(n)
    {
        m_id = new int[n];
        for (int i = 0; i < n; i++)
        {
            m_id[i] = i;
        }
    }

    ~UnionFind() { delete[] m_id; }

    int find(int p)
    {
        assert(p >= 0 && p < m_count);
        return m_id[p];
    }

    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }

    void unionElements(int p, int q)
    {
        int pId = m_id[p];
        int qId = m_id[q];
        if (pId == qId)
            return ;
        for (int i = 0; i < m_count; ++i)
            if (m_id[i] == pId)
                m_id[i] = qId;
    } 
};


} // namespace UF1