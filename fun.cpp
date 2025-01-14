#include <iostream>
#include <string>
using namespace std;


string mult(const string& b) {
	string result = "";
	int l = b.length();
	int ost = 0;
	for (int i = l - 1; i >= 0; i--) {
		int a = b[i] - '0'; //преобразование в int
		int res = a + a + ost;
		result += (res % 10) + '0'; //преобразование обратно в строку
		ost = res / 10; //формирование остатка
	}
	if (ost > 0) //если остался остаток, добавляем его в начало строки
		result += ost + '0';
	reverse(result.begin(), result.end());//переворачиваем строку, т.к результат формировался в обратном порядке
	return result;
}

//разделение строки на подстроки по 9 цифр и занесение их в массив
void massiv(long int a[], string s, int len, int part) {
	string sub;
	//k-номер подстроки j-номер элемента в массиве i - позиция первого символа в подстроке
	int k = 1, i = len - 9, j = 0;
	while (k <= part) { //выделяем подстроку из 9 цифр с конца 
		//если последняя подстрока содержит меньше 9 символов, то берем с 0 символа все оставшиеся
		sub = i >= 0 ? s.substr(i, 9) : s.substr(0, 9 + i);
		a[j] = atoi(sub.c_str());    //преобразование в число
		//c_str() преобразует строку в символьный массив с последним символом \0)
		j++; k++;
		i -= 9;
	}
}
//преобразование числа в строку с добавлением 0 до 9 разрядов
string tostr(long int m) {
	string s = to_string(m);
	s.insert(0, 9 - s.length(), '0');
	return s;
}
//функция для сложения
string sumnum(long int a[], long int b[], int part) {
	int ost = 0;
	string result = "";
	//сложение и перенос разрядов
	for (int i = 0; i <= part; i++) {
		long int sum = (a[i] + b[i]) + ost; //сумма чисел
		a[i] = sum % 1000000000;
		ost = sum / 1000000000; //перенос
	}
	//формируем строку без ведущих нулей
	bool zero = true;
	for (int i = part; i >= 0; i--) {
		string block = tostr(a[i]);
		if (zero) {
			int przero = 0;
			//вычисление индекса ненулевого элемента
			while (przero < block.size() && block[przero] == '0') {
				++przero;
			}
			if (przero != block.size()) {
				result += block.substr(przero);//добавление части без 0
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
	//формируем строку без ведущих нулей
	bool zero = true;
	for (int i = part - 1; i >= 0; i--) {
		string block = tostr(c[i]);
		if (zero) {
			int przero = 0;
			//вычисление индекса ненулевого элемента
			while (przero < block.size() && block[przero] == '0') {
				++przero;
			}
			if (przero != block.size()) {
				resdif += block.substr(przero);//добавление части без 0
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
