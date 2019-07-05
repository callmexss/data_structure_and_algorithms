template <typename Key, typename Value>
class BST
{
public:
    struct Node
    {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value)
        {
            this->key = key;
            this->value = value;
            this->left = this->right = nullptr;
        }
    };

    BST() : m_count(0), m_root(nullptr)
    {
    }

    ~BST()
    {
        // TODO: ~BST()
    }

    int size() { return m_count; }

    bool isEmpty() { return m_count == 0; }

private:
    Node *root;
    int m_count;
};