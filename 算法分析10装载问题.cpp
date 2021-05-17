#include<iostream>
#include<vector>
 
using namespace std;
 
int max(int, int);
int main() {
 
	int n, b;//物品的种类和重量限制
	int i, j;//辅助变量
	cin >> n >> b;
 
	vector<int>w(n);
	vector<int>v(n);
	for (i = 0; i < n; ++i) {
		cin >> w[i] >> v[i];
	}
	vector<vector<int>> F(n, vector<int>(b+1));
 
	//对F[i][j]进行赋值，F[i][j]代表前i种物品重量不超过j的最大价值，0<=i<n,0<=j<=b；
	for (j = 0; j < b + 1; ++j) {
		F[0][j] = (j / w[0])*v[0];//可以放置的第一种物品的数量*价值
	}
	for (i = 1; i < n; ++i) {
		for (j = 0; j < b + 1; ++j) {
			//分为两种情况：放置第i件物品和不放第i件物品
			if (j < w[i])
				F[i][j] = F[i - 1][j];
			else
				F[i][j] = max(F[i - 1][j], F[i][j - w[i]] + v[i]);
		}
	}
	cout << "the max value is: " << F[n - 1][b] << endl;
}
int max(int v1,int v2){
	if (v1 < v2)return v2;
	else return v1;
}
