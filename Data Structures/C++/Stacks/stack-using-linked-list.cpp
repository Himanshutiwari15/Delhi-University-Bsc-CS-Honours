#include <iostream>

using namespace std;

class Node
{
        int data;
        Node *next;

public:
        int menu()
        {
                int ch;
                cout << "\nStack";
                cout << "\n1.Push\n2.Pop\n3.Top element\n4.Is Empty\n5.Display Stack\n6.Exit";
                cout << "\nEnter your Choice:";
                cin >> ch;
                return ch;
        }

        int isEmpty();
        void push(int);
        void pop();
        void topNode();
        void display();

} * top;

int Node::isEmpty()
{
        return top == NULL;
}

void Node::push(int data)
{

        struct Node *temp;
        temp = new Node();

        if (!temp)
        {
                cout << "\nHeap Overflow";
                exit(1);
        }

        temp->data = data;
        temp->next = top;
        top = temp;
}

void Node::topNode()
{
        if (!isEmpty())
        {
                cout << "\nElement of the top node is : " << top->data << " \n";
        }

        else
        {
                cout << "\nStack Underflow" << endl;
        }
}

void Node::pop()
{
        struct Node *temp;
        if (isEmpty())
        {
                cout << "\nStack Underflow" << endl;
                exit(1);
        }
        else
        {
                temp = top;
                top = top->next;
                temp->next = NULL;
                free(temp);
        }
}

void Node::display()
{
        struct Node *temp;
        if (isEmpty())
        {
                cout << "\nStack Underflow";
                exit(1);
        }
        else
        {
                temp = top;
                while (temp != NULL)
                {
                        cout << temp->data << "-> ";
                        temp = temp->next;
                }
        }
}

int main()
{

        Node *head;

        head = NULL;
        int choice;

        do
        {
                choice = head->menu();

                switch (choice)
                {
                case 1:
                        int data;
                        cout << "Enter value to be stored in stack: ";
                        cin >> data;
                        head->push(data);
                        break;
                case 2:
                        head->pop();
                        break;
                case 3:
                        head->topNode();
                        break;
                case 4:
                        cout << "The stack is ";
                        head->isEmpty() ? cout << "empty" : cout << "not empty";
                        break;
                case 5:
                        head->display();
                        break;
                case 6:
                        break;

                default:
                        cout << "\nEnter a valid choice!!\n";
                }
        } while (choice != 6);

        return 0;
}
