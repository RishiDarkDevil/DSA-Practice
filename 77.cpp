#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> discharge;

int main() {
	int n, m;
	cin >> n >> m;

	int arr[n], treat[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < n; ++i)
		cin >> treat[i];

	int ans[m] = {0}; // the answer
	int filled_till[m] = {0}; // Absolute dates
	set<int> vacant; // the vacant centres

	for (int i = 0; i < n; ++i) {
		// Vacate all hospitals where the patient's treatment is over when ith patient arrives
		for (auto it = discharge.begin(); it != discharge.end();) {
			if (it->first > arr[i]) 
				break;
			else {
				for (auto &centre: it->second) {
					vacant.insert(centre);
				}
			}
			auto it_cp = it;
			it++;
			discharge.erase(it_cp);
		}
		// ith patient arrives after the person who was there in i%m th centre left
		if (filled_till[i%m] <= arr[i]) {
			filled_till[i%m] = arr[i] + treat[i];
			discharge[filled_till[i%m]].push_back(i%m);
			ans[i%m]++;
			vacant.erase(i%m);
		}
		else {
			// if no centre vacant patient leaves
			if (vacant.size() == 0) continue;
			//if vacant search for (i%m, m-1] if hospital is vacant --> If no vacant then choose the first centre in [0, i%m)
			auto it = vacant.upper_bound(i%m);
			if (it != vacant.end()) {
				filled_till[*it] = arr[i] + treat[i];
				discharge[filled_till[*it]].push_back(*it);
				ans[*it]++;
				vacant.erase(*it);
			}
			else {
				filled_till[*vacant.begin()] = arr[i] + treat[i];
				discharge[filled_till[*vacant.begin()]].push_back(*vacant.begin());
				ans[*vacant.begin()]++;
				vacant.erase(*vacant.begin());
			}
		}
	}

	for (int i = 0; i < m; ++i)
		cout << ans[i] << " ";
}