#include <iostream>

using namespace std;

int main() {

	int a, b, v;
	cin >> a >> b >> v;

	int day = (v - b - 1) / (a - b) + 1;

	cout << day << endl;

	return 0;
}

/*
�� v��ŭ �ö󰬴ٸ�
���������� (v - b) ��ŭ �ö� ����
(v - b) ������ �Ϸ翡 (a - b) ��ŭ �ö����Ƿ�
yesterday = (v - b) / (a - b)
�̶� yesterday + 1�� ��������(�������� �ö� �Ÿ� (v - b)�� �������� ��������Ƿ�),
���࿡ yesterday�� ����������ٸ�, ���� �㿡 �̲����� �Ÿ� b�� ���� �ʾҴٸ� �� �ö��� ���̹Ƿ�
�̶��� yesterday�� + 1�� ���� �ʴ´�.
�̶� yesterday�� ���ڿ� 1�� ���ָ� ������ ������ �������� �����Ƿ�
���ڿ� 1�� ���� �� yesterday + 1�� ���ش�.
https://yahohococo.tistory.com/28
*/