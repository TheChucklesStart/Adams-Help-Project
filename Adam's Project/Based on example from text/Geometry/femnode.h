/*
 femNode

 The femNode class contains a node id, the coordinates, and pointers to the
 dofs (degrees of freedom).  There are two types of dof, UX and UY.
*/

#ifndef femNode_h
#define femNode_h

#include "femDof.h"
#include <iostream>

using namespace std;

//class femDof;

class femNode
{
  private:
	int d_id;	//node id
	double d_x, d_y;	//coordinates x and y of this node
	femDof* d_dof[2];	//ecah node contains two dofs. Therefore two pointers are used

	// Never used constructors
	femNode();
	femNode(const femNode& node);

  public:

	// Constructors
	femNode(int id);

    // Destructor
    virtual ~femNode();

    // Functions
	int getID() const;					//return d_id;
	void setCoords(double x, double y);	//set d_x = x, d_y = y;
    double getX() const;				//return d_x;
	double getY() const;				//return d_y;
	femDof* getDof(DOFType dof) const;	//return d_dof[dof];
	void printData(ostream &out) const;	//print useful info
	void printResults(ostream &out) const;	//print useful results
};

#endif
