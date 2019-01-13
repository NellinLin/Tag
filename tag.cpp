#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <time.h>

void Mas_out(int **a, int n, int m);
int **mas_memory(int n, int m);
void Mas_in(int **a, int n, int m);
int Find_Null(int **a, int n, int m, int z);
void Sdvig_W(int **a, int n, int m);
void Sdvig_S(int **a, int n, int m);
void Sdvig_A(int **a, int n, int m);
void Sdvig_D(int **a, int n, int m);
void Menu(void);
int Sravnenie(int **a, int n, int m);

int main(void) {
	srand(time(NULL));
	setlocale(LC_ALL, ".1251");

	int **a;
	a = mas_memory(4, 4);
	Menu();
	Mas_in(a, 4, 4);
	Mas_out(a, 4, 4);

	char action;
	for (;;) {
		scanf_s("%c", &action);
		if (action == 'q') {
			printf("Вы вышли\n");
				break;
		}
		switch (action) {
		case'w':
			Sdvig_W(a, 4, 4);
			break;
		case 's':
			Sdvig_S(a, 4, 4);
			break;
		case 'a':
			Sdvig_A(a, 4, 4);
			break;
		case'd':
			Sdvig_D(a, 4, 4);
			break;
		//default:
			//printf("\nПопробуйте ещё раз\n");
		}
		//int z = Sravnenie(a, 4, 4);
		if (Sravnenie(a,4,4)== 1) {
			printf("\n\nYOU WIN!!!\n");
			break;
		}
	}

	_getch();
}

int **mas_memory(int n, int m) {
	int **a;
	a = new int*[n];
	for (int i = 0; i < n; i++) a[i] = new int[m];
	return a;
}

void Mas_in(int **a, int n, int m) { //Функция рандомного заполнения 0..15 без повторений

	int i = 0;

	int *b = new int[n*m];
	b[0] = rand() % (n*m);
	while (i < n*m) {
		int t = 0; //номер элемента в массиве
		int x = rand() % (n*m);
		while ((t <= i) && (b[t] != x)) t = t + 1;
		if (t > i) {	//элемент не присутствует в массиве
						//i++;
			b[i++] = x;
		}
	}

	int t = 0;
	for (i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = b[t];
			t++;
		}
	}

	delete[]b;

}

void Mas_out(int **a, int n, int m) {
	for (int i = 0; i < n; i++) {
		printf("+----+----+----+----+\n");
		for (int j = 0; j < m; j++) {
			if (a[i][j]<10 && a[i][j] != 0) printf("| 0%d ", a[i][j]);
			else if (a[i][j] == 0) printf("|    ");
			else printf("| %d ", a[i][j]);
		}
		printf("|\n");
	}
	printf("+----+----+----+----+\n");
}

int Find_Null(int **a, int n, int m, int z) {
	//Если z=0 выводится i, если z=1 выводится j
	int i, j, Ind1, Ind2;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				Ind1 = i;
				Ind2 = j;
				break;
			}
		}
	}
	if (z == 0) return (Ind1);
	else return(Ind2);
}


void Sdvig_W(int **a, int n, int m) {
	int I_Str, I_Sto, c;
	I_Str = Find_Null(a, n, m, 0);
	I_Sto = Find_Null(a, n, m, 1);

	if (I_Str != n - 1) {
		c = a[I_Str][I_Sto];
		a[I_Str][I_Sto] = a[I_Str +1][I_Sto];
		a[I_Str +1][I_Sto] = c;
	}
	else printf("Выберете другое действие\n");
	Mas_out(a, n, m);
}

void Sdvig_S(int **a, int n, int m) {
	int I_Str, I_Sto, c;
	I_Str = Find_Null(a, n, m, 0);
	I_Sto = Find_Null(a, n, m, 1);

	if (I_Str != 0) {
		c = a[I_Str][I_Sto];
		a[I_Str][I_Sto] = a[I_Str-1][I_Sto];
		a[I_Str-1][I_Sto] = c;
	}
	else printf("Выберете другое действие\n");
	Mas_out(a, n, m);
}

void Sdvig_A(int **a, int n, int m) {
	int I_Str, I_Sto, c;
	I_Str = Find_Null(a, n, m, 0);
	I_Sto = Find_Null(a, n, m, 1);

	if (I_Sto != m-1) {
		c = a[I_Str][I_Sto];
		a[I_Str][I_Sto] = a[I_Str][I_Sto+1];
		a[I_Str][I_Sto+1] = c;
	}
	else printf("Выберете другое действие\n");
	Mas_out(a, n, m);
}

void Sdvig_D(int **a, int n, int m) {
	int I_Str, I_Sto, c;
	I_Str = Find_Null(a, n, m, 0);
	I_Sto = Find_Null(a, n, m, 1);

	if (I_Sto != 0) {
		c = a[I_Str][I_Sto];
		a[I_Str][I_Sto] = a[I_Str][I_Sto -1];
		a[I_Str][I_Sto -1] = c;
	}
	else printf("Выберете другое действие\n");
	Mas_out(a, n, m);
}

void Menu(void) {
	printf("Правила игры:\nРасставьте цифры по возрастанию, последняя ячейка должна остаться пустой.");
	printf("\n\nw-сдвиг вперёд\ns-сдвиг вниз\na-сдвиг влево\nd-сдвиг вправо\nq-выход\n\nУдачи :)\n\n");
}

int Sravnenie(int **a, int n, int m) {
	int *b = new int[n*m];
	int i, j, c=0,k=0;
	for (i = 0; i < n*m-1; i++) b[i] = i+1;
	b[n*m-1] = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i][j] == b[k]) c++;
			k++;
		}
	}
	if (c == n*m) return 1;
	else return 0;
}
