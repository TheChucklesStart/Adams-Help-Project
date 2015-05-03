/* 
 femDof

 This class implements the degree of freedom.  It stores a value, an
 equation number, and a flag whether it is active (to be solved).  The 
 assumption is that if the node is not active, then the value is an
 essential boundary condition.
*/

#ifndef femDof_h
#define femDof_h
#include <iostream>

using namespace std;

enum DOFType {UX=0, UY};

class femDof
{
  private:
	double d_value;	//the value of this degree of freedom (either UX or UY). For essential BC (inactive), it is specified by user. For active dof, it stores the displacement value after the system equation is solved.
	int d_eqn;		//the equation number of this dof
	bool d_active;	//	d_active = true for active dof, = false for inactive dof
	//never used copy constructor
	femDof (femDof &dof);

  public:
	// Constructors
	femDof();
    //Destructor
    virtual ~femDof();
    // Functions
	void setNotActive();	//set d_active = false;
	bool isActive() const;	//	return d_active;
	int setEqn(int currEqn);	//for active dof, set d_eqn = currEqn, and ibrement currEgn by 1; for inactive dof, set d_eqn = -1 (any negative integer)
	void setEqnXin(int count);	//for active dof, set d_eqn = count, and ibrement currEgn by 1; for inactive dof, set d_eqn = -1 (any negative integer)
	int getEqn() const;		//	return d_eqn;
	void setValue(double value);	//	set d_value = value;
	double getValue() const;		//	return d_value;
	void print(ostream &out) const;	//print any useful info
};

#endif
