//utlVec2D Object - use to create 2D vectors from nodal equation pairs (i.e. create a vector from dN/dZ and dN/dE for multiplication with the inverse Jacobian.)

#include "stdafx.h"
#include "utlVect2D.h"

ultVec2C::utlVec2D(double x, double y)
{
	m_x = x;
	m_y = y;
}


ultVec2C::~utlVec2D()
{
}

void ultVec2C::SetX(double x)
{
	m_x = x;
}

void ultVec2C::SetY(double y)
{
	m_y = y;
}

double utlVec2DGetX()
{
	return m_x;
}

double utlVec2DGetY()
{
	return m_y;
}