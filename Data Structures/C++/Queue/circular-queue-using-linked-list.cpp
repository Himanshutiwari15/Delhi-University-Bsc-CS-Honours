#include <iostream>

#define SIZE 100

using namespace std;

class Node
{
public:
        int data;
        Node *next;
        Node()
        {
                next = NULL;
        }

} *front = NULL, *rear = NULL;

class CircularQueue
{
public:
        void enqueue();
        void dequeue();
        void display();
};

int main()
{
        CircularQueue cQueue;
        int ch;
        do
        {
                cout << "\n-------------------------";
                cout << "\n\tMain Menu";
                cout << "\n-------------------------";

                cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit\n\nEnter Your Choice: ";
                cin >> ch;
                switch (ch)
                {
                case 1:
                        cQueue.enqueue();
                        cQueue.display();
                        break;
                case 2:
                        cQueue.dequeue();
                        break;
                case 3:
                        cQueue.display();
                        break;
                case 4:
                        break;
                default:
                        cout << "\n\n!!INVALID CHOICE!!";
                }
        } while (ch != 4);
        return 0;
}

void CircularQueue::enqueue()
{
        Node *n = new Node();
        cout << "\nEnter the element: ";
        cin >> n->data;
        if (front == NULL)
        {
                front = n;
        }
        else
        {
                rear->next = n;
        }
        rear = n;
        rear->next = front;
}

void CircularQueue::dequeue()
{
        int x;
        Node *temp = front;
        if (front == NULL)
        {
                cout << "\nCircular Queue empty!";
        }
        else
        {
                if (front == rear)
                {
                        x = front->data;
                        delete (temp);
                        front = NULL;
                        rear = NULL;
                }
                else
                {
                        x = temp->data;
                        front = front->next;
                        rear->next = front;
                        delete (temp);
                }
                cout << "\nElement " << x << " is deleted";
                display();
        }
}

void CircularQueue::display()
{
        Node *temp = front;
        Node *tempCopy = NULL;
        if (front == NULL)
        {
                cout << "\n\nCircular Queue Empty!";
        }
        else
        {
                cout << "\n\nCircular Queue elements are:\n\n";
                while (temp != tempCopy)
                {
                        cout << temp->data << "  ";
                        temp = temp->next;
                        tempCopy = front;
                }
        }
}