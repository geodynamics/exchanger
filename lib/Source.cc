// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  <LicenseText>
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#include <portinfo>
#include "journal/journal.h"
#include "BoundedMesh.h"
#include "Interpolator.h"
#include "Source.h"


namespace Exchanger {

    Source::Source(MPI_Comm c, int sinkrank,
		   BoundedMesh& mesh, const BoundedBox& mybbox) :
	comm(c),
	sinkRank(sinkrank)
    {}


    Source::~Source()
    {
	delete interp;
    }


    // protected functions

    void Source::init(BoundedMesh& mesh, const BoundedBox& mybbox)
    {
	recvMesh(mesh, mybbox);
	if(isOverlapped(mesh.bbox(), mybbox)) {
	    createInterpolator(mesh);
	    meshNode_.print("meshNode");
	}
	sendMeshNode();
	initX(mesh);
    }


    void Source::recvMesh(BoundedMesh& mesh, const BoundedBox& mybbox)
    {
#if 1
	// assuming sink is broadcasting mesh to every source
	mesh.broadcast(comm, sinkRank);

#else
	BoundedBox bbox = mybbox;
	util::exchange(comm, sinkRank, bbox);

	if(isOverlapped(mybbox, bbox)) {
	    mesh.receive(comm, source[i]);
	    createInterpolator(mesh);
	}

#endif
    }


    void Source::sendMeshNode() const
    {
	meshNode_.sendSize(comm, sinkRank);
	send(meshNode_);
    }


    void Source::initX(const BoundedMesh& mesh)
    {
	X_.resize(meshNode_.size());

	for(int i=0; i<X_.size(); ++i) {
	    int n = meshNode_[0][i];
	    for(int j=0; j<DIM; ++j)
		X_[j][i] = mesh.X(j,n);
	}
    }

}


// version
// $Id: Source.cc,v 1.1 2004/05/08 01:51:14 tan2 Exp $

// End of file
