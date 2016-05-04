/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: meshgrid.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Dec-2015 14:45:42
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "assign6BoundariesNB.h"
#include "meshgrid.h"
#include "assign6BoundariesNB_emxutil.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                const double y[26]
 *                emxArray_real_T *xx
 *                emxArray_real_T *yy
 * Return Type  : void
 */
void meshgrid(const emxArray_real_T *x, const double y[26], emxArray_real_T *xx,
              emxArray_real_T *yy)
{
  int ibtile;
  emxArray_real_T *a;
  int outsize_idx_1;
  emxArray_real_T *b;
  int k;
  int varargin_1_idx_1;
  if (x->size[0] == 0) {
    ibtile = xx->size[0] * xx->size[1];
    xx->size[0] = 0;
    xx->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)xx, ibtile, (int)sizeof(double));
    ibtile = yy->size[0] * yy->size[1];
    yy->size[0] = 0;
    yy->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)yy, ibtile, (int)sizeof(double));
  } else {
    emxInit_real_T(&a, 2);
    outsize_idx_1 = x->size[0];
    ibtile = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = outsize_idx_1;
    emxEnsureCapacity((emxArray__common *)a, ibtile, (int)sizeof(double));
    for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
      a->data[a->size[0] * ibtile] = x->data[ibtile];
    }

    emxInit_real_T(&b, 2);
    outsize_idx_1 = a->size[1];
    ibtile = b->size[0] * b->size[1];
    b->size[0] = 26;
    b->size[1] = outsize_idx_1;
    emxEnsureCapacity((emxArray__common *)b, ibtile, (int)sizeof(double));
    for (outsize_idx_1 = 0; outsize_idx_1 + 1 <= a->size[1]; outsize_idx_1++) {
      ibtile = outsize_idx_1 * 26;
      for (k = 0; k < 26; k++) {
        b->data[ibtile + k] = a->data[outsize_idx_1];
      }
    }

    emxFree_real_T(&a);
    ibtile = xx->size[0] * xx->size[1];
    xx->size[0] = 26;
    xx->size[1] = b->size[1];
    emxEnsureCapacity((emxArray__common *)xx, ibtile, (int)sizeof(double));
    outsize_idx_1 = b->size[0] * b->size[1];
    for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
      xx->data[ibtile] = b->data[ibtile];
    }

    varargin_1_idx_1 = x->size[0];
    ibtile = b->size[0] * b->size[1];
    b->size[0] = 26;
    b->size[1] = varargin_1_idx_1;
    emxEnsureCapacity((emxArray__common *)b, ibtile, (int)sizeof(double));
    for (outsize_idx_1 = 1; outsize_idx_1 <= varargin_1_idx_1; outsize_idx_1++)
    {
      ibtile = (outsize_idx_1 - 1) * 26;
      for (k = 0; k < 26; k++) {
        b->data[ibtile + k] = y[k];
      }
    }

    ibtile = yy->size[0] * yy->size[1];
    yy->size[0] = 26;
    yy->size[1] = b->size[1];
    emxEnsureCapacity((emxArray__common *)yy, ibtile, (int)sizeof(double));
    outsize_idx_1 = b->size[0] * b->size[1];
    for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
      yy->data[ibtile] = b->data[ibtile];
    }

    emxFree_real_T(&b);
  }
}

/*
 * File trailer for meshgrid.c
 *
 * [EOF]
 */
