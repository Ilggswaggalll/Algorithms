#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int prefixCount = 0;   // Кол-во слов, проходящих через этот узел
    bool isEndOfWord = false;

    ~TrieNode() {
        for (auto& pair : children)
            delete pair.second;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    // Вставка слова в дерево
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

    // Подсчет количества слов с данным префиксом
    int countWordsWithPrefix(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->children[ch])
                return 0;
            node = node->children[ch];
        }
        return node->prefixCount;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");
    trie.insert("bat");
    trie.insert("batch");
    trie.insert("banana");

    cout << "Слов с префиксом 'app': " << trie.countWordsWithPrefix("app") << endl;     // 2
    cout << "Слов с префиксом 'ba': " << trie.countWordsWithPrefix("ba") << endl;       // 3
    cout << "Слов с префиксом 'cat': " << trie.countWordsWithPrefix("cat") << endl;     // 0

    return 0;
}

