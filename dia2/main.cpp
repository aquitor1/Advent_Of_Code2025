#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
    long long value;
    Node* left;
    Node* right;

    Node(long long v) : value(v), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root = nullptr;

    void insert(long long v) {
        root = insertRec(root, v);
    }

    long long sumInOrder() {
        return sumInOrderRec(root);
    }

private:
    Node* insertRec(Node* node, long long v) {
        if (!node) return new Node(v);
        if (v < node->value)
            node->left = insertRec(node->left, v);
        else if (v > node->value)
            node->right = insertRec(node->right, v);
        return node; // duplicados ignorados
    }

    long long sumInOrderRec(Node* node) {
        if (!node) return 0;
        return sumInOrderRec(node->left) + node->value + sumInOrderRec(node->right);
    }
};


vector<long long> generarPPenRango(long long a, long long b) {
    vector<long long> result;

    int lenA = to_string(a).size();
    int lenB = to_string(b).size();

    for (int totalLen = lenA; totalLen <= lenB; totalLen++) {
        if (totalLen % 2 != 0) continue;
        int half = totalLen / 2;

        long long pMin = pow(10, half - 1);
        long long pMax = pow(10, half) - 1;

        long long factor = pow(10, half) + 1;

        long long low = ceil((long double)a / factor);
        long long high = b / factor;

        if (high < low) continue;

        if (low < pMin) low = pMin;
        if (high > pMax) high = pMax;

        if (high < low) continue;

        for (long long p = low; p <= high; p++) {
            long long n = p * factor;
            if (n >= a && n <= b) result.push_back(n);
        }
    }

    return result;
}

vector<pair<long long,long long>> parseRanges(const string& line) {
    vector<pair<long long,long long>> ranges;
    string temp = "";
    for (char c : line) {
        if (c == ',') {
            size_t pos = temp.find('-');
            if (pos != string::npos) {
                long long a = stoll(temp.substr(0, pos));
                long long b = stoll(temp.substr(pos+1));
                if (a > b) swap(a, b);
                ranges.push_back({a, b});
            }
            temp = "";
        } else temp += c;
    }
    if (!temp.empty()) {
        size_t pos = temp.find('-');
        if (pos != string::npos) {
            long long a = stoll(temp.substr(0, pos));
            long long b = stoll(temp.substr(pos+1));
            if (a > b) swap(a, b);
            ranges.push_back({a, b});
        }
    }
    return ranges;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Uso: ./day02 input.txt\n";
        return 1;
    }

    ifstream f(argv[1]);
    if (!f.is_open()) {
        cout << "No se pudo abrir el fichero.\n";
        return 1;
    }

    string line;
    getline(f, line);

    auto ranges = parseRanges(line);

    BST arbol;

    for (auto& r : ranges) {
        long long a = r.first;
        long long b = r.second;

        vector<long long> nums = generarPPenRango(a, b);
        for (long long n : nums) {
            arbol.insert(n);
        }
    }

    long long total = arbol.sumInOrder();
    cout << total << endl;

    return 0;
}

