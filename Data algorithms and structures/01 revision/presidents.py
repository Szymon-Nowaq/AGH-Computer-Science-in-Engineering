import pandas as pd 
import numpy as np

class President:
    def __init__(self, data):
        self.name = data[0]
        self.years = data[1]
        self.party = data[2]
        self.end = data[3]
        self.start = data[4]

    def show(self):
        print('Name: ', self.name)
        print('RuleYears: ', self.years)
        print('Party: ', self.party)
        print('Start: ', self.start)
        print('End: ', self.end)

    def get_data(self):
        return self.name, self.years, self.party, self.end, self.start

class Object:
    def __init__(self, data):
        self.data = President(data)
        self.next = None
        self.prev = None
        self.index = 0
    
    def show(self):
        print('index: ', self.index)
        self.data.show()
    

class TwoWayList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.count = 0

    def is_empty(self):
        return self.head is None

    def append(self, data):
        new_Object = Object(data)
        new_Object.index = self.count
        self.count += 1
        if self.is_empty():
            self.head = new_Object
            self.tail = new_Object
        else:
            new_Object.prev = self.tail
            self.tail.next = new_Object
            self.tail = new_Object

    def prepend(self, data):
        new_Object = Object(data)
        new_Object.index = 0
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


    def show(self):
        current = self.head
        while current is not None:
            if current.index != 0:
                print("\t↑\n\t↓")
            current.show()
            current = current.next
        print("None")
    
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
            
    def get_list_of_shortest_cadence(self):
        current = self.head
        min = current.data.years
        arr = np.array([])
        for i in range(self.count):
            if current.data.years < min:
                min = current.data.years
                arr = np.array([i])
            elif current.data.years == min:
                arr = np.append(arr, i)
            current = current.next
        list = TwoWayList()
        for i in range(len(arr)):
            list.append(self.find_element(arr[i]).data.get_data())
        return list
    
    def get_list_of_all_prsd_from_party(self, party):
        current = self.head
        list = TwoWayList()
        while current:
            if current.data.party == party:
                list.append(current.data.get_data())
            current = current.next
        return list
    
    def get_president_by_year(self, year):
        current = self.head
        i = 0
        list = TwoWayList()
        while current:
            if current.data.start <= year and year <= current.data.end:
                list.append(current.data.get_data())
                i += 1
            if year < current.data.end:
                if i == 1:
                    return list.head
                else:
                    return list       
            current = current.next
        print('wrong year')
        return None


presidents = pd.read_csv('02 list/presidents.csv')
presidents['End'] = pd.to_numeric(presidents['RuleYears'].str[-4:]) 
presidents['Start'] = pd.to_numeric(presidents['RuleYears'].str[:4])
presidents['RuleYears'] = presidents['End'] - presidents['Start']

USA_prsd = TwoWayList()
for i in range(len(presidents)):
    USA_prsd.append(presidents.iloc[i - 1,:5])

#USA_prsd.insert(presidents.iloc[0,:5], 10)
#USA_prsd.show()

shortest = USA_prsd.get_list_of_shortest_cadence()
#shortest.show()

rep_prsd = USA_prsd.get_list_of_all_prsd_from_party('Republican')
#rep_prsd.show()

prsd_year = USA_prsd.get_president_by_year(1841)
#prsd_year.show()

#USA_prsd.show_by_index(10)
#USA_prsd.show_by_index(20)

#print(presidents)









''' def delete(self, data):
        current = self.head
        while current:
            if current.data == data:
                if current.prev:
                    current.prev.next = current.next
                else:
                    self.head = current.next
                if current.next:
                    current.next.prev = current.prev
                else:
                    self.tail = current.prev
                return
            current = current.next'''