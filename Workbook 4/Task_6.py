def han_b(n, source, target, auxiliary):
    if n == 1:
        print(f"Переместить диск 1 с {source} на {target}")
        return

    han_b(n - 1, source, auxiliary, target)
    print(f"Переместить диск {n} с {source} на {target}")
    han_b(n - 1, auxiliary, target, source)


n = int(input())
han_b(n, 'A', 'C', 'B')