#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int main()
{
    vector<int> a(1000);
    int i = 1;
    generate(a.begin(), a.end(), [&i]() {return i++; });

    cout << a[0] << "\n";

    auto rng = default_random_engine{};
    shuffle(a.begin(), a.end(), rng);

    cout << a[0] << "\n";

    stack<int> b;
    for (int i = 0; i < 500; i++) {
        b.push(a[2*i]);
    }
    for (int i = 0; i < 500; i++) {
        a[2 * i] = b.top();
        b.pop();
    }

    cout << a[0] << "\n";

    for (int i = 0; i < 1000; i++) {
        a[i] += ((rand()%1000) - 500);
    }
    
    cout << a[0] << "\n";

    set<int> nums(a.begin(), a.end());
    cout << nums.size();
    
}

