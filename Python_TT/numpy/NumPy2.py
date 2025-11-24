# 1. Create a NumPy array from a list and perform basic operations

# Create a NumPy array from the list [1, 2, 3, 4, 5]. Perform the following operations:
# - Add 2 to each element
# - Multiply each element by 3
# - Calculate the sum of all elements

# 2. Indexing and Slicing

# Create a NumPy array arr = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9]). Perform the following operations:
# - Access the 3rd element
# - Access the last 3 elements
# - Slice the array from index 2 to 5

# 3. Array Reshaping

# Create a NumPy array arr = np.array([1, 2, 3, 4, 5, 6]). Reshape the array to a 2x3 matrix.

# 4. Array Statistics

# Create a NumPy array arr = np.array([1, 2, 3, 4, 5]). Calculate the following statistics:
# - Mean
# - Median
# - Standard Deviation

# 5. Array Concatenation

# Create two NumPy arrays arr1 = np.array([1, 2, 3]) and arr2 = np.array([2, 4, 6]). 
# Concatenate the arrays horizontally and vertically.
import numpy as np

arr = np.array([1, 2, 3, 4, 5])

add_arr = arr + 2
print(add_arr)

mul_arr = arr * 3
print(mul_arr)

sum_arr = np.sum(arr)
print(sum_arr)

arr = np.array([1, 2, 3, 4, 5, 6])
reshaped_arr = arr.reshape(2, 3)
print(reshaped_arr)

arr = np.array([1, 2, 3, 4, 5])
mean_val = np.mean(arr)
print(mean_val)
median_val = np.median(arr)
print(median_val)
standard_deviation = np.std(arr)
print(standard_deviation)

# arr1 = np.array([1, 2, 3])
# arr2 = np.array([2, 4, 6])

# c_vert = np.concatenate((arr1, arr2), axis = 0)
# c_horiz = np.concatenate((arr1, arr2), axis = 1)
# print(c_vert)
# print(c_horiz)

array1 = np.array([1, 2, 3])
array2 = np.array([4, 5, 6])

concatenated_array = np.concatenate((array1, array2))
print(concatenated_array)
