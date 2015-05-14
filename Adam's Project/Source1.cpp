/*
converting the nodal equations from local coordinates to global coordinates for an element requires multiplying the local nodal equations by a 2x2 Jacobian matrix.  The values of the jacobian matrix are 
created by multiplying the x and y coordinates of each node in the element by the corresponding nodal equations: i.e. dx/dZ=sum(dNi/dZ*xi), dx/dE=sum(dNi/dE*xi), dy/dZ=sum(dNi/dZ*yi), dy/dE=sum(dNi/dE*yi)
Once the Jacobian is built, it must be inverted so it can be multiplied by 1x2 vectors made up of the local nodal equations.  The resulting 1x2 vectors are the global nodal equations.

The nodal equations have 2 variables zeta and eta.  normally, once all the matrices have been assembled they are integrated twice, first w.r.t. eta from -1 to 1, then w.r.t. zeta from -1 to 1.  
Since c++ can't do integration in the  traditional sense, 2-point Gaussian Numerical Integration is used.  This requires substituing values into zeta and eta, and multiplying by a weighting factor.  
*/

//define gaussian points and weights
double zeta[2];
double eta[2];
double weight[2];

zeta[0] = 0.577350269189626; // ~1/sqrt(3)
zeta[1] = -0.577350269189626; // ~-1/sqrt(3)
eta[0] = 0.577350269189626; // ~1/sqrt(3)
eta[1] = -0.577350269189626; // ~-1/sqrt(3)
weight[0] = 1;
weight[1] = 1;

//Begin Coordinate conversion
for (int k = 0; k < numElements; k++)//how to call numElements?
{
	//get nodes of the element
	Node[l]

	//get nodal coords
	double x1 = nodeData[l].x;
	double y1 = nodeData[l].y;
	double x2 = nodeData[l].x;
	double y2 = nodeData[l].y;
	double x3 = nodeData[l].x;
	double y3 = nodeData[l].y;
	double x4 = nodeData[l].x;
	double y4 = nodeData[l].y;
	double x5 = nodeData[l].x;
	double y5 = nodeData[l].y;
	double x6 = nodeData[l].x;
	double y6 = nodeData[l].y;
	double x7 = nodeData[l].x;
	double y7 = nodeData[l].y;
	double x8 = nodeData[l].x;
	double y8 = nodeData[l].y;


	//define derivatives of nodal coordinates
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

	//Place derivatives in vectors for later converstion
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

	//calculate dx/dZ, dx/dE, dy/dZ, dy/dE
	double dx_dZ = dN1_dZ*x1 + dN2_dZ*x2 + dN3_dZ*x3 + dN4_dZ*x4 + dN5_dZ*x5 + dN6_dZ*x6 + dN7_dZ*x7 + dN8_dZ*x8;
	double dx_dE = dN1_dE*x1 + dN2_dE*x2 + dN3_dE*x3 + dN4_dE*x4 + dN5_dE*x5 + dN6_dE*x6 + dN7_dE*x7 + dN8_dE*x8;
	double dy_dZ = dN1_dZ*y1 + dN2_dZ*y2 + dN3_dZ*y3 + dN4_dZ*y4 + dN5_dZ*y5 + dN6_dZ*y6 + dN7_dZ*y7 + dN8_dZ*y8;
	double dy_dE = dN1_dE*y1 + dN2_dE*y2 + dN3_dE*y3 + dN4_dE*y4 + dN5_dE*y5 + dN6_dE*y6 + dN7_dE*y7 + dN8_dE*y8;

	//create Jacobian matrix
	double Jacobian[2][2] = { dx_dZ, dx_dE, dy_dZ, dy_dE };

	//calculate determiniate
	double det_J = dx_dZ*dy_dE-dx_dE*dy_dZ;

	//invert and multiply
	//inversion function(Jacobian);
	//multiplication function(Jacobian, vector); run 8 times
}	
