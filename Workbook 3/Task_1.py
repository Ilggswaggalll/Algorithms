import datetime


# сравнение одинаковых по длине чисел (поразрядно)
def srav(a, b):
    for i in range(len(a)):
        if a[i] > b[i]:
            return 0
    return 1


# вычитание в столбик подготовленных чисел
def subt(m1, m2, a):
    m3 = [0] * len(m1)
    m = []
    if a == 1:
        m.append('-')
    for i in range(len(m1) - 1, -1, -1):
        m1[i], m2[i] = int(m1[i]), int(m2[i])
        if int(m1[i]) - int(m2[i]) < 0:
            for j in range(i - 1, -1, -1):
                if m1[j] - 1 < 0:
                    m1[j] += 9
                else:
                    m1[j] -= 1
                    break
            m1[i] += 10
            m3[i] = m1[i] - m2[i]
        else:
            m3[i] = m1[i] - m2[i]
    h = 0
    for i in range(len(m3)):
        if m3[i] != 0:
            h = i
            break
    for i in range(h, len(m3)):
        m.append(m3[i])
    if m == [0]:
        return m[1:]
    if all(i == 0 for i in m):
        return [0]
    return m


# подготовка чисел для вычитания в столбик и нахождение результата функции subt
def subtraction(a, b):
        if len(a) != len(b):
            if len(a) > len(b):
                m1 = [int(i) for i in a]
                m2 = []
                for i in range(len(a) - len(b)):
                    m2.append(0)
                for i in b:
                    m2.append(int(i))
                m = subt(m1, m2, 0)
                return m
            else:
                m2 = [int(i) for i in b]
                m1 = []
                for i in range(len(b) - len(a)):
                    m1.append(0)
                for i in a:
                    m1.append(i)
                m = subt(m2, m1, 1)
                return m
        else:
            m1 = [int(i) for i in a]
            m2 = [int(i) for i in b]
            for i in range(len(m1)):
                if m1[i] > m2[i]:
                    m = subt(m1, m2, 0)
                    break
                elif m1[i] < m2[i]:
                    m = subt(m2, m1, 1)
                    break
        return m


# сложение в столбик
def addit(a, b):
    if len(a) != len(b):
        if len(a) > len(b):
            m1 = [int(i) for i in a]
            m2 = []
            for i in range(len(a) - len(b)):
                m2.append(0)
            for i in b:
                m2.append(int(i))
        else:
            m2 = [int(i) for i in b]
            m1 = []
            for i in range(len(b) - len(a)):
                m1.append(0)
            for i in a:
                m1.append(int(i))
    else:
        m1 = [int(i) for i in a]
        m2 = [int(i) for i in b]
    m3 = []
    v_ume = 0
    for i in range(len(m1) - 1, -1, -1):
        n = m1[i] + m2[i] + v_ume
        v_ume = 0
        if n >= 10:
            while n - 10 >= 0:
                n -= 10
                v_ume += 1
            m3.append(n)
        else:
            m3.append(n)
    if v_ume != 0:
        m3.append(v_ume)
    return m3[::-1]


# проверка
a = input("Первое большое число: ")
b = input("Второе большое число: ")
start = datetime.datetime.now()
print("Сложение: ", end='')
if a[0] == '-' and b[0] == '-':
    m = addit(a[1:], b[1:])
    print('-', end='')
    for i in m:
        print(i, end='')
    print()
elif a[0] == '-' and b[0] != '-':
    m = subtraction(b, a[1:])
    for i in m:
        print(i, end='')
    print()
elif a[0] != '-' and b[0] == '-':
    m = subtraction(a, b[1:])
    for i in m:
        print(i, end='')
    print()
else:
    m = addit(a, b)
    for i in m:
        print(i, end='')
    print()
print("Вычитание: ", end='')
if a[0] == '-' and b[0] == '-':
    m = subtraction(b[1:], a[1:])
    for i in m:
        print(i, end='')
    print()
elif a[0] == '-' and b[0] != '-':
    m = addit(a[1:], b)
    print('-', end='')
    for i in m:
        print(i, end='')
    print()
elif a[0] != '-' and b[0] == '-':
    m = addit(a, b[1:])
    for i in m:
        print(i, end='')
    print()
else:
    m = subtraction(a, b)
    for i in m:
        print(i, end='')
    print()
finish = datetime.datetime.now()
print("Микросекунд прошло:", finish.microsecond - start.microsecond)