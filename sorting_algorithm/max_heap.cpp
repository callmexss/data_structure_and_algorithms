#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

template <typename Item>
class MaxHeap
{
public:
    MaxHeap(int capacity) : m_capacity(capacity), m_count(0)
    {
        m_data = new Item[capacity + 1];
    }

    ~MaxHeap()
    {
        delete[] m_data;
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
        shiftUp(m_count);
    }

    Item extractMax()
    {
        assert(m_count > 0);
        Item ret = m_data[1];
        swap(m_data[1], m_data[m_count]);
        m_count--;
        shiftDown(1);
        return ret;
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
    int m_capacity;
    int m_count;

    void shiftUp(int n)
    {
        while (n > 1 && m_data[n] > m_data[n / 2])
        {
            swap(m_data[n], m_data[n / 2]);
            n /= 2;
        }
    }

    void shiftDown(int k)
    {
        while (2 * k <= m_count)
        {
            int j = 2 * k;
            if (j + 1 <= m_count)  // right child exists
            {
                if (m_data[j] < m_data[j + 1])  // set j to the bigger one of two children
                {
                    j++;
                }
            }

            if (m_data[k] >= m_data[j])  // m_data[k] is larger than both its children
                break;
                
            swap(m_data[k], m_data[j]);
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
    MaxHeap<int> maxHeap = MaxHeap<int>(100);
    int arr[5] = {1, 7, 3, 2, 4};
    for (int i = 0; i < 5; i++)
    {
        maxHeap.insert(i);
    }

    maxHeap.testPrint();

    maxHeap.clear();

    srand(time(NULL));
    for (int i = 0; i < 15; i++)
    {
        maxHeap.insert(rand() % 100);
    }
    maxHeap.testPrint();

    while (!maxHeap.isEmpty())
    {
        cout << maxHeap.extractMax() << " ";
    }
    cout << endl;

    return 0;
}
