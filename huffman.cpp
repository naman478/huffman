#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct HuffmanNode {
    char data;
    unsigned frequency;
    HuffmanNode *left, *right;

    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->frequency > r->frequency;
    }
};

class Huffman {
private:
    unordered_map<char, string> huffmanCodes;
    HuffmanNode* root;

    void generateCodes(HuffmanNode* root, string str) {
        if (!root) return;
        if (root->data != '$') huffmanCodes[root->data] = str;
        generateCodes(root->left, str + "0");
        generateCodes(root->right, str + "1");
    }

public:
    Huffman() : root(nullptr) {}

    void buildHuffmanTree(string text) {
        unordered_map<char, unsigned> freq;
        for (char c : text) freq[c]++;

        priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

        for (auto pair : freq) {
            pq.push(new HuffmanNode(pair.first, pair.second));
        }

        while (pq.size() != 1) {
            HuffmanNode *left = pq.top(); pq.pop();
            HuffmanNode *right = pq.top(); pq.pop();

            HuffmanNode *top = new HuffmanNode('$', left->frequency + right->frequency);
            top->left = left;
            top->right = right;
            pq.push(top);
        }

        root = pq.top();
        generateCodes(root, "");
    }

    string encode(string text) {
        string encoded = "";
        for (char c : text) {
            encoded += huffmanCodes[c];
        }
        return encoded;
    }

    string decode(string encoded) {
        string decoded = "";
        HuffmanNode* current = root;
        for (char bit : encoded) {
            if (bit == '0') current = current->left;
            else current = current->right;

            if (!current->left && !current->right) {
                decoded += current->data;
                current = root;
            }
        }
        return decoded;
    }
};

int main() {
    Huffman huffman;
    string text = "this is an example for huffman encoding";
    
    huffman.buildHuffmanTree(text);
    
    string encoded = huffman.encode(text);
    cout << "Encoded: " << encoded << endl;
    
    string decoded = huffman.decode(encoded);
    cout << "Decoded: " << decoded << endl;
    
    return 0;
}
