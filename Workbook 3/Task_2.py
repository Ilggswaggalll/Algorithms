def addit_n_perenos(a, b):
    addit = []
    transfer = []
    transfer.append(0)
    for i in range(len(a)):
        if a[i] + b[i] == 2:
            transfer.append(1)
            addit.append(0)
        else:
            addit.append(a[i] + b[i])
            transfer.append(0)
    if len(addit) != len(transfer):
        addit.append(0)
    return [addit, transfer]


def fast_addit(a, b):
    num_1 = [int(i) for i in a[::-1]]
    num_2 = [int(i) for i in b[::-1]]
    if len(a) != len(b):
        if len(a) > len(b):
            for i in range(len(a) - len(b)):
                num_2.append(0)
        else:
            for i in range(len(b) - len(a)):
                num_1.append(0)
    print(num_1[::-1])
    print(num_2[::-1])
    print()
    x = addit_n_perenos(num_1, num_2)
    print(x[0][::-1])
    print(x[1][::-1])
    print()
    while not all(i == 0 for i in x[1]):
        x = addit_n_perenos(x[0], x[1])
        print(x[0][::-1])
        print(x[1][::-1])
        print()
    s = ''
    for i in x[0]:
        s += str(i)
    if not all(s[i] == '0' for i in range(len(s))):
        while s[-1] == '0':
            s = s[:-1]
    return s[::-1]
    
a = input("Первое большое число: ")
b = input("Второе большое число: ")
print(fast_addit(a, b))
