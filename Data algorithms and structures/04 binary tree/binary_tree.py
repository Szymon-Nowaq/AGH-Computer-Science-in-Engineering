import numpy as np

class Node:
    def __init__(self, key, parent):
        self.left = None
        self.right = None
        self.parent = parent
        self.val = key
    def show(self):
        print('[',self.val,']', end = '', sep='')

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
    
    def show(self):
        current = self.find_min()
        max_val = self.find_max().val
        while current.val != max_val:
            current.show()
            print(', ', end='')
            current = find_next(current)
        current.show()
        print()

def remove(root : Node):
    if root.right != None and root.left != None:
        if root.val > 10:
            delete(find_next(root))
        else:
            delete(find_prev(root))
    else:
        print("wrong root")
        return

def height(root : Node):
    if root is None:
        return -1
    else:
        left_height = height(root.left)
        right_height = height(root.right)
        return max(left_height, right_height) + 1

def get_by_value(root : Node, val):
        current = root
        while current.val != val:
            if current == None:
                print('value doesnt exist')
                return None
            if current.val > val:
                current = current.left
            else:
                current = current.right
        return current

def delete(root : Node, val):
    to_del = get_by_value(root,val)
    if to_del.left == None and to_del.right == None:
        if is_younger_son(to_del):
            to_del.parent.left = None
        else:
            to_del.parent.right = None
    elif to_del.left == None:
        if is_younger_son(to_del):
            to_del.parent.left = to_del.right
        else:
            to_del.parent.right = to_del.right
        to_del.right.parent = to_del.parent
    elif to_del.right == None:
        if is_younger_son(to_del):
            to_del.parent.left = to_del.left
        else:
            to_del.parent.right = to_del.left
        to_del.left.parent = to_del.parent
    else:
        to_swap = find_min(to_del.right)
        to_del.val = to_swap.val
        delete(to_del.right, to_swap.val) 

def delete(root : Node):
    to_del = root
    if to_del.left == None and to_del.right == None:
        if is_younger_son(to_del):
            to_del.parent.left = None
        else:
            to_del.parent.right = None
    elif to_del.left == None:
        if is_younger_son(to_del):
            to_del.parent.left = to_del.right
        else:
            to_del.parent.right = to_del.right
        to_del.right.parent = to_del.parent
    elif to_del.right == None:
        if is_younger_son(to_del):
            to_del.parent.left = to_del.left
        else:
            to_del.parent.right = to_del.left
        to_del.left.parent = to_del.parent
    else:
        to_swap = find_min(to_del.right)
        to_del.val = to_swap.val
        delete(to_del.right, to_swap.val) 

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

def postorder(root : Node):
    if root == None:
        return
    postorder(root.left)
    postorder(root.right)
    root.show()
    print(', ', end='')
    return

def inorder(root : Node):
    if root == None:
        return
    inorder(root.left)
    root.show()
    print(', ', end='')
    inorder(root.right)
    return

def preorder(root : Node):
    if root == None:
        return
    root.show()
    print(', ', end='')
    preorder(root.right)
    preorder(root.left)
    return
    

# Przykład użycia:
bt = BinaryTree()


bt.insert(7)
bt.insert(5)
bt.insert(9)
bt.insert(2)
bt.insert(6)
bt.insert(8)
bt.insert(11)
bt.insert(10)
bt.insert(16)
bt.insert(17)
bt.insert(14)
bt.insert(12)


bt.show()
print('height: ', height(bt.root))
#delete(bt.root,8)
#print("po usunieciu 8:")
#bt.show()

#print(height(bt.root))

remove(get_by_value(bt.root, 17))
bt.show()
print('height: ', height(bt.root))

remove(bt.root)
bt.show()