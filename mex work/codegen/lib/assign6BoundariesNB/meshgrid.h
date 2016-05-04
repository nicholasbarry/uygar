/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: meshgrid.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Dec-2015 14:45:42
 */

#ifndef __MESHGRID_H__
#define __MESHGRID_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "assign6BoundariesNB_types.h"

/* Function Declarations */
extern void meshgrid(const emxArray_real_T *x, const double y[26],
                     emxArray_real_T *xx, emxArray_real_T *yy);

#endif

/*
 * File trailer for meshgrid.h
 *
 * [EOF]
 */
