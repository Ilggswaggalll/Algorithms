import datetime

# вычитание в столбик подготовленных
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
    return m


# вычитание чисел в столбик
def subtraction(a, b):
    if int(a) < 0:
        print()
        if len(a[1:]) != len(b):
            if len(a[1:]) > len(b):
                m1 = [int(i) for i in a[1:]]
                print(m1)
                m2 = []
                for i in range(len(a[1:]) - len(b)):
                    m2.append(0)
                for i in b:
                    m2.append(int(i))
                print(m1)
                print(m2)
                m = subt(m1, m2, 0)
                return m
            else:
                m2 = [int(i) for i in b]
                m1 = []
                for i in range(len(b) - len(a[1:])):
                    m1.append(0)
                for i in a[1:]:
                    m1.append(i)
                m = subt(m2, m1, 1)
                return m
                
        else:
            m1 = [int(i) for i in a[1:]]
            m2 = [int(i) for i in b]
            if int(a) < int(b):
                m = subt(m2, m1, 0)
            else:
                m = subt(m2, m1, 1)
            return m
    else:
        print()
        if len(b[1:]) != len(a):
            if len(b[1:]) > len(a):
                m1 = [int(i) for i in b[1:]]
                m2 = []
                for i in range(len(b[1:]) - len(a)):
                    m2.append(0)
                for i in a:
                    m2.append(int(i))
                m = subt(m1, m2, 0)
                return m
            else:
                m2 = [int(i) for i in a]
                m1 = []
                for i in range(len(a) - len(b[1:])):
                    m1.append(0)
                for i in b[1:]:
                    m1.append(i)
                m = subt(m2, m1, 1)
                return m
        else:
            m1 = [int(i) for i in b[1:]]
            m2 = [int(i) for i in a]
            if int(b) < int(a):
                m = subt(m2, m1, 1)
            else:
                m = subt(m2, m1, 0)
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
    m3 = [0] * (max(len(a), len(b)))
    v_ume = 0
    for i in range(len(m1) - 1, -1, -1):
        n = m1[i] + m2[i] + v_ume
        v_ume = 0
        if n >= 10:
            while n - 10 >= 0:
                n -= 10
                v_ume += 1
            m3[i] = n
        else:
            m3[i] = n
    return m3

# проверка
a = input()
b = input()
print(int(a) + int(b))
start = datetime.datetime.now()
if int(a) > 0 and int(b) > 0:
    m = addit(a, b)
    for i in m:
        print(i, end='')
elif int(a) < 0 and int(b) < 0:
    m = addit(a[1:], b[1:])
    print('-', end='')
    for i in m:
        print(i, end='')
else:
    m = subtraction(a, b)
    for i in m:
        print(i, end='')
    
print()
finish = datetime.datetime.now()
print(finish - start)
