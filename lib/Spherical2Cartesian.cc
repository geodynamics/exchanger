// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  <LicenseText>
//
// Purpose:
// Transformation from Spherical to Euclidean coordinate system
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#include <portinfo>
#include <vector>
#include "journal/journal.h"
#include "Spherical2Cartesian.h"


namespace Exchanger {


    Spherical2Cartesian::Spherical2Cartesian()
    {}


    Spherical2Cartesian::~Spherical2Cartesian()
    {}


    void Spherical2Cartesian::coordinate(BoundedBox& bbox) const
    {
	BoundedBox bbox_tmp(bbox);

	std::vector<double> xt(DIM),xc(DIM);

	for(int i=0; i<2; i++)
	    for(int j=0; j<DIM; j++) {
		if(i==0) bbox[0][j] = 1.e27;
		if(i==1) bbox[1][j] = -1.e27;
	    }

	for(int a=0; a<2; a++) {
	    xt[0] = bbox_tmp[a][0];

	    // Degenerate case for theta (xt[0])

	    //         if((a==0) && ((bbox_tmp[0][0] < M_PI) &&(bbox_tmp[1][0] > M_PI))) xt[0]=M_PI;
	    //         if((a==1) && ((bbox_tmp[0][0] < 0) &&(bbox_tmp[1][0] > 0))) xt[0]=0;

	    for(int b=0; b<2; b++) {
		xt[1] = bbox_tmp[b][1];
		for(int c=0; c<2; c++) {
		    xt[2] = bbox_tmp[c][2];
		    xc[2] = xt[2] * cos(xt[0]);
		    if( (c==1) &&  (bbox_tmp[0][0] < M_PI/2.) &&
			(bbox_tmp[1][0] > M_PI/2.) )
			xt[0] = M_PI/2.;
		    xc[0] = xt[2] * sin(xt[0]) * cos(xt[1]);
		    xc[1] = xt[2] * sin(xt[0]) * sin(xt[1]);
	
		    for(int j=0;j<DIM;j++) {
			if(xc[j] < bbox[0][j]) bbox[0][j] = xc[j];
			if(xc[j] > bbox[1][j]) bbox[1][j] = xc[j];
		    }

		    // Degenerate case for phi (xt[1])
		    if(c==1 &&  bbox_tmp[0][0] < M_PI/2. &&  bbox_tmp[1][0] > M_PI/2.)xt[0]=M_PI/2.;
		    if(c==1 &&  bbox_tmp[0][1]< 0 &&  bbox_tmp[1][1]> 0)xc[0] = xt[2] * sin(xt[0]);
		    if(c==1 && bbox_tmp[0][1]< M_PI/2. &&  bbox_tmp[1][1]> M_PI/2.) xc[1] = xt[2] * sin(xt[0]);
		    if(c==0 &&  bbox_tmp[0][1]< M_PI && bbox_tmp[1][1]> M_PI) xc[0] = -1.*xt[2] * sin(xt[0]);
		    if(c==0 &&  bbox_tmp[0][1]< 1.5*M_PI &&  bbox_tmp[1][1]> 1.5*M_PI) xc[1] = -1.*xt[2] * sin(xt[0]);

		    for(int j=0;j<DIM;j++) {
			if(xc[j] < bbox[0][j]) bbox[0][j] = xc[j];
			if(xc[j] > bbox[1][j]) bbox[1][j] = xc[j];
		    }

		}
	    }
	}
    }


    void Spherical2Cartesian::coordinate(Array2D<double,DIM>& X) const
    {
	std::vector<double> xt(DIM);

	for(int i=0; i<X.size(); ++i) {

	    for(int j=0; j<DIM; j++)
		xt[j] = X[j][i];

	    X[0][i] = xt[2] * sin(xt[0]) * cos(xt[1]);
	    X[1][i] = xt[2] * sin(xt[0]) * sin(xt[1]);
	    X[2][i] = xt[2] * cos(xt[0]);
	}
    }


    void Spherical2Cartesian::vector(Array2D<double,DIM>& V,
				     const Array2D<double,DIM>& X) const
    {
	std::vector<double> vt(DIM);
	std::vector<double> xt(DIM);

	// sanity check
	if(V.size() != X.size()) {
	    journal::firewall_t firewall("Spherical2Cartesian");
	    firewall << journal::loc(__HERE__)
		     << "size of vectors mismatch" << journal::end;
	}

	for(int i=0; i<V.size(); ++i) {

	    for(int j=0; j<DIM; j++) {
		vt[j] = V[j][i];
		xt[j] = X[j][i];
	    }

	    V[0][i] = cos(xt[0]) * cos(xt[1]) * vt[0]
	        - sin(xt[1]) * vt[1]
	        + sin(xt[0]) * cos(xt[1]) * vt[2];
	    V[1][i] = cos(xt[0]) * sin(xt[1]) * vt[0]
	        + cos(xt[1]) * vt[1]
	        + sin(xt[0]) * sin(xt[1]) * vt[2];
	    V[2][i] = -sin(xt[0]) * vt[0]
	        + cos(xt[0]) * vt[2];
	}
    }


    // Transformation from Euclidean to Spherical coordinate system

    void Spherical2Cartesian::xcoordinate(BoundedBox& bbox) const
    {
	BoundedBox bbox_tmp(bbox);
	double minrad;
	std::vector<double> xt(DIM), xc(DIM);
	for(int i=0; i<2; i++)
	    for(int j=0; j<DIM; j++) {
		if(i==0) bbox[0][j] = 1.e27;
		if(i==1) bbox[1][j] = -1.e27;
		minrad = 1.e27;
	    }

	for(int a=0; a<2; a++) {
	    xt[0] = bbox_tmp[a][0];

	    for(int b=0; b<2; b++) {
		xt[1] = bbox_tmp[b][1];
		for(int c=0; c<2; c++) {
		    xt[2] = bbox_tmp[c][2];
	      
		    xc[2] = std::sqrt(xt[0]*xt[0] + xt[1]*xt[1] + xt[2]*xt[2]);
		    xc[1] = std::atan2(xt[1], xt[0]);
		    xc[0] = std::acos(xt[2] / xc[2]);
	      
		    for(int j=0;j<DIM;j++) {
		  
			if(minrad > fabs(xt[j])) minrad = fabs(xt[j]);
			if(xc[j] < bbox[0][j]) bbox[0][j] = xc[j];
			if(xc[j] > bbox[1][j]) bbox[1][j] = xc[j];
		    }
	      
		}
	    }
	}
	bbox[0][2] = minrad;
    }


    void Spherical2Cartesian::xcoordinate(Array2D<double,DIM>& X) const
    {
	std::vector<double> xt(DIM);

	for(int i=0; i<X.size(); ++i) {

	    for(int j=0; j<DIM; j++)
		xt[j] = X[j][i];

	    X[2][i] = std::sqrt(xt[0]*xt[0] + xt[1]*xt[1] + xt[2]*xt[2]);
	    X[1][i] = std::atan2(xt[1], xt[0]);
	    X[0][i] = std::acos(xt[2] / X[2][i]);
	}
    }


    void Spherical2Cartesian::xvector(Array2D<double,DIM>& V,
				      const Array2D<double,DIM>& X) const
    {
	std::vector<double> vt(DIM);
	std::vector<double> xt(DIM);

	// sanity check
	if(V.size() != X.size()) {
	    journal::firewall_t firewall("Spherical2Cartesian");
	    firewall << journal::loc(__HERE__)
		     << "size of vectors mismatch" << journal::end;
	}

	for(int i=0; i<V.size(); ++i) {

	    for(int j=0; j<DIM; j++) {
		vt[j] = V[j][i];
		xt[j] = X[j][i];
	    }

	    V[0][i] = cos(xt[0]) * cos(xt[1]) * vt[0]
	        + cos(xt[0]) * sin(xt[1]) * vt[1]
	        - sin(xt[0]) * vt[2];
	    V[1][i] = -sin(xt[0]) * vt[0]
	        + cos(xt[1]) * vt[1];
	    V[2][i] = sin(xt[0]) * cos(xt[1]) * vt[0]
	        + sin(xt[0]) * sin(xt[1]) * vt[1]
	        + cos(xt[0]) * vt[2];
	}
    }

}


// version
// $Id: Spherical2Cartesian.cc,v 1.1 2004/05/08 01:51:14 tan2 Exp $

// End of file
