class HashNode:
    #Класс для узла связанного списка

    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None


class HashTable:
    #Класс хэш-таблицы
    HASH_MUL = 31
    HASH_SIZE = 128

    def __init__(self):
        self.table = [None] * self.HASH_SIZE

    def hash_function(self, key):
        """Функция хэширования"""
        if isinstance(key, int):
            return key % self.HASH_SIZE
        elif isinstance(key, str):
            h = 0
            for char in key:
                h = h * self.HASH_MUL + ord(char)
            return h % self.HASH_SIZE

    def add(self, key, value):
        #Метод для добавления элемента
        index = self.hash_function(key)
        new_node = HashNode(key, value)

        if not self.table[index]:
            self.table[index] = new_node  # type: ignore
        else:
            current = self.table[index]
            while current:
                if current.key == key:
                    while current.next:
                        current = current.next
                    current.next = new_node
                    return
                if not current.next:
                    current.next = new_node
                    return
                current = current.next

    def search(self, key):
        #Метод для поиска элемента по ключу
        index = self.hash_function(key)
        current = self.table[index]
        values = []

        while current:
            if current.key == key:
                values.append(current.value)
            current = current.next

        if not values:
            return None

        return values[0] if len(values) == 1 else values

    def remove(self, key, value=None):
        #Метод для удаления элемента
        index = self.hash_function(key)
        current = self.table[index]
        prev = None

        while current:
            if current.key == key:
                if value is None or current.value == value:
                    if prev:
                        prev.next = current.next
                    else:
                        self.table[index] = current.next
                    return True
                prev = current
            current = current.next
        return False


phone_book = HashTable()

phone_book.add("Иванов", "123-456-789")
phone_book.add("Петров", "987-654-321")
phone_book.add("Сидоров", "555-555-555")
phone_book.add("Иванов", "111-222-333")

print("Поиск номера по фамилии Иванов:", phone_book.search("Иванов"))

phone_book.remove("Иванов", "123-456-789")
print("Поиск номера по фамилии Иванов после удаления:", phone_book.search("Иванов"))
