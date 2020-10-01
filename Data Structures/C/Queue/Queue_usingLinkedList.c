#include <stdio.h>
#include <stdlib.h>

// Node Structure
typedef struct Node
{
    int Data;   // Data Part of the Node.
    struct Node *next;    // Pointer to the next Node in the Queue.

}*Node;    // Pointer Variable of the structure Node.

// front and rear of the queue.
Node front = NULL;
Node rear = NULL;

// Function Prototypes.
Node CreateNode();     // To Create Nodes in the Queue
void enqueue(int);    // To push item in the Queue
void dequeue();      // To pop (remove) item from the Queue.
void Display();     // To Display the Queue.
void Exit();       // To exit the program (by freeing the memory)

int main()
{
    int operation = 0, element;

    while(1)
    {
        printf("QUEUE\n");

        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\n:: ");
        scanf("%d", &operation);

        switch(operation)
        {
        case 1:
            printf("\nElement: ");
            scanf("%d", &element);

            enqueue(element);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            Display();
            break;

        case 4:
            Exit();
            break;

        default:
            printf("\nWrong Operation\n");
        }
        printf("\n");
    }

}

// Function Definition.

// Create Node
Node CreateNode()
{
    // Variable node of the type Node i.e a new node.
    Node node;

    // allocating memory to the new node.
    // sizeof(struct Node):- allocate the same size of memory as structure Node have.
    node = (Node)malloc(sizeof(struct Node));

    // checking if node is NULL i.e whether we got memory or not
    if (node == NULL)
    {
        // Displaying the Error and exiting.
        printf ("\nError: Null Pointer Exception\n");
        exit(1);
    }

    // making node point to NULL i.e nothing
    node->next = NULL;

    // returning node;
    return node;
}

// enqueue
void enqueue(int value_toInsert)
{
    // New Node in the Queue.
    Node newNode;

    // CreateNode which would return a newly create node by allocating memory and making in point to NULL.
    newNode = CreateNode();

    // inserting the value in New Node.
    newNode->Data = value_toInsert;

    // checking if front is NULL i.e Queue is empty
    if (front == NULL)
    {
        // Insert the first node in the Queue.
        // both front and rear are pointing to the newly create node.
        front = rear = newNode;
        return;
    }

    // last node in the Queue is pointing to the new node.
    rear->next = newNode;

    // rear pointing to the new node in the Queue.
    rear = newNode;
}

// dequeue
void dequeue()
{
    // Temporary Variable to remove the first element.
    Node temp;

    // checking is Queue is empty.
    if (front == NULL)
    {
        // if Queue is Empty display "Queue Underflow" i.e empty Queue.
        printf("\nQueue Underflow\n");
        return;
    }

    // giving value of front to temp.
    temp = front;

    // incrementing the front i.e making front point to next element in the Queue.
    front = front->next;

    // Displaying the element that we are removing.
    printf ("\nItem Removed: %d\n", temp->Data);

    // deleting the element.
    free(temp);
}

// Display the Queue.
void Display()
{
    // Temporary variable for displaying the elements in the Queue.
    Node temp;

    // Checking is Queue is empty.
    if (front == NULL)
    {
        printf("\nEmpty Queue\n");
        return;
    }

    // initializing temp by giving it the value of front.
    temp = front;

    printf("\nQueue: ");

    // loop until temp is NULL i.e we do not reach the end
    while (temp)
    {
        // display each element in the Queue.
        printf("%d ", temp->Data);

        // move to the next element.
        temp=temp->next;
    }

    printf("\n");
}

// To exit the Program.
void Exit()
{
    Node temp;

    // Checking if top is null i.e whether list is empty or not.
    // if empty exit safely.
    if (front == NULL)
        exit(0);

    // if stack is not empty first delete each node, free memory and exit program.
    while ((temp = front) != NULL)   // Setting temp to the top and stopping if list is empty
    {
        front = front->next;  // advancing to the next node (element)
        free(temp); // deleting the saved pointer
    }

    exit(0);    // exiting program.
}





