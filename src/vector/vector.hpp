#pragma once
namespace bc {
//-------------------------
const double PI = 3.141592653589793238463;

template<class T>
class vector {
private:
	T m_x;
	T m_y;

public:
	static vector from_polar(double rad, double len);//constructor from polar coordiantes - angle, length

    T& x();
	T& y();

	const T& x() const;
	const T& y() const;

	double length() const;
	double angle() const;
	
	vector& rotate(double rad);
	vector& mirror(const vector& axis);

	vector& operator+=(const vector& rhs);
	vector& operator-=(const vector& rhs);
	vector& operator*=(const double& rhs);
	vector& operator/=(const double& rhs);

	vector operator-();

	vector(T x_ = 0, T y_ = 0);
};

template<class T>
inline vector<T> operator+(vector<T> lhs, const vector<T>& rhs);

template<class T>
inline vector<T> operator-(vector<T> lhs, const vector<T>& rhs);

template<class T>
inline vector<T> operator*(vector<T> lhs, const double& rhs);

template<class T>
inline vector<T> operator*(const double& lhs, vector<T> rhs);

template<class T>
inline vector<T> operator/(vector<T> lhs, const double& rhs);

template<class T>
inline T dot_product(const vector<T>& a, const vector<T>& b);
//-------------------------
}//////////////namespace bc

#include "vector.inl"