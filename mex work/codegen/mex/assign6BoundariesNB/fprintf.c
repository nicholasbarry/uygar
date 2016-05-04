/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fprintf.c
 *
 * Code generation for function 'fprintf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "assign6BoundariesNB.h"
#include "fprintf.h"

/* Variable Definitions */
static emlrtMCInfo b_emlrtMCI = { 71, 18, "fprintf",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtRSInfo ub_emlrtRSI = { 71, "fprintf",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/iofun/fprintf.m" };

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_feval,
  const char_T *identifier);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location);
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_feval,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(b_feval), &thisId);
  emlrtDestroyArray(&b_feval);
  return y;
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m7;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(sp, 1, &m7, 4, pArrays, "feval", true, location);
}

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

real_T b_fprintf(const emlrtStack *sp, int8_T varargin_1)
{
  int32_T i0;
  static const char_T cv4[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv5[2] = { 1, 7 };

  const mxArray *m3;
  const mxArray *b_y;
  static const char_T formatSpec[54] = { '\\', 'n', 'a', 's', 's', 'i', 'g', 'n',
    '6', 'b', 'o', 'u', 'n', 'd', 'a', 'r', 'i', 'e', 's', ' ', 'c', 'o', 'n',
    'v', 'e', 'r', 'g', 'e', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', '%', 'd',
    ' ', 'i', 't', 'e', 'r', 'a', 't', 'i', 'o', 'n', 's', '.', '\\', 'n', '\\',
    'n' };

  char_T b_u[54];
  const mxArray *c_y;
  static const int32_T iv6[2] = { 1, 54 };

  const mxArray *d_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i0 = 0; i0 < 7; i0++) {
    u[i0] = cv4[i0];
  }

  y = NULL;
  m3 = emlrtCreateCharArray(2, iv5);
  emlrtInitCharArrayR2013a(sp, 7, m3, &u[0]);
  emlrtAssign(&y, m3);
  b_y = NULL;
  m3 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m3);
  for (i0 = 0; i0 < 54; i0++) {
    b_u[i0] = formatSpec[i0];
  }

  c_y = NULL;
  m3 = emlrtCreateCharArray(2, iv6);
  emlrtInitCharArrayR2013a(sp, 54, m3, &b_u[0]);
  emlrtAssign(&c_y, m3);
  d_y = NULL;
  m3 = emlrtCreateNumericMatrix(1, 1, mxINT8_CLASS, mxREAL);
  *(int8_T *)mxGetData(m3) = varargin_1;
  emlrtAssign(&d_y, m3);
  st.site = &ub_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, b_y, c_y, d_y, &b_emlrtMCI),
    "feval");
}

/* End of code generation (fprintf.c) */
