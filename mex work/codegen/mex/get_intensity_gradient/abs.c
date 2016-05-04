/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "get_intensity_gradient.h"
#include "abs.h"
#include "get_intensity_gradient_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_intensity_gradient_data.h"

/* Variable Definitions */
static emlrtRSInfo q_emlrtRSI = { 16, "abs",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elfun/abs.m" };

static emlrtRSInfo r_emlrtRSI = { 67, "applyScalarFunction",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 1, 14, "abs",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elfun/abs.m" };

/* Function Definitions */
void b_abs(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  uint32_T uv0[4];
  int32_T n;
  boolean_T b7;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &q_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  for (n = 0; n < 4; n++) {
    uv0[n] = (uint32_T)x->size[n];
  }

  n = y->size[0] * y->size[1] * y->size[2] * y->size[3];
  y->size[0] = (int32_T)uv0[0];
  y->size[1] = (int32_T)uv0[1];
  y->size[2] = (int32_T)uv0[2];
  y->size[3] = (int32_T)uv0[3];
  emxEnsureCapacity(&st, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  n = x->size[0] * x->size[1] * x->size[2] * x->size[3];
  b_st.site = &r_emlrtRSI;
  if (1 > n) {
    b7 = false;
  } else {
    b7 = (n > 2147483646);
  }

  if (b7) {
    c_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k + 1 <= n; k++) {
    y->data[k] = muDoubleScalarAbs(x->data[k]);
  }
}

/* End of code generation (abs.c) */
