// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  <LicenseText>
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#if !defined(pyExchanger_Spherical2Cartesian_h)
#define pyExchanger_Spherical2Cartesian_h

#include "Array2D.h"
#include "BoundedBox.h"
#include "CartesianCoord.h"
#include "DIM.h"


namespace Exchanger {


    class Spherical2Cartesian : public CartesianCoord {

    public:
	Spherical2Cartesian();
	virtual ~Spherical2Cartesian();

	// Transform to cartesian coordinate system from spherical system
	virtual void coordinate(BoundedBox& bbox) const;
	virtual void coordinate(Array2D<double,DIM>& X) const;
	virtual void vector(Array2D<double,DIM>& V,
			    const Array2D<double,DIM>& X) const;
    
	// Transform to spherical coordinate system from cartesian system
	virtual void xcoordinate(BoundedBox& bbox) const;
	virtual void xcoordinate(Array2D<double,DIM>& X) const;
	virtual void xvector(Array2D<double,DIM>& V,
			     const Array2D<double,DIM>& X) const;

    private:
	// disable
	Spherical2Cartesian(const Spherical2Cartesian&);
	Spherical2Cartesian& operator=(const Spherical2Cartesian&);

    };


}


#endif

// version
// $Id: Spherical2Cartesian.h,v 1.1.1.1 2004/05/08 01:51:14 tan2 Exp $

// End of file
