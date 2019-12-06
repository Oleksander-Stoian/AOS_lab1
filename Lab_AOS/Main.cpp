#include <iostream>
#include <time.h>


using namespace std;
long sum_iter=1999999;
long minus_iter = 1999999;
long multiplication_iter = 1999999;
long division_iter = 1999999;

double sumint, sumdouble, sumlong, sumfload, sumchar;


double timeSum()
{
	clock_t t;
	int x = 0, a = 0;
	t = clock();
	for (long i = 0; i < sum_iter; ++i) { x = x + a; }
	t = clock() - t;
	return (double(t)) / CLOCKS_PER_SEC;
}
double timeMinus()
{
	clock_t t;
	int x = 0, a = 0;
	t = clock();
	for (long i = 0; i < sum_iter; ++i) { x = x - a; }
	t = clock() - t;
	return (double(t)) / CLOCKS_PER_SEC;
}
double timeDivision()
{
	clock_t t;
	int x = 1, a = 1;
	t = clock();
	for (long i = 1; i < sum_iter; ++i) { x = x / a; }
	t = clock() - t;
	return (double(t)) / CLOCKS_PER_SEC;
}
double timeMultiplication()
{
	clock_t t;
	int x = 1, a = 0;
	t = clock();
	for (long i = 0; i < sum_iter; ++i) { x = x * a; }
	t = clock() - t;
	return (double(t)) / CLOCKS_PER_SEC;
}



double timesum()
{
	clock_t t;
	int x = 0, a = 0;
	t = clock();
	for (long i = 1; i < sum_iter; ++i) { x = x + a; }
	t = clock() - t;
	return (double(t)) / CLOCKS_PER_SEC;
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
	return  (double(t)) / CLOCKS_PER_SEC;
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
	return (double(t)) / CLOCKS_PER_SEC;
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
	return  (double(t)) / CLOCKS_PER_SEC;
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
		c = a / (b+1);
	}
	t = clock() - t;
	return  (double(t)) / CLOCKS_PER_SEC;
}

void print_int(double time)
{	
	int x;
	int arr[4] = {};
	arr[0] = sum_iter / sumint;
	arr[1] = sum_iter / sumdouble;
	arr[2] = sum_iter / sumlong;
	arr[3] = sum_iter / sumfload;
	arr[4] = sum_iter / sumchar;
	
	for (int i = 0; i < 4; ++i)
	{
		if (arr[i] <= arr[i + 1])
		{

			x = arr[i + 1];
		}
		else
		{
			x = arr[i];
		}

	}






}


int main() {
	
	
	int num = 0;
	double time_sum = 0., time_minus = 0.,time_division = 0., time_multiplication = 0.;
	double time_int = 0., time_double = 0., time_long = 0., time_float = 0., time_char = 0.;
	
	
	while (num<=4)
	{


		switch (num)
		{
		case 1:         
			time_sum = timeSum();
			sumint = Sum<int>();
			sumdouble = Sum<double>();
			sumlong = Sum<long>();
			sumfload = Sum<float>();
			sumchar = Sum<char>();

			
			time_int = sumint - time_sum;
			time_double = sumdouble - time_sum;
			time_long = sumlong - time_sum;
			time_float = sumfload - time_sum;
			time_char =sumchar - time_sum;

			break;
		case 2: 
			time_minus = timeMinus();
			time_int = Minus<int>() - time_minus;
			time_double = Minus<double>() - time_minus;
			time_long = Minus<long>() - time_minus;
			time_float = Minus<float>() - time_minus;
			time_char=Minus<char>() - time_minus;
			break;
		case 3:
			time_multiplication = timeMultiplication();
			time_int = Multiplication<int>() - time_multiplication;
			time_double = Multiplication<double>() - time_multiplication;
			time_long = Multiplication<long>() - time_multiplication;
			time_float = Multiplication<float>() - time_multiplication;
			time_char = Multiplication<char>() - time_multiplication;
			break;
		case 4:
			time_division = timeDivision();
			time_int = Division<int>() - time_division;
			time_double = Division<double>() - time_division;
			time_long = Division<long>() - time_division;
			time_float = Division<float>() - time_division;
			time_char = Division<char>() - time_division;
			break;
		
		}
		++num;
	}



	

	system("pause");
	return 0;
}