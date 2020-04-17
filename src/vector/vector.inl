#pragma once
#include "vector.hpp"
#include <cmath>
#include <iostream>

namespace bc {
//-------------------------
template<class T>
inline vector<T> vector<T>::from_polar(double rad, double len) {
	vector<T> rslt;

	rslt.x() = std::cos(rad)*len;
	rslt.y() = std::sin(rad)*len;

	return rslt;
}

template<class T>
inline T& vector<T>::x() {
	return m_x;
}

template<class T>
inline T& vector<T>::y() {
	return m_y;
}

template<class T>
inline const T& vector<T>::x() const {
	return m_x;
}

template<class T>
inline const T& vector<T>::y() const {
	return m_y;
}

template<class T>
inline double vector<T>::length() const {
	return std::sqrt(m_x*m_x + m_y * m_y);
}

template<class T>
inline double vector<T>::angle() const {
	if(std::atan2(m_y, m_x) >= 0) return std::atan2(m_y, m_x);
	else return std::atan2(m_y, m_x) + 2*PI;
}

template<class T>
inline vector<T>& vector<T>::rotate(double rad) {
	*this = from_polar(angle() + rad, length());
	return *this;
}

template<class T>
inline vector<T>& vector<T>::mirror(const vector& axis) {
	double rad = angle() + 2 * (axis.angle() - angle());
	*this = from_polar(rad, length());
	return *this;
}

template<class T>
inline vector<T>& vector<T>::operator+=(const vector<T>& rhs) {
	m_x = rhs.x() + m_x;
	m_y = rhs.y() + m_y;

	return *this;
}

template<class T>
inline vector<T>& vector<T>::operator-=(const vector<T>& rhs) {
	m_x = m_x - rhs.x();
	m_y = m_y - rhs.y();

	return *this;
}

template<class T>
inline vector<T>& vector<T>::operator*=(const double& rhs) {
	m_x = m_x * rhs;
	m_y = m_y * rhs;

	return *this;
}

template<class T>
inline vector<T>& vector<T>::operator/=(const double& rhs) {
	m_x = m_x / rhs;
	m_y = m_y / rhs;

	return *this;
}

template<class T>
inline vector<T> vector<T>::operator-() {
	vector vec2 = *this;
	vec2.x() = -m_x;
	vec2.y() = -m_y;

	return vec2;
}

template<class T>
inline vector<T>::vector(T x_, T y_) {
	m_x = x_;
	m_y = y_;
}

template<class T>
inline vector<T> operator+(vector<T> lhs, const vector<T>& rhs) {
	lhs += rhs;
	return lhs;
}

template<class T>
inline vector<T> operator-(vector<T> lhs, const vector<T>& rhs) {
	lhs -= rhs;
	return lhs;
}

template<class T>
inline vector<T> operator*(vector<T> lhs, const double& rhs) {
	lhs *= rhs;
	return lhs;
}

template<class T>
inline vector<T> operator*(const double& lhs, vector<T> rhs) {
	rhs *= lhs;
	return rhs;
}

template<class T>
inline vector<T> operator/(vector<T> lhs, const double & rhs) {
	lhs /= rhs;
	return lhs;
}

template<class T>
inline T dot_product(const vector<T>& a, const vector<T>& b) {
	return a.x()*b.x() + a.y()*b.y();
}
//-------------------------
}//////////////namespace bc
