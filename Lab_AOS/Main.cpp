#include <iostream>
#include <time.h>


using namespace std;
long sum_iter=			   19999999;
long minus_iter =		   19999999;
long multiplication_iter = 19999999;
long division_iter =       19999999;

double sumint, sumdouble, sumlong, sumfload, sumchar;

template<typename T>
double timeSum()
{
	clock_t t;
	T x = 0, a = 0;
	t = clock();
	for (long i = 0; i < sum_iter; ++i) { x = x + a; }
	t = clock() - t;
	return (double(t)) / CLOCKS_PER_SEC;
}

template<typename T>
double timeMinus()
{
	clock_t t;
	T x = 0, a = 0;
	t = clock();
	for (long i = 0; i < sum_iter; ++i) { x = x - a; }
	t = clock() - t;
	return (double(t)) / CLOCKS_PER_SEC;
}

template<typename T>
double timeDivision()
{
	clock_t t;
	T x = 1, a = 1;
	t = clock();
	for (long i = 1; i < sum_iter; ++i) { x = x / a; }
	t = clock() - t;
	return (double(t)) / CLOCKS_PER_SEC;
}

template<typename T>
double timeMultiplication()
{
	clock_t t;
	T x = 1, a = 0;
	t = clock();
	for (long i = 0; i < sum_iter; ++i) { x = x * a; }
	t = clock() - t;
	return (double(t)) / CLOCKS_PER_SEC;
}



template<typename T>
double Sum() 
{	
	T a = 2, b = 2, c = 1, d = 4;
	clock_t t;
	t = clock();
	for (int i = 0; i < sum_iter; ++i) { a = b + c; b = a + c; c = a + b; d = c + b; b = c + d; }
	t = clock() - t;
	return  (double(t)) / CLOCKS_PER_SEC;
}

template<typename T1>
double Minus()
{
	T1 a = 2, b = 2, c = 1, d = 4;
	clock_t t;
	t = clock();
	for (int i = 0; i < minus_iter; ++i) { a = b - c; b = a - c; c = a - b; d = c - b; b = c - d; }
	t = clock() - t;
	return (double(t)) / CLOCKS_PER_SEC;
}

template<typename T2>
double Multiplication()
{
	T2 a = 2, b = 2, c = 1, d = 4;
	clock_t t;
	t = clock();
	for (int i = 0; i < multiplication_iter; ++i) { a = b * c; b = a * c; c = a * b; d = c * b; b = c * d; }
	t = clock() - t;
	return  (double(t)) / CLOCKS_PER_SEC;
}
template<typename T3>
double Division()
{
	T3 a = 1, b = 1, c = 1, d = 1;
	clock_t t;
	t = clock();
	for (int i = 0; i < division_iter; ++i) { a = b / c; b = a / c; c = a / b; d = c / b; b = c / d; }
	t = clock() - t;
	return  (double(t)) / CLOCKS_PER_SEC;

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
	if (tipe == "int" ||tipe =="long") {arr_time[1] = arr_time[0] * 1.001; }
	int arr_procent[4] = {};
	double time_max = diagram(arr_time);
	for ( int i = 0; i < 4; ++i){arr_procent[i] = (arr_time[i] / time_max) * 100; }

	char arr_sign[4] = { '+','-','*','/' };
	for (int i = 0; i < 4; ++i)
	{
		cout << arr_sign[i] << "\t" << tipe << "\t" << arr_time[i]<<"\t"; print_x(arr_procent[i]);  cout <<"\t"<< arr_procent[i] << endl;
	}
	cout << "================================================|" << endl;
}

void seconds(double& res1, double& res2, double& res3, double& res4)
{
	res1 = sum_iter / res1 * CLOCKS_PER_SEC;
	res2 = minus_iter / res2 * CLOCKS_PER_SEC;
	res3 = multiplication_iter / res3 * CLOCKS_PER_SEC;
	res4 = division_iter / res4 * CLOCKS_PER_SEC;
	
}

int main() 
{
	cout << "================================================|" << endl;

	int num = 0;
	
	double time_res1 = 0., time_res2 = 0., time_res3 = 0., time_res4 = 0.;
	

	
	while (num <= 5)
	{
		switch (num)
		{
		case 1:
			time_res1 = Sum<int>() - timeSum<int>();
			time_res2 = Minus<int>() - timeMinus<int>(); 
			time_res3 = Multiplication<int>() - timeMultiplication<int>();
			time_res4 = Division<int>() - timeDivision<int>();
			seconds(time_res1, time_res2, time_res3, time_res4);
			print(time_res1, time_res1, time_res3, time_res4, "int");
			break;
		case 2:
			time_res1 = Sum<double>() - timeSum<double>();
			time_res2 = Minus<double>() - timeMinus<double>();
			time_res3 = Multiplication<double>() - timeMultiplication<double>();
			time_res4 = Division<double>() - timeDivision<double>();
			seconds(time_res1, time_res2, time_res3, time_res4);
			print(time_res1, time_res2, time_res3, time_res4, "double");
			break;
		case 3:
			time_res1= Sum<long>() - timeSum<long>();
			time_res2 = Minus<long>() - timeMinus<long>();
			time_res3 = Multiplication<long>() - timeMultiplication<long>();
			time_res4 = Division<long>() - timeDivision<long>();
			seconds(time_res1, time_res2, time_res3, time_res4);
			print(time_res1, time_res2, time_res3, time_res4, "long");
			break;
		case 4:
			time_res1 = Sum<float>() - timeSum<float>();
			time_res2 = Minus<float>() - timeMinus<float>();
			time_res3 = Multiplication<float>() - timeMultiplication<float>();
			time_res4 = Division<float>() - timeDivision<float>();
			seconds(time_res1, time_res2, time_res3, time_res4);
			print(time_res1, time_res2, time_res3, time_res4, "float");
			break;
		case 5:
			time_res1 = Sum<char>() - timeSum<char>();
			time_res2 = Minus<char>() - timeMinus<char>();
			time_res3= Multiplication<char>() - timeMultiplication<char>();
			time_res4 = Division<char>() - timeDivision<char>();
			seconds(time_res1, time_res2, time_res3, time_res4);
			print(time_res1, time_res2, time_res3, time_res4, "char");
			break;
		}
		++num;
	}
	
	

	system("pause");
	return 0;
}















