#include <iostream>

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr || head->data >= value)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr && current->next->data < value)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void remove(int value)
    {
        Node *current = head;
        Node *prev = nullptr;

        while (current != nullptr && current->data != value)
        {
            prev = current;
            current = current->next;
        }

        if (current != nullptr)
        {
            if (prev != nullptr)
            {
                prev->next = current->next;
            }
            else
            {
                head = current->next;
            }
            delete current;
        }
    }

    void printList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }
};

int main()
{
    LinkedList myList;

    myList.insert(5);
    myList.insert(3);
    myList.insert(8);
    myList.insert(1);
    myList.insert(10);

    std::cout << "Original List: ";
    myList.printList();

    myList.remove(3);
    myList.remove(8);

    std::cout << "List after removal: ";
    myList.printList();

    return 0;
}
