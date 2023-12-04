import numpy as np 

np.random.seed(42)
arr = np.random.randint(0,10,10)

#BUBBLE

print('BUBBLE: ')
print(arr)
for i in range(len(arr)):
    for j in range(len(arr) - i - 1):
        if arr[j + 1] < arr[j]:
            temp= arr[j]
            arr[j] = arr[j+1]
            arr[j+1] = temp

print(arr)

# INSERT
print('\nINSERT: ')
arr = np.random.randint(0,10,10)
print(arr)
srt_arr = [arr[-1]]
for i in range(len(arr) - 1):
    to_insert = arr[i]
    j = i
    while j >= 0 and to_insert < srt_arr[j]:
        j -= 1
    srt_arr.insert(j + 1, to_insert)
print(np.array(srt_arr))