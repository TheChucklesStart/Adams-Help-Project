#include "vex.h"

const vex vex_zero;

vex::vex()
{
	int i;
	data = mydata;
	for(i=0;i<dimension;i++)
		data[i] = 0;
	return;
}

vex::vex(const double &x, const double &y, const double &z)
{
	data = mydata;
	data[0] = x;
	data[1] = y;
	data[2] = z;
	return;
}

vex::vex(const vex &orig)
{
	int i;
	data = mydata;
	for(i=0;i<dimension;i++)
		data[i] = orig.data[i];
	return;
}

vex::vex(const double orig[dimension])
{
	int i;
	data = mydata;
	for(i=0;i<dimension;i++)
		data[i] = orig[i];
	return;
}

vex::~vex()
{
	return;
}

void vex::randomize(double low, double high)
{
	int i;
	vex temp;
	for(i=0;i<dimension;i++)
		temp.data[i] = rand();
	temp/=RAND_MAX/(high-low);
	for(i=0;i<dimension;i++)
		data[i] = temp.data[i] + low;
	return;
}

void vex::randomize(double max)
{
	int i;
	//vex temp;
	for(i=0;i<dimension;i++)
		data[i] = cos(1.0*rand());
	makeunit();
	(*this)*=max*rand()/RAND_MAX;
	/*temp *= 2;
	for(i=0;i<dimension;i++)
		temp.data[i] -= 1;
	temp *= rand()*max/RAND_MAX;
	//temp *= max;
	for(i=0;i<dimension;i++)
		data[i] = temp.data[i];*/
	return;
}

void vex::set(const double &x, const double &y, const double &z)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
	return;
}

void vex::set(const vex &orig)
{
	int i;
	for(i=0;i<dimension;i++)
		data[i] = orig.data[i];
	return;
}

void vex::set(const double orig[dimension])
{
	int i;
	for(i=0;i<dimension;i++)
		data[i] = orig[i];
	return;
}

void vex::setarray(double *new_space)
{
	int i;
	for(i=0;i<dimension;i++)
		new_space[i] = data[i];
	data = new_space;
	return;
}

double* vex::getArray()
{
	return data;
}

double & vex::operator [](int i)
{
	if(i<dimension && i >= 0)
		return data[i];
	cerr<<"VEX ERROR: Index out of Range: "<<i<<endl;
	system("pause");
	exit(1);
}

vex vex::unit() const
{
	vex temp;
	temp = (*this);
	temp.makeunit();
	return temp;
}

vex vex::makeunit()
{
	int i;
	double r;
	r = abs();
	for(i=0;i<dimension;i++)
		data[i] /= r;
	return (*this);
}

double vex::abs() const
{
	double r=0;
	int i;
	for(i=0;i<dimension;i++)
	{
		r+= data[i] * data[i];
	}
	r = sqrt(r);
	return r;
}

vex vex::rotate(const double &theta, vex axis)
{
	double a,b,c,d;
	vex p, q;
	if(dimension != 3)
		return vex_zero;
	// step 1: rotate space about the x axis so that the rotation axis lies in the xz plane
	p = *this;
	axis.makeunit();
	//p = axis;
	a = axis.data[0];
	b = axis.data[1];
	c = axis.data[2];
	d = sqrt(b*b+c*c);
	if(d>0)
	{
		q.data[0] = p.data[0];
		q.data[1] = p.data[1] * c/d - p.data[2] * b/d;
		q.data[2] = p.data[1] * b/d + p.data[2] * c/d;
	}
	else
	{
		q = p;
	}
	// step 2: rotate space about the y axis so that the rotation axis lies along the z axis
	p.data[0] = q.data[0] * d - q.data[2] * a;
	p.data[1] = q.data[1];
	p.data[2] = q.data[0] * a + q.data[2] * d;
	// step 3: perform the desired rotation by theta about the z axis
	q.data[0] = p.data[0] * cos(theta) - p.data[1] * sin(theta); 
	q.data[1] = p.data[0] * sin(theta) + p.data[1] * cos(theta);
	q.data[2] = p.data[2];
	// inverse of step 2
	p.data[0] = q.data[0] * d + q.data[2] * a;
	p.data[1] = q.data[1];
	p.data[2] = -q.data[0] * a + q.data[2] * d;
	// inverse of step 1
	if(d>0)
	{
		data[0] = p.data[0];
		data[1] = p.data[1] * c/d + p.data[2] * b/d;
		data[2] = -p.data[1] * b/d + p.data[2] * c/d;
	}
	else
	{
		*this = p;
	}
	return (*this);
}

vex vex::rotate(const double &theta, const double &x, const double &y, const double  &z)
{
	vex temp;
	temp.data[0] = x;
	temp.data[1] = y;
	temp.data[2] = z;
	return rotate(theta, temp);
}
vex vex::rotate(const double &theta)
{
	vex temp;
	temp = *this;
	data[0] = temp.data[0] * cos(theta) - temp.data[1] * sin(theta); 
	data[1] = temp.data[0] * sin(theta) + temp.data[1] * cos(theta);
	return *this;
}

bool vex::operator ==(const vex &right)
{
	bool test = true;
	int i;
	for(i=0;i<dimension;i++)
	{
		test = test && data[i] == right.data[i];
	}
	return test;
}

bool vex::operator !=(const vex &right)
{
	bool test = true;
	int i;
	for(i=0;i<dimension;i++)
	{
		test = test && data[i] == right.data[i];
	}
	return !test;
}

const vex& vex::operator =(const vex &orig)
{
	int i;
	for(i=0;i<dimension;i++)
		data[i] = orig.data[i];
	return orig;
}

vex vex::operator+=(const vex &right)
{
	int i;
	for(i=0;i<dimension;i++)
		data[i] += right.data[i];
	return (*this);
}

vex vex::operator-=(const vex &right)
{
	int i;
	for(i=0;i<dimension;i++)
		data[i] -= right.data[i];
	return (*this);
}

vex vex::operator&=(const vex &right)
{
	vex temp;
	temp = (*this) & right;
	this->operator =(temp);
	return (*this);
}

vex vex::operator*=(const double &right)
{
	int i;
	for(i=0;i<dimension;i++)
		data[i] *= right;
	return (*this);
}

vex vex::operator/=(const double &right)
{
	int i;
	for(i=0;i<dimension;i++)
		data[i] /= right;
	return (*this);
}

vex vex::operator+(const vex &right) const
{
	vex temp;
	int i;
	for(i=0;i<dimension;i++)
	{
		temp.data[i] = this->data[i] + right.data[i];
	}
	return temp;
}

vex vex::operator-(const vex &right) const
{
	vex temp;
	int i;
	for(i=0;i<dimension;i++)
	{
		temp.data[i] = this->data[i] - right.data[i];
	}
	return temp;
}

vex vex::operator&(const vex &right) const
{
	vex temp;
	int i;
	for(i=0;i<dimension;i++)
	{
		temp.data[i] = data[(i+1)%dimension] * right.data[(i+2)%dimension];
		temp.data[i]-= data[(i+2)%dimension] * right.data[(i+1)%dimension];
	}
	return temp;
}

double vex::operator*(const vex &right) const
{
	double temp = 0;
	int i;
	for(i=0;i<dimension;i++)
	{
		temp+= data[i] * right.data[i];
	}
	return temp;
}

vex vex::operator*(const double &right) const
{
	vex temp;
	int i;
	for(i=0;i<dimension;i++)
	{
		temp.data[i] = this->data[i] * right;
	}
	return temp;
}

vex vex::operator/(const double &right) const
{
	vex temp;
	int i;
	for(i=0;i<dimension;i++)
	{
		temp.data[i] = this->data[i] / right;
	}
	return temp;
}

vex operator*(const double &left, const vex &right)
{
	vex temp;
	int i;
	for(i=0;i<right.dimension;i++)
	{
		temp.data[i] = left * right.data[i];
	}
	return temp;
}

vex operator/(const double &left, const vex &right)
{
	vex temp;
	int i;
	for(i=0;i<right.dimension;i++)
	{
		temp.data[i] = left / right.data[i];
	}
	return temp;
}