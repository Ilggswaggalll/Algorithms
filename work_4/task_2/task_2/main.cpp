#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int prefixCount = 0;
    bool isEndOfWord = false;

    ~TrieNode() {
        for (auto& pair : children)
            delete pair.second;
    }
};

class Trie {
private:
    TrieNode* root;

    // Рекурсивное удаление слова
    bool removeWord(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        if (depth == word.size()) {
            if (!node->isEndOfWord)
                return false; // слово не найдено

            node->isEndOfWord = false;
            return node->children.empty(); // если нет дочерей, можно удалить этот узел
        }

        char ch = word[depth];
        TrieNode* child = node->children[ch];
        if (!child)
            return false; // слово не найдено

        bool shouldDeleteChild = removeWord(child, word, depth + 1);

        if (shouldDeleteChild) {
            delete child;
            node->children.erase(ch);
        }

        node->prefixCount--;
        return node->children.empty() && !node->isEndOfWord;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch])
                node->children[ch] = new TrieNode();
            node = node->children[ch];
            node->prefixCount++;
        }
        node->isEndOfWord = true;
    }

    bool search(const string& word) const {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch))
                return false;
            node = node->children.at(ch);
        }
        return node->isEndOfWord;
    }

    void remove(const string& word) {
        removeWord(root, word, 0);
    }

    int countWordsWithPrefix(const string& prefix) const {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->children.count(ch))
                return 0;
            node = node->children.at(ch);
        }
        return node->prefixCount;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");

    cout << "До удаления:\n";
    cout << "Слово 'app' найдено? " << (trie.search("app") ? "Да" : "Нет") << endl;

    trie.remove("app");

    cout << "После удаления:\n";
    cout << "Слово 'app' найдено? " << (trie.search("app") ? "Да" : "Нет") << endl;
    cout << "Слово 'apple' найдено? " << (trie.search("apple") ? "Да" : "Нет") << endl;

    return 0;
}

