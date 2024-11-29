def two_sum(nums, target):
    #Функция для поиска индексов двух чисел, сумма которых равна target
    hash_table = {}

    for index, num in enumerate(nums):
        complement = target - num

        if complement in hash_table:
            return [hash_table[complement], index]

        hash_table[num] = index

    return None


nums = [-1, 2, 3, 4, 7]
target = 5
result = two_sum(nums, target)

if result:
    print(f"Индексы: {result}")
else:
    print("Пара с заданной суммой не найдена.")
