//============================================================================
// Name        : Week4_Overload1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;

class Rational {
public:
	Rational() {
		p = 0;
		q = 1;
	}

	Rational(int numerator, int denominator) {
		if (numerator > 0 && denominator > 0) {
			p = numerator / gcd(numerator, denominator);
			q = denominator / gcd(numerator, denominator);
		}
		if (numerator == 0) {
			p = 0;
			q = 1;
		}
		if (numerator < 0&& denominator < 0) {
			p = abs(numerator) / gcd(abs(numerator), abs(denominator));
			q = abs(denominator) / gcd(abs(numerator), abs(denominator));
		}
		if ((denominator > 0 && numerator < 0)
				|| (denominator < 0 && numerator > 0)) {
			p = -(abs(numerator) / gcd(abs(numerator), abs(denominator)));
			q = abs(denominator) / gcd(abs(numerator), abs(denominator));
		}
	}

	int Numerator() const {
		return p;
	}

	int Denominator() const {
		return q;
	}

private:
	int p, q;
};

int main() {
	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10) {
			cout << "Rational(3, 10) != 3/10" << endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3) {
			cout << "Rational(8, 12) != 2/3" << endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(-4, 6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(4, -6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1) {
			cout << "Rational(0, 15) != 0/1" << endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0
				|| defaultConstructed.Denominator() != 1) {
			cout << "Rational() != 0/1" << endl;
			return 5;
		}
	}

	cout << "OK" << endl;
	return 0;
}
