#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining a structure as Node with 2 elements 'data' and 'next';
typedef struct Node
{
    // First part of the Node i.e stores the data (elements)
    int data;

    //Second part of the Node i.e pointer to the next Node in the List. It stores the address of next Node.
    struct Node *next;  // It is a Self Referencial pointer;
}*Node;

// Creating a Head of the List that points to the first element in the List;
// Head helps in transversing Linked List.
Node head = NULL;  // Created head and assigned it to NULL.

// Functions.
Node CreateNode();  // To create nodes.
void AddNode_Start(int);  // To add new nodes to the list.
void AddNode_End(int);    // To add new nodes at the end of the list.
bool Delete(int);    // To delete a node from the list.
bool Search(int);   // To Search for a element in the List.
void Display();    // To Display the List.
void Free();    // To free the memory at the end.

int main()
{
    // Variable to take input from user for the elements that we need to store in Linked List
    // Variable to Search in the List.
    int Elements = 0, element_toSearch = 0, i;

    printf ("|-----------LINKED LIST----------|\n");

    for (i = 0; i < 5; i++)    // Loop to store 5 elements in the List.
    {
        printf("\nData (Element): ");
        scanf("%d", &Elements);

        AddNode_End(Elements);    // Calling AddNode to add the element into the List.
    }

    printf ("\nElements: ");
    Display();  // Display the List.

    /*
    printf ("\nElement to Search: ");
    scanf ("%d", &element_toSearch);

    if (Search(element_toSearch))
        printf("\nElement Found \n");
    else
        printf ("\nElement Not Found\n");
    */
    printf ("\nElement to Delete: ");
    scanf ("%d", &element_toSearch);

    if (Delete(element_toSearch))
        printf("\nElement Deleted \n");
    else
        printf ("\nElement Not in List\n");

    printf ("\nElements: ");
    Display();  // Display the List.

    Free();    // Free Memory at the end.
}

Node CreateNode()
{
    Node temp;  // Declaring a Node temp

    temp = (Node)malloc(sizeof(struct Node));   // Allocating Memory to the Node temp.

    // Checking if temp is NULL.
    if (temp == NULL)
    {
        // Print Error and exit if its Null;
        printf("\nError: Null Pointer Exception\n");
        exit(1);
    }

    temp->next = NULL;  // Making temp's next part point to NULL.

    return temp;    // returning the newly created Node.

}

// Add new Node at the Beginning of the List.
void AddNode_Start(int value)
{
    Node temp;   // Declaring a Nodes;

    temp = CreateNode();    // Calling CreateNode() function to allocate a new Node in the Memory. temp will store the newly created node.

    temp->data = value;    // inserting the value into the data part of the Node.

    if (head == NULL)   // checking if head if NULL i.e list is empty.
        head = temp;    // if list is empty then making head point to the newly created Node.
    else    // if head is not NULL i.e list is not empty then.
    {
        temp->next = head;  // first make newly created node point to the node that head is pointing to.
        head = temp;    // make head point to the newly created Node.
    }

}

// Add new Node at the End of the List.
void AddNode_End(int value)
{
    Node temp, end;   // Declaring two Nodes;

    temp = CreateNode();    // Calling CreateNode() function to allocate a new Node in the Memory. temp will store the newly created node.

    temp->data = value;    // inserting the value into the data part of the Node.

    if (head == NULL)   // checking if head if NULL i.e list is empty.
    {
        head = temp;    // if list is empty then making head point to the newly created Node.
    }
    else    // if head is not NULL i.e list is not empty then.
    {
        end = head;   // starting for the beginning of the List.

        while (end->next != NULL)   // Step till the end of the list
            end = end->next;    // move from one node to another till we are at the end node.

        end->next = temp;  // make end Node point to newly created Node.
    }

}

bool Search(int element_to_search)
{
    Node temp = head;  // Declaring a temporary variable to transverse the List and assigning it to the starting of the list.

    while (temp->next != NULL)  // Going to each Node until List is empty i.e till end.
    {
        if (temp->data == element_to_search)    // Checking if data part of a Node is same as the item that we are looking for
            return true;    // if yes, then return true
        temp = temp->next;    // otherwise, move to the next Node.
    }
    return false;   // return false if item not found in the List.
}

bool Delete (int value_toDelete)
{
    Node prev, current;
    current = prev = head;

    while (current != NULL)
    {
        if (current->data == value_toDelete)
        {
            if (current == head)
            {
                head = head->next;
                free(current);
                return true;
            }
            prev->next = current->next;
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

void Display()
{
    // Checking if head is null i.e whether list is empty or not.
    // if empty print error message and exit.
    if (head == NULL)
    {
        printf ("\nERROR: Empty List\n");
        exit(1);
    }
    Node temp = head;   // Creating a temporary variable and giving it the address of head.
    while (temp != NULL)  // transversing till the end of the list.
    {
        printf("%d ", temp->data);  // printing out the elements in each of the Nodes.
        temp = temp->next;    // Going from one node to another.
    }
    printf("\n");   // New Line.
}

void Free()
{
    Node temp;

    // Checking if head is null i.e whether list is empty or not.
    // if empty print error message and exit.
    if (head == NULL)
    {
        printf ("\nERROR: Empty List\n");
        exit(1);
    }

    while ((temp = head) != NULL)   // Setting temp to the head and stopping if list is empty
    {
        head = head->next;  // advancing to the next node (element)
        free(temp); // deleting the saved pointer
    }
}
