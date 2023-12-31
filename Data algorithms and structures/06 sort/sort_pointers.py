import numpy as np

class Object:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
        self.index = 0
    
    def show(self):
        print(self.data, '-> ', end='')

class TwoWayList:
    def __init__(self):
        self.head = Object(None)
        self.tail = Object(None)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.count = 0

    def is_empty(self):
        return self.head.next.data == None

    def append(self, data):
        new_Object = Object(data)
        self.count += 1
        new_Object.index = self.count    
        if self.is_empty():
            self.head.next = new_Object
            new_Object.prev = self.head
        else:
            current_last = self.tail.prev
            current_last.next = new_Object
            new_Object.prev = current_last
        new_Object.next = self.tail
        self.tail.prev = new_Object


    def prepend(self, data):
        new_Object = Object(data)
        new_Object.index = 1
        self.count += 1
        if self.is_empty():
            self.head = new_Object
            self.tail = new_Object
        else:
            new_Object.next = self.head
            self.head.prev = new_Object
            self.head = new_Object
            current = self.head.next
            while current:
                current.index += 1
                current = current.next

    def insert(self, data, index):
        new_Object = Object(data)
        new_Object.index = index
        self.count += 1
        current = self.head
        while current:
            if current.index == index:
                current.prev.next = new_Object
                new_Object.next = current
                new_Object.prev = current.prev
                current.prev = new_Object
                while current:
                    current.index += 1
                    current = current.next
                break
            current = current.next

    def insert_sorted(self, data):
        new_Object = Object(data)
        self.count += 1
        if self.head == None:
            self.head = new_Object
        else:
            current = self.head
            while current.next and current.next.data < data:
                current = current.next
            temp = current.next
            current.next = new_Object
            new_Object.next = temp
            new_Object.prev = current

    def show(self):
        current = self.head
        while current != self.tail:
            current.show()
            #print(current.index, end=None)
            current = current.next
        print("End of the list\n")
    
    def show_by_index(self, index):
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
    
    def find_element(self, index):
        current = self.head.next
        while current.index != index:
            current = current.next
        return current
            
    def delete_by_index(self, index):
        to_delete = self.find_element(index)
        if 0 < index and index < self.tail.index:
            to_delete.prev.next = to_delete.next
            to_delete.next.prev = to_delete.prev 
        elif index == 0:
            self.head = self.head.next
            self.head.prev = None
        elif index == self.tail.index:
            self.tail = self.tail.prev
            self.tail.next = None
        else:
            print('wrong index')
            return None
        current = to_delete.next
        while current:
            current.index -= 1
            current = current.next
        self.count -= 1
        return None
    
    def sort_bubble(self):
        ite = 0
        last_swap = 0
        last_swapG = self.count - 1
        for i in range(self.count - 1):
            current = self.head.next
            last_swap = 0
            for j in range(last_swapG):
                if current.data > current.next.data:
                    last_swap = j
                    temp = current.data
                    current.data = current.next.data
                    current.next.data = temp 
                ite += 1
                current = current.next
            if last_swap != 0:
                last_swapG = last_swap
            else:
                break
    
    def sort_insert(self):
        count = self.count + 1
        for i in range(2, count):
            to_insert = self.find_element(i)
            to_compare = self.find_element(i - 1)
            to_insert.prev.next = to_insert.next
            to_insert.next.prev = to_insert.prev
            current = to_insert.next
            while current:
                    current.index -= 1
                    current = current.next
            while to_compare != self.head and to_insert.data < to_compare.data:
                to_compare = to_compare.prev
            #print(to_insert.data, to_compare.next.index)
            self.insert(to_insert.data, to_compare.next.index)
            #self.show()
        
    
list_bubble = TwoWayList()
list_insert = TwoWayList()

np.random.seed(40)
random_num1 = np.random.randint(0,10,10)
random_num2 = np.random.randint(0,10,10)


for i, j in zip(random_num1, random_num2):
    list_bubble.append(i)
    list_insert.append(j)


print('BUBBLE:')
list_bubble.show()
list_bubble.sort_bubble()
list_bubble.show()

print('\nINSERT:')
list_insert.show()
list_insert.sort_insert()
list_insert.show()