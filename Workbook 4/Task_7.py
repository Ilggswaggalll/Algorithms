numbers = [86, 90, 27, 29, 38, 30, 40]
hash_table = [[] for _ in range(7)]


def hash_function(value):
    return value % 7


def insert_into_hash_table(value):
    index = hash_function(value)
    hash_table[index].append(value)


for number in numbers:
    insert_into_hash_table(number)

print("Хэш-таблица:", hash_table)
