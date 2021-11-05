#
# @file    TestReadFromFile1.py
# @brief   Reads tests/l1v1-branch.xml into memory and tests it.
#
# @author  Akiya Jouraku (Python conversion)
# @author  Ben Bornstein 
# 
# ====== WARNING ===== WARNING ===== WARNING ===== WARNING ===== WARNING ======
#
# DO NOT EDIT THIS FILE.
#
# This file was generated automatically by converting the file located at
# src/sbml/test/TestReadFromFile1.c
# using the conversion program dev/utilities/translateTests/translateTests.pl.
# Any changes made here will be lost the next time the file is regenerated.
#
# -----------------------------------------------------------------------------
# This file is part of libSBML.  Please visit http://sbml.org for more
# information about SBML, and the latest version of libSBML.
#
# Copyright 2005-2010 California Institute of Technology.
# Copyright 2002-2005 California Institute of Technology and
#                     Japan Science and Technology Corporation.
# 
# This library is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation.  A copy of the license agreement is provided
# in the file named "LICENSE.txt" included with this software distribution
# and also available online as http://sbml.org/software/libsbml/license.html
# -----------------------------------------------------------------------------

import sys
import unittest
import libsbml


class TestReadFromFile1(unittest.TestCase):


  def test_read_l1v1_branch(self):
    filename = "../../sbml/test/test-data/l1v1-branch.xml"
    d = libsbml.readSBML(filename)
    if (d == None):
      pass    
    self.assertTrue( d.getLevel() == 1 )
    self.assertTrue( d.getVersion() == 1 )
    m = d.getModel()
    self.assertTrue((  "Branch" == m.getName() ))
    self.assertTrue( m.getNumCompartments() == 1 )
    c = m.getCompartment(0)
    self.assertTrue((  "compartmentOne" == c.getName() ))
    self.assertTrue( c.getVolume() == 1 )
    ud = c.getDerivedUnitDefinition()
    self.assertTrue( ud.getNumUnits() == 1 )
    self.assertTrue( ud.getUnit(0).getKind() == libsbml.UNIT_KIND_LITRE )
    self.assertTrue( m.getNumSpecies() == 4 )
    s = m.getSpecies(0)
    self.assertTrue((  "S1"              == s.getName() ))
    self.assertTrue((  "compartmentOne"  == s.getCompartment() ))
    self.assertTrue( s.getInitialAmount() == 0 )
    self.assertTrue( s.getBoundaryCondition() == False )
    ud = s.getDerivedUnitDefinition()
    self.assertTrue( ud.getNumUnits() == 2 )
    self.assertTrue( ud.getUnit(0).getKind() == libsbml.UNIT_KIND_MOLE )
    self.assertTrue( ud.getUnit(0).getExponent() == 1 )
    self.assertTrue( ud.getUnit(1).getKind() == libsbml.UNIT_KIND_LITRE )
    self.assertTrue( ud.getUnit(1).getExponent() == -1 )
    s = m.getSpecies(1)
    self.assertTrue((  "X0"              == s.getName() ))
    self.assertTrue((  "compartmentOne"  == s.getCompartment() ))
    self.assertTrue( s.getInitialAmount() == 0 )
    self.assertTrue( s.getBoundaryCondition() == True )
    s = m.getSpecies(2)
    self.assertTrue((  "X1"              == s.getName() ))
    self.assertTrue((  "compartmentOne"  == s.getCompartment() ))
    self.assertTrue( s.getInitialAmount() == 0 )
    self.assertTrue( s.getBoundaryCondition() == True )
    s = m.getSpecies(3)
    self.assertTrue((  "X2"              == s.getName() ))
    self.assertTrue((  "compartmentOne"  == s.getCompartment() ))
    self.assertTrue( s.getInitialAmount() == 0 )
    self.assertTrue( s.getBoundaryCondition() == True )
    self.assertTrue( m.getNumReactions() == 3 )
    r = m.getReaction(0)
    self.assertTrue((  "reaction_1" == r.getName() ))
    self.assertTrue( r.getReversible() == False )
    self.assertTrue( r.getFast() == False )
    ud = r.getKineticLaw().getDerivedUnitDefinition()
    self.assertTrue( ud.getNumUnits() == 2 )
    self.assertTrue( ud.getUnit(0).getKind() == libsbml.UNIT_KIND_MOLE )
    self.assertTrue( ud.getUnit(0).getExponent() == 1 )
    self.assertTrue( ud.getUnit(1).getKind() == libsbml.UNIT_KIND_LITRE )
    self.assertTrue( ud.getUnit(1).getExponent() == -1 )
    self.assertTrue( r.getKineticLaw().containsUndeclaredUnits() == True )
    r = m.getReaction(1)
    self.assertTrue((  "reaction_2" == r.getName() ))
    self.assertTrue( r.getReversible() == False )
    self.assertTrue( r.getFast() == False )
    r = m.getReaction(2)
    self.assertTrue((  "reaction_3" == r.getName() ))
    self.assertTrue( r.getReversible() == False )
    self.assertTrue( r.getFast() == False )
    r = m.getReaction(0)
    self.assertTrue( r.getNumReactants() == 1 )
    self.assertTrue( r.getNumProducts() == 1 )
    sr = r.getReactant(0)
    self.assertTrue((  "X0" == sr.getSpecies() ))
    self.assertTrue( sr.getStoichiometry() == 1 )
    self.assertTrue( sr.getDenominator() == 1 )
    sr = r.getProduct(0)
    self.assertTrue((  "S1" == sr.getSpecies() ))
    self.assertTrue( sr.getStoichiometry() == 1 )
    self.assertTrue( sr.getDenominator() == 1 )
    kl = r.getKineticLaw()
    self.assertTrue((  "k1 * X0" == kl.getFormula() ))
    self.assertTrue( kl.getNumParameters() == 1 )
    p = kl.getParameter(0)
    self.assertTrue((  "k1" == p.getName() ))
    self.assertTrue( p.getValue() == 0 )
    r = m.getReaction(1)
    self.assertTrue( r.getNumReactants() == 1 )
    self.assertTrue( r.getNumProducts() == 1 )
    sr = r.getReactant(0)
    self.assertTrue((  "S1" == sr.getSpecies() ))
    self.assertTrue( sr.getStoichiometry() == 1 )
    self.assertTrue( sr.getDenominator() == 1 )
    sr = r.getProduct(0)
    self.assertTrue((  "X1" == sr.getSpecies() ))
    self.assertTrue( sr.getStoichiometry() == 1 )
    self.assertTrue( sr.getDenominator() == 1 )
    kl = r.getKineticLaw()
    self.assertTrue((  "k2 * S1" == kl.getFormula() ))
    self.assertTrue( kl.getNumParameters() == 1 )
    p = kl.getParameter(0)
    self.assertTrue((  "k2" == p.getName() ))
    self.assertTrue( p.getValue() == 0 )
    r = m.getReaction(2)
    self.assertTrue( r.getNumReactants() == 1 )
    self.assertTrue( r.getNumProducts() == 1 )
    sr = r.getReactant(0)
    self.assertTrue((  "S1" == sr.getSpecies() ))
    self.assertTrue( sr.getStoichiometry() == 1 )
    self.assertTrue( sr.getDenominator() == 1 )
    sr = r.getProduct(0)
    self.assertTrue((  "X2" == sr.getSpecies() ))
    self.assertTrue( sr.getStoichiometry() == 1 )
    self.assertTrue( sr.getDenominator() == 1 )
    kl = r.getKineticLaw()
    self.assertTrue((  "k3 * S1" == kl.getFormula() ))
    self.assertTrue( kl.getNumParameters() == 1 )
    p = kl.getParameter(0)
    self.assertTrue((  "k3" == p.getName() ))
    self.assertTrue( p.getValue() == 0 )
    _dummyList = [ d ]; _dummyList[:] = []; del _dummyList
    pass  

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestReadFromFile1))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)
