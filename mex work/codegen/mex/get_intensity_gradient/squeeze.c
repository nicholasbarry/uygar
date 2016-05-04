/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * squeeze.c
 *
 * Code generation for function 'squeeze'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "get_intensity_gradient.h"
#include "squeeze.h"
#include "get_intensity_gradient_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "get_intensity_gradient_data.h"

/* Variable Definitions */
static emlrtRSInfo ab_emlrtRSI = { 28, "squeeze",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/squeeze.m" };

static emlrtRSInfo bb_emlrtRSI = { 58, "squeeze",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/squeeze.m" };

static emlrtRTEInfo i_emlrtRTEI = { 1, 14, "squeeze",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/squeeze.m" };

/* Function Definitions */
void squeeze(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *b)
{
  int32_T k;
  int32_T sqsz[3];
  int32_T b_b;
  boolean_T b8;
  boolean_T b9;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  k = 3;
  while ((k > 2) && (a->size[2] == 1)) {
    k = 2;
  }

  if (k <= 2) {
    sqsz[0] = a->size[0];
    sqsz[1] = a->size[1];
    k = b->size[0] * b->size[1] * b->size[2];
    b->size[0] = sqsz[0];
    b->size[1] = sqsz[1];
    b->size[2] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)b, k, (int32_T)sizeof(real_T),
                      &i_emlrtRTEI);
    b_b = a->size[0] * a->size[1] * a->size[2];
    st.site = &ab_emlrtRSI;
    if (1 > b_b) {
      b8 = false;
    } else {
      b8 = (b_b > 2147483646);
    }

    if (b8) {
      b_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (k = 0; k + 1 <= b_b; k++) {
      b->data[k] = a->data[k];
    }
  } else {
    for (k = 0; k < 3; k++) {
      sqsz[k] = 1;
    }

    k = 0;
    if (a->size[0] != 1) {
      sqsz[0] = a->size[0];
      k = 1;
    }

    if (a->size[1] != 1) {
      sqsz[k] = a->size[1];
      k++;
    }

    if (a->size[2] != 1) {
      sqsz[k] = a->size[2];
    }

    k = b->size[0] * b->size[1] * b->size[2];
    b->size[0] = sqsz[0];
    b->size[1] = sqsz[1];
    b->size[2] = sqsz[2];
    emxEnsureCapacity(sp, (emxArray__common *)b, k, (int32_T)sizeof(real_T),
                      &i_emlrtRTEI);
    b_b = a->size[0] * a->size[1] * a->size[2];
    st.site = &bb_emlrtRSI;
    if (1 > b_b) {
      b9 = false;
    } else {
      b9 = (b_b > 2147483646);
    }

    if (b9) {
      b_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (k = 0; k + 1 <= b_b; k++) {
      b->data[k] = a->data[k];
    }
  }
}

/* End of code generation (squeeze.c) */
