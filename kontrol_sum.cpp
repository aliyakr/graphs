#include <iostream>
int  N = 10;//размер массива
using namespace std;

//warning!!! очень много проверочек

int firstgr[10][10] =		//начальный граф
{
	{0,1,0,1,0,0,0,0,0,0},
	{1,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,0,1,0},
	{1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,0,0,0,1},
	{0,0,0,0,1,0,0,0,0,1},
	{0,0,1,0,0,0,0,1,1,0},
	{0,0,0,0,0,0,1,0,1,0},
	{0,0,1,0,0,0,1,1,0,0},
	{0,0,0,0,1,1,0,0,0,0}
};
int sum = 0; //итоговая сума связных графов
int kontrol[10] = { 0 }, //контрольный граф
work1[10] = { 0 },//рабочий граф 1
work2[10] = { 0 };//рабочий граф 2

void coutkontrol()
{
	cout << "kontrol= {";
	for (int i = 0; i < N; i++)
	{
		cout << kontrol[i] << ",";
	}
	cout << "}\n";
}

void coutwork1()
{
	cout << "work1=   {";
	for (int i = 0; i < N; i++)
	{
		cout << work1[i] << ",";
	}
	cout << "}\n";
}

void coutwork2()
{
	cout << "work2=   {";
	for (int i = 0; i < N; i++)
	{
		cout << work2[i] << ",";
	}
	cout << "}\n";
}

void first_out()
{
	cout << "FIRST array:\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << firstgr[i][j] << " ";
		}
		cout << "\n";
	}
}

int manu()
{
	int number;
	cout << " ____________________________\n";
	cout << "|           MANU             |\n";
	cout << "|____________________________|\n";
	cout << "|1)output the initial matrix |\n";
	cout << "|2)enter a new matrix        |\n";
	cout << "|3)calculate                 |\n";
	cout << "|4)goodbye                   |\n";
	cout << "|____________________________|\n";
	cout << "selected action:";
	cin >> number;
	return number;
}

void new_array()
{
	cout << "size array: ";
	cin >> N;
	cout << "enter a new array:\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> firstgr[i][j];
		}
	}
}

void calculation1(int nmbrtstring) {
	cout << "calculation1\n--------------------------\n" << "nmbrtstring=" << nmbrtstring << endl;
	int koef;//этим коэффициентом запоминаем на какой позиции столкнулись с условием
	coutkontrol();
	coutwork1();
	coutwork2();

	bool cycle = false;

	
	for (int i = 0; i < N; i++)
	{
		work1[i] = firstgr[nmbrtstring][i];
	}
	cout << "............................\n";
	coutkontrol();
	coutwork1();
	coutwork2();

	kontrol[nmbrtstring] = 1;

	for (int i = 0; i < N; i++)
	{
		bool flag = false;
		if (work1[i] == 1 && work2[i] == 0 && i != nmbrtstring && work1[i] != kontrol[i])
		{
			cycle = true;
			koef = i;
			for (int j = 0; j < N; j++)
			{
				if (work1[j] == 1)
					work2[j] = 1;
			}
			flag = true;
			for (int k = 0; k < N; k++)
			{
				work1[k] = firstgr[koef][k];
			}
			cout << "............................\n" << "i=" << i << " flag=" << flag << endl;
			coutkontrol();
			coutwork1();
			coutwork2();
		}
		if (flag)
		{
			cout << "flag srabotal\n";
			i = -1;//-1потому что он не заходит в первый элемент масива при обороте цикла, i=1 а не 0

		}
	}

	coutkontrol();
	coutwork1();
	coutwork2();

	for (int i = 0; i < N; i++)
	{
		if (work2[i] == 1)
			kontrol[i] = 1;
		work1[i] = 0;
		work2[i] = 0;
	}


	if (cycle)
		sum++;
	cout << "............................\n" << "sum=" << sum << endl;
	coutkontrol();
	coutwork1();
	coutwork2();
}

void calculation()
{	
	sum = 0;
	int asum = 0;
	for (int i = 0; i < N; i++)
	{
		cout << "=================================\n i=" << i << " sum=" << sum << endl;
		if (kontrol[i] == 0) {
			asum = 0;
			for (int j = 0; j < N; j++)
			{
				asum = asum + firstgr[i][j];
			}
			cout << "asum=" << asum << "\n";
			if (asum == 0)// елси сумма =0 значит эта вершина одинокая(
			{
				kontrol[i] = 1;
				cout << "odinokay vershina\n";
				sum++;
			}
			else//для не одиноких вершин
			{
				calculation1(i);
			}
		}
	}
	cout << "\nControl sum = " << sum << endl;
}

int goodbye(int znach) {
	cout << "goodbye\n";
	znach = 0;
	return znach;
}

int main()
{
	int znach;
	do
	{
		znach = manu();
		switch (znach)
		{
		case 1:
			first_out();
			break;
		case 2:
			new_array();
			break;
		case 3:
			calculation();
			break;
		case 4:
			znach = goodbye(znach);
			break;
		default:
			system("cls");
			cout << "enter a correct variable again!!!!\n";
			znach = manu();
			break;
		}
		system("pause");
		system("cls");
	} while (znach != 0);

return 0;
}