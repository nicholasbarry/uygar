/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_assign6BoundariesNB_api.c
 *
 * Code generation for function '_coder_assign6BoundariesNB_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "assign6BoundariesNB.h"
#include "_coder_assign6BoundariesNB_api.h"
#include "assign6BoundariesNB_emxutil.h"
#include "assign6BoundariesNB_data.h"

/* Variable Definitions */
static emlrtRTEInfo e_emlrtRTEI = { 1, 1, "_coder_assign6BoundariesNB_api", "" };

/* Function Declarations */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *L, const
  char_T *identifier, emxArray_uint32_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_uint32_T *y);
static void d_emlrt_marshallOut(const emxArray_uint32_T *u, const mxArray *y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *bbVol, const
  char_T *identifier, emxArray_real_T *y);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_uint32_T *ret);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *L, const
  char_T *identifier, emxArray_uint32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(L), &thisId, y);
  emlrtDestroyArray(&L);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_uint32_T *y)
{
  h_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void d_emlrt_marshallOut(const emxArray_uint32_T *u, const mxArray *y)
{
  mxSetData((mxArray *)y, (void *)u->data);
  emlrtSetDimensions((mxArray *)y, u->size, 3);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *bbVol, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(bbVol), &thisId, y);
  emlrtDestroyArray(&bbVol);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_uint32_T *ret)
{
  int32_T iv7[3];
  boolean_T bv0[3] = { true, true, true };

  static const int32_T dims[3] = { -1, -1, -1 };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "uint32", false, 3U, dims, &bv0[0],
    iv7);
  ret->size[0] = iv7[0];
  ret->size[1] = iv7[1];
  ret->size[2] = iv7[2];
  ret->allocatedSize = ret->size[0] * ret->size[1] * ret->size[2];
  ret->data = (uint32_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv8[4];
  boolean_T bv1[4] = { true, true, true, true };

  static const int32_T dims[4] = { -1, -1, -1, -1 };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 4U, dims, &bv1[0],
    iv8);
  ret->size[0] = iv8[0];
  ret->size[1] = iv8[1];
  ret->size[2] = iv8[2];
  ret->size[3] = iv8[3];
  ret->allocatedSize = ret->size[0] * ret->size[1] * ret->size[2] * ret->size[3];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void assign6BoundariesNB_api(const mxArray *prhs[2], const mxArray *plhs[1])
{
  emxArray_uint32_T *L;
  emxArray_real_T *bbVol;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_uint32_T(&st, &L, 3, &e_emlrtRTEI, true);
  emxInit_real_T1(&st, &bbVol, 4, &e_emlrtRTEI, true);
  prhs[0] = emlrtProtectR2012b(prhs[0], 0, true, -1);

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "L", L);
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "bbVol", bbVol);

  /* Invoke the target function */
  assign6BoundariesNB(&st, L, bbVol);

  /* Marshall function outputs */
  d_emlrt_marshallOut(L, prhs[0]);
  plhs[0] = prhs[0];
  bbVol->canFreeData = false;
  emxFree_real_T(&bbVol);
  L->canFreeData = false;
  emxFree_uint32_T(&L);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_assign6BoundariesNB_api.c) */
