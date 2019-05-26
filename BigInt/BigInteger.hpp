#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
//using namespace std;
//typedef vector <long long> vll;

template<typename T, size_t Base = std::numeric_limits<T>::max()>
class BigInteger {
private:
	template<typename Tp, size_t B> friend std::ostream & operator <<(std::ostream &, const BigInteger &);
	template<typename Tp, size_t B> friend std::istream & operator >>(std::istream &, BigInteger &);
	int sign;
	std::vector<T> number;
	size_t size_of_number = 0;
	const size_t num_of_bits = std::ceil(log2(Base));
	const size_t num_of_blocks = sizeof(T) * 8 / num_of_bits;

	/*static std::vector<T> karatsubaMultiply(const std::vector <T> &a, const std::vector <T> &b) {
        int n = a.size();
        vector <T> res(n + n);
        if (n <= 2) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }
        int k = n >> 1;
		vector <T> a1(a.begin(), a.begin() + k);
		vector <T> a2(a.begin() + k, a.end());
		vector <T> b1(b.begin(), b.begin() + k);
		vector <T> b2(b.begin() + k, b.end());

		vector <T> a1b1 = karatsubaMultiply(a1, b1);
		vector <T> a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

		vector <T> r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }*/


public:
	explicit BigInteger(long long val = 0);
	explicit BigInteger(const std::string & s);
	explicit BigInteger(const std::vector<T> & number, const int sign);

	template<typename NewT, size_t NewBase>
	explicit operator BigInteger<NewT, NewBase>();
	BigInteger(const BigInteger &);
	BigInteger(BigInteger &&);

	size_t Size() const;
	T operator[](size_t id) const;

	BigInteger& operator = (BigInteger val);

	bool operator < (const BigInteger &val) const;
	bool operator > (const BigInteger &val) const;
	bool operator <= (const BigInteger &val) const;
	bool operator >= (const BigInteger &val) const;
	bool operator == (const BigInteger &val) const;
	bool operator != (const BigInteger &val) const;
	BigInteger abs() const;

	BigInteger & operator += (const BigInteger &val);
	BigInteger operator + (const BigInteger &val) const;
	BigInteger & operator -= (const BigInteger &val);
	BigInteger operator - (const BigInteger &val) const;
	BigInteger & operator *= (const BigInteger &val);
	BigInteger operator * (const BigInteger &val);
	BigInteger & operator /= (long long val);
	BigInteger operator / (long long val) const;
	long long operator % (long long val) const;
	BigInteger operator - () const;
	void clear();

};

template<typename T, size_t Base>
std::ostream & operator <<(std::ostream &, const BigInteger<T, Base> &);

template<typename T, size_t Base>
std::istream & operator >>(std::istream &, BigInteger<T, Base> &);
