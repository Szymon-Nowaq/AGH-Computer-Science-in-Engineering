import numpy as np
import pandas as pd
import math
from matplotlib import pyplot as plt

def distance(x,y):
    return(math.sqrt((y[0]-x[0])**2 + (y[1]-x[1])**2))

def zad1(size, point):
    board = np.zeros(size)
    board[point[0], point[1]] = 1
    corners = np.array([(0,0), (0,size[1] - 1), (size[0] - 1,0), (size[0] - 1,size[1] - 1)])
    distances = np.zeros(4)
    for i in range(4):
        distances[i] = distance(corners[i], point)
    df = pd.DataFrame({'corners': list(corners), 'distances': distances})
    fur_point = tuple(df.loc[df['distances'].idxmax(), 'corners'])
    board[(fur_point)] = 2
    #print(board) 
    return(fur_point)

def zad2(size, color_count):
    board = np.random.randint(0,color_count, size)
    #print(board)
    neighbour_count = np.zeros(color_count)
    for i in range(size[0]):
        for j in range(size[1]):
            if j > 0 and j < size[1] - 1:
                if board[i, j - 1] == board[i, j + 1]:
                    neighbour_count[board[i,j]] += 1
    plt.bar(x=np.arange(len(neighbour_count)), height=neighbour_count)
    #print(neighbour_count)
    plt.show()
    return np.argmax(neighbour_count)

def zad3(size, n):
    board = np.random.randint(1,size[0], size)
    #print(board)
    results = np.zeros([size[0], size[1]])
    for i in range(1,size[0] - 1):
        for j in range(1, size[1] - 1):
            if (i + j) % n == 0:
                results[i,j] = board[i-1,j-1] * board[i-1,j] * board[i,j-1] * board[i+1,j+1] * board[i+1,j] * board[i,j+1] * board[i+1,j-1] *board[i-1,j+1]
    #print(results)
    non_zero_idx = np.argwhere(results != 0)
    #print(non_zero_idx)
    return tuple(non_zero_idx[np.argmin(results[results != 0])])
            

board_size = (10,10)

print('zad1:', zad1(board_size, (5,4)))
print('zad2:',zad2(board_size, 100))
print('zad3:',zad3(board_size,2))
