/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_unique_counts.c
 *
 * Code generation for function 'get_unique_counts'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "get_unique_counts.h"
#include "get_unique_counts_emxutil.h"
#include "get_unique_counts_data.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 1, 21, "get_unique_counts",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/variations under dev/get_unique_counts.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 6, 24, "uniques", "get_unique_counts",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/variations under dev/get_unique_counts.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 6, 5, "counts", "get_unique_counts",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/variations under dev/get_unique_counts.m",
  0 };

/* Function Definitions */

/*
 * function [counts] = get_unique_counts(a,uniques)
 */
void get_unique_counts(const emlrtStack *sp, const emxArray_real_T *a, const
  emxArray_real_T *uniques, emxArray_real_T *counts)
{
  int32_T i0;
  int32_T loop_ub;
  int32_T i;
  emxArray_boolean_T *s;
  real_T b_uniques;
  int32_T k;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* 'get_unique_counts:3' counts = zeros(numel(uniques),1); */
  i0 = counts->size[0];
  counts->size[0] = uniques->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)counts, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = uniques->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    counts->data[i0] = 0.0;
  }

  /* 'get_unique_counts:5' for i = 1:numel(uniques) */
  i = 1;
  emxInit_boolean_T(sp, &s, 3, &emlrtRTEI, true);
  while (i - 1 <= uniques->size[0] - 1) {
    /* 'get_unique_counts:6' counts(i) = nnz(a==uniques(i)); */
    i0 = s->size[0] * s->size[1] * s->size[2];
    s->size[0] = a->size[0];
    s->size[1] = a->size[1];
    s->size[2] = a->size[2];
    emxEnsureCapacity(sp, (emxArray__common *)s, i0, (int32_T)sizeof(boolean_T),
                      &emlrtRTEI);
    i0 = uniques->size[0];
    if (!((i >= 1) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, &emlrtBCI, sp);
    }

    b_uniques = uniques->data[i - 1];
    loop_ub = a->size[0] * a->size[1] * a->size[2];
    for (i0 = 0; i0 < loop_ub; i0++) {
      s->data[i0] = (a->data[i0] == b_uniques);
    }

    loop_ub = 0;
    i0 = s->size[0] * s->size[1] * s->size[2];
    for (k = 0; k < i0; k++) {
      if (s->data[k]) {
        loop_ub++;
      }
    }

    i0 = counts->size[0];
    if (!((i >= 1) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, &b_emlrtBCI, sp);
    }

    counts->data[i - 1] = loop_ub;
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_boolean_T(&s);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (get_unique_counts.c) */
