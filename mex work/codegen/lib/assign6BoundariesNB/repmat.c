/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: repmat.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Dec-2015 14:45:42
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "assign6BoundariesNB.h"
#include "repmat.h"
#include "assign6BoundariesNB_emxutil.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *a
 *                const double varargin_1[2]
 *                emxArray_real_T *b
 * Return Type  : void
 */
void b_repmat(const emxArray_real_T *a, const double varargin_1[2],
              emxArray_real_T *b)
{
  int outsize_idx_1;
  int jcol;
  int ibmat;
  int itilerow;
  outsize_idx_1 = a->size[1];
  jcol = b->size[0] * b->size[1];
  b->size[0] = (int)varargin_1[0];
  b->size[1] = outsize_idx_1;
  emxEnsureCapacity((emxArray__common *)b, jcol, (int)sizeof(double));
  if ((!(a->size[1] == 0)) && (!(outsize_idx_1 == 0))) {
    outsize_idx_1 = (int)varargin_1[0];
    for (jcol = 0; jcol + 1 <= a->size[1]; jcol++) {
      ibmat = jcol * outsize_idx_1;
      for (itilerow = 1; itilerow <= outsize_idx_1; itilerow++) {
        b->data[(ibmat + itilerow) - 1] = a->data[jcol];
      }
    }
  }
}

/*
 * Arguments    : const double a[3]
 *                double b[78]
 * Return Type  : void
 */
void repmat(const double a[3], double b[78])
{
  int jcol;
  int ibmat;
  int itilerow;
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * 26;
    for (itilerow = 0; itilerow < 26; itilerow++) {
      b[ibmat + itilerow] = a[jcol];
    }
  }
}

/*
 * File trailer for repmat.c
 *
 * [EOF]
 */
