// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  <LicenseText>
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#include <portinfo>
#include <stdexcept>
#include "journal/journal.h"
#include "SIUnit.h"


namespace Exchanger {


    SIUnit::SIUnit()
    {}


    SIUnit::~SIUnit()
    {}


    void SIUnit::coordinate(BoundedBox& bbox) const
    {
	for(int i=0; i<2; ++i)
	    bbox[i][DIM-1] *= length_factor;
    }


    void SIUnit::coordinate(Array2D<double,DIM>& X) const
    {
	for(int i=0; i<X.size(); ++i)
	    X[DIM-1][i] *= length_factor;
    }


    void SIUnit::temperature(Array2D<double,1>& T) const
    {
	for(int i=0; i<T.size(); ++i) {
	    T[0][i] *= temperature_factor;
	    T[0][i] += temperature_offset;
	}
    }


    void SIUnit::time(double& t) const
    {
	t *= time_factor;
    }


    void SIUnit::traction(Array2D<double,DIM>& F) const
    {
	for(int i=0; i<F.size(); ++i)
	    for(int d=0; d<DIM; ++d)
		F[d][i] *= traction_factor;
    }


    void SIUnit::velocity(Array2D<double,DIM>& V) const
    {
	for(int i=0; i<V.size(); ++i)
	    for(int d=0; d<DIM; ++d)
		V[d][i] *= velocity_factor;
    }


    void SIUnit::xcoordinate(BoundedBox& bbox) const
    {
	for(int i=0; i<2; ++i)
	    bbox[i][DIM-1] /= length_factor;
    }


    void SIUnit::xcoordinate(Array2D<double,DIM>& X) const
    {
	for(int i=0; i<X.size(); ++i)
	    X[DIM-1][i] /= length_factor;
    }


    void SIUnit::xtemperature(Array2D<double,1>& T) const
    {
	for(int i=0; i<T.size(); ++i) {
	    T[0][i] -= temperature_offset;
	    T[0][i] /= temperature_factor;
	}
    }


    void SIUnit::xtime(double& t) const
    {
	t /= time_factor;
    }


    void SIUnit::xtraction(Array2D<double,DIM>& F) const
    {
	for(int i=0; i<F.size(); ++i)
	    for(int d=0; d<DIM; ++d)
		F[d][i] /= traction_factor;
    }


    void SIUnit::xvelocity(Array2D<double,DIM>& V) const
    {
	for(int i=0; i<V.size(); ++i)
	    for(int d=0; d<DIM; ++d)
		V[d][i] /= velocity_factor;
    }


}


// version
// $Id: SIUnit.cc,v 1.1.1.1 2004/05/08 01:51:14 tan2 Exp $

// End of file
