#ifndef vex_by_Chuckles_Brock
#define vex_by_Chuckles_Brock

#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#ifndef pi
#define pi acos(-1.0)
#endif

class vex
{
public:
	static const int dimension = 3;
	vex();
	vex(const double &x, const double &y, const double &z);
	vex(const vex &orig);
	vex(const double orig[dimension]);
	~vex();

	void randomize(double low, double high);
	void randomize(double max);
	void set(const double &x, const double &y, const double &z);
	void set(const vex &orig);
	void set(const double orig[dimension]);

	void setarray(double *new_space);
	double* getArray();

	double & operator[](int i);

	vex unit() const;
	vex makeunit();
	double abs() const;

	vex rotate(const double &theta, vex axis);
		// theta is angle in radians
		// 3D ROTATION FUNCTION ONLY!!!!!!
	vex rotate(const double &theta, const double &x, const double &y, const double &z);
		// theta is angle in radians
		// 3D ROTATION FUNCTION ONLY!!!!!!
	vex rotate(const double &theta);
		// theta is angle in radians
		// 2D ROTATION FUNCTION ONLY!!!!!!

	bool operator==(const vex &right);
	bool operator!=(const vex &right);

	const vex& operator=(const vex &orig);
	vex operator+=(const vex &right);
	vex operator-=(const vex &right);
	vex operator&=(const vex &right);  // cross product equals
	// There is no dot product equals since the dot product returns a scaler
	vex operator*=(const double &right);
	vex operator/=(const double &right);

	vex operator+(const vex &right) const;
	vex operator-(const vex &right) const;
	vex operator&(const vex &right) const;  // cross product
	double operator*(const vex &right) const; // dot product
	vex operator*(const double &right) const;
	vex operator/(const double &right) const;
	friend vex operator*(const double &left, const vex &right);
	friend vex operator/(const double &left, const vex &right);
	// can't add friend operator= for scalars since that returns a vector

private:
	double *data;
	double mydata[dimension];
};

extern const vex vex_zero;

#endif