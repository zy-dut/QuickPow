/*
*	矩阵快速幂算法的应用
*	斐波那契数列的应用
*/


#include <iostream>
#include <vector>
using namespace std;

// 函数声明
vector<vector<int>> matrix_multiply(vector<vector<int>>& a, vector<vector<int>>& b);
vector<vector<int>> matrix_pow(vector<vector<int>> base, int pow);


// Fibonacci Number: 0 1 1 2 3 5... F(n+2) = F(n)+F(n+1)
int fib(int n) {
	if (n < 2) {
		return n;
	}
	vector<vector<int>> phi{ {1,1},{1,0} }; // Fibonacci数列状态转移矩阵
	vector<vector<int>> res = matrix_pow(phi, n - 1);
	return res[0][0];

}

vector<vector<int>> matrix_pow(vector<vector<int>> base, int pow) {
	vector<vector<int>> ret{ {1,0},{0,1} };
	while (pow > 0) {
		if (pow & 1) {
		// 位运算
			ret = matrix_multiply(ret, base);
		}
		pow = pow>> 1;
		base = matrix_multiply(base, base);
	}
	return ret;
}


vector<vector<int>> matrix_multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
	vector<vector<int>> c{ {0,0},{0,0} };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
		}
	}
	return c;
}


int main() {
	int value = fib(14);
	cout << value << endl;
	return 1;
}

