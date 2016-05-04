/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assign6BoundariesNB.c
 *
 * Code generation for function 'assign6BoundariesNB'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "assign6BoundariesNB.h"
#include "assign6BoundariesNB_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "scalexpAlloc.h"
#include "repmat.h"
#include "indexShapeCheck.h"
#include "fprintf.h"
#include "meshgrid.h"
#include "sum.h"
#include "assign6BoundariesNB_data.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 69, 1, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtRSInfo emlrtRSI = { 3, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtRSInfo b_emlrtRSI = { 36, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtRSInfo c_emlrtRSI = { 38, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtRSInfo d_emlrtRSI = { 47, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtRSInfo e_emlrtRSI = { 48, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtRSInfo f_emlrtRSI = { 49, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtRSInfo g_emlrtRSI = { 56, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtRSInfo h_emlrtRSI = { 63, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtRSInfo i_emlrtRSI = { 69, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtRSInfo j_emlrtRSI = { 44, "find",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo k_emlrtRSI = { 234, "find",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo l_emlrtRSI = { 253, "find",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo o_emlrtRSI = { 21, "colon",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/ops/colon.m" };

static emlrtRSInfo p_emlrtRSI = { 79, "colon",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/ops/colon.m" };

static emlrtRSInfo q_emlrtRSI = { 283, "colon",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/ops/colon.m" };

static emlrtRSInfo r_emlrtRSI = { 291, "colon",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/ops/colon.m" };

static emlrtRSInfo y_emlrtRSI = { 10, "eml_null_assignment",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo ab_emlrtRSI = { 14, "eml_null_assignment",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo db_emlrtRSI = { 176, "eml_null_assignment",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo ib_emlrtRSI = { 49, "power",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/ops/power.m" };

static emlrtRSInfo jb_emlrtRSI = { 58, "power",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/ops/power.m" };

static emlrtRSInfo kb_emlrtRSI = { 73, "applyScalarFunction",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"
};

static emlrtRSInfo lb_emlrtRSI = { 132, "applyScalarFunction",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"
};

static emlrtRSInfo mb_emlrtRSI = { 13, "sum",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/sum.m" };

static emlrtRSInfo nb_emlrtRSI = { 46, "sumprod",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

static emlrtRSInfo ob_emlrtRSI = { 56, "combine_vector_elements",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"
};

static emlrtRSInfo pb_emlrtRSI = { 60, "combine_vector_elements",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"
};

static emlrtRSInfo qb_emlrtRSI = { 18, "min",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/min.m" };

static emlrtRSInfo rb_emlrtRSI = { 15, "minOrMax",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo sb_emlrtRSI = { 35, "fprintf",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtRTEInfo b_emlrtRTEI = { 1, 14, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtRTEInfo f_emlrtRTEI = { 253, 13, "find",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo g_emlrtRTEI = { 16, 9, "scalexpAlloc",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 3, 1, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtRTEInfo i_emlrtRTEI = { 4, 1, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtRTEInfo j_emlrtRTEI = { 36, 1, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtRTEInfo k_emlrtRTEI = { 39, 1, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtRTEInfo l_emlrtRTEI = { 36, 6, "find",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo q_emlrtRTEI = { 17, 19, "scalexpAlloc",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"
};

static emlrtRTEInfo r_emlrtRTEI = { 243, 9, "find",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo s_emlrtRTEI = { 126, 19, "find",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtECInfo emlrtECI = { -1, 62, 5, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtECInfo b_emlrtECI = { 2, 56, 51, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtECInfo c_emlrtECI = { 2, 56, 57, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 46, 54, "validIdxs",
  "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 45, 42, "boundaries",
  "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m", 0 };

static emlrtECInfo d_emlrtECI = { 2, 39, 13, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m" };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 62, 5, "L", "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m", 0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 49, 18, "L", "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m", 0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 56, 51, "bbVol", "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m", 0 };

static emlrtDCInfo emlrtDCI = { 56, 51, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m", 1 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 56, 149, "bbVol",
  "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m", 0 };

static emlrtDCInfo b_emlrtDCI = { 56, 149, "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m", 1 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 57, 42, "L", "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m", 0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 57, 44, "validIdx",
  "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 57, 13, "newBoundaryAssignments",
  "assign6BoundariesNB",
  "/Users/spnba/Desktop/MIT/uygar/to send/assign6BoundariesNB.m", 0 };

static emlrtRTEInfo t_emlrtRTEI = { 175, 9, "eml_null_assignment",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRTEInfo u_emlrtRTEI = { 172, 9, "eml_null_assignment",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRTEInfo v_emlrtRTEI = { 81, 27, "eml_null_assignment",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

/* Function Declarations */
static int32_T asr_s32(int32_T u, uint32_T n);
static void eml_null_assignment(const emlrtStack *sp, real_T x_data[], int32_T
  x_size[1], const boolean_T idx_data[], const int32_T idx_size[1]);
static const mxArray *emlrt_marshallOut(const real_T u);

/* Function Definitions */
static int32_T asr_s32(int32_T u, uint32_T n)
{
  int32_T y;
  if (u >= 0) {
    y = (int32_T)((uint32_T)u >> n);
  } else {
    y = -(int32_T)((uint32_T)-(u + 1) >> n) - 1;
  }

  return y;
}

static void eml_null_assignment(const emlrtStack *sp, real_T x_data[], int32_T
  x_size[1], const boolean_T idx_data[], const int32_T idx_size[1])
{
  int32_T k;
  int32_T nxin;
  int32_T nrowx;
  int32_T k0;
  int32_T nxout;
  real_T b_x_data[26];
  int32_T iv13[2];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &y_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  k = idx_size[0];
  while ((k >= 1) && (!idx_data[k - 1])) {
    k--;
  }

  if (k <= x_size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &v_emlrtRTEI, "MATLAB:subsdeldimmismatch",
      0);
  }

  st.site = &ab_emlrtRSI;
  nxin = x_size[0];
  nrowx = x_size[0];
  k0 = 0;
  for (k = 1; k <= idx_size[0]; k++) {
    k0 += idx_data[k - 1];
  }

  nxout = x_size[0] - k0;
  k0 = -1;
  for (k = 1; k <= nxin; k++) {
    if ((k > idx_size[0]) || (!idx_data[k - 1])) {
      k0++;
      x_data[k0] = x_data[k - 1];
    }
  }

  if (nrowx != 1) {
    if (nxout <= nrowx) {
    } else {
      emlrtErrorWithMessageIdR2012b(&st, &u_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (1 > nxout) {
      nxout = 0;
    }

    for (k0 = 0; k0 < nxout; k0++) {
      b_x_data[k0] = x_data[k0];
    }

    x_size[0] = nxout;
    for (k0 = 0; k0 < nxout; k0++) {
      x_data[k0] = b_x_data[k0];
    }
  } else {
    if (nxout <= nxin) {
    } else {
      emlrtErrorWithMessageIdR2012b(&st, &t_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (1 > nxout) {
      k0 = 0;
    } else {
      k0 = nxout;
    }

    iv13[0] = 1;
    iv13[1] = k0;
    b_st.site = &db_emlrtRSI;
    indexShapeCheck(&b_st, x_size[0], iv13);
    x_size[0] = k0;
  }
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m4;
  y = NULL;
  m4 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m4);
  return y;
}

void assign6BoundariesNB(const emlrtStack *sp, emxArray_uint32_T *L, const
  emxArray_real_T *bbVol)
{
  emxArray_boolean_T *x;
  int32_T voxelCount;
  int32_T ixstart;
  int32_T idx;
  int32_T nx;
  boolean_T b0;
  emxArray_int32_T *ii;
  boolean_T b1;
  int32_T nm1d2;
  boolean_T exitg3;
  boolean_T guard2 = false;
  int32_T iv9[2];
  emxArray_real_T *boundaries;
  emxArray_real_T *newBoundaryAssignments;
  int32_T iv10[2];
  int32_T apnd;
  emxArray_real_T *shift_by_channel;
  int32_T k;
  real_T b_bbVol[3];
  real_T dv0[78];
  real_T dv1[78];
  static const int8_T translation_matrix[78] = { -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, 0, 0, 0,
    1, 1, 1, -1, -1, -1, 0, 0, 1, 1, 1, -1, -1, -1, 0, 0, 0, 1, 1, 1, -1, 0, 1,
    -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1
  };

  emxArray_real_T *validIdxs;
  emxArray_real_T *bar;
  real_T dv2[26];
  int32_T b_validIdxs[2];
  int32_T b_bar[2];
  real_T iterCount;
  emxArray_real_T *r0;
  emxArray_real_T *r1;
  emxArray_real_T *a;
  emxArray_real_T *c_bbVol;
  int32_T kk;
  int32_T validIdx_size[1];
  real_T validIdx_data[26];
  int32_T tmp_size[1];
  boolean_T tmp_data[26];
  real_T validIdx[2];
  real_T dv3[2];
  int32_T c_bar[2];
  int32_T iv11[2];
  real_T s;
  real_T b_boundaries;
  real_T b_validIdx[2];
  boolean_T b2;
  real_T varargin_1_data[26];
  int32_T varargin_1_size_idx_0;
  int32_T ix;
  boolean_T b3;
  boolean_T exitg2;
  boolean_T b4;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv12[2];
  int8_T i1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &x, 3, &b_emlrtRTEI, true);
  voxelCount = L->size[0] * L->size[1] * L->size[2];
  st.site = &emlrtRSI;
  ixstart = x->size[0] * x->size[1] * x->size[2];
  x->size[0] = L->size[0];
  x->size[1] = L->size[1];
  x->size[2] = L->size[2];
  emxEnsureCapacity(&st, (emxArray__common *)x, ixstart, (int32_T)sizeof
                    (boolean_T), &b_emlrtRTEI);
  idx = L->size[0] * L->size[1] * L->size[2];
  for (ixstart = 0; ixstart < idx; ixstart++) {
    x->data[ixstart] = (L->data[ixstart] == 0U);
  }

  b_st.site = &j_emlrtRSI;
  nx = x->size[0] * x->size[1] * x->size[2];
  idx = 0;
  if ((!(((x->size[0] == 1) || (x->size[1] == 1)) && (x->size[2] == 1))) ||
      (x->size[0] != 1) || (x->size[1] <= 1)) {
    b0 = true;
  } else {
    b0 = false;
  }

  if (b0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &s_emlrtRTEI,
      "Coder:toolbox:find_incompatibleShape", 0);
  }

  emxInit_int32_T(&b_st, &ii, 1, &l_emlrtRTEI, true);
  ixstart = ii->size[0];
  ii->size[0] = nx;
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, ixstart, (int32_T)sizeof
                    (int32_T), &b_emlrtRTEI);
  c_st.site = &k_emlrtRSI;
  if (1 > nx) {
    b1 = false;
  } else {
    b1 = (nx > 2147483646);
  }

  if (b1) {
    d_st.site = &m_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  nm1d2 = 1;
  exitg3 = false;
  while ((!exitg3) && (nm1d2 <= nx)) {
    guard2 = false;
    if (x->data[nm1d2 - 1]) {
      idx++;
      ii->data[idx - 1] = nm1d2;
      if (idx >= nx) {
        exitg3 = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      nm1d2++;
    }
  }

  if (idx <= nx) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (nx == 1) {
    if (idx == 0) {
      ixstart = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, ixstart, (int32_T)sizeof
                        (int32_T), &b_emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      ixstart = 0;
    } else {
      ixstart = idx;
    }

    iv9[0] = 1;
    iv9[1] = ixstart;
    c_st.site = &l_emlrtRSI;
    indexShapeCheck(&c_st, ii->size[0], iv9);
    nm1d2 = ii->size[0];
    ii->size[0] = ixstart;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, nm1d2, (int32_T)sizeof
                      (int32_T), &f_emlrtRTEI);
  }

  emxInit_real_T2(&b_st, &boundaries, 1, &h_emlrtRTEI, true);
  ixstart = boundaries->size[0];
  boundaries->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)boundaries, ixstart, (int32_T)
                    sizeof(real_T), &b_emlrtRTEI);
  idx = ii->size[0];
  for (ixstart = 0; ixstart < idx; ixstart++) {
    boundaries->data[ixstart] = ii->data[ixstart];
  }

  emxInit_real_T2(&st, &newBoundaryAssignments, 1, &i_emlrtRTEI, true);

  /*  linear indices  */
  iv10[0] = boundaries->size[0];
  ixstart = newBoundaryAssignments->size[0];
  newBoundaryAssignments->size[0] = iv10[0];
  emxEnsureCapacity(sp, (emxArray__common *)newBoundaryAssignments, ixstart,
                    (int32_T)sizeof(real_T), &b_emlrtRTEI);
  idx = iv10[0];
  for (ixstart = 0; ixstart < idx; ixstart++) {
    newBoundaryAssignments->data[ixstart] = 0.0;
  }

  /*  translation_matrix  = fliplr(combvec([-1,0,1],[-1,0,1],[-1,0,1])');translation_matrix(ceil(size(translation_matrix,1)/2),:)=[]; */
  /*  a = {[-1,0,1],[-1,0,1],[-1,0,1]};v=cell(3,1);[v{:}] = ndgrid(a{:});res = reshape(cat(4,v{:}),[],3);translation_matrix(ceil(size(res,1)/2),:)=[]; */
  st.site = &b_emlrtRSI;
  b_st.site = &o_emlrtRSI;
  c_st.site = &p_emlrtRSI;
  if (bbVol->size[3] - 1 < 0) {
    idx = -1;
    apnd = -1;
  } else {
    idx = (int32_T)muDoubleScalarFloor(((real_T)bbVol->size[3] - 1.0) + 0.5) - 1;
    apnd = idx + 1;
    nx = (idx - bbVol->size[3]) + 2;
    if (muDoubleScalarAbs(nx) < 4.4408920985006262E-16 * muDoubleScalarAbs
        ((real_T)bbVol->size[3] - 1.0)) {
      idx++;
      apnd = bbVol->size[3] - 1;
    } else if (nx > 0) {
      apnd = idx;
    } else {
      idx++;
    }
  }

  emxInit_real_T(&c_st, &shift_by_channel, 2, &j_emlrtRTEI, true);
  d_st.site = &q_emlrtRSI;
  ixstart = shift_by_channel->size[0] * shift_by_channel->size[1];
  shift_by_channel->size[0] = 1;
  shift_by_channel->size[1] = idx + 1;
  emxEnsureCapacity(&c_st, (emxArray__common *)shift_by_channel, ixstart,
                    (int32_T)sizeof(real_T), &b_emlrtRTEI);
  if (idx + 1 > 0) {
    shift_by_channel->data[0] = 0.0;
    if (idx + 1 > 1) {
      shift_by_channel->data[idx] = apnd;
      nm1d2 = asr_s32(idx + (idx < 0), 1U);
      d_st.site = &r_emlrtRSI;
      for (k = 1; k < nm1d2; k++) {
        shift_by_channel->data[k] = k;
        shift_by_channel->data[idx - k] = apnd - k;
      }

      if (nm1d2 << 1 == idx) {
        shift_by_channel->data[nm1d2] = (real_T)apnd / 2.0;
      } else {
        shift_by_channel->data[nm1d2] = nm1d2;
        shift_by_channel->data[nm1d2 + 1] = apnd - nm1d2;
      }
    }
  }

  ixstart = shift_by_channel->size[0] * shift_by_channel->size[1];
  shift_by_channel->size[0] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)shift_by_channel, ixstart, (int32_T)
                    sizeof(real_T), &b_emlrtRTEI);
  nm1d2 = shift_by_channel->size[0];
  nx = shift_by_channel->size[1];
  idx = nm1d2 * nx;
  for (ixstart = 0; ixstart < idx; ixstart++) {
    shift_by_channel->data[ixstart] *= (real_T)voxelCount;
  }

  /*  1 x numChannels vector containing multiples of the number of voxels in each 3D stack */
  b_bbVol[0] = bbVol->size[0];
  b_bbVol[1] = (real_T)bbVol->size[0] * (real_T)bbVol->size[1];
  b_bbVol[2] = 1.0;
  repmat(b_bbVol, dv0);
  for (ixstart = 0; ixstart < 78; ixstart++) {
    dv1[ixstart] = dv0[ixstart] * (real_T)translation_matrix[ixstart];
  }

  emxInit_real_T(sp, &validIdxs, 2, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &bar, 2, &b_emlrtRTEI, true);
  sum(dv1, dv2);
  st.site = &c_emlrtRSI;
  meshgrid(&st, boundaries, dv2, validIdxs, bar);
  for (ixstart = 0; ixstart < 2; ixstart++) {
    b_validIdxs[ixstart] = validIdxs->size[ixstart];
  }

  for (ixstart = 0; ixstart < 2; ixstart++) {
    b_bar[ixstart] = bar->size[ixstart];
  }

  if ((b_validIdxs[0] != b_bar[0]) || (b_validIdxs[1] != b_bar[1])) {
    emlrtSizeEqCheckNDR2012b(&b_validIdxs[0], &b_bar[0], &d_emlrtECI, sp);
  }

  ixstart = validIdxs->size[0] * validIdxs->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)validIdxs, ixstart, (int32_T)sizeof
                    (real_T), &b_emlrtRTEI);
  nm1d2 = validIdxs->size[0];
  nx = validIdxs->size[1];
  idx = nm1d2 * nx;
  for (ixstart = 0; ixstart < idx; ixstart++) {
    validIdxs->data[ixstart] += bar->data[ixstart];
  }

  iterCount = 1.0;
  emxInit_real_T(sp, &r0, 2, &b_emlrtRTEI, true);
  emxInit_real_T(sp, &r1, 2, &b_emlrtRTEI, true);
  emxInit_real_T(sp, &a, 2, &b_emlrtRTEI, true);
  emxInit_real_T(sp, &c_bbVol, 2, &b_emlrtRTEI, true);
  while (!(boundaries->size[0] == 0)) {
    kk = 0;
    while (kk <= boundaries->size[0] - 1) {
      ixstart = boundaries->size[0];
      nm1d2 = kk + 1;
      if (!((nm1d2 >= 1) && (nm1d2 <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(nm1d2, 1, ixstart, &b_emlrtBCI, sp);
      }

      idx = validIdxs->size[0];
      ixstart = validIdxs->size[1];
      nm1d2 = 1 + kk;
      if (!((nm1d2 >= 1) && (nm1d2 <= ixstart))) {
        emlrtDynamicBoundsCheckR2012b(nm1d2, 1, ixstart, &emlrtBCI, sp);
      }

      validIdx_size[0] = idx;
      for (ixstart = 0; ixstart < idx; ixstart++) {
        validIdx_data[ixstart] = validIdxs->data[ixstart + validIdxs->size[0] *
          (nm1d2 - 1)];
      }

      tmp_size[0] = idx;
      for (ixstart = 0; ixstart < idx; ixstart++) {
        tmp_data[ixstart] = (validIdx_data[ixstart] < 1.0);
      }

      st.site = &d_emlrtRSI;
      eml_null_assignment(&st, validIdx_data, validIdx_size, tmp_data, tmp_size);

      /*  index below range */
      tmp_size[0] = validIdx_size[0];
      idx = validIdx_size[0];
      for (ixstart = 0; ixstart < idx; ixstart++) {
        tmp_data[ixstart] = (validIdx_data[ixstart] > voxelCount);
      }

      st.site = &e_emlrtRSI;
      eml_null_assignment(&st, validIdx_data, validIdx_size, tmp_data, tmp_size);

      /*  index above range */
      st.site = &f_emlrtRSI;
      b_indexShapeCheck(&st, *(int32_T (*)[3])L->size, validIdx_size[0]);
      nx = L->size[0] * L->size[1] * L->size[2];
      tmp_size[0] = validIdx_size[0];
      idx = validIdx_size[0];
      for (ixstart = 0; ixstart < idx; ixstart++) {
        nm1d2 = (int32_T)validIdx_data[ixstart];
        if (!((nm1d2 >= 1) && (nm1d2 <= nx))) {
          emlrtDynamicBoundsCheckR2012b(nm1d2, 1, nx, &d_emlrtBCI, sp);
        }

        tmp_data[ixstart] = (L->data[nm1d2 - 1] == 0U);
      }

      st.site = &f_emlrtRSI;
      eml_null_assignment(&st, validIdx_data, validIdx_size, tmp_data, tmp_size);

      /*  BOUNDARY VOXELS ARE INELIGIBLE */
      if (!(validIdx_size[0] == 0)) {
        /*              validVal                   = bbVol(repmat(shift_by_channel,[numel(validIdx),1]) + repmat(validIdx,[1 size(bbVol,4)])); % validVal has shape numel(validIdx) x size(bbVol,4); a 2D array in which each column is the list of values for those linear indices in that color */
        /*              thisVal                    = bbVol(shift_by_channel + thisVoxIdx); % val is the val of the pixel in the volume of thisVoxIdx for each color channel */
        /*              allNormSq                  = sum((validVal - repmat(thisVal, [numel(validIdx), 1])).^2, 2); % normalizing the neighbors by the center voxel, squaring, then summing along the rows */
        /*              [~,pos]                    = min(allNormSq); % the indices of the minimum of the normed values */
        validIdx[0] = validIdx_size[0];
        validIdx[1] = 1.0;
        st.site = &g_emlrtRSI;
        b_repmat(&st, shift_by_channel, validIdx, bar);
        dv3[0] = 1.0;
        dv3[1] = bbVol->size[3];
        st.site = &g_emlrtRSI;
        c_repmat(&st, validIdx_data, validIdx_size, dv3, r0);
        for (ixstart = 0; ixstart < 2; ixstart++) {
          c_bar[ixstart] = bar->size[ixstart];
        }

        for (ixstart = 0; ixstart < 2; ixstart++) {
          iv11[ixstart] = r0->size[ixstart];
        }

        if ((c_bar[0] != iv11[0]) || (c_bar[1] != iv11[1])) {
          emlrtSizeEqCheckNDR2012b(&c_bar[0], &iv11[0], &c_emlrtECI, sp);
        }

        st.site = &g_emlrtRSI;
        c_indexShapeCheck(&st, *(int32_T (*)[4])bbVol->size, *(int32_T (*)[2])
                          bar->size);
        st.site = &g_emlrtRSI;
        c_indexShapeCheck(&st, *(int32_T (*)[4])bbVol->size, *(int32_T (*)[2])
                          shift_by_channel->size);
        ixstart = a->size[0] * a->size[1];
        a->size[0] = bar->size[0];
        a->size[1] = bar->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)a, ixstart, (int32_T)sizeof
                          (real_T), &b_emlrtRTEI);
        nx = bbVol->size[0] * bbVol->size[1] * bbVol->size[2] * bbVol->size[3];
        idx = bar->size[0] * bar->size[1];
        for (ixstart = 0; ixstart < idx; ixstart++) {
          s = bar->data[ixstart] + r0->data[ixstart];
          if (s != (int32_T)muDoubleScalarFloor(s)) {
            emlrtIntegerCheckR2012b(s, &emlrtDCI, sp);
          }

          nm1d2 = (int32_T)s;
          if (!((nm1d2 >= 1) && (nm1d2 <= nx))) {
            emlrtDynamicBoundsCheckR2012b(nm1d2, 1, nx, &e_emlrtBCI, sp);
          }

          a->data[ixstart] = bbVol->data[nm1d2 - 1];
        }

        ixstart = c_bbVol->size[0] * c_bbVol->size[1];
        c_bbVol->size[0] = 1;
        c_bbVol->size[1] = shift_by_channel->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)c_bbVol, ixstart, (int32_T)
                          sizeof(real_T), &b_emlrtRTEI);
        b_boundaries = boundaries->data[kk];
        nx = bbVol->size[0] * bbVol->size[1] * bbVol->size[2] * bbVol->size[3];
        idx = shift_by_channel->size[0] * shift_by_channel->size[1];
        for (ixstart = 0; ixstart < idx; ixstart++) {
          s = shift_by_channel->data[ixstart] + b_boundaries;
          if (s != (int32_T)muDoubleScalarFloor(s)) {
            emlrtIntegerCheckR2012b(s, &b_emlrtDCI, sp);
          }

          nm1d2 = (int32_T)s;
          if (!((nm1d2 >= 1) && (nm1d2 <= nx))) {
            emlrtDynamicBoundsCheckR2012b(nm1d2, 1, nx, &f_emlrtBCI, sp);
          }

          c_bbVol->data[ixstart] = bbVol->data[nm1d2 - 1];
        }

        b_validIdx[0] = validIdx_size[0];
        b_validIdx[1] = 1.0;
        st.site = &g_emlrtRSI;
        b_repmat(&st, c_bbVol, b_validIdx, r1);
        for (ixstart = 0; ixstart < 2; ixstart++) {
          iv9[ixstart] = r1->size[ixstart];
        }

        emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])bar->size, iv9, &b_emlrtECI,
          sp);
        st.site = &g_emlrtRSI;
        ixstart = a->size[0] * a->size[1];
        emxEnsureCapacity(&st, (emxArray__common *)a, ixstart, (int32_T)sizeof
                          (real_T), &b_emlrtRTEI);
        nm1d2 = a->size[0];
        nx = a->size[1];
        idx = nm1d2 * nx;
        for (ixstart = 0; ixstart < idx; ixstart++) {
          a->data[ixstart] -= r1->data[ixstart];
        }

        b_st.site = &ib_emlrtRSI;
        c_st.site = &jb_emlrtRSI;
        d_st.site = &kb_emlrtRSI;
        for (ixstart = 0; ixstart < 2; ixstart++) {
          iv10[ixstart] = a->size[ixstart];
        }

        ixstart = bar->size[0] * bar->size[1];
        bar->size[0] = iv10[0];
        bar->size[1] = iv10[1];
        emxEnsureCapacity(&d_st, (emxArray__common *)bar, ixstart, (int32_T)
                          sizeof(real_T), &g_emlrtRTEI);
        if (dimagree(bar, a)) {
        } else {
          emlrtErrorWithMessageIdR2012b(&d_st, &q_emlrtRTEI, "MATLAB:dimagree",
            0);
        }

        nm1d2 = a->size[0] * a->size[1];
        d_st.site = &lb_emlrtRSI;
        if (1 > nm1d2) {
          b2 = false;
        } else {
          b2 = (nm1d2 > 2147483646);
        }

        if (b2) {
          e_st.site = &m_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }

        for (k = 0; k + 1 <= nm1d2; k++) {
          bar->data[k] = a->data[k] * a->data[k];
        }

        st.site = &g_emlrtRSI;
        b_st.site = &mb_emlrtRSI;
        c_st.site = &nb_emlrtRSI;
        varargin_1_size_idx_0 = bar->size[0];
        if (bar->size[1] == 0) {
          for (ixstart = 0; ixstart < varargin_1_size_idx_0; ixstart++) {
            varargin_1_data[ixstart] = 0.0;
          }
        } else {
          nx = bar->size[1];
          idx = bar->size[0];
          nm1d2 = -1;
          ixstart = -1;
          d_st.site = &ob_emlrtRSI;
          for (apnd = 1; apnd <= idx; apnd++) {
            ixstart++;
            ix = ixstart;
            s = bar->data[ixstart];
            d_st.site = &pb_emlrtRSI;
            if (2 > nx) {
              b3 = false;
            } else {
              b3 = (nx > 2147483646);
            }

            if (b3) {
              e_st.site = &m_emlrtRSI;
              check_forloop_overflow_error(&e_st);
            }

            for (k = 2; k <= nx; k++) {
              ix += idx;
              s += bar->data[ix];
            }

            nm1d2++;
            varargin_1_data[nm1d2] = s;
          }
        }

        st.site = &g_emlrtRSI;
        b_st.site = &qb_emlrtRSI;
        c_st.site = &rb_emlrtRSI;
        ixstart = 1;
        s = varargin_1_data[0];
        nx = 1;
        if (varargin_1_size_idx_0 > 1) {
          if (muDoubleScalarIsNaN(varargin_1_data[0])) {
            ix = 2;
            exitg2 = false;
            while ((!exitg2) && (ix <= varargin_1_size_idx_0)) {
              ixstart = ix;
              if (!muDoubleScalarIsNaN(varargin_1_data[ix - 1])) {
                s = varargin_1_data[ix - 1];
                nx = ix;
                exitg2 = true;
              } else {
                ix++;
              }
            }
          }

          if (ixstart < varargin_1_size_idx_0) {
            while (ixstart + 1 <= varargin_1_size_idx_0) {
              if (varargin_1_data[ixstart] < s) {
                s = varargin_1_data[ixstart];
                nx = ixstart + 1;
              }

              ixstart++;
            }
          }
        }

        /*  the indices of the minimum of the normed values */
        ixstart = L->size[0] * L->size[1] * L->size[2];
        if (!((nx >= 1) && (nx <= validIdx_size[0]))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, validIdx_size[0], &h_emlrtBCI, sp);
        }

        nm1d2 = (int32_T)validIdx_data[nx - 1];
        if (!((nm1d2 >= 1) && (nm1d2 <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(nm1d2, 1, ixstart, &g_emlrtBCI, sp);
        }

        ixstart = newBoundaryAssignments->size[0];
        nx = 1 + kk;
        if (!((nx >= 1) && (nx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(nx, 1, ixstart, &i_emlrtBCI, sp);
        }

        newBoundaryAssignments->data[nx - 1] = L->data[nm1d2 - 1];

        /*  isn't this potentially assigning a vector to a 1x1 spot? */
      }

      kk++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    nx = L->size[0] * L->size[1] * L->size[2];
    ixstart = ii->size[0];
    ii->size[0] = boundaries->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)ii, ixstart, (int32_T)sizeof
                      (int32_T), &b_emlrtRTEI);
    idx = boundaries->size[0];
    for (ixstart = 0; ixstart < idx; ixstart++) {
      nm1d2 = (int32_T)boundaries->data[ixstart];
      if (!((nm1d2 >= 1) && (nm1d2 <= nx))) {
        emlrtDynamicBoundsCheckR2012b(nm1d2, 1, nx, &c_emlrtBCI, sp);
      }

      ii->data[ixstart] = nm1d2;
    }

    ixstart = ii->size[0];
    nm1d2 = newBoundaryAssignments->size[0];
    if (ixstart != nm1d2) {
      emlrtSizeEqCheck1DR2012b(ixstart, nm1d2, &emlrtECI, sp);
    }

    idx = newBoundaryAssignments->size[0];
    for (ixstart = 0; ixstart < idx; ixstart++) {
      L->data[ii->data[ixstart] - 1] = (uint32_T)muDoubleScalarRound
        (newBoundaryAssignments->data[ixstart]);
    }

    st.site = &h_emlrtRSI;
    ixstart = x->size[0] * x->size[1] * x->size[2];
    x->size[0] = L->size[0];
    x->size[1] = L->size[1];
    x->size[2] = L->size[2];
    emxEnsureCapacity(&st, (emxArray__common *)x, ixstart, (int32_T)sizeof
                      (boolean_T), &b_emlrtRTEI);
    idx = L->size[0] * L->size[1] * L->size[2];
    for (ixstart = 0; ixstart < idx; ixstart++) {
      x->data[ixstart] = (L->data[ixstart] == 0U);
    }

    b_st.site = &j_emlrtRSI;
    nx = x->size[0] * x->size[1] * x->size[2];
    idx = 0;
    if ((!(((x->size[0] == 1) || (x->size[1] == 1)) && (x->size[2] == 1))) ||
        (x->size[0] != 1) || (x->size[1] <= 1)) {
      b0 = true;
    } else {
      b0 = false;
    }

    if (b0) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &s_emlrtRTEI,
        "Coder:toolbox:find_incompatibleShape", 0);
    }

    ixstart = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, ixstart, (int32_T)sizeof
                      (int32_T), &b_emlrtRTEI);
    c_st.site = &k_emlrtRSI;
    if (1 > nx) {
      b4 = false;
    } else {
      b4 = (nx > 2147483646);
    }

    if (b4) {
      d_st.site = &m_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    nm1d2 = 1;
    exitg1 = false;
    while ((!exitg1) && (nm1d2 <= nx)) {
      guard1 = false;
      if (x->data[nm1d2 - 1]) {
        idx++;
        ii->data[idx - 1] = nm1d2;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        nm1d2++;
      }
    }

    if (idx <= nx) {
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (nx == 1) {
      if (idx == 0) {
        ixstart = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)ii, ixstart, (int32_T)
                          sizeof(int32_T), &b_emlrtRTEI);
      }
    } else {
      if (1 > idx) {
        ixstart = 0;
      } else {
        ixstart = idx;
      }

      iv12[0] = 1;
      iv12[1] = ixstart;
      c_st.site = &l_emlrtRSI;
      indexShapeCheck(&c_st, ii->size[0], iv12);
      nm1d2 = ii->size[0];
      ii->size[0] = ixstart;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, nm1d2, (int32_T)sizeof
                        (int32_T), &f_emlrtRTEI);
    }

    ixstart = boundaries->size[0];
    boundaries->size[0] = ii->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)boundaries, ixstart, (int32_T)
                      sizeof(real_T), &b_emlrtRTEI);
    idx = ii->size[0];
    for (ixstart = 0; ixstart < idx; ixstart++) {
      boundaries->data[ixstart] = ii->data[ixstart];
    }

    iv10[0] = boundaries->size[0];
    ixstart = newBoundaryAssignments->size[0];
    newBoundaryAssignments->size[0] = iv10[0];
    emxEnsureCapacity(sp, (emxArray__common *)newBoundaryAssignments, ixstart,
                      (int32_T)sizeof(real_T), &b_emlrtRTEI);
    idx = iv10[0];
    for (ixstart = 0; ixstart < idx; ixstart++) {
      newBoundaryAssignments->data[ixstart] = 0.0;
    }

    iterCount++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&c_bbVol);
  emxFree_real_T(&a);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&r1);
  emxFree_real_T(&r0);
  emxFree_real_T(&bar);
  emxFree_real_T(&validIdxs);
  emxFree_real_T(&shift_by_channel);
  emxFree_real_T(&newBoundaryAssignments);
  emxFree_real_T(&boundaries);
  st.site = &i_emlrtRSI;
  s = muDoubleScalarRound(iterCount);
  if (s < 128.0) {
    i1 = (int8_T)s;
  } else {
    i1 = MAX_int8_T;
  }

  b_st.site = &sb_emlrtRSI;
  s = b_fprintf(&b_st, i1);
  emlrtDisplayR2012b(emlrt_marshallOut(s), "ans", &emlrtRTEI, sp);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (assign6BoundariesNB.c) */
