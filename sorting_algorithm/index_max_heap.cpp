#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>
#include <cmath>

#include "sorttesthelper.h"

using namespace std;

template <typename Item>
class IndexMaxHeap
{
public:
    IndexMaxHeap(int capacity) : m_capacity(capacity), m_count(0)
    {
        m_data = new Item[capacity + 1];
        m_indexes = new int[capacity + 1];
        m_reverse = new int[capacity + 1];
        for (int i = 0; i <= capacity; ++i)
            m_reverse[i] = 0;
    }

    ~IndexMaxHeap()
    {
        delete[] m_data;
        delete[] m_indexes;
        delete[] m_reverse;
    }

    int size()
    {
        return m_count;
    }

    bool isEmpty()
    {
        return m_count == 0;
    }

    void clear()
    {
        m_count = 0;
    }

    void insert(Item item)
    {
        assert(m_count + 1 <= m_capacity);
        m_data[++m_count] = item;
        m_indexes[m_count] = m_count;
        m_reverse[m_count] = m_count;
        shiftUp(m_count);
        // cout << "m_data: ";
        // SortTestHelper::printArray(m_data, m_count + 1);
        // cout << "m_indexes: ";
        // SortTestHelper::printArray(m_indexes, m_count + 1);
    }

    Item extractMax()
    {
        assert(m_count > 0);
        Item ret = m_data[m_indexes[1]];
        swap(m_indexes[1], m_indexes[m_count]);
        m_reverse[m_indexes[1]] = 1;
        m_reverse[m_indexes[m_count]] = 0;
        m_count--;
        shiftDown(1);
        return ret;
    }

    int extractMaxIndex()
    {
        assert(m_count > 0);

        int ret = m_indexes[1] - 1;
        swap(m_indexes[1], m_indexes[m_count]);
        m_reverse[m_indexes[1]] = 1;
        m_reverse[m_indexes[m_count]] = 0;
        m_count--;
        shiftDown(1);

        return ret;
    }

    Item getItem(int i)
    {
        return m_data[i + 1];
    }

    bool contain(int i)
    {
        assert(i + 1 >= 1 && i <= m_capacity);
        return m_reverse[i + 1] != 0;
    }

    void change(int i, Item newItem)
    {
        assert(contain(i));
        i += 1;
        m_data[i] = newItem;

        // find indexes[j] = i, j is the position of data[i] in the heap
        // then shiftUp(j); shiftDown(j);
        // for (int j = 1; j <= m_count; j++)
        // {
        //     if (m_indexes[j] == i)
        //     {
        //         shiftUp(j);
        //         shiftDown(j);
        //         return;
        //     }
        // }
        int j = m_reverse[i];
        shiftUp(j);
        shiftDown(j);
    }

    void testPrint()
    {

        if (size() >= 100)
        {
            cout << "Fancy print can only work for less than 100 int";
            return;
        }

        if (typeid(Item) != typeid(int))
        {
            cout << "Fancy print can only work for int item";
            return;
        }

        cout << "The Heap size is: " << size() << endl;
        cout << "data in heap: ";
        for (int i = 1; i <= size(); i++)
            cout << m_data[i] << " ";
        cout << endl;
        cout << endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while (n > 0)
        {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level - 1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for (int level = 0; level < max_level; level++)
        {
            string line1 = string(max_level_number * 3 - 1, ' ');

            int cur_level_number = min(m_count - int(pow(2, level)) + 1, int(pow(2, level)));
            bool isLeft = true;
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++)
            {
                putNumberInLine(m_data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
                isLeft = !isLeft;
            }
            cout << line1 << endl;

            if (level == max_level - 1)
                break;

            string line2 = string(max_level_number * 3 - 1, ' ');
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
                putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
            cout << line2 << endl;

            cur_tree_max_level_number /= 2;
        }
    }

private:
    Item *m_data;
    int *m_indexes;
    int *m_reverse;
    int m_capacity;
    int m_count;

    void shiftUp(int n)
    {
        // cout << "n: " << n << " ";
        // cout << m_indexes[n] << m_indexes[n / 2] << endl;
        while (n > 1 && m_data[m_indexes[n]] > m_data[m_indexes[n / 2]])
        {
            swap(m_indexes[n], m_indexes[n / 2]);
            m_reverse[m_indexes[n]] = n;
            m_reverse[m_indexes[n / 2]] = n / 2;
            n /= 2;
        }
    }

    void shiftDown(int k)
    {
        while (2 * k <= m_count)
        {
            int j = 2 * k;
            if (j + 1 <= m_count) // right child exists
            {
                if (m_data[m_indexes[j]] < m_data[m_indexes[j + 1]]) // set j to the bigger one of two children
                {
                    j++;
                }
            }

            if (m_data[m_indexes[k]] >= m_data[m_indexes[j]]) // m_data[k] is larger than both its children
                break;

            swap(m_indexes[k], m_indexes[j]);
            m_reverse[m_indexes[k]] = k;
            m_reverse[m_indexes[j]] = j;
            k = j;
        }
    }

    void putNumberInLine(int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft)
    {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if (num >= 10)
        {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else
        {
            if (isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine(string &line, int index_cur_level, int cur_tree_width)
    {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
        assert(offset_left + 1 < line.size());
        int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert(offset_right < line.size());

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }
};

int main()
{
    IndexMaxHeap<int> indexMaxHeap = IndexMaxHeap<int>(100);
    int arr[5] = {1, 7, 3, 2, 4};
    for (int i = 0; i < 5; i++)
    {
        indexMaxHeap.insert(arr[i]);
    }

    indexMaxHeap.change(3, 10);

    indexMaxHeap.testPrint();

    while (!indexMaxHeap.isEmpty())
    {
        cout << indexMaxHeap.extractMax() << " ";
    }
    cout << endl;

    indexMaxHeap.clear();

    srand(time(NULL));
    for (int i = 0; i < 15; i++)
    {
        indexMaxHeap.insert(rand() % 100);
    }
    indexMaxHeap.testPrint();

    while (!indexMaxHeap.isEmpty())
    {
        cout << indexMaxHeap.extractMax() << " ";
    }
    cout << endl;

    return 0;
}
