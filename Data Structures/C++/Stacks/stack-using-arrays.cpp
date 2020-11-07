#include <iostream>
#define MAX 10

using namespace std;

class Stack
{
        int tos;
        int stack_array[MAX];
        bool isEmpty()
        {
                return tos == -1;
        }
        bool isFull()
        {
                return tos == MAX - 1;
        }

public:
        Stack()
        {
                tos = -1;
        }

        void display()
        {
                if (!isEmpty())
                {
                        for (int i = 0; i <= tos; i++)
                                cout << stack_array[i] << " ";
                        cout << endl;
                }
                else
                        cout << "Stack is Empty!" << endl;
        }

        void push(int x)
        {
                if (!isFull())
                {
                        stack_array[++tos] = x;
                        cout << "\nStack after pushing " << x << " :";
                        display();
                }
                else
                        cout << "\nStack is Full!" << endl;
        }

        void pop()
        {
                if (!isEmpty())
                {
                        cout << "\nElement popped from the stack " << stack_array[tos];
                        tos--;
                }
                else
                        cout << "Stack is Empty!" << endl;
        }

        void find(int x)
        {
                int flag = 0;
                if (!isEmpty())
                {
                        for (int i = 0; i <= tos; i++)
                        {
                                if (stack_array[i] == x)
                                {
                                        cout << "\nFound at position: " << i << "\n";
                                        flag = 1;
                                        break;
                                }
                        }
                        if (flag == 0)
                                cout << "\nNumber " << x << " not found!"
                                     << "\n";
                }
                else
                        cout << "Stack is Empty!" << endl;
        }
};

int main()
{
        Stack s;
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        s.find(0);
        s.find(6);
        s.pop();
        s.display();
        s.pop();
        s.display();
}