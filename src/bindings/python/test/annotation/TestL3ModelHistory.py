#
# @file    TestL3ModelHistory.py
# @brief   test for ModelHistory on any SBase object
#
# @author  Akiya Jouraku (Python conversion)
# @author  Sarah Keating 
# 
# ====== WARNING ===== WARNING ===== WARNING ===== WARNING ===== WARNING ======
#
# DO NOT EDIT THIS FILE.
#
# This file was generated automatically by converting the file located at
# src/annotation/test/TestL3ModelHistory.cpp
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

def wrapString(s):
  return s
  pass


class TestL3ModelHistory(unittest.TestCase):

  global c
  c = None
  global d
  d = None
  global m
  m = None

  def equals(self, *x):
    if len(x) == 2:
      return x[0] == x[1]
    elif len(x) == 1:
      return x[0] == self.OSS.str()

  def setUp(self):
    filename = "../../sbml/annotation/test/test-data/annotationL3.xml"
    self.d = libsbml.readSBML(filename)
    self.m = self.d.getModel()
    self.c = self.m.getCompartment(0)
    pass  

  def tearDown(self):
    self.d = None
    pass  

  def test_L3ModelHistory_delete(self):
    print self.c
    node = libsbml.RDFAnnotationParser.parseModelHistory(self.c)
    n1 = libsbml.RDFAnnotationParser.deleteRDFAnnotation(node)
    expected =  "<annotation/>";
    self.assert_( n1.getNumChildren() == 0 )
    self.assert_( n1.getName() ==  "annotation" )
    self.assertEqual( True, self.equals(expected,n1.toXMLString()) )
    node = None
    pass  

  def test_L3ModelHistory_deleteWithOther(self):
    self.c = self.m.getCompartment(1)
    node = libsbml.RDFAnnotationParser.deleteRDFAnnotation(self.c.getAnnotation())
    expected = wrapString("<annotation>\n"
"  <jd2:JDesignerLayout version=\"2.0\" MajorVersion=\"2\" MinorVersion=\"0\" BuildVersion=\"41\">\n"
 + 
    "    <jd2:header>\n"
 + 
    "      <jd2:VersionHeader JDesignerVersion=\"2.0\"/>\n"
 + 
    "      <jd2:ModelHeader Author=\"Mr Untitled\" ModelVersion=\"0.0\" ModelTitle=\"untitled\"/>\n"
 + 
    "      <jd2:TimeCourseDetails timeStart=\"0\" timeEnd=\"10\" numberOfPoints=\"1000\"/>\n"
 + 
    "    </jd2:header>\n"
 + 
    "  </jd2:JDesignerLayout>\n"
 + 
    "</annotation>")
    self.assertEqual( True, self.equals(expected,node.toXMLString()) )
    pass  

  def test_L3ModelHistory_deleteWithOutOther(self):
    self.c = self.m.getCompartment(2)
    node = self.c.getAnnotation()
    expected = wrapString("<annotation>\n"
"  <jd2:JDesignerLayout version=\"2.0\" MajorVersion=\"2\" MinorVersion=\"0\" BuildVersion=\"41\">\n"
 + 
    "    <jd2:header>\n"
 + 
    "      <jd2:VersionHeader JDesignerVersion=\"2.0\"/>\n"
 + 
    "      <jd2:ModelHeader Author=\"Mr Untitled\" ModelVersion=\"0.0\" ModelTitle=\"untitled\"/>\n"
 + 
    "      <jd2:TimeCourseDetails timeStart=\"0\" timeEnd=\"10\" numberOfPoints=\"1000\"/>\n"
 + 
    "    </jd2:header>\n"
 + 
    "  </jd2:JDesignerLayout>\n"
 + 
    "</annotation>")
    self.assertEqual( True, self.equals(expected,node.toXMLString()) )
    pass  

  def test_L3ModelHistory_delete_Model(self):
    node = libsbml.RDFAnnotationParser.parseModelHistory(self.m)
    n1 = libsbml.RDFAnnotationParser.deleteRDFAnnotation(node)
    expected =  "<annotation/>";
    self.assert_( n1.getNumChildren() == 0 )
    self.assert_( n1.getName() ==  "annotation" )
    self.assertEqual( True, self.equals(expected,n1.toXMLString()) )
    node = None
    pass  

  def test_L3ModelHistory_getModelHistory(self):
    self.assert_( (self.c == None) == False )
    history = self.c.getModelHistory()
    self.assert_( history != None )
    mc = history.getCreator(0)
    self.assert_((  "Le Novere" == mc.getFamilyName() ))
    self.assert_((  "Nicolas" == mc.getGivenName() ))
    self.assert_((  "lenov@ebi.ac.uk" == mc.getEmail() ))
    self.assert_((  "EMBL-EBI" == mc.getOrganisation() ))
    date = history.getCreatedDate()
    self.assert_( date.getYear() == 2005 )
    self.assert_( date.getMonth() == 2 )
    self.assert_( date.getDay() == 2 )
    self.assert_( date.getHour() == 14 )
    self.assert_( date.getMinute() == 56 )
    self.assert_( date.getSecond() == 11 )
    self.assert_( date.getSignOffset() == 0 )
    self.assert_( date.getHoursOffset() == 0 )
    self.assert_( date.getMinutesOffset() == 0 )
    self.assert_((  "2005-02-02T14:56:11Z" == date.getDateAsString() ))
    date = history.getModifiedDate()
    self.assert_( date.getYear() == 2006 )
    self.assert_( date.getMonth() == 5 )
    self.assert_( date.getDay() == 30 )
    self.assert_( date.getHour() == 10 )
    self.assert_( date.getMinute() == 46 )
    self.assert_( date.getSecond() == 2 )
    self.assert_( date.getSignOffset() == 0 )
    self.assert_( date.getHoursOffset() == 0 )
    self.assert_( date.getMinutesOffset() == 0 )
    self.assert_((  "2006-05-30T10:46:02Z" == date.getDateAsString() ))
    pass  

  def test_L3ModelHistory_getModelHistory_Model(self):
    self.assert_( (self.m == None) == False )
    history = self.m.getModelHistory()
    self.assert_( history != None )
    mc = history.getCreator(0)
    self.assert_((  "Le Novere" == mc.getFamilyName() ))
    self.assert_((  "Nicolas" == mc.getGivenName() ))
    self.assert_((  "lenov@ebi.ac.uk" == mc.getEmail() ))
    self.assert_((  "EMBL-EBI" == mc.getOrganisation() ))
    date = history.getCreatedDate()
    self.assert_( date.getYear() == 2005 )
    self.assert_( date.getMonth() == 2 )
    self.assert_( date.getDay() == 2 )
    self.assert_( date.getHour() == 14 )
    self.assert_( date.getMinute() == 56 )
    self.assert_( date.getSecond() == 11 )
    self.assert_( date.getSignOffset() == 0 )
    self.assert_( date.getHoursOffset() == 0 )
    self.assert_( date.getMinutesOffset() == 0 )
    self.assert_((  "2005-02-02T14:56:11Z" == date.getDateAsString() ))
    date = history.getModifiedDate()
    self.assert_( date.getYear() == 2006 )
    self.assert_( date.getMonth() == 5 )
    self.assert_( date.getDay() == 30 )
    self.assert_( date.getHour() == 10 )
    self.assert_( date.getMinute() == 46 )
    self.assert_( date.getSecond() == 2 )
    self.assert_( date.getSignOffset() == 0 )
    self.assert_( date.getHoursOffset() == 0 )
    self.assert_( date.getMinutesOffset() == 0 )
    self.assert_((  "2006-05-30T10:46:02Z" == date.getDateAsString() ))
    pass  

  def test_L3ModelHistory_parseModelHistory(self):
    node = libsbml.RDFAnnotationParser.parseModelHistory(self.c)
    self.assert_( node.getNumChildren() == 1 )
    rdf = node.getChild(0)
    self.assert_((  "RDF" == rdf.getName() ))
    self.assert_((  "rdf" == rdf.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == rdf.getURI() ))
    self.assert_( rdf.getNumChildren() == 1 )
    desc = rdf.getChild(0)
    self.assert_((  "Description" == desc.getName() ))
    self.assert_((  "rdf" == desc.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == desc.getURI() ))
    self.assert_( desc.getNumChildren() == 4 )
    creator = desc.getChild(0)
    self.assert_((  "creator" == creator.getName() ))
    self.assert_((  "dc" == creator.getPrefix() ))
    self.assert_((  "http://purl.org/dc/elements/1.1/" == creator.getURI() ))
    self.assert_( creator.getNumChildren() == 1 )
    Bag = creator.getChild(0)
    self.assert_((  "Bag" == Bag.getName() ))
    self.assert_((  "rdf" == Bag.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == Bag.getURI() ))
    self.assert_( Bag.getNumChildren() == 1 )
    li = Bag.getChild(0)
    self.assert_((  "li" == li.getName() ))
    self.assert_((  "rdf" == li.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == li.getURI() ))
    self.assert_( li.getNumChildren() == 3 )
    N = li.getChild(0)
    self.assert_((  "N" == N.getName() ))
    self.assert_((  "vCard" == N.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == N.getURI() ))
    self.assert_( N.getNumChildren() == 2 )
    Family = N.getChild(0)
    self.assert_((  "Family" == Family.getName() ))
    self.assert_((  "vCard" == Family.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == Family.getURI() ))
    self.assert_( Family.getNumChildren() == 1 )
    Given = N.getChild(1)
    self.assert_((  "Given" == Given.getName() ))
    self.assert_((  "vCard" == Given.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == Given.getURI() ))
    self.assert_( Given.getNumChildren() == 1 )
    EMAIL = li.getChild(1)
    self.assert_((  "EMAIL" == EMAIL.getName() ))
    self.assert_((  "vCard" == EMAIL.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == EMAIL.getURI() ))
    self.assert_( EMAIL.getNumChildren() == 1 )
    ORG = li.getChild(2)
    self.assert_((  "ORG" == ORG.getName() ))
    self.assert_((  "vCard" == ORG.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == ORG.getURI() ))
    self.assert_( ORG.getNumChildren() == 1 )
    Orgname = ORG.getChild(0)
    self.assert_((  "Orgname" == Orgname.getName() ))
    self.assert_((  "vCard" == Orgname.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == Orgname.getURI() ))
    self.assert_( Orgname.getNumChildren() == 1 )
    created = desc.getChild(1)
    self.assert_((  "created" == created.getName() ))
    self.assert_((  "dcterms" == created.getPrefix() ))
    self.assert_((  "http://purl.org/dc/terms/" == created.getURI() ))
    self.assert_( created.getNumChildren() == 1 )
    cr_date = created.getChild(0)
    self.assert_((  "W3CDTF" == cr_date.getName() ))
    self.assert_((  "dcterms" == cr_date.getPrefix() ))
    self.assert_((  "http://purl.org/dc/terms/" == cr_date.getURI() ))
    self.assert_( cr_date.getNumChildren() == 1 )
    modified = desc.getChild(2)
    self.assert_((  "modified" == modified.getName() ))
    self.assert_((  "dcterms" == modified.getPrefix() ))
    self.assert_((  "http://purl.org/dc/terms/" == modified.getURI() ))
    self.assert_( modified.getNumChildren() == 1 )
    mo_date = created.getChild(0)
    self.assert_((  "W3CDTF" == mo_date.getName() ))
    self.assert_((  "dcterms" == mo_date.getPrefix() ))
    self.assert_((  "http://purl.org/dc/terms/" == mo_date.getURI() ))
    self.assert_( mo_date.getNumChildren() == 1 )
    node = None
    pass  

  def test_L3ModelHistory_parseModelHistory_Model(self):
    node = libsbml.RDFAnnotationParser.parseModelHistory(self.m)
    self.assert_( node.getNumChildren() == 1 )
    rdf = node.getChild(0)
    self.assert_((  "RDF" == rdf.getName() ))
    self.assert_((  "rdf" == rdf.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == rdf.getURI() ))
    self.assert_( rdf.getNumChildren() == 1 )
    desc = rdf.getChild(0)
    self.assert_((  "Description" == desc.getName() ))
    self.assert_((  "rdf" == desc.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == desc.getURI() ))
    self.assert_( desc.getNumChildren() == 3 )
    creator = desc.getChild(0)
    self.assert_((  "creator" == creator.getName() ))
    self.assert_((  "dc" == creator.getPrefix() ))
    self.assert_((  "http://purl.org/dc/elements/1.1/" == creator.getURI() ))
    self.assert_( creator.getNumChildren() == 1 )
    Bag = creator.getChild(0)
    self.assert_((  "Bag" == Bag.getName() ))
    self.assert_((  "rdf" == Bag.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == Bag.getURI() ))
    self.assert_( Bag.getNumChildren() == 1 )
    li = Bag.getChild(0)
    self.assert_((  "li" == li.getName() ))
    self.assert_((  "rdf" == li.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == li.getURI() ))
    self.assert_( li.getNumChildren() == 3 )
    N = li.getChild(0)
    self.assert_((  "N" == N.getName() ))
    self.assert_((  "vCard" == N.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == N.getURI() ))
    self.assert_( N.getNumChildren() == 2 )
    Family = N.getChild(0)
    self.assert_((  "Family" == Family.getName() ))
    self.assert_((  "vCard" == Family.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == Family.getURI() ))
    self.assert_( Family.getNumChildren() == 1 )
    Given = N.getChild(1)
    self.assert_((  "Given" == Given.getName() ))
    self.assert_((  "vCard" == Given.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == Given.getURI() ))
    self.assert_( Given.getNumChildren() == 1 )
    EMAIL = li.getChild(1)
    self.assert_((  "EMAIL" == EMAIL.getName() ))
    self.assert_((  "vCard" == EMAIL.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == EMAIL.getURI() ))
    self.assert_( EMAIL.getNumChildren() == 1 )
    ORG = li.getChild(2)
    self.assert_((  "ORG" == ORG.getName() ))
    self.assert_((  "vCard" == ORG.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == ORG.getURI() ))
    self.assert_( ORG.getNumChildren() == 1 )
    Orgname = ORG.getChild(0)
    self.assert_((  "Orgname" == Orgname.getName() ))
    self.assert_((  "vCard" == Orgname.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == Orgname.getURI() ))
    self.assert_( Orgname.getNumChildren() == 1 )
    created = desc.getChild(1)
    self.assert_((  "created" == created.getName() ))
    self.assert_((  "dcterms" == created.getPrefix() ))
    self.assert_((  "http://purl.org/dc/terms/" == created.getURI() ))
    self.assert_( created.getNumChildren() == 1 )
    cr_date = created.getChild(0)
    self.assert_((  "W3CDTF" == cr_date.getName() ))
    self.assert_((  "dcterms" == cr_date.getPrefix() ))
    self.assert_((  "http://purl.org/dc/terms/" == cr_date.getURI() ))
    self.assert_( cr_date.getNumChildren() == 1 )
    modified = desc.getChild(2)
    self.assert_((  "modified" == modified.getName() ))
    self.assert_((  "dcterms" == modified.getPrefix() ))
    self.assert_((  "http://purl.org/dc/terms/" == modified.getURI() ))
    self.assert_( modified.getNumChildren() == 1 )
    mo_date = created.getChild(0)
    self.assert_((  "W3CDTF" == mo_date.getName() ))
    self.assert_((  "dcterms" == mo_date.getPrefix() ))
    self.assert_((  "http://purl.org/dc/terms/" == mo_date.getURI() ))
    self.assert_( mo_date.getNumChildren() == 1 )
    node = None
    pass  

  def test_L3ModelHistory_recreate(self):
    self.c = self.m.getCompartment(1)
    expected = wrapString("<compartment id=\"A\" constant=\"true\">\n"
 + 
    "  <annotation>\n"
 + 
    "    <jd2:JDesignerLayout version=\"2.0\" MajorVersion=\"2\" MinorVersion=\"0\" BuildVersion=\"41\">\n"
 + 
    "      <jd2:header>\n"
 + 
    "        <jd2:VersionHeader JDesignerVersion=\"2.0\"/>\n"
 + 
    "        <jd2:ModelHeader Author=\"Mr Untitled\" ModelVersion=\"0.0\" ModelTitle=\"untitled\"/>\n"
 + 
    "        <jd2:TimeCourseDetails timeStart=\"0\" timeEnd=\"10\" numberOfPoints=\"1000\"/>\n"
 + 
    "      </jd2:header>\n"
 + 
    "    </jd2:JDesignerLayout>\n"
 + 
    "    <rdf:RDF xmlns:rdf=\"http://www.w3.org/1999/02/22-rdf-syntax-ns#\" xmlns:dc=\"http://purl.org/dc/elements/1.1/\" xmlns:dcterms=\"http://purl.org/dc/terms/\" xmlns:vCard=\"http://www.w3.org/2001/vcard-rdf/3.0#\" xmlns:bqbiol=\"http://biomodels.net/biology-qualifiers/\" xmlns:bqmodel=\"http://biomodels.net/model-qualifiers/\">\n"
 + 
    "      <rdf:Description rdf:about=\"#\">\n"
 + 
    "        <dc:creator>\n"
 + 
    "          <rdf:Bag>\n"
 + 
    "            <rdf:li rdf:parseType=\"Resource\">\n"
 + 
    "              <vCard:N rdf:parseType=\"Resource\">\n"
 + 
    "                <vCard:Family>Le Novere</vCard:Family>\n"
 + 
    "                <vCard:Given>Nicolas</vCard:Given>\n"
 + 
    "              </vCard:N>\n"
 + 
    "              <vCard:EMAIL>lenov@ebi.ac.uk</vCard:EMAIL>\n"
 + 
    "              <vCard:ORG rdf:parseType=\"Resource\">\n"
 + 
    "                <vCard:Orgname>EMBL-EBI</vCard:Orgname>\n"
 + 
    "              </vCard:ORG>\n"
 + 
    "            </rdf:li>\n"
 + 
    "          </rdf:Bag>\n"
 + 
    "        </dc:creator>\n"
 + 
    "        <dcterms:created rdf:parseType=\"Resource\">\n"
 + 
    "          <dcterms:W3CDTF>2005-02-02T14:56:11Z</dcterms:W3CDTF>\n"
 + 
    "        </dcterms:created>\n"
 + 
    "        <dcterms:modified rdf:parseType=\"Resource\">\n"
 + 
    "          <dcterms:W3CDTF>2006-05-30T10:46:02Z</dcterms:W3CDTF>\n"
 + 
    "        </dcterms:modified>\n"
 + 
    "        <bqbiol:is>\n"
 + 
    "          <rdf:Bag>\n"
 + 
    "            <rdf:li rdf:resource=\"http://www.geneontology.org/#GO:0007274\"/>\n"
 + 
    "          </rdf:Bag>\n"
 + 
    "        </bqbiol:is>\n"
 + 
    "      </rdf:Description>\n"
 + 
    "    </rdf:RDF>\n"
 + 
    "  </annotation>\n"
 + 
    "</compartment>")
    self.assertEqual( True, self.equals(expected,self.c.toSBML()) )
    pass  

  def test_L3ModelHistory_recreateFromEmpty(self):
    self.c = self.m.getCompartment(3)
    expected = wrapString("<compartment id=\"C\" constant=\"true\">\n"
 + 
    "  <annotation>\n"
 + 
    "    <rdf:RDF xmlns:rdf=\"http://www.w3.org/1999/02/22-rdf-syntax-ns#\" xmlns:dc=\"http://purl.org/dc/elements/1.1/\" xmlns:dcterms=\"http://purl.org/dc/terms/\" xmlns:vCard=\"http://www.w3.org/2001/vcard-rdf/3.0#\" xmlns:bqbiol=\"http://biomodels.net/biology-qualifiers/\" xmlns:bqmodel=\"http://biomodels.net/model-qualifiers/\">\n"
 + 
    "      <rdf:Description rdf:about=\"#\">\n"
 + 
    "        <dc:creator>\n"
 + 
    "          <rdf:Bag>\n"
 + 
    "            <rdf:li rdf:parseType=\"Resource\">\n"
 + 
    "              <vCard:N rdf:parseType=\"Resource\">\n"
 + 
    "                <vCard:Family>Le Novere</vCard:Family>\n"
 + 
    "                <vCard:Given>Nicolas</vCard:Given>\n"
 + 
    "              </vCard:N>\n"
 + 
    "              <vCard:EMAIL>lenov@ebi.ac.uk</vCard:EMAIL>\n"
 + 
    "              <vCard:ORG rdf:parseType=\"Resource\">\n"
 + 
    "                <vCard:Orgname>EMBL-EBI</vCard:Orgname>\n"
 + 
    "              </vCard:ORG>\n"
 + 
    "            </rdf:li>\n"
 + 
    "          </rdf:Bag>\n"
 + 
    "        </dc:creator>\n"
 + 
    "        <dcterms:created rdf:parseType=\"Resource\">\n"
 + 
    "          <dcterms:W3CDTF>2005-02-02T14:56:11Z</dcterms:W3CDTF>\n"
 + 
    "        </dcterms:created>\n"
 + 
    "        <dcterms:modified rdf:parseType=\"Resource\">\n"
 + 
    "          <dcterms:W3CDTF>2006-05-30T10:46:02Z</dcterms:W3CDTF>\n"
 + 
    "        </dcterms:modified>\n"
 + 
    "        <bqbiol:is>\n"
 + 
    "          <rdf:Bag>\n"
 + 
    "            <rdf:li rdf:resource=\"http://www.geneontology.org/#GO:0007274\"/>\n"
 + 
    "          </rdf:Bag>\n"
 + 
    "        </bqbiol:is>\n"
 + 
    "      </rdf:Description>\n"
 + 
    "    </rdf:RDF>\n"
 + 
    "  </annotation>\n"
 + 
    "</compartment>")
    self.assertEqual( True, self.equals(expected,self.c.toSBML()) )
    pass  

  def test_L3ModelHistory_recreateFromEmpty_Model(self):
    ann = self.m.getAnnotationString()
    self.m.setAnnotation(None)
    n1 = self.m.getAnnotation()
    self.assert_( n1 == None )
    self.m.setAnnotation(ann)
    n1 = self.m.getAnnotation()
    expected = wrapString("<annotation>\n" + 
    "  <rdf:RDF xmlns:rdf=\"http://www.w3.org/1999/02/22-rdf-syntax-ns#\" xmlns:dc=\"http://purl.org/dc/elements/1.1/\" xmlns:dcterms=\"http://purl.org/dc/terms/\" xmlns:vCard=\"http://www.w3.org/2001/vcard-rdf/3.0#\" xmlns:bqbiol=\"http://biomodels.net/biology-qualifiers/\" xmlns:bqmodel=\"http://biomodels.net/model-qualifiers/\">\n" + 
    "    <rdf:Description rdf:about=\"#_000001\">\n" + 
    "      <dc:creator>\n" + 
    "        <rdf:Bag>\n" + 
    "          <rdf:li rdf:parseType=\"Resource\">\n" + 
    "            <vCard:N rdf:parseType=\"Resource\">\n" + 
    "              <vCard:Family>Le Novere</vCard:Family>\n" + 
    "              <vCard:Given>Nicolas</vCard:Given>\n" + 
    "            </vCard:N>\n" + 
    "            <vCard:EMAIL>lenov@ebi.ac.uk</vCard:EMAIL>\n" + 
    "            <vCard:ORG rdf:parseType=\"Resource\">\n" + 
    "              <vCard:Orgname>EMBL-EBI</vCard:Orgname>\n" + 
    "            </vCard:ORG>\n" + 
    "          </rdf:li>\n" + 
    "        </rdf:Bag>\n" + 
    "      </dc:creator>\n" + 
    "      <dcterms:created rdf:parseType=\"Resource\">\n" + 
    "        <dcterms:W3CDTF>2005-02-02T14:56:11Z</dcterms:W3CDTF>\n" + 
    "      </dcterms:created>\n" + 
    "      <dcterms:modified rdf:parseType=\"Resource\">\n" + 
    "        <dcterms:W3CDTF>2006-05-30T10:46:02Z</dcterms:W3CDTF>\n" + 
    "      </dcterms:modified>\n" + 
    "    </rdf:Description>\n" + 
    "  </rdf:RDF>\n" + 
    "</annotation>")
    self.assertEqual( True, self.equals(expected,n1.toXMLString()) )
    pass  

  def test_L3ModelHistory_recreateWithOutOther(self):
    self.c = self.m.getCompartment(2)
    expected = wrapString("<compartment id=\"B\" constant=\"true\">\n"
 + 
    "  <annotation>\n"
 + 
    "    <jd2:JDesignerLayout version=\"2.0\" MajorVersion=\"2\" MinorVersion=\"0\" BuildVersion=\"41\">\n"
 + 
    "      <jd2:header>\n"
 + 
    "        <jd2:VersionHeader JDesignerVersion=\"2.0\"/>\n"
 + 
    "        <jd2:ModelHeader Author=\"Mr Untitled\" ModelVersion=\"0.0\" ModelTitle=\"untitled\"/>\n"
 + 
    "        <jd2:TimeCourseDetails timeStart=\"0\" timeEnd=\"10\" numberOfPoints=\"1000\"/>\n"
 + 
    "      </jd2:header>\n"
 + 
    "    </jd2:JDesignerLayout>\n"
 + 
    "  </annotation>\n"
 + 
    "</compartment>")
    self.assertEqual( True, self.equals(expected,self.c.toSBML()) )
    pass  

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestL3ModelHistory))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)

