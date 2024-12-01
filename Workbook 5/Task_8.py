import random
import time


def insertion(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr


def binary_search(sub_arr, key, start, end):
    while start < end:
        mid = (start + end) // 2
        if sub_arr[mid] < key:
            start = mid + 1
        else:
            end = mid
    return start


def binary_insertion(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        pos = binary_search(arr, key, 0, i)
        arr = arr[:pos] + [key] + arr[pos:i] + arr[i + 1:]
    return arr


array = [random.randint(1, 1000) for _ in range(5000)]
arr_test = [45, 55, 20, 17, 6, 70, 5, 1, 9, 9, 34]
array_1 = array.copy()
array_2 = array.copy()

start_1 = time.time()
insertion(array_1)
print("Insertion Sort", '{:.20f}'.format(time.time() - start_1), 'seconds')
print()

start_2 = time.time()
print(binary_insertion(arr_test), '- test for binary_insertion')
print("Binary Insertion Sort", '{:.20f}'.format(time.time() - start_2), 'seconds')
