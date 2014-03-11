/**
 * @cond doxygenLibsbmlInternal
 *
 * @file    UniquePortIds.cpp
 * @brief   Ensures the appropriate ids within a Model are unique
 * @author  Sarah Keating
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2014 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *     3. University of Heidelberg, Heidelberg, Germany
 * 
 * Copyright 2011-2012 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->*/

#include <sbml/Model.h>
#include "UniquePortIds.h"

/** @cond doxygenIgnored */

using namespace std;

/** @endcond */

LIBSBML_CPP_NAMESPACE_BEGIN
#ifdef __cplusplus

/*
 * Creates a new Constraint with the given constraint id.
 */
UniquePortIds::UniquePortIds (unsigned int id, CompValidator& v) :
  UniqueCompIdBase(id, v)
{
}


/*
 * Destroys this Constraint.
 */
UniquePortIds::~UniquePortIds ()
{
}


/*
 * Checks that all ids on the following Model objects are unique:
 * FunctionDefinitions, Species, Compartments, global Parameters,
 * Reactions, and Events.
 */
void
UniquePortIds::doCheck (const Model& m)
{
  unsigned int n, size;

  const CompModelPlugin * plug = 
    static_cast <const CompModelPlugin*>(m.getPlugin("comp"));
  if (plug == NULL)
  {
    return;
  }

  size = plug->getNumPorts();
  for (n = 0; n < size; ++n) 
  {
    checkId( *(plug->getPort(n)) );
  }

  reset();
}

#endif /* __cplusplus */

LIBSBML_CPP_NAMESPACE_END

/** @endcond */
