// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  <LicenseText>
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#if !defined(pyExchanger_Boundary_h)
#define pyExchanger_Boundary_h

#include "BoundedMesh.h"


namespace Exchanger {

    class Boundary : public BoundedMesh {
	Array2D<int,DIM> normal_;

    public:
	Boundary();
	virtual ~Boundary() = 0;

	inline int normal(int d, int n) const {return normal_[d][n];}

	virtual void broadcast(const MPI_Comm& comm, int broadcaster);
	virtual void broadcast(const MPI_Comm& comm, int broadcaster) const;
	virtual void recv(const MPI_Comm& comm, int sender);
	virtual void send(const MPI_Comm& comm, int receiver) const;

    private:
	Boundary(const Boundary&);
	Boundary& operator=(const Boundary&);

    };

}


#endif

// version
// $Id: Boundary.h,v 1.1 2004/05/08 01:51:14 tan2 Exp $

// End of file
