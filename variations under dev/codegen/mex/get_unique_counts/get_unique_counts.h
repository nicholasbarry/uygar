/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_unique_counts.h
 *
 * Code generation for function 'get_unique_counts'
 *
 */

#ifndef __GET_UNIQUE_COUNTS_H__
#define __GET_UNIQUE_COUNTS_H__

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "get_unique_counts_types.h"

/* Function Declarations */
extern void get_unique_counts(const emlrtStack *sp, const emxArray_real_T *a,
  const emxArray_real_T *uniques, emxArray_real_T *counts);

#endif

/* End of code generation (get_unique_counts.h) */
