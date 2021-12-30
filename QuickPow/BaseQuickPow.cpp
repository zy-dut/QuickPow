/*
*	快速幂算法的应用
*	求A^B的最后三位数表示的整数
*/
#include <iostream>

using namespace std;

// (a*b)%p = (a%p * b%p)%p;
long long normalPower(long long base, long long power) {
	long long result = 1;
	if (base == 0 || power == 0)
		return 0;	// 不考虑此情况计算
	for (int i = 0; i < power; i++) {
		result = result * base;
		result = result % 1000;
	}
	return result % 1000;
}


long long quickPower(long long base, long long power) {
	long long result = 1;
	if (base == 0 || power == 0)
		return 0;	// 不考虑此情况计算
	
	//while (power > 0) {
	//	if (power % 2 == 0) {
	//	// 如果指数为偶数
	//		power = power / 2;
	//		base = base * base % 1000;
	//	}
	//	else {
	//	// 如果指数为奇数
	//		power = power - 1;
	//		result = result * base % 1000;
	//		power = power / 2;
	//		base = base * base % 1000;
	//	}
	//}

	while (power > 0) {
		if (power % 2 != 0) {
			result = result * base % 1000;
		}
		power = power / 2;
		base = base * base % 1000;
 // 用位运算代替% 和/ 可得到更快的速度		
	}

	return result % 1000;
}


void test01() {
	long long base, power;
	base = 2;
	power = 100;
	cout << normalPower(base, power) << endl;
}

void test02() {
	long long base, power;
	base = 2;
	power = 100;
	cout << quickPower(base, power) << endl;
}
//
//int main() {
//	//test01();
//	test02();
//	return 0;
//}
