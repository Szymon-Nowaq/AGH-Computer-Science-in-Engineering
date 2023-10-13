import numpy as np
#from queue import Queue

class Object:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
        self.index = 0
    
    def show(self):
        print('(id: ', self.index, ', val: ', self.data,')', end='', sep='')
    

class TwoWayList:
    def __init__(self):
        self.end = Object(-1)
        self.end.index = -1
        self.head = None
        self.tail = None
        self.count = 0

    def is_empty(self):
        return self.head is None

    def append(self, new_Object: Object):
        new_Object.index = self.count
        self.count += 1
        if self.is_empty():
            self.head = new_Object
            self.tail = new_Object
            self.tail.next = self.end
            self.end.prev = self.tail
        else:
            new_Object.prev = self.tail
            new_Object.next = self.end
            self.tail.next = new_Object
            self.tail = new_Object
            self.end.prev = new_Object

    def prepend(self, new_Object):
        new_Object.index = 0
        self.count += 1
        if self.is_empty():
            self.head = new_Object
            self.tail = new_Object
            self.tail.next = self.end
            self.end.prev = self.tail
        else:
            new_Object.next = self.head
            self.head.prev = new_Object
            self.head = new_Object
            current = self.head.next
            while current != self.end:
                current.index += 1
                current = current.next

    def insert(self, new_Object, index):
        new_Object.index = index
        self.count += 1
        current = self.head
        if self.is_empty():
            self.head = new_Object
            self.tail = new_Object
            self.tail.next = self.end
            self.end.prev = self.tail
        else:
            while current != self.end:
                if current.index == index:
                    current.prev.next = new_Object
                    new_Object.next = current
                    new_Object.prev = current.prev
                    current.prev = new_Object
                    while current != self.end:
                        current.index += 1
                        current = current.next
                    break
                current = current.next


    def show(self):
        if self.is_empty():
            print('empty list')
            return None
        current = self.head
        while current is not None:
            if current.index != 0:
                print(" <-> ", end='')
            current.show()
            current = current.next
        print('\n')
    
    def find_element(self, index):
        current = self.head
        while current != self.end:
            if current.index == index:
                return current
            current = current.next
        print('element not found')
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
    
    def first(self):
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
    
    def get_value_by_id(self, id):
        object = self.find_element(id)
        return object.data
    
    def del_el_after_max(self):
        current = self.head
        max = current.data
        id = 0
        while current != self.end:
            current = current.next
            if max < current.data:
                max = current.data
                id = current.index
        if id == self.count - 1:
            print('max element is the last element')
            return None
        self.delete(id + 1)
        
    
    

list_len = 4
np.random.seed(42)
values = np.random.randint(0,10,list_len)
list = TwoWayList()

for i in range(list_len):
    list.append(Object(values[i]))

#zad 1
list.show()
list.append(Object(1))
list.show()
list.insert(Object(2), 2)
list.show()
list.delete(1)
list.show()
value = list.get_value_by_id(2)
print(value)
list.makenull()
list.show()

#zad 2
for i in range(list_len):
    list.append(Object(values[i]))

list.show()
list.del_el_after_max()
list.show()