// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  <LicenseText>
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#if !defined(pyExchanger_Interpolator_h)
#define pyExchanger_Interpolator_h

#include "Array2D.h"
#include "BoundedBox.h"
#include "DIM.h"

namespace Exchanger {

    class BoundedMesh;
    static const int NODES_PER_ELEMENT = 8; // pow(2, DIM);


    class Interpolator {
    protected:
	Array2D<int,1> elem_;  // elem # from which fields are interpolated
	Array2D<double,NODES_PER_ELEMENT> shape_; // shape functions for interpolation

    public:
	Interpolator(const BoundedMesh& boundedMesh,
		     Array2D<int,1>& meshNode);
	virtual ~Interpolator();

	inline int size() const {return elem_.size();}
	virtual void interpolateDisplacement(Array2D<double,DIM>& D) = 0;
	virtual void interpolateForce(Array2D<double,DIM>& F) = 0;
	virtual void interpolateHeatflux(Array2D<double,DIM>& H) = 0;
	virtual void interpolatePressure(Array2D<double,1>& P) = 0;
	virtual void interpolateStress(Array2D<double,STRESS_DIM>& S) = 0;
	virtual void interpolateTemperature(Array2D<double,1>& T) = 0;
	virtual void interpolateTraction(Array2D<double,DIM>& F) = 0;
	virtual void interpolateVelocity(Array2D<double,DIM>& V) = 0;

    private:
	void init(const BoundedMesh& boundedMesh,
		  Array2D<int,1>& meshNode);
	
	void selfTest(const BoundedMesh& boundedMesh,
		      const Array2D<int,1>& meshNode) const;
	
	virtual void init2(const BoundedMesh& boundedMesh,
			  Array2D<int,1>& meshNode) = 0;
	
	virtual void selfTest2(const BoundedMesh& boundedMesh,
		      const Array2D<int,1>& meshNode) const = 0
;
	// disable copy c'tor and assignment operator
	Interpolator(const Interpolator&);
	Interpolator& operator=(const Interpolator&);

    };

}

#endif

// version
// $Id: Interpolator.h,v 1.1 2004/05/08 01:51:14 tan2 Exp $

// End of file
