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


def div_2(n):
    result = []
    carry = 0
    for digit in n:
        current = carry * 10 + digit
        result.append(current // 2)
        carry = current % 2

    while len(result) > 1 and result[0] == 0:
        result.pop(0)

    return result


def le(n1, n2):
    if len(n1) != len(n2):
        return len(n1) < len(n2)

    for d1, d2 in zip(n1, n2):
        if d1 != d2:
            return d1 < d2
    return True


def lt(n1, n2):
    if len(n1) != len(n2):
        return len(n1) < len(n2)

    for d1, d2 in zip(n1, n2):
        if d1 != d2:
            return d1 < d2
    return False


def mul(n1, n2):
    n1, n2 = normalization(n1, n2)
    n1, n2 = n1[::-1], n2[::-1]
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
        res = add(buffer[::-1] + [0] * j, res)
    return zero_deleting(res)

def divide_half(a, b):
    if b == [0]:
        raise ValueError("Деление на ноль!")
    if lt(a, b):
        return [0], a

    low, high = [0], a
    while le(low, high):
        mid = div_2(add(low, high))
        product = mul(mid, b)

        if product == a:
            return mid, [0]
        elif lt(product, a):
            low = add(mid, [1])
        else:
            high = sub(mid, [1])

    return high, sub(a, mul(high, b))


n1 = [int(elem) for elem in input("Первое оч большое двоичное число: ")]
n2 = [int(elem) for elem in input("Второе оч большое двоичное число: ")]

quotient, remainder = divide_half(n1, n2)
quotient, remainder = "".join(map(str, quotient)), "".join(map(str, remainder))
print(f"Частное: {quotient}, Остаток: {remainder}")