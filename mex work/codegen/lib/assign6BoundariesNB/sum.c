/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sum.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Dec-2015 14:45:42
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "assign6BoundariesNB.h"
#include "sum.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Arguments    : const double x[78]
 *                double y[26]
 * Return Type  : void
 */
void sum(const double x[78], double y[26])
{
  int iy;
  int ixstart;
  int j;
  int ix;
  double s;
  int k;
  iy = -1;
  ixstart = -1;
  for (j = 0; j < 26; j++) {
    ixstart++;
    ix = ixstart;
    s = x[ixstart];
    for (k = 0; k < 2; k++) {
      ix += 26;
      s += x[ix];
    }

    iy++;
    y[iy] = s;
  }
}

/*
 * File trailer for sum.c
 *
 * [EOF]
 */
