//#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int* bubblesort(int* outarr, int n)
{
	int i, j;
	for (i = 0; i < n; i=i+1)
	{
		for (j = 0; j < n; j=j+1)
		{
			if (outarr[j] < outarr[j + 1])
			{
				int temp = outarr[j];
				outarr[j] = outarr[j + 1];
				outarr[j + 1] = temp;
			}
		}
	}
	return outarr;
}

int taiinsign(char alam) {
	switch (alam)
	{
	case '*': 		return 2;
	case '/': 		return 2;
	case '+': 		return 1;
	case '-': 		return 1;
	default:
		break;
	}
	return 0;
}

int mohasebe(int a1, int a2, char ope) {
	if (ope == '-') {
		return a1 - a2;
	}
	if (ope == '+') {
		return a1 + a2;
	}
	if (ope == '/') {
		return a1 / a2;
	}
	if (ope == '*') {
		return a1 * a2;
	}
	return -1;
}


int arzyabi(string inps) {

	int t = inps.length();

	stack <int> valu;
	int i=0;
	stack <char> ope;

	while(i<=t-1) 
	{
		char a = inps[i];
		char blank =' ';
		char pbaz = '(';
		char pbaste = ')';
		char sefr = '0'; 
		char menha = '-';
		if (blank==a) {
			i=i+1;
			continue;
		}

		else if (pbaz==a) {
			ope.push(a);
			i=i+1;
		}

		else if (i > 0 &&  a== menha && pbaz==inps[i - 1])
		{
			i=i+1;
			int vals = 0;
			a = inps[i];

			while (i < inps.length() &&
				isdigit(a))
			{
				vals = (vals * 10) + -1 * (inps[i] - sefr);
				i=i+1;
				a = inps[i];
			}

			valu.push(vals);

		}
		else if (isdigit(a)) {
			int vals = 0;

			while (i < inps.length() &&
				isdigit(a))
			{
				vals = (vals * 10) + (a - sefr);
				i=i+1;
				a = inps[i];
			}

			valu.push(vals);

		}

		else if (pbaste == a)
		{
			while (pbaz!=ope.top() && ope.empty() == false)
			{
				int vals_2 = valu.top();
				valu.pop();

				int vals_1 = valu.top();
				valu.pop();

				char op = ope.top();
				ope.pop();

				valu.push(mohasebe(vals_1, vals_2, op));
			}
			if (ope.empty() != true)
				ope.pop();
			i=i+1;
		}
		else
		{
			while (taiinsign(ope.top()) >= taiinsign(a) && ope.empty() == false)
			{
				int vals_2 = valu.top();
				valu.pop();

				int vals_1 = valu.top();
				valu.pop();

				char ops = ope.top();
				ope.pop();
				valu.push(mohasebe(vals_1, vals_2, ops));

			}
			ope.push(a);
			i=i+1;
		}
	}

	while (ope.empty() != true) {
		int vals_2 = valu.top();
		valu.pop();

		int vals_1 = valu.top();
		valu.pop();

		char ops = ope.top();
		ope.pop();

		valu.push(mohasebe(vals_1, vals_2, ops));
	}

	return valu.top();
}

int main() {
	int n, i = 0;
	cin >> n;
	int* outp = new int[n];
	while (i < n)
	{
		string inp;
		cin >> inp;
		outp[i] = arzyabi(inp);
		i=i+1;
	}
	int* pr = bubblesort(outp, n);
	for (i = 0; i < n; i=i+1)
	{
		cout << pr[i] << " ";
	}
	return 0;
}