/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.h
 *
 * Code generation for function 'repmat'
 *
 */

#ifndef __REPMAT_H__
#define __REPMAT_H__

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
extern void b_repmat(const emlrtStack *sp, const emxArray_real_T *a, const
                     real_T varargin_1[2], emxArray_real_T *b);
extern void c_repmat(const emlrtStack *sp, const real_T a_data[], const int32_T
                     a_size[1], const real_T varargin_1[2], emxArray_real_T *b);
extern void repmat(const real_T a[3], real_T b[78]);

#endif

/* End of code generation (repmat.h) */
