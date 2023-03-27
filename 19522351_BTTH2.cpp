#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, k;
	vector<char> type;
	vector<int> after;

	cout << "Nhap n = "; cin >> n;
	cout << "Nhap m = "; cin >> m;
	cout << "Nhap k = "; cin >> k;
	for (int i = 0; i < n; i++) {
		char c;
		cout << "Nguoi " << i + 1 << " la nguoi hoang phi (W) / tiet kiem (E): ";
		cin >> c;
		type.push_back(c);
	}
	for (int i = 0; i < m; i++) {
		int t;
		cout << "So nuoc con lai trong binh thu " << i + 1 << ": ";
		cin >> t;
		after.push_back(t);
	}

	vector<int> before(m, k);
	vector<int> choose(m, 0);

	for (int i = 0; i < n; i++) {
		if (type[i] == 'E') {
			int jmin = 0;
			while (before[jmin] == 0)
				jmin++;
			int min = before[jmin];
			for (int j = jmin + 1; j < m; j++)
				if (before[j] < min) {
					min = before[j];
					jmin = j;
				}
			before[jmin]--;
			choose[i] = jmin;
		}
		else {
			int max = before[0];
			int jmax = 0;
			for (int j = 1; j < m; j++)
				if (before[j] > max) {
					max = before[j];
					jmax = j;
				}
			if (max == 0) {
				cout << "Khong du nuoc cho moi nguoi uong!" << endl;
				return -1;
			}
			before[jmax]--;
			choose[i] = jmax;
		}
	}

	vector<int> pos(m, 0);
	for (int i = 0; i < m; i++)
		pos[i] = i;

	for (int i = 0; i < m - 1; i++)
		for (int j = i + 1; j < m; j++)
			if (after[i] > after[j]) {
				swap(after[i], after[j]);
				swap(pos[i], pos[j]);
			}

	for (int i = 0; i < m; i++)
		cout << pos[choose[i]] + 1 << " ";
}