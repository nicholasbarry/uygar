/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_assign6BoundariesNB_api.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Dec-2015 14:45:42
 */

#ifndef ___CODER_ASSIGN6BOUNDARIESNB_API_H__
#define ___CODER_ASSIGN6BOUNDARIESNB_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_assign6BoundariesNB_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef struct_emxArray_uint32_T
#define struct_emxArray_uint32_T

struct emxArray_uint32_T
{
  uint32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint32_T*/

#ifndef typedef_emxArray_uint32_T
#define typedef_emxArray_uint32_T

typedef struct emxArray_uint32_T emxArray_uint32_T;

#endif                                 /*typedef_emxArray_uint32_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void assign6BoundariesNB(emxArray_uint32_T *L, emxArray_real_T *bbVol);
extern void assign6BoundariesNB_api(const mxArray *prhs[2], const mxArray *plhs
  [1]);
extern void assign6BoundariesNB_atexit(void);
extern void assign6BoundariesNB_initialize(void);
extern void assign6BoundariesNB_terminate(void);
extern void assign6BoundariesNB_xil_terminate(void);

#endif

/*
 * File trailer for _coder_assign6BoundariesNB_api.h
 *
 * [EOF]
 */
