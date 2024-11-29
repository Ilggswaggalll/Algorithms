import time


def simple_sum(n1, n2):
    if len(n1) < len(n2):
        n1 = [0] * (len(n2) - len(n1)) + n1
    else:
        n2 = [0] * (len(n1) - len(n2)) + n2

    shift = 0
    res = []

    for i in range(len(n1) - 1, -1, -1):
        res.append((n1[i] + n2[i] + shift) % 10)
        shift = (n1[i] + n2[i] + shift) // 10

    if shift:
        res.append(shift)
    return res[::-1]


def mul(n1, n2):
    if len(n1) < len(n2):
        n1.extend([0] * (len(n2) - len(n1)))
    else:
        n2.extend([0] * (len(n1) - len(n2)))

    res = [0] * (len(n1) + len(n2))
    shift = 0

    for j in range(len(n2)):
        buffer = [0] * (len(n1) + len(n2))
        for i in range(len(n1)):
            buffer[i] = (n1[i] * n2[j] + shift) % 10
            shift = (n1[i] * n2[j] + shift) // 10
        if shift:
            buffer[i + 1] += shift
            shift = 0
        res = simple_sum(buffer[::-1] + [0] * j, res)
    return res

def normalization(n1, n2):
    if len(n1) < len(n2):
        n1 = [0] * (len(n2) - len(n1)) + n1
    else:
        n2 = [0] * (len(n1) - len(n2)) + n2
    return n1, n2


def zero_deleting(n: list):
    while len(n) > 1 and n[0] == 0:
        n.pop(0)
    return n


def shift_n_div(n: list, a: int):
    if len(n) <= a:
        return [0], n[-a::]
    return n[:-a], n[-a::]


def add(n1: list, n2: list):
    n1, n2 = normalization(n1, n2)
    shift = 0
    res = []
    for i in range(len(n1) - 1, -1, -1):
        res.append((n1[i] + n2[i] + shift) % 10)
        shift = (n1[i] + n2[i] + shift) // 10
    if shift:
        res.append(shift)
    return res[::-1]


def sub(n1: list, n2: list):
    n1, n2 = normalization(n1, n2)
    n1, n2 = n1[::-1], n2[::-1]
    borrow = 0
    res_sub = []
    for i in range(len(n1)):
        diff = n1[i] - n2[i] - borrow
        if diff < 0:
            diff += 10
            borrow = 1
        else:
            borrow = 0
        res_sub.append(diff)
    return zero_deleting(res_sub[::-1])


def zero_mul(n: list, a: int):
    return n + [0] * a


def karatsuba(x: list, y: list):
    if len(zero_deleting(x)) == 1 or len(zero_deleting(y)) == 1:
        return list(map(int, str(int("".join(map(str, x))) * int("".join(map(str, y))))))

    n = max(len(zero_deleting(x)), len(zero_deleting(y)))
    half = n // 2

    high_x, low_x = shift_n_div(x, half)
    high_y, low_y = shift_n_div(y, half)

    z0 = karatsuba(low_x, low_y)
    z1 = karatsuba(high_x, high_y)
    z2 = karatsuba(add(high_x, low_x), add(high_y, low_y))

    return add(
        add(zero_mul(z1, 2 * half), zero_mul(sub(sub(z2, z1), z0), half)),
        z0,
    )

a = input("Первое большое число: ")
b = input("Второе большое число: ")

n1 = [int(i) for i in a]
n2 = [int(i) for i in b]

start_time = time.time()
result1 = "".join(map(str, zero_deleting(mul(n1[::-1], n2[::-1]))))
end_time = time.time()
time_mul = end_time - start_time
print("Результат mul:", result1)
print("Время выполнения mul:", time_mul, "секунд")

start_time = time.time()
result2 = "".join(map(str, karatsuba(n1, n2)))
end_time = time.time()
time_karatsuba = end_time - start_time
print("Результат karatsuba:", result2)
print("Время выполнения karatsuba:", time_karatsuba, "секунд")

speedup = time_mul / time_karatsuba
print("Karatsuba быстрее mul в", speedup, "раз")