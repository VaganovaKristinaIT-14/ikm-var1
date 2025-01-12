#include <iostream>
#include <string>
#include "fun.h"
using namespace std;

int main() {
	setlocale(LC_ALL,"RU");
	string a, b, c;
	cout << "Введите числа А,В,С для подсчёта выражения А+2*В-С (числа более 20 знаков) через пробел " << endl;
	cin >> a >> b >> c;
	int cnt=0; //счетчик проверок
	while (cnt != 4) {
		cnt = 0;
		if (a[0] == '-' || b[0] == '-' || c[0] == '-') {
			cout << "Некорректные данные, числа не могут быть отрицательными.Повторите ввод:" << endl;
			cin >> a >> b >> c;
		}
		else
			cnt++;
		if (isnum(a) == 0 || isnum(b) == 0 || isnum(c) == 0) {
			cout << "Число должно состоять только из цифр.Повторите ввод: " << endl;
			cin >> a >> b >> c;
		}
		else
			cnt++;
		if (a[0] == '0' || b[0] == '0' || c[0] == '0') {
			cout << " Число не должно начинаться с нуля.Повторите ввод: " << endl;
			cin >> a >> b >> c;
		}
		else
			cnt++;
		if (a.size()<=20 || b.size() <= 20 || c.size() <= 20) {
			cout << "Числа должны быть более 20 знаков.Повторите ввод:" << endl;
			cin >> a >> b >> c;
		}
		else
			cnt++;

	}

	

	//2*b
	b = mult(b);
	
	//а+2b
	int lena = a.size(), lenb = b.size(), lenc = c.size();
	//добавляем 0 слева к меньшей строке
	if (lena < lenb) {
		a.insert(0, lenb - lena, '0');
	}
	else if (lena > lenb) {
		b.insert(0, lena - lenb, '0');
	}
	int len = a.size(); //итоговая длинна строк
	int part = len % 9 == 0 ? len / 9 : len / 9 + 1; //количество блоков
	long int* masa= new long int[part + 1]();
	long int* masb= new long int[part + 1]();
	massiv(masa, a, len, part);//делим на блоки
	massiv(masb, b, len, part);
	string ressum = sumnum(masa, masb, part); //считаем результат
	

	//Вычитание С
	len = ressum.size();
	int k = 3; //если числа равны
	//добавляем 0 слева к меньшей строке
	if (lenc < len) {
		c.insert(0, len - lenc, '0');
		k = 1; //а+2b больше
	}
	else if (lenc > len) {
		ressum.insert(0, lenc - len, '0');
		k = 2; //с больше
	}
	else {
		for (int i = 0; i < len; i++) { //поразрядное сравнение чисел
			if (ressum[i] > c[i]) {
				k = 1;
				break;
			}
			if (c[i] > ressum[i]) {
				k = 2;
				break;
			}
		}
	}
	if (k == 3)
		cout << 0; 
	else {
		len = ressum.size(); //итоговая длинна(длины строк уже уравняли)
	}
	part = len % 9 == 0 ? len / 9 : len / 9 + 1;
	long int* masres = new long int[part]();
	long int* masc = new long int[part]();
	long int* masfin = new long int[part]();
	massiv(masres, ressum, len, part);
	massiv(masc, c, len, part);
	string fin;
	if (k == 1)
		fin = dif(masres, masc, masfin, part);
	else
		fin = dif(masc,masres, masfin, part);
	if (k == 2) 
		cout <<"-";
	if (!isnum(fin)) {
	cout << "0";
}
	cout << "A+2*B-C = " <<fin;
return 0;
}
