/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_intensity_gradient.c
 *
 * Code generation for function 'get_intensity_gradient'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "get_intensity_gradient.h"
#include "get_intensity_gradient_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "scalexpAlloc.h"
#include "squeeze.h"
#include "abs.h"
#include "diff.h"
#include "cat.h"
#include "get_intensity_gradient_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 5, "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m"
};

static emlrtRSInfo b_emlrtRSI = { 6, "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m"
};

static emlrtRSInfo c_emlrtRSI = { 8, "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m"
};

static emlrtRSInfo d_emlrtRSI = { 9, "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m"
};

static emlrtRSInfo e_emlrtRSI = { 11, "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m"
};

static emlrtRSInfo f_emlrtRSI = { 12, "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m"
};

static emlrtRSInfo s_emlrtRSI = { 16, "max",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/max.m" };

static emlrtRSInfo t_emlrtRSI = { 18, "minOrMax",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo u_emlrtRSI = { 160, "minOrMax",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo v_emlrtRSI = { 161, "minOrMax",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo w_emlrtRSI = { 163, "minOrMax",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo x_emlrtRSI = { 308, "minOrMax",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo y_emlrtRSI = { 281, "minOrMax",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo cb_emlrtRSI = { 59, "minOrMax",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo db_emlrtRSI = { 182, "minOrMax",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo eb_emlrtRSI = { 208, "minOrMax",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRTEInfo emlrtRTEI = { 1, 28, "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 19, 24, "scalexpAllocNoCheck",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/scalexpAllocNoCheck.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 16, 9, "scalexpAlloc",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 5, 1, "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 35, 9, "scalexpAllocNoCheck",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/scalexpAllocNoCheck.m"
};

static emlrtDCInfo emlrtDCI = { 3, 23, "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m",
  4 };

static emlrtDCInfo b_emlrtDCI = { 3, 23, "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m",
  1 };

static emlrtDCInfo c_emlrtDCI = { 3, 35, "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m",
  4 };

static emlrtDCInfo d_emlrtDCI = { 3, 35, "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m",
  1 };

static emlrtDCInfo e_emlrtDCI = { 3, 47, "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m",
  4 };

static emlrtDCInfo f_emlrtDCI = { 3, 47, "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m",
  1 };

static emlrtBCInfo emlrtBCI = { -1, -1, 5, 21, "bbVol", "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 8, 23, "bbVol",
  "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 11, 25, "bbVol",
  "get_intensity_gradient",
  "/Users/spnba/Dropbox (MIT)/MIT/uygar/code/working core/get_intensity_gradient.m",
  0 };

static emlrtRTEInfo k_emlrtRTEI = { 81, 19, "minOrMax",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRTEInfo l_emlrtRTEI = { 17, 19, "scalexpAlloc",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"
};

/* Function Definitions */
void get_intensity_gradient(const emlrtStack *sp, real_T numYpixels, real_T
  numXpixels, real_T numSlices, const emxArray_real_T *bbVol, emxArray_real_T
  *gradAmplitude)
{
  emxArray_real_T *b_bbVol;
  int32_T ix;
  int32_T k;
  int32_T iy;
  int32_T loop_ub;
  int32_T ixstart;
  int32_T ixstop;
  emxArray_real_T *tmpbb;
  emxArray_real_T *r0;
  uint32_T outsz[4];
  emxArray_real_T *x;
  int32_T n;
  int32_T vstride;
  boolean_T b0;
  real_T mtmp;
  boolean_T overflow;
  boolean_T exitg3;
  emxArray_real_T *varargin_2;
  emxArray_real_T *ztemp;
  emxArray_real_T *r1;
  boolean_T b1;
  emxArray_real_T *c_bbVol;
  emxArray_real_T *r2;
  boolean_T b2;
  boolean_T exitg2;
  emxArray_real_T *b_ztemp;
  boolean_T b3;
  emxArray_real_T *d_bbVol;
  emxArray_real_T *r3;
  boolean_T b4;
  boolean_T exitg1;
  emxArray_real_T *c_ztemp;
  boolean_T b5;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_bbVol, 4, &emlrtRTEI, true);
  if (!(numYpixels > 0.0)) {
    emlrtNonNegativeCheckR2012b(numYpixels, &emlrtDCI, sp);
  }

  if (numYpixels != (int32_T)muDoubleScalarFloor(numYpixels)) {
    emlrtIntegerCheckR2012b(numYpixels, &b_emlrtDCI, sp);
  }

  if (!(numXpixels > 0.0)) {
    emlrtNonNegativeCheckR2012b(numXpixels, &c_emlrtDCI, sp);
  }

  if (numXpixels != (int32_T)muDoubleScalarFloor(numXpixels)) {
    emlrtIntegerCheckR2012b(numXpixels, &d_emlrtDCI, sp);
  }

  if (!(numSlices > 0.0)) {
    emlrtNonNegativeCheckR2012b(numSlices, &e_emlrtDCI, sp);
  }

  if (numSlices != (int32_T)muDoubleScalarFloor(numSlices)) {
    emlrtIntegerCheckR2012b(numSlices, &f_emlrtDCI, sp);
  }

  ix = bbVol->size[0];
  if (!(1 <= ix)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, ix, &emlrtBCI, sp);
  }

  k = bbVol->size[1];
  iy = bbVol->size[2];
  loop_ub = bbVol->size[3];
  ix = b_bbVol->size[0] * b_bbVol->size[1] * b_bbVol->size[2] * b_bbVol->size[3];
  b_bbVol->size[0] = 1;
  b_bbVol->size[1] = k;
  b_bbVol->size[2] = iy;
  b_bbVol->size[3] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)b_bbVol, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  for (ix = 0; ix < loop_ub; ix++) {
    for (ixstart = 0; ixstart < iy; ixstart++) {
      for (ixstop = 0; ixstop < k; ixstop++) {
        b_bbVol->data[(b_bbVol->size[0] * ixstop + b_bbVol->size[0] *
                       b_bbVol->size[1] * ixstart) + b_bbVol->size[0] *
          b_bbVol->size[1] * b_bbVol->size[2] * ix] = bbVol->data[(bbVol->size[0]
          * ixstop + bbVol->size[0] * bbVol->size[1] * ixstart) + bbVol->size[0]
          * bbVol->size[1] * bbVol->size[2] * ix];
      }
    }
  }

  emxInit_real_T(sp, &tmpbb, 4, &d_emlrtRTEI, true);
  emxInit_real_T(sp, &r0, 4, &emlrtRTEI, true);
  st.site = &emlrtRSI;
  cat(&st, b_bbVol, bbVol, tmpbb);
  st.site = &b_emlrtRSI;
  diff(&st, tmpbb, r0);
  st.site = &b_emlrtRSI;
  b_abs(&st, r0, tmpbb);
  st.site = &b_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  c_st.site = &t_emlrtRSI;
  emxFree_real_T(&b_bbVol);
  emxFree_real_T(&r0);
  if (tmpbb->size[3] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &k_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  for (ix = 0; ix < 4; ix++) {
    outsz[ix] = (uint32_T)tmpbb->size[ix];
  }

  emxInit_real_T1(&c_st, &x, 3, &emlrtRTEI, true);
  ix = x->size[0] * x->size[1] * x->size[2];
  x->size[0] = (int32_T)outsz[0];
  x->size[1] = (int32_T)outsz[1];
  x->size[2] = (int32_T)outsz[2];
  emxEnsureCapacity(&c_st, (emxArray__common *)x, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  n = tmpbb->size[3];
  k = 4;
  while ((k > 2) && (tmpbb->size[k - 1] == 1)) {
    k--;
  }

  if (4 > k) {
    vstride = tmpbb->size[0] * tmpbb->size[1] * tmpbb->size[2] * tmpbb->size[3];
  } else {
    vstride = 1;
    for (k = 0; k < 3; k++) {
      vstride *= tmpbb->size[k];
    }
  }

  k = 0;
  iy = -1;
  d_st.site = &u_emlrtRSI;
  d_st.site = &v_emlrtRSI;
  if (1 > vstride) {
    b0 = false;
  } else {
    b0 = (vstride > 2147483646);
  }

  if (b0) {
    e_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (loop_ub = 1; loop_ub <= vstride; loop_ub++) {
    k++;
    d_st.site = &w_emlrtRSI;
    ixstart = k;
    ixstop = k + (n - 1) * vstride;
    mtmp = tmpbb->data[k - 1];
    if (n > 1) {
      if (muDoubleScalarIsNaN(tmpbb->data[k - 1])) {
        ix = k + vstride;
        e_st.site = &y_emlrtRSI;
        if ((vstride == 0) || (ix > ixstop)) {
          overflow = false;
        } else {
          overflow = (ixstop > MAX_int32_T - vstride);
        }

        if (overflow) {
          f_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        exitg3 = false;
        while ((!exitg3) && ((vstride > 0) && (ix <= ixstop))) {
          ixstart = ix;
          if (!muDoubleScalarIsNaN(tmpbb->data[ix - 1])) {
            mtmp = tmpbb->data[ix - 1];
            exitg3 = true;
          } else {
            ix += vstride;
          }
        }
      }

      if (ixstart < ixstop) {
        ix = ixstart + vstride;
        e_st.site = &x_emlrtRSI;
        if ((vstride == 0) || (ix > ixstop)) {
          overflow = false;
        } else {
          overflow = (ixstop > MAX_int32_T - vstride);
        }

        if (overflow) {
          f_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while ((vstride > 0) && (ix <= ixstop)) {
          if (tmpbb->data[ix - 1] > mtmp) {
            mtmp = tmpbb->data[ix - 1];
          }

          ix += vstride;
        }
      }
    }

    iy++;
    x->data[iy] = mtmp;
  }

  emxInit_real_T1(&c_st, &varargin_2, 3, &emlrtRTEI, true);
  st.site = &b_emlrtRSI;
  squeeze(&st, x, varargin_2);
  st.site = &b_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  c_st.site = &t_emlrtRSI;
  d_st.site = &cb_emlrtRSI;
  e_st.site = &db_emlrtRSI;
  if ((int32_T)numYpixels <= varargin_2->size[0]) {
    k = (int32_T)numYpixels;
  } else {
    k = varargin_2->size[0];
  }

  if ((int32_T)numXpixels <= varargin_2->size[1]) {
    iy = (int32_T)numXpixels;
  } else {
    iy = varargin_2->size[1];
  }

  if ((int32_T)numSlices <= varargin_2->size[2]) {
    loop_ub = (int32_T)numSlices;
  } else {
    loop_ub = varargin_2->size[2];
  }

  emxInit_real_T1(&e_st, &ztemp, 3, &e_emlrtRTEI, true);
  emxInit_real_T1(&e_st, &r1, 3, &emlrtRTEI, true);
  ix = ztemp->size[0] * ztemp->size[1] * ztemp->size[2];
  ztemp->size[0] = k;
  ztemp->size[1] = iy;
  ztemp->size[2] = loop_ub;
  emxEnsureCapacity(&e_st, (emxArray__common *)ztemp, ix, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  ix = gradAmplitude->size[0] * gradAmplitude->size[1] * gradAmplitude->size[2];
  gradAmplitude->size[0] = k;
  gradAmplitude->size[1] = iy;
  gradAmplitude->size[2] = loop_ub;
  emxEnsureCapacity(&e_st, (emxArray__common *)gradAmplitude, ix, (int32_T)
                    sizeof(real_T), &c_emlrtRTEI);
  ix = r1->size[0] * r1->size[1] * r1->size[2];
  r1->size[0] = (int32_T)numYpixels;
  r1->size[1] = (int32_T)numXpixels;
  r1->size[2] = (int32_T)numSlices;
  emxEnsureCapacity(&e_st, (emxArray__common *)r1, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  k = (int32_T)numYpixels * (int32_T)numXpixels * (int32_T)numSlices;
  for (ix = 0; ix < k; ix++) {
    r1->data[ix] = 0.0;
  }

  if (dimagree(gradAmplitude, r1, varargin_2)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&e_st, &l_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  emxFree_real_T(&r1);
  n = ztemp->size[0] * ztemp->size[1] * ztemp->size[2];
  e_st.site = &eb_emlrtRSI;
  emxFree_real_T(&ztemp);
  if (1 > n) {
    b1 = false;
  } else {
    b1 = (n > 2147483646);
  }

  if (b1) {
    f_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (k = 0; k + 1 <= n; k++) {
    gradAmplitude->data[k] = muDoubleScalarMax(0.0, varargin_2->data[k]);
  }

  emxInit_real_T(&d_st, &c_bbVol, 4, &emlrtRTEI, true);
  ix = bbVol->size[1];
  if (!(1 <= ix)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, ix, &b_emlrtBCI, sp);
  }

  k = bbVol->size[0];
  iy = bbVol->size[2];
  loop_ub = bbVol->size[3];
  ix = c_bbVol->size[0] * c_bbVol->size[1] * c_bbVol->size[2] * c_bbVol->size[3];
  c_bbVol->size[0] = k;
  c_bbVol->size[1] = 1;
  c_bbVol->size[2] = iy;
  c_bbVol->size[3] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)c_bbVol, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  for (ix = 0; ix < loop_ub; ix++) {
    for (ixstart = 0; ixstart < iy; ixstart++) {
      for (ixstop = 0; ixstop < k; ixstop++) {
        c_bbVol->data[(ixstop + c_bbVol->size[0] * c_bbVol->size[1] * ixstart) +
          c_bbVol->size[0] * c_bbVol->size[1] * c_bbVol->size[2] * ix] =
          bbVol->data[(ixstop + bbVol->size[0] * bbVol->size[1] * ixstart) +
          bbVol->size[0] * bbVol->size[1] * bbVol->size[2] * ix];
      }
    }
  }

  emxInit_real_T(sp, &r2, 4, &emlrtRTEI, true);
  st.site = &c_emlrtRSI;
  b_cat(&st, c_bbVol, bbVol, tmpbb);
  st.site = &d_emlrtRSI;
  b_diff(&st, tmpbb, r2);
  st.site = &d_emlrtRSI;
  b_abs(&st, r2, tmpbb);
  st.site = &d_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  c_st.site = &t_emlrtRSI;
  emxFree_real_T(&c_bbVol);
  emxFree_real_T(&r2);
  if (tmpbb->size[3] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &k_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  for (ix = 0; ix < 4; ix++) {
    outsz[ix] = (uint32_T)tmpbb->size[ix];
  }

  ix = x->size[0] * x->size[1] * x->size[2];
  x->size[0] = (int32_T)outsz[0];
  x->size[1] = (int32_T)outsz[1];
  x->size[2] = (int32_T)outsz[2];
  emxEnsureCapacity(&c_st, (emxArray__common *)x, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  n = tmpbb->size[3];
  k = 4;
  while ((k > 2) && (tmpbb->size[k - 1] == 1)) {
    k--;
  }

  if (4 > k) {
    vstride = tmpbb->size[0] * tmpbb->size[1] * tmpbb->size[2] * tmpbb->size[3];
  } else {
    vstride = 1;
    for (k = 0; k < 3; k++) {
      vstride *= tmpbb->size[k];
    }
  }

  k = 0;
  iy = -1;
  d_st.site = &u_emlrtRSI;
  d_st.site = &v_emlrtRSI;
  if (1 > vstride) {
    b2 = false;
  } else {
    b2 = (vstride > 2147483646);
  }

  if (b2) {
    e_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (loop_ub = 1; loop_ub <= vstride; loop_ub++) {
    k++;
    d_st.site = &w_emlrtRSI;
    ixstart = k;
    ixstop = k + (n - 1) * vstride;
    mtmp = tmpbb->data[k - 1];
    if (n > 1) {
      if (muDoubleScalarIsNaN(tmpbb->data[k - 1])) {
        ix = k + vstride;
        e_st.site = &y_emlrtRSI;
        if ((vstride == 0) || (ix > ixstop)) {
          overflow = false;
        } else {
          overflow = (ixstop > MAX_int32_T - vstride);
        }

        if (overflow) {
          f_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        exitg2 = false;
        while ((!exitg2) && ((vstride > 0) && (ix <= ixstop))) {
          ixstart = ix;
          if (!muDoubleScalarIsNaN(tmpbb->data[ix - 1])) {
            mtmp = tmpbb->data[ix - 1];
            exitg2 = true;
          } else {
            ix += vstride;
          }
        }
      }

      if (ixstart < ixstop) {
        ix = ixstart + vstride;
        e_st.site = &x_emlrtRSI;
        if ((vstride == 0) || (ix > ixstop)) {
          overflow = false;
        } else {
          overflow = (ixstop > MAX_int32_T - vstride);
        }

        if (overflow) {
          f_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while ((vstride > 0) && (ix <= ixstop)) {
          if (tmpbb->data[ix - 1] > mtmp) {
            mtmp = tmpbb->data[ix - 1];
          }

          ix += vstride;
        }
      }
    }

    iy++;
    x->data[iy] = mtmp;
  }

  st.site = &d_emlrtRSI;
  squeeze(&st, x, varargin_2);
  st.site = &d_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  c_st.site = &t_emlrtRSI;
  d_st.site = &cb_emlrtRSI;
  ix = x->size[0] * x->size[1] * x->size[2];
  x->size[0] = gradAmplitude->size[0];
  x->size[1] = gradAmplitude->size[1];
  x->size[2] = gradAmplitude->size[2];
  emxEnsureCapacity(&d_st, (emxArray__common *)x, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  k = gradAmplitude->size[0] * gradAmplitude->size[1] * gradAmplitude->size[2];
  for (ix = 0; ix < k; ix++) {
    x->data[ix] = gradAmplitude->data[ix];
  }

  e_st.site = &db_emlrtRSI;
  if (gradAmplitude->size[0] <= varargin_2->size[0]) {
    k = gradAmplitude->size[0];
  } else {
    k = varargin_2->size[0];
  }

  if (gradAmplitude->size[1] <= varargin_2->size[1]) {
    iy = gradAmplitude->size[1];
  } else {
    iy = varargin_2->size[1];
  }

  if (gradAmplitude->size[2] <= varargin_2->size[2]) {
    loop_ub = gradAmplitude->size[2];
  } else {
    loop_ub = varargin_2->size[2];
  }

  emxInit_real_T1(&e_st, &b_ztemp, 3, &e_emlrtRTEI, true);
  ix = b_ztemp->size[0] * b_ztemp->size[1] * b_ztemp->size[2];
  b_ztemp->size[0] = k;
  b_ztemp->size[1] = iy;
  b_ztemp->size[2] = loop_ub;
  emxEnsureCapacity(&e_st, (emxArray__common *)b_ztemp, ix, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  ix = gradAmplitude->size[0] * gradAmplitude->size[1] * gradAmplitude->size[2];
  gradAmplitude->size[0] = k;
  gradAmplitude->size[1] = iy;
  gradAmplitude->size[2] = loop_ub;
  emxEnsureCapacity(&e_st, (emxArray__common *)gradAmplitude, ix, (int32_T)
                    sizeof(real_T), &c_emlrtRTEI);
  if (dimagree(gradAmplitude, x, varargin_2)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&e_st, &l_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  n = b_ztemp->size[0] * b_ztemp->size[1] * b_ztemp->size[2];
  e_st.site = &eb_emlrtRSI;
  emxFree_real_T(&b_ztemp);
  if (1 > n) {
    b3 = false;
  } else {
    b3 = (n > 2147483646);
  }

  if (b3) {
    f_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (k = 0; k + 1 <= n; k++) {
    gradAmplitude->data[k] = muDoubleScalarMax(x->data[k], varargin_2->data[k]);
  }

  emxInit_real_T(&d_st, &d_bbVol, 4, &emlrtRTEI, true);
  ix = bbVol->size[2];
  if (!(1 <= ix)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, ix, &c_emlrtBCI, sp);
  }

  k = bbVol->size[0];
  iy = bbVol->size[1];
  loop_ub = bbVol->size[3];
  ix = d_bbVol->size[0] * d_bbVol->size[1] * d_bbVol->size[2] * d_bbVol->size[3];
  d_bbVol->size[0] = k;
  d_bbVol->size[1] = iy;
  d_bbVol->size[2] = 1;
  d_bbVol->size[3] = loop_ub;
  emxEnsureCapacity(sp, (emxArray__common *)d_bbVol, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  for (ix = 0; ix < loop_ub; ix++) {
    for (ixstart = 0; ixstart < iy; ixstart++) {
      for (ixstop = 0; ixstop < k; ixstop++) {
        d_bbVol->data[(ixstop + d_bbVol->size[0] * ixstart) + d_bbVol->size[0] *
          d_bbVol->size[1] * d_bbVol->size[2] * ix] = bbVol->data[(ixstop +
          bbVol->size[0] * ixstart) + bbVol->size[0] * bbVol->size[1] *
          bbVol->size[2] * ix];
      }
    }
  }

  emxInit_real_T(sp, &r3, 4, &emlrtRTEI, true);
  st.site = &e_emlrtRSI;
  c_cat(&st, d_bbVol, bbVol, tmpbb);
  st.site = &f_emlrtRSI;
  c_diff(&st, tmpbb, r3);
  st.site = &f_emlrtRSI;
  b_abs(&st, r3, tmpbb);
  st.site = &f_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  c_st.site = &t_emlrtRSI;
  emxFree_real_T(&d_bbVol);
  emxFree_real_T(&r3);
  if (tmpbb->size[3] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &k_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  for (ix = 0; ix < 4; ix++) {
    outsz[ix] = (uint32_T)tmpbb->size[ix];
  }

  ix = x->size[0] * x->size[1] * x->size[2];
  x->size[0] = (int32_T)outsz[0];
  x->size[1] = (int32_T)outsz[1];
  x->size[2] = (int32_T)outsz[2];
  emxEnsureCapacity(&c_st, (emxArray__common *)x, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  n = tmpbb->size[3];
  k = 4;
  while ((k > 2) && (tmpbb->size[k - 1] == 1)) {
    k--;
  }

  if (4 > k) {
    vstride = tmpbb->size[0] * tmpbb->size[1] * tmpbb->size[2] * tmpbb->size[3];
  } else {
    vstride = 1;
    for (k = 0; k < 3; k++) {
      vstride *= tmpbb->size[k];
    }
  }

  k = 0;
  iy = -1;
  d_st.site = &u_emlrtRSI;
  d_st.site = &v_emlrtRSI;
  if (1 > vstride) {
    b4 = false;
  } else {
    b4 = (vstride > 2147483646);
  }

  if (b4) {
    e_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (loop_ub = 1; loop_ub <= vstride; loop_ub++) {
    k++;
    d_st.site = &w_emlrtRSI;
    ixstart = k;
    ixstop = k + (n - 1) * vstride;
    mtmp = tmpbb->data[k - 1];
    if (n > 1) {
      if (muDoubleScalarIsNaN(tmpbb->data[k - 1])) {
        ix = k + vstride;
        e_st.site = &y_emlrtRSI;
        if ((vstride == 0) || (ix > ixstop)) {
          overflow = false;
        } else {
          overflow = (ixstop > MAX_int32_T - vstride);
        }

        if (overflow) {
          f_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        exitg1 = false;
        while ((!exitg1) && ((vstride > 0) && (ix <= ixstop))) {
          ixstart = ix;
          if (!muDoubleScalarIsNaN(tmpbb->data[ix - 1])) {
            mtmp = tmpbb->data[ix - 1];
            exitg1 = true;
          } else {
            ix += vstride;
          }
        }
      }

      if (ixstart < ixstop) {
        ix = ixstart + vstride;
        e_st.site = &x_emlrtRSI;
        if ((vstride == 0) || (ix > ixstop)) {
          overflow = false;
        } else {
          overflow = (ixstop > MAX_int32_T - vstride);
        }

        if (overflow) {
          f_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while ((vstride > 0) && (ix <= ixstop)) {
          if (tmpbb->data[ix - 1] > mtmp) {
            mtmp = tmpbb->data[ix - 1];
          }

          ix += vstride;
        }
      }
    }

    iy++;
    x->data[iy] = mtmp;
  }

  emxFree_real_T(&tmpbb);
  st.site = &f_emlrtRSI;
  squeeze(&st, x, varargin_2);
  st.site = &f_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  c_st.site = &t_emlrtRSI;
  d_st.site = &cb_emlrtRSI;
  ix = x->size[0] * x->size[1] * x->size[2];
  x->size[0] = gradAmplitude->size[0];
  x->size[1] = gradAmplitude->size[1];
  x->size[2] = gradAmplitude->size[2];
  emxEnsureCapacity(&d_st, (emxArray__common *)x, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  k = gradAmplitude->size[0] * gradAmplitude->size[1] * gradAmplitude->size[2];
  for (ix = 0; ix < k; ix++) {
    x->data[ix] = gradAmplitude->data[ix];
  }

  e_st.site = &db_emlrtRSI;
  if (gradAmplitude->size[0] <= varargin_2->size[0]) {
    k = gradAmplitude->size[0];
  } else {
    k = varargin_2->size[0];
  }

  if (gradAmplitude->size[1] <= varargin_2->size[1]) {
    iy = gradAmplitude->size[1];
  } else {
    iy = varargin_2->size[1];
  }

  if (gradAmplitude->size[2] <= varargin_2->size[2]) {
    loop_ub = gradAmplitude->size[2];
  } else {
    loop_ub = varargin_2->size[2];
  }

  emxInit_real_T1(&e_st, &c_ztemp, 3, &e_emlrtRTEI, true);
  ix = c_ztemp->size[0] * c_ztemp->size[1] * c_ztemp->size[2];
  c_ztemp->size[0] = k;
  c_ztemp->size[1] = iy;
  c_ztemp->size[2] = loop_ub;
  emxEnsureCapacity(&e_st, (emxArray__common *)c_ztemp, ix, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  ix = gradAmplitude->size[0] * gradAmplitude->size[1] * gradAmplitude->size[2];
  gradAmplitude->size[0] = k;
  gradAmplitude->size[1] = iy;
  gradAmplitude->size[2] = loop_ub;
  emxEnsureCapacity(&e_st, (emxArray__common *)gradAmplitude, ix, (int32_T)
                    sizeof(real_T), &c_emlrtRTEI);
  if (dimagree(gradAmplitude, x, varargin_2)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&e_st, &l_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  n = c_ztemp->size[0] * c_ztemp->size[1] * c_ztemp->size[2];
  e_st.site = &eb_emlrtRSI;
  emxFree_real_T(&c_ztemp);
  if (1 > n) {
    b5 = false;
  } else {
    b5 = (n > 2147483646);
  }

  if (b5) {
    f_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (k = 0; k + 1 <= n; k++) {
    gradAmplitude->data[k] = muDoubleScalarMax(x->data[k], varargin_2->data[k]);
  }

  emxFree_real_T(&x);
  emxFree_real_T(&varargin_2);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (get_intensity_gradient.c) */
