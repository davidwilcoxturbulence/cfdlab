#include <iostream>
#include <assert.h>
#include <vector>
#include "grid.h"

using namespace std;

// Grid constructor
Grid::Grid(unsigned int nx_, unsigned int ny_)
   :
   nx (nx_),
   ny (ny_),
   x  (nx_, ny_),
   y  (nx_, ny_)
{

   n_cells = (nx-1) * (ny-1);

}

// destructor
Grid::~Grid ()
{
}

void Grid::allocate ()
{
   assert (nx > 1);
   assert (ny > 1);

   x.allocate (nx,ny);
   y.allocate (nx,ny);

   ibeg.resize (n_boundary);
   iend.resize (n_boundary);
   jbeg.resize (n_boundary);
   jend.resize (n_boundary);
   boundary_condition.resize (n_boundary);
   b_type.resize (n_boundary);

   n_cells = (nx-1) * (ny-1);
}

// map from (i,j) to cell number
// cells are numbered starting at bottom left corner, then going
// horizontally from i=0 to i=grid.nx-2
unsigned int Grid::cell_num (const unsigned int i, const unsigned int j)
{
   return i + (nx-1)*j;
}