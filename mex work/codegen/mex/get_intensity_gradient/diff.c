/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diff.c
 *
 * Code generation for function 'diff'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "get_intensity_gradient.h"
#include "diff.h"
#include "get_intensity_gradient_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_intensity_gradient_data.h"

/* Variable Definitions */
static emlrtRSInfo m_emlrtRSI = { 81, "diff",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/diff.m" };

static emlrtRSInfo n_emlrtRSI = { 87, "diff",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/diff.m" };

static emlrtRSInfo o_emlrtRSI = { 90, "diff",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/diff.m" };

static emlrtRSInfo p_emlrtRSI = { 106, "diff",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/diff.m" };

static emlrtRTEInfo g_emlrtRTEI = { 1, 14, "diff",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/diff.m" };

/* Function Definitions */
void b_diff(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T dimSize;
  uint32_T ySize[4];
  int32_T k;
  int32_T stride;
  int32_T nHigh;
  int32_T yNext;
  int32_T ixStart;
  int32_T iyStart;
  boolean_T b11;
  int32_T r;
  int32_T ix;
  int32_T iy;
  boolean_T b12;
  int32_T s;
  int32_T ixLead;
  int32_T iyLead;
  real_T work;
  int32_T m;
  real_T tmp2;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  dimSize = x->size[1];
  if (x->size[1] <= 1) {
    for (k = 0; k < 4; k++) {
      ySize[k] = (uint32_T)x->size[k];
    }

    k = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = (int32_T)ySize[0];
    y->size[1] = 0;
    y->size[2] = (int32_T)ySize[2];
    y->size[3] = (int32_T)ySize[3];
    emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                      &g_emlrtRTEI);
  } else {
    for (k = 0; k < 4; k++) {
      ySize[k] = (uint32_T)x->size[k];
    }

    ySize[1] = (uint32_T)(x->size[1] - 1);
    k = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = (int32_T)ySize[0];
    y->size[1] = (int32_T)ySize[1];
    y->size[2] = (int32_T)ySize[2];
    y->size[3] = (int32_T)ySize[3];
    emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                      &g_emlrtRTEI);
    if (!((y->size[0] == 0) || (y->size[2] == 0) || (y->size[3] == 0))) {
      stride = x->size[0];
      nHigh = 1;
      k = 4;
      while ((k > 2) && (x->size[k - 1] == 1)) {
        k--;
      }

      for (yNext = 3; yNext <= k; yNext++) {
        nHigh *= x->size[yNext - 1];
      }

      k = x->size[0] * x->size[1];
      yNext = x->size[0] * (x->size[1] - 1);
      ixStart = 1;
      iyStart = 1;
      st.site = &n_emlrtRSI;
      if (1 > nHigh) {
        b11 = false;
      } else {
        b11 = (nHigh > 2147483646);
      }

      if (b11) {
        b_st.site = &l_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (r = 1; r <= nHigh; r++) {
        ix = ixStart - 1;
        iy = iyStart - 1;
        st.site = &o_emlrtRSI;
        if (1 > stride) {
          b12 = false;
        } else {
          b12 = (stride > 2147483646);
        }

        if (b12) {
          b_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (s = 1; s <= stride; s++) {
          ixLead = ix + stride;
          iyLead = iy;
          work = x->data[ix];
          st.site = &p_emlrtRSI;
          if (dimSize > 2147483646) {
            b_st.site = &l_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          for (m = 2; m <= dimSize; m++) {
            tmp2 = work;
            work = x->data[ixLead];
            tmp2 = x->data[ixLead] - tmp2;
            ixLead += stride;
            y->data[iyLead] = tmp2;
            iyLead += stride;
          }

          ix++;
          iy++;
        }

        ixStart += k;
        iyStart += yNext;
      }
    }
  }
}

void c_diff(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T dimSize;
  uint32_T ySize[4];
  int32_T k;
  int32_T stride;
  int32_T nHigh;
  int32_T yNext;
  int32_T ixStart;
  int32_T iyStart;
  boolean_T b14;
  int32_T r;
  int32_T ix;
  int32_T iy;
  boolean_T b15;
  int32_T s;
  int32_T ixLead;
  int32_T iyLead;
  real_T work;
  int32_T m;
  real_T tmp2;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  dimSize = x->size[2];
  if (x->size[2] <= 1) {
    for (k = 0; k < 4; k++) {
      ySize[k] = (uint32_T)x->size[k];
    }

    k = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = (int32_T)ySize[0];
    y->size[1] = (int32_T)ySize[1];
    y->size[2] = 0;
    y->size[3] = (int32_T)ySize[3];
    emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                      &g_emlrtRTEI);
  } else {
    for (k = 0; k < 4; k++) {
      ySize[k] = (uint32_T)x->size[k];
    }

    ySize[2] = (uint32_T)(x->size[2] - 1);
    k = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = (int32_T)ySize[0];
    y->size[1] = (int32_T)ySize[1];
    y->size[2] = (int32_T)ySize[2];
    y->size[3] = (int32_T)ySize[3];
    emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                      &g_emlrtRTEI);
    if (!((y->size[0] == 0) || (y->size[1] == 0) || (y->size[3] == 0))) {
      k = 4;
      while ((k > 2) && (x->size[k - 1] == 1)) {
        k--;
      }

      if (3 > k) {
        stride = x->size[0] * x->size[1] * x->size[2] * x->size[3];
      } else {
        stride = 1;
        for (k = 0; k < 2; k++) {
          stride *= x->size[k];
        }
      }

      k = 4;
      while ((k > 2) && (x->size[k - 1] == 1)) {
        k--;
      }

      if (3 > k) {
        nHigh = 1;
      } else {
        nHigh = 1;
        k = 4;
        while ((k > 2) && (x->size[k - 1] == 1)) {
          k--;
        }

        yNext = 4;
        while (yNext <= k) {
          nHigh *= x->size[3];
          yNext = 5;
        }
      }

      k = stride * x->size[2];
      yNext = stride * (x->size[2] - 1);
      ixStart = 1;
      iyStart = 1;
      st.site = &n_emlrtRSI;
      if (1 > nHigh) {
        b14 = false;
      } else {
        b14 = (nHigh > 2147483646);
      }

      if (b14) {
        b_st.site = &l_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (r = 1; r <= nHigh; r++) {
        ix = ixStart - 1;
        iy = iyStart - 1;
        st.site = &o_emlrtRSI;
        if (1 > stride) {
          b15 = false;
        } else {
          b15 = (stride > 2147483646);
        }

        if (b15) {
          b_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (s = 1; s <= stride; s++) {
          ixLead = ix + stride;
          iyLead = iy;
          work = x->data[ix];
          st.site = &p_emlrtRSI;
          if (dimSize > 2147483646) {
            b_st.site = &l_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          for (m = 2; m <= dimSize; m++) {
            tmp2 = work;
            work = x->data[ixLead];
            tmp2 = x->data[ixLead] - tmp2;
            ixLead += stride;
            y->data[iyLead] = tmp2;
            iyLead += stride;
          }

          ix++;
          iy++;
        }

        ixStart += k;
        iyStart += yNext;
      }
    }
  }
}

void diff(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T dimSize;
  uint32_T ySize[4];
  int32_T k;
  int32_T nHigh;
  int32_T iyStart;
  boolean_T b6;
  int32_T r;
  int32_T ixLead;
  int32_T iyLead;
  real_T work;
  int32_T m;
  real_T tmp2;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  dimSize = x->size[0];
  if (x->size[0] <= 1) {
    for (k = 0; k < 4; k++) {
      ySize[k] = (uint32_T)x->size[k];
    }

    k = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 0;
    y->size[1] = (int32_T)ySize[1];
    y->size[2] = (int32_T)ySize[2];
    y->size[3] = (int32_T)ySize[3];
    emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                      &g_emlrtRTEI);
  } else {
    for (k = 0; k < 4; k++) {
      ySize[k] = (uint32_T)x->size[k];
    }

    ySize[0] = (uint32_T)(x->size[0] - 1);
    k = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = (int32_T)ySize[0];
    y->size[1] = (int32_T)ySize[1];
    y->size[2] = (int32_T)ySize[2];
    y->size[3] = (int32_T)ySize[3];
    emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                      &g_emlrtRTEI);
    if (!((y->size[1] == 0) || (y->size[2] == 0) || (y->size[3] == 0))) {
      st.site = &m_emlrtRSI;
      nHigh = 1;
      k = 4;
      while ((k > 2) && (x->size[k - 1] == 1)) {
        k--;
      }

      for (iyStart = 2; iyStart <= k; iyStart++) {
        nHigh *= x->size[iyStart - 1];
      }

      k = 1;
      iyStart = 1;
      st.site = &n_emlrtRSI;
      if (1 > nHigh) {
        b6 = false;
      } else {
        b6 = (nHigh > 2147483646);
      }

      if (b6) {
        b_st.site = &l_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (r = 1; r <= nHigh; r++) {
        st.site = &o_emlrtRSI;
        ixLead = k;
        iyLead = iyStart;
        work = x->data[k - 1];
        st.site = &p_emlrtRSI;
        if (dimSize > 2147483646) {
          b_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (m = 2; m <= dimSize; m++) {
          tmp2 = work;
          work = x->data[ixLead];
          tmp2 = x->data[ixLead] - tmp2;
          ixLead++;
          y->data[iyLead - 1] = tmp2;
          iyLead++;
        }

        k += dimSize;
        iyStart = (iyStart + dimSize) - 1;
      }
    }
  }
}

/* End of code generation (diff.c) */
