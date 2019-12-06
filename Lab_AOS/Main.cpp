#include <iostream>
#include <time.h>


using namespace std;
long sum_iter=			   19999999;
long minus_iter =		   19999999;
long multiplication_iter = 19999999;
long division_iter =       19999999;

double sumint, sumdouble, sumlong, sumfload, sumchar;


double timeSum()
{
	clock_t t;
	int x = 0, a = 0;
	t = clock();
	for (long i = 0; i < sum_iter; ++i) { x = x + a; }
	t = clock() - t;
	return (float(t)) / CLOCKS_PER_SEC;
}
double timeMinus()
{
	clock_t t;
	int x = 0, a = 0;
	t = clock();
	for (long i = 0; i < sum_iter; ++i) { x = x - a; }
	t = clock() - t;
	return (float(t)) / CLOCKS_PER_SEC;
}
double timeDivision()
{
	clock_t t;
	int x = 1, a = 1;
	t = clock();
	for (long i = 1; i < sum_iter; ++i) { x = x / a; }
	t = clock() - t;
	return (float(t)) / CLOCKS_PER_SEC;
}
double timeMultiplication()
{
	clock_t t;
	int x = 1, a = 0;
	t = clock();
	for (long i = 0; i < sum_iter; ++i) { x = x * a; }
	t = clock() - t;
	return (float(t)) / CLOCKS_PER_SEC;
}



double timesum()
{
	clock_t t;
	int x = 0, a = 0;
	t = clock();
	for (long i = 1; i < sum_iter; ++i) { x = x + a; }
	t = clock() - t;
	return (float(t)) / CLOCKS_PER_SEC;
}

template<typename T>
double Sum() {
	T a, b, c;
	clock_t t;
	t = clock();
	for (long i = 1; i < sum_iter; ++i)
	{
		a = 280 + i;
		b = a + i;
		c = a + b;
		
	}
	t = clock() - t;
	return  (float(t)) / CLOCKS_PER_SEC;
}

template<typename T1>
double Minus()
{
	T1 a, b, c;
	clock_t t;
	t = clock();
	for (long i = 1; i < minus_iter; ++i)
	{
		a = 280 - i;
		b = a - i;
		c = a - b;
	}
	t = clock() - t;
	return (float(t)) / CLOCKS_PER_SEC;
}

template<typename T2>
double Multiplication()
{
	T2 a, b, c;
	clock_t t;
	t = clock();
	for (long i = 1; i < multiplication_iter; ++i)
	{
		a = 280 * i;
		b = a * i;
		c = a * b;
	}
	t = clock() - t;
	return  (float(t)) / CLOCKS_PER_SEC;
}
template<typename T3>
double Division()
{
	T3 a, b, c;
	clock_t t;
	t = clock();
	for (long i = 1; i < division_iter; ++i)
	{
		a = 280 / i;
		b = a / i;
		c = a / (b + 1);
	}
	t = clock() - t;
	return  (float(t)) / CLOCKS_PER_SEC;

}
double diagram(double arr[])
{
	int arr_procent[4] = {};
	double time_max = arr[0];
	int i = 0;
	for (int i = 0; i < 4; ++i) 
	{
		if (arr[i] > time_max)
		{
			time_max = arr[i];
		}
	}
	return time_max;
}

void print_x(int procent)
{
		int index = 0, num2 = 0,index2=0;
		int num = procent / 10;
		while (index < num)
		{
			cout << "X";
			++index;
		}
		
		if (num < 10)
		{
			num2 = 10 - num;
			while (index2 < num2)
			{
				cout << " ";
				++index2;
			}
		}
}

void print(double time_sum, double time_minus, double time_multiplication, double time_division,string tipe)
{
	double arr_time[4] = { time_sum,time_minus,time_multiplication,time_division };
	int arr_procent[4] = {};
	double time_max = diagram(arr_time);
	for ( int i = 0; i < 4; ++i){arr_procent[i] = (arr_time[i] / time_max) * 100; }

	char arr_sign[4] = { '+','-','*','/' };
	for (int i = 0; i < 4; ++i)
	{
		cout << arr_sign[i] << "\t" << tipe << "\t" << arr_time[i]<<"\t"; print_x(arr_procent[i]);  cout <<"\t"<< arr_procent[i] << "\t|" << endl;
	}
	cout << "================================================|" << endl;
}

int main() 
{
	cout << "================================================|" << endl;

	int num = 0;
	float time_sum = 0., time_minus = 0.,time_division = 0., time_multiplication = 0.;
	float time_res1 = 0., time_res2 = 0., time_res3 = 0., time_res4 = 0.;
	
	time_sum = timeSum();
	time_minus = timeMinus();
	time_multiplication = timeMultiplication();
	time_division = timeDivision();
	
	
	while (num <= 5)
	{
		switch (num)
		{
		case 1:
			time_res1 = Sum<int>() - time_sum;
			time_res2 = Minus<int>() - time_minus;
			time_res3 = Multiplication<int>() - time_multiplication;
			time_res4 = Division<int>() - time_division;
			print(time_res1, time_res2, time_res3, time_res4, "int");
			break;
		case 2:
			time_res1 = Sum<double>() - time_sum;
			time_res2 = Minus<double>() - time_minus;
			time_res3 = Multiplication<double>() - time_multiplication;
			time_res4 = Division<double>() - time_division;
			print(time_res1, time_res2, time_res3, time_res4, "double");
			
			break;
		case 3:
			time_res1= Sum<long>() - time_sum;
			time_res2 = Minus<long>() - time_minus;
			time_res3 = Multiplication<long>() - time_multiplication;
			time_res4 = Division<long>() - time_division;
			print(time_res1, time_res2, time_res3, time_res4, "long");
			break;
		case 4:
			time_res1 = Sum<float>() - time_sum;
			time_res2 = Minus<float>() - time_minus;
			time_res3 = Multiplication<float>() - time_multiplication;
			time_res4 = Division<float>() - time_division;
			print(time_res1, time_res2, time_res3, time_res4, "float");
			break;
		case 5:
			time_res1 = Sum<char>() - time_sum;
			time_res2 = Minus<char>() - time_minus;
			time_res3= Multiplication<char>() - time_multiplication;
			time_res4 = Division<char>() - time_division;
			print(time_res1, time_res2, time_res3, time_res4, "char");
			break;
		}
		++num;
	}
	
	

	system("pause");
	return 0;
}















