#!/usr/bin/env python
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
# <LicenseText>
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#


# factory
def layout(name="layout", facility="layout"):
    return Layout(name, facility)



from pyre.components.Component import Component



class Layout(Component):


    def __init__(self, name, facility):
        Component.__init__(self, name, facility)

        self.coarse = None
        self.fine = None
        self.coarsePlus = []
        self.finePlus = []
        return



    def initialize(self, application):
        self.verify(application)
        self.createCommunicators()
        return



    def verify(self, application):
        size = len(self.inventory.fine) + len(self.inventory.coarse)
        nodes = application.inventory.staging.inventory.nodes

        if nodes != size:
            import journal
            firewall = journal.firewall("layout")
            firewall.log("processor count mismatch: %d != %d" % (nodes, size))

        if nodes < 2:
            import journal
            firewall = journal.firewall("layout")
            firewall.log("'%s' requires at least 2 processors"
                         % application.inventory.name)
        return



    def createCommunicators(self):
	import mpi
        world = mpi.world()
        fineGroup = self.inventory.fine
        coarseGroup = self.inventory.coarse

        self.fine = world.include(fineGroup)
        self.coarse = world.include(coarseGroup)

        for each in coarseGroup:
            self.finePlus.append(world.include(fineGroup + [each]))

        for each in fineGroup:
            self.coarsePlus.append(world.include(coarseGroup + [each]))

        return



    class Inventory(Component.Inventory):

        import pyre.properties

        inventory = [

            pyre.properties.sequence("coarse", [0]),
            pyre.properties.sequence("fine", [1]),

            ]


# version
__id__ = "$Id: Layout.py,v 1.1 2004/05/18 23:12:26 tan2 Exp $"

# End of file
