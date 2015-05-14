#include "stdafx.h"
#include "Controller.h"
#include "calc_B_matrix.h"
#include "ElementData.h"

calc_B_matrix::calc_B_matrix(int val1, Controller &controller)
{

	elem_id = val1;

	Node1 = controller.getNode1(elem_id);

	x1 = controller.getXcoord(Node1);
	y1 = controller.getYcoord(Node1);
	

		/*
code for cal_bmatrix, based on pseudo code provided by the professor.
must be done for all elements.
will need the zeta[i] and eta[j] information that is currently in cal_kematrix
*/
	/*
//define derivatives of nodal equations, N, in terms of zeta (Z) and eta (E)
	double dN1_dZ = -.25*(2 * zeta[i] + eta[j])*(eta[j] - 1);
	double dN1_dE = -.25*(2 * eta[j] + zeta[i])*(zeta[i] - 1);
	double dN2_dZ = zeta[i] * (eta[j] - 1);
	double dN2_dE = .5*(zeta[i] * zeta[i] - 1);
	double dN3_dZ = -.25*(2 * zeta[i] - eta[j])*(eta[j] - 1);
	double dN3_dE = .25*(2 * eta[j] - zeta[i])*(zeta[i] + 1);
	double dN4_dZ = -.5*(eta[j] * eta[j] - 1);
	double dN4_dE = -eta[j] * (zeta[i] + 1);
	double dN5_dZ = .25*(2 * zeta[i] + eta[j])*(eta[j] + 1);
	double dN5_dE = .25*(2 * eta[j] + zeta[i])*(zeta[i] + 1);
	double dN6_dZ = -zeta[i] * (eta[j] + 1);
	double dN6_dE = -.5*(zeta[i] * zeta[i] - 1);
	double dN7_dZ = .25*(2 * zeta[i] - eta[j])*(eta[j] + 1);
	double dN7_dE = -.25*(2 * eta[j] - zeta[i])*(zeta[i] - 1);
	double dN8_dZ = .5*(eta[j] * eta[j] - 1);
	double dN8_dE = eta[j] * (zeta[i] - 1);

	getNodes(element, a, b, c, d, e, f, g, h)*///function to get nodes form the element
	/*
	perhaps like this either as the function or without the function:
	a = elementData[k].Node1;
	b = elementData[k].Node2;
	c = elementData[k].Node3;
	d = elementData[k].Node4;
	e = elementData[k].Node5;
	f = elementData[k].Node6;
	g = elementData[k].Node7;
	h = elementData[k].Node8;
	*/

		/*
	//get nodal coords
		double x1 = nodeData[a].x;
	double y1 = nodeData[a].y;
	double x2 = nodeData[b].x;
	double y2 = nodeData[b].y;
	double x3 = nodeData[c].x;
	double y3 = nodeData[c].y;
	double x4 = nodeData[d].x;
	double y4 = nodeData[d].y;
	double x5 = nodeData[e].x;
	double y5 = nodeData[e].y;
	double x6 = nodeData[f].x;
	double y6 = nodeData[f].y;
	double x7 = nodeData[g].x;
	double y7 = nodeData[g].y;
	double x8 = nodeData[h].x;
	double y8 = nodeData[h].y;

	//calculate dx/dZ, dx/dE, dy/dZ, dy/dE
	double dx_dZ = dN1_dZ*x1 + dN2_dZ*x2 + dN3_dZ*x3 + dN4_dZ*x4 + dN5_dZ*x5 + dN6_dZ*x6 + dN7_dZ*x7 + dN8_dZ*x8;
	double dx_dE = dN1_dE*x1 + dN2_dE*x2 + dN3_dE*x3 + dN4_dE*x4 + dN5_dE*x5 + dN6_dE*x6 + dN7_dE*x7 + dN8_dE*x8;
	double dy_dZ = dN1_dZ*y1 + dN2_dZ*y2 + dN3_dZ*y3 + dN4_dZ*y4 + dN5_dZ*y5 + dN6_dZ*y6 + dN7_dZ*y7 + dN8_dZ*y8;
	double dy_dE = dN1_dE*y1 + dN2_dE*y2 + dN3_dE*y3 + dN4_dE*y4 + dN5_dE*y5 + dN6_dE*y6 + dN7_dE*y7 + dN8_dE*y8;

	//create Jacobian matrix
	double Jacobian[2][2] = { dx_dZ, dx_dE, dy_dZ, dy_dE };

	//calculate determiniate
	double det_J = dx_dZ*dy_dE - dx_dE*dy_dZ;

	//invert Jacobian  NEED TO CREATE INVERSE FUNCTION
	minverse_function(Jacobian, Jacobian_inverse)

		//Place derivatives in vectors
		double vectorN1[2][1];
	double vectorN2[2][1];
	double vectorN3[2][1];
	double vectorN4[2][1];
	double vectorN5[2][1];
	double vectorN6[2][1];
	double vectorN7[2][1];
	double vectorN8[2][1];
	vectorN1[0][0] = dN1_dZ;
	vectorN1[1][0] = dN1_dE;
	vectorN2[0][0] = dN2_dZ;
	vectorN2[1][0] = dN2_dE;
	vectorN3[0][0] = dN3_dZ;
	vectorN3[1][0] = dN3_dE;
	vectorN4[0][0] = dN4_dZ;
	vectorN4[1][0] = dN4_dE;
	vectorN5[0][0] = dN5_dZ;
	vectorN5[1][0] = dN5_dE;
	vectorN6[0][0] = dN6_dZ;
	vectorN6[1][0] = dN6_dE;
	vectorN7[0][0] = dN7_dZ;
	vectorN7[1][0] = dN7_dE;
	vectorN8[0][0] = dN8_dZ;
	vectorN8[1][0] = dN8_dE;

	//Multiply inverse jacobian by local vectors to get global vectors NEED TO CREATE MULTIPLICATION FUNCTION
	mmult_function(Jacobian_inverse, vectorN1, r, s, t, gN1vector)
		dN1_dx = gN1vector[0][0];
	dN1_dy = gN1vector[1][0];

	mmult_function(Jacobian_inverse, vectorN2, r, s, t, gN2vector)
		dN2_dx = gN2vector[0][0];
	dN2_dy = gN2vector[1][0];

	mmult_function(Jacobian_inverse, vectorN3, r, s, t, gN3vector)
		dN3_dx = gN3vector[0][0];
	dN3_dy = gN3vector[1][0];

	mmult_function(Jacobian_inverse, vectorN4, r, s, t, gN4vector)
		dN4_dx = gN4vector[0][0];
	dN4_dy = gN4vector[1][0];

	mmult_function(Jacobian_inverse, vectorN5, r, s, t, gN5vector)
		dN5_dx = gN5vector[0][0];
	dN5_dy = gN5vector[1][0];

	mmult_function(Jacobian_inverse, vectorN6, r, s, t, gN6vector)
		dN6_dx = gN6vector[0][0];
	dN6_dy = gN6vector[1][0];

	mmult_function(Jacobian_inverse, vectorN7, r, s, t, gN7vector)
		dN7_dx = gN7vector[0][0];
	dN7_dy = gN7vector[1][0];

	mmult_function(Jacobian_inverse, vectorN8, r, s, t, gN8vector)
		dN8_dx = gN8vector[0][0];
	dN8_dy = gN8vector[1][0];

	//create and populate B matrix
	Double B_matrix[4][16];
	B_matrix[0][0] = dN1_dx;
	B_matrix[0][1] = 0;
	B_matrix[0][2] = dN2_dx;
	B_matrix[0][3] = 0;
	B_matrix[0][4] = dN3_dx;
	B_matrix[0][5] = 0;
	B_matrix[0][6] = dN4_dx;
	B_matrix[0][7] = 0;
	B_matrix[0][8] = dN5_dx;
	B_matrix[0][9] = 0;
	B_matrix[0][10] = dN6_dx;
	B_matrix[0][11] = 0;
	B_matrix[0][12] = dN7_dx;
	B_matrix[0][13] = 0;
	B_matrix[0][14] = dN8_dx;
	B_matrix[0][15] = 0;
	B_matrix[1][0] = 0;
	B_matrix[1][1] = dN1_dy;
	B_matrix[1][2] = 0;
	B_matrix[1][3] = dN2_dy;
	B_matrix[1][4] = 0;
	B_matrix[1][5] = dN3_dy;
	B_matrix[1][6] = 0;
	B_matrix[1][7] = dN4_dy;
	B_matrix[1][8] = 0;
	B_matrix[1][9] = dN5_dy;
	B_matrix[1][10] = 0;
	B_matrix[1][11] = dN6_dy;
	B_matrix[1][12] = 0;
	B_matrix[1][13] = dN7_dy;
	B_matrix[1][14] = 0;
	B_matrix[1][15] = dN8_dy;
	B_matrix[2][0] = 0;
	B_matrix[2][1] = 0;
	B_matrix[2][2] = 0;
	B_matrix[2][3] = 0;
	B_matrix[2][4] = 0;
	B_matrix[2][5] = 0;
	B_matrix[2][6] = 0;
	B_matrix[2][7] = 0;
	B_matrix[2][8] = 0;
	B_matrix[2][9] = 0;
	B_matrix[2][10] = 0;
	B_matrix[2][11] = 0;
	B_matrix[2][12] = 0;
	B_matrix[2][13] = 0;
	B_matrix[2][14] = 0;
	B_matrix[2][15] = 0;
	B_matrix[3][0] = dN1_dy;
	B_matrix[3][1] = dN1_dx;
	B_matrix[3][2] = dN2_dy;
	B_matrix[3][3] = dN2_dx;
	B_matrix[3][4] = dN3_dy;
	B_matrix[3][5] = dN3_dx;
	B_matrix[3][6] = dN4_dy;
	B_matrix[3][7] = dN4_dx;
	B_matrix[3][8] = dN5_dy;
	B_matrix[3][9] = dN5_dx;
	B_matrix[3][10] = dN6_dy;
	B_matrix[3][11] = dN6_dx;
	B_matrix[3][12] = dN7_dy;
	B_matrix[3][13] = dN7_dx;
	B_matrix[3][14] = dN8_dy;
	B_matrix[3][15] = dN8_dx;

	//double loop to create B transpose matrix
	for (int p = 0; p < 4; p++)
	{
		for (int q = 0; q < 16; q++)
		{
			B_transpose[j][i] = B_matrix[i][j];
		}
	}

	*/
}

void calc_B_matrix::printData(ostream &out) const
{
	out << elem_id << endl;
	out << Node1 << endl;
	out << x1 << endl;
	out << y1 << endl; 
}