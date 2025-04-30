#include <iostream>
#include <string>
#include <vector>

struct Node {
    std::string name;
    std::vector<std::string> phoneNumbers;
    Node* left;
    Node* right;
};
void addRecord(Node*& node, const std::string& name, const std::string& phoneNumber) {
    if (node == nullptr) {
        node = new Node{ name, {phoneNumber}, nullptr, nullptr };
        return;
    }

    if (node->name == name) {
        node->phoneNumbers.push_back(phoneNumber);
    }
    else if (node->name > name) {
        addRecord(node->left, name, phoneNumber);
    }
    else {
        addRecord(node->right, name, phoneNumber);
    }
}

void printRecords(Node* node) {
    if (node == nullptr) {
        return;
    }

    printRecords(node->left);
    std::cout << "Name: " << node->name << ", Phone Numbers: ";
    for (const auto& number : node->phoneNumbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    printRecords(node->right);
}

Node* searchRecord(Node* node, const std::string& name) {
    if (node == nullptr || node->name == name) {
        return node;
    }

    if (node->name > name) {
        return searchRecord(node->left, name);
    }
    return searchRecord(node->right, name);
}

void deleteRecord(Node*& node, const std::string& name) {
    if (node == nullptr) {
        return;
    }

    if (name < node->name) {
        deleteRecord(node->left, name);
    }
    else if (name > node->name) {
        deleteRecord(node->right, name);
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else {
            Node* temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            node->name = temp->name;
            node->phoneNumbers = temp->phoneNumbers;
            deleteRecord(node->right, temp->name);
        }
    }
}


int main() {
    setlocale(LC_CTYPE, "rus");
    system("color 0A");
    Node* root = nullptr;
    int choice;
    std::string name, phoneNumber;

    do {
        std::cout << "+----------------------------+\n";
        std::cout << "|        МЕНЮ ДЕЙСТВИЙ       |\n";
        std::cout << "+----------------------------+\n";
        std::cout << "| 1 | Добавить запись        |\n";
        std::cout << "| 2 | Найти запись           |\n";
        std::cout << "| 3 | Удалить запись         |\n";
        std::cout << "| 4 | Вывести все записи     |\n";
        std::cout << "| 5 | Выйти                  |\n";
        std::cout << "+----------------------------+\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите имя: ";
            std::cin >> name;
            std::cout << "Введите номер телефона: ";
            std::cin >> phoneNumber;
            addRecord(root, name, phoneNumber);
            break;
        case 2:
            std::cout << "Введите имя для поиска: ";
            std::cin >> name;
            if (Node* record = searchRecord(root, name)) {
                std::cout << "Имя: " << record->name << ", Номера: ";
                for (const auto& number : record->phoneNumbers) {
                    std::cout << number << " ";
                }
                std::cout << std::endl;
            }
            else {
                std::cout << "Запись не найдена.\n";
            }
            break;
        case 3:
            std::cout << "Введите имя, которое нужно удалить: ";
            std::cin >> name;
            deleteRecord(root, name);
            break;
        case 4:
            printRecords(root);
            std::cout << std::endl;
            break;
        case 5:
            std::cout << "Выходим...\n";
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте ещё раз.\n";
        }
    } while (choice != 5);

    return 0;
}
