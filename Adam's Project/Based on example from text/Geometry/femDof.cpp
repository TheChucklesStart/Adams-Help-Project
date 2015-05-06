//femDof object

#include "stdafx.h"
#include "femdof.h"

femdof::femDOF()
{
}

femdof::~femDof()
{
}

void femdof::setNotActive()
{
	d_active = false;
}

bool femdof::isActive()
{
	return d_active;
}

int femdof::setEqn(int currEqn)
{
	if(d_active == true)
	{
		d_eqn = currEqn;
		currEqn++;
	}

	else if(d_active == false)
	{
		d_eqn = -1;
	}
}

void femdof::setEqnXin(int count)
{
	if(d_active == true)
	{
		d_eqn = count;
		count++;
	}

	else if(d_active == false)
	{
		d_eqn = -1;
	}
}

int femdof::getEqn()
{
	return d_eqn;
}

void femdof::setValue(double value)
{
	d_value = value;
}

double femdof::getValue() const
{
	return d_value;
}