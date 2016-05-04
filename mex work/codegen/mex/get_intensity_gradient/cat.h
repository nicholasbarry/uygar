/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cat.h
 *
 * Code generation for function 'cat'
 *
 */

#ifndef __CAT_H__
#define __CAT_H__

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
#include "get_intensity_gradient_types.h"

/* Function Declarations */
extern void b_cat(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
                  emxArray_real_T *varargin_2, emxArray_real_T *y);
extern void c_cat(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
                  emxArray_real_T *varargin_2, emxArray_real_T *y);
extern void cat(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
                emxArray_real_T *varargin_2, emxArray_real_T *y);

#endif

/* End of code generation (cat.h) */
