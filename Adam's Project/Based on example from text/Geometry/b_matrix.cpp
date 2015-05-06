//define derivatives of nodal equations dNi/dZ and dNi/dE
double dN1_dZ = -.25*(2*zeta[i]+eta[j])*(eta[j]-1);
double dN1_dE = -.25*(2*eta[j]+zeta[i])*(zeta[i]-1);
double dN2_dZ = zeta[i]*(eta[j]-1);
double dN2_dE = .5*(zeta[i]*zeta[i]-1);
double dN3_dZ = -.25*(2*zeta[i]-eta[j])*(eta[j]-1);
double dN3_dE = .25*(2*eta[j]-zeta[i])*(zeta[i]+1);
double dN4_dZ = -.5*(eta[j]*eta[j]-1);
double dN4_dE = -eta[j]*(zeta[i]+1);
double dN5_dZ = .25*(2*zeta[i]+eta[j])*(eta[j]+1);
double dN5_dE = .25*(2*eta[j]+zeta[i])*(zeta[i]+1);
double dN6_dZ = -zeta[i]*(eta[j]+1);
double dN6_dE = -.5*(zeta[i]*zeta[i]-1);
double dN7_dZ = .25*(2*zeta[i]-eta[j])*(eta[j]+1);
double dN7_dE = -.25*(2*eta[j]-zeta[i])*(zeta[i]-1);
double dN8_dZ = .5*(eta[j]*eta[j]-1);
double dN8_dE = eta[j]*(zeta[i]-1);

//Nodal arrays
double vectorN1[1][2];
double vectorN2[1][2];
double vectorN3[1][2];
double vectorN4[1][2];
double vectorN5[1][2];
double vectorN6[1][2];
double vectorN7[1][2];
double vectorN8[1][2];
vectorN1[0][0] = dN1_dZ;
vectorN1[0][1] = dN1_dE;
vectorN2[0][0] = dN2_dZ;
vectorN2[0][1] = dN2_dE;
vectorN3[0][0] = dN3_dZ;
vectorN3[0][1] = dN3_dE;
vectorN4[0][0] = dN4_dZ;
vectorN4[0][1] = dN4_dE;
vectorN5[0][0] = dN5_dZ;
vectorN5[0][1] = dN5_dE;
vectorN6[0][0] = dN6_dZ;
vectorN6[0][1] = dN6_dE;
vectorN7[0][0] = dN7_dZ;
vectorN7[0][1] = dN7_dE;
vectorN8[0][0] = dN8_dZ;
vectorN8[0][1] = dN8_dE;

//define dx/dZ, dx/dE, dy/dZ, dy/dE
double dx_dZ = dN1_dZ*x1+dN2_dZ*x2+dN3_dZ*x3+dN4_dZ*x4+dN5_dZ*x5+dN6_dZ*x6+dN7_dZ*x7+dN8_dZ*x8;
double dx_dE = dN1_dE*x1+dN2_dE*x2+dN3_dE*x3+dN4_dE*x4+dN5_dE*x5+dN6_dE*x6+dN7_dE*x7+dN8_dE*x8;
double dy_dZ = dN1_dZ*y1+dN2_dZ*y2+dN3_dZ*y3+dN4_dZ*y4+dN5_dZ*y5+dN6_dZ*y6+dN7_dZ*y7+dN8_dZ*y8;
double dy_dE = dN1_dE*y1+dN2_dE*y2+dN3_dE*y3+dN4_dE*y4+dN5_dE*y5+dN6_dE*y6+dN7_dE*y7+dN8_dE*y8;

//define Javobian
double Jacobian[2][2];
Jacobian[0][0] = dx_dZ;
Jacobian[0][1] = dx_dE;
Jacobian[1][0] = dy_dZ;
Jacobian[1][1] = dy_dE;

//determinate of jacobian
det_jacob = dx_dZ*dy_dE-dx_dE*dy_dZ;

//invert jacobian via function
//invert function
jacobian_inverse

//multiply jacobian inverse by nodal array
//matrix multiplication function
//create globalvectorN vectors

global_vectorN1[1][2];
global_vectorN2[1][2];
global_vectorN3[1][2];
global_vectorN4[1][2];
global_vectorN5[1][2];
global_vectorN6[1][2];
global_vectorN7[1][2];
global_vectorN8[1][2];
global_vectorN1[0][0] = dN1_dx;
global_vectorN1[0][1] = dN1_dy;
global_vectorN2[0][0] = dN2_dx;
global_vectorN2[0][1] = dN2_dy;
global_vectorN3[0][0] = dN3_dx;
global_vectorN3[0][1] = dN3_dy;
global_vectorN4[0][0] = dN4_dx;
global_vectorN4[0][1] = dN4_dy;
global_vectorN5[0][0] = dN5_dx;
global_vectorN5[0][1] = dN5_dy;
global_vectorN6[0][0] = dN6_dx;
global_vectorN6[0][1] = dN6_dy;
global_vectorN7[0][0] = dN7_dx;
global_vectorN7[0][1] = dN7_dy;
global_vectorN8[0][0] = dN8_dx;
global_vectorN8[0][1] = dN8_dy;

//create B matrix
double b_matrix[3][16];
b_matrix[0][0] = dN1_dx;
b_matrix[0][1] = 0;
b_matrix[0][2] = dN2_dx;
b_matrix[0][3] = 0;
b_matrix[0][4] = dN13dx;
b_matrix[0][5] = 0;
b_matrix[0][6] = dN14dx;
b_matrix[0][7] = 0;
b_matrix[0][8] = dN15dx;
b_matrix[0][9] = 0;
b_matrix[0][10] = dN6_dx;
b_matrix[0][11] = 0;
b_matrix[0][12] = dN7_dx;
b_matrix[0][13] = 0;
b_matrix[0][14] = dN8_dx;
b_matrix[0][15] = 0;
b_matrix[1][0] = 0;
b_matrix[1][1] = dN1_dy;
b_matrix[1][2] = 0;
b_matrix[1][3] = dN2_dy;
b_matrix[1][4] = 0;
b_matrix[1][5] = dN3_dy;
b_matrix[1][6] = 0;
b_matrix[1][7] = dN4_dy;
b_matrix[1][8] = 0;
b_matrix[1][9] = dN5_dy;
b_matrix[1][10] = 0;
b_matrix[1][11] = dN6_dy;
b_matrix[1][12] = 0;
b_matrix[1][13] = dN7_dy;
b_matrix[1][14] = 0;
b_matrix[1][15] = dN8_dy;
b_matrix[2][0] = dN1_dy;
b_matrix[2][1] = dN1_dx;
b_matrix[2][2] = dN2_dy;
b_matrix[2][3] = dN2_dx;
b_matrix[2][4] = dN3_dy;
b_matrix[2][5] = dN3_dx;
b_matrix[2][6] = dN4_dy;
b_matrix[2][7] = dN4_dx;
b_matrix[2][8] = dN5_dy;
b_matrix[2][9] = dN5_dx;
b_matrix[2][10] = dN6_dy;
b_matrix[2][11] = dN6_dx;
b_matrix[2][12] = dN7_dy;
b_matrix[2][13] = dN7_dx;
b_matrix[2][14] = dN8_dy;
b_matrix[2][15] = dN8_dx;

for (int i = 0; i<2; i++)
{
	for (int j = 0; j<15; j++)
	{
		b_inverse[j][i] = b_matrix[i][j];
	}
}