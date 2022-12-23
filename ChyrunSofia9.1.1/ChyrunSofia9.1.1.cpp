// ChyrunSofia9.1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab_09_1.cpp
// < Чирун Софія >
// Лабораторна робота № 9.1.1
// Послідовний пошук в масиві структур
// Варіант 18

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;
enum Student { KN, IT, ME, FI, TN };
string studentStr[] = { "Комп’ютерні науки", "Інформатика" , "Матем. та екон.", "Фізика та інформ.", "Трудове навчання" };
struct Specialist
{
	string prizv;
	int course;
	Student student;
	double fizyk;
	double matem;
	double progr;
	double serbl;
};

void Create(Specialist* p, const int N);
void Print(Specialist* p, const int N);
void Serbal(Specialist* p, const int N);
double MinSerbal(Specialist* p, const int N);
int Dobre(Specialist* p, int j, const int N, int d);
int main()
{ 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	int N;
	cout << "Введіть N: "; cin >> N;
	Specialist* p = new Specialist[N];
	Create(p, N);
	Serbal(p, N);
	Print(p, N);
	cout << endl << "Мінімaльний середній бал: " << MinSerbal(p, N) << endl;
	cout << endl << "Кількість оцінок добре: ";
	cout << endl << "Фізика: " << Dobre(p, 1, N, 0);
	cout << endl << "Математика: " << Dobre(p, 2, N, 0);
	cout << endl << "Інформатика: " << Dobre(p, 3, N, 0);
	cout << endl << endl;
	return 0;
}

void Create(Specialist* p, const int N)
{
	int student;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); 
		cin.sync(); 
		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс: "; cin >> p[i].course;
		cout << " спеціальність (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> student;
		p[i].student = (Student)student;
		cout << " фізика: "; cin >> p[i].fizyk;
		cout << " математика: "; cin >> p[i].matem;
		cout << " інофрматика : "; cin >> p[i].progr;
		cout << endl;
	}
}

void Serbal(Specialist* p, const int N)
{
	double s = 0;
	for (int i = 0; i < N; i++)
	{
		s = p[i].fizyk + p[i].matem+ p[i].progr;
		p[i].serbl = s / 3;
		s = 0;
	}
}

double MinSerbal(Specialist* p, const int N)
{
	double s = 1000;
	for (int i = 0; i < N; i++)
	{
		if (p[i].serbl < s)
			s = p[i].serbl;
	}
	return s;
}

int Dobre(Specialist* p, int j, const int N, int d)
{
	double s = 4;
	for (int i = 0; i < N; i++)
		switch (j)
		{
		case 1:

			if (p[i].fizyk == s)
			    d++;
			break;
		case 2:
			if (p[i].matem == s)
				d++;
			break;
		case 3:
			if (p[i].progr == s)
				d++; 
			break;
		}
	return d;
}

void Print(Specialist* p, const int N)
{
	cout << "=============================================================================================="
		<< endl;
	cout << "| № | Прізвище | Курс |   Спеціальність   | Фізика | Математика | Інформатика | Середній бал |"
		<< endl;
	cout << "----------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "|" << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].course << " "
			<< "| " << setw(17) << left << studentStr[p[i].student] << " "
			<< "| " << setw(6) << setprecision(2) << fixed << right << p[i].fizyk << " "
			<< "| " << setw(10) << setprecision(2) << fixed << right << p[i].matem << " "
			<< "| " << setw(11) << setprecision(2) << fixed << right << p[i].progr << " | " ;
		cout << setw(12) << setprecision(2) << fixed << right << p[i].serbl << " | " << endl;
	}
	cout << "==============================================================================================" << endl;
	cout << endl;
}
