#include <iostream>
#include <vector>

#include "BST.h"

using namespace std;

typedef std::pair<int, int> TreeE;

int main(int argc, char const *argv[])
{
    BST<int, int> tree;
    cout << tree.size() << endl;
    tree.insert(1, 1);
    cout << tree.size() << endl;

    vector<TreeE> vec{
        TreeE(1, 2),
        TreeE(3, 4),
        TreeE(5, 6)
    };

    for (auto e : vec)
        tree.insert(e.first, e.second);

    cout << tree.size() << endl;

    return 0;
}
