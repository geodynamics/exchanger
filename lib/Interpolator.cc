// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  <LicenseText>
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#include <portinfo>
#include <algorithm>
#include "journal/journal.h"
#include "BoundedMesh.h"
#include "Interpolator.h"

namespace Exchanger {


    Interpolator::Interpolator(const BoundedMesh& boundedMesh,
			       Array2D<int,1>& meshNode) :
	elem_(0),
	shape_(0)
    {
	journal::debug_t debug("Exchanger");
	debug << journal::loc(__HERE__) << journal::end;

	init(boundedMesh, meshNode);
	selfTest(boundedMesh, meshNode);

	elem_.print("Exchanger-Interpolator-elem");
	shape_.print("Exchanger-Interpolator-shape");
    }


    Interpolator::~Interpolator()
    {}


    // private functions

    void Interpolator::init(const BoundedMesh& boundedMesh,
			    Array2D<int,1>& meshNode)
    {
	elem_.reserve(boundedMesh.size());
	shape_.reserve(boundedMesh.size());

	init2(boundedMesh, meshNode);
    }


    void Interpolator::selfTest(const BoundedMesh& boundedMesh,
				const Array2D<int,1>& meshNode) const
    {
	selfTest2(boundedMesh, meshNode);
    }

}


// version
// $Id: Interpolator.cc,v 1.1 2004/05/08 01:51:14 tan2 Exp $

// End of file
