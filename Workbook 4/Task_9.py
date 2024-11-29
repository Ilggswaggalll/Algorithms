def count_characters(input):
    char_count = {}

    for char in input:
        if char in char_count:
            char_count[char] += 1
        else:
            char_count[char] = 1

    for char, count in char_count.items():
        print(f"{char}: {count}")



input_string = input("Введите строку: ")
count_characters(input_string)
