#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool containdigit(string s) {
	bool y = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			y = true;
			break;
		}
	}
	return y;
}

string lower(string s) {
	for (int i = 0; i < s.size(); i++) {
		s[i] = tolower(s[i]);
	}
	return s;
}

pair<int, int> convert(string s) {
	pair<int, int> p;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			sum += (s[i] - '0');
		}
		else {
			sum += (s[i] - 'a');
		}
	}
	p.first = sum;
	return p;
}

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

	cout << count_if(a.begin(), a.end(), containdigit) << "\n";

	transform(a.begin(), a.end(), a.begin(), lower);
	
	vector<pair<int, int>> pa(a.size());
	int i = 0;
	transform(a.begin(), a.end(), pa.begin(), [&i](string& p) {pair<int, int> s = convert(p); s.second = i; i++; return s; });
	
	sort(pa.begin(), pa.end(), [&](pair<int, int> one, pair<int, int> two) {return one.first < two.first; });
	
	

}
