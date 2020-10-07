#include <vector>
#include <iostream>
#include <assert.h>

template<class T>
void print_vector(std::vector<T> q)
{
    for (int i = 0; i < q.size(); i++) {
        int k = q[i];
        for (int j = 0; j < q.size(); j++) {
            if (j == k) {
                std::cout << "#";
            } else {
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool is_diagonally_away(int x1, int y1, int x2, int y2)
{
    assert(x1 != x2 && y1 != y2);
    int xdiff = std::max(x1, x2) - std::min(x1, x2);
    return y1 + xdiff == y2 || y1 - xdiff == y2;
}

bool is_valid(std::vector<int> q, int i, int k)
{
    // (i, k) position of new queen
    int row = i;
    int col = k;
    for (int j = 0; j < i; j++) {
        // (j, q[j])
        int other_row = j;
        int other_col = q[j];
        if (col == other_col
                || row == other_row
                || is_diagonally_away(row, col, other_row, other_col)) {
            return false;
        }
    }
    return true;
}

void nqueens(std::vector<int> q, int i)
{
    int n = q.size();

    if (i == n) {
        print_vector(q);
    }

    for (int k = 0; k < n; k++) {
        if (is_valid(q, i, k)) {
            q[i] = k;
            nqueens(q, i + 1);
        };
    }
}

int main()
{
    int n = 8;
    std::vector<int> q(n, -1);
    nqueens(q, 0);
}
