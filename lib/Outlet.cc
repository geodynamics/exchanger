// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  <LicenseText>
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#include <portinfo>
#include "Source.h"
#include "Outlet.h"


namespace Exchanger {


    Outlet::Outlet(const Source& src) :
	source(src)
    {}


    Outlet::~Outlet()
    {}


}

// version
// $Id: Outlet.cc,v 1.1 2004/05/08 01:51:14 tan2 Exp $

// End of file
