// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  <LicenseText>
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#include "journal/journal.h"
#include "Utility.h"

namespace Exchanger {

    namespace util {

	MPI_Status waitRequest(const MPI_Request& request)
	{
	    MPI_Status status;
	    int result = MPI_Wait(const_cast<MPI_Request*>(&request), &status);
	    testResult(result, "wait error!");

	    return status;
	}


	std::vector<MPI_Status>
	waitRequest(const std::vector<MPI_Request>& request)
	{
	    std::vector<MPI_Status> status(request.size());
	    int result = MPI_Waitall(request.size(),
				     const_cast<MPI_Request*>(&request[0]), &status[0]);
	    testResult(result, "wait error!");

	    return status;
	}


	void testResult(int result, const std::string& errmsg)
	{
	    if (result != MPI_SUCCESS) {
		journal::error_t error("Exchanger-Utility");
		error << journal::loc(__HERE__) << errmsg << journal::end;
		throw result;
	    }
	}


    }
}

// version
// $Id: Utility.cc,v 1.2 2005/03/11 22:42:43 steve Exp $

// End of file
