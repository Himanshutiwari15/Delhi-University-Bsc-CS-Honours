#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
        int data;
        Node *next;

public:
        void push(int);
        void insertAfter(Node *, int);
        void insertBefore(Node *, Node *, int);
        void append(int);
        void printList();
        void headDeletion();
        void tailDeletion();
        void deleteParticularNode(int);
        void recursiveTraversal(Node *);
        void recursiveSearch(Node *, int, int);
};
Node *head = NULL;

void Node::push(int newData)
{
        Node *ptr;
        ptr = new Node();
        ptr->data = newData;
        ptr->next = head;

        head = ptr;
}

void Node::insertAfter(Node *prevNode, int newData)
{
        if (prevNode == NULL)
        {
                cout << "Not a valid linked list to insertAfter a node";
                return;
        }

        Node *new_node = new Node();
        new_node->data = newData;

        new_node->next = prevNode->next;

        prevNode->next = new_node;
}

void Node::insertBefore(Node *head, Node *afterNode, int newData)
{
        if (afterNode == NULL || head == NULL)
        {
                cout << "Not a valid linked list to insertBefore a node";
                return;
        }
        Node *newNode = new Node();
        newNode->data = newData;
        Node *tempNode = head;

        while (tempNode != NULL)
        {
                if (tempNode->next->data == afterNode->data)
                {
                        tempNode->next = newNode;
                        newNode->next = afterNode;
                        return;
                }
                tempNode = tempNode->next;
        }
}

void Node::append(int newData)
{
        Node *new_node = new Node();
        Node *last = head;
        new_node->data = newData;
        new_node->next = NULL;

        if (head == NULL)
        {
                head = new_node;
                return;
        }

        while (last->next != NULL)
                last = last->next;

        last->next = new_node;
        return;
}

void Node::recursiveSearch(Node *head, int newData, int index = 0)
{
        Node *temp = new Node();
        temp = head;
        if (temp == NULL)
        {
                cout << "\nRequired node not found || linked list is empty !!";
                return;
        }
        if (temp->data == newData)
        {
                cout << "\nRequired Node is in the list at ( 0 based ) index " << index;
                return;
        }
        index++;
        recursiveSearch(head->next, newData, index++);
}

void Node::headDeletion()
{
        if (head == NULL)
        {
                cout << "Empty linked list !!";
                return;
        }
        Node *temp = head;
        head = head->next;
        free(temp);
}

void Node::tailDeletion()
{
        if (head == NULL)
        {
                cout << "Empty linked list !!";
                return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
                temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
}

void Node::deleteParticularNode(int dataToLookFor)
{
        Node *temp = new Node();
        temp = head;
        while (temp->next->data != dataToLookFor)
        {
                temp = temp->next;
        }
        Node *nodeToBeDeleted = new Node();
        nodeToBeDeleted = temp->next;
        temp->next = nodeToBeDeleted->next;
        free(nodeToBeDeleted);
}

void Node::printList()
{
        Node *temp = new Node();
        temp = head;
        while (temp != NULL)
        {
                cout << "\n " << temp->data;
                temp = temp->next;
        }
}

void Node::recursiveTraversal(Node *head)
{
        if (head == NULL)
        {
                return;
        }

        cout << head->data << "\n";
        recursiveTraversal(head->next);
}

int main()
{
        head->push(5);
        head->push(8);
        head->push(2);
        head->push(9);

        cout << "Linked list : \n";
        // head->printList();
        head->recursiveTraversal(head);

        head->append(6);
        head->append(4);

        cout << "\nLinked list after appending nodes with data 6 and 4: ";
        head->printList();

        head->insertAfter(head->next, 1);
        head->insertBefore(head, head->next->next, 0);

        cout << "\nLinked list after insertAfter,"
             << "insertBefore and append: ";
        head->printList();

        cout << "\nSearching 9 in linked list recursively:";
        head->recursiveSearch(head, 0);

        head->deleteParticularNode(5);
        cout << "\n----------------------------------------------------";
        cout << "\n\nAfter Deleting a particular node with data=5:";
        head->printList();

        head->headDeletion();

        cout << "\nAfter deleting from head of list:";
        head->printList();

        head->tailDeletion();

        cout << "\nAfter deleting from tail of list:";
        head->printList();

        return 0;
}
