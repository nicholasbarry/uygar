/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assign6BoundariesNB_initialize.c
 *
 * Code generation for function 'assign6BoundariesNB_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "assign6BoundariesNB.h"
#include "assign6BoundariesNB_initialize.h"
#include "_coder_assign6BoundariesNB_mex.h"
#include "assign6BoundariesNB_data.h"

/* Function Definitions */
void assign6BoundariesNB_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (assign6BoundariesNB_initialize.c) */
