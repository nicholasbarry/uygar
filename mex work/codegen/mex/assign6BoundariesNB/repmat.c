/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "assign6BoundariesNB.h"
#include "repmat.h"
#include "assign6BoundariesNB_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "assertValidSizeArg.h"
#include "assign6BoundariesNB_mexutil.h"
#include "assign6BoundariesNB_data.h"

/* Variable Definitions */
static emlrtRSInfo hb_emlrtRSI = { 119, "repmat",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };

static emlrtRTEInfo d_emlrtRTEI = { 1, 14, "repmat",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };

/* Function Definitions */
void b_repmat(const emlrtStack *sp, const emxArray_real_T *a, const real_T
              varargin_1[2], emxArray_real_T *b)
{
  int32_T ncols;
  static const char_T cv2[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
    'a', 'x', 's', 'i', 'z', 'e' };

  char_T u[15];
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 15 };

  const mxArray *m1;
  int32_T outsize_idx_1;
  char_T b_u[15];
  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 15 };

  int32_T jcol;
  int32_T ibmat;
  int32_T itilerow;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &v_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  assertValidSizeArg(&st, varargin_1);
  if ((int8_T)(int32_T)varargin_1[0] == (int32_T)varargin_1[0]) {
  } else {
    for (ncols = 0; ncols < 15; ncols++) {
      u[ncols] = cv2[ncols];
    }

    y = NULL;
    m1 = emlrtCreateCharArray(2, iv2);
    emlrtInitCharArrayR2013a(sp, 15, m1, &u[0]);
    emlrtAssign(&y, m1);
    st.site = &tb_emlrtRSI;
    error(&st, y, &emlrtMCI);
  }

  outsize_idx_1 = a->size[1];
  if (outsize_idx_1 == a->size[1]) {
  } else {
    for (ncols = 0; ncols < 15; ncols++) {
      b_u[ncols] = cv2[ncols];
    }

    b_y = NULL;
    m1 = emlrtCreateCharArray(2, iv3);
    emlrtInitCharArrayR2013a(sp, 15, m1, &b_u[0]);
    emlrtAssign(&b_y, m1);
    st.site = &tb_emlrtRSI;
    error(&st, b_y, &emlrtMCI);
  }

  ncols = b->size[0] * b->size[1];
  b->size[0] = (int32_T)varargin_1[0];
  b->size[1] = outsize_idx_1;
  emxEnsureCapacity(sp, (emxArray__common *)b, ncols, (int32_T)sizeof(real_T),
                    &d_emlrtRTEI);
  if ((!(a->size[1] == 0)) && (!(outsize_idx_1 == 0))) {
    ncols = a->size[1];
    outsize_idx_1 = (int32_T)varargin_1[0];
    st.site = &w_emlrtRSI;
    st.site = &u_emlrtRSI;
    if (ncols > 2147483646) {
      b_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (jcol = 0; jcol + 1 <= ncols; jcol++) {
      ibmat = jcol * outsize_idx_1;
      st.site = &x_emlrtRSI;
      for (itilerow = 1; itilerow <= outsize_idx_1; itilerow++) {
        b->data[(ibmat + itilerow) - 1] = a->data[jcol];
      }
    }
  }
}

void c_repmat(const emlrtStack *sp, const real_T a_data[], const int32_T a_size
              [1], const real_T varargin_1[2], emxArray_real_T *b)
{
  int32_T nrows;
  static const char_T cv3[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
    'a', 'x', 's', 'i', 'z', 'e' };

  char_T u[15];
  const mxArray *y;
  static const int32_T iv4[2] = { 1, 15 };

  const mxArray *m2;
  boolean_T overflow;
  int32_T jtilecol;
  int32_T ibtile;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &v_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  assertValidSizeArg(&st, varargin_1);
  if ((int8_T)a_size[0] == a_size[0]) {
  } else {
    for (nrows = 0; nrows < 15; nrows++) {
      u[nrows] = cv3[nrows];
    }

    y = NULL;
    m2 = emlrtCreateCharArray(2, iv4);
    emlrtInitCharArrayR2013a(sp, 15, m2, &u[0]);
    emlrtAssign(&y, m2);
    st.site = &tb_emlrtRSI;
    error(&st, y, &emlrtMCI);
  }

  nrows = b->size[0] * b->size[1];
  b->size[0] = a_size[0];
  b->size[1] = (int32_T)varargin_1[1];
  emxEnsureCapacity(sp, (emxArray__common *)b, nrows, (int32_T)sizeof(real_T),
                    &d_emlrtRTEI);
  if (!((int32_T)varargin_1[1] == 0)) {
    nrows = a_size[0];
    st.site = &w_emlrtRSI;
    if (1 > (int32_T)varargin_1[1]) {
      overflow = false;
    } else {
      overflow = ((int32_T)varargin_1[1] > 2147483646);
    }

    if (overflow) {
      b_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (jtilecol = 1; jtilecol <= (int32_T)varargin_1[1]; jtilecol++) {
      ibtile = (jtilecol - 1) * nrows;
      st.site = &x_emlrtRSI;
      st.site = &hb_emlrtRSI;
      for (k = 1; k <= nrows; k++) {
        b->data[(ibtile + k) - 1] = a_data[k - 1];
      }
    }
  }
}

void repmat(const real_T a[3], real_T b[78])
{
  int32_T jcol;
  int32_T ibmat;
  int32_T itilerow;
  for (jcol = 0; jcol < 3; jcol++) {
    ibmat = jcol * 26;
    for (itilerow = 0; itilerow < 26; itilerow++) {
      b[ibmat + itilerow] = a[jcol];
    }
  }
}

/* End of code generation (repmat.c) */
