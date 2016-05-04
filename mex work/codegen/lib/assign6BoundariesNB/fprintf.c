/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fprintf.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 21-Dec-2015 14:45:42
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "assign6BoundariesNB.h"
#include "fprintf.h"
#include "fileManager.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Arguments    : signed char varargin_1
 * Return Type  : double
 */
double b_fprintf(signed char varargin_1)
{
  int nbytesint;
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[52] = { '\x0a', 'a', 's', 's', 'i', 'g', 'n', '6', 'b',
    'o', 'u', 'n', 'd', 'a', 'r', 'i', 'e', 's', ' ', 'c', 'o', 'n', 'v', 'e',
    'r', 'g', 'e', 'd', ' ', 'a', 'f', 't', 'e', 'r', ' ', '%', 'd', ' ', 'i',
    't', 'e', 'r', 'a', 't', 'i', 'o', 'n', 's', '.', '\x0a', '\x0a', '\x00' };

  nbytesint = 0;
  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    nbytesint = fprintf(filestar, cfmt, varargin_1);
    fflush(filestar);
  }

  return nbytesint;
}

/*
 * File trailer for fprintf.c
 *
 * [EOF]
 */
