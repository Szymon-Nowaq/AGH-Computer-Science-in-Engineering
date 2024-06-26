import numpy as np

class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size

    def find(self, node):
        if self.parent[node] != node:
            self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    def union(self, node1, node2):
        root1 = self.find(node1)
        root2 = self.find(node2)
        if root1 != root2:
            if self.rank[root1] > self.rank[root2]:
                self.parent[root2] = root1
            elif self.rank[root1] < self.rank[root2]:
                self.parent[root1] = root2
            else:
                self.parent[root2] = root1
                self.rank[root1] += 1

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
    def __init__(self, filename : str):
            self.node_count, self.ver_count, connections = read_txt(filename)
            self.nodes = [Node(label) for label in np.arange(self.node_count)]
            self.verticles = [Verticle(self.nodes[int(start)], self.nodes[int(end)], wage) for start, end, wage in connections]
            for vert in self.verticles:
                vert.start.add_vert(vert)
                
            self.neigh_matrix = np.zeros((self.node_count, self.node_count)) 
            for i, j, w in connections[:,:3].astype(int):
                self.neigh_matrix[i,j] = w
            #print('macierz sasiedztwa:\n', self.neigh_matrix)

            self.incident = np.zeros((self.ver_count, self.node_count))
            for i, vert in enumerate(self.verticles):
                self.incident[i, vert.start.label] = vert.wage
                self.incident[i, vert.end.label] = -vert.wage
            #print('\nmacierz incydencji:\n', self.incident)

            self.neigh_list = []
            for node in self.nodes:
                node_list = []
                for neight in node.ver_list:
                    node_list.append(neight.end)
                self.neigh_list.append(node_list) 
            #print('\nlista sasiedztwa:\n')
            '''for i, list in enumerate(self.neigh_list):
                print('\nsasiedzi wezla ', self.nodes[i])
                for neigh in list:
                    print(neigh)'''
    
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

    def KruskalMST(self):
        uf = UnionFind(self.node_count)

        sorted_edges = sorted(self.verticles, key=lambda x: x.wage)
        mst = []
        for edge in sorted_edges:
            if uf.find(edge.start.label) != uf.find(edge.end.label):
                uf.union(edge.start.label, edge.end.label)
                mst.append(edge)
        
    
        print("Początkowa lista krawędzi i ich wag:")
        for edge in sorted_edges:
            print(f"Verticle(Start: {edge.start.label}, End: {edge.end.label}, Wage: {edge.wage})")
        
        print("\nLista krawędzi minimalnego drzewa rozpinającego i suma wag:")
        total_weight = 0
        for edge in mst:
            total_weight += edge.wage
            print(f"Verticle(Start: {edge.start.label}, End: {edge.end.label}, Wage: {edge.wage})")
        print(f"Suma wag: {total_weight}")


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
graf1.KruskalMST()





