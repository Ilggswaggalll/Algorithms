n1 = [int(elem) for elem in input("Первое большое число: ")[::-1]]
n2 = [int(elem) for elem in input("Второе большое число: ")[::-1]]


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


def simple_mul(n1, n2):
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

finish_res = "".join(map(str, simple_mul(n1, n2)))
while finish_res[0] == "0":
    finish_res = finish_res[1:]
print(finish_res)