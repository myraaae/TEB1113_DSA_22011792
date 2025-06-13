// Umairah binti Mohamed Azhar
// 22011792
// sort matrix

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortMatrix(vector<vector<int>>& mat) {
    vector<int> temp;
    
    //put in temp vector
    for (auto& row : mat) {
        for (int x : row) {
            temp.push_back(x);
        }
    }
    
    //sort
    sort(temp.begin(), temp.end());
    
    int k = 0;
    for (auto& row : mat) {
        for (int& x : row) {
            x = temp[k++];
        }
    }
}

int main() {
    vector<vector<int>> mat{{5, 4, 7}, {1, 3, 8}, {2, 9, 6}};
    
    sortMatrix(mat);
    
    for (auto& row : mat) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}
