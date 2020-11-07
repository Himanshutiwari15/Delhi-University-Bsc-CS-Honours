#include <iostream>

using namespace std;

void menu()
{
    cout << "\n-------- MENU ---------" << endl
         << "1. Insert at Front" << endl
         << "2. Insert at Back" << endl
         << "3. Delete a node with particular index" << endl
         << "4. Delete from front" << endl
         << "5. Delete from Back" << endl
         << "6. Display" << endl
         << "7. Total Nodes" << endl
         << "8. Search" << endl
         << "9. Insert before a node" << endl
         << "10. Insert after a node" << endl
         << "11. Exit" << endl;
}

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int);
};

Node::Node(int value) //!Constructor
{
    data = value;
    next = prev = NULL;
}

class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void push(DoublyLinkedList *, int);
    void insert_front(int);
    void insert_back(int);
    void insert_after(DoublyLinkedList *, int, int);
    void insert_before(DoublyLinkedList *, int, int);
    void delete_Node(Node *, Node *);
    int delete_front();
    int delete_back();
    void deleteNodeAtGivenPos(DoublyLinkedList *, int);
    bool is_empty();
    void display();
    int length();
    void search(int);

private:
    Node *head;
    Node *tail;
    int size;
};

DoublyLinkedList::DoublyLinkedList()
{
    head = tail = NULL;
    size = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
}

void DoublyLinkedList::push(DoublyLinkedList *head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = head_ref->head;
    new_node->prev = NULL;

    if (head_ref->head != NULL)
        head_ref->head->prev = new_node;

    head_ref->head = new_node;
    size++;
}

void DoublyLinkedList::insert_front(int value)
{
    Node *temp = new Node(value);

    if (head == NULL)
        head = tail = temp;
    else
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    size++;
}

void DoublyLinkedList::insert_back(int value)
{
    Node *temp = new Node(value);

    if (tail == NULL)
        head = tail = temp;
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    size++;
}

void DoublyLinkedList::insert_after(DoublyLinkedList *head_ref, int index, int value)
{
    Node *current = head_ref->head;
    for (int i = 0; current != NULL && i < index; i++)
        current = current->next;

    Node *prev_node = current;
    if (prev_node == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    Node *new_node = new Node(value);

    new_node->next = prev_node->next;

    prev_node->next = new_node;

    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
    size++;
}

void DoublyLinkedList::insert_before(DoublyLinkedList *head_ref, int index, int value)
{
    Node *current = head_ref->head;
    for (int i = 0; current != NULL && i < index; i++)
        current = current->next;

    Node *next_node = current;

    if (next_node == NULL)
    {
        cout << "the given next node cannot be NULL";
        return;
    }
    Node *new_node = new Node(value);

    new_node->prev = next_node->prev;

    next_node->prev = new_node;

    new_node->next = next_node;

    if (new_node->prev != NULL)
        new_node->prev->next = new_node;
    else
        head_ref->head = new_node;
    size++;
}

void DoublyLinkedList::delete_Node(Node *head_ref, Node *del)
{
    if (head_ref == NULL || del == NULL)
        return;

    if (head_ref == del)
        head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    size--;
}

int DoublyLinkedList::delete_front()
{
    if (!is_empty())
    {
        Node *temp = head;
        if (head == tail)
        {
            tail = NULL;
        }
        int delValue = temp->data;
        head = head->next;

        delete temp;

        size--;

        return delValue;
    }
    return 0;
}

int DoublyLinkedList::delete_back()
{
    if (!is_empty())
    {
        Node *temp = tail;
        if (head == tail)
        {
            head = NULL;
        }
        int delValue = temp->data;
        tail = tail->prev;
        tail->next = NULL;

        delete temp;

        size--;

        return delValue;
    }
    return 0;
}

void DoublyLinkedList::deleteNodeAtGivenPos(DoublyLinkedList *head_ref, int n)
{
    if (head_ref->head == NULL || n <= 0)
        return;

    Node *current = head_ref->head;
    int i;

    for (int i = 0; current != NULL && i < n; i++)
        current = current->next;

    if (current == NULL)
        return;

    // delete the node pointed to by 'current'
    delete_Node(head_ref->head, current);
}

bool DoublyLinkedList::is_empty()
{
    if (size <= 0)
    {
        return true;
    }

    return false;
}

void DoublyLinkedList::display()
{
    Node *temp = head;

    cout << "\n\nDisplay in forward order\n";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << " NULL";
}

int DoublyLinkedList::length()
{
    return size;
}

void DoublyLinkedList::search(int value)
{
    if (!is_empty())
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == value)
            {
                cout << "YES! got it." << endl;
                break;
            }
            temp = temp->next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
}

int main()
{
    DoublyLinkedList *dll = new DoublyLinkedList();
    int choice, nn;

    do
    {
        menu();
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Enter data: ";
            cin >> nn;
            dll->push(dll, nn);
            break;

        case 1:
            cout << "Enter data: ";
            cin >> nn;
            dll->insert_front(nn);
            break;

        case 2:
            cout << "Enter data: ";
            cin >> nn;
            dll->insert_back(nn);
            break;

        case 3:
            cout << "Enter the index of the node :";
            cin >> nn;
            dll->deleteNodeAtGivenPos(dll, nn);

        case 4:
            cout << "Deleted value is: " << dll->delete_front();
            break;

        case 5:
            cout << "Deleted value is: " << dll->delete_back();
            break;

        case 6:
            dll->display();
            break;

        case 7:
            cout << "Total Nodes = " << dll->length();
            break;

        case 8:
            int searchVal;
            cout << "Enter search data: ";
            cin >> searchVal;
            dll->search(searchVal);
            break;

        case 9:
            int index;
            cout << "Enter data:";
            cin >> nn;
            cout << "Index of the node before which new node has to be inserted:";
            cin >> index;
            dll->insert_before(dll, index, nn);
            break;

        case 10:
            cout << "Enter data:";
            cin >> nn;
            cout << "Index of the node before which new node has to be inserted:";
            cin >> index;
            dll->insert_after(dll, index, nn);
            break;

        default:
            cout
                << "Sorry Wrong choice" << endl;
            break;
        }
    } while (choice !=11);

    return 0;
}