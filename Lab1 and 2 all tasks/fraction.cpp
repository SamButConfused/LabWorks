#include <iostream>

using namespace std;

class Fraction {
public:
    int num;
    int den;

    Fraction(int n, int d) {
        num = n;
        den = d;
        reduce();
    }

    Fraction() {
        num = 0;
        den = 1;
    }

    void reduce() {
        if (den == 0) {
            cout << "Error: denominator cannot be zero" << endl;
            return;
        }
        int gcd = getGcd(num, den);
        num /= gcd;
        den /= gcd;
        if (den < 0) {
            num *= -1;
            den *= -1;
        }
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.den == 1 || f.num == 0) {
            os << f.num;
        } else if (abs(f.num) > f.den) {
            int whole = f.num / f.den;
            int remainder = abs(f.num) % f.den;
            if (remainder == 0) {
                os << whole;
            } else {
                os << whole << " " << remainder << "/" << f.den;
            }
        } else {
            os << f.num << "/" << f.den;
        }
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        char slash;
        is >> f.num >> slash >> f.den;
        f.reduce();
        return is;
    }

    friend Fraction operator+(const Fraction& f1, const Fraction& f2) {
        return Fraction(f1.num * f2.den + f2.num * f1.den, f1.den * f2.den);
    }

    friend Fraction operator-(const Fraction& f1, const Fraction& f2) {
        return Fraction(f1.num * f2.den - f2.num * f1.den, f1.den * f2.den);
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2) {
        return Fraction(f1.num * f2.num, f1.den * f2.den);
    }

    friend Fraction operator/(const Fraction& f1, const Fraction& f2) {
        return Fraction(f1.num * f2.den, f1.den * f2.num);
    }

    friend bool operator<(const Fraction& f1, const Fraction& f2) {
        return f1.num * f2.den < f2.num * f1.den;
    }

    friend bool operator<=(const Fraction& f1, const Fraction& f2) {
        return f1.num * f2.den <= f2.num * f1.den;
    }

    friend bool operator>(const Fraction& f1, const Fraction& f2) {
        return f1.num * f2.den > f2.num * f1.den;
    }

    friend bool operator>=(const Fraction& f1, const Fraction& f2) {
        return f1.num * f2.den >= f2.num * f1.den;
    }

private:
    int getGcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return getGcd(b, a % b);
        }
    }
};

int main() {
    Fraction f1, f2;
    cout << "Enter two fractions: ";
    cin >> f1 >> f2;

    cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
    cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
    cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
    cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;

    if (f1 < f2) {
        cout << f1 << " is less than " << f2 << endl;
    } else {
        cout << f1 << " is not less than " << f2 << endl;
    }

    if (f1 <= f2) {
        cout << f1 << " is less than or equal to " << f2 << endl;
    } else {
        cout << f1 << " is not less than or equal to " << f2 << endl;
    }

    if (f1 > f2) {
        cout << f1 << " is greater than " << f2 << endl;
    } else {
        cout << f1 << " is not greater than " << f2 << endl;
    }

    if (f1 >= f2) {
        cout << f1 << " is greater than or equal to " << f2 << endl;
    } else {
        cout << f1 << " is not greater than or equal to " << f2 << endl;
    }

    return 0;
}
