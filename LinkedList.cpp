#include<iostream>

template<typename T>
struct Node
{
    T value;
    Node* next;
    Node(const T& val) : value{ val }, next{ nullptr }
    {
    }
};

template<typename T>
class LinkedList
{
private:
    Node<T>* head;
public:
    LinkedList() : head{ nullptr }
    {
    }
    void insert(const T& val)
    {
        Node<T>* node{ new Node<T>(val) };
        node->next = head;
        head = node;
    }
    void printList()
    {
        Node<T>* nodeItr{ head };
        std::cout << "List:\n";
        while (nodeItr != nullptr)
        {
            std::cout << nodeItr->value << '\n';
            nodeItr = nodeItr->next;
        }
    }
    void insertPos(const int& pos, const T& val)
    {
        Node<T>* node{ new Node<T>(val) };
        int currentPos{ 0 };
        Node<T>* nodeItr{ head };
        if (pos == 0)
        {
            node->next = head;
            head = node;
        }
        else
        {
            while (nodeItr != nullptr)
            {
                if (pos == currentPos + 1)
                {
                    node->next = nodeItr->next;
                    nodeItr->next = node;
                    return;
                }
                ++currentPos;
                nodeItr = nodeItr->next;
            }
            delete node;
            std::cout << "Insertion Out of range\n";
        }
    }

    void insertAfterElement(const T& elem, const T& val)
    {
        Node<T>* node{ new Node<T>(val) };
        Node<T>* nodeItr{ head };
        while (nodeItr != nullptr)
        {
            if (nodeItr->value == elem)
            {
                node->next = nodeItr->next;
                nodeItr->next = node;
                return;
            }
            nodeItr = nodeItr->next;
        }
        delete node;
        std::cout << "Element " << elem << " not in the list.\n";
    }

    void insertBeforeElement(const T& elem, const T& val)
    {
        Node<T>* node{ new Node<T>(val) };
        if (head->value == elem)
        {
            node->next = head;
            head = node;
            return;
        }
        else
        {
            Node<T>* nodeItr{ head };
            while (nodeItr->next)
            {
                if (nodeItr->next->value == elem)
                {
                    node->next = nodeItr->next;
                    nodeItr->next = node;
                    return;
                }
                nodeItr = nodeItr->next;
            }
            std::cout << "Element " << elem << " not found.\n";

        }
    }


    void deleteElement(const T& elem)
    {
        if (head->value == elem)
        {
            Node<T>* next{ head->next };
            delete head;
            head = next;
            return;
        }
        else
        {
            Node<T>* nodeItr{ head };
            while (nodeItr->next)
            {
                if (nodeItr->next->value == elem)
                {
                    Node<T>* next{ nodeItr->next->next };
                    delete nodeItr->next;
                    nodeItr->next = next;
                    return;
                }
                nodeItr = nodeItr->next;
            }
            std::cout << "Element " << elem << " not found.\n";
        }
    }

    Node<T>* getHead()
    {
        return head;
    }

    void reversePrintList(const Node<T>* nodeItr)
    {
        if (nodeItr)
        {
            reversePrintList(nodeItr->next);
            std::cout << nodeItr->value << '\n';
        }
    }

    void reverseList()
    {
        Node<T>* currNode{ head };
        Node<T>* prevNode{ nullptr };
        Node<T>* nextNode{ nullptr };
        while (currNode)
        {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        head = prevNode ;

    }

    ~LinkedList()
    {
        Node<T>* nodeItr{ head };
        while (nodeItr != nullptr)
        {
            Node<T>* next{ nodeItr->next };
            delete nodeItr;
            nodeItr = next;
        }
    }
};


int main()
{
    LinkedList<int> test;
    test.insert(4);
    test.insert(3);
    test.insert(2);
    test.insert(1);
    test.reverseList();
    test.printList();

}
