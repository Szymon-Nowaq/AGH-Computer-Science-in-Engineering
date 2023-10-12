import numpy as np

class Object:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
        self.index = 0
    
    def show(self):
        print('(id: ', self.index, ', val: ', self.data,')', end='', sep='')
    

class Stack:
    def __init__(self):
        self.end = Object(-1)
        self.end.index = -1
        self.top = None
        self.count = 0

    def empty(self):
        return self.top is None

    def push(self, new_Object: Object):
        new_Object.index = self.count
        self.count += 1
        if self.empty():
            self.top = new_Object
            self.end.next = self.top
            self.top.prev = self.end
        else:
            new_Object.prev = self.top
            self.top.next = new_Object
            self.top = new_Object

    def pop(self):
        to_delete = self.top
        self.top = self.top.prev
        self.top.next = None
        del to_delete
        self.count -= 1
        

    def show(self):
        if self.empty():
            print('empty list')
            return None
        current = self.top
        while current is not None:
            if current.index != self.count - 1:
                print(" <-> ", end='')
            current.show()
            current = current.prev
        print('\n')
    
    def find_element(self, index):
        current = self.top
        while current != self.end:
            if index == current.index:
                return current    
            current = current.prev
        print('wrong index')
        return None
    
    def Top(self):
        return self.end
    
    def next(self, id):
        obj = self.find_element(id)
        return obj.next
    
    def previous(self, id):
        obj = self.find_element(id)
        return obj.prev
    
    def Top(self):
        return self.top
    
    def locate(self, object: Object):
        current = self.top
        while current != self.end:
            if current.data == object.data:
                return current
            current = current.prev
        return self.end
    
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
    
    def delete(self, index):
        to_delete = self.find_element(index)
        if 0 < index and index < self.tail.index:
            to_delete.prev.next = to_delete.next
            to_delete.next.prev = to_delete.prev 
        elif index == 0:
            self.head = self.head.next
            self.head.prev = None
        elif index == self.tail.index:
            self.tail = self.tail.prev
            self.tail.next = self.end
            self.end.prev = self.tail
        else:
            print('wrong index')
            return None
        current = to_delete.next
        while current != self.end:
            current.index -= 1
            current = current.next
        del to_delete
        self.count -= 1
        return None
    
    def makenull(self):
        current = self.top
        while current != self.end: 
            current = current.prev
            to_delete = current.next
            del to_delete
        self.top = None
        self.end.next = None
        self.count = 0
        return self.end
    


list_len = 2
np.random.seed(42)
values = np.random.randint(0,10,list_len)
list = Stack()

for i in range(list_len):
    list.push(Object(values[i]))

list.show()

list.push(Object(10))
list.show()

list.pop()
list.show()