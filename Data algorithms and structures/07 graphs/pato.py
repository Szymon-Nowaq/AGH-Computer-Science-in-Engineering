import numpy as np

class Node():
    def __init__(self, label):
        self.label = label
        self.ver_list = []
        self.visited = False

    def add_vert(self, vert):
        self.ver_list.append(vert)

    def __str__(self):
        vert_str = '\n'.join('\t' + str(vert) for vert in self.ver_list)
        #return f"Node(Label: {self.label})"
        return f"Node(Label: {self.label}, Verticles: \n{vert_str})" 
        

class Verticle():
    def __init__(self, start : Node, end : Node, wage):
        self.start = start
        self.end = end
        self.wage = wage

    def __str__(self):
        return f"Verticle(Start: {self.start.label}, End: {self.end.label}, Wage: {self.wage})"
        

class Graph():
    def __init__(self, filename: str):
        self.node_count, self.ver_count, connections = read_txt(filename)
        self.nodes = [Node(label) for label in np.arange(self.node_count)]
        self.verticles = []

        for start, end, wage in connections:
            # Tworzenie dwóch krawędzi dla każdego połączenia: jednej od start do end, a drugiej od end do start
            vert1 = Verticle(self.nodes[int(start)], self.nodes[int(end)], wage)
            vert2 = Verticle(self.nodes[int(end)], self.nodes[int(start)], wage)

            # Dodawanie obu krawędzi do odpowiednich węzłów
            self.nodes[int(start)].add_vert(vert1)
            self.nodes[int(end)].add_vert(vert2)

            # Dodawanie krawędzi do listy krawędzi
            self.verticles.extend([vert1, vert2])

        # Tworzenie macierzy sąsiedztwa, incydencji i listy sąsiedztwa
        self.neigh_matrix = np.zeros((self.node_count, self.node_count)) 
        for i, j, w in connections:
            self.neigh_matrix[i, j] = w
            self.neigh_matrix[j, i] = w  # Dodanie symetrycznego elementu

        self.incident = np.zeros((2 * self.ver_count, self.node_count))
        for i, vert in enumerate(self.verticles):
            self.incident[i, vert.start.label] = vert.wage
            self.incident[i, vert.end.label] = -vert.wage

        self.neigh_list = []
        for node in self.nodes:
            node_list = []
            for neight in node.ver_list:
                node_list.append(neight.end)
            self.neigh_list.append(node_list)

    
    def DFS(self):
        stack = [self.nodes[0]]
        #print(self.nodes[0])
        stack[0].visited = True
        unique_vert = []

        while stack:
            current_node = stack[-1]
            next_node, unique_vert = self.seek_next(current_node, unique_vert)
            if next_node is None:
                stack.pop()
            else:
                stack.append(next_node)
                #print(next_node)
                next_node.visited = True

        print('Unikalne krawędzie:')
        for vert in unique_vert:
            print(vert)

    def seek_next(self, node: Node, unique_vert):
        for ver in node.ver_list:
            print(ver)
            if not ver.end.visited:
                unique_vert.append(ver)
                return ver.end, unique_vert
        return None, unique_vert



    def BFS(self):
        queue = [self.nodes[0]]
        unique_vert = []

        while queue:
            current_node = queue.pop(0)
            if not current_node.visited:
                current_node.visited = True
                for vert in current_node.ver_list:
                    print(vert)
                    if not vert.end.visited:
                        queue.append(vert.end)
                        unique_vert.append(vert)
                        print(vert)

        print('Unikalne krawędzie:')
        for vert in unique_vert:
            print(vert)


def read_txt(filename):
    with open(filename, 'r') as file:
        params = []
        for i in range(2):
            line = file.readline()
            params.append(int(line.strip()))
        indexes_to_correct = np.array([])
        for line in file:
            indexes_to_correct = np.append(indexes_to_correct, [int(element) for element in line.split()])
        if len(indexes_to_correct)/params[1] == 3:
            wages = indexes_to_correct[2::3]
            indexes_to_correct = np.array([val for i, val in enumerate(indexes_to_correct) if (i+1)%3 != 0])
        else:
            wages = np.zeros(params[1]) + 1
        indexes_to_correct -= indexes_to_correct.min()
        unique_sorted = np.sort(np.unique(indexes_to_correct))
        value_mapping = {value: i for i, value in enumerate(unique_sorted)}
        correct_indexes = np.array([value_mapping[value] for value in indexes_to_correct]).reshape((params[1], 2))
        return params[0], params[1], np.column_stack([correct_indexes.astype(int), wages]) 

graf1 = Graph("zad2.txt")
#graf2 = Graph("BSF.txt")
graf1.DFS()




