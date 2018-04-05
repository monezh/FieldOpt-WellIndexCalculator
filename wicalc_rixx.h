//
// Created by bellout on 3/2/18.
//

#ifndef FIELDOPT_WICALC_RIXX_H
#define FIELDOPT_WICALC_RIXX_H

// -----------------------------------------------------------------
// FieldOpt::RESINXX
#include "resinxx/well_path.h"

// -----------------------------------------------------------------
namespace Reservoir {
namespace WellIndexCalculation {

// -----------------------------------------------------------------
using std::cout;
using std::endl;
using std::string;
using std::vector;

//==================================================================
class wicalc_rixx {
 public:
  // ---------------------------------------------------------------
  wicalc_rixx(Settings::Model::Well well_settings,
              Grid::Grid *grid,
              RICaseData *ricasedata = nullptr);

  // ---------------------------------------------------------------
  ~wicalc_rixx();

  // ---------------------------------------------------------------
  Settings::Model::Well well_settings_;
  vector<double> intersections_;
  Grid::Grid* grid_;

  // -------------------------------------------------------
  RICaseData* ricasedata_;

  // Experimental
  // cvf::ref<RICaseData> ricasedatac_;
  // cvf::ref<RICaseData> ricasedatap_;
  RIReaderECL* rireaderecl_;
  // RIGrid* rigrid_;

  // ---------------------------------------------------------------
  // WellPath *wellPath_;
  const RIActiveCellInfo* activeCellInfo_;

  // ---------------------------------------------------------------
  void collectIntersectedCells(vector<IntersectedCell> &isc_cells,
                               vector<WellPathCellIntersectionInfo> isc_info,
                               WellDefinition well,
                               WellPath& wellPath,
                               int rank=0);

  // ---------------------------------------------------------------
  void calculateWellPathIntersections(const WellPath& wellPath,
                                      vector<double> &isc_values);

  // ---------------------------------------------------------------
  void ComputeWellBlocks(map<string, vector<IntersectedCell>> &well_indices,
                         vector<WellDefinition> &wells,
                         int rank = 0);

 protected:
  // ---------------------------------------------------------------
  // size_t grid_count_;
  // size_t cell_count_;
  // size_t gcellarray_sz_;
  int cl_; // cl: current dbg.msg.level

};

}
}

#endif //FIELDOPT_WICALC_RIXX_H