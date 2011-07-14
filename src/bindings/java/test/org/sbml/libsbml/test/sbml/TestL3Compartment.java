/*
 * @file    TestL3Compartment.java
 * @brief   L3 Compartment unit tests
 *
 * @author  Akiya Jouraku (Java conversion)
 * @author  Sarah Keating 
 * 
 * ====== WARNING ===== WARNING ===== WARNING ===== WARNING ===== WARNING ======
 *
 * DO NOT EDIT THIS FILE.
 *
 * This file was generated automatically by converting the file located at
 * src/sbml/test/TestL3Compartment.c
 * using the conversion program dev/utilities/translateTests/translateTests.pl.
 * Any changes made here will be lost the next time the file is regenerated.
 *
 * -----------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright 2005-2010 California Institute of Technology.
 * Copyright 2002-2005 California Institute of Technology and
 *                     Japan Science and Technology Corporation.
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * -----------------------------------------------------------------------------
 */

package org.sbml.libsbml.test.sbml;

import org.sbml.libsbml.*;

import java.io.File;
import java.lang.AssertionError;

public class TestL3Compartment {

  static void assertTrue(boolean condition) throws AssertionError
  {
    if (condition == true)
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertEquals(Object a, Object b) throws AssertionError
  {
    if ( (a == null) && (b == null) )
    {
      return;
    }
    else if ( (a == null) || (b == null) )
    {
      throw new AssertionError();
    }
    else if (a.equals(b))
    {
      return;
    }

    throw new AssertionError();
  }

  static void assertNotEquals(Object a, Object b) throws AssertionError
  {
    if ( (a == null) && (b == null) )
    {
      throw new AssertionError();
    }
    else if ( (a == null) || (b == null) )
    {
      return;
    }
    else if (a.equals(b))
    {
      throw new AssertionError();
    }
  }

  static void assertEquals(boolean a, boolean b) throws AssertionError
  {
    if ( a == b )
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertNotEquals(boolean a, boolean b) throws AssertionError
  {
    if ( a != b )
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertEquals(int a, int b) throws AssertionError
  {
    if ( a == b )
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertNotEquals(int a, int b) throws AssertionError
  {
    if ( a != b )
    {
      return;
    }
    throw new AssertionError();
  }
  private Compartment C;

  public boolean isnan(double x)
  {
    return (x != x);
  }

  protected void setUp() throws Exception
  {
    C = new  Compartment(3,1);
    if (C == null);
    {
    }
  }

  protected void tearDown() throws Exception
  {
    C = null;
  }

  public void test_L3_Compartment_NS()
  {
    assertTrue( C.getNamespaces() != null );
    assertTrue( C.getNamespaces().getLength() == 1 );
    assertTrue(C.getNamespaces().getURI(0).equals(    "http://www.sbml.org/sbml/level3/version1/core"));
  }

  public void test_L3_Compartment_constant()
  {
    assertTrue( C.isSetConstant() == false );
    C.setConstant(true);
    assertTrue( C.getConstant() == true );
    assertTrue( C.isSetConstant() == true );
    C.setConstant(false);
    assertTrue( C.getConstant() == false );
    assertTrue( C.isSetConstant() == true );
  }

  public void test_L3_Compartment_create()
  {
    assertTrue( C.getTypeCode() == libsbml.SBML_COMPARTMENT );
    assertTrue( C.getMetaId().equals("") == true );
    assertTrue( C.getNotes() == null );
    assertTrue( C.getAnnotation() == null );
    assertTrue( C.getId().equals("") == true );
    assertTrue( C.getName().equals("") == true );
    assertTrue( C.getUnits().equals("") == true );
    assertTrue( C.getOutside().equals("") == true );
    assertEquals( true, isnan(C.getSpatialDimensionsAsDouble()) );
    assertEquals( true, isnan(C.getVolume()) );
    assertTrue( C.getConstant() == true );
    assertEquals( false, C.isSetId() );
    assertEquals( false, C.isSetSpatialDimensions() );
    assertEquals( false, C.isSetName() );
    assertEquals( false, C.isSetSize() );
    assertEquals( false, C.isSetVolume() );
    assertEquals( false, C.isSetUnits() );
    assertEquals( false, C.isSetOutside() );
    assertEquals( false, C.isSetConstant() );
  }

  public void test_L3_Compartment_createWithNS()
  {
    XMLNamespaces xmlns = new  XMLNamespaces();
    xmlns.add( "http://www.sbml.org", "testsbml");
    SBMLNamespaces sbmlns = new  SBMLNamespaces(3,1);
    sbmlns.addNamespaces(xmlns);
    Compartment c = new  Compartment(sbmlns);
    assertTrue( c.getTypeCode() == libsbml.SBML_COMPARTMENT );
    assertTrue( c.getMetaId().equals("") == true );
    assertTrue( c.getNotes() == null );
    assertTrue( c.getAnnotation() == null );
    assertTrue( c.getLevel() == 3 );
    assertTrue( c.getVersion() == 1 );
    assertTrue( c.getNamespaces() != null );
    assertTrue( c.getNamespaces().getLength() == 2 );
    assertTrue( c.getId().equals("") == true );
    assertTrue( c.getName().equals("") == true );
    assertTrue( c.getUnits().equals("") == true );
    assertTrue( c.getOutside().equals("") == true );
    assertEquals( true, isnan(c.getSpatialDimensionsAsDouble()) );
    assertEquals( true, isnan(c.getVolume()) );
    assertTrue( c.getConstant() == true );
    assertEquals( false, c.isSetId() );
    assertEquals( false, c.isSetSpatialDimensions() );
    assertEquals( false, c.isSetName() );
    assertEquals( false, c.isSetSize() );
    assertEquals( false, c.isSetVolume() );
    assertEquals( false, c.isSetUnits() );
    assertEquals( false, c.isSetOutside() );
    assertEquals( false, c.isSetConstant() );
    c = null;
  }

  public void test_L3_Compartment_free_NULL()
  {
  }

  public void test_L3_Compartment_hasRequiredAttributes()
  {
    Compartment c = new  Compartment(3,1);
    assertEquals( false, c.hasRequiredAttributes() );
    c.setId( "id");
    assertEquals( false, c.hasRequiredAttributes() );
    c.setConstant(false);
    assertEquals( true, c.hasRequiredAttributes() );
    c = null;
  }

  public void test_L3_Compartment_id()
  {
    String id =  "mitochondria";
    assertEquals( false, C.isSetId() );
    C.setId(id);
    assertTrue(C.getId().equals(id));
    assertEquals( true, C.isSetId() );
    if (C.getId() == id);
    {
    }
  }

  public void test_L3_Compartment_initDefaults()
  {
    Compartment c = new  Compartment(3,1);
    c.setId( "A");
    assertEquals( true, c.isSetId() );
    assertEquals( false, c.isSetName() );
    assertEquals( false, c.isSetSize() );
    assertEquals( false, c.isSetVolume() );
    assertEquals( false, c.isSetUnits() );
    assertEquals( false, c.isSetConstant() );
    assertEquals( false, c.isSetSpatialDimensions() );
    c.initDefaults();
    assertTrue(c.getId().equals( "A"));
    assertTrue( c.getName().equals("") == true );
    assertTrue(c.getUnits().equals( "litre"));
    assertTrue( c.getSpatialDimensions() == 3 );
    assertTrue( c.getSize() == 1 );
    assertTrue( c.getConstant() == true );
    assertEquals( true, c.isSetId() );
    assertEquals( false, c.isSetName() );
    assertEquals( false, c.isSetSize() );
    assertEquals( false, c.isSetVolume() );
    assertEquals( true, c.isSetUnits() );
    assertEquals( true, c.isSetConstant() );
    assertEquals( true, c.isSetSpatialDimensions() );
    c = null;
  }

  public void test_L3_Compartment_name()
  {
    String name =  "My_Favorite_Factory";
    assertEquals( false, C.isSetName() );
    C.setName(name);
    assertTrue(C.getName().equals(name));
    assertEquals( true, C.isSetName() );
    if (C.getName() == name);
    {
    }
    C.unsetName();
    assertEquals( false, C.isSetName() );
    if (C.getName() != null);
    {
    }
  }

  public void test_L3_Compartment_size()
  {
    double size = 0.2;
    assertEquals( false, C.isSetSize() );
    assertEquals( true, isnan(C.getSize()) );
    C.setSize(size);
    assertTrue( C.getSize() == size );
    assertEquals( true, C.isSetSize() );
    C.unsetSize();
    assertEquals( false, C.isSetSize() );
    assertEquals( true, isnan(C.getSize()) );
  }

  public void test_L3_Compartment_spatialDimensions()
  {
    assertEquals( false, C.isSetSpatialDimensions() );
    assertEquals( true, isnan(C.getSpatialDimensionsAsDouble()) );
    C.setSpatialDimensions(1.5);
    assertEquals( true, C.isSetSpatialDimensions() );
    assertTrue( C.getSpatialDimensionsAsDouble() == 1.5 );
    C.unsetSpatialDimensions();
    assertEquals( false, C.isSetSpatialDimensions() );
    assertEquals( true, isnan(C.getSpatialDimensionsAsDouble()) );
  }

  public void test_L3_Compartment_units()
  {
    String units =  "volume";
    assertEquals( false, C.isSetUnits() );
    C.setUnits(units);
    assertTrue(C.getUnits().equals(units));
    assertEquals( true, C.isSetUnits() );
    if (C.getUnits() == units);
    {
    }
    C.unsetUnits();
    assertEquals( false, C.isSetUnits() );
    if (C.getUnits() != null);
    {
    }
  }

  /**
   * Loads the SWIG-generated libSBML Java module when this class is
   * loaded, or reports a sensible diagnostic message about why it failed.
   */
  static
  {
    String varname;
    String shlibname;

    if (System.getProperty("mrj.version") != null)
    {
      varname = "DYLD_LIBRARY_PATH";    // We're on a Mac.
      shlibname = "libsbmlj.jnilib and/or libsbml.dylib";
    }
    else
    {
      varname = "LD_LIBRARY_PATH";      // We're not on a Mac.
      shlibname = "libsbmlj.so and/or libsbml.so";
    }

    try
    {
      System.loadLibrary("sbmlj");
      // For extra safety, check that the jar file is in the classpath.
      Class.forName("org.sbml.libsbml.libsbml");
    }
    catch (SecurityException e)
    {
      e.printStackTrace();
      System.err.println("Could not load the libSBML library files due to a"+
                         " security exception.\n");
      System.exit(1);
    }
    catch (UnsatisfiedLinkError e)
    {
      e.printStackTrace();
      System.err.println("Error: could not link with the libSBML library files."+
                         " It is likely\nyour " + varname +
                         " environment variable does not include the directories\n"+
                         "containing the " + shlibname + " library files.\n");
      System.exit(1);
    }
    catch (ClassNotFoundException e)
    {
      e.printStackTrace();
      System.err.println("Error: unable to load the file libsbmlj.jar."+
                         " It is likely\nyour -classpath option and CLASSPATH" +
                         " environment variable\n"+
                         "do not include the path to libsbmlj.jar.\n");
      System.exit(1);
    }
  }
}

