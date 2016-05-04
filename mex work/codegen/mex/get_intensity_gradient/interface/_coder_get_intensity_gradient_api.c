/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_get_intensity_gradient_api.c
 *
 * Code generation for function '_coder_get_intensity_gradient_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "get_intensity_gradient.h"
#include "_coder_get_intensity_gradient_api.h"
#include "get_intensity_gradient_emxutil.h"
#include "get_intensity_gradient_data.h"

/* Variable Definitions */
static emlrtRTEInfo j_emlrtRTEI = { 1, 1, "_coder_get_intensity_gradient_api",
  "" };

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *bbVol, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *numYpixels,
  const char_T *identifier);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *bbVol, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(bbVol), &thisId, y);
  emlrtDestroyArray(&bbVol);
}

static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv0[3] = { 0, 0, 0 };

  const mxArray *m2;
  y = NULL;
  m2 = emlrtCreateNumericArray(3, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m2, (void *)u->data);
  emlrtSetDimensions((mxArray *)m2, u->size, 3);
  emlrtAssign(&y, m2);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *numYpixels,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(numYpixels), &thisId);
  emlrtDestroyArray(&numYpixels);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv1[4];
  boolean_T bv0[4] = { true, true, true, true };

  static const int32_T dims[4] = { -1, -1, -1, -1 };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 4U, dims, &bv0[0],
    iv1);
  ret->size[0] = iv1[0];
  ret->size[1] = iv1[1];
  ret->size[2] = iv1[2];
  ret->size[3] = iv1[3];
  ret->allocatedSize = ret->size[0] * ret->size[1] * ret->size[2] * ret->size[3];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void get_intensity_gradient_api(const mxArray * const prhs[4], const mxArray
  *plhs[1])
{
  emxArray_real_T *bbVol;
  emxArray_real_T *gradAmplitude;
  real_T numYpixels;
  real_T numXpixels;
  real_T numSlices;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &bbVol, 4, &j_emlrtRTEI, true);
  emxInit_real_T1(&st, &gradAmplitude, 3, &j_emlrtRTEI, true);

  /* Marshall function inputs */
  numYpixels = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "numYpixels");
  numXpixels = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "numXpixels");
  numSlices = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "numSlices");
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "bbVol", bbVol);

  /* Invoke the target function */
  get_intensity_gradient(&st, numYpixels, numXpixels, numSlices, bbVol,
    gradAmplitude);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(gradAmplitude);
  gradAmplitude->canFreeData = false;
  emxFree_real_T(&gradAmplitude);
  bbVol->canFreeData = false;
  emxFree_real_T(&bbVol);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_get_intensity_gradient_api.c) */
