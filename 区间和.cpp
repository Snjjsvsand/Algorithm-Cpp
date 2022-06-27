#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 3e5 + 10;
int n, m;
int a[N], s[N];

vector<pair<int, int>> add, query;
vector<int> alls; // allsֵΪ�����±꣬���±���Ϊ�������±��Ӧ��ӳ����������

int find( int x ) {
	int l = 0, r = alls.size()-1;
	while (l<r) {
		int mid = l + r >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;
}


int main() {
	cin >> n >> m;

	while (n--) {
		int x, c;
		cin >> x >> c;
		add.push_back({x, c});
		alls.push_back(x);
	}

	while (m--) {
		int l, r;
		cin >> l >> r;
		alls.push_back(l) , alls.push_back(r);
		query.push_back({l , r});
	}

	sort(alls.begin() , alls.end());
	alls.erase(unique(alls.begin() , alls.end()) , alls.end());

	for (int i = 0;i < add.size();i++) {
		//�൱�ڰ���ɢ���±�ӳ����������±꣨��ɢ���±����
		int index = find(add[i].first); // �ҳ�l , r , x����alls���±� (alls���±���������) , index��find�����б�ͳһ��һ��a[index]�������a[0]��
		a[index] += add[i].second;
	}

	for (int i = 1;i <= alls.size();i++) {
		s[i] = s[i - 1] + a[i];
	}

	for (int i = 0;i < query.size();i++) {
		int l = find(query[i].first), r = find(query[i].second);
		cout << s[r] - s[l - 1] << endl;
	}

	return 0;
}