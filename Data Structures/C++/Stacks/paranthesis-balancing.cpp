#include <iostream>
#include <string>
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
        int topNode();
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

int Node::topNode()
{
        if (!isEmpty())
                return top->data;
        else
                exit(1);
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

        string expr;
        cout << "\nEnter expression : ";
        cin >> expr;
        char x;

        // traversing the Expression
        for (int i = 0; i < expr.length(); i++)
        {
                if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
                {
                        head->push(expr[i]);
                        continue;
                }

                // IF current current character is not opening
                // bracket, then it must be closing. So stack
                // cannot be empty at this point.
                if (head->isEmpty())
                        return false;

                switch (expr[i])
                {
                case ')':

                        x = head->topNode();
                        head->pop();
                        if (x == '{' || x == '[')
                                return false;
                        break;

                case '}':

                        x = head->topNode();
                        head->pop();
                        if (x == '(' || x == '[')
                                return false;
                        break;

                case ']':

                        x = head->topNode();
                        head->pop();
                        if (x == '(' || x == '{')
                                return false;
                        break;
                }
        }

        // Check Empty Stack
        head->isEmpty() ? cout << "\nBalanced expression" : cout << "\nUnbalanced expression";
}
