/* 
 femData

 This class stores all the finite element model data.  The user requests
 needed data from this class.
*/

#ifndef femData_h
#define femData_h

//#include <iostream>
//#include "femDefine.h"
#include "femNode.h"
#include "femMaterial.h"
#include "femElement.h"
#include "femEssentialBC.h"
#include "femPointBC.h"
#include "femNaturalBC.h"
#include "utlMatrix.h"
#include "utlVector.h"

using namespace std;

class femData
{
  private:
	femNode** d_nodes;		//array of ptrs to node class (femNode)
	femMaterial** d_matprops; //array of ptrs to material class (femMaterial)
	femElement** d_elems;		//array of ptrs to element class (femElement)
	femEssentialBC** d_essentialBCs;	//array of ptrs to essential B.C. class (femEssentialBC)
	femPointBC** d_pointBCs;	//array of prts to point force B.C. class (femPointBC)
	femNaturalBC** d_naturalBCs;	//array of prts to natural B.C. class (femNaturalBC)
	char* d_title;		//title of the fem run
	int d_numNodes;	//total number of nodes of the fem model
	int d_numMats;		//total number of materials of the fem model
	int d_numElems;	//total number of elements of the fem model
	int d_probType;	//problem type, =0 for axisymmetric (irrelevant in this course); =1 for plane stress; =2 for plane strain.
	int d_numEssentialBCs;		//number of essential B.C. of the fem model
	int d_numPointBCs;			//number of point force B.C.
	int d_numNaturalBCs;		//number of natural B.C
	int d_neq;					//number of equations
	int d_bandw;				//band width of the matrix (irrelevant) 

  public:
	// Constructors
	femData();
    //Destructor
    virtual ~femData();
    // Functions
	void readData(istream &inp);	//read all input data
	void writeData(ostream &out);	//write the output data, see standard "finite.out" for format
	int getProbType();			//return d_probType
	int getNumNodes();			//return d_numNodes
	int getNumElems();			//return d_numElems
	int getNumEssentialBCs();	//return d_numEssentialBCs
	int getNumPointBCs();		//return d_numPointBCs
	int getNumNaturalBCs();	//return d_numNaturalBCs
	femNode *getNode(int node);					//return d_nodes[node]
	femElement *getElem(int elem);				//return d_elems[elem]
	femEssentialBC *getEssentialBC(int ebc);		//return d_essentialBCs[ebc]
	femPointBC *getPointBC(int pbc);				//return d_pointBCs[pbc]
	femNaturalBC *getNaturalBC(int nbc);			//return d_naturalBCs[nbc]
	void setBandwidth(int value);		//irrelevant
	void setNumEquation(int value);	//set d_neq = value
	void writeResults(ostream &out);	//output results data, see standard "finite.out" for format
	void writePlotFile(ostream &plt);	//write the output data for contour plot program "ConPlot". see "finite.con for format.
};

#endif
