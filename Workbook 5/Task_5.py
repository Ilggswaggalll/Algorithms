def shell(arr):
    n = len(arr)
    d = n // 2
    while d > 0:
        for i in range(d, n):
            key = arr[i]
            j = i
            while j >= d and arr[j - d] > key:
                arr[j] = arr[j - d]
                j -= d
            arr[j] = key
        d //= 2
    return arr


arr = [45, 55, 20, 17, 6, 70, 5, 1]
print(shell(arr))
