import numpy as np

class Node():
    def __init__(self, label):
        self.label = label
        self.ver_list = []

    def add_vert(self, vert):
        self.ver_list.append(vert)

    def __str__(self):
        vert_str = '\n'.join('\t' + str(vert) for vert in self.ver_list)
        return f"Node(Label: {self.label})"
        #return f"Node(Label: {self.label}, Verticles: \n{vert_str})" 
        

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
            for i, j in connections[:,:2].astype(int):
                self.neigh_matrix[i,j] = 1
            print('macierz sasiedztwa:\n', self.neigh_matrix)

            self.incident = np.zeros((self.ver_count, self.node_count))
            for i, vert in enumerate(self.verticles):
                self.incident[i, vert.start.label] = 1
                self.incident[i, vert.end.label] = 1
            print('\nmacierz incydencji:\n', self.incident)

            self.neigh_list = []
            for node in self.nodes:
                node_list = []
                for neight in node.ver_list:
                    node_list.append(neight.end)
                self.neigh_list.append(node_list) 
            print('\nlista sasiedztwa:\n')
            for i, list in enumerate(self.neigh_list):
                print('\nsasiedzi wezla ', self.nodes[i])
                for neigh in list:
                    print(neigh)

        

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
            wages = indexes_to_correct[::3]
            indexes_to_correct = np.array([val for i, val in enumerate(indexes_to_correct) if (i+1)%3 != 0])
        else:
            wages = np.zeros(params[1])
        indexes_to_correct -= indexes_to_correct.min()
        unique_sorted = np.sort(np.unique(indexes_to_correct))
        value_mapping = {value: i for i, value in enumerate(unique_sorted)}
        correct_indexes = np.array([value_mapping[value] for value in indexes_to_correct]).reshape((params[1], 2))
        return params[0], params[1], np.column_stack([correct_indexes.astype(int), wages]) 

graf1 = Graph("input1.txt")
#graf2 = Graph("input2.txt")




