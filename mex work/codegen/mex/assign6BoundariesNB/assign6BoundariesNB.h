/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assign6BoundariesNB.h
 *
 * Code generation for function 'assign6BoundariesNB'
 *
 */

#ifndef __ASSIGN6BOUNDARIESNB_H__
#define __ASSIGN6BOUNDARIESNB_H__

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
extern void assign6BoundariesNB(const emlrtStack *sp, emxArray_uint32_T *L,
  const emxArray_real_T *bbVol);

#endif

/* End of code generation (assign6BoundariesNB.h) */
