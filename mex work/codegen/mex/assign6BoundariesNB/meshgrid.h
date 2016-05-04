/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * meshgrid.h
 *
 * Code generation for function 'meshgrid'
 *
 */

#ifndef __MESHGRID_H__
#define __MESHGRID_H__

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "assign6BoundariesNB_types.h"

/* Function Declarations */
extern void meshgrid(const emlrtStack *sp, const emxArray_real_T *x, const
                     real_T y[26], emxArray_real_T *xx, emxArray_real_T *yy);

#endif

/* End of code generation (meshgrid.h) */
