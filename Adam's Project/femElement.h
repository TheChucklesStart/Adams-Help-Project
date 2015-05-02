/*
 femElement

 Class femElement contains an id, pointer to a material, the number
 of nodes it has, and an array of corresponding node pointers.
 This class defines the external interface to elements.
*/

#ifndef femElement_h
#define femElement_h

//#include <iostream.h>
#include "femNode.h"
#include "femMaterial.h"
#include "utlMatrix.h"
#include "utlMatrixFull.h"
#include "utlVector.h"
#include "utlStress2D.h"
//#include "femDefine.h"

using namespace std;

class femElement	//this is a pure virtual class!
{

  protected:
	int d_id;					//element id
	femMaterial* d_material;	//ptr to the material class
	int d_numNodes;				//total number of nodes of this element. For Q8, it is 8
	femNode** d_nodes;			//array of ptrs to nodes in this element

	//never to be used constructors
	femElement();
	femElement(const femElement &elem);

  public:

	// Constructors
	femElement(int id, femMaterial* mat, int numNodes, femNode* nodes[]);

    //Destructor
    virtual ~femElement();

    // Functions
	int getID() const;		//	return d_id;
	int getNumNodes() const;	// return d_numNodes;
	void getNodes(femNode* nodes[]) const;	//set each 	nodes[i] = d_nodes[i];
	void printData(ostream &out) const;		//print any useful info
	virtual int getNumDofs() const = 0;		//implement all virtual functions in the derived classes
	virtual int getBandwidth() const = 0;
	virtual void getElementK(utlMatrix &k, femDof* dofs[],
		ostream &out) = 0;
	virtual void calcData() = 0;
	virtual void getNodalData(utlStress2D stresses[]) = 0;
	virtual void printResults(ostream &out) const = 0;
};

#endif
