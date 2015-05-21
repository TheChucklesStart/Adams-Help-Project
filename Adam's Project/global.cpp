//create and initialize global matrix outside of element loop
//numNodes = controller.getnumNodes();

//MatrixFunctions::assignMatrix global_matrix(numNodes*2, numNodes*2);

double ke_matrix[4][4];
ke_matrix[0][0] = 1;
ke_matrix[0][1] = 1;
ke_matrix[0][2] = 2;
ke_matrix[0][3] = 2;
ke_matrix[1][0] = 1;
ke_matrix[1][1] = 1;
ke_matrix[1][2] = 2;
ke_matrix[1][3] = 2;
ke_matrix[2][0] = 2;
ke_matrix[2][1] = 2;
ke_matrix[2][2] = 1;
ke_matrix[2][3] = 1;
ke_matrix[3][0] = 2;
ke_matrix[3][1] = 2;
ke_matrix[3][2] = 1;
ke_matrix[3][3] = 1;

double global_matrix[4][4];

//initialize global matrix to 0, 

for (int i = 0; i<numNodes*2; i++)
{
	for (int j = 0; j<numNodes*2; j++)
	{
		global_matrix[i][j] = 0;
	}
}

//for each element
//get ke_matrix
//get nodes1-8
//get global_matrix

for (int n = 0; n<2;n++)
{
	for (int m = 0;m<2;m++)
	{
		cout<<ke_matrix[n][m]<< " ";
	}
	cout<<endl;
}
double Node[2];
Node[0] = 2;
Node[1] = 1;
/*
Node1
Node2
Node3
Node4
Node5
Node6
Node7
Node8

//for ke_matrix row 1&2 correspond to Node 1, row 3&4 correspond to node 2...row 15&16 correspond to Node 8.  The same is true for columns i.e. column 1&2 correspond to Node1
//odd number rows & columns of ke and global matrices are x direction, even number rows and columns are y direction

/*
//convert row 1 of ke matrix to global matrix
global_matrix[Node1*2-1][Node1*2-1] = global_matrix[Node1*2-1][Node1*2-1]+ke_matrix[0][0];
global_matrix[Node1*2-1][Node1*2] = global_matrix[Node1*2-1][Node1*2]+ke_matrix[0][1];
global_matrix[Node1*2-1][Node2*2-1] = global_matrix[Node1*2-1][Node2*2-1]+ke_matrix[0][2];
global_matrix[Node1*2-1][Node2*2] = global_matrix[Node1*2-1][Node2*2]+ke_matrix[0][3];
global_matrix[Node1*2-1][Node3*2-1] = global_matrix[Node1*2-1][Node3*2-1]+ke_matrix[0][4];
global_matrix[Node1*2-1][Node3*2] = global_matrix[Node1*2-1][Node3*2]+ke_matrix[0][5];
global_matrix[Node1*2-1][Node4*2-1] = global_matrix[Node1*2-1][Node4*2-1]+ke_matrix[0][6];
global_matrix[Node1*2-1][Node4*2] = global_matrix[Node1*2-1][Node4*2]+ke_matrix[0][7];
global_matrix[Node1*2-1][Node5*2-1] = global_matrix[Node1*2-1][Node5*2-1]+ke_matrix[0][8];
global_matrix[Node1*2-1][Node5*2] = global_matrix[Node1*2-1][Node5*2]+ke_matrix[0][9];
global_matrix[Node1*2-1][Node6*2-1] = global_matrix[Node1*2-1][Node6*2-1]+ke_matrix[0][10];
global_matrix[Node1*2-1][Node6*2] = global_matrix[Node1*2-1][Node6*2]+ke_matrix[0][11];
global_matrix[Node1*2-1][Node7*2-1] = global_matrix[Node1*2-1][Node7*2-1]+ke_matrix[0][12];
global_matrix[Node1*2-1][Node7*2] = global_matrix[Node1*2-1][Node7*2]+ke_matrix[0][13];
global_matrix[Node1*2-1][Node8*2-1] = global_matrix[Node1*2-1][Node8*2-1]+ke_matrix[0][14];
global_matrix[Node1*2-1][Node8*2] = global_matrix[Node1*2-1][Node8*2]+ke_matrix[0][15];
*/

//Need to define Node[8]

//simplify row 1 conversion
for (int j = 0; j<8; j++)
{
	for (int i = 0; i<8; i++)
	{
		global_matrix[Node[j]*2-2][Node[i]*2-2] = global_matrix[Node[j]*2-2][Node[i]*2-2]+ke_matrix[2*j][2*i];
		global_matrix[Node[j]*2-2][Node[i]*2-1] = global_matrix[Node[j]*2-2][Node[i]*2-1]+ke_matrix[2*j][2*i+1];
		global_matrix[Node[j]*2-1][Node[i]*2-2] = global_matrix[Node[j]*2-1][Node[i]*2-2]+ke_matrix[2*j+1][2*i];
		global_matrix[Node[j]*2-1][Node[i]*2-1] = global_matrix[Node[j]*2-1][Node[i]*2-1]+ke_matrix[2*j+1][2*i+1];
	}
}

cout<<endl;
for (int n = 0; n<2;n++)
{
	for (int m = 0;m<2;m++)
	{
		cout<<global_matrix[n][m]<< " ";
	}
	cout<<endl;
}