import json
from collections import defaultdict


def json_to_hash_table():
    json_data = json.loads(open("data.json").read())
    hash_table = defaultdict(list)

    for item in json_data:
        hash_table[item["id"]].append(item["name"])

    return dict(hash_table)


print("Хэш-таблица:", json_to_hash_table())
