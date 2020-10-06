q=[60,10,20,30,40,50]
item_insert=10
item_delete=50
def enqueue():
    q.append(item_insert)
    print(item_insert, "added to the queue")
def dequeue():
    i=0
    while(i<len(q)):
        if item_delete==q[i]:
            print(q.pop(i), 'deleted from {} position'.format(i+1))
        i+=1
def show():
    print('Queue now is {}'.format(q))


enqueue()
dequeue()
show()