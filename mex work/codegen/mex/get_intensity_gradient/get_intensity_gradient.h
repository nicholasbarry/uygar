/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_intensity_gradient.h
 *
 * Code generation for function 'get_intensity_gradient'
 *
 */

#ifndef __GET_INTENSITY_GRADIENT_H__
#define __GET_INTENSITY_GRADIENT_H__

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
extern void get_intensity_gradient(const emlrtStack *sp, real_T numYpixels,
  real_T numXpixels, real_T numSlices, const emxArray_real_T *bbVol,
  emxArray_real_T *gradAmplitude);

#endif

/* End of code generation (get_intensity_gradient.h) */
