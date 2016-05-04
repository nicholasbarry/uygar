/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * indexShapeCheck.h
 *
 * Code generation for function 'indexShapeCheck'
 *
 */

#ifndef __INDEXSHAPECHECK_H__
#define __INDEXSHAPECHECK_H__

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
extern void b_indexShapeCheck(const emlrtStack *sp, const int32_T matrixSize[3],
  int32_T indexSize);
extern void c_indexShapeCheck(const emlrtStack *sp, const int32_T matrixSize[4],
  const int32_T indexSize[2]);
extern void indexShapeCheck(const emlrtStack *sp, int32_T matrixSize, const
  int32_T indexSize[2]);

#endif

/* End of code generation (indexShapeCheck.h) */
