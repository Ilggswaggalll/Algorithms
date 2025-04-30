#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


struct HuffmanNode {
    char character;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;
    
    HuffmanNode(char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}
    HuffmanNode(int freq) : character('\0'), frequency(freq), left(nullptr), right(nullptr) {}
};

// Компаратор для приоритетной очереди
struct Compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->frequency > right->frequency;
    }
};


class HuffmanCoding {
private:
    HuffmanNode* root;
    unordered_map<char, string> codes;
    unordered_map<string, char> reverseCodes;
    
    // Вспомогательная функция для построения кодов
    void buildCodesHelper(HuffmanNode* node, string code) {
        if (!node) return;
        
        if (node->character != '\0') {
            codes[node->character] = code;
            reverseCodes[code] = node->character;
            return;
        }
        
        buildCodesHelper(node->left, code + "0");
        buildCodesHelper(node->right, code + "1");
    }
    
    // Удаление дерева (очистка памяти)
    void deleteTree(HuffmanNode* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    
public:
    HuffmanCoding() : root(nullptr) {}
    ~HuffmanCoding() {
        deleteTree(root);
    }
    
    // Построение списка частот
    unordered_map<char, int> buildFrequencyMap(const string& text) {
        unordered_map<char, int> frequencyMap;
        for (char ch : text) {
            frequencyMap[ch]++;
        }
        return frequencyMap;
    }
    
    // Построение дерева Хаффмана
    void buildHuffmanTree(const unordered_map<char, int>& frequencyMap) {
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;
        
        // Создаем узлы для каждого символа
        for (auto& pair : frequencyMap) {
            minHeap.push(new HuffmanNode(pair.first, pair.second));
        }
        
        // Строим дерево
        while (minHeap.size() > 1) {
            HuffmanNode* left = minHeap.top(); minHeap.pop();
            HuffmanNode* right = minHeap.top(); minHeap.pop();
            
            HuffmanNode* newNode = new HuffmanNode(left->frequency + right->frequency);
            newNode->left = left;
            newNode->right = right;
            
            minHeap.push(newNode);
        }
        
        root = minHeap.top();
        buildCodes();
    }
    
    // Построение кодов
    void buildCodes() {
        codes.clear();
        reverseCodes.clear();
        buildCodesHelper(root, "");
    }
    
    // Сжатие текста
    string compress(const string& text) {
        if (text.length() < 2) return "";
        
        string compressed;
        for (char ch : text) {
            compressed += codes[ch];
        }
        return compressed;
    }
    
    // Дешифровка
    string decompress(const string& compressed) {
        string currentCode;
        string decompressed;
        
        for (char bit : compressed) {
            currentCode += bit;
            if (reverseCodes.find(currentCode) != reverseCodes.end()) {
                decompressed += reverseCodes[currentCode];
                currentCode.clear();
            }
        }
        
        return decompressed;
    }
    
    // Расчет коэффициента сжатия
    double calculateCompressionRatio(const string& original, const string& compressed) {
        if (original.empty() || compressed.empty()) return 0.0;
        
        double originalSize = original.length() * 8.0;
        double compressedSize = compressed.length();
        return (1.0 - compressedSize / originalSize) * 100.0;
    }
    
    // Вывод частот символов
    void printFrequencies(const string& text) {
        auto frequencyMap = buildFrequencyMap(text);
        vector<pair<char, int>> sortedFrequencies(frequencyMap.begin(), frequencyMap.end());
        
        // Сортируем по убыванию частоты
        sort(sortedFrequencies.begin(), sortedFrequencies.end(),
            [](const pair<char, int>& a, const pair<char, int>& b) {
                if (a.second == b.second) return a.first < b.first;
                return a.second > b.second;
            });
        
        cout << "полученный список:" << endl;
        for (auto& pair : sortedFrequencies) {
            double freq = static_cast<double>(pair.second) / text.length();
            cout << fixed << setprecision(6) << "(" << freq << ") --> " << pair.first << " ";
        }
        cout << endl;
    }
};

int main() {
    HuffmanCoding huffman;
    
    cout << "Введите текст, содержащий не менее двух символов..." << endl;
    string text;
    getline(cin, text);
    
    if (text.length() < 2) {
        cout << "Текст должен содержать не менее двух символов." << endl;
        return 0;
    }
    
    // Выводим частоты символов
    huffman.printFrequencies(text);
    
    // Строим дерево
    cout << "Построим дерево..." << endl;
    auto frequencyMap = huffman.buildFrequencyMap(text);
    huffman.buildHuffmanTree(frequencyMap);
    cout << "    ... (дерево построено)" << endl;
    
    // Сжимаем текст
    cout << "---" << endl;
    cout << "Приступим к кодировке введенного текста..." << endl;
    string compressed = huffman.compress(text);
    cout << "Сод перед Вами... " << compressed << endl;
    
    // Вычисляем коэффициент сжатия
    double ratio = huffman.calculateCompressionRatio(text, compressed);
    cout << "Оэффициент сжатия: " << fixed << setprecision(4) << ratio << "%" << endl;
    
    // Дешифруем
    cout << "Ранее было зашифровано... " << text << endl;
    string decompressed = huffman.decompress(compressed);
    cout << "Расшифровано..." << decompressed << endl;
    
    return 0;
}
