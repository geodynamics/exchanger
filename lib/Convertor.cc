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
#include "CartesianCoord.h"
#include "SIUnit.h"
#include "Convertor.h"


namespace Exchanger {


    // definition of static variables
    SIUnit* Convertor::si = 0;
    CartesianCoord* Convertor::cart = 0;
    bool Convertor::inited = false;


    // the singleton
    Convertor& Convertor::instance()
    {
	static Convertor* handle;

	if(!handle) {
	    if(!inited) {
 		journal::firewall_t firewall("Convertor");
 		firewall << journal::loc(__HERE__)
 			 << "instance() is called before init()" << journal::end;
		throw std::domain_error("Convertor");
	    }

 	    journal::debug_t debug("Exchanger");
 	    debug << journal::loc(__HERE__) << journal::end;

	    handle = new Convertor();
	}
	return *handle;
    }


    Convertor::Convertor()
    {}


    Convertor::~Convertor()
    {
	delete si;
	si = 0;
	delete cart;
	cart = 0;

	inited = false;
    }


    // internal representation ==> standard representation

    void Convertor::coordinate(BoundedBox& bbox) const
    {
	if(si) si->coordinate(bbox);
	if(cart) cart->coordinate(bbox);
    }


    void Convertor::coordinate(BoundingBox& bbox) const
    {
	if(si) si->coordinate(bbox);
	if(cart) cart->coordinate(bbox);
    }


    void Convertor::coordinate(Array2D<double,DIM>& X) const
    {
	if(si) si->coordinate(X);
	if(cart) cart->coordinate(X);
    }


    void Convertor::temperature(Array2D<double,1>& T) const
    {
	if(si) si->temperature(T);
    }


    void Convertor::time(double& t) const
    {
	if(si) si->time(t);
    }


    void Convertor::traction(Array2D<double,DIM>& F,
			     const Array2D<double,DIM>& X) const
    {
	if(si) si->traction(F);
	if(cart) cart->vector(F, X);
    }


    void Convertor::velocity(Array2D<double,DIM>& V,
			     const Array2D<double,DIM>& X) const
    {
	if(si) si->velocity(V);
	if(cart) cart->vector(V, X);
    }


    // standard representation ==> internal representation

    void Convertor::xcoordinate(BoundedBox& bbox) const
    {
	if(cart) cart->xcoordinate(bbox);
	if(si) si->xcoordinate(bbox);
    }


    void Convertor::xcoordinate(BoundingBox& bbox) const
    {
	if(cart) cart->xcoordinate(bbox);
	if(si) si->xcoordinate(bbox);
    }


    void Convertor::xcoordinate(Array2D<double,DIM>& X) const
    {
	if(cart) cart->xcoordinate(X);
	if(si) si->xcoordinate(X);
    }


    void Convertor::xtemperature(Array2D<double,1>& T) const
    {
	if(si) si->xtemperature(T);
    }


    void Convertor::xtime(double& t) const
    {
	if(si) si->xtime(t);
    }


    void Convertor::xtraction(Array2D<double,DIM>& F,
			      const Array2D<double,DIM>& X) const
    {
	if(cart) cart->xvector(F, X);
	if(si) si->xtraction(F);
    }


    void Convertor::xvelocity(Array2D<double,DIM>& V,
			      const Array2D<double,DIM>& X) const
    {
	if(cart) cart->xvector(V, X);
	if(si) si->xvelocity(V);
    }

}


// version
// $Id: Convertor.cc,v 1.4 2004/07/22 04:11:42 tan2 Exp $

// End of file
