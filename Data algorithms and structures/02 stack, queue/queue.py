import numpy as np

class Object:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
        self.index = 0
    
    def show(self):
        print('(id: ', self.index, ', val: ', self.data,')', end='', sep='')
    

class Queue:
    def __init__(self):
        self.end = Object(-1)
        self.end.index = -1
        self.head = None
        self.tail = None
        self.count = 0

    def empty(self):
        return self.head is None

    def enqueue(self, new_Object : Object()):
        new_Object.index = self.count
        self.count += 1
        if self.empty():
            self.head = new_Object
            self.tail = new_Object
            self.tail.next = self.end
            self.end.prev = self.tail
        else:
            new_Object.prev = self.tail
            new_Object.next = self.end
            self.tail.next = new_Object
            self.tail = new_Object
            self.end.prev = self.tail

    def show(self):
        if self.empty():
            print('empty list')
            return None
        current = self.head
        while current is not None:
            if current.index != 0:
                print(" <-> ", end='')
            current.show()
            current = current.next
        print("\n")
    
    def find_element(self, index):
        half = self.count / 2
        if index <= half:
            current = self.head
            while current.index != index:
                current = current.next
        else:
            current = self.tail
            while current.index != index:
                current = current.prev
        return current
    
    #aktualizacja
    def End(self):
        return self.end
    
    def next(self, id):
        obj = self.find_element(id)
        return obj.next
    
    def previous(self, id):
        obj = self.find_element(id)
        return obj.prev
    
    def front(self):
        return self.head
    
    def locate(self, object: Object):
        current = self.head
        while current != self.end:
            if current.data == object.data:
                return current
            current = current.next
        return self.End()
    
    def retrieve(self, index):
        half = self.count / 2
        if index <= half:
            current = self.head
            while current.index != index:
                current = current.next
            current.show()
        else:
            current = self.tail
            while current.index != index:
                current = current.prev
            current.show()
    
    def dequeue(self):
        to_delete = self.head
        current = to_delete.next
        self.head = current
        while current != self.end:
            current.index -= 1
            current = current.next
        del to_delete
        self.count -= 1
        return None
    
    def makenull(self):
        current = self.head
        while current != self.end: 
            current = current.next
            to_delete = current.prev
            del to_delete
        self.head = None
        self.tail.prev = None
        self.tail.next = self.end
        self.end.prev = None
        self.count = 0
        return self.end
    
    
def zad3(list):
    que = Queue()
    for i in range(len(list)):
        if i % 3 == 0:
            que.enqueue(Object(list[i]))
    return que
    

list_len = 12
np.random.seed(42)
values = np.random.randint(0,10,list_len)

print(values)

que = zad3(values)
que.show()

