// -*- C++ -*-
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//  <LicenseText>
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

#include <portinfo>
#include <string>
#include <Python.h>
#include "mpi.h"
#include "mpi/Communicator.h"
#include "Inlet.h"
#include "Outlet.h"
#include "inlets_outlets.h"

using namespace Exchanger;


char pyExchanger_Inlet_impose__doc__[] = "";
char pyExchanger_Inlet_impose__name__[] = "Inlet_impose";

PyObject * pyExchanger_Inlet_impose(PyObject *, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O:Inlet_impose", &obj))
        return NULL;

    Inlet* inlet = static_cast<Inlet*>(PyCObject_AsVoidPtr(obj));

    inlet->impose();

    Py_INCREF(Py_None);
    return Py_None;
}


char pyExchanger_Inlet_recv__doc__[] = "";
char pyExchanger_Inlet_recv__name__[] = "Inlet_recv";

PyObject * pyExchanger_Inlet_recv(PyObject *, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O:Inlet_recv", &obj))
        return NULL;

    Inlet* inlet = static_cast<Inlet*>(PyCObject_AsVoidPtr(obj));

    inlet->recv();

    Py_INCREF(Py_None);
    return Py_None;
}


char pyExchanger_Inlet_storeTimestep__doc__[] = "";
char pyExchanger_Inlet_storeTimestep__name__[] = "Inlet_storeTimestep";

PyObject * pyExchanger_Inlet_storeTimestep(PyObject *self, PyObject *args)
{
    PyObject *obj;
    double fge_t, cge_t;

    if (!PyArg_ParseTuple(args, "Odd:Inlet_storeTimestep",
                          &obj, &fge_t, &cge_t))
        return NULL;

    Inlet* inlet = static_cast<Inlet*>(PyCObject_AsVoidPtr(obj));

    inlet->storeTimestep(fge_t, cge_t);

    Py_INCREF(Py_None);
    return Py_None;
}


char pyExchanger_Outlet_send__doc__[] = "";
char pyExchanger_Outlet_send__name__[] = "Outlet_send";

PyObject * pyExchanger_Outlet_send(PyObject *, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O:Outlet_send", &obj))
        return NULL;

    Outlet* outlet = static_cast<Outlet*>(PyCObject_AsVoidPtr(obj));

    outlet->send();

    Py_INCREF(Py_None);
    return Py_None;
}


// version
// $Id: inlets_outlets.cc,v 1.1 2004/05/08 01:51:14 tan2 Exp $

// End of file
