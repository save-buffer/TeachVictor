#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> x;

    for (int i = 0; i < 4; i++) {
        int c;
        cin >> c;
        x.push_back(c);
    }

    int minx, maxx;

    cout << (minx = *min_element(x.begin(), x.end())) << "\n";
    cout << (maxx = *max_element(x.begin(), x.end())) << "\n";

    int x5;
    cin >> x5;

    x5 = max(min(x5, maxx), minx);
    cout << x5;
}

