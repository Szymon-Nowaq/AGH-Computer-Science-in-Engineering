import numpy as np

class Node:
    def __init__(self, key, parent):
        self.left = None
        self.right = None
        self.parent = parent
        self.val = key

class BinaryTree:
    def __init__(self):
        self.root = None
        self.count = 0

    def insert(self, key):
        if self.root is None:
            self.root = Node(key, None)
            self.count += 1
        else:
            current = self.root
            while True:
                if key > current.val:
                    if current.right == None:
                        new_Node = Node(key, current)
                        current.right = new_Node
                        self.count += 1
                        break
                    else:
                        current = current.right
                elif key < current.val:
                    if current.left == None:
                        new_Node = Node(key, current)
                        current.left = new_Node
                        self.count += 1
                        break
                    else:
                        current = current.left
                else:
                    print('equal element')
                    return None
    
    def find_min(self):
        current = self.root
        while True:
            if current.left == None:
                return current
            current = current.left

    def find_max(self):
        current = self.root
        while True:
            if current.right == None:
                return current
            current = current.right

    def get_by_value(self, val):
        current = self.root
        while current.val != val:
            if current == None:
                print('value doesnt exist')
                return None
            if current.val > val:
                current = current.left
            else:
                current = current.right
        return current

def is_younger_son(node: Node):
    if node.parent != None:
        if node.parent.val > node.val:
            return True
        else: 
            return False
    else:
        return None

def find_next(node : Node):
    current = node
    if node.right == None:
        if is_younger_son(current):
            return current.parent
        current = current.parent
        while not is_younger_son(current):
            current = current.parent
            if current.parent == None:
                print("this element is max of tree")
                return Node(-1,None)
        return current.parent    
    else:
        current = current.right
        if current.left != None:
            return find_min(current)
        else:
            return current


def find_prev(node : Node):
    current = node
    if node.left != None:
        return find_max(node.left)
    elif node.parent != None:
        while is_younger_son(current):
            if current.parent != None:
                current = current.parent
            else:
                return current
        if current.parent != None:
            return current.parent
        else:
            print('this element is min of tree')
            return Node(-1,None)
    else:
        return current.parent

def find_min(node : Node):
    current = node
    while True:
        if current.left == None:
            return current
        current = current.left

def find_max(node : Node):
    current = node
    while True:
        if current.right == None:
            return current
        current = current.right

    

# Przykład użycia:
bt = BinaryTree()
'''bt.insert(15)
bt.insert(6)
bt.insert(18)
bt.insert(3)
bt.insert(7)
bt.insert(17)
bt.insert(20)
bt.insert(2)
bt.insert(4)
bt.insert(13)
bt.insert(9)

print(find_prev(bt.get_by_value(15)).val)
print(find_prev(bt.get_by_value(17)).val)
print(find_prev(bt.get_by_value(4)).val)
print(find_prev(bt.get_by_value(20)).val)
print(find_prev(bt.get_by_value(2)).val)

print('\n')

print(find_next(bt.get_by_value(15)).val)
print(find_next(bt.get_by_value(13)).val)
print(find_next(bt.get_by_value(6)).val)
print(find_next(bt.get_by_value(17)).val)
print(find_next(bt.get_by_value(20)).val)'''

tab = np.arange(100)

np.random.shuffle(tab)
#print(tab)

for value in tab:
    bt.insert(value)

print('PREV TEST:')
for i in range(100):
    print("prev of",i,"is: ",find_prev(bt.get_by_value(i)).val)

print('\n\nNEXT TEST:')
for i in range(100):
    print("next of",i,"is: ",find_next(bt.get_by_value(i)).val)

