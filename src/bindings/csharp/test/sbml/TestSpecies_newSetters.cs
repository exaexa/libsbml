///  @file    TestSpecies_newSetters.cs
///  @brief   Species unit tests for new set function API
///  @author  Frank Bergmann (Csharp conversion)
///  @author  Akiya Jouraku (Csharp conversion)
///  @author  Sarah Keating 
/// 
/// 
///  ====== WARNING ===== WARNING ===== WARNING ===== WARNING ===== WARNING ======
/// 
///  DO NOT EDIT THIS FILE.
/// 
///  This file was generated automatically by converting the file located at
///  src/sbml/test/TestSpecies_newSetters.c
///  using the conversion program dev/utilities/translateTests/translateTests.pl.
///  Any changes made here will be lost the next time the file is regenerated.
/// 
///  -----------------------------------------------------------------------------
///  This file is part of libSBML.  Please visit http://sbml.org for more
///  information about SBML, and the latest version of libSBML.
/// 
///  Copyright 2005-2010 California Institute of Technology.
///  Copyright 2002-2005 California Institute of Technology and
///                      Japan Science and Technology Corporation.
///  
///  This library is free software; you can redistribute it and/or modify it
///  under the terms of the GNU Lesser General Public License as published by
///  the Free Software Foundation.  A copy of the license agreement is provided
///  in the file named "LICENSE.txt" included with this software distribution
///  and also available online as http://sbml.org/software/libsbml/license.html
///  -----------------------------------------------------------------------------


namespace LibSBMLCSTest.sbml {

  using libsbmlcs;

  using System;

  using System.IO;

  public class TestSpecies_newSetters {
    public class AssertionError : System.Exception 
    {
      public AssertionError() : base()
      {
        
      }
    }


    static void assertTrue(bool condition)
    {
      if (condition == true)
      {
        return;
      }
      throw new AssertionError();
    }

    static void assertEquals(object a, object b)
    {
      if ( (a == null) && (b == null) )
      {
        return;
      }
      else if ( (a == null) || (b == null) )
      {
        throw new AssertionError();
      }
      else if (a.Equals(b))
      {
        return;
      }
  
      throw new AssertionError();
    }

    static void assertNotEquals(object a, object b)
    {
      if ( (a == null) && (b == null) )
      {
        throw new AssertionError();
      }
      else if ( (a == null) || (b == null) )
      {
        return;
      }
      else if (a.Equals(b))
      {
        throw new AssertionError();
      }
    }

    static void assertEquals(bool a, bool b)
    {
      if ( a == b )
      {
        return;
      }
      throw new AssertionError();
    }

    static void assertNotEquals(bool a, bool b)
    {
      if ( a != b )
      {
        return;
      }
      throw new AssertionError();
    }

    static void assertEquals(int a, int b)
    {
      if ( a == b )
      {
        return;
      }
      throw new AssertionError();
    }

    static void assertNotEquals(int a, int b)
    {
      if ( a != b )
      {
        return;
      }
      throw new AssertionError();
    }

    private Species C;

    public void setUp()
    {
      C = new  Species(1,2);
      if (C == null);
      {
      }
    }

    public void tearDown()
    {
      C = null;
    }

    public void test_Species_setBoundaryCondition1()
    {
      int i = C.setBoundaryCondition(false);
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertTrue( C.getBoundaryCondition() == false );
      i = C.setBoundaryCondition(true);
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertTrue( C.getBoundaryCondition() == true );
    }

    public void test_Species_setCharge1()
    {
      int i = C.setCharge(2);
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( true, C.isSetCharge() );
      assertTrue( C.getCharge() == 2 );
      i = C.unsetCharge();
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, C.isSetCharge() );
    }

    public void test_Species_setCharge2()
    {
      Species c = new  Species(2,2);
      int i = c.setCharge(4);
      assertTrue( i == libsbml.LIBSBML_UNEXPECTED_ATTRIBUTE );
      assertEquals( false, c.isSetCharge() );
      c = null;
    }

    public void test_Species_setCharge3()
    {
      Species c = new  Species(2,1);
      int i = c.unsetCharge();
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, c.isSetCharge() );
      c = null;
    }

    public void test_Species_setCompartment1()
    {
      int i = C.setCompartment( "1cell");
      assertTrue( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE );
      assertEquals( false, C.isSetCompartment() );
      i = C.setCompartment( "");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, C.isSetCompartment() );
    }

    public void test_Species_setCompartment2()
    {
      int i = C.setCompartment( "cell");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( true, C.isSetCompartment() );
      i = C.setCompartment( "");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, C.isSetCompartment() );
    }

    public void test_Species_setConstant1()
    {
      int i = C.setConstant(false);
      assertTrue( i == libsbml.LIBSBML_UNEXPECTED_ATTRIBUTE );
      assertTrue( C.getConstant() == false );
    }

    public void test_Species_setConstant2()
    {
      Species c = new  Species(2,2);
      int i = c.setConstant(true);
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertTrue( c.getConstant() == true );
      c = null;
    }

    public void test_Species_setHasOnlySubstanceUnits1()
    {
      int i = C.setHasOnlySubstanceUnits(false);
      assertTrue( C.getHasOnlySubstanceUnits() == false );
      assertTrue( i == libsbml.LIBSBML_UNEXPECTED_ATTRIBUTE );
    }

    public void test_Species_setHasOnlySubstanceUnits2()
    {
      Species c = new  Species(2,2);
      int i = c.setHasOnlySubstanceUnits(false);
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertTrue( c.getHasOnlySubstanceUnits() == false );
      i = c.setHasOnlySubstanceUnits(true);
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertTrue( c.getHasOnlySubstanceUnits() == true );
      c = null;
    }

    public void test_Species_setId2()
    {
      Species c = new  Species(2,2);
      int i = c.setId( "1cell");
      assertTrue( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE );
      assertEquals( false, c.isSetId() );
      c = null;
    }

    public void test_Species_setId3()
    {
      Species c = new  Species(2,2);
      int i = c.setId( "cell");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( true, c.isSetId() );
      assertTrue((  "cell"  == c.getId() ));
      c = null;
    }

    public void test_Species_setId4()
    {
      Species c = new  Species(2,2);
      int i = c.setId( "cell");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( true, c.isSetId() );
      assertTrue((  "cell"  == c.getId() ));
      i = c.setId("");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, c.isSetId() );
      c = null;
    }

    public void test_Species_setInitialAmount1()
    {
      int i = C.setInitialAmount(2.0);
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertTrue( C.getInitialAmount() == 2.0 );
      assertEquals( true, C.isSetInitialAmount() );
      i = C.unsetInitialAmount();
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, C.isSetInitialAmount() );
    }

    public void test_Species_setInitialAmount2()
    {
      Species c = new  Species(2,2);
      int i = c.setInitialAmount(4);
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertTrue( c.getInitialAmount() == 4.0 );
      assertEquals( true, c.isSetInitialAmount() );
      i = c.unsetInitialAmount();
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, c.isSetInitialAmount() );
      c = null;
    }

    public void test_Species_setInitialConcentration1()
    {
      int i = C.setInitialConcentration(2.0);
      assertTrue( i == libsbml.LIBSBML_UNEXPECTED_ATTRIBUTE );
      assertEquals( false, C.isSetInitialConcentration() );
    }

    public void test_Species_setInitialConcentration2()
    {
      Species c = new  Species(2,2);
      int i = c.setInitialConcentration(4);
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertTrue( c.getInitialConcentration() == 4 );
      assertEquals( true, c.isSetInitialConcentration() );
      i = c.unsetInitialConcentration();
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, c.isSetInitialConcentration() );
      c = null;
    }

    public void test_Species_setName1()
    {
      int i = C.setName( "cell");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( true, C.isSetName() );
      i = C.unsetName();
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, C.isSetName() );
    }

    public void test_Species_setName2()
    {
      Species c = new  Species(2,2);
      int i = c.setName( "1cell");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( true, c.isSetName() );
      i = c.unsetName();
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, c.isSetName() );
      c = null;
    }

    public void test_Species_setName3()
    {
      int i = C.setName( "cell");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( true, C.isSetName() );
      i = C.setName("");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, C.isSetName() );
    }

    public void test_Species_setSpatialSizeUnits1()
    {
      int i = C.setSpatialSizeUnits( "mm");
      assertTrue( i == libsbml.LIBSBML_UNEXPECTED_ATTRIBUTE );
      assertEquals( false, C.isSetSpatialSizeUnits() );
    }

    public void test_Species_setSpatialSizeUnits2()
    {
      Species c = new  Species(2,2);
      int i = c.setSpatialSizeUnits( "1cell");
      assertTrue( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE );
      assertEquals( false, c.isSetSpatialSizeUnits() );
      c = null;
    }

    public void test_Species_setSpatialSizeUnits3()
    {
      Species c = new  Species(2,2);
      int i = c.setSpatialSizeUnits( "mole");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertTrue((  "mole" == c.getSpatialSizeUnits() ));
      assertEquals( true, c.isSetSpatialSizeUnits() );
      c = null;
    }

    public void test_Species_setSpatialSizeUnits4()
    {
      Species c = new  Species(2,2);
      int i = c.setSpatialSizeUnits("");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, c.isSetSpatialSizeUnits() );
      c = null;
    }

    public void test_Species_setSpeciesType1()
    {
      int i = C.setSpeciesType( "cell");
      assertTrue( i == libsbml.LIBSBML_UNEXPECTED_ATTRIBUTE );
      assertEquals( false, C.isSetSpeciesType() );
      i = C.unsetSpeciesType();
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, C.isSetSpeciesType() );
    }

    public void test_Species_setSpeciesType2()
    {
      Species c = new  Species(2,2);
      int i = c.setSpeciesType( "1cell");
      assertTrue( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE );
      assertEquals( false, c.isSetSpeciesType() );
      i = c.unsetSpeciesType();
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, c.isSetSpeciesType() );
      c = null;
    }

    public void test_Species_setSpeciesType3()
    {
      Species c = new  Species(2,2);
      int i = c.setSpeciesType( "cell");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( true, c.isSetSpeciesType() );
      assertTrue((  "cell"  == c.getSpeciesType() ));
      i = c.unsetSpeciesType();
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, c.isSetSpeciesType() );
      c = null;
    }

    public void test_Species_setSpeciesType4()
    {
      Species c = new  Species(2,2);
      int i = c.setSpeciesType( "cell");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( true, c.isSetSpeciesType() );
      assertTrue((  "cell"  == c.getSpeciesType() ));
      i = c.setSpeciesType("");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, c.isSetSpeciesType() );
      c = null;
    }

    public void test_Species_setSubstanceUnits1()
    {
      int i = C.setSubstanceUnits( "mm");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( true, C.isSetSubstanceUnits() );
    }

    public void test_Species_setSubstanceUnits2()
    {
      Species c = new  Species(2,2);
      int i = c.setSubstanceUnits( "1cell");
      assertTrue( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE );
      assertEquals( false, c.isSetSubstanceUnits() );
      c = null;
    }

    public void test_Species_setSubstanceUnits3()
    {
      Species c = new  Species(2,2);
      int i = c.setSubstanceUnits( "mole");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertTrue((  "mole" == c.getSubstanceUnits() ));
      assertEquals( true, c.isSetSubstanceUnits() );
      c = null;
    }

    public void test_Species_setSubstanceUnits4()
    {
      Species c = new  Species(2,2);
      int i = c.setSubstanceUnits( "mole");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertTrue((  "mole" == c.getSubstanceUnits() ));
      assertEquals( true, c.isSetSubstanceUnits() );
      i = c.setSubstanceUnits("");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, c.isSetSubstanceUnits() );
      c = null;
    }

    public void test_Species_setUnits1()
    {
      int i = C.setUnits( "1cell");
      assertTrue( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE );
      assertEquals( false, C.isSetUnits() );
      i = C.unsetUnits();
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, C.isSetUnits() );
    }

    public void test_Species_setUnits2()
    {
      int i = C.setUnits( "litre");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( true, C.isSetUnits() );
      i = C.unsetUnits();
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, C.isSetUnits() );
    }

    public void test_Species_setUnits3()
    {
      int i = C.setUnits( "litre");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( true, C.isSetUnits() );
      i = C.setUnits("");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, C.isSetUnits() );
    }

  }
}
