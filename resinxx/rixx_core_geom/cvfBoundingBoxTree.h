//####################################################################
//
//   Custom Visualization Core library
//   Copyright (C) Ceetron Solutions AS
//
//   This library may be used under the terms of either the GNU General Public License or
//   the GNU Lesser General Public License as follows:
//
//   GNU General Public License Usage
//   This library is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   This library is distributed in the hope that it will be useful, but WITHOUT ANY
//   WARRANTY; without even the implied warranty of MERCHANTABILITY or
//   FITNESS FOR A PARTICULAR PURPOSE.
//
//   See the GNU General Public License at <<http://www.gnu.org/licenses/gpl.html>>
//   for more details.
//
//   GNU Lesser General Public License Usage
//   This library is free software; you can redistribute it and/or modify
//   it under the terms of the GNU Lesser General Public License as published by
//   the Free Software Foundation; either version 2.1 of the License, or
//   (at your option) any later version.
//
//   This library is distributed in the hope that it will be useful, but WITHOUT ANY
//   WARRANTY; without even the implied warranty of MERCHANTABILITY or
//   FITNESS FOR A PARTICULAR PURPOSE.
//
//   See the GNU Lesser General Public License at <<http://www.gnu.org/licenses/lgpl-2.1.html>>
//   for more details.
//
//####################################################################

// -----------------------------------------------------------------
#pragma once

// STD -------------------------------------------------------------
#include <vector>

// QT --------------------------------------------------------------
//#include <QDateTime>

// FIELDOPT: UTILITIES ---------------------------------------------
#include <Utilities/time.hpp>
#include <Utilities/debug.hpp>
#include <Utilities/colors.hpp>

// RESINSIGHT: FWK/VIZFWK/LIBCORE ----------------------------------
#include "cvfBase.h"
//#include "cvfObject.h"

// RESINSIGHT: FWK/VIZFWK/LIBGEOMETRY ------------------------------
#include "cvfBoundingBox.h"

namespace cvf {

class BoundingBoxTreeImpl;

//====================================================================
// An axis-aligned bounding-box search tree class
class BoundingBoxTree // : public cvf::Object
{
 public:
  BoundingBoxTree();
  ~BoundingBoxTree();

  void buildTreeFromBoundingBoxes(
      const vector<cvf::BoundingBox>& boundingBoxes,
      const vector<size_t>* optionalBoundingBoxIds);

  void findIntersections(
      const cvf::BoundingBox& inputBB,
      vector<size_t>* bbIdsOrIndexesIntersected) const;

 private:

  BoundingBoxTreeImpl* m_implTree;
};

} // Namespace cvf

