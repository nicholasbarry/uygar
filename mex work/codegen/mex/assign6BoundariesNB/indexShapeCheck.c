/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * indexShapeCheck.c
 *
 * Code generation for function 'indexShapeCheck'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "assign6BoundariesNB.h"
#include "indexShapeCheck.h"

/* Variable Definitions */
static emlrtRSInfo n_emlrtRSI = { 18, "indexShapeCheck",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"
};

static emlrtRSInfo fb_emlrtRSI = { 14, "indexShapeCheck",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"
};

static emlrtRSInfo gb_emlrtRSI = { 80, "indexShapeCheck",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"
};

static emlrtRTEInfo n_emlrtRTEI = { 85, 5, "indexShapeCheck",
  "/Applications/MIT/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"
};

/* Function Definitions */
void b_indexShapeCheck(const emlrtStack *sp, const int32_T matrixSize[3],
  int32_T indexSize)
{
  boolean_T nonSingletonDimFound;
  boolean_T guard1 = false;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nonSingletonDimFound = false;
  if (matrixSize[0] != 1) {
    nonSingletonDimFound = true;
  }

  guard1 = false;
  if (matrixSize[1] != 1) {
    if (nonSingletonDimFound) {
      nonSingletonDimFound = false;
    } else {
      nonSingletonDimFound = true;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (matrixSize[2] != 1) {
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
      } else {
        nonSingletonDimFound = true;
      }
    }
  }

  if (nonSingletonDimFound) {
    nonSingletonDimFound = false;
    if (indexSize != 1) {
      nonSingletonDimFound = true;
    }

    if (nonSingletonDimFound) {
      st.site = &fb_emlrtRSI;
      if (((matrixSize[0] == 1) != (indexSize == 1)) || (matrixSize[1] != 1)) {
        nonSingletonDimFound = true;
      } else {
        nonSingletonDimFound = false;
      }

      if (nonSingletonDimFound || (matrixSize[2] != 1)) {
        nonSingletonDimFound = true;
      }

      b_st.site = &gb_emlrtRSI;
      if (!nonSingletonDimFound) {
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &n_emlrtRTEI,
          "Coder:FE:PotentialMatrixMatrix", 0);
      }
    }
  }
}

void c_indexShapeCheck(const emlrtStack *sp, const int32_T matrixSize[4], const
  int32_T indexSize[2])
{
  boolean_T nonSingletonDimFound;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nonSingletonDimFound = false;
  if (matrixSize[0] != 1) {
    nonSingletonDimFound = true;
  }

  guard1 = false;
  guard2 = false;
  if (matrixSize[1] != 1) {
    if (nonSingletonDimFound) {
      nonSingletonDimFound = false;
    } else {
      nonSingletonDimFound = true;
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2) {
    if (matrixSize[2] != 1) {
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
      } else {
        nonSingletonDimFound = true;
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    if (matrixSize[3] != 1) {
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
      } else {
        nonSingletonDimFound = true;
      }
    }
  }

  if (nonSingletonDimFound) {
    nonSingletonDimFound = false;
    if (indexSize[0] != 1) {
      nonSingletonDimFound = true;
    }

    if (indexSize[1] != 1) {
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
      } else {
        nonSingletonDimFound = true;
      }
    }

    if (nonSingletonDimFound) {
      st.site = &fb_emlrtRSI;
      nonSingletonDimFound = ((matrixSize[0] == 1) != (indexSize[0] == 1));
      if (nonSingletonDimFound || ((matrixSize[1] == 1) != (indexSize[1] == 1)))
      {
        nonSingletonDimFound = true;
      }

      if (nonSingletonDimFound || (matrixSize[2] != 1)) {
        nonSingletonDimFound = true;
      } else {
        nonSingletonDimFound = false;
      }

      if (nonSingletonDimFound || (matrixSize[3] != 1)) {
        nonSingletonDimFound = true;
      }

      b_st.site = &gb_emlrtRSI;
      if (!nonSingletonDimFound) {
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &n_emlrtRTEI,
          "Coder:FE:PotentialMatrixMatrix", 0);
      }
    }
  }
}

void indexShapeCheck(const emlrtStack *sp, int32_T matrixSize, const int32_T
                     indexSize[2])
{
  boolean_T guard1 = false;
  boolean_T nonSingletonDimFound;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  guard1 = false;
  if (!(matrixSize != 1)) {
    nonSingletonDimFound = false;
    if (indexSize[0] != 1) {
      nonSingletonDimFound = true;
    }

    if (indexSize[1] != 1) {
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
      } else {
        nonSingletonDimFound = true;
      }
    }

    if (nonSingletonDimFound) {
      nonSingletonDimFound = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    nonSingletonDimFound = false;
  }

  st.site = &n_emlrtRSI;
  if (!nonSingletonDimFound) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &n_emlrtRTEI,
      "Coder:FE:PotentialVectorVector", 0);
  }
}

/* End of code generation (indexShapeCheck.c) */
