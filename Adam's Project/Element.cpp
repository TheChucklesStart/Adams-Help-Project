#include "stdafx.h"
#include "Element.h"

calc_B_matrix ElementData::get_B_matrix(double eta, double zeta)
{
	return calc_B_matrix(*this, *controller, eta, zeta);
}

calc_M_matrix ElementData::get_M_matrix(calc_B_matrix & calc_B_matrix, calc_D_matrix & calc_D_matrix)
{
	return calc_M_matrix(calc_B_matrix, calc_D_matrix);
}

calc_Ke_matrix ElementData::get_Ke_matrix(calc_D_matrix & calc_D_matrix)
{
	return calc_Ke_matrix(*this, controller->getThickness(), calc_D_matrix);
}
