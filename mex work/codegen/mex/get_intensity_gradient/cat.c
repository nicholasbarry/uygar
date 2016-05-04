/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cat.c
 *
 * Code generation for function 'cat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "get_intensity_gradient.h"
#include "cat.h"
#include "error.h"
#include "get_intensity_gradient_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_intensity_gradient_data.h"

/* Variable Definitions */
static emlrtRSInfo g_emlrtRSI = { 36, "cat",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/cat.m" };

static emlrtRSInfo h_emlrtRSI = { 52, "cat",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/cat.m" };

static emlrtRSInfo i_emlrtRSI = { 57, "cat",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/cat.m" };

static emlrtRSInfo j_emlrtRSI = { 65, "cat",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/cat.m" };

static emlrtRTEInfo f_emlrtRTEI = { 1, 14, "cat",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/cat.m" };

static emlrtRTEInfo m_emlrtRTEI = { 38, 23, "cat",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/cat.m" };

/* Function Definitions */
void b_cat(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
           emxArray_real_T *varargin_2, emxArray_real_T *y)
{
  uint32_T sz1[4];
  int32_T k;
  uint32_T ysize[4];
  int32_T exitg3;
  boolean_T overflow;
  int32_T exitg2;
  int32_T vstride;
  int32_T npages;
  boolean_T exitg1;
  int32_T b_ysize[4];
  int32_T iy;
  int32_T c_ysize[4];
  int32_T i;
  int32_T istart;
  boolean_T b10;
  int32_T ix;
  int32_T l;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (k = 0; k < 4; k++) {
    sz1[k] = (uint32_T)varargin_1->size[k];
  }

  for (k = 0; k < 4; k++) {
    ysize[k] = sz1[k];
  }

  ysize[1] += varargin_2->size[1];
  k = y->size[0] * y->size[1] * y->size[2] * y->size[3];
  y->size[0] = (int32_T)ysize[0];
  y->size[1] = (int32_T)ysize[1];
  y->size[2] = (int32_T)ysize[2];
  y->size[3] = (int32_T)ysize[3];
  emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                    &f_emlrtRTEI);
  if ((varargin_1->size[0] == 0) || (varargin_1->size[2] == 0) ||
      (varargin_1->size[3] == 0)) {
    st.site = &g_emlrtRSI;
    error(&st);
  }

  k = 0;
  do {
    exitg3 = 0;
    if (k < 4) {
      if ((!(2 == 1 + k)) && (y->size[k] != varargin_1->size[k])) {
        overflow = false;
        exitg3 = 1;
      } else {
        k++;
      }
    } else {
      overflow = true;
      exitg3 = 1;
    }
  } while (exitg3 == 0);

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &m_emlrtRTEI,
      "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }

  if ((varargin_2->size[0] == 0) || (varargin_2->size[1] == 0) ||
      (varargin_2->size[2] == 0) || (varargin_2->size[3] == 0)) {
    st.site = &g_emlrtRSI;
    error(&st);
  }

  k = 0;
  do {
    exitg2 = 0;
    if (k < 4) {
      if ((!(2 == 1 + k)) && (y->size[k] != varargin_2->size[k])) {
        overflow = false;
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      overflow = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &m_emlrtRTEI,
      "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }

  for (k = 0; k < 4; k++) {
    ysize[k] = (uint32_T)y->size[k];
  }

  vstride = (int32_T)ysize[0];
  for (k = 0; k < 4; k++) {
    ysize[k] = (uint32_T)y->size[k];
  }

  npages = 1;
  k = 4;
  exitg1 = false;
  while ((!exitg1) && (k > 2)) {
    b_ysize[0] = (int32_T)ysize[0];
    b_ysize[1] = (int32_T)ysize[1];
    b_ysize[2] = (int32_T)ysize[2];
    b_ysize[3] = (int32_T)ysize[3];
    if (b_ysize[k - 1] == 1) {
      k--;
    } else {
      exitg1 = true;
    }
  }

  for (iy = 3; iy <= k; iy++) {
    c_ysize[0] = (int32_T)ysize[0];
    c_ysize[1] = (int32_T)ysize[1];
    c_ysize[2] = (int32_T)ysize[2];
    c_ysize[3] = (int32_T)ysize[3];
    npages *= c_ysize[iy - 1];
  }

  iy = 0;
  for (i = 0; i < npages; i++) {
    istart = iy;
    st.site = &i_emlrtRSI;
    if (1 > vstride) {
      b10 = false;
    } else {
      b10 = (vstride > 2147483646);
    }

    if (b10) {
      b_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (k = 1; k <= vstride; k++) {
      istart++;
      y->data[istart - 1] = varargin_1->data[(k + i * vstride) - 1];
      iy = istart + vstride;
      ix = k + i * (vstride * varargin_2->size[1]);
      st.site = &j_emlrtRSI;
      overflow = (varargin_2->size[1] > 2147483646);
      if (overflow) {
        b_st.site = &l_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (l = 1; l <= varargin_2->size[1]; l++) {
        y->data[iy - 1] = varargin_2->data[ix - 1];
        ix += vstride;
        iy += vstride;
      }
    }

    iy -= vstride;
  }
}

void c_cat(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
           emxArray_real_T *varargin_2, emxArray_real_T *y)
{
  uint32_T sz1[4];
  int32_T k;
  uint32_T ysize[4];
  int32_T exitg5;
  boolean_T overflow;
  int32_T exitg4;
  boolean_T exitg3;
  int32_T b_ysize[4];
  int32_T vstride;
  int32_T c_ysize[4];
  boolean_T exitg2;
  int32_T d_ysize[4];
  int32_T npages;
  boolean_T exitg1;
  int32_T e_ysize[4];
  int32_T iy;
  int32_T i;
  int32_T istart;
  boolean_T b13;
  int32_T ix;
  int32_T l;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (k = 0; k < 4; k++) {
    sz1[k] = (uint32_T)varargin_1->size[k];
  }

  for (k = 0; k < 4; k++) {
    ysize[k] = sz1[k];
  }

  ysize[2] += varargin_2->size[2];
  k = y->size[0] * y->size[1] * y->size[2] * y->size[3];
  y->size[0] = (int32_T)ysize[0];
  y->size[1] = (int32_T)ysize[1];
  y->size[2] = (int32_T)ysize[2];
  y->size[3] = (int32_T)ysize[3];
  emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                    &f_emlrtRTEI);
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0) ||
      (varargin_1->size[3] == 0)) {
    st.site = &g_emlrtRSI;
    error(&st);
  }

  k = 0;
  do {
    exitg5 = 0;
    if (k < 4) {
      if ((!(3 == 1 + k)) && (y->size[k] != varargin_1->size[k])) {
        overflow = false;
        exitg5 = 1;
      } else {
        k++;
      }
    } else {
      overflow = true;
      exitg5 = 1;
    }
  } while (exitg5 == 0);

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &m_emlrtRTEI,
      "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }

  if ((varargin_2->size[0] == 0) || (varargin_2->size[1] == 0) ||
      (varargin_2->size[2] == 0) || (varargin_2->size[3] == 0)) {
    st.site = &g_emlrtRSI;
    error(&st);
  }

  k = 0;
  do {
    exitg4 = 0;
    if (k < 4) {
      if ((!(3 == 1 + k)) && (y->size[k] != varargin_2->size[k])) {
        overflow = false;
        exitg4 = 1;
      } else {
        k++;
      }
    } else {
      overflow = true;
      exitg4 = 1;
    }
  } while (exitg4 == 0);

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &m_emlrtRTEI,
      "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }

  for (k = 0; k < 4; k++) {
    ysize[k] = (uint32_T)y->size[k];
  }

  k = 4;
  exitg3 = false;
  while ((!exitg3) && (k > 2)) {
    b_ysize[0] = (int32_T)ysize[0];
    b_ysize[1] = (int32_T)ysize[1];
    b_ysize[2] = (int32_T)ysize[2];
    b_ysize[3] = (int32_T)ysize[3];
    if (b_ysize[k - 1] == 1) {
      k--;
    } else {
      exitg3 = true;
    }
  }

  if (3 > k) {
    vstride = (int32_T)ysize[0] * (int32_T)ysize[1] * (int32_T)ysize[2] *
      (int32_T)ysize[3];
  } else {
    vstride = 1;
    for (k = 0; k < 2; k++) {
      c_ysize[0] = (int32_T)ysize[0];
      c_ysize[1] = (int32_T)ysize[1];
      c_ysize[2] = (int32_T)ysize[2];
      c_ysize[3] = (int32_T)ysize[3];
      vstride *= c_ysize[k];
    }
  }

  for (k = 0; k < 4; k++) {
    ysize[k] = (uint32_T)y->size[k];
  }

  k = 4;
  exitg2 = false;
  while ((!exitg2) && (k > 2)) {
    d_ysize[0] = (int32_T)ysize[0];
    d_ysize[1] = (int32_T)ysize[1];
    d_ysize[2] = (int32_T)ysize[2];
    d_ysize[3] = (int32_T)ysize[3];
    if (d_ysize[k - 1] == 1) {
      k--;
    } else {
      exitg2 = true;
    }
  }

  if (3 > k) {
    npages = 1;
  } else {
    npages = 1;
    k = 4;
    exitg1 = false;
    while ((!exitg1) && (k > 2)) {
      e_ysize[0] = (int32_T)ysize[0];
      e_ysize[1] = (int32_T)ysize[1];
      e_ysize[2] = (int32_T)ysize[2];
      e_ysize[3] = (int32_T)ysize[3];
      if (e_ysize[k - 1] == 1) {
        k--;
      } else {
        exitg1 = true;
      }
    }

    iy = 4;
    while (iy <= k) {
      npages *= (int32_T)ysize[3];
      iy = 5;
    }
  }

  iy = 0;
  for (i = 0; i < npages; i++) {
    istart = iy;
    st.site = &i_emlrtRSI;
    if (1 > vstride) {
      b13 = false;
    } else {
      b13 = (vstride > 2147483646);
    }

    if (b13) {
      b_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (k = 1; k <= vstride; k++) {
      istart++;
      y->data[istart - 1] = varargin_1->data[(k + i * vstride) - 1];
      iy = istart + vstride;
      ix = k + i * (vstride * varargin_2->size[2]);
      st.site = &j_emlrtRSI;
      overflow = (varargin_2->size[2] > 2147483646);
      if (overflow) {
        b_st.site = &l_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (l = 1; l <= varargin_2->size[2]; l++) {
        y->data[iy - 1] = varargin_2->data[ix - 1];
        ix += vstride;
        iy += vstride;
      }
    }

    iy -= vstride;
  }
}

void cat(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
         emxArray_real_T *varargin_2, emxArray_real_T *y)
{
  uint32_T sz1[4];
  int32_T k;
  uint32_T ysize[4];
  int32_T exitg3;
  boolean_T overflow;
  int32_T exitg2;
  int32_T npages;
  boolean_T exitg1;
  int32_T b_ysize[4];
  int32_T b_k;
  int32_T c_ysize[4];
  int32_T ix;
  int32_T l;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (k = 0; k < 4; k++) {
    sz1[k] = (uint32_T)varargin_1->size[k];
  }

  for (k = 0; k < 4; k++) {
    ysize[k] = sz1[k];
  }

  ysize[0] += varargin_2->size[0];
  k = y->size[0] * y->size[1] * y->size[2] * y->size[3];
  y->size[0] = (int32_T)ysize[0];
  y->size[1] = (int32_T)ysize[1];
  y->size[2] = (int32_T)ysize[2];
  y->size[3] = (int32_T)ysize[3];
  emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                    &f_emlrtRTEI);
  if ((varargin_1->size[1] == 0) || (varargin_1->size[2] == 0) ||
      (varargin_1->size[3] == 0)) {
    st.site = &g_emlrtRSI;
    error(&st);
  }

  k = 0;
  do {
    exitg3 = 0;
    if (k < 4) {
      if ((!(1 == 1 + k)) && (y->size[k] != varargin_1->size[k])) {
        overflow = false;
        exitg3 = 1;
      } else {
        k++;
      }
    } else {
      overflow = true;
      exitg3 = 1;
    }
  } while (exitg3 == 0);

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &m_emlrtRTEI,
      "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }

  if ((varargin_2->size[0] == 0) || (varargin_2->size[1] == 0) ||
      (varargin_2->size[2] == 0) || (varargin_2->size[3] == 0)) {
    st.site = &g_emlrtRSI;
    error(&st);
  }

  k = 0;
  do {
    exitg2 = 0;
    if (k < 4) {
      if ((!(1 == 1 + k)) && (y->size[k] != varargin_2->size[k])) {
        overflow = false;
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      overflow = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &m_emlrtRTEI,
      "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }

  for (k = 0; k < 4; k++) {
    ysize[k] = (uint32_T)y->size[k];
  }

  st.site = &h_emlrtRSI;
  npages = 1;
  k = 4;
  exitg1 = false;
  while ((!exitg1) && (k > 2)) {
    b_ysize[0] = (int32_T)ysize[0];
    b_ysize[1] = (int32_T)ysize[1];
    b_ysize[2] = (int32_T)ysize[2];
    b_ysize[3] = (int32_T)ysize[3];
    if (b_ysize[k - 1] == 1) {
      k--;
    } else {
      exitg1 = true;
    }
  }

  for (b_k = 2; b_k <= k; b_k++) {
    c_ysize[0] = (int32_T)ysize[0];
    c_ysize[1] = (int32_T)ysize[1];
    c_ysize[2] = (int32_T)ysize[2];
    c_ysize[3] = (int32_T)ysize[3];
    npages *= c_ysize[b_k - 1];
  }

  k = 0;
  for (b_k = 0; b_k < npages; b_k++) {
    st.site = &i_emlrtRSI;
    y->data[k] = varargin_1->data[b_k];
    k++;
    ix = b_k * varargin_2->size[0];
    st.site = &j_emlrtRSI;
    overflow = (varargin_2->size[0] > 2147483646);
    if (overflow) {
      b_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (l = 1; l <= varargin_2->size[0]; l++) {
      y->data[k] = varargin_2->data[ix];
      ix++;
      k++;
    }
  }
}

/* End of code generation (cat.c) */
