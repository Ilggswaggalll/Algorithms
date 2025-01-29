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


def insertion_sort(arr):
    for i in range(1, len(arr)):
      temp = arr[i]
      pos = binary_search(arr, temp, 0, i) + 1
      for k in range(i, pos, -1):
         arr[k] = arr[k - 1]
      arr[pos] = temp
    return arr

def binary_search(arr, key, start, end):
   if end - start <= 1:
      if key < arr[start]:
         return start - 1
      else:
         return start
   mid = (start + end)//2
   if arr[mid] < key:
      return binary_search(arr, key, mid, end)
   elif arr[mid] > key:
      return binary_search(arr, key, start, mid)
   else:
      return mid


array = [random.randint(1, 2000) for _ in range(5000)]
#arr_test = [45, 55, 20, 17, 6, 70, 5, 1, 9, 9]
start_1 = time.time()
insertion(array.copy())
print("Insertion Sort", '{:.20f}'.format(time.time() - start_1), 'seconds')
print()
start_2 = time.time()
insertion_sort(array.copy())
print("Binary Insertion Sort", '{:.20f}'.format(time.time() - start_2), 'seconds')