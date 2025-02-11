def find_merged_sequence_element(x):
    """
    Находит x-ый элемент объединенной последовательности A и B, где A[i] = i^2, B[i] = i^3.

    Args:
        x (int): Индекс искомого элемента в объединенной последовательности.

    Returns:
        int: Значение x-ого элемента объединенной последовательности.
    """

    a_index = 1
    b_index = 1
    merged_index = 1

    while merged_index < x:
        a_val = a_index ** 2
        b_val = b_index ** 3

        if a_val < b_val:
            a_index += 1
        elif b_val < a_val:
            b_index += 1
        else:  # a_val == b_val: избегаем дубликатов
            a_index += 1
            b_index += 1

        merged_index += 1

    # Находим значения A и B для текущих индексов
    a_val = a_index ** 2
    b_val = b_index ** 3
    return min(a_val, b_val)

x = int(input())
result = find_merged_sequence_element(x)
print(result)