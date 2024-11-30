def shaker(arr):
    n = len(arr)
    left, right = 0, n - 1
    while left < right:
        for i in range(left, right):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
        right -= 1
        for i in range(right, left, -1):
            if arr[i] < arr[i - 1]:
                arr[i], arr[i - 1] = arr[i - 1], arr[i]
        left += 1
    return arr


arr = [45, 55, 20, 17, 6, 70, 5, 1]
print(shaker(arr))