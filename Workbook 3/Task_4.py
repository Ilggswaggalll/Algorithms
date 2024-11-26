import datetime


def mul(a, b):
    num_1 = a[::-1]
    num_2 = b[::-1]

    results = [0] * (len(num_1) + len(num_2))

    for i in range(len(num_1)):
        for j in range(len(num_2)):
            results[i + j] += int(num_1[i]) * int(num_2[j])
            print(results[i + j], i, j)

    carry = 0
    for i in range(len(results)):
        results[i] += carry
        print(results[i], end=' ')
        carry = results[i] // 10
        results[i] %= 10
        print(carry, results[i])

    while len(results) > 1 and results[-1] == 0:
        results.pop()

    return int(''.join(map(str, results[::-1])))


# тест
a = input("Первое большое число: ")
b = input("Второе большое число: ")
start = datetime.datetime.now()
print(mul(a, b))
finish = datetime.datetime.now()
print("Микросекунд прошло:", finish.microsecond - start.microsecond)