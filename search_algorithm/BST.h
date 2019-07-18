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

    void insert(Key key, Value value)
    {
        m_root = insert(m_root, key, value);
    }

private:
    Node* m_root;
    int m_count;

    Node* insert(Node *node, Key key, Value value)
    {
        // insert Node(key, value) to BST whose root is node
        // return the new BST's root
        if (!node)
        {
            m_count++;
            return new Node(key, value);
        }

        if (value > node->value)
        {
            node->right = insert(node->right, key, value);
        }
        else if (value < node->value)
        {
            node->left = insert(node->left, key, value);
        }
        else
        {
            node->value = value;
        }

        return node;
    }
};