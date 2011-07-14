# @file    TestAssignmentRule.rb
# @brief   AssignmentRule unit tests
#
# @author  Akiya Jouraku (Ruby conversion)
# @author  Ben Bornstein 
#
#
# ====== WARNING ===== WARNING ===== WARNING ===== WARNING ===== WARNING ======
#
# DO NOT EDIT THIS FILE.
#
# This file was generated automatically by converting the file located at
# src/sbml/test/TestAssignmentRule.c
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
require 'test/unit'
require 'libSBML'

class TestAssignmentRule < Test::Unit::TestCase

  def setup
    @@ar = LibSBML::AssignmentRule.new(2,4)
    if (@@ar == nil)
    end
  end

  def teardown
    @@ar = nil
  end

  def test_AssignmentRule_L2_create
    assert( @@ar.getTypeCode() == LibSBML::SBML_ASSIGNMENT_RULE )
    assert( @@ar.getMetaId() == "" )
    assert( @@ar.getNotes() == nil )
    assert( @@ar.getAnnotation() == nil )
    assert( @@ar.getFormula() == "" )
    assert( @@ar.getMath() == nil )
    assert( @@ar.getVariable() == "" )
    assert( @@ar.getType() == LibSBML::RULE_TYPE_SCALAR )
  end

  def test_AssignmentRule_createWithFormula
    ar = LibSBML::AssignmentRule.new(2,4)
    ar.setVariable( "s")
    ar.setFormula( "1 + 1")
    assert( ar.getTypeCode() == LibSBML::SBML_ASSIGNMENT_RULE )
    assert( ar.getMetaId() == "" )
    assert ((  "s" == ar.getVariable() ))
    math = ar.getMath()
    assert( math != nil )
    formula = LibSBML::formulaToString(math)
    assert( formula != nil )
    assert ((  "1 + 1" == formula ))
    assert (( formula == ar.getFormula() ))
    ar = nil
  end

  def test_AssignmentRule_createWithMath
    math = LibSBML::parseFormula("1 + 1")
    ar = LibSBML::AssignmentRule.new(2,4)
    ar.setVariable( "s")
    ar.setMath(math)
    assert( ar.getTypeCode() == LibSBML::SBML_ASSIGNMENT_RULE )
    assert( ar.getMetaId() == "" )
    assert ((  "s" == ar.getVariable() ))
    assert ((  "1 + 1" == ar.getFormula() ))
    assert( ar.getMath() != math )
    ar = nil
  end

  def test_AssignmentRule_createWithNS
    xmlns = LibSBML::XMLNamespaces.new()
    xmlns.add( "http://www.sbml.org", "testsbml")
    sbmlns = LibSBML::SBMLNamespaces.new(2,1)
    sbmlns.addNamespaces(xmlns)
    object = LibSBML::AssignmentRule.new(sbmlns)
    assert( object.getTypeCode() == LibSBML::SBML_ASSIGNMENT_RULE )
    assert( object.getMetaId() == "" )
    assert( object.getNotes() == nil )
    assert( object.getAnnotation() == nil )
    assert( object.getLevel() == 2 )
    assert( object.getVersion() == 1 )
    assert( object.getNamespaces() != nil )
    assert( object.getNamespaces().getLength() == 2 )
    object = nil
  end

  def test_AssignmentRule_free_NULL
  end

  def test_AssignmentRule_setVariable
    variable =  "x";
    @@ar.setVariable(variable)
    assert (( variable == @@ar.getVariable() ))
    assert_equal true, @@ar.isSetVariable()
    if (@@ar.getVariable() == variable)
    end
    @@ar.setVariable(@@ar.getVariable())
    assert (( variable == @@ar.getVariable() ))
    @@ar.setVariable("")
    assert_equal false, @@ar.isSetVariable()
    if (@@ar.getVariable() != nil)
    end
  end

end

