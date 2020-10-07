class Node:
    # Function to initialise the node object
    def __init__(self, data):
        self.data = data  # Assign data
        self.next = None  # Initialize next as null

class LinkedList:

    # Function to initialize head
    def __init__(self):
        self.size=0
        self.head = None
    # INSERTING IN THE FRONT END
    def insert_front(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node
        self.size+=1
        print(new_data," inserted in the front")
    # INSERTING IN THE REAR END
    def insert_rear(self, new_data):
        self.size+=1
        new_node= Node(new_data)
        if self.head is None:
            self.head = new_node
            return

        last = self.head
        while (last.next):
            last = last.next

        last.next = new_node
        print(new_data, ' inserted in the rear')

    # DELETING FROM THE REAR END
    def delete_rear(self):
        temp=self.head
        if temp==None:
            return None
        if temp.next==None:
            head=None
            return None
        second_last=temp
        while(second_last.next.next):
            second_last=second_last.next
        print(second_last.next.data, ' removed from the rear end')
        second_last.next=None

    # DELETING FROM THE FRONT END
    def delete_front(self):
        temp=self.head
        self.head=self.head.next
        print(temp.data, ' removed from the front')
        temp=None

        return self.head

    # DISPLAY
    def display(self):
        print('The Linked List is ')
        temp = self.head
        while (temp):

            print(temp.data,end=' ')
            temp = temp.next
        print('\n')


l=LinkedList()
print('1 inserted in the list')
l.insert_rear(1)
l.insert_rear(2)
l.insert_front(100)
l.insert_rear(10)
l.display()

l.delete_rear()
l.delete_front()
l.display()
# print('\n',l.size)
