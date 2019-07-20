#include <iostream>
#include <vector>
#include <cassert>

#include "BST.h"

using namespace std;

typedef std::pair<int, int> TreeE;

int main(int argc, char const *argv[])
{
    BST<int, int> tree;
    // cout << tree.size() << endl;
    // tree.insert(1, 1);
    // cout << tree.size() << endl;

    vector<TreeE> vec{
        TreeE(1, 1),
        TreeE(7, 7),
        TreeE(3, 3),
        TreeE(2, 2),
        TreeE(4, 4),
        TreeE(5, 5),
        TreeE(6, 6),
    };

    for (auto e : vec)
        tree.insert(e.first, e.second);

    cout << "tree size: " << tree.size() << endl;

    assert(tree.contain(3) == true);
    assert(tree.contain(4) == true);

    int *val = tree.search(3);
    cout << "tree[3]: " << *val << endl;
    *val = 3;
    cout << "tree[3]: " << *val << endl;

    tree.preOrder();
    cout << endl;
    tree.inOrder();
    cout << endl;
    tree.postOrder();
    cout << endl;
    tree.levelOrder();
    cout << endl;

    assert(tree.minimum() == 1);
    assert(tree.maximum() == 7);

    tree.removeMax();
    tree.removeMin();

    assert(tree.minimum() == 2);
    assert(tree.maximum() == 6);

    return 0;
}
