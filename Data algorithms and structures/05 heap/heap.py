class Node:
    def __init__(self, key, parent, id):
        self.left = None
        self.right = None
        self.parent = parent
        self.val = key
        self.id = id

class Heap:
    def __init__(self):
        self.n = 0
        self.root = None
    
    def push(self, key):
        self.n += 1
        if self.root == None:
            new_node = Node(key, None, self.n)
            self.root = new_node
        else:
            path = self.make_path()
            temp = self.root
            for id in path[:-1]:
                if id % 2 == 0:
                    temp = temp.left
                else:
                    temp = temp.right
            if path[-1] % 2 == 0:
                temp.left = new_node = Node(key, temp, self.n)
                self.hierarchia_kastowa(temp.left)
            else:
                temp.right = new_node = Node(key, temp, self.n)
                self.hierarchia_kastowa(temp.right)
        
    def hierarchia_kastowa(self, node : Node):
        while node.id != 1:
            if node.val > node.parent.val:
                temp = node.parent.val
                node.parent.val = node.val
                node.val = temp
            else:
                break
            node = node.parent

    def wypierdol(self, val):
        to_delete = self.find_by_value(val)
        if to_delete == None:
            print('value not in the heap')
            return None
        self.n -= 1

    def make_path(self):
        if self.n == 2 or self.n == 3:
            return [self.n]
        else:
            path = []
            current = self.n
            while True:
                path.append(current)
                current = (current / 2).__floor__()
                if current <= 1:
                    break
            path.reverse()
            return path
    
    def display(self, node, level=0):
        if node is not None:
            self.display(node.right, level + 1)
            print('  ' * 4 * level + '->', node.val)
            self.display(node.left, level + 1)
        else:
            return

    def find_by_value(self, value):
            return self._find_recursive(self.root, value)

    def _find_recursive(self, node, value):
            if node is None:
                return None
            if node.val == value:
                return node
            found_node = self._find_recursive(node.left, value)
            if found_node is None:
                found_node = self._find_recursive(node.right, value)
            return found_node

kopiec = Heap()
kopiec.push(30)
kopiec.push(25)
kopiec.push(20)
kopiec.push(45)
kopiec.push(30)
kopiec.push(56)
kopiec.push(74)
kopiec.push(81)
kopiec.push(90)
kopiec.push(15)
kopiec.push(20)
kopiec.push(55)
kopiec.display(kopiec.root)
print(kopiec.n)