// Umairah binti Mohamed Azhar
// 22011792
//count paths
#include <iostream>
using namespace std;

int numberOfPaths(int m, int n) {

    if (m == 1 || n == 1)
        return 1;


    //sum the paths coming from the cell above (m-1, n)
    //and the cell to the left (m, n-1)
    return numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1);
}

int main() {
    int m = 3;
    int n = 3;
    int res = numberOfPaths(m, n);
    cout << res << endl;
    return 0;
}
