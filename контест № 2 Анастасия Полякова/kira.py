def solve():
    n = int(input())  # Количество бизнесов
    incomes = list(map(int, input().split()))  # Доходы бизнесов

    ruined = [0] * n  # Массив, в котором храним день разорения для каждого бизнеса
    alive = [True] * n  # Массив, отслеживающий жив ли бизнес

    day = 1  # Начинаем с первого дня
    while True:
        to_remove = []  # Список индексов бизнесов, которые нужно разорить в этот день

        # Проверяем все бизнесы
        for i in range(n):
            if alive[i]:
                left = (i - 1) % n
                right = (i + 1) % n
                # Если бизнес приносит меньше, чем оба соседа, то его разоряют
                if incomes[i] < incomes[left] and incomes[i] < incomes[right]:
                    to_remove.append(i)

        if not to_remove:
            # Если никто не разорился, рынок достиг равновесия
            break
        
        # Разоряем выбранные бизнесы
        for i in to_remove:
            alive[i] = False
            ruined[i] = day
        
        # Если осталось только 2 живых бизнеса, рынок также достиг равновесия
        if sum(alive) <= 2:
            break

        day += 1  # Переходим к следующему дню

    print(" ".join(map(str, ruined)))


solve()
