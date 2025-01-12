#include <iostream>
#include <string>
using namespace std;


string mult(const string& b) {
	string result = "";
	int l = b.length();
	int ost = 0;
	for (int i = l - 1; i >= 0; i--) {
		int a = b[i] - '0'; //�������������� � int
		int res = a + a + ost;
		result += (res % 10) + '0'; //�������������� ������� � ������
		ost = res / 10; //������������ �������
	}
	if (ost > 0) //���� ������� �������, ��������� ��� � ������ ������
		result += ost + '0';
	reverse(result.begin(), result.end());//�������������� ������, �.� ��������� ������������ � �������� �������
	return result;
}

//���������� ������ �� ��������� �� 9 ���� � ��������� �� � ������
void massiv(long int a[], string s, int len, int part) {
	string sub;
	//k-����� ��������� j-����� �������� � ������� i - ������� ������� ������� � ���������
	int k = 1, i = len - 9, j = 0;
	while (k <= part) { //�������� ��������� �� 9 ���� � ����� 
		//���� ��������� ��������� �������� ������ 9 ��������, �� ����� � 0 ������� ��� ����������
		sub = i >= 0 ? s.substr(i, 9) : s.substr(0, 9 + i);
		a[j] = atoi(sub.c_str());    //�������������� � �����
		//c_str() ����������� ������ � ���������� ������ � ��������� �������� \0)
		j++; k++;
		i -= 9;
	}
}
//�������������� ����� � ������ � ����������� 0 �� 9 ��������
string tostr(long int m) {
	string s = to_string(m);
	s.insert(0, 9 - s.length(), '0');
	return s;
}
//������� ��� ��������
string sumnum(long int a[], long int b[], int part) {
	int ost = 0;
	string result = "";
	//�������� � ������� ��������
	for (int i = 0; i <= part; i++) {
		long int sum = (a[i] + b[i]) + ost; //����� �����
		a[i] = sum % 1000000000;
		ost = sum / 1000000000; //�������
	}
	//��������� ������ ��� ������� �����
	bool zero = true;
	for (int i = part; i >= 0; i--) {
		string block = tostr(a[i]);
		if (zero) {
			int przero = 0;
			//���������� ������� ���������� ��������
			while (przero < block.size() && block[przero] == '0') {
				++przero;
			}
			if (przero != block.size()) {
				result += block.substr(przero);//���������� ����� ��� 0
				zero = false;
			}
		}
		else {
			result += block;
		}
	}
	return result.empty() ? "0" : result;
}

string dif(long int* a, long int* b, long int* c, int part) {
	string resdif = "";
	for (int i = 0; i < part; i++) {
		c[i] = a[i] - b[i];
		if (c[i] < 0) {
			c[i] += 1000000000;
			if (i + 1 < part)
				a[i + 1]--;
		}
	}
	//��������� ������ ��� ������� �����
	bool zero = true;
	for (int i = part - 1; i >= 0; i--) {
		string block = tostr(c[i]);
		if (zero) {
			int przero = 0;
			//���������� ������� ���������� ��������
			while (przero < block.size() && block[przero] == '0') {
				++przero;
			}
			if (przero != block.size()) {
				resdif += block.substr(przero);//���������� ����� ��� 0
				zero = false;
			}
		}
		else {
			resdif += block;
		}
	}
	return resdif.empty() ? "0" : resdif;

}
bool isnum(string a) {
	string dig = "0123456789";
	for (char c : a) {
		if (dig.find(c) == string::npos) {
			return false;
		}
	}
	return true;
}