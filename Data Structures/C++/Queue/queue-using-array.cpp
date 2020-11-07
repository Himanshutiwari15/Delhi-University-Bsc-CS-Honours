#include <iostream>
#define MAX 100

using namespace std;

class Queue
{
public:
        int front, rear;
        int queue_array[MAX];
        bool isEmpty()
        {
                return front == -1;
        }
        bool isFull()
        {
                return front == MAX - 1;
        }

public:
        Queue()
        {
                front = -1;
                rear = -1;
        }
        void display()
        {
                cout << "\n";
                if (!isEmpty())
                {
                        for (int i = rear; i <= front; i++)
                                cout << queue_array[i] << " ";
                        cout << endl;
                }
                else
                        cout << "\nQueue is Empty!" << endl;
        }

        void enqueue(int x)
        {
                if (!isFull())
                {
                        queue_array[++front] = x;
                        if (rear == -1)
                                rear = 0;
                        cout << "\nenqueue " << x << ":";
                        display();
                }
                else
                        cout << "Queue is Full!" << endl;
        }

        void dequeue()
        {
                if (!isEmpty())
                {
                        if (rear == front)
                                rear = front = -1;
                        else
                        {
                                rear++;
                                cout << "\ndequeue " << rear << ":";
                                display();
                        }
                }
                else
                        cout << "Queue is Empty!" << endl;
        }
        int Front()
        {
                if (front == -1)
                {
                        cout << "Error: cannot return front from empty queue\n";
                        return -1;
                }
                return queue_array[front];
        }
};

int main()
{
        Queue q;
        q.enqueue(15);

        q.enqueue(25);

        q.enqueue(35);

        q.enqueue(45);

        q.enqueue(55);

        q.enqueue(55);
        q.dequeue();

        q.dequeue();

        q.dequeue();

        q.dequeue();

        q.dequeue();

        q.dequeue();
}