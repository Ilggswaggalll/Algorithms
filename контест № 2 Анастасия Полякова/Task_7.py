def bubble_sort(my_list):
    n = len(my_list)
    for i in range(n):
        fl = True
        for j in range(n - 1):
            if my_list[j] > my_list[j + 1]:
                my_list[j], my_list[j + 1] = my_list[j + 1], my_list[j]
                fl = False
        if fl:
            break


N, M = map(int, input().split())
sklad = [list(map(int, input().split())) for _ in range(N)]
lims = []
for i in range(N):
    for j in range(M):
        lims.append(sklad[i][j])
number = int(input())
conts = [int(i) for i in input().split()]
bubble_sort(lims)
bubble_sort(conts)

counter = 0
i = 0
j = 0
while i < number and j < len(lims):
        if conts[i] <= lims[j]:
            counter += 1
            i += 1
            j += 1
        else:
            j += 1
print(counter)