/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: assign6BoundariesNB.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Dec-2015 14:45:42
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "assign6BoundariesNB.h"
#include "assign6BoundariesNB_emxutil.h"
#include "repmat.h"
#include "fprintf.h"
#include "meshgrid.h"
#include "sum.h"
#include <stdio.h>

/* Function Declarations */
static void eml_null_assignment(double x_data[], int x_size[1], const boolean_T
  idx_data[], const int idx_size[1]);
static double rt_roundd_snf(double u);

/* Function Definitions */

/*
 * Arguments    : double x_data[]
 *                int x_size[1]
 *                const boolean_T idx_data[]
 *                const int idx_size[1]
 * Return Type  : void
 */
static void eml_null_assignment(double x_data[], int x_size[1], const boolean_T
  idx_data[], const int idx_size[1])
{
  int nxin;
  int k0;
  int k;
  int nxout;
  double b_x_data[26];
  nxin = x_size[0];
  k0 = 0;
  for (k = 1; k <= idx_size[0]; k++) {
    k0 += idx_data[k - 1];
  }

  nxout = x_size[0] - k0;
  k0 = -1;
  for (k = 1; k <= nxin; k++) {
    if ((k > idx_size[0]) || (!idx_data[k - 1])) {
      k0++;
      x_data[k0] = x_data[k - 1];
    }
  }

  if (x_size[0] != 1) {
    if (1 > nxout) {
      k0 = 0;
    } else {
      k0 = nxout;
    }

    for (nxout = 0; nxout < k0; nxout++) {
      b_x_data[nxout] = x_data[nxout];
    }

    x_size[0] = k0;
    for (nxout = 0; nxout < k0; nxout++) {
      x_data[nxout] = b_x_data[nxout];
    }
  } else if (1 > nxout) {
    x_size[0] = 0;
  } else {
    x_size[0] = nxout;
  }
}

/*
 * Arguments    : double u
 * Return Type  : double
 */
static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/*
 * Arguments    : emxArray_uint32_T *L
 *                const emxArray_real_T *bbVol
 * Return Type  : void
 */
void assign6BoundariesNB(emxArray_uint32_T *L, const emxArray_real_T *bbVol)
{
  emxArray_boolean_T *x;
  int voxelCount;
  int nm1d2;
  int nx;
  emxArray_int32_T *ii;
  int idx;
  boolean_T exitg3;
  boolean_T guard2 = false;
  emxArray_real_T *boundaries;
  emxArray_real_T *newBoundaryAssignments;
  int varargin_1[2];
  double b_bbVol[3];
  double dv0[78];
  double dv1[78];
  static const signed char translation_matrix[78] = { -1, -1, -1, -1, -1, -1, -1,
    -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, 0, 0,
    0, 1, 1, 1, -1, -1, -1, 0, 0, 1, 1, 1, -1, -1, -1, 0, 0, 0, 1, 1, 1, -1, 0,
    1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0,
    1 };

  int apnd;
  emxArray_real_T *shift_by_channel;
  int k;
  emxArray_real_T *validIdxs;
  emxArray_real_T *bar;
  double dv2[26];
  double iterCount;
  emxArray_real_T *r0;
  emxArray_real_T *a;
  emxArray_real_T *c_bbVol;
  int kk;
  int validIdx_size[1];
  double validIdx_data[26];
  int tmp_size[1];
  boolean_T tmp_data[26];
  double validIdx[2];
  double s;
  double b_validIdx[2];
  double y_data[26];
  int y_size_idx_0;
  int ix;
  boolean_T exitg2;
  boolean_T exitg1;
  boolean_T guard1 = false;
  signed char i0;
  emxInit_boolean_T(&x, 3);
  voxelCount = L->size[0] * L->size[1] * L->size[2];
  nm1d2 = x->size[0] * x->size[1] * x->size[2];
  x->size[0] = L->size[0];
  x->size[1] = L->size[1];
  x->size[2] = L->size[2];
  emxEnsureCapacity((emxArray__common *)x, nm1d2, (int)sizeof(boolean_T));
  nx = L->size[0] * L->size[1] * L->size[2];
  for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
    x->data[nm1d2] = (L->data[nm1d2] == 0U);
  }

  emxInit_int32_T(&ii, 1);
  nx = x->size[0] * x->size[1] * x->size[2];
  idx = 0;
  nm1d2 = ii->size[0];
  ii->size[0] = nx;
  emxEnsureCapacity((emxArray__common *)ii, nm1d2, (int)sizeof(int));
  nm1d2 = 1;
  exitg3 = false;
  while ((!exitg3) && (nm1d2 <= nx)) {
    guard2 = false;
    if (x->data[nm1d2 - 1]) {
      idx++;
      ii->data[idx - 1] = nm1d2;
      if (idx >= nx) {
        exitg3 = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      nm1d2++;
    }
  }

  if (nx == 1) {
    if (idx == 0) {
      nm1d2 = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, nm1d2, (int)sizeof(int));
    }
  } else {
    nm1d2 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)ii, nm1d2, (int)sizeof(int));
  }

  emxInit_real_T2(&boundaries, 1);
  nm1d2 = boundaries->size[0];
  boundaries->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)boundaries, nm1d2, (int)sizeof(double));
  nx = ii->size[0];
  for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
    boundaries->data[nm1d2] = ii->data[nm1d2];
  }

  emxInit_real_T2(&newBoundaryAssignments, 1);

  /*  linear indices  */
  varargin_1[0] = boundaries->size[0];
  nm1d2 = newBoundaryAssignments->size[0];
  newBoundaryAssignments->size[0] = varargin_1[0];
  emxEnsureCapacity((emxArray__common *)newBoundaryAssignments, nm1d2, (int)
                    sizeof(double));
  nx = varargin_1[0];
  for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
    newBoundaryAssignments->data[nm1d2] = 0.0;
  }

  /*  translation_matrix  = fliplr(combvec([-1,0,1],[-1,0,1],[-1,0,1])');translation_matrix(ceil(size(translation_matrix,1)/2),:)=[]; */
  /*  a = {[-1,0,1],[-1,0,1],[-1,0,1]};v=cell(3,1);[v{:}] = ndgrid(a{:});res = reshape(cat(4,v{:}),[],3);translation_matrix(ceil(size(res,1)/2),:)=[]; */
  b_bbVol[0] = bbVol->size[0];
  b_bbVol[1] = (double)bbVol->size[0] * (double)bbVol->size[1];
  b_bbVol[2] = 1.0;
  repmat(b_bbVol, dv0);
  for (nm1d2 = 0; nm1d2 < 78; nm1d2++) {
    dv1[nm1d2] = dv0[nm1d2] * (double)translation_matrix[nm1d2];
  }

  if (bbVol->size[3] - 1 < 0) {
    idx = -1;
    apnd = -1;
  } else {
    idx = (int)floor(((double)bbVol->size[3] - 1.0) + 0.5) - 1;
    apnd = idx + 1;
    nx = (idx - bbVol->size[3]) + 2;
    if (fabs(nx) < 4.4408920985006262E-16 * fabs((double)bbVol->size[3] - 1.0))
    {
      idx++;
      apnd = bbVol->size[3] - 1;
    } else if (nx > 0) {
      apnd = idx;
    } else {
      idx++;
    }
  }

  emxInit_real_T(&shift_by_channel, 2);
  nm1d2 = shift_by_channel->size[0] * shift_by_channel->size[1];
  shift_by_channel->size[0] = 1;
  shift_by_channel->size[1] = idx + 1;
  emxEnsureCapacity((emxArray__common *)shift_by_channel, nm1d2, (int)sizeof
                    (double));
  if (idx + 1 > 0) {
    shift_by_channel->data[0] = 0.0;
    if (idx + 1 > 1) {
      shift_by_channel->data[idx] = apnd;
      nm1d2 = (idx + (idx < 0)) >> 1;
      for (k = 1; k < nm1d2; k++) {
        shift_by_channel->data[k] = k;
        shift_by_channel->data[idx - k] = apnd - k;
      }

      if (nm1d2 << 1 == idx) {
        shift_by_channel->data[nm1d2] = (double)apnd / 2.0;
      } else {
        shift_by_channel->data[nm1d2] = nm1d2;
        shift_by_channel->data[nm1d2 + 1] = apnd - nm1d2;
      }
    }
  }

  nm1d2 = shift_by_channel->size[0] * shift_by_channel->size[1];
  shift_by_channel->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)shift_by_channel, nm1d2, (int)sizeof
                    (double));
  nx = shift_by_channel->size[0];
  nm1d2 = shift_by_channel->size[1];
  nx *= nm1d2;
  for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
    shift_by_channel->data[nm1d2] *= (double)voxelCount;
  }

  emxInit_real_T(&validIdxs, 2);
  emxInit_real_T(&bar, 2);

  /*  1 x numChannels vector containing multiples of the number of voxels in each 3D stack */
  sum(dv1, dv2);
  meshgrid(boundaries, dv2, validIdxs, bar);
  nm1d2 = validIdxs->size[0] * validIdxs->size[1];
  emxEnsureCapacity((emxArray__common *)validIdxs, nm1d2, (int)sizeof(double));
  nx = validIdxs->size[0];
  nm1d2 = validIdxs->size[1];
  nx *= nm1d2;
  for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
    validIdxs->data[nm1d2] += bar->data[nm1d2];
  }

  iterCount = 1.0;
  emxInit_real_T(&r0, 2);
  emxInit_real_T(&a, 2);
  emxInit_real_T(&c_bbVol, 2);
  while (!(boundaries->size[0] == 0)) {
    for (kk = 0; kk < boundaries->size[0]; kk++) {
      nx = validIdxs->size[0];
      validIdx_size[0] = nx;
      for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
        validIdx_data[nm1d2] = validIdxs->data[nm1d2 + validIdxs->size[0] * kk];
      }

      tmp_size[0] = nx;
      for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
        tmp_data[nm1d2] = (validIdx_data[nm1d2] < 1.0);
      }

      eml_null_assignment(validIdx_data, validIdx_size, tmp_data, tmp_size);

      /*  index below range */
      tmp_size[0] = validIdx_size[0];
      nx = validIdx_size[0];
      for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
        tmp_data[nm1d2] = (validIdx_data[nm1d2] > voxelCount);
      }

      eml_null_assignment(validIdx_data, validIdx_size, tmp_data, tmp_size);

      /*  index above range */
      tmp_size[0] = validIdx_size[0];
      nx = validIdx_size[0];
      for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
        tmp_data[nm1d2] = (L->data[(int)validIdx_data[nm1d2] - 1] == 0U);
      }

      eml_null_assignment(validIdx_data, validIdx_size, tmp_data, tmp_size);

      /*  BOUNDARY VOXELS ARE INELIGIBLE */
      if (!(validIdx_size[0] == 0)) {
        /*              validVal                   = bbVol(repmat(shift_by_channel,[numel(validIdx),1]) + repmat(validIdx,[1 size(bbVol,4)])); % validVal has shape numel(validIdx) x size(bbVol,4); a 2D array in which each column is the list of values for those linear indices in that color */
        /*              thisVal                    = bbVol(shift_by_channel + thisVoxIdx); % val is the val of the pixel in the volume of thisVoxIdx for each color channel */
        /*              allNormSq                  = sum((validVal - repmat(thisVal, [numel(validIdx), 1])).^2, 2); % normalizing the neighbors by the center voxel, squaring, then summing along the rows */
        /*              [~,pos]                    = min(allNormSq); % the indices of the minimum of the normed values */
        validIdx[0] = validIdx_size[0];
        validIdx[1] = 1.0;
        b_repmat(shift_by_channel, validIdx, bar);
        varargin_1[1] = bbVol->size[3];
        nm1d2 = r0->size[0] * r0->size[1];
        r0->size[0] = validIdx_size[0];
        r0->size[1] = varargin_1[1];
        emxEnsureCapacity((emxArray__common *)r0, nm1d2, (int)sizeof(double));
        if (!(varargin_1[1] == 0)) {
          nx = validIdx_size[0];
          for (idx = 1; idx <= varargin_1[1]; idx++) {
            nm1d2 = (idx - 1) * nx;
            for (k = 0; k + 1 <= nx; k++) {
              r0->data[nm1d2 + k] = validIdx_data[k];
            }
          }
        }

        nm1d2 = a->size[0] * a->size[1];
        a->size[0] = bar->size[0];
        a->size[1] = bar->size[1];
        emxEnsureCapacity((emxArray__common *)a, nm1d2, (int)sizeof(double));
        nx = bar->size[0] * bar->size[1];
        for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
          a->data[nm1d2] = bbVol->data[(int)(bar->data[nm1d2] + r0->data[nm1d2])
            - 1];
        }

        nm1d2 = c_bbVol->size[0] * c_bbVol->size[1];
        c_bbVol->size[0] = 1;
        c_bbVol->size[1] = shift_by_channel->size[1];
        emxEnsureCapacity((emxArray__common *)c_bbVol, nm1d2, (int)sizeof(double));
        s = boundaries->data[kk];
        nx = shift_by_channel->size[0] * shift_by_channel->size[1];
        for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
          c_bbVol->data[nm1d2] = bbVol->data[(int)(shift_by_channel->data[nm1d2]
            + s) - 1];
        }

        b_validIdx[0] = validIdx_size[0];
        b_validIdx[1] = 1.0;
        b_repmat(c_bbVol, b_validIdx, bar);
        nm1d2 = a->size[0] * a->size[1];
        emxEnsureCapacity((emxArray__common *)a, nm1d2, (int)sizeof(double));
        nm1d2 = a->size[0];
        nx = a->size[1];
        nx *= nm1d2;
        for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
          a->data[nm1d2] -= bar->data[nm1d2];
        }

        for (nm1d2 = 0; nm1d2 < 2; nm1d2++) {
          varargin_1[nm1d2] = a->size[nm1d2];
        }

        nm1d2 = bar->size[0] * bar->size[1];
        bar->size[0] = varargin_1[0];
        bar->size[1] = varargin_1[1];
        emxEnsureCapacity((emxArray__common *)bar, nm1d2, (int)sizeof(double));
        nm1d2 = a->size[0] * a->size[1];
        for (k = 0; k + 1 <= nm1d2; k++) {
          bar->data[k] = a->data[k] * a->data[k];
        }

        y_size_idx_0 = bar->size[0];
        if (bar->size[1] == 0) {
          for (nm1d2 = 0; nm1d2 < y_size_idx_0; nm1d2++) {
            y_data[nm1d2] = 0.0;
          }
        } else {
          nx = bar->size[0];
          idx = -1;
          apnd = -1;
          for (nm1d2 = 1; nm1d2 <= nx; nm1d2++) {
            apnd++;
            ix = apnd;
            s = bar->data[apnd];
            for (k = 2; k <= bar->size[1]; k++) {
              ix += nx;
              s += bar->data[ix];
            }

            idx++;
            y_data[idx] = s;
          }
        }

        apnd = 1;
        s = y_data[0];
        nx = 0;
        if (y_size_idx_0 > 1) {
          if (rtIsNaN(y_data[0])) {
            ix = 2;
            exitg2 = false;
            while ((!exitg2) && (ix <= y_size_idx_0)) {
              apnd = ix;
              if (!rtIsNaN(y_data[ix - 1])) {
                s = y_data[ix - 1];
                nx = ix - 1;
                exitg2 = true;
              } else {
                ix++;
              }
            }
          }

          if (apnd < y_size_idx_0) {
            while (apnd + 1 <= y_size_idx_0) {
              if (y_data[apnd] < s) {
                s = y_data[apnd];
                nx = apnd;
              }

              apnd++;
            }
          }
        }

        /*  the indices of the minimum of the normed values */
        newBoundaryAssignments->data[kk] = L->data[(int)validIdx_data[nx] - 1];

        /*  isn't this potentially assigning a vector to a 1x1 spot? */
      }
    }

    nx = newBoundaryAssignments->size[0];
    for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
      L->data[(int)boundaries->data[nm1d2] - 1] = (unsigned int)rt_roundd_snf
        (newBoundaryAssignments->data[nm1d2]);
    }

    nm1d2 = x->size[0] * x->size[1] * x->size[2];
    x->size[0] = L->size[0];
    x->size[1] = L->size[1];
    x->size[2] = L->size[2];
    emxEnsureCapacity((emxArray__common *)x, nm1d2, (int)sizeof(boolean_T));
    nx = L->size[0] * L->size[1] * L->size[2];
    for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
      x->data[nm1d2] = (L->data[nm1d2] == 0U);
    }

    nx = x->size[0] * x->size[1] * x->size[2];
    idx = 0;
    nm1d2 = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity((emxArray__common *)ii, nm1d2, (int)sizeof(int));
    nm1d2 = 1;
    exitg1 = false;
    while ((!exitg1) && (nm1d2 <= nx)) {
      guard1 = false;
      if (x->data[nm1d2 - 1]) {
        idx++;
        ii->data[idx - 1] = nm1d2;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        nm1d2++;
      }
    }

    if (nx == 1) {
      if (idx == 0) {
        nm1d2 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity((emxArray__common *)ii, nm1d2, (int)sizeof(int));
      }
    } else {
      nm1d2 = ii->size[0];
      if (1 > idx) {
        ii->size[0] = 0;
      } else {
        ii->size[0] = idx;
      }

      emxEnsureCapacity((emxArray__common *)ii, nm1d2, (int)sizeof(int));
    }

    nm1d2 = boundaries->size[0];
    boundaries->size[0] = ii->size[0];
    emxEnsureCapacity((emxArray__common *)boundaries, nm1d2, (int)sizeof(double));
    nx = ii->size[0];
    for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
      boundaries->data[nm1d2] = ii->data[nm1d2];
    }

    varargin_1[0] = boundaries->size[0];
    nm1d2 = newBoundaryAssignments->size[0];
    newBoundaryAssignments->size[0] = varargin_1[0];
    emxEnsureCapacity((emxArray__common *)newBoundaryAssignments, nm1d2, (int)
                      sizeof(double));
    nx = varargin_1[0];
    for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
      newBoundaryAssignments->data[nm1d2] = 0.0;
    }

    iterCount++;
  }

  emxFree_real_T(&c_bbVol);
  emxFree_real_T(&a);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&r0);
  emxFree_real_T(&bar);
  emxFree_real_T(&validIdxs);
  emxFree_real_T(&shift_by_channel);
  emxFree_real_T(&newBoundaryAssignments);
  emxFree_real_T(&boundaries);
  s = rt_roundd_snf(iterCount);
  if (s < 128.0) {
    i0 = (signed char)s;
  } else {
    i0 = MAX_int8_T;
  }

  b_fprintf(i0);
}

/*
 * File trailer for assign6BoundariesNB.c
 *
 * [EOF]
 */
