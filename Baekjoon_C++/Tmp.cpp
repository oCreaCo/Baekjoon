#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <bitset>

using namespace std;



int main(void)
{
	unsigned int tmp = 0x00c3;

	cout << tmp << endl;
	cout << bitset<16>(tmp) << endl;

	tmp += 256;

	cout << tmp << endl;
	cout << bitset<16>(tmp) << endl;

	cout << int('F') << '	' << int ('f') << endl;

	return 0;
}