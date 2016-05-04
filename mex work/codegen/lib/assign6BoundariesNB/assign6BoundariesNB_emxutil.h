/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: assign6BoundariesNB_emxutil.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Dec-2015 14:45:42
 */

#ifndef __ASSIGN6BOUNDARIESNB_EMXUTIL_H__
#define __ASSIGN6BOUNDARIESNB_EMXUTIL_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "assign6BoundariesNB_types.h"

/* Function Declarations */
extern void emxEnsureCapacity(emxArray__common *emxArray, int oldNumel, int
  elementSize);
extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxFree_uint32_T(emxArray_uint32_T **pEmxArray);
extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int numDimensions);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_real_T1(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_real_T2(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_uint32_T(emxArray_uint32_T **pEmxArray, int numDimensions);

#endif

/*
 * File trailer for assign6BoundariesNB_emxutil.h
 *
 * [EOF]
 */
