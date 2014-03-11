/**
 * @cond doxygenLibsbmlInternal
 *
 * @file    UniqueModelIds.h
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

#ifndef UniqueModelIds_h
#define UniqueModelIds_h


#ifdef __cplusplus

#include <string>

#include "UniqueCompIdBase.h"

LIBSBML_CPP_NAMESPACE_BEGIN

class UniqueModelIds: public UniqueCompIdBase
{
public:

  /**
   * Creates a new Constraint with the given constraint id.
   */
  UniqueModelIds (unsigned int id, CompValidator& v);

  /**
   * Destroys this Constraint.
   */
  virtual ~UniqueModelIds ();


protected:

  /**
   * Checks that all ids on the following SBMLDocument objects are unique:
   * Model (both <model> and <modelDefinition> objects) and 
   * ExternalModelDefinition.
   */
  virtual void doCheck (const Model& m);
};

LIBSBML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif  /* UniqueModelIds_h */

/** @endcond */
