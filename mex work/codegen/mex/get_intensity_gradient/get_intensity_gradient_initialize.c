/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_intensity_gradient_initialize.c
 *
 * Code generation for function 'get_intensity_gradient_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "get_intensity_gradient.h"
#include "get_intensity_gradient_initialize.h"
#include "_coder_get_intensity_gradient_mex.h"
#include "get_intensity_gradient_data.h"

/* Function Definitions */
void get_intensity_gradient_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (get_intensity_gradient_initialize.c) */
