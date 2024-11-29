def NOD(a, b):
    if a == 0: return b
    if b == 0: return a

    return NOD(a - b, b) if a > b else NOD(a, b - a)


a = int(input())
b = int(input())

print(f"НОД({a}, {b}) = {NOD(abs(a), abs(b))}")
