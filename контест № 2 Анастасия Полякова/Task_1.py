n = int(input())
a = [int(i) for i in input().split()]

counter = 0
for i in range(n - 1):
    for j in range(n - 1 - i):
        if a[j] > a[j+1]:
            a[j], a[j+1] = a[j+1], a[j]
            counter += 1
print(*a)
print(counter)