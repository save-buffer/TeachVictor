#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

int main()
{
	vector<string> a;
	string p;
	do {
		getline(cin, p);
		a.push_back(p);
	} while (p != "");
	a.pop_back();

	if (all_of(a.begin(), a.end(), [](string& i) {return (i.size() >= 4); })) {
		cout << "ALL\n";
	}
	else if (any_of(a.begin(), a.end(), [](string& i) {return (i.size() >= 4); })) {
		cout << "SOME\n";
	}
	else if (none_of(a.begin(), a.end(), [](string& i) {return (i.size() >= 4); })) {
		cout << "NONE\n";
	}

	for_each(a.begin(), a.end(), [](string& i) {cout << i.back() << "\n"; });

	cout << count_if(a.begin(), a.end(), [](string& i) {return count_if(i.begin(), i.end(), isdigit); }) << "\n";

	transform(a.begin(), a.end(), a.begin(), [](string& i) {transform(i.begin(), i.end(), i.begin(), tolower); return NULL; });

	vector<pair<int, int>> pa(a.size());
	int i = 0;
	transform(a.begin(), a.end(), pa.begin(), [&i](string& p) {pair<int, int> s; s.first = accumulate(p.begin(), p.end(), 0);  s.second = i; i++; return s; });

	sort(pa.begin(), pa.end(), [&](pair<int, int> one, pair<int, int> two) {return one.first < two.first; });
	const auto val = make_pair(75, 0);

	auto c = lower_bound(pa.begin(), pa.end(), val, [](const pair<int, int>& p1, const pair<int, int>& p2) {return p1.first < p2.first; });
	if (pa.end() == c) {
		cout << "NONE";
	}
	else {
		cout << a[c->second];
	}
}

