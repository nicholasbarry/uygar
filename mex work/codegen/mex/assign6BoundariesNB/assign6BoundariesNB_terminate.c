/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assign6BoundariesNB_terminate.c
 *
 * Code generation for function 'assign6BoundariesNB_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "assign6BoundariesNB.h"
#include "assign6BoundariesNB_terminate.h"
#include "_coder_assign6BoundariesNB_mex.h"
#include "assign6BoundariesNB_data.h"

/* Function Definitions */
void assign6BoundariesNB_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void assign6BoundariesNB_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (assign6BoundariesNB_terminate.c) */
