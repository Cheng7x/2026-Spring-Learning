import numpy as np

'''
N-dimensional array
array = np.array([['A', 'B', 'C'], ['D', 'E', 'F'], ['G', 'H', 'I']])
print(array[0, 2])
'''

"""
# slice 
array = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]])
# row slice
print(array[2:4]) # [[9, 10, 11, 12], [13, 14, 15, 16]] 
# column slice
print(array[:, 2]) # [3, 7, 11, 15]
# row and column slice
print(array[1:3, 1:3]) # [[6, 7], [10, 11]]
"""

# array = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
# print(array.ndim)


a = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])

print(a.shape)   # (3, 3)
print(a.ndim)    # 2
print(a.size)    # 9
print(a.dtype)   # 元素类型

b = a.reshape(3, 3)
c = a.T

print(b)
print(c)


