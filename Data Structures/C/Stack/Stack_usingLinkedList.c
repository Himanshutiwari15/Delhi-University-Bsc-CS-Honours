#include <stdio.h>
#include <stdlib.h>

// Structure of Node.
typedef struct Node
{
    int data;   // First part:- To Store the Data
    struct Node *next;    // Second part:- pointer to the next node.
}*Stack;    // giving this node a name i.e Stack.

// top i.e top of the stack.
// Initial it's null i.e stack is empty.
Stack top = NULL;

// Functions.
void push(int);    // To push item into the stack.
void pop();    // To pop item from the stack.
void Display();    // To Display the items in the Stack.
void Exit();    // To "Safely" Exit the program

// Main Function.
int main(void)
{
    // element_toPush:- to take input from user for pushing item into stack.
    // choice:- to take choice from user i.e either push, pop, display or close the program.
    int element_toPush = 0, choice = 0;

    while (1)   // infinity loop i.e keep running until we close it.
    {
        printf ("|~~~~~~~~~~~~STACK~~~~~~~~~~|\n");

        // Options available within stack.
        printf ("\n1. Push");
        printf ("\n2. Pop");
        printf ("\n3. Display");
        printf ("\n4. Exit");

        printf ("\n:: ");
        scanf ("%d", &choice);    // Taking Choice from the user

        // switch to run one case that user wants.
        switch (choice)
        {
        case 1:
            // Push Value into the Stack.
            printf ("\nValue to Push: ");
            scanf ("%d", &element_toPush);    // Taking Input from the User

            push(element_toPush);    // Calling Push Function.
            break;

        case 2:
            // Pop i.e delete element from the Stack.
            pop();  // calling pop() function.
            break;

        case 3:
            // Display Value in the Stack.
            Display();  // Calling Display() function.
            break;

        case 4:
            // Exit the Program.
            Exit();
            break;

        default:    printf ("\nerror: wrong input. TRY AGAIN\n");
        }
        printf("\n");
    }
}

// PUSH function to insert value into the stack.
void push(int value_toInsert)
{
    Stack new_Node, temp;   // Declaring two nodes.

    new_Node = (Stack)malloc(sizeof(struct Node));    // Allocating memory to the new_Node.

    // Checking whether malloc have given us memory or nor
    if (new_Node == NULL)
    {
        printf ("\nERROR: Null Pointer Exception\n");   // Printing error and exiting i.e closing program if we didn't get memory.
        exit(1);
    }

    new_Node->data = value_toInsert;    // inserting value
    new_Node->next = NULL;    // making new_Node point to NULL (NOTHING).

    if (top == NULL)
    {
        top = new_Node;
        return;    // if stack is empty, make top points towards the new_Node
    }

    new_Node->next = top;
    top = new_Node;
}

void pop()
{
    Stack currentNode, previousNode;    // 2 Variable Nodes.

    if (top == NULL)
    {
        printf ("\nERROR: Stack Underflow\n");
        exit(1);
    }

    currentNode = previousNode = top;

    // Loop to get to the last node or last element in the stack.
    while (currentNode->next != NULL)
    {
        previousNode = currentNode;    // making previousNode points what currentNode is pointing at
        currentNode = currentNode->next;    // moving currentNode to the next Node;
    }

    printf("\nElement Removed: %d\n", currentNode->data);   // Displaying the item

    if (currentNode == top)    // checking if the item we are removing is at beginning
    {
        free(currentNode);    // delete the currentNode;
        top = NULL;    // make top again NULL;
    }
    else
    {
        free(currentNode);    // delete currentNode;
        previousNode->next = NULL;    // make previousNode point NULL;
    }
}

void Display()
{
    // Checking if head is null i.e whether list is empty or not.
    // if empty print error message and exit.
    if (top == NULL)
    {
        printf ("\nStack Underflow\n");
        exit(1);
    }
    Stack temp = top;   // Creating a temporary variable and giving it the address of head.
    printf("\n  Stack  \nTOP: ");
    while (temp != NULL)  // transversing till the end of the list.
    {
        printf("%d \n", temp->data);  // printing out the elements in each of the Nodes.
        temp = temp->next;    // Going from one node to another.
    }
    printf("\n");   // New Line.
}

// To Exit Program
void Exit()
{
    Stack temp;

    // Checking if top is null i.e whether list is empty or not.
    // if empty exit safely.
    if (top == NULL)
        exit(0);

    // if stack is not empty first delete each node, free memory and exit program.
    while ((temp = top) != NULL)   // Setting temp to the top and stopping if list is empty
    {
        top = top->next;  // advancing to the next node (element)
        free(temp); // deleting the saved pointer
    }

    exit(0);    // exiting program.
}




