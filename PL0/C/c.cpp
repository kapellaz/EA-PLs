#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> vec; 
    int num;
    while (cin >> num) {
       vec.push_back(num);
    }
    sort(vec.begin(), vec.end());

    for(int i : vec) cout << i << endl;
    return 0;
}