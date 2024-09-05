#include <iostream>
using namespace std;

int main() {
    int c1, m1, c2, m2, c3, m3;

    // Read input: capacities and milk amounts for the three buckets
    cin >> c1 >> m1;
    cin >> c2 >> m2;
    cin >> c3 >> m3;

    // Perform 100 pours in a cyclic manner
    for (int i = 0; i < 100; i++) {
        if (i % 3 == 0) {
            // Pour from bucket 1 to bucket 2
            int pour = min(m1, c2 - m2);
            m1 -= pour;
            m2 += pour;
        } else if (i % 3 == 1) {
            // Pour from bucket 2 to bucket 3
            int pour = min(m2, c3 - m3);
            m2 -= pour;
            m3 += pour;
        } else {
            // Pour from bucket 3 to bucket 1
            int pour = min(m3, c1 - m1);
            m3 -= pour;
            m1 += pour;
        }
    }

    // Output the final amount of milk in each bucket
    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3 << endl;

    return 0;
}
