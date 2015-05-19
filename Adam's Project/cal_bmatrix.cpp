#include "stdafx.h"
#include "Controller.h"
#include "calc_B_matrix.h"
#include "MatrixFunctions.h"

calc_B_matrix::calc_B_matrix(int val1, Controller &controller, double eta, double zeta)
{
	Jacobian = MatrixFunctions::allocateMatrix(2, 2);
	B_transpose = MatrixFunctions::allocateMatrix(16, 4);
	B_matrix = MatrixFunctions::allocateMatrix(4, 16);

	//Get element ID
	elem_id = val1;
	//Get element nodes
	Node1 = controller.getNode1(elem_id - 1);
	Node2 = controller.getNode2(elem_id - 1);
	Node3 = controller.getNode3(elem_id - 1);
	Node4 = controller.getNode4(elem_id - 1);
	Node5 = controller.getNode5(elem_id - 1);
	Node6 = controller.getNode6(elem_id - 1);
	Node7 = controller.getNode7(elem_id - 1); 
	Node8 = controller.getNode8(elem_id - 1);
	//Get nodal coordinates
	x1 = controller.getXcoord(Node1 - 1);
	y1 = controller.getYcoord(Node1 - 1);
	x2 = controller.getXcoord(Node2 - 1);
	y2 = controller.getYcoord(Node2 - 1);
	x3 = controller.getXcoord(Node3 - 1);
	y3 = controller.getYcoord(Node3 - 1);
	x4 = controller.getXcoord(Node4 - 1);
	y4 = controller.getYcoord(Node4 - 1);
	x5 = controller.getXcoord(Node5 - 1);
	y5 = controller.getYcoord(Node5 - 1);
	x6 = controller.getXcoord(Node6 - 1);
	y6 = controller.getYcoord(Node6 - 1);
	x7 = controller.getXcoord(Node7 - 1);
	y7 = controller.getYcoord(Node7 - 1);
	x8 = controller.getXcoord(Node8 - 1);
	y8 = controller.getYcoord(Node8 - 1);

	double weight[2] = { 1, 1 };

	/*
	code for cal_bmatrix, based on pseudo code provided by the professor.
	must be done for all elements.
	will need the zeta[i] and eta[j] information that is currently in cal_kematrix
	*/

	//define derivatives of nodal equations, N, in terms of zeta (Z) and eta (E)
	double dN1_dZ = -.25*(2 * zeta + eta)*(eta - 1);
	double dN1_dE = -.25*(2 * eta + zeta)*(zeta - 1);
	double dN2_dZ = zeta * (eta - 1);
	double dN2_dE = .5*(zeta * zeta - 1);
	double dN3_dZ = -.25*(2 * zeta - eta)*(eta - 1);
	double dN3_dE = .25*(2 * eta - zeta)*(zeta + 1);
	double dN4_dZ = -.5*(eta * eta - 1);
	double dN4_dE = -eta * (zeta + 1);
	double dN5_dZ = .25*(2 * zeta + eta)*(eta + 1);
	double dN5_dE = .25*(2 * eta + zeta)*(zeta + 1);
	double dN6_dZ = -zeta * (eta + 1);
	double dN6_dE = -.5*(zeta * zeta - 1);
	double dN7_dZ = .25*(2 * zeta - eta)*(eta + 1);
	double dN7_dE = -.25*(2 * eta - zeta)*(zeta - 1);
	double dN8_dZ = .5*(eta * eta - 1);
	double dN8_dE = eta * (zeta - 1);

	//calculate dx/dZ, dx/dE, dy/dZ, dy/dE
	double dx_dZ = dN1_dZ*x1 + dN2_dZ*x2 + dN3_dZ*x3 + dN4_dZ*x4 + dN5_dZ*x5 + dN6_dZ*x6 + dN7_dZ*x7 + dN8_dZ*x8;
	double dx_dE = dN1_dE*x1 + dN2_dE*x2 + dN3_dE*x3 + dN4_dE*x4 + dN5_dE*x5 + dN6_dE*x6 + dN7_dE*x7 + dN8_dE*x8;
	double dy_dZ = dN1_dZ*y1 + dN2_dZ*y2 + dN3_dZ*y3 + dN4_dZ*y4 + dN5_dZ*y5 + dN6_dZ*y6 + dN7_dZ*y7 + dN8_dZ*y8;
	double dy_dE = dN1_dE*y1 + dN2_dE*y2 + dN3_dE*y3 + dN4_dE*y4 + dN5_dE*y5 + dN6_dE*y6 + dN7_dE*y7 + dN8_dE*y8;

	//create Jacobian matrix
	//Jacobian[2][2] = { dx_dZ, dx_dE, dy_dZ, dy_dE };
	Jacobian[0][0] = dx_dZ;
	Jacobian[0][1] = dx_dE;
	Jacobian[1][0] = dy_dZ;
	Jacobian[1][1] = dy_dE;

	//calculate determiniate
	det_Jacob = dx_dZ*dy_dE - dx_dE*dy_dZ;

	//Place derivatives in vectors
	double vectorN1[2];
	double vectorN2[2];
	double vectorN3[2];
	double vectorN4[2];
	double vectorN5[2];
	double vectorN6[2];
	double vectorN7[2];
	double vectorN8[2];
	vectorN1[0] = dN1_dZ;
	vectorN1[1] = dN1_dE;
	vectorN2[0] = dN2_dZ;
	vectorN2[1] = dN2_dE;
	vectorN3[0] = dN3_dZ;
	vectorN3[1] = dN3_dE;
	vectorN4[0] = dN4_dZ;
	vectorN4[1] = dN4_dE;
	vectorN5[0] = dN5_dZ;
	vectorN5[1] = dN5_dE;
	vectorN6[0] = dN6_dZ;
	vectorN6[1] = dN6_dE;
	vectorN7[0] = dN7_dZ;
	vectorN7[1] = dN7_dE;
	vectorN8[0] = dN8_dZ;
	vectorN8[1] = dN8_dE;

	//Declare global vectors
	double gN1vector[2];
	double gN2vector[2];
	double gN3vector[2];
	double gN4vector[2];
	double gN5vector[2];
	double gN6vector[2];
	double gN7vector[2];
	double gN8vector[2];

	//Call matrix functions class for finding inverse of Jacobian, dN/dx, and dN/dy
	MatrixFunctions::invert(2, Jacobian, vectorN1, gN1vector);
	//operations.multiply(2,2,1, Jacobian, vectorN1, gN1vector);
	MatrixFunctions::multiply(2, 2, Jacobian, vectorN2, gN2vector);
	MatrixFunctions::multiply(2, 2, Jacobian, vectorN3, gN3vector);
	MatrixFunctions::multiply(2, 2, Jacobian, vectorN4, gN4vector);
	MatrixFunctions::multiply(2, 2, Jacobian, vectorN5, gN5vector);
	MatrixFunctions::multiply(2, 2, Jacobian, vectorN6, gN6vector);
	MatrixFunctions::multiply(2, 2, Jacobian, vectorN7, gN7vector);
	MatrixFunctions::multiply(2, 2, Jacobian, vectorN8, gN8vector);

	//Collect dN/dx and dN/dy terms
	double dN1_dx = gN1vector[0];
	double dN1_dy = gN1vector[1];
	double dN2_dx = gN2vector[0];
	double dN2_dy = gN2vector[1];
	double dN3_dx = gN3vector[0];
	double dN3_dy = gN3vector[1];
	double dN4_dx = gN4vector[0];
	double dN4_dy = gN4vector[1];
	double dN5_dx = gN5vector[0];
	double dN5_dy = gN5vector[1];
	double dN6_dx = gN6vector[0];
	double dN6_dy = gN6vector[1];
	double dN7_dx = gN7vector[0];
	double dN7_dy = gN7vector[1];
	double dN8_dx = gN8vector[0];
	double dN8_dy = gN8vector[1];

	//create and populate B matrix
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
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			B_transpose[j][i] = B_matrix[i][j];
		}
	}
}

calc_B_matrix::~calc_B_matrix()
{
	MatrixFunctions::deleteMatrix(Jacobian, 2, 2);
	MatrixFunctions::deleteMatrix(B_transpose, 16, 4);
	MatrixFunctions::deleteMatrix(B_matrix, 4, 16);
}

//Get determinant of Jacobian
double calc_B_matrix::getJacobianDet()
{
	return det_Jacob;
}

//Get B matrix
double** calc_B_matrix::getBmatrix()
{
	return B_matrix;
}

//Get transpose of B matrix
double** calc_B_matrix::getBtranspose()
{
	return B_transpose;
}
//Print info for checking purposes
void calc_B_matrix::printData(ostream &out) const
{
	out << elem_id << endl;
	out << Node1 << " " << Node2 << " " << Node3 << " " << Node4 << " " << Node5 << " " << Node6 << " " << Node7 << " " << Node8 << endl;
	out << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << " " << x6 << " " << x7 << " " << x8 << endl;
	out << y1 << " " << y2 << " " << y3 << " " << y4 << " " << y5 << " " << y6 << " " << y7 << " " << y8 << endl;
	for (int i = 0; i <2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			out << Jacobian[i][j] << " ";
		}
		out << endl;
	}
}