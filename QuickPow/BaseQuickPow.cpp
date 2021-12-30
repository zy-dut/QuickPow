/*
*	�������㷨��Ӧ��
*	��A^B�������λ����ʾ������
*/
#include <iostream>

using namespace std;

// (a*b)%p = (a%p * b%p)%p;
long long normalPower(long long base, long long power) {
	long long result = 1;
	if (base == 0 || power == 0)
		return 0;	// �����Ǵ��������
	for (int i = 0; i < power; i++) {
		result = result * base;
		result = result % 1000;
	}
	return result % 1000;
}


long long quickPower(long long base, long long power) {
	long long result = 1;
	if (base == 0 || power == 0)
		return 0;	// �����Ǵ��������
	
	//while (power > 0) {
	//	if (power % 2 == 0) {
	//	// ���ָ��Ϊż��
	//		power = power / 2;
	//		base = base * base % 1000;
	//	}
	//	else {
	//	// ���ָ��Ϊ����
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
 // ��λ�������% ��/ �ɵõ�������ٶ�		
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
