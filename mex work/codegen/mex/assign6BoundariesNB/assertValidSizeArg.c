/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assertValidSizeArg.c
 *
 * Code generation for function 'assertValidSizeArg'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "assign6BoundariesNB.h"
#include "assertValidSizeArg.h"

/* Variable Definitions */
static emlrtRTEInfo o_emlrtRTEI = { 59, 15, "assertValidSizeArg",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"
};

static emlrtRTEInfo p_emlrtRTEI = { 44, 19, "assertValidSizeArg",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"
};

/* Function Definitions */
void assertValidSizeArg(const emlrtStack *sp, const real_T varargin_1[2])
{
  int32_T k;
  int32_T exitg1;
  boolean_T p;
  real_T n;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      if (varargin_1[k] != varargin_1[k]) {
        p = false;
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &p_emlrtRTEI,
      "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  n = 1.0;
  for (k = 0; k < 2; k++) {
    if (varargin_1[k] <= 0.0) {
      n = 0.0;
    } else {
      n *= varargin_1[k];
    }
  }

  if (2.147483647E+9 >= n) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &o_emlrtRTEI, "Coder:MATLAB:pmaxsize", 0);
  }
}

/* End of code generation (assertValidSizeArg.c) */
