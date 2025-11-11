#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(Node* left, Node* right) {
        return (left->freq > right->freq);
    }
};

void printCodes(Node* root, string code) {
    if (!root)
        return;

    if (!root->left && !root->right)
        cout << root->data << " : " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void HuffmanCodes(vector<char> &data, vector<int> &freq) {
    priority_queue<Node*, vector<Node*>, compare> pq;

    for (int i = 0; i < data.size(); i++)
        pq.push(new Node(data[i], freq[i]));

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    printCodes(pq.top(), "");
}

int main() {
    vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    cout << "Huffman Codes:\n";
    HuffmanCodes(data, freq);

    return 0;
}
