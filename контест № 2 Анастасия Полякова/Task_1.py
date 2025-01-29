n = int(input())  # количество элементов в списке
a = [int(i) for i in range(n)]
print(a)  # вывод исходного неотсортированного списка

# Сама сортировка методом "пузырька"
for i in range(n-1):
    for j in range(n-1-i):
        if a[j] > a[j+1]:
            a[j], a[j+1] = a[j+1], a[j]

print(a)  # вывод отсортированного списка