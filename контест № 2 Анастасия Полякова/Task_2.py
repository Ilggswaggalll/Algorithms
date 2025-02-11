n = int(input())
if n != 0:
    my_list = [x for x in list(map(int, input().split()))]
    counter = 0
    for i in range(n):
        fl = True
        for j in range(n-1):
            if my_list[j] > my_list[j+1]:
                my_list[j], my_list[j+1] = my_list[j+1], my_list[j]
                fl = False
                counter +=1
        if fl:
            break

    print(*my_list)
    print(counter)
else:
    print()
    print(0)