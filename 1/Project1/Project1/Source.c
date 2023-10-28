#include < Windows.h >
#include < stdio.h >

#define LEN 100
int main() {
	char str[LEN], rts[LEN], slovo[LEN], perslov[LEN];
	int i, k, p, m, n, r, s;
	SetConsoleCP(1251); //установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); //установка кодовой страницы win-cp 1251 в поток вывода
	for (i = 0; i < LEN; ++i) { //заполняем все массивы нулями
		str[i] = 0;
		rts[i] = 0;
		slovo[i] = 0;
		perslov[i] = 0;
	}
	char c;
	int j = 0;
	while ((c = getchar()) != '\n') { //ввод масива со строки + задаем размер второму массиву
		str[j] = c;
		rts[j] = c;
		++j;
	}
	for (k = 0; k < j; ++k) { //переворачиваем массив (str --> rts)
		rts[j - k - 1] = str[k];
	}
	printf("Перевернутая строка: %s\n", rts);
	printf("Длина твоего шедевра: %d\n", j);
	rts[j] = ' '; //переводим слово из первого массива во второй массив (rts --> slovo)
	rts[j + 1] = 'ᵔ';
	r = 0;
	m = 0;
	while (rts[r] != 'ᵔ') {
		if (rts[r] != ' ') {
			slovo[m] = rts[r];
			++m;
			++r;
		}
		else {
			++r;
			for (s = 0; s < m; ++s) { //переворачиваем массив (str --> rts)
				perslov[m - s - 1] = slovo[s];
			}
			printf("%s ", perslov);
			m = 0;
			for (i = 0; i < LEN; ++i) {
				slovo[i] = 0;
				perslov[i] = 0;
			}
		}
	}
}