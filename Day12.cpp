#include <bits/stdc++.h>
using namespace std;

struct Piece {
    vector<vector<int>> base;
    vector<vector<vector<int>>> variants;
};

struct Region {
    int width, height;
    vector<vector<int>> board;
    vector<int> count;
};

vector<vector<int>> rotate90(const vector<vector<int>>& m) {
    int h = m.size(), w = m[0].size();
    vector<vector<int>> r(w, vector<int>(h));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            r[j][h - 1 - i] = m[i][j];
    return r;
}

vector<vector<int>> flip(const vector<vector<int>>& m) {
    vector<vector<int>> r = m;
    for (auto& row : r) reverse(row.begin(), row.end());
    return r;
}

void generateVariants(Piece& p) {
    set<vector<vector<int>>> seen;
    vector<vector<int>> cur = p.base;

    for (int i = 0; i < 4; i++) {
        if (seen.insert(cur).second) p.variants.push_back(cur);
        auto f = flip(cur);
        if (seen.insert(f).second) p.variants.push_back(f);
        cur = rotate90(cur);
    }
}

bool canPlace(const vector<vector<int>>& board,
              const vector<vector<int>>& piece,
              int x, int y) {
    for (int i = 0; i < piece.size(); i++)
        for (int j = 0; j < piece[0].size(); j++)
            if (piece[i][j] && board[x+i][y+j]) return false;
    return true;
}

void place(vector<vector<int>>& board,
           const vector<vector<int>>& piece,
           int x, int y, int val) {
    for (int i = 0; i < piece.size(); i++)
        for (int j = 0; j < piece[0].size(); j++)
            if (piece[i][j]) board[x+i][y+j] = val;
}

bool solve(Region& r, const vector<Piece>& pieces) {
    bool done = true;
    for (int c : r.count)
        if (c > 0) done = false;
    if (done) return true;

    for (int i = 0; i < pieces.size(); i++) {
        if (r.count[i] == 0) continue;

        for (auto& v : pieces[i].variants) {
            for (int x = 0; x + v.size() <= r.height; x++) {
                for (int y = 0; y + v[0].size() <= r.width; y++) {
                    if (canPlace(r.board, v, x, y)) {
                        place(r.board, v, x, y, i+1);
                        r.count[i]--;
                        if (solve(r, pieces)) return true;
                        r.count[i]++;
                        place(r.board, v, x, y, 0);
                    }
                }
            }
        }
        return false;
    }
    return false;
}


int main() {
    ifstream in("input.txt");

    int numPieces;
    in >> numPieces;
    vector<Piece> pieces(numPieces);

    for (int i = 0; i < numPieces; i++) {
        int h, w;
        in >> h >> w;
        pieces[i].base.resize(h, vector<int>(w));
        for (int r = 0; r < h; r++) {
            string s; in >> s;
            for (int c = 0; c < w; c++)
                pieces[i].base[r][c] = (s[c] == '#');
        }
        generateVariants(pieces[i]);
    }

    int regions;
    in >> regions;
    int valid = 0;

    while (regions--) {
        Region r;
        in >> r.width >> r.height;
        r.board.assign(r.height, vector<int>(r.width, 0));
        r.count.resize(numPieces);
        for (int i = 0; i < numPieces; i++) in >> r.count[i];

        if (solve(r, pieces)) valid++;
    }

    cout << "Regiones válidas: " << valid << endl;
    return 0;
}