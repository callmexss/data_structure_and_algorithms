#include <queue>

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

        Node(Node *node)
        {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    BST() : m_count(0), m_root(nullptr)
    {
    }

    ~BST()
    {
        destroy(m_root);
    }

    int size() { return m_count; }

    bool isEmpty() { return m_count == 0; }

    void insert(Key key, Value value)
    {
        m_root = insert(m_root, key, value);
    }

    bool contain(Key key)
    {
        contain(m_root, key);
    }

    Value *search(Key key)
    {
        return search(m_root, key);
    }

    void preOrder()
    {
        preOrder(m_root);
    }

    void inOrder()
    {
        inOrder(m_root);
    }

    void postOrder()
    {
        postOrder(m_root);
    }

    void levelOrder()
    {
        std::queue<Node *> q;
        if (m_root)
        {
            q.push(m_root);
            while (!q.empty())
            {
                Node *node = q.front();
                q.pop();
                std::cout << node->key << std::endl;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
    }

    Key minimum()
    {
        assert(m_count != 0);
        // Node *cur = m_root;
        // while (cur)
        // {
        //     if (cur->left)
        //         cur = cur->left;
        //     else
        //         break;
        // }
        // return cur->key;
        Node *node = minimum(m_root);
        return node->key;
    }

    Key maximum()
    {
        assert(m_count != 0);
        // Node *cur = m_root;
        // while (cur)
        // {
        //     if (cur->right)
        //         cur = cur->right;
        //     else
        //         break;
        // }
        // return cur->key;
        Node *node = maximum(m_root);
        return node->key;
    }

    void removeMin()
    {
        if (m_root)
            m_root = removeMin(m_root);
    }

    void removeMax()
    {
        if (m_root)
            m_root = removeMax(m_root);
    }

    void remove(Key key)
    {
        m_root = remove(m_root, key);
    }

private:
    Node *m_root;
    int m_count;

    Node *insert(Node *node, Key key, Value value)
    {
        // insert Node(key, value) to BST whose root is node
        // return the new BST's root
        if (!node)
        {
            m_count++;
            return new Node(key, value);
        }

        if (key > node->key)
        {
            node->right = insert(node->right, key, value);
        }
        else if (key < node->key)
        {
            node->left = insert(node->left, key, value);
        }
        else
        {
            node->value = value;
        }

        return node;
    }

    bool contain(Node *node, Key key)
    {
        if (!node)
            return false;

        if (key == node->key)
            return true;
        else if (key > node->key)
            return contain(node->right, key);
        else
            return contain(node->left, key);
    }

    Value *search(Node *node, Key key)
    {
        if (!node)
            return nullptr;

        if (key == node->key)
            return &(node->value);
        else if (key > node->key)
            return search(node->right, key);
        else
            return search(node->left, key);
    }

    void preOrder(Node *node)
    {
        if (node)
        {
            std::cout << node->key << std::endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node *node)
    {
        if (node)
        {
            inOrder(node->left);
            std::cout << node->key << std::endl;
            inOrder(node->right);
        }
    }

    void postOrder(Node *node)
    {
        if (node)
        {
            postOrder(node->left);
            postOrder(node->right);
            std::cout << node->key << std::endl;
        }
    }

    void destroy(Node *node)
    {
        if (node)
        {
            destroy(node->left);
            destroy(node->right);
            delete node;
            m_count--;
        }
    }

    Node *minimum(Node *node)
    {
        if (node->left == nullptr)
            return node;

        return minimum(node->left);
    }

    Node *maximum(Node *node)
    {
        if (node->right == nullptr)
            return node;

        return maximum(node->right);
    }

    Node* removeMin(Node *node)
    {
        if (node->left == nullptr)
        {
            Node* rightNode = node->right;
            delete node;
            m_count--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    Node* removeMax(Node* node)
    {
        if (node->right == nullptr)
        {
            Node* leftNode = node->left;
            delete node;
            m_count--;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }

    Node* remove(Node* node, Key key)
    {
        if (node == nullptr)
            return nullptr;

        if (key < node->key)
        {
            node->left = remove(node->left, key);
            return node;
        }
        else if (key > node->key)
        {
            node->right = remove(node->right, key);
            return node;
        }
        else // key == node->key
        {
            if (node->left == nullptr)
            {
                Node* rightNode = node->right;
                delete node;
                m_count--;
                return rightNode;
            }
            if (node->right == nullptr)
            {
                Node* leftNode = node->left;
                delete node;
                m_count--;
                return leftNode;
            }
        }

        // node->left != nullptr and node->right != nullptr
        Node *successor = new Node(minimum(node->right));
        m_count++;

        successor->right = removeMin(node->right);
        successor->left = node->left;

        return successor;
    }
};