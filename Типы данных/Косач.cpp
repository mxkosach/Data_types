#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
using namespace std;

void binout(int, char = '\n');
void binout(char, char = '\n');
void binout(short, char = '\n');
void binout(long long, char = '\n');
bool realequal(float, float, double = 1e-6);
bool realequal(double, double, double = 1e-12);
enum colors {black, blue, green, cyan, red, magenta, brown, lightgray, darkgray,
lightblue, lightgreen, lightcyan, lightred, lightmagenta, yellow, white};
void getcolor(colors&, colors&);
void setcolor(colors, colors);


int main()
{
	setlocale(LC_ALL, "rus");

	{cout << "=== Задание 1 ================\n";
	cout.flags(0);
	//unsigned char n = 0;
	short n = 0;
	int nmin, nmax;

	int m = sizeof(n);
	cout << "Размер памяти для данных типа "
		<< typeid(n).name() << " = " << m << " байт"
		<< (m > 1 && m < 5 ? "a" : "") << endl;
	while (1)
	{
		n++;
		if (n <= 0)
		{
			nmin = n;
			nmax = --n;
			break;
		}
	}
	cout << "Числовой диапазон данных типа " << typeid(n).name()
		<< ": от " << nmin << " до " << nmax << endl;
	}



	{
		cout << "\n=== Задание 2 ================\n";
		cout.flags(0);
		char a = 100;
		cout << setw(19) << right << 1 * a << " = ";
		binout(a);

		short b = 10000;
		cout << setw(19) << right << b << " = ";
		binout(b);

		int c = 1000000000;
		cout << setw(19) << right << c << " = ";
		binout(c);

		long long d = 1000000000000000000;
		cout << d << " = \n";
		binout(d);
	}


	{
		cout << "\n=== Задание 3 ================\n";
		cout.flags(0);
		short m = 923, n = 21707;
		short a = m & n, b = m | n, c = m ^ n;
		cout << "a = " << m << " & " << n << " = "; binout(a);
		cout << "b = " << m << " | " << n << " = "; binout(b);
		cout << "c = " << m << " ^ " << n << " = "; binout(c);
	}


	{
		cout << "\n=== Задание 4 ================\n";
		cout.flags(0);
		short n = 18294;
		binout(n);
		cout << "Применяем ~, <<5, >>2:\n";
		n = ~n; n = n << 5; n = n >> 2; binout(n);
	}


	{
		cout << "\n=== Задание 5 ================\n";
		cout.flags(0);
		char n = 75;
		binout(n);
		cout << "Устанавливаем четвёртый бит:\n";
		char k = 1;
		k = k << 4;
		n = n | k;
		binout(n);
	}


	{
		cout << "\n=== Задание 6 ================\n";
		cout.flags(0);
		char n = 75;
		binout(n);
		cout << "Сбрасываем шестой бит:\n";
		char k = 1;
		k = k << 6;
		k = ~k;
		n = k & n;
		binout(n);
	}


	{
		cout << "\n=== Задание 7 ================\n";
		cout.flags(0);
		char n = 75;
		binout(n);
		cout << "Инверсия второго и третьего битов:\n";
		char k = 3;
		k = k << 2;
		n = n ^ k;
		binout(n);
	}


	{
		cout << "\n=== Задание 8 ================\n";
		cout.flags(0);
		char n = 75;
		binout(n);
		char k = 1;
		cout << "Бит №5 = " << (n & (k << 5) ? 1 : 0) << endl;
		cout << "Бит №6 = " << (n & (k << 6) ? 1 : 0) << endl;
	}


	{
		cout << "\n=== Задание 9 ================\n";
		cout.flags(0);
		short n = -5718;
		cout << "n = " << n << " = "; binout(n);
	}


	{
		cout << "\n=== Задание 11 ================\n";
		cout.flags(0);
		short k1 = 30, k2 = -1707; short r = k1 | k2;
		cout << k1 << " | " << k2 << " = " << r << endl;
	}


	{
		cout << "\n=== Задание 12 ================\n";
		cout.flags(0);
		short k1 = 30, r1 = ~k1;
		char k2 = -42, r2 = k2 >> 2;
		cout << "~" << k1 << " = " << r1 << endl
			<< (int)k2 << ">>2 = " << (int)r2 << endl;
	}


	{
		cout << "\n=== Задание 14 ================\n";
		cout.flags(0);
		float a = 0, b = 1, h = 0.1, x = a; cout << fixed;
		while (1)
		{
			cout << setw(4) << setprecision(1) << x
				<< setw(12) << setprecision(5) << sin(x) << endl;
			//if (x == b)
			if (realequal(x, b))
				break;
			x += h;
		}
	}


	{
		cout << "\n=== Задание 15 ================\n";
		cout.flags(0);
		short k1 = 71, k2 = -22828, r = (k1 << 6) | k2;
		binout(k1);
		binout(k2);
		binout(k1 << 6);
		binout(r);
		cout << r << endl;
	}


	{
		cout << "\n=== Задание 17 ================\n";
		cout.flags(0);
		double A[8][2] = { //координаты первой вершины
		{8.332, 8.106}, {4.896, 6.199}, {8.17, 7.597}, {7.139, 5.204},
		{5.124, 5.275}, {8.579, 6.968}, {5.407, 4.22}, {2.404, 8.947}
		};
		double B[8][2] = { //координаты второй вершины
		{8.67850930678613, 8.56002914934391}, {5.60855339652141, 8.4173704959059},
		{9.8055120616494, 10.2903844127488},  {6.84963824740223, 5.72287725029507},
		{3.121398739477, 6.93318822554971},   {9.72026276558557, 7.97685854811635},
		{6.10745319602677, 5.54314764999946}, {0.0846151121643115, 9.32509224017352}
		};
		double C[8][2] = { //координаты третьей вершины
		{8.4120538760026, 8.11348519472582},  {3.33111149380031, 7.92527459089338},
		{7.05521670722718, 9.66726687693111}, {6.56995824349977, 5.16954272632506},
		{2.68666624215621, 4.3697905475112},  {8.27143425129894, 8.46858605008262},
		{4.64134712015617, 5.43622256269385}, {0.916870071118119, 7.12739988606733}
		};
		for (int i = 0; i < 8; i++)
		{
			double x, y, ab, bc, ca;
			x = A[i][0] - B[i][0], y = A[i][1] - B[i][1]; ab = x * x + y * y;
			x = B[i][0] - C[i][0], y = B[i][1] - C[i][1]; bc = x * x + y * y;
			x = C[i][0] - A[i][0], y = C[i][1] - A[i][1]; ca = x * x + y * y;
			if (realequal(ab, bc) && realequal(ab, ca))
				cout << "Треугольник №" << i + 1 << " является равносторонним\n";
		}
	}


	{
		cout << "\n=== Задание 18 ================\n";
		cout.flags(0);
		char a = 'z', b = 75;
		cout << a << ' ' << b << ' ' << ' ' << a * 1 << ' ' << b + 0 << endl;
		cout << (char)a << ' ' << (char)b << ' ' << ' ' << (int)a << ' ' << (int)b << endl;
	}


	{
		cout << "\nВыполнить задание 19(y/n)?";
		if (_getch() == 'y')
		{
			cout << "\n=== Задание 19 ================\n";
			cout.flags(0);
			cout << setfill('0');
			char ch = 0;
			for (int i = 0; i < 16; i++)
			{
				cout << setw(3) << i * 16 << ".." << setw(3) << i * 16 + 15 << "| ";
				for (int j = 0; j < 16; j++)
				{
					if (ch == 7 || ch == 9 || ch == 10 || ch == 13 || ch == (char)149)
						cout << ' ';
					else
						cout << ch;
					cout << ' ';
					ch++;
				}
				cout << endl;
			}
			cout << setfill(' ');
		}
	}


	{
		cout << "\nВыполнить задание 20(y/n)?";
		if (_getch() == 'y')
		{
			cout << "\n=== Задание 20 ================\n";
			cout.flags(0);
			const int ns = 32; char S[ns];
			for (int i = 0; i < ns; i++)
				S[i] = '*';
			cout << "Ввод текста в строку S:\n";
			//cin >> S;
			cin.getline(S, ns);
			cout << "Строка S:\n" << S << endl;
			cout << "Символы строки S:\n";
			for (int i = 0; i < ns; i++)
				if (S[i] >= 0 && S[i] <= 31)
					cout << '\\' << (int)S[i];
				else
					cout << S[i];
			cout << "\nsttrlen(S) = " << strlen(S) << endl;
			for (int i = 0; i < ns; i++)
				if (S[i] == 0)
				{
					cout << "Длина строки = " << i;
					break;
				}
		}
	}

	{
		cout << "\nВыполнить задание 21(y/n)?";
		if (_getch() == 'y')
		{
			cout << "\n=== Задание 21 ================\n";
			cout.flags(0);
			const int snum = 10, slen = 16;
			char S1[snum][slen] = {
				"нуль", "один", "два", "три", "четыре",
				"пять", "шесть", "семь", "восемь", "девять"
			};
			int n = 1;
			while (n)
			{
				cout << "n = ";
				cin >> n;
				if (n < 0)
				{
					cout << "минус ";
					n = -n;
				}
				n = n % 10;
				cout << S1[n] << endl;
			}
		}
	}


	{
		cout << "\nВыполнить задание 22(y/n)?";
		if (_getch() == 'y')
		{
			cout << "\n=== Задание 22 ================\n";
			cout.flags(0);
			const int snum = 10, slen = 16;
			char S1[snum][slen] = {
				"нуль","один","два","три","четыре",
				"пять", "шесть", "семь", "восемь", "девять"
			};
			char S2a[snum][slen] = {
				"десять","одиннадцать", "двенадцать", "тринадцать", "четырнадцать",
				"пятнадцать", "шестнадцать","семнадцать","восемнадцать","девятнадцать"
			};
			char S2b[snum][slen] = {
				"двадцать ","тридцать ","сорок ","пятьдесят ","шестьдесят ","семдесят ",
				"восемьдесят ","девяносто "
			};
			char S3[snum][slen] = {
				"сто ","двести ", "триста ","четыреста ","пятьсот ",
				"шестьсот ","семьсот ","весемьсот ","девятьсот "
			};
			const int ns = 64; char s[ns];
			int n = 1;
			while (n)
			{
				cout << "n = ";
				cin >> n;
				strcpy_s(s, "");
				if (n < 0)
				{
					strcpy_s(s, "минус ");
					n = -n;
				}
				int n1 = n % 10, n2 = n / 10 % 10, n3 = n / 100 % 10;
				if (n3 > 0)
					strcat_s(s, S3[n3 - 1]);
				if (n2 == 1)
					strcat_s(s, S2a[n1]);
				else
					if (n2 > 1)
						strcat_s(s, S2b[n2 - 2]);
				if (n1 > 0 && n2 != 1)
					strcat_s(s, S1[n1]);
				cout << s << endl;
			}

		}
	}


	{
		cout << "\n=== Задание 23 ================\n";
		cout.flags(0);
		int b1 = 15 < 0xF, b2 = 0x25, res;
		cout << "res = " << (res = b1 || b2 && 10) << endl;
	}


	{
		cout << "\n=== Задание 24 ================\n"; cout.flags(0);
		enum coins { penny = 1, nickel = 5, dime = 10, quarter = 25, half = 50, dollar = 100 };
		coins coin1, coin2, coin3;
		coin1 = dime;
		coin2 = nickel;
		coin3 = penny;
		cout << "Один dime равен " << coin1/coin2 << " nickel и "
			<< coin1/coin3 << " penny\n";
		coins C[3];
		C[0] = half;
		C[1] = quarter;
		C[2] = nickel;
		int N[3] = { 74,51,162 }, sum = 0;
		for (int i = 0; i < 3; i++)
			sum += C[i] * N[i];
		cout << "Сумма равна " << sum / dollar << " долларов и " << sum % dollar << " центов\n";

		coin1 = quarter;
		//coin1 = 25; //Ошибка: значение типа "int" нельзя присвоить сущности типа "coins"
		coin2 = dollar;
		//coin2 = "dollar"; //Ошибка: значение типа "const char*" нельзя присвоить сущности типа "coins"
	}


	{
		cout << "\n=== Задание 25 ================\n"; cout.flags(0);
		colors text0, back0;
		getcolor(text0, back0);
		setcolor(lightgreen, yellow);
		cout << "светло-зелёный текст на жёлтом фоне";
		setcolor(text0, back0);
		cout << endl;
		setcolor(lightred, white);
		cout << "светло-красный текст на белом фоне";
		setcolor(text0, back0);
		cout << endl;
		cout << "исходные цвета восстановлены\n";
	}


	{
		cout << "\n=== Задание 26 ================\n"; cout.flags(0);
		char c = 100; int k = 27; float f = 2.7; double d = 6.3198, res;
		res = (f + d) * (c - k);
		cout << "res = " << res<<endl;
	}


	{
		cout << "\n=== Задание 27 ================\n"; cout.flags(0);
		const int nv = 5;
		int V[nv] = { 6,9,4,7,8 }, sum = 0;
		for (int i = 0; i < nv; i++)
			sum += V[i];
		cout << "sum = " << sum << endl;
		cout << "средняя оценка = " << sum / nv << endl;
		cout << "средняя оценка = " << 1. * sum / nv << endl;
		cout << "средняя оценка = " << (double)sum / nv << endl;
	}


	{
		cout << "\n=== Задание 28 ================\n"; cout.flags(0);
		float f = 100.5;
		cout << "f = " << f<<endl;
		cout << (int)f / 6 << ' ' << (int)f / 6 << ' ' << f / 6. << endl;
	}


	{
		cout << "\n=== Задание 29 ================\n"; cout.flags(0);
		char c; short s; int i; float f;
		s = 0x2b72; i = 0x41d57a63;
		cout << "1) " << (int)(c = s) << " ";
		cout << (int)(c = i) << endl;

		i = 0x610d71a3;
		cout << "2) " << (s = i) << endl;

		f = 117.6204;
		cout << "3) " << (int)(c = f) << " ";
		cout << (s = f) << " ";
		cout << (i = f) << endl;

		c = 89; s = 28904; i = 1234512384;
		cout << fixed << setprecision(0) << "4) " << (f = c) << " ";
		cout << (f = s) << " ";
		cout << (f = i) << endl;
	}


	cout << endl; system("pause"); return 0;
}

void binout(int n, char ch)
{
	int nd = sizeof(n) * 8;
	unsigned int m = n;
	unsigned int k = 1;

	for (int i = nd - 1; i >= 0; i--)
	{
		cout << (m & (k << i) ? 1 : 0);
		if (i && i % 8 == 0) cout << ' ';
	}
	cout << ch;
}

void binout(char n, char ch)
{
	int nd = sizeof(n) * 8;
	unsigned char m = n;
	unsigned char k = 1;

	for (int i = nd - 1; i >= 0; i--)
	{
		cout << (m & (k << i) ? 1 : 0);
		if (i && i % 8 == 0) cout << ' ';
	}
	cout << ch;
}

void binout(short n, char ch)
{
	int nd = sizeof(n) * 8;
	unsigned short m = n;
	unsigned short k = 1;

	for (int i = nd - 1; i >= 0; i--)
	{
		cout << (m & (k << i) ? 1 : 0);
		if (i && i % 8 == 0) cout << ' ';
	}
	cout << ch;
}

void binout(long long n, char ch)
{
	int nd = sizeof(n) * 8;
	unsigned long long m = n;
	unsigned long long k = 1;

	for (int i = nd - 1; i >= 0; i--)
	{
		cout << (m & (k << i) ? 1 : 0);
		if (i && i % 8 == 0) cout << ' ';
	}
	cout << ch;
}

bool realequal(float a, float b, double e)
{
	if (abs(a - b) < e)
		return true;
	else
		return false;
}

bool realequal(double a, double b, double e)
{
	if (abs(a - b) < e)
		return true;
	else
		return false;
}

void getcolor(colors& text, colors& background) 
{
	CONSOLE_SCREEN_BUFFER_INFO sbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
	int n = sbi.wAttributes;
	text = (colors)(n % 16); background = (colors)(n / 16 % 16);
}

void setcolor(colors text, colors background) 
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
