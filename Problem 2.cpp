#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int x1, x2, x3, x4;
    cin >> x1;
    cin >> x2;
    cin >> x3;
    cin >> x4;
    
    int minx, maxx;

    cout << (minx = min(min(x1, x2), min(x3, x4)));
    cout << (maxx = max(max(x1, x2), max(x3, x4)));

    int x5;
    cin >> x5;

    if (x5 > maxx) {
        x5 = maxx;
    }
    else if(x5 < minx) {
        x5 = minx;
    }

}

