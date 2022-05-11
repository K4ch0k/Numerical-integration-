#include <stdio.h>
#include <windows.h>
#include <math.h>

double Calculation(double x)	//	Расчет функции
{
	return pow(cos(sqrt(x)), 2) + x;
}

int main(int argc, char** argv) {
	system("title Lab1.2 #24");
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	int a = 2;		//	Начало отрезка, на котором находится интеграл
	int b = 9;		//	Конец отрезка, на котором находится интеграл
	int n;			//	Число разбиений
	double h;		//	Шаг разбиения
	double ah;		//	Узлы разбиения
	double* M;		//	Массив разбиений
	double* Mres;	//	Массив результатов
	double res = 0;	//	Ответ задания
	int flag = 0;	//	Флаг
	int j = 0;		//

	printf("Показывать результат каждого шага разбиения? (1 - Да; 0 - Нет) :");
	while (scanf("%d", &flag) != 1)
	{
		printf("Не удалось прочитать переменную, повторите попытку\n");
		scanf("%*[^\n]");
	}
	system("cls");

	Mres = (double*)malloc(sizeof(double) * 12);
	for (n = 10; n <= 640; n *= 4)
	{
		M = (double*)malloc(sizeof(double) * n + 1);
		h = (b - a) / (double)n;
		ah = a;
		res = 0;

		if (flag)
		{
			printf("Отрезок интеграла: [%d, %d]\n", a, b);
			printf("Число разбиений: %d\n", n);
			printf("Шаг: %f\n\n", h);
		}

		for (int i = 0; i <= n; i++)
		{
			M[i] = Calculation(ah);
			if (i != 0 && i != n)
				res += M[i];

			if (flag)
			{
				printf("%3d\\ Для узла %f : %f \n", i + 1, ah, M[i]);
			}
			ah += h;
		}

		res = h * (((M[0] + M[n]) / 2) + res);
		Mres[j] = res;
		j++;
		Mres[j] = (double)n;
		j++;
		Mres[j] = (double)h;
		j++;

		if (flag)
		{
			printf("\nРезультат: %f\nФункция: cos(sqrt(x))^2 + x\n\n", res);
			system("pause");
			system("cls");
		}
	}

	printf("Отрезок интеграла: [%d, %d]\n", a, b);
	printf("Функция: cos(sqrt(x))^2 + x\n\n");
	for (int i = 0; i < j; i += 3)
	{
		printf("Определенный интеграл для %3.1f разбиений\nС шагом: %f\nРавен: %f \n\n", Mres[i + 1], Mres[i + 2], Mres[i]);
	}

	system("pause");
	return 0;
}