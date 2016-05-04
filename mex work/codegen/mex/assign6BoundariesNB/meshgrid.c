/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * meshgrid.c
 *
 * Code generation for function 'meshgrid'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "assign6BoundariesNB.h"
#include "meshgrid.h"
#include "assign6BoundariesNB_emxutil.h"
#include "repmat.h"
#include "eml_int_forloop_overflow_check.h"
#include "assertValidSizeArg.h"
#include "assign6BoundariesNB_mexutil.h"
#include "assign6BoundariesNB_data.h"

/* Variable Definitions */
static emlrtRSInfo s_emlrtRSI = { 17, "meshgrid",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/meshgrid.m"
};

static emlrtRSInfo t_emlrtRSI = { 18, "meshgrid",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/meshgrid.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 1, 23, "meshgrid",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/meshgrid.m"
};

/* Function Definitions */
void meshgrid(const emlrtStack *sp, const emxArray_real_T *x, const real_T y[26],
              emxArray_real_T *xx, emxArray_real_T *yy)
{
  int32_T ibtile;
  emxArray_real_T *a;
  int32_T outsize_idx_1;
  static const char_T cv1[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
    'a', 'x', 's', 'i', 'z', 'e' };

  char_T u[15];
  const mxArray *b_y;
  static const int32_T iv0[2] = { 1, 15 };

  const mxArray *m0;
  emxArray_real_T *b;
  boolean_T overflow;
  int32_T k;
  real_T varargin_1[2];
  char_T b_u[15];
  const mxArray *c_y;
  static const int32_T iv1[2] = { 1, 15 };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (x->size[0] == 0) {
    ibtile = xx->size[0] * xx->size[1];
    xx->size[0] = 0;
    xx->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)xx, ibtile, (int32_T)sizeof(real_T),
                      &c_emlrtRTEI);
    ibtile = yy->size[0] * yy->size[1];
    yy->size[0] = 0;
    yy->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)yy, ibtile, (int32_T)sizeof(real_T),
                      &c_emlrtRTEI);
  } else {
    emxInit_real_T(sp, &a, 2, &c_emlrtRTEI, true);
    st.site = &s_emlrtRSI;
    outsize_idx_1 = x->size[0];
    ibtile = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = outsize_idx_1;
    emxEnsureCapacity(&st, (emxArray__common *)a, ibtile, (int32_T)sizeof(real_T),
                      &c_emlrtRTEI);
    for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
      a->data[a->size[0] * ibtile] = x->data[ibtile];
    }

    outsize_idx_1 = a->size[1];
    if (outsize_idx_1 == a->size[1]) {
    } else {
      for (ibtile = 0; ibtile < 15; ibtile++) {
        u[ibtile] = cv1[ibtile];
      }

      b_y = NULL;
      m0 = emlrtCreateCharArray(2, iv0);
      emlrtInitCharArrayR2013a(&st, 15, m0, &u[0]);
      emlrtAssign(&b_y, m0);
      b_st.site = &tb_emlrtRSI;
      error(&b_st, b_y, &emlrtMCI);
    }

    emxInit_real_T(&st, &b, 2, &c_emlrtRTEI, true);
    ibtile = b->size[0] * b->size[1];
    b->size[0] = 26;
    b->size[1] = outsize_idx_1;
    emxEnsureCapacity(&st, (emxArray__common *)b, ibtile, (int32_T)sizeof(real_T),
                      &c_emlrtRTEI);
    b_st.site = &u_emlrtRSI;
    overflow = (a->size[1] > 2147483646);
    if (overflow) {
      c_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (outsize_idx_1 = 0; outsize_idx_1 + 1 <= a->size[1]; outsize_idx_1++) {
      ibtile = outsize_idx_1 * 26;
      for (k = 0; k < 26; k++) {
        b->data[ibtile + k] = a->data[outsize_idx_1];
      }
    }

    emxFree_real_T(&a);
    ibtile = xx->size[0] * xx->size[1];
    xx->size[0] = 26;
    xx->size[1] = b->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)xx, ibtile, (int32_T)sizeof(real_T),
                      &c_emlrtRTEI);
    outsize_idx_1 = b->size[0] * b->size[1];
    for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
      xx->data[ibtile] = b->data[ibtile];
    }

    st.site = &t_emlrtRSI;
    varargin_1[0] = 1.0;
    varargin_1[1] = x->size[0];
    b_st.site = &v_emlrtRSI;
    assertValidSizeArg(&b_st, varargin_1);
    if (varargin_1[1] == varargin_1[1]) {
    } else {
      for (ibtile = 0; ibtile < 15; ibtile++) {
        b_u[ibtile] = cv1[ibtile];
      }

      c_y = NULL;
      m0 = emlrtCreateCharArray(2, iv1);
      emlrtInitCharArrayR2013a(&st, 15, m0, &b_u[0]);
      emlrtAssign(&c_y, m0);
      b_st.site = &tb_emlrtRSI;
      error(&b_st, c_y, &emlrtMCI);
    }

    ibtile = b->size[0] * b->size[1];
    b->size[0] = 26;
    b->size[1] = (int32_T)varargin_1[1];
    emxEnsureCapacity(&st, (emxArray__common *)b, ibtile, (int32_T)sizeof(real_T),
                      &c_emlrtRTEI);
    b_st.site = &w_emlrtRSI;
    if (varargin_1[1] > 2.147483646E+9) {
      c_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (outsize_idx_1 = 1; outsize_idx_1 <= (int32_T)varargin_1[1];
         outsize_idx_1++) {
      ibtile = (outsize_idx_1 - 1) * 26;
      b_st.site = &x_emlrtRSI;
      for (k = 0; k < 26; k++) {
        b->data[ibtile + k] = y[k];
      }
    }

    ibtile = yy->size[0] * yy->size[1];
    yy->size[0] = 26;
    yy->size[1] = b->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)yy, ibtile, (int32_T)sizeof(real_T),
                      &c_emlrtRTEI);
    outsize_idx_1 = b->size[0] * b->size[1];
    for (ibtile = 0; ibtile < outsize_idx_1; ibtile++) {
      yy->data[ibtile] = b->data[ibtile];
    }

    emxFree_real_T(&b);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (meshgrid.c) */
