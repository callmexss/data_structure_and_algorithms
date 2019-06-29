/*
 * File:          heap.h
 * File Created:  Friday, 28th June 2019 5:20:30 pm
 * Author:        xss (callmexss@126.com)
 * Description:   implement heap data structure
 * -----
 * Last Modified: Friday, 28th June 2019 5:20:34 pm
 * Modified By:   xss (callmexss@126.com)
 * -----
 */
#include <iostream>
#include <algorithm>
#include <cassert>


template <typename Item>
class MaxHeap
{
public:
    MaxHeap(int n) : m_count(0), m_capacity(n)
    {
        m_data = new Item[n + 1];
    }

    MaxHeap(Item arr[], int n): MaxHeap(n)
    {
        for (int i = 0; i < n; ++i)
        {
            m_data[i + 1] = arr[i];
        }
        m_count = n;

        int k = n / 2;  // the first node that is not a leaf
        while (k >= 1)
        {
            shiftDown(k--);
        }
    }
    
    ~MaxHeap() { delete[] m_data; }

    int size() { return m_count; }

    bool isEmpty() { return m_count == 0; }

    void insert(Item item)
    {
        assert (m_count + 1 <= m_capacity);
        m_data[++m_count] = item;
        shiftUp(m_count);
    }

    Item extractMax()
    {
        assert (m_count > 0);
        Item ret = m_data[1];
        std::swap(m_data[1], m_data[m_count]);
        m_count--;
        shiftDown(1);
        return ret;
    }

private:
    Item *m_data;
    int m_count;
    int m_capacity;

    void shiftUp(int k)
    {
        while (k > 1 && m_data[k] > m_data[k / 2])
        {
            std::swap(m_data[k], m_data[k / 2]);
            k /= 2;
        }
    }

    void shiftDown(int k)
    {
        while (2 * k <= m_count)
        {
            int j = 2 * k;
            if (j + 1 <= m_count && m_data[j + 1] > m_data[j])
            {
                j++;
            }

            if (m_data[k] >= m_data[j])
            {
                break;
            }

            std::swap(m_data[k], m_data[j]);
            k = j;
        }
    }
};

template <typename Item>
class MinHeap
{
};
