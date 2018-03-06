/////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) 2017  Statoil ASA
// 
//  ResInsight is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
// 
//  ResInsight is distributed in the hope that it will be useful, but WITHOUT ANY
//  WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE.
// 
//  See the GNU General Public License at <http://www.gnu.org/licenses/gpl.html> 
//  for more details.
//
/////////////////////////////////////////////////////////////////////////////////

#include "RiaPorosityModel.h"
#include "../../Fwk/AppFwk/cafProjectDataModel/cafPdmCore/cafAppEnum.h"

namespace caf
{
template<>
void caf::AppEnum< RiaDefines::PorosityModelType >::setUp() {
  addItem(RiaDefines::MATRIX_MODEL, "MATRIX_MODEL", "Matrix");
  addItem(RiaDefines::FRACTURE_MODEL, "FRACTURE_MODEL", "Fracture");
  setDefault(RiaDefines::MATRIX_MODEL);
}
}
