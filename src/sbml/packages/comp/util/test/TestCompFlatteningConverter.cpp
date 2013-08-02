/**
 * \file    TestCompFlatteningConverter.cpp
 * \brief   Implementation of the Tests for the Comp flattening converter
 * \author  Frank T. Bergmann
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2009-2011 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->*/

#include <sbml/common/common.h>

#include <sbml/packages/comp/common/CompExtensionTypes.h>

#include <sbml/conversion/SBMLConverterRegistry.h>
#include <sbml/SBMLReader.h>
#include <sbml/SBMLTypes.h>

#include <string>

#include <check.h>

using namespace std;

LIBSBML_CPP_NAMESPACE_USE

BEGIN_C_DECLS


extern char *TestDataDirectory;

START_TEST (test_comp_get_flattening_converter)
{
  ConversionProperties* props = new ConversionProperties();
  props->addOption("flatten comp");
  props->addOption("perform validation", true);
  
  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // ensure we have a converter
  fail_unless(converter!= NULL);  

  // ensure that conversion without document does not work
  fail_unless(converter->convert() == LIBSBML_INVALID_OBJECT);

  SBMLDocument doc(new CompPkgNamespaces());
  converter->setDocument(&doc);

  // ensure that conversion without model does not work
  fail_unless(converter->convert() == LIBSBML_INVALID_OBJECT);

  Model* model = doc.createModel("model");

  // now conversion should work
  fail_unless(converter->convert() == LIBSBML_OPERATION_SUCCESS);

  delete converter;

}
END_TEST

START_TEST (test_comp_flatten_aggregate)
{ 
  string filename(TestDataDirectory);
  //string filename("C:\\Development\\libsbml\\src\\sbml\\packages\\comp\\util\\test\\test-data\\");

  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("basePath", filename);
  props->addOption("perform validation", true);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // ensure we have a converter
  fail_unless(converter!= NULL);

  // load document
  filename += "aggregate.xml";  
  SBMLDocument* doc = readSBMLFromFile(filename.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  converter->setDocument(doc);
  
  string oldModel = writeSBMLToString(doc);

  // fail unless this model does use comp
  fail_unless(oldModel .find("comp:") != string::npos);

  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);


  string newModel = writeSBMLToString(doc);
  //writeSBMLToFile(doc, "aggregate_flat.xml");
  
  // fail unless this model does not use comp
  fail_unless(newModel.find("comp:") == string::npos);

  string ffile = TestDataDirectory;
  ffile += "aggregate_flat.xml";
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);


  delete doc;
  delete converter;
  


}
END_TEST

void TestFlattenedPair(string file1, string file2)
{
  string filename(TestDataDirectory);
  //string filename("C:\\Development\\libsbml\\src\\sbml\\packages\\comp\\util\\test\\test-data\\");
  

  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("basePath", filename);
  props->addOption("perform validation", true);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // load document
  string cfile = filename + file1;  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  //Fail if we claim there are errors in the document (there shouldn't be)

  fail_unless(doc->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) == 0);
  //For use debugging the above statement:

  converter->setDocument(doc);
  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);

  //For use in debugging the above statement.
  /*
  SBMLErrorLog* errors = doc->getErrorLog();
  if (errors->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) != 0) {
    fail_unless(false);
    for (unsigned long e=0; e<errors->getNumErrors(); e++) {
      const SBMLError* error = errors->getError(e);
      if (error->getSeverity() == LIBSBML_SEV_ERROR) {
        cout << error->getMessage() << endl;
      }
    }
  }
  */

  string newModel = writeSBMLToString(doc);
  //writeSBMLToFile(doc, "test1_flat.xml");
  string ffile = filename + file2;
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
  delete converter;
}

START_TEST (test_comp_flatten_enzyme_identical)
{ 
  TestFlattenedPair("enzyme_identical.xml", "identical_flat.xml");

}
END_TEST

START_TEST (test_comp_flatten_complexified)
{ 
  TestFlattenedPair("complexified.xml", "complexified_flat.xml");
}
END_TEST


START_TEST (test_comp_flatten_complexified2)
{ 
  TestFlattenedPair("complexified2.xml", "complexified2_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_qtpop)
{ 

  string filename(TestDataDirectory);
  //string filename("C:\\Development\\libsbml\\src\\sbml\\packages\\comp\\util\\test\\test-data\\");
  

  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("basePath", filename);
  props->addOption("perform validation", true);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // ensure we have a converter
  fail_unless(converter!= NULL);

  // load document
  filename += "QTPop.xml";  
  SBMLDocument* doc = readSBMLFromFile(filename.c_str());

  // fail if document is null
  fail_unless(doc != NULL);

  converter->setDocument(doc);
  
  string oldModel = writeSBMLToString(doc);

  // fail unless this model does use comp
  fail_unless(oldModel .find("comp:") != string::npos);

  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);

  string newModel = writeSBMLToString(doc);

  // fail unless this model does not use comp
  fail_unless(newModel.find("comp:") == string::npos);
  //writeSBMLToFile(doc, "QTPop_libsbml_flat.xml");
  string ffile = TestDataDirectory;

  // taken layout out of the original files
  //if (doc->getPlugin("layout") == NULL) {
    
  ffile += "QTPop_flat_nolayout.xml";
  
  //}
  //else {
  //  ffile += "QTPop_flat_withlayout.xml";
  //}
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete converter;
}
END_TEST


START_TEST (test_comp_flatten_double_ext1)
{ 
  SBMLNamespaces sbmlns(3,1,"comp",1);

  // create the document
  SBMLDocument *doc = new SBMLDocument(&sbmlns);
  CompSBMLDocumentPlugin* compdoc = static_cast<CompSBMLDocumentPlugin*>(doc->getPlugin("comp"));
  compdoc->setRequired(true);

  ExternalModelDefinition* extmod = compdoc->createExternalModelDefinition();
  extmod->setSource("enzyme_identical.xml");
  string filename(TestDataDirectory);
  doc->setLocationURI("file:" + filename + "test.xml");
  extmod->setModelRef("ExtMod1");
  extmod->setId("EM1");
  Model* model = doc->createModel();
  CompModelPlugin* modplug = static_cast<CompModelPlugin*>(model->getPlugin("comp"));
  Submodel* submod = modplug->createSubmodel();
  submod->setModelRef("EM1");
  submod->setId("A");
  string origmodel = writeSBMLToString(doc);
  string ffile = TestDataDirectory;
  ffile += "doubleext.xml";
  SBMLDocument* origdoc = readSBMLFromFile(ffile.c_str());
  string origstored = writeSBMLToString(origdoc);
  fail_unless(origmodel == origstored);

  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("basePath", filename);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // ensure we have a converter
  fail_unless(converter!= NULL);

  converter->setDocument(doc);
  
  string oldModel = writeSBMLToString(doc);

  // fail unless this model does use comp
  fail_unless(oldModel .find("comp:") != string::npos);

  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);
  string newModel = writeSBMLToString(doc);
  //writeSBMLToFile(doc, "doubleext_flat.xml");

  // fail unless this model does not use comp
  fail_unless(newModel.find("comp:") == string::npos);

  ffile = TestDataDirectory;
  ffile += "doubleext_flat.xml";
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete converter;
}
END_TEST

START_TEST (test_comp_flatten_double_ext2)
{ 
  SBMLNamespaces sbmlns(3,1,"comp",1);

  // create the document
  SBMLDocument *doc = new SBMLDocument(&sbmlns);
  CompSBMLDocumentPlugin* compdoc = static_cast<CompSBMLDocumentPlugin*>(doc->getPlugin("comp"));
  compdoc->setRequired(true);

  ExternalModelDefinition* extmod = compdoc->createExternalModelDefinition();
  extmod->setSource("enzyme_identical.xml");
  string filename(TestDataDirectory);
  doc->setLocationURI("file:" + filename + "test.xml");
  extmod->setId("EM1");
  Model* model = doc->createModel();
  CompModelPlugin* modplug = static_cast<CompModelPlugin*>(model->getPlugin("comp"));
  Submodel* submod = modplug->createSubmodel();
  submod->setModelRef("EM1");
  submod->setId("A");
  string origmodel = writeSBMLToString(doc);
  string ffile = TestDataDirectory;
  ffile += "doubleext2.xml";
  SBMLDocument* origdoc = readSBMLFromFile(ffile.c_str());
  string origstored = writeSBMLToString(origdoc);
  fail_unless(origmodel == origstored);

  ConversionProperties* props = new ConversionProperties();
  props->addOption("flatten comp");
  props->addOption("basePath", filename);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  // ensure we have a converter
  fail_unless(converter!= NULL);

  converter->setDocument(doc);
  
  string oldModel = writeSBMLToString(doc);

  // fail unless this model does use comp
  fail_unless(oldModel .find("comp:") != string::npos);

  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);


  string newModel = writeSBMLToString(doc);
  //writeSBMLToFile(doc, "doubleext2_flat.xml");

  // fail unless this model does not use comp
  fail_unless(newModel.find("comp:") == string::npos);

  ffile = TestDataDirectory;
  ffile += "doubleext2_flat.xml";
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);


  delete doc;
  delete converter;
}
END_TEST

START_TEST (test_comp_flatten_spec1)
{ 
  TestFlattenedPair("eg-simple-aggregate.xml", "eg-simple-aggregate_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_spec2)
{ 
  TestFlattenedPair("eg-import-external.xml", "eg-import-external_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_spec3)
{ 
  TestFlattenedPair("eg-ports.xml", "eg-ports_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_spec4)
{ 
  TestFlattenedPair("eg-replacement.xml", "eg-replacement_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_dropports)
{ 
  SBMLNamespaces sbmlns(3,1,"comp",1);

  // create the document
  SBMLDocument *doc = new SBMLDocument(&sbmlns);
  CompSBMLDocumentPlugin* compdoc = static_cast<CompSBMLDocumentPlugin*>(doc->getPlugin("comp"));
  compdoc->setRequired(true);
  Model* model = doc->createModel();
  Parameter* param = model->createParameter();
  param->setId("p1");
  param->setConstant(true);
  CompModelPlugin* cmp = static_cast<CompModelPlugin*>(model->getPlugin("comp"));
  Port* port = cmp->createPort();
  port->setId("p1_port");
  port->setIdRef("p1");
  //writeSBMLToFile(doc, "dropports.xml");

  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // ensure we have a converter
  fail_unless(converter!= NULL);

  converter->setDocument(doc);
  
  string oldModel = writeSBMLToString(doc);

  // fail unless this model does use comp, and has a port.
  fail_unless(oldModel.find("comp:") != string::npos);
  fail_unless(oldModel.find("port") != string::npos);

  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);
  string newModel = writeSBMLToString(doc);
  //writeSBMLToFile(doc, "dropports_flat.xml");

  // fail unless this model does not use comp, and doesn't have any ports in it.
  fail_unless(newModel.find("comp:") == string::npos);
  fail_unless(newModel.find("port")==string::npos);

  string ffile = TestDataDirectory;
  ffile += "dropports_flat.xml";
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete converter;
}
END_TEST

START_TEST (test_comp_flatten_exchange1)
{ 
  TestFlattenedPair("exchangetest.xml", "exchangetest_flat.xml");
}
END_TEST
  
START_TEST (test_comp_flatten_exchange2)
{
  TestFlattenedPair("exchangetest2.xml", "exchangetest2_flat.xml");
}
END_TEST
  
START_TEST (test_comp_flatten_exchange3)
{ 
  TestFlattenedPair("CompTest.xml", "CompTest_flat.xml");
}
END_TEST
  
START_TEST (test_comp_flatten_replace_rules_and_constraints)
{ 
  TestFlattenedPair("replace_rules_and_constraints.xml", "replace_rules_and_constraints_flat.xml");
}
END_TEST
  
START_TEST (test_comp_flatten_test1)
{ 
  TestFlattenedPair("test1.xml", "test1_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test2)
{ 
  TestFlattenedPair("test2.xml", "test2_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test3)
{ 
  TestFlattenedPair("test3.xml", "test3_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test4)
{ 
  TestFlattenedPair("test4.xml", "test4_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test5)
{ 
  TestFlattenedPair("test5.xml", "test5_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test6)
{ 
  TestFlattenedPair("test6.xml", "test6_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test7)
{ 
  TestFlattenedPair("test7.xml", "test7_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test8)
{ 
  TestFlattenedPair("test8.xml", "test8_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test9)
{ 
  TestFlattenedPair("test9.xml", "test9_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test10)
{ 
  TestFlattenedPair("test10.xml", "test10_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test11)
{ 
  TestFlattenedPair("test11.xml", "test11_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test12)
{ 
  TestFlattenedPair("test12.xml", "test12_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test13)
{ 
  TestFlattenedPair("test13.xml", "test13_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test14)
{ 
  TestFlattenedPair("test14.xml", "test14_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test14_ports)
{ 
  string filename(TestDataDirectory);
  
  // load document
  string cfile = filename + "test14.xml";  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  Model* model = doc->getModel();
  fail_unless(model != NULL);

  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("leavePorts", true);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  converter->setDocument(doc);
  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);

  string newModel = writeSBMLToString(doc);

  string ffile = filename + "test14_flat_ports.xml";
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
}
END_TEST

START_TEST (test_comp_flatten_test15)
{ 
  TestFlattenedPair("test15.xml", "test15_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test16)
{ 
  TestFlattenedPair("test16.xml", "test16_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test17)
{ 
  TestFlattenedPair("test17.xml", "test17_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test18)
{ 
  TestFlattenedPair("test18.xml", "test18_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test19)
{ 
  TestFlattenedPair("test19.xml", "test19_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test20)
{ 
  TestFlattenedPair("test20.xml", "test20_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test21)
{ 
  TestFlattenedPair("test21.xml", "test21_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test22)
{ 
  TestFlattenedPair("test22.xml", "test22_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test23)
{ 
  TestFlattenedPair("test23.xml", "test23_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test24)
{ 
  TestFlattenedPair("test24.xml", "test24_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test25)
{ 
  TestFlattenedPair("test25.xml", "test25_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test26)
{ 
  TestFlattenedPair("test26.xml", "test26_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test27)
{ 
  TestFlattenedPair("test27.xml", "test27_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test28)
{ 
  TestFlattenedPair("test28.xml", "test28_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test29)
{ 
  TestFlattenedPair("test29.xml", "test29_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test30)
{ 
  TestFlattenedPair("test30.xml", "test30_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test31)
{ 
  TestFlattenedPair("test31.xml", "test31_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test32)
{ 
  TestFlattenedPair("test32.xml", "test32_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test33)
{ 
  TestFlattenedPair("test33.xml", "test33_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test34)
{ 
  TestFlattenedPair("test34.xml", "test34_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test35)
{ 
  TestFlattenedPair("test35.xml", "test35_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test36)
{ 
  TestFlattenedPair("test36.xml", "test36_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test37)
{ 
  TestFlattenedPair("test37.xml", "test37_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test38)
{ 
  TestFlattenedPair("test38.xml", "test38_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test39)
{ 
  TestFlattenedPair("test39.xml", "test39_flat.xml");
}
END_TEST

START_TEST (test_comp_flatten_test40)
{ 
  TestFlattenedPair("test40.xml", "test40_flat.xml");
}
END_TEST
  
START_TEST (test_comp_flatten_test41)
{ 
  TestFlattenedPair("test41.xml", "test41_flat.xml");
}
END_TEST
  
START_TEST (test_comp_flatten_test42)
{ 
  TestFlattenedPair("test42.xml", "test42_flat.xml");
}
END_TEST
  
START_TEST (test_comp_flatten_test43)
{ 
  TestFlattenedPair("test43.xml", "test43_flat.xml");
}
END_TEST
  
START_TEST (test_comp_flatten_test44)
{ 
  TestFlattenedPair("test44.xml", "test44_flat.xml");
}
END_TEST
  
START_TEST (test_comp_flatten_test45)
{ 
  TestFlattenedPair("test45.xml", "test45_flat.xml");
}
END_TEST
  
START_TEST (test_comp_flatten_test46)
{ 
  TestFlattenedPair("test46.xml", "test46_flat.xml");
}
END_TEST
  
START_TEST (test_comp_flatten_test47)
{ 
  TestFlattenedPair("test47.xml", "test47_flat.xml");
}
END_TEST
  
START_TEST (test_comp_flatten_test48)
{ 
  TestFlattenedPair("test48.xml", "test48_flat.xml");
}
END_TEST
  
START_TEST (test_comp_flatten_test49)
{ 
  TestFlattenedPair("test49.xml", "test49_flat.xml");
}
END_TEST
  
START_TEST (test_comp_flatten_test50)
{ 
  TestFlattenedPair("test50.xml", "test50_flat.xml");
}
END_TEST
  

START_TEST (test_comp_flatten_id_collisions)
{ 
  TestFlattenedPair("id_collisions.xml", "id_collisions_flat.xml");
}
END_TEST
  
START_TEST (test_comp_flatten_id_collisions2)
{
  TestFlattenedPair("id_collisions2.xml", "id_collisions2_flat.xml");
}
END_TEST
  

START_TEST (test_comp_flatten_converter_properties1)
{ 
  string filename(TestDataDirectory);
  
  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("basePath", filename);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // load document
  string cfile = filename + "test14.xml";  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  //Fail if we claim there are errors in the document (there shouldn't be)

  fail_unless(doc->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) == 0);

  converter->setDocument(doc);
  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);

  string newModel = writeSBMLToString(doc);
  string ffile = filename + "test14_flat.xml";
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
  delete converter;
}
END_TEST


START_TEST (test_comp_flatten_converter_properties2)
{ 
  string filename(TestDataDirectory);
  
  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("basePath", filename);
  props->addOption("leavePorts", true);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // load document
  string cfile = filename + "test14.xml";  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  //Fail if we claim there are errors in the document (there shouldn't be)

  fail_unless(doc->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) == 0);

  converter->setDocument(doc);
  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);

  string newModel = writeSBMLToString(doc);
  string ffile = filename + "test14_flat_ports.xml";
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
  delete converter;
}
END_TEST


START_TEST (test_comp_flatten_converter_properties3)
{ 
  string filename(TestDataDirectory);
  
  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("basePath", filename);
  props->addOption("listModelDefinitions", true);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // load document
  string cfile = filename + "test14.xml";  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  //Fail if we claim there are errors in the document (there shouldn't be)

  fail_unless(doc->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) == 0);

  converter->setDocument(doc);
  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);

  string newModel = writeSBMLToString(doc);
  string ffile = filename + "test14_flat_definitions.xml";
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
  delete converter;
}
END_TEST


START_TEST (test_comp_flatten_converter_properties4)
{ 
  string filename(TestDataDirectory);
  
  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("basePath", filename);
  props->addOption("listModelDefinitions", false);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // load document
  string cfile = filename + "test14.xml";  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  //Fail if we claim there are errors in the document (there shouldn't be)

  fail_unless(doc->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) == 0);

  converter->setDocument(doc);
  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);

  string newModel = writeSBMLToString(doc);
  string ffile = filename + "test14_flat.xml";
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
  delete converter;
}
END_TEST


START_TEST (test_comp_flatten_converter_properties5)
{ 
  string filename(TestDataDirectory);
  
  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("basePath", filename);
  props->addOption("leavePorts", false);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // load document
  string cfile = filename + "test14.xml";  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  //Fail if we claim there are errors in the document (there shouldn't be)

  fail_unless(doc->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) == 0);

  converter->setDocument(doc);
  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);

  string newModel = writeSBMLToString(doc);
  string ffile = filename + "test14_flat.xml";
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
  delete converter;
}
END_TEST


START_TEST (test_comp_flatten_converter_properties6)
{ 
  string filename(TestDataDirectory);
  
  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("basePath", filename);
  props->addOption("leavePorts", true);
  props->addOption("listModelDefinitions", true);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // load document
  string cfile = filename + "test14.xml";  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  //Fail if we claim there are errors in the document (there shouldn't be)

  fail_unless(doc->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) == 0);

  converter->setDocument(doc);
  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);

  string newModel = writeSBMLToString(doc);
  string ffile = filename + "test14_flat_portsAndDefinitions.xml";
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
  delete converter;
}
END_TEST


START_TEST (test_comp_flatten_converter_properties7)
{ 
  string filename(TestDataDirectory);
  
  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("basePath", filename);
  props->addOption("leavePorts", true);
  props->addOption("listModelDefinitions", false);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // load document
  string cfile = filename + "test14.xml";  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  //Fail if we claim there are errors in the document (there shouldn't be)

  fail_unless(doc->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) == 0);

  converter->setDocument(doc);
  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);

  string newModel = writeSBMLToString(doc);
  string ffile = filename + "test14_flat_ports.xml";
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
  delete converter;
}
END_TEST


START_TEST (test_comp_flatten_converter_properties8)
{ 
  string filename(TestDataDirectory);
  
  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("basePath", filename);
  props->addOption("leavePorts", false);
  props->addOption("listModelDefinitions", true);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // load document
  string cfile = filename + "test14.xml";  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  //Fail if we claim there are errors in the document (there shouldn't be)

  fail_unless(doc->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) == 0);

  converter->setDocument(doc);
  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);

  string newModel = writeSBMLToString(doc);
  string ffile = filename + "test14_flat_definitions.xml";
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
  delete converter;
}
END_TEST


START_TEST (test_comp_flatten_converter_properties9)
{ 
  string filename(TestDataDirectory);
  
  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("basePath", filename);
  props->addOption("leavePorts", false);
  props->addOption("listModelDefinitions", false);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // load document
  string cfile = filename + "test14.xml";  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  //Fail if we claim there are errors in the document (there shouldn't be)

  fail_unless(doc->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) == 0);

  converter->setDocument(doc);
  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);

  string newModel = writeSBMLToString(doc);
  string ffile = filename + "test14_flat.xml";
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
  delete converter;
}
END_TEST


//This tests to see if the 'basePath' option works properly.
START_TEST (test_comp_flatten_converter_properties10)
{ 
  string filename(TestDataDirectory);
  string subdirname = filename + "subdir/";
  
  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("basePath", subdirname);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // load document
  string cfile = filename + "ext_in_subdir.xml";  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  //Fail if we claim there are errors in the document (there shouldn't be)
  fail_unless(doc->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) == 0);

  converter->setDocument(doc);
  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);

  string newModel = writeSBMLToString(doc);
  string ffile = filename + "ext_in_subdir_flat.xml";
  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
  delete converter;
}
END_TEST


START_TEST (test_comp_flatten_converter_packages1)
{ 
  string filename(TestDataDirectory);
  
  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("perform validation", true);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // load document
  string cfile = filename + "aggregate_layout.xml";  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  //Fail if we claim there are errors in the document (there shouldn't be)

  fail_unless(doc->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) == 0);

  converter->setDocument(doc);
  int result = converter->convert();

  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);

  string newModel = writeSBMLToString(doc);
  string ffile;

  // NOTE: since layout flattening is not yet implemented
  // the same result should be chieved whether layout is enabled or not
  if (SBMLExtensionRegistry::isPackageEnabled("layout") == true)
  {
    ffile = filename + "aggregate_layout_flat_layout_removed.xml";
    fail_unless(result == LIBSBML_OPERATION_SUCCESS);
    fail_unless(doc->getNumErrors() == 1);
    fail_unless(doc->getErrorLog()->getError(0)->getErrorId() == 1090109);
  }
  else
  {
    fail_unless(result == LIBSBML_OPERATION_SUCCESS);
    fail_unless(doc->getNumErrors() == 2);
    fail_unless(doc->getErrorLog()->getError(0)->getErrorId() == 99108);
    fail_unless(doc->getErrorLog()->getError(1)->getErrorId() == 1090108);
    ffile = filename + "aggregate_layout_flat_layout_removed.xml";
  }

  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
  delete converter;
}
END_TEST


START_TEST (test_comp_flatten_converter_packages2)
{ 
  string filename(TestDataDirectory);
 
  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("ignorePackages", true);
  props->addOption("perform validation", true);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // load document
  string cfile = filename + "aggregate_fbc.xml";  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  //Fail if we claim there are errors in the document (there shouldn't be)

  if (SBMLExtensionRegistry::isPackageEnabled("fbc") == true)
  {
    fail_unless(doc->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) == 0);
  }

  converter->setDocument(doc);
  int result = converter->convert();


  string newModel = writeSBMLToString(doc);
  string ffile;

  // NOTE: since fbc flattening is not yet implemented
  // the same result should be chieved whether fbc is enabled or not
  if (SBMLExtensionRegistry::isPackageEnabled("fbc") == true)
  {
    // fbc is not required so should just get removed
    fail_unless(result == LIBSBML_OPERATION_SUCCESS);
    fail_unless(doc->getNumErrors() == 1);
    fail_unless(doc->getErrorLog()->getError(0)->getErrorId() == 1090109);
    ffile = filename + "aggregate_fbc_flat_fbc_removed.xml";
  }
  else
  {
    fail_unless(result == LIBSBML_OPERATION_SUCCESS);
    fail_unless(doc->getNumErrors() == 2);
    fail_unless(doc->getErrorLog()->getError(0)->getErrorId() == 99108);
    fail_unless(doc->getErrorLog()->getError(1)->getErrorId() == 1090108);
    ffile = filename + "aggregate_fbc_flat_fbc_removed.xml";
  }

  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
  delete converter;
}
END_TEST


START_TEST (test_comp_flatten_converter_packages3)
{ 
  string filename(TestDataDirectory);
 
  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("ignorePackages", true);
  props->addOption("perform validation", true);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // load document
  string cfile = filename + "aggregate_fbc.xml";  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  //Fail if we claim there are errors in the document (there shouldn't be)

  if (SBMLExtensionRegistry::isPackageEnabled("fbc") == true)
  {
    fail_unless(doc->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) == 0);
  }

  converter->setDocument(doc);
  int result = converter->convert();


  string newModel = writeSBMLToString(doc);
  string ffile;

  // NOTE: since fbc flattening is not yet implemented
  // the same result should be chieved whether fbc is enabled or not
  if (SBMLExtensionRegistry::isPackageEnabled("fbc") == true)
  {
    // fbc is not required so should just get removed
    fail_unless(result == LIBSBML_OPERATION_SUCCESS);
    fail_unless(doc->getNumErrors() == 1);
    fail_unless(doc->getErrorLog()->getError(0)->getErrorId() == 1090109);
    ffile = filename + "aggregate_fbc_flat_fbc_removed.xml";
  }
  else
  {
    fail_unless(result == LIBSBML_OPERATION_SUCCESS);
    fail_unless(doc->getNumErrors() == 2);
    fail_unless(doc->getErrorLog()->getError(0)->getErrorId() == 99108);
    fail_unless(doc->getErrorLog()->getError(1)->getErrorId() == 1090108);
    ffile = filename + "aggregate_fbc_flat_fbc_removed.xml";
  }

  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
  delete converter;
}
END_TEST


START_TEST (test_comp_flatten_converter_packages4)
{ 
  string filename(TestDataDirectory);
  
  ConversionProperties* props = new ConversionProperties();
  
  props->addOption("flatten comp");
  props->addOption("ignorePackages", false);
  props->addOption("perform validation", true);

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  
  // load document
  string cfile = filename + "aggregate_fbc.xml";  
  SBMLDocument* doc = readSBMLFromFile(cfile.c_str());

  // fail if there is no model (readSBMLFromFile always returns a valid document)
  fail_unless(doc->getModel() != NULL);

  //Fail if we claim there are errors in the document (there shouldn't be)

  if (SBMLExtensionRegistry::isPackageEnabled("fbc") == true)
  {
    fail_unless(doc->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) == 0);
  }

  converter->setDocument(doc);
  int result = converter->convert();


  string newModel = writeSBMLToString(doc);
  string ffile;

  // NOTE: here we explicitly say do not remove packages
  if (SBMLExtensionRegistry::isPackageEnabled("fbc") == true)
  {
    fail_unless(result == LIBSBML_OPERATION_SUCCESS);
    fail_unless(doc->getNumErrors() == 1);
    fail_unless(doc->getErrorLog()->getError(0)->getErrorId() == 1090109);
    ffile = filename + "aggregate_fbc_flat_fbc_not_removed.xml";
  }
  else
  {
    fail_unless(result == LIBSBML_OPERATION_SUCCESS);
    fail_unless(doc->getNumErrors() == 2);
    fail_unless(doc->getErrorLog()->getError(0)->getErrorId() == 99108);
    fail_unless(doc->getErrorLog()->getError(1)->getErrorId() == 1090108);
    ffile = filename + "aggregate_fbc_flat_fbc_not_enabled.xml";
  }

  SBMLDocument* fdoc = readSBMLFromFile(ffile.c_str());
  string flatModel = writeSBMLToString(fdoc);
  fail_unless(flatModel == newModel);

  delete doc;
  delete fdoc;
  delete converter;
}
END_TEST

START_TEST(test_comp_validator_44781839)
{
  SBMLDocument* doc = NULL;
  string dir(TestDataDirectory);
  string fileName = dir + "exchangetest.xml";

  doc = readSBMLFromFile(fileName.c_str());
  doc->checkConsistency();
  delete doc;
  
  fileName = dir + "exchangetest2.xml";
  
  doc = readSBMLFromFile(fileName.c_str());
  doc->checkConsistency();
  delete doc;

  fileName = dir + "exchangetest2_flat_ports.xml";

  doc = readSBMLFromFile(fileName.c_str());
  doc->checkConsistency();
  delete doc;

  fileName = dir + "test34.xml";

  doc = readSBMLFromFile(fileName.c_str());
  doc->checkConsistency();
  delete doc;

  fileName = dir + "test35.xml";

  doc = readSBMLFromFile(fileName.c_str());
  doc->checkConsistency();
  delete doc;

  fileName = dir + "test36.xml";

  doc = readSBMLFromFile(fileName.c_str());
  doc->checkConsistency();
  delete doc;

  fileName = dir + "test37.xml";

  doc = readSBMLFromFile(fileName.c_str());
  doc->checkConsistency();
  delete doc;

  fileName = dir + "test38.xml";

  doc = readSBMLFromFile(fileName.c_str());
  doc->checkConsistency();
  delete doc;
  
}
END_TEST

Suite *
create_suite_TestFlatteningConverter (void)
{ 
  TCase *tcase = tcase_create("SBMLCompFlatteningConverter");
  Suite *suite = suite_create("SBMLCompFlatteningConverter");
  
  tcase_add_test(tcase, test_comp_flatten_double_ext2);
  tcase_add_test(tcase, test_comp_get_flattening_converter);
  tcase_add_test(tcase, test_comp_flatten_aggregate);
  tcase_add_test(tcase, test_comp_flatten_enzyme_identical);
  tcase_add_test(tcase, test_comp_flatten_complexified);
  tcase_add_test(tcase, test_comp_flatten_complexified2);
  tcase_add_test(tcase, test_comp_flatten_qtpop);
  tcase_add_test(tcase, test_comp_flatten_double_ext1);
  tcase_add_test(tcase, test_comp_flatten_spec1);
  tcase_add_test(tcase, test_comp_flatten_spec2);
  tcase_add_test(tcase, test_comp_flatten_spec3);
  tcase_add_test(tcase, test_comp_flatten_spec4);
  tcase_add_test(tcase, test_comp_flatten_dropports);
  tcase_add_test(tcase, test_comp_flatten_exchange1);
  tcase_add_test(tcase, test_comp_flatten_exchange2); 
  tcase_add_test(tcase, test_comp_flatten_exchange3);
  tcase_add_test(tcase, test_comp_flatten_replace_rules_and_constraints);
  tcase_add_test(tcase, test_comp_flatten_test1);
  tcase_add_test(tcase, test_comp_flatten_test2);
  tcase_add_test(tcase, test_comp_flatten_test3);
  tcase_add_test(tcase, test_comp_flatten_test4);
  tcase_add_test(tcase, test_comp_flatten_test5);
  tcase_add_test(tcase, test_comp_flatten_test6);
  tcase_add_test(tcase, test_comp_flatten_test7);
  tcase_add_test(tcase, test_comp_flatten_test8);
  tcase_add_test(tcase, test_comp_flatten_test9);
  tcase_add_test(tcase, test_comp_flatten_test10);
  tcase_add_test(tcase, test_comp_flatten_test11);
  tcase_add_test(tcase, test_comp_flatten_test12);
  tcase_add_test(tcase, test_comp_flatten_test13);
  tcase_add_test(tcase, test_comp_flatten_test14);
  tcase_add_test(tcase, test_comp_flatten_test14_ports);
  tcase_add_test(tcase, test_comp_flatten_test15);
  tcase_add_test(tcase, test_comp_flatten_test16);
  tcase_add_test(tcase, test_comp_flatten_test17);
  tcase_add_test(tcase, test_comp_flatten_test18);
  tcase_add_test(tcase, test_comp_flatten_test19);
  tcase_add_test(tcase, test_comp_flatten_test20);
  tcase_add_test(tcase, test_comp_flatten_test21);
  tcase_add_test(tcase, test_comp_flatten_test22);
  tcase_add_test(tcase, test_comp_flatten_test23);
  tcase_add_test(tcase, test_comp_flatten_test24);
  tcase_add_test(tcase, test_comp_flatten_test25);
  tcase_add_test(tcase, test_comp_flatten_test26);
  tcase_add_test(tcase, test_comp_flatten_test27);
  tcase_add_test(tcase, test_comp_flatten_test28);
  tcase_add_test(tcase, test_comp_flatten_test29);
  tcase_add_test(tcase, test_comp_flatten_test30);
  tcase_add_test(tcase, test_comp_flatten_test31);
  tcase_add_test(tcase, test_comp_flatten_test32);
  tcase_add_test(tcase, test_comp_flatten_test33);
  tcase_add_test(tcase, test_comp_flatten_test34);
  tcase_add_test(tcase, test_comp_flatten_test35);
  tcase_add_test(tcase, test_comp_flatten_test36);
  tcase_add_test(tcase, test_comp_flatten_test37);
  tcase_add_test(tcase, test_comp_flatten_test38);
  tcase_add_test(tcase, test_comp_flatten_test39);
  tcase_add_test(tcase, test_comp_flatten_test40);
  tcase_add_test(tcase, test_comp_flatten_test41);
  tcase_add_test(tcase, test_comp_flatten_test42);
  tcase_add_test(tcase, test_comp_flatten_test43);
  tcase_add_test(tcase, test_comp_flatten_test44);
  tcase_add_test(tcase, test_comp_flatten_test45);
  tcase_add_test(tcase, test_comp_flatten_test46);
  tcase_add_test(tcase, test_comp_flatten_test47);
  tcase_add_test(tcase, test_comp_flatten_test48);
  tcase_add_test(tcase, test_comp_flatten_test49);
  tcase_add_test(tcase, test_comp_flatten_test50);

  tcase_add_test(tcase, test_comp_flatten_id_collisions);
  tcase_add_test(tcase, test_comp_flatten_id_collisions2);

  tcase_add_test(tcase, test_comp_flatten_converter_properties1);
  tcase_add_test(tcase, test_comp_flatten_converter_properties2);
  tcase_add_test(tcase, test_comp_flatten_converter_properties3);
  tcase_add_test(tcase, test_comp_flatten_converter_properties4);
  tcase_add_test(tcase, test_comp_flatten_converter_properties5);
  tcase_add_test(tcase, test_comp_flatten_converter_properties6);
  tcase_add_test(tcase, test_comp_flatten_converter_properties7);
  tcase_add_test(tcase, test_comp_flatten_converter_properties8);
  tcase_add_test(tcase, test_comp_flatten_converter_properties9);
  tcase_add_test(tcase, test_comp_flatten_converter_properties10);

  //tcase_add_test(tcase, test_comp_flatten_converter_packages1);
  //tcase_add_test(tcase, test_comp_flatten_converter_packages2);
  //tcase_add_test(tcase, test_comp_flatten_converter_packages3);
  //tcase_add_test(tcase, test_comp_flatten_converter_packages4);
  tcase_add_test(tcase, test_comp_validator_44781839);
 
  suite_add_tcase(suite, tcase);

  return suite;
}


END_C_DECLS

