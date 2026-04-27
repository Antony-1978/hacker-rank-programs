#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;  // number of arrays
    int q;  // number of queries
    cin >> n >> q;

    // store variable-length arrays
    vector<vector<int>> arrays(n);

    for (int i = 0; i < n; i++) {
        int len;  // length of the i-th array
        cin >> len;

        arrays[i].resize(len);

        for (int j = 0; j < len; j++) {
            cin >> arrays[i][j];
        }
    }

    // process queries
    for (int k = 0; k < q; k++) {
        int arrayIndex;
        int elementIndex;
        cin >> arrayIndex >> elementIndex;

        cout << arrays[arrayIndex][elementIndex] << "\n";
    }

    return 0;
}
