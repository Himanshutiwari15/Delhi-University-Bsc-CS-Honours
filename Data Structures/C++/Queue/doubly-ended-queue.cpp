#include <iostream>
using namespace std;

#define MAX 20 // Maximum size of dqArray for Dequeue

class Deque
{
        int dqArray[MAX];
        int front;
        int rear;
        int size;

public:
        Deque(int size)
        {
                front = -1;
                rear = 0;
                this->size = size;
        }

        bool isFull()
        {
                return ((front == 0 && rear == size - 1) || front == rear + 1);
        }

        bool isEmpty()
        {
                return (front == -1);
        }

        void insertFront(int key);
        void insertRear(int key);
        void deleteFront();
        void deleteRear();
        int getFront();
        int getRear();
};

void Deque::insertFront(int key)
{
        if (isFull())
        {
                cout << "Overflow!!\n";
                return;
        }

        // If queue is initially empty,set front=rear=0; start of deque
        if (front == -1)
        {
                front = 0;
                rear = 0;
        }
        else if (front == 0) // front is first position of queue
                front = size - 1;
        else // decrement front 1 position
                front = front - 1;

        dqArray[front] = key; // insert current element into Deque
}

void Deque ::insertRear(int key)
{
        if (isFull())
        {
                cout << " Overflow!!\n " << endl;
                return;
        }

        //  If queue is initially empty,set front=rear=0; start of deque
        if (front == -1)
        {
                front = 0;
                rear = 0;
        }
        else if (rear == size - 1) // rear is at last position of queue
                rear = 0;
        else // increment rear by 1 position
                rear = rear + 1;

        dqArray[rear] = key; // insert current element into Deque
}

void Deque ::deleteFront()
{
        if (isEmpty())
        {
                cout << "Queue Underflow!!\n";
                return;
        }

        // Deque has only one element
        if (front == rear)
        {
                front = -1;
                rear = -1;
        }
        else
            // back to initial position
            if (front == size - 1)
                front = 0;

        else // remove current front value from Deque;increment front by 1
                front = front + 1;
}

void Deque::deleteRear()
{
        if (isEmpty())
        {
                cout << " Underflow!!\n"
                     << endl;
                return;
        }

        // Deque has only one element
        if (front == rear)
        {
                front = -1;
                rear = -1;
        }
        else if (rear == 0)
                rear = size - 1;
        else
                rear = rear - 1;
}

int Deque::getFront()
{
        if (isEmpty())
        {
                cout << " Underflow!!\n"
                     << endl;
                return -1;
        }
        return dqArray[front];
}

int Deque::getRear()
{
        if (isEmpty() || rear < 0)
        {
                cout << " Underflow!!\n"
                     << endl;
                return -1;
        }
        return dqArray[rear];
}

int main()
{
        Deque dq(5);
        cout << "Insert element 1 at rear end \n";
        dq.insertRear(1);

        cout << "insert element 3 at rear end \n";
        dq.insertRear(3);

        cout << "rear element of deque "
             << " " << dq.getRear() << endl;

        dq.deleteRear();
        cout << "After deleteRear, rear = " << dq.getRear() << endl;

        cout << "inserting element 5 at front end \n";
        dq.insertFront(5);

        cout << "front element of deque "
             << " " << dq.getFront() << endl;

        dq.deleteFront();

        cout << "After deleteFront, front = " << dq.getFront() << endl;
        return 0;
}