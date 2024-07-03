#include <iostream> 
#include <bits/stdc++.h>
using namespace std; 

// https://www.geeksforgeeks.org/mathematical-algorithms/

void DivisibleBySix()
{
    long x = 36358839596; 
    long y = 36300000000;
    
    for(long i=y;i<=x;i++)
    {
    	if (i % 6 == 0) 
        	cout << i<<"-Yes"; 
    	else
        	cout << i<<"-No"; 
    }
}

// CPP program to find sum of series
// 2, 22, 222, ..
void SumOfSeries()
{
     int n = 6;
     cout << 0.02469 * (10*(pow(10, n) - 1)- (9 * n));
}

// C++ program to find required minimum digits
// need to remove to make a number perfect square
int perfectSquare(string s)
{
	// size of the string
	int n = s.size();

	// our final answer
	int ans = -1;

	// to store string which is perfect square.
	string num;

	// We make all possible subsequences
	for (int i = 1; i < (1 << n); i++) {
		string str = "";
		
		for (int j = 0; j < n; j++) {
			
			// to check jth bit is set or not.
			if ((i >> j) & 1) {
				str += s[j];
			}
		}

		// we do not consider a number with leading zeros
		if (str[0] != '0') {
			
			// convert our temporary string into integer
			int temp = 0;
			for (int j = 0; j < str.size(); j++)
				temp = temp * 10 + (int)(str[j] - '0');

			int k = sqrt(temp);

			// checking temp is perfect square or not.
			if (k * k == temp) {
				
				// taking maximum sized string
				if (ans < (int)str.size()) {
					ans = (int)str.size();
					num = str;
				}
			}
		}
	}

	if (ans == -1)
		return ans;
	else {
		
		// print PerfectSquare
		cout << num << " ";
		return n - ans;
	}
}


// Simple C++ program to add two polynomials

int max(int m, int n) { return (m > n) ? m : n; }

int* add(int A[], int B[], int m, int n)
{
    int size = max(m, n);
    int* sum = new int[size];

    // Initialize the product polynomial
    for (int i = 0; i < m; i++)
        sum[i] = A[i];

    // Take every term of first polynomial
    for (int i = 0; i < n; i++)
        sum[i] += B[i];

    return sum;
}

void printPoly(int poly[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << poly[i];
        if (i != 0)
            cout << "x^" << i;
        if (i != n - 1)
            cout << " + ";
    }
}

// C++ implementation to 
// convert a binary number to hexadecimal number 

void createMap(unordered_map<string, char> *um) 
{ 
	(*um)["0000"] = '0'; 
	(*um)["0001"] = '1'; 
	(*um)["0010"] = '2'; 
	(*um)["0011"] = '3'; 
	(*um)["0100"] = '4'; 
	(*um)["0101"] = '5'; 
	(*um)["0110"] = '6'; 
	(*um)["0111"] = '7'; 
	(*um)["1000"] = '8'; 
	(*um)["1001"] = '9'; 
	(*um)["1010"] = 'A'; 
	(*um)["1011"] = 'B'; 
	(*um)["1100"] = 'C'; 
	(*um)["1101"] = 'D'; 
	(*um)["1110"] = 'E'; 
	(*um)["1111"] = 'F'; 
} 


string convertBinToHex(string bin) 
{ 
	int l = bin.size(); 
	int t = bin.find_first_of('.'); 
	
	// length of string before '.' 
	int len_left = t != -1 ? t : l; 
	
	// add min 0's in the beginning to make 
	// left substring length divisible by 4 
	for (int i = 1; i <= (4 - len_left % 4) % 4; i++) 
		bin = '0' + bin; 
	
	// if decimal point exists	 
	if (t != -1)	 
	{ 
		// length of string after '.' 
		int len_right = l - len_left - 1; 
		
		// add min 0's in the end to make right 
		// substring length divisible by 4 
		for (int i = 1; i <= (4 - len_right % 4) % 4; i++) 
			bin = bin + '0'; 
	} 
	
	// create map between binary and its 
	// equivalent hex code 
	unordered_map<string, char> bin_hex_map; 
	createMap(&bin_hex_map); 
	
	int i = 0; 
	string hex = ""; 
	
	while (1) 
	{ 
		// one by one extract from left, substring 
		// of size 4 and add its hex code 
		hex += bin_hex_map[bin.substr(i, 4)]; 
		i += 4; 
		if (i == bin.size()) 
			break; 
			
		// if '.' is encountered add it 
		// to result 
		if (bin.at(i) == '.')	 
		{ 
			hex += '.'; 
			i++; 
		} 
	} 
	
	// required hexadecimal number 
	return hex;	 
} 

// C++ program to check whether a number 
// is prime or not using recursion 
bool isPrime(int n) 
{ 
	static int i = 2; 

	// corner cases 
	if (n == 0 || n == 1) { 
		return false; 
	} 

	// Checking Prime 
	if (n == i) 
		return true; 

	// base cases 
	if (n % i == 0) { 
		return false; 
	} 
	i++; 
	return isPrime(n); 
} 

// Program to print kth prime factor

int kPrimeFactor(int n, int k)
{
	// Find the number of 2's that divide k
	while (n%2 == 0)
	{
		k--;
		n = n/2;
		if (k == 0)
		return 2;
	}

	// n must be odd at this point. So we can skip
	// one element (Note i = i +2)
	for (int i = 3; i <= sqrt(n); i = i+2)
	{
		// While i divides n, store i and divide n
		while (n%i == 0)
		{
			if (k == 1)
			return i;

			k--;
			n = n/i;
		}
	}

	// This condition is to handle the case where
	// n is a prime number greater than 2
	if (n > 2 && k == 1)
		return n;

	return -1;
}

// C++ program to find 
// factorial of given number 
 
unsigned long factorial(unsigned int n) 
{ 
	if (n == 0 || n == 1) 
		return 1; 
	return n * factorial(n - 1); 
} 

// Fibonacci Series using Space Optimized Method
void fib(int n)
{
	int a = 0, b = 1, c, i;
	if (n == 0)
		cout<<a<<" ";
	for (i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
		cout<<b<<" ";
	}
}



  
int main() 
{ 
   cout<< "Numbers divisible by 6:";
   DivisibleBySix();
   //---------------------------------------
   cout<<"sum of series 2, 22, 222, .. ,222222 is:";
   SumOfSeries();
   //--------------------------------------
   cout<< "perfect square: ";
   cout << perfectSquare("8314") << endl;
   cout << perfectSquare("753") << endl; 
   //--------------------------------polynomial---
       // The following array represents polynomial 5 + 10x^2 + 6x^3
    int A[] = { 5, 0, 10, 6 };

    // The following array represents polynomial 1 + 2x + 4x^2
    int B[] = { 1, 2, 4 };
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);

    cout << "First polynomial is \n";
    printPoly(A, m);
    cout << "\nSecond polynomial is \n";
    printPoly(B, n);

    int* sum = add(A, B, m, n);
    int size = max(m, n);
    
    cout << "\nsum polynomial is \n";
    printPoly(sum, size);
    //---------------------------convert to hexa---------------------
    
    string bin = "1111001010010100001.010110110011011"; 
    cout << "Hexadecimal number = " << convertBinToHex(bin); 
    
    //-----------------------------------------------------------

    cout<<"prime numbers: ";
    for(int ii=5;ii<250000;ii++)
    	isPrime(ii) ? cout <<"is prime?"<<ii<< ": true\n" : cout << " false\n"; 
    
    //---------------------------------------------------
    cout<<"k prime factor: ";
    	int n1 = 12, k1 = 3;
	cout << kPrimeFactor(n1, k1) << endl;
	n1 = 14, k1 = 3;
	cout << kPrimeFactor(n1, k1) << endl;
    //-----------------------------------------------------
    int num = 25; 
    cout << "Factorial of "<< num << " is " << factorial(num) << endl; 
    
    //---------------------------------------------------------------
    int n2 = 25;
    cout<<"fibonacci:";
    fib(n2);


   return 0; 
} 
