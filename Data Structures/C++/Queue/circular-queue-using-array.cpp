#include <iostream>
using namespace std;
#define MAX 100 //maximum size of the queue array

class Queue
{
private:
        int A[MAX];
        int front, rear;

public:
        //  both front and rear will be -1.
        Queue()
        {
                front = -1;
                rear = -1;
        }

        // To check wheter Queue is empty or not
        bool isEmpty()
        {
                return (front == -1 && rear == -1);
        }

        // To check whether Queue is full or not
        bool isFull()
        {
                return (rear + 1) % MAX == front ? true : false;
        }

        void enqueue(int x)
        {
                cout << "Enqueuing " << x << " \n";
                if (isFull())
                {
                        cout << "Error: Queue is Full\n";
                        return;
                }
                if (isEmpty())
                {
                        front = rear = 0;
                }
                else
                {
                        rear = (rear + 1) % MAX;
                }
                A[rear] = x;
        }

        void dequeue()
        {
                cout << "Dequeuing \n";
                if (isEmpty())
                {
                        cout << "Error: Queue is Empty\n";
                        return;
                }
                else if (front == rear)
                {
                        rear = front = -1;
                }
                else
                {
                        front = (front + 1) % MAX;
                }
        }
        int Front()
        {
                if (front == -1)
                {
                        cout << "Error: cannot return front from empty queue\n";
                        return -1;
                }
                return A[front];
        }

        void traverseQueue()
        {
                int count = (rear + MAX - front) % MAX + 1;
                cout << "Queue       : ";
                for (int i = 0; i < count; i++)
                {
                        int index = (front + i) % MAX;
                        cout << A[index] << " ";
                }
                cout << "\n\n";
        }
};

int main()
{

        Queue Q;
        Q.enqueue(2);
        Q.traverseQueue();
        Q.enqueue(1);
        Q.traverseQueue();
        Q.enqueue(9);
        Q.traverseQueue();
        Q.dequeue();
        Q.traverseQueue();
        Q.enqueue(8);
        Q.traverseQueue();
        Q.dequeue();
        Q.traverseQueue();

        return 0;
}