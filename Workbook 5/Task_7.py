import time
import random


def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr


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


def insertion(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr


def selection(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr


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


def qsort(s):
    if len(s) <= 1:
        return s
    opp = s[len(s) // 2]
    middle = [i for i in s if i == opp]
    left = [i for i in s if i < opp]
    right = [i for i in s if i > opp]
    return qsort(left) + middle + qsort(right)


def duration(s1, s2):
    start1 = time.time()
    m1 = bubble_sort(s1)
    end1 = time.time()
    start11 = time.time()
    m1 = bubble_sort(s2)
    end11 = time.time()
    print("Сортировка bubble_1:", '{:.20f}'.format(end1 - start1), 'секунд')
    print("Сортировка bubble_2:", end11 - start11, 'секунд')
    print()
    
    start2 = time.time()
    m2 = shaker(s1)
    end2 = time.time()
    start22 = time.time()
    m2 = shaker(s2)
    end22 = time.time()
    print("Сортировка shaker_1:", '{:.20f}'.format(end2 - start2), 'секунд')
    print("Сортировка shaker_2:", end22 - start22, 'секунд')
    print()

    start3 = time.time()
    m3 = insertion(s1)
    end3 = time.time()
    start33 = time.time()
    m3 = insertion(s2)
    end33 = time.time()
    print("Сортировка insertion_1:", '{:.20f}'.format(end3 - start3), 'секунд')
    print("Сортировка insertion_2:", end33 - start33, 'секунд')
    print()


    start4 = time.time()
    m4 = selection(s1)
    end4 = time.time()
    start44 = time.time()
    m4 = selection(s2)
    end44 = time.time()
    print("Сортировка selection_1:", '{:.20f}'.format(end4 - start4), 'секунд')
    print("Сортировка selection_2:", end44 - start44, 'секунд')
    print()


    start5 = time.time()
    m5 = shell(s1)
    end5 = time.time()
    start55 = time.time()
    m5 = shell(s2)
    end55 = time.time()
    print("Сортировка shell_1:", '{:.20f}'.format(end5 - start5), 'секунд')
    print("Сортировка shell_2:", end55 - start55, 'секунд')
    print()

    start6 = time.time()
    m6 = qsort(s1)
    end6 = time.time()
    start66 = time.time()
    m6 = qsort(s2)
    end66 = time.time()
    print("Сортировка qsort_1:", '{:.20f}'.format(end6 - start6), 'секунд')
    print("Сортировка qsort_2:", end66 - start66, 'секунд')
    print()


arr_1 = [45, 55, 20, 17, 6, 70, 5, 1, 9, 9, 34]
arr_2 = []
for i in range(5000):
    arr_2.append(random.randint(1, 1000))

duration(arr_1, arr_2)








