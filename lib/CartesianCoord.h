// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  <LicenseText>
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#if !defined(pyCitcom_CartesianCoord_h)
#define pyCitcom_CartesianCoord_h

#include "Array2D.h"
#include "BoundedBox.h"
#include "DIM.h"

namespace Exchanger {

    class BoundedMesh;


    class CartesianCoord {

    public:
	CartesianCoord() {};
	virtual ~CartesianCoord() {};

	// Transform to cartesian coordinate system from spherical system
	virtual void coordinate(BoundedBox& bbox) const = 0;
	virtual void coordinate(Array2D<double,DIM>& X) const = 0;
	virtual void vector(Array2D<double,DIM>& V,
			    const Array2D<double,DIM>& X) const = 0;

	// Transform to spherical coordinate system from cartesian system
	virtual void xcoordinate(BoundedBox& bbox) const = 0;
	virtual void xcoordinate(Array2D<double,DIM>& X) const = 0;
	virtual void xvector(Array2D<double,DIM>& V,
			     const Array2D<double,DIM>& X) const = 0;

    private:
	// disable
	CartesianCoord(const CartesianCoord&);
	CartesianCoord& operator=(const CartesianCoord&);

    };


}


#endif

// version
// $Id: CartesianCoord.h,v 1.1.1.1 2004/05/08 01:51:14 tan2 Exp $

// End of file
