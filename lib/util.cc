// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  <LicenseText>
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#include <portinfo>
#include <Python.h>
#include "mpi.h"
#include "mpi/Communicator.h"
#include "mpi/Group.h"
#include "BoundedBox.h"
#include "Convertor.h"
#include "DIM.h"
#include "UtilTemplate.h"
#include "Utility.h"
#include "util.h"

void deleteBoundedBox(void*);
using namespace Exchanger;


char pyExchanger_exchangeBoundedBox__doc__[] = "";
char pyExchanger_exchangeBoundedBox__name__[] = "exchangeBoundedBox";

PyObject * pyExchanger_exchangeBoundedBox(PyObject *, PyObject *args)
{
    PyObject *obj0, *obj1, *obj2;
    int target;

    if (!PyArg_ParseTuple(args, "OOOi:exchangeBoundedBox",
			  &obj0, &obj1, &obj2, &target))
	return NULL;

    BoundedBox* bbox = static_cast<BoundedBox*>(PyCObject_AsVoidPtr(obj0));

    mpi::Communicator* temp1 = static_cast<mpi::Communicator*>
  	                       (PyCObject_AsVoidPtr(obj1));
    MPI_Comm mycomm = temp1->handle();

    const int leader = 0;
    int rank;
    MPI_Comm_rank(mycomm, &rank);

    // copy contents of bbox to newbbox
    BoundedBox* newbbox = new BoundedBox(*bbox);

    if(rank == leader) {
	mpi::Communicator* temp2 = static_cast<mpi::Communicator*>
	                           (PyCObject_AsVoidPtr(obj2));
	MPI_Comm intercomm = temp2->handle();

	// convert before sending
	Convertor& convertor = Convertor::instance();
	convertor.coordinate(*newbbox);

	util::exchange(intercomm, target, *newbbox);

	// unconvert after receiving
	convertor.xcoordinate(*newbbox);
    }

    util::broadcast(mycomm, leader, *newbbox);
    newbbox->print("Exchanger-util-RemoteBBox");

    PyObject *cobj = PyCObject_FromVoidPtr(newbbox, deleteBoundedBox);
    return Py_BuildValue("O", cobj);
}


char pyExchanger_exchangeSignal__doc__[] = "";
char pyExchanger_exchangeSignal__name__[] = "exchangeSignal";

PyObject * pyExchanger_exchangeSignal(PyObject *, PyObject *args)
{
    int signal;
    PyObject *obj1, *obj2;
    int target;

    if (!PyArg_ParseTuple(args, "iOOi:exchangeTimestep",
			  &signal, &obj1, &obj2, &target))
	return NULL;

    mpi::Communicator* temp1 = static_cast<mpi::Communicator*>
	                       (PyCObject_AsVoidPtr(obj1));
    MPI_Comm mycomm = temp1->handle();

    const int leader = 0;
    int rank;
    MPI_Comm_rank(mycomm, &rank);

    if(rank == leader) {
	mpi::Communicator* temp2 = static_cast<mpi::Communicator*>
	                           (PyCObject_AsVoidPtr(obj2));
	MPI_Comm intercomm = temp2->handle();

	util::exchange(intercomm, target, signal);
    }

    util::broadcast(mycomm, leader, signal);

    return Py_BuildValue("i", signal);
}


char pyExchanger_exchangeTimestep__doc__[] = "";
char pyExchanger_exchangeTimestep__name__[] = "exchangeTimestep";

PyObject * pyExchanger_exchangeTimestep(PyObject *, PyObject *args)
{
    double dt;
    PyObject *obj1, *obj2;
    int target;

    if (!PyArg_ParseTuple(args, "dOOi:exchangeTimestep",
			  &dt, &obj1, &obj2, &target))
	return NULL;

    mpi::Communicator* temp1 = static_cast<mpi::Communicator*>
  	                       (PyCObject_AsVoidPtr(obj1));
    MPI_Comm mycomm = temp1->handle();

    const int leader = 0;
    int rank;
    MPI_Comm_rank(mycomm, &rank);

    if(rank == leader) {
	mpi::Communicator* temp2 = static_cast<mpi::Communicator*>
	                           (PyCObject_AsVoidPtr(obj2));
	MPI_Comm intercomm = temp2->handle();

	Convertor& convertor = Convertor::instance();
	convertor.time(dt);

	util::exchange(intercomm, target, dt);

	convertor.xtime(dt);
    }

    util::broadcast(mycomm, leader, dt);

    return Py_BuildValue("d", dt);
}


// helper functions

void deleteBoundedBox(void* p)
{
    delete static_cast<BoundedBox*>(p);
}


// version
// $Id: util.cc,v 1.1.1.1 2004/05/08 01:51:14 tan2 Exp $

// End of file
