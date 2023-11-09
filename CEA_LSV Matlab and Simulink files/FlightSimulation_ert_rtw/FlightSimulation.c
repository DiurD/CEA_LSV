/*
 * FlightSimulation.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "FlightSimulation".
 *
 * Model version              : 2.0
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Mon Aug 22 21:46:49 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FlightSimulation.h"
#include "FlightSimulation_private.h"

/* Block signals (default storage) */
B_FlightSimulation_T FlightSimulation_B;

/* Continuous states */
X_FlightSimulation_T FlightSimulation_X;

/* Block states (default storage) */
DW_FlightSimulation_T FlightSimulation_DW;

/* External inputs (root inport signals with default storage) */
ExtU_FlightSimulation_T FlightSimulation_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_FlightSimulation_T FlightSimulation_Y;

/* Real-time model */
static RT_MODEL_FlightSimulation_T FlightSimulation_M_;
RT_MODEL_FlightSimulation_T *const FlightSimulation_M = &FlightSimulation_M_;

/* Forward declaration for local functions */
static void rt_mldivide_U1d3x3_U2d_9O8lG8_l(const real_T u0[9], const real_T u1
  [3], real_T y[3]);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  FlightSimulation_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  FlightSimulation_step();
  FlightSimulation_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  FlightSimulation_step();
  FlightSimulation_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int16_T u0_0;
  int16_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static void rt_mldivide_U1d3x3_U2d_9O8lG8_l(const real_T u0[9], const real_T u1
  [3], real_T y[3])
{
  real_T a21;
  real_T maxval;
  int16_T r1;
  int16_T r2;
  int16_T r3;
  int16_T rtemp;
  memcpy(&FlightSimulation_B.A[0], &u0[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = fabs(u0[0]);
  a21 = fabs(u0[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(u0[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  FlightSimulation_B.A[r2] = u0[r2] / u0[r1];
  FlightSimulation_B.A[r3] /= FlightSimulation_B.A[r1];
  FlightSimulation_B.A[r2 + 3] -= FlightSimulation_B.A[r1 + 3] *
    FlightSimulation_B.A[r2];
  FlightSimulation_B.A[r3 + 3] -= FlightSimulation_B.A[r1 + 3] *
    FlightSimulation_B.A[r3];
  FlightSimulation_B.A[r2 + 6] -= FlightSimulation_B.A[r1 + 6] *
    FlightSimulation_B.A[r2];
  FlightSimulation_B.A[r3 + 6] -= FlightSimulation_B.A[r1 + 6] *
    FlightSimulation_B.A[r3];
  if (fabs(FlightSimulation_B.A[r3 + 3]) > fabs(FlightSimulation_B.A[r2 + 3])) {
    rtemp = r2 + 1;
    r2 = r3;
    r3 = rtemp - 1;
  }

  FlightSimulation_B.A[r3 + 3] /= FlightSimulation_B.A[r2 + 3];
  FlightSimulation_B.A[r3 + 6] -= FlightSimulation_B.A[r3 + 3] *
    FlightSimulation_B.A[r2 + 6];
  y[1] = u1[r2] - u1[r1] * FlightSimulation_B.A[r2];
  y[2] = (u1[r3] - u1[r1] * FlightSimulation_B.A[r3]) - FlightSimulation_B.A[r3
    + 3] * y[1];
  y[2] /= FlightSimulation_B.A[r3 + 6];
  y[0] = u1[r1] - FlightSimulation_B.A[r1 + 6] * y[2];
  y[1] -= FlightSimulation_B.A[r2 + 6] * y[2];
  y[1] /= FlightSimulation_B.A[r2 + 3];
  y[0] -= FlightSimulation_B.A[r1 + 3] * y[1];
  y[0] /= FlightSimulation_B.A[r1];
}

/* Model step function */
void FlightSimulation_step(void)
{
  if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    /* set solver stop time */
    if (!(FlightSimulation_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&FlightSimulation_M->solverInfo,
                            ((FlightSimulation_M->Timing.clockTickH0 + 1) *
        FlightSimulation_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&FlightSimulation_M->solverInfo,
                            ((FlightSimulation_M->Timing.clockTick0 + 1) *
        FlightSimulation_M->Timing.stepSize0 +
        FlightSimulation_M->Timing.clockTickH0 *
        FlightSimulation_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(FlightSimulation_M)) {
    FlightSimulation_M->Timing.t[0] = rtsiGetT(&FlightSimulation_M->solverInfo);
  }

  {
    codertarget_arduinobase_inter_T *obj;
    real_T rad2deg_tmp_tmp;
    real_T rtb_Add;
    real_T *lastU;
    int16_T iU;
    uint16_T rtb_AnalogInput_0;

    /* SignalConversion generated from: '<S22>/Trigonometric Function' incorporates:
     *  Integrator: '<S16>/PHI_rad'
     *  Integrator: '<S16>/PSI_rad'
     *  Integrator: '<S16>/THETA_rad'
     */
    FlightSimulation_B.rad2deg1[0] = FlightSimulation_X.PHI_rad;
    FlightSimulation_B.rad2deg1[1] = FlightSimulation_X.THETA_rad;
    FlightSimulation_B.rad2deg1[2] = FlightSimulation_X.PSI_rad;

    /* SignalConversion generated from: '<S27>/ SFunction ' incorporates:
     *  MATLAB Function: '<S23>/MATLAB Function'
     *  MATLAB Function: '<S23>/MATLAB Function1'
     *  MATLAB Function: '<S23>/MATLAB Function2'
     *  MATLAB Function: '<S23>/MATLAB Function3'
     *  MATLAB Function: '<S23>/MATLAB Function4'
     *  MATLAB Function: '<S23>/MATLAB Function5'
     *  MATLAB Function: '<S23>/MATLAB Function7'
     *  MATLAB Function: '<S23>/MATLAB Function8'
     *  SignalConversion generated from: '<S28>/ SFunction '
     *  SignalConversion generated from: '<S29>/ SFunction '
     *  SignalConversion generated from: '<S30>/ SFunction '
     *  SignalConversion generated from: '<S31>/ SFunction '
     *  SignalConversion generated from: '<S32>/ SFunction '
     *  SignalConversion generated from: '<S34>/ SFunction '
     *  SignalConversion generated from: '<S35>/ SFunction '
     *  Trigonometry: '<S23>/Trigonometric Function'
     */
    FlightSimulation_B.Add_f[0] = sin(FlightSimulation_B.rad2deg1[0]);
    FlightSimulation_B.Add_f[3] = cos(FlightSimulation_B.rad2deg1[0]);

    /* Trigonometry: '<S23>/Trigonometric Function' */
    FlightSimulation_B.TAS_mps = sin(FlightSimulation_B.rad2deg1[1]);

    /* SignalConversion generated from: '<S27>/ SFunction ' incorporates:
     *  MATLAB Function: '<S23>/MATLAB Function'
     *  MATLAB Function: '<S23>/MATLAB Function1'
     *  MATLAB Function: '<S23>/MATLAB Function2'
     *  MATLAB Function: '<S23>/MATLAB Function3'
     *  MATLAB Function: '<S23>/MATLAB Function4'
     *  MATLAB Function: '<S23>/MATLAB Function5'
     *  MATLAB Function: '<S23>/MATLAB Function7'
     *  MATLAB Function: '<S23>/MATLAB Function8'
     *  SignalConversion generated from: '<S28>/ SFunction '
     *  SignalConversion generated from: '<S29>/ SFunction '
     *  SignalConversion generated from: '<S30>/ SFunction '
     *  SignalConversion generated from: '<S31>/ SFunction '
     *  SignalConversion generated from: '<S32>/ SFunction '
     *  SignalConversion generated from: '<S34>/ SFunction '
     *  SignalConversion generated from: '<S35>/ SFunction '
     *  Trigonometry: '<S23>/Trigonometric Function'
     */
    FlightSimulation_B.Add_f[1] = FlightSimulation_B.TAS_mps;
    FlightSimulation_B.Add_f[4] = cos(FlightSimulation_B.rad2deg1[1]);

    /* SignalConversion generated from: '<S33>/ SFunction ' incorporates:
     *  MATLAB Function: '<S23>/MATLAB Function6'
     */
    FlightSimulation_B.Sqrt1 = FlightSimulation_B.TAS_mps;

    /* Trigonometry: '<S23>/Trigonometric Function' */
    FlightSimulation_B.TAS_mps = sin(FlightSimulation_B.rad2deg1[2]);
    FlightSimulation_B.Divide1_h = cos(FlightSimulation_B.rad2deg1[2]);

    /* Math: '<S23>/Math Function' incorporates:
     *  MATLAB Function: '<S23>/MATLAB Function'
     *  MATLAB Function: '<S23>/MATLAB Function3'
     *  MATLAB Function: '<S23>/MATLAB Function6'
     *  SignalConversion generated from: '<S27>/ SFunction '
     *  SignalConversion generated from: '<S30>/ SFunction '
     */
    FlightSimulation_B.MathFunction_c[0] = FlightSimulation_B.Add_f[4] *
      FlightSimulation_B.Divide1_h;
    FlightSimulation_B.MathFunction_c[1] = FlightSimulation_B.TAS_mps *
      FlightSimulation_B.Add_f[4];
    FlightSimulation_B.MathFunction_c[2] = -FlightSimulation_B.Sqrt1;

    /* MATLAB Function: '<S23>/MATLAB Function1' incorporates:
     *  MATLAB Function: '<S23>/MATLAB Function4'
     *  SignalConversion generated from: '<S28>/ SFunction '
     */
    FlightSimulation_B.Sqrt1 = FlightSimulation_B.Add_f[0] *
      FlightSimulation_B.Add_f[1];

    /* Math: '<S23>/Math Function' incorporates:
     *  MATLAB Function: '<S23>/MATLAB Function1'
     *  MATLAB Function: '<S23>/MATLAB Function2'
     *  MATLAB Function: '<S23>/MATLAB Function4'
     *  MATLAB Function: '<S23>/MATLAB Function5'
     *  MATLAB Function: '<S23>/MATLAB Function7'
     *  MATLAB Function: '<S23>/MATLAB Function8'
     *  SignalConversion generated from: '<S28>/ SFunction '
     *  SignalConversion generated from: '<S29>/ SFunction '
     *  SignalConversion generated from: '<S31>/ SFunction '
     *  SignalConversion generated from: '<S32>/ SFunction '
     *  SignalConversion generated from: '<S34>/ SFunction '
     *  SignalConversion generated from: '<S35>/ SFunction '
     */
    FlightSimulation_B.MathFunction_c[3] = FlightSimulation_B.Sqrt1 *
      FlightSimulation_B.Divide1_h - FlightSimulation_B.TAS_mps *
      FlightSimulation_B.Add_f[3];
    FlightSimulation_B.MathFunction_c[4] = FlightSimulation_B.Sqrt1 *
      FlightSimulation_B.TAS_mps + FlightSimulation_B.Add_f[3] *
      FlightSimulation_B.Divide1_h;
    FlightSimulation_B.MathFunction_c[5] = FlightSimulation_B.Add_f[0] *
      FlightSimulation_B.Add_f[4];
    FlightSimulation_B.MathFunction_c[6] = FlightSimulation_B.Add_f[1] *
      FlightSimulation_B.Divide1_h * FlightSimulation_B.Add_f[3] +
      FlightSimulation_B.Add_f[0] * FlightSimulation_B.TAS_mps;
    FlightSimulation_B.MathFunction_c[7] = FlightSimulation_B.Add_f[1] *
      FlightSimulation_B.Add_f[3] * FlightSimulation_B.TAS_mps -
      FlightSimulation_B.Add_f[0] * FlightSimulation_B.Divide1_h;
    FlightSimulation_B.MathFunction_c[8] = FlightSimulation_B.Add_f[3] *
      FlightSimulation_B.Add_f[4];

    /* Integrator: '<S15>/u_mps' */
    FlightSimulation_B.u_mps = FlightSimulation_X.u_mps;

    /* Integrator: '<S15>/w_mps' */
    FlightSimulation_B.w_mps = FlightSimulation_X.w_mps;

    /* Trigonometry: '<S2>/Trigonometric Function1' */
    FlightSimulation_B.TrigonometricFunction1 = rt_atan2d_snf
      (FlightSimulation_B.w_mps, FlightSimulation_B.u_mps);

    /* Gain: '<S2>/rad2deg1' */
    FlightSimulation_B.Alpha_deg = FlightSimulation_P.rad2deg1_Gain *
      FlightSimulation_B.TrigonometricFunction1;

    /* Gain: '<S1>/deg->rad' */
    FlightSimulation_B.degrad = FlightSimulation_P.degrad_Gain *
      FlightSimulation_B.Alpha_deg;

    /* Trigonometry: '<S11>/Cos' */
    FlightSimulation_B.UnaryMinus = cos(FlightSimulation_B.degrad);

    /* Integrator: '<S15>/v_mps' */
    FlightSimulation_B.v_mps = FlightSimulation_X.v_mps;

    /* Sqrt: '<S2>/Sqrt' incorporates:
     *  Math: '<S2>/Math Function1'
     *  Math: '<S2>/Math Function2'
     *  Math: '<S2>/Math Function3'
     *  Sum: '<S2>/Add1'
     */
    FlightSimulation_B.TAS_mps = sqrt((FlightSimulation_B.u_mps *
      FlightSimulation_B.u_mps + FlightSimulation_B.v_mps *
      FlightSimulation_B.v_mps) + FlightSimulation_B.w_mps *
      FlightSimulation_B.w_mps);

    /* Saturate: '<S2>/Saturation' */
    if (FlightSimulation_B.TAS_mps > FlightSimulation_P.Saturation_UpperSat) {
      FlightSimulation_B.TAS_mps = FlightSimulation_P.Saturation_UpperSat;
    } else if (FlightSimulation_B.TAS_mps <
               FlightSimulation_P.Saturation_LowerSat) {
      FlightSimulation_B.TAS_mps = FlightSimulation_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* Product: '<S2>/Divide1' */
    FlightSimulation_B.Divide1_h = FlightSimulation_B.v_mps /
      FlightSimulation_B.TAS_mps;

    /* Trigonometry: '<S2>/Trigonometric Function' */
    if (FlightSimulation_B.Divide1_h > 1.0) {
      FlightSimulation_B.Divide1_h = 1.0;
    } else if (FlightSimulation_B.Divide1_h < -1.0) {
      FlightSimulation_B.Divide1_h = -1.0;
    }

    /* Gain: '<S2>/rad2deg' incorporates:
     *  Trigonometry: '<S2>/Trigonometric Function'
     */
    FlightSimulation_B.Beta_deg = FlightSimulation_P.rad2deg_Gain * asin
      (FlightSimulation_B.Divide1_h);

    /* Gain: '<S1>/deg->rad1' */
    FlightSimulation_B.degrad1 = FlightSimulation_P.degrad1_Gain *
      FlightSimulation_B.Beta_deg;

    /* Trigonometry: '<S11>/Cos1' */
    FlightSimulation_B.q_bar_Pa = cos(FlightSimulation_B.degrad1);

    /* Trigonometry: '<S11>/Sin' */
    FlightSimulation_B.Sqrt1 = sin(FlightSimulation_B.degrad);

    /* Trigonometry: '<S11>/Tan' */
    FlightSimulation_B.Divide1_h = tan(FlightSimulation_B.degrad1);

    /* Reshape: '<S11>/Reshape1' incorporates:
     *  Constant: '<S11>/Constant29'
     *  Constant: '<S11>/Constant30'
     *  Constant: '<S11>/Constant31'
     *  Math: '<S11>/Math Function'
     *  Math: '<S11>/Math Function1'
     *  Product: '<S11>/Divide26'
     *  Product: '<S11>/Divide27'
     *  Product: '<S11>/Divide28'
     *  Product: '<S11>/Divide29'
     *  SignalConversion generated from: '<S26>/ SFunction '
     *  UnaryMinus: '<S11>/Unary Minus2'
     *  UnaryMinus: '<S11>/Unary Minus3'
     *  UnaryMinus: '<S11>/Unary Minus4'
     *
     * About '<S11>/Math Function':
     *  Operator: reciprocal
     *
     * About '<S11>/Math Function1':
     *  Operator: reciprocal
     */
    FlightSimulation_B.TmpSignalConversionAtSFunct[0] = 1.0 /
      FlightSimulation_B.q_bar_Pa * FlightSimulation_B.UnaryMinus;
    FlightSimulation_B.TmpSignalConversionAtSFunct[1] =
      FlightSimulation_P.Constant30_Value;
    FlightSimulation_B.TmpSignalConversionAtSFunct[2] = 1.0 /
      FlightSimulation_B.q_bar_Pa * FlightSimulation_B.Sqrt1;
    FlightSimulation_B.TmpSignalConversionAtSFunct[3] =
      -(FlightSimulation_B.UnaryMinus * FlightSimulation_B.Divide1_h);
    FlightSimulation_B.TmpSignalConversionAtSFunct[4] =
      FlightSimulation_P.Constant29_Value;
    FlightSimulation_B.TmpSignalConversionAtSFunct[5] =
      -(FlightSimulation_B.Sqrt1 * FlightSimulation_B.Divide1_h);
    FlightSimulation_B.TmpSignalConversionAtSFunct[6] =
      -FlightSimulation_B.Sqrt1;
    FlightSimulation_B.TmpSignalConversionAtSFunct[7] =
      FlightSimulation_P.Constant31_Value;
    FlightSimulation_B.TmpSignalConversionAtSFunct[8] =
      FlightSimulation_B.UnaryMinus;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
      /* Gain: '<S1>/ft²_to_m²' incorporates:
       *  Constant: '<S1>/Wingspan_ft²'
       */
      FlightSimulation_B.ft_to_m = FlightSimulation_P.ft_to_m_Gain *
        FlightSimulation_P.S_ft2;
    }

    /* Gain: '<S2>/constant' incorporates:
     *  Integrator: '<S18>/ZI_m'
     */
    FlightSimulation_B.Divide1_h = FlightSimulation_P.constant_Gain *
      FlightSimulation_X.ZI_m;

    /* Saturate: '<S12>/Limit to Tropopause' */
    if (FlightSimulation_B.Divide1_h >
        FlightSimulation_P.LimittoTropopause_UpperSat) {
      FlightSimulation_B.Sqrt1 = FlightSimulation_P.LimittoTropopause_UpperSat;
    } else if (FlightSimulation_B.Divide1_h <
               FlightSimulation_P.LimittoTropopause_LowerSat) {
      FlightSimulation_B.Sqrt1 = FlightSimulation_P.LimittoTropopause_LowerSat;
    } else {
      FlightSimulation_B.Sqrt1 = FlightSimulation_B.Divide1_h;
    }

    /* End of Saturate: '<S12>/Limit to Tropopause' */

    /* Sum: '<S12>/Add' incorporates:
     *  Constant: '<S12>/Constant'
     *  Gain: '<S12>/k'
     */
    FlightSimulation_B.Sqrt1 = FlightSimulation_P.k_Gain *
      FlightSimulation_B.Sqrt1 + FlightSimulation_P.Constant_Value;

    /* Gain: '<S12>/1//T0' */
    FlightSimulation_B.MathFunction1_kg = FlightSimulation_P.uT0_Gain *
      FlightSimulation_B.Sqrt1;

    /* Sum: '<S12>/Add1' incorporates:
     *  Constant: '<S12>/Constant1'
     */
    FlightSimulation_B.Divide1_h -= FlightSimulation_P.Constant1_Value;

    /* Math: '<S12>/Math Function' incorporates:
     *  Constant: '<S12>/-g//(k*R)'
     */
    if ((FlightSimulation_B.MathFunction1_kg < 0.0) &&
        (FlightSimulation_P.gkR_Value > floor(FlightSimulation_P.gkR_Value))) {
      FlightSimulation_B.MathFunction1_kg = -rt_powd_snf
        (-FlightSimulation_B.MathFunction1_kg, FlightSimulation_P.gkR_Value);
    } else {
      FlightSimulation_B.MathFunction1_kg = rt_powd_snf
        (FlightSimulation_B.MathFunction1_kg, FlightSimulation_P.gkR_Value);
    }

    /* End of Math: '<S12>/Math Function' */

    /* Saturate: '<S12>/Limit to Tropopause1' */
    if (FlightSimulation_B.Divide1_h >
        FlightSimulation_P.LimittoTropopause1_UpperSat) {
      FlightSimulation_B.Divide1_h =
        FlightSimulation_P.LimittoTropopause1_UpperSat;
    } else if (FlightSimulation_B.Divide1_h <
               FlightSimulation_P.LimittoTropopause1_LowerSat) {
      FlightSimulation_B.Divide1_h =
        FlightSimulation_P.LimittoTropopause1_LowerSat;
    }

    /* End of Saturate: '<S12>/Limit to Tropopause1' */

    /* Product: '<S12>/Divide1' incorporates:
     *  Constant: '<S12>/-g//R'
     *  Gain: '<S12>/P0_Pa'
     *  Math: '<S12>/Math Function1'
     *  Product: '<S12>/Divide3'
     *  Product: '<S12>/Divide4'
     *
     * About '<S12>/Math Function1':
     *  Operator: exp
     */
    FlightSimulation_B.Divide1_h = exp(FlightSimulation_P.gR_Value /
      FlightSimulation_B.Sqrt1 * FlightSimulation_B.Divide1_h) *
      (FlightSimulation_P.P0_Pa_Gain * FlightSimulation_B.MathFunction1_kg);

    /* Product: '<S12>/Divide2' incorporates:
     *  Gain: '<S12>/R'
     */
    FlightSimulation_B.MathFunction1_kg = FlightSimulation_B.Divide1_h /
      (FlightSimulation_P.R_Gain * FlightSimulation_B.Sqrt1);

    /* Product: '<S1>/Divide' incorporates:
     *  Constant: '<S1>/Constant'
     */
    FlightSimulation_B.q_bar_Pa = FlightSimulation_B.TAS_mps *
      FlightSimulation_B.TAS_mps * FlightSimulation_B.MathFunction1_kg /
      FlightSimulation_P.Constant_Value_h;

    /* Gain: '<S1>/deg->rad2' incorporates:
     *  Inport: '<Root>/Aileron_deg'
     *  Inport: '<Root>/Elevator_deg'
     *  Inport: '<Root>/Rudder_deg'
     */
    FlightSimulation_B.TrigonometricFunction_o1[0] =
      FlightSimulation_P.degrad2_Gain * FlightSimulation_U.Elevator_deg;
    FlightSimulation_B.TrigonometricFunction_o1[1] =
      FlightSimulation_P.degrad2_Gain * FlightSimulation_U.Aileron_deg;
    FlightSimulation_B.TrigonometricFunction_o1[2] =
      FlightSimulation_P.degrad2_Gain * FlightSimulation_U.Rudder_deg;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
      /* Gain: '<S1>/ft_to_m' incorporates:
       *  Constant: '<S1>/b_ft'
       */
      FlightSimulation_B.ft_to_m_b = FlightSimulation_P.ft_to_m_Gain_a *
        FlightSimulation_P.b_ft;
    }

    /* Product: '<S1>/Divide32' incorporates:
     *  Constant: '<S1>/Constant32'
     *  Integrator: '<S14>/p_radps'
     */
    FlightSimulation_B.Product3 = FlightSimulation_X.p_radps *
      FlightSimulation_B.ft_to_m_b / FlightSimulation_B.TAS_mps /
      FlightSimulation_P.Constant32_Value;

    /* Product: '<S1>/Divide33' incorporates:
     *  Constant: '<S1>/Constant33'
     *  Integrator: '<S14>/r_radps'
     */
    FlightSimulation_B.Gain_k = FlightSimulation_X.r_radps *
      FlightSimulation_B.ft_to_m_b / FlightSimulation_B.TAS_mps /
      FlightSimulation_P.Constant33_Value;

    /* Sum: '<S7>/Add3' incorporates:
     *  Gain: '<S7>/Gain'
     *  Gain: '<S7>/Gain1'
     *  Gain: '<S7>/Gain2'
     *  Gain: '<S7>/Gain3'
     *  Gain: '<S7>/Gain4'
     */
    FlightSimulation_B.Product5 = (((FlightSimulation_P.C_Ybeta *
      FlightSimulation_B.degrad1 + FlightSimulation_P.C_YdeltaA *
      FlightSimulation_B.TrigonometricFunction_o1[1]) +
      FlightSimulation_P.C_YdeltaR *
      FlightSimulation_B.TrigonometricFunction_o1[2]) + FlightSimulation_P.C_Yp *
      FlightSimulation_B.Product3) + FlightSimulation_P.C_Yr *
      FlightSimulation_B.Gain_k;

    /* Derivative: '<S2>/Derivative' */
    FlightSimulation_B.UnaryMinus = FlightSimulation_M->Timing.t[0];
    if ((FlightSimulation_DW.TimeStampA >= FlightSimulation_B.UnaryMinus) &&
        (FlightSimulation_DW.TimeStampB >= FlightSimulation_B.UnaryMinus)) {
      /* Derivative: '<S2>/Derivative' */
      FlightSimulation_B.AlphaDot_radps = 0.0;
    } else {
      FlightSimulation_B.Abs = FlightSimulation_DW.TimeStampA;
      lastU = &FlightSimulation_DW.LastUAtTimeA;
      if (FlightSimulation_DW.TimeStampA < FlightSimulation_DW.TimeStampB) {
        if (FlightSimulation_DW.TimeStampB < FlightSimulation_B.UnaryMinus) {
          FlightSimulation_B.Abs = FlightSimulation_DW.TimeStampB;
          lastU = &FlightSimulation_DW.LastUAtTimeB;
        }
      } else if (FlightSimulation_DW.TimeStampA >= FlightSimulation_B.UnaryMinus)
      {
        FlightSimulation_B.Abs = FlightSimulation_DW.TimeStampB;
        lastU = &FlightSimulation_DW.LastUAtTimeB;
      }

      /* Derivative: '<S2>/Derivative' */
      FlightSimulation_B.AlphaDot_radps =
        (FlightSimulation_B.TrigonometricFunction1 - *lastU) /
        (FlightSimulation_B.UnaryMinus - FlightSimulation_B.Abs);
    }

    /* End of Derivative: '<S2>/Derivative' */
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
      /* Gain: '<S1>/ft_to_m   2' incorporates:
       *  Constant: '<S1>/mean_c_ft'
       */
      FlightSimulation_B.ft_to_m2 = FlightSimulation_P.ft_to_m2_Gain *
        FlightSimulation_P.mean_c_ft;
    }

    /* Product: '<S1>/Divide35' incorporates:
     *  Constant: '<S1>/Constant35'
     */
    FlightSimulation_B.UnaryMinus = FlightSimulation_B.AlphaDot_radps *
      FlightSimulation_B.ft_to_m2 / FlightSimulation_B.TAS_mps /
      FlightSimulation_P.Constant35_Value;

    /* Product: '<S1>/Divide34' incorporates:
     *  Constant: '<S1>/Constant34'
     *  Integrator: '<S14>/q_radps'
     */
    FlightSimulation_B.Abs = FlightSimulation_X.q_radps *
      FlightSimulation_B.ft_to_m2 / FlightSimulation_B.TAS_mps /
      FlightSimulation_P.Constant34_Value;

    /* Sum: '<S6>/Add' incorporates:
     *  Constant: '<S6>/Constant1'
     *  Gain: '<S6>/Gain'
     *  Gain: '<S6>/Gain1'
     *  Gain: '<S6>/Gain2'
     *  Gain: '<S6>/Gain3'
     */
    rtb_Add = (((FlightSimulation_P.C_Lalpha * FlightSimulation_B.degrad +
                 FlightSimulation_P.C_L0) + FlightSimulation_P.C_LdeltaE *
                FlightSimulation_B.TrigonometricFunction_o1[0]) +
               FlightSimulation_P.C_Lalphadot * FlightSimulation_B.UnaryMinus) +
      FlightSimulation_P.C_Lq * FlightSimulation_B.Abs;

    /* Product: '<S1>/Divide36' incorporates:
     *  Constant: '<S9>/Constant9'
     *  Gain: '<S10>/Gain'
     *  Gain: '<S10>/Gain1'
     *  Gain: '<S10>/Gain2'
     *  Gain: '<S10>/Gain3'
     *  Gain: '<S10>/Gain4'
     *  Gain: '<S8>/Gain'
     *  Gain: '<S8>/Gain1'
     *  Gain: '<S8>/Gain2'
     *  Gain: '<S8>/Gain3'
     *  Gain: '<S8>/Gain4'
     *  Gain: '<S9>/Gain'
     *  Gain: '<S9>/Gain1'
     *  Gain: '<S9>/Gain2'
     *  Gain: '<S9>/Gain3'
     *  SignalConversion generated from: '<S18>/Product'
     *  Sum: '<S10>/Add5'
     *  Sum: '<S8>/Add4'
     *  Sum: '<S9>/Add2'
     */
    rad2deg_tmp_tmp = FlightSimulation_B.ft_to_m * FlightSimulation_B.q_bar_Pa;
    FlightSimulation_B.rad2deg[0] = ((((FlightSimulation_P.C_lbeta *
      FlightSimulation_B.degrad1 + FlightSimulation_P.C_ldeltaA *
      FlightSimulation_B.TrigonometricFunction_o1[1]) +
      FlightSimulation_P.C_ldeltaR *
      FlightSimulation_B.TrigonometricFunction_o1[2]) + FlightSimulation_P.C_lp *
      FlightSimulation_B.Product3) + FlightSimulation_P.C_lr *
      FlightSimulation_B.Gain_k) * rad2deg_tmp_tmp;
    FlightSimulation_B.rad2deg[1] = ((((FlightSimulation_P.C_malpha *
      FlightSimulation_B.degrad + FlightSimulation_P.C_m0) +
      FlightSimulation_P.C_mdeltaE *
      FlightSimulation_B.TrigonometricFunction_o1[0]) +
      FlightSimulation_P.C_malphadot * FlightSimulation_B.UnaryMinus) +
      FlightSimulation_P.C_mq * FlightSimulation_B.Abs) * rad2deg_tmp_tmp;
    FlightSimulation_B.rad2deg[2] = ((((FlightSimulation_P.C_nbeta *
      FlightSimulation_B.degrad1 + FlightSimulation_P.C_ndeltaA *
      FlightSimulation_B.TrigonometricFunction_o1[1]) +
      FlightSimulation_P.C_ndeltaR *
      FlightSimulation_B.TrigonometricFunction_o1[2]) + FlightSimulation_P.C_np *
      FlightSimulation_B.Product3) + FlightSimulation_P.C_nr *
      FlightSimulation_B.Gain_k) * rad2deg_tmp_tmp;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
      /* Trigonometry: '<S4>/Cos' incorporates:
       *  Constant: '<S4>/eta_T_deg'
       */
      FlightSimulation_B.Cos = cos(FlightSimulation_P.eta_T_deg);

      /* MATLABSystem: '<Root>/Analog Input' */
      if (FlightSimulation_DW.obj.SampleTime !=
          FlightSimulation_P.AnalogInput_SampleTime) {
        FlightSimulation_DW.obj.SampleTime =
          FlightSimulation_P.AnalogInput_SampleTime;
      }

      obj = &FlightSimulation_DW.obj;
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
      MW_AnalogInSingle_ReadResult
        (FlightSimulation_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
         &rtb_AnalogInput_0, 3);

      /* Gain: '<Root>/Gain' incorporates:
       *  MATLABSystem: '<Root>/Analog Input'
       */
      FlightSimulation_B.Gain = (uint32_T)FlightSimulation_P.Gain_Gain_o *
        rtb_AnalogInput_0;

      /* Trigonometry: '<S4>/Sin' incorporates:
       *  Constant: '<S4>/eta_T_deg'
       */
      FlightSimulation_B.Sin = sin(FlightSimulation_P.eta_T_deg);
    }

    /* Product: '<S4>/Divide' incorporates:
     *  Constant: '<S4>/Max_Thrust_N'
     *  Constant: '<S4>/V_ref_mps'
     *  Constant: '<S4>/n_rho'
     *  Constant: '<S4>/n_v'
     *  Constant: '<S4>/rho_ref_kgpm³'
     *  Gain: '<Root>/Gain'
     *  Math: '<S4>/Math Function'
     *  Math: '<S4>/Math Function1'
     *  Product: '<S4>/Divide1'
     *  Product: '<S4>/Divide2'
     */
    FlightSimulation_B.T_N = rt_powd_snf(FlightSimulation_B.TAS_mps /
      FlightSimulation_P.V_ref_mps, FlightSimulation_P.n_v) *
      FlightSimulation_P.T_max_N * rt_powd_snf
      (FlightSimulation_B.MathFunction1_kg / FlightSimulation_P.rho_ref_kgpm3,
       FlightSimulation_P.n_rho) * ((real_T)FlightSimulation_B.Gain *
      2.9802322387695312E-8);

    /* Product: '<S1>/Divide31' */
    FlightSimulation_B.UnaryMinus = FlightSimulation_B.ft_to_m *
      FlightSimulation_B.q_bar_Pa;

    /* Product: '<S1>/Divide30' incorporates:
     *  Abs: '<S5>/Abs'
     *  Abs: '<S5>/Abs1'
     *  Constant: '<S5>/Constant6'
     *  Gain: '<S5>/Gain'
     *  Gain: '<S5>/Gain1'
     *  Sum: '<S5>/Add1'
     *  UnaryMinus: '<S1>/Unary Minus'
     */
    FlightSimulation_B.Abs = -((FlightSimulation_P.C_Dalpha * fabs
      (FlightSimulation_B.degrad) + FlightSimulation_P.C_D0) +
      FlightSimulation_P.C_DdeltaE * fabs
      (FlightSimulation_B.TrigonometricFunction_o1[0]));
    for (iU = 0; iU < 3; iU++) {
      /* Sum: '<S17>/Add' incorporates:
       *  Product: '<S1>/Divide31'
       *  Reshape: '<S1>/Reshape'
       *  SignalConversion generated from: '<S26>/ SFunction '
       *  UnaryMinus: '<S1>/Unary Minus1'
       */
      FlightSimulation_B.dv[iU] =
        ((FlightSimulation_B.TmpSignalConversionAtSFunct[iU + 3] *
          FlightSimulation_B.Product5 +
          FlightSimulation_B.TmpSignalConversionAtSFunct[iU] *
          FlightSimulation_B.Abs) +
         FlightSimulation_B.TmpSignalConversionAtSFunct[iU + 6] * -rtb_Add) *
        FlightSimulation_B.UnaryMinus;
    }

    /* End of Product: '<S1>/Divide30' */

    /* Sum: '<S17>/Add' incorporates:
     *  Constant: '<S4>/Constant2'
     *  Constant: '<S4>/Constant3'
     *  Constant: '<S4>/Constant4'
     *  Constant: '<S4>/Constant5'
     *  Product: '<S1>/Divide37'
     *  Product: '<S1>/Divide38'
     *  Product: '<S1>/Divide39'
     *  Product: '<S4>/X_P'
     *  Product: '<S4>/Z_P'
     */
    FlightSimulation_B.dv[3] = FlightSimulation_B.ft_to_m_b *
      FlightSimulation_B.rad2deg[0];
    FlightSimulation_B.dv[4] = FlightSimulation_B.ft_to_m2 *
      FlightSimulation_B.rad2deg[1];
    FlightSimulation_B.dv[5] = FlightSimulation_B.ft_to_m_b *
      FlightSimulation_B.rad2deg[2];
    FlightSimulation_B.dv1[0] = FlightSimulation_B.Cos * FlightSimulation_B.T_N;
    FlightSimulation_B.dv1[1] = FlightSimulation_P.Constant4_Value;
    FlightSimulation_B.dv1[2] = FlightSimulation_B.Sin * FlightSimulation_B.T_N;
    FlightSimulation_B.dv1[3] = FlightSimulation_P.Constant2_Value;
    FlightSimulation_B.dv1[4] = FlightSimulation_P.Constant3_Value;
    FlightSimulation_B.dv1[5] = FlightSimulation_P.Constant5_Value;
    for (iU = 0; iU < 6; iU++) {
      FlightSimulation_B.Add_f[iU] = FlightSimulation_B.dv[iU] +
        FlightSimulation_B.dv1[iU];
    }

    /* Saturate: '<Root>/Saturation' incorporates:
     *  Inport: '<Root>/Mass_kg'
     */
    if (FlightSimulation_U.Mass_kg > FlightSimulation_P.Saturation_UpperSat_l) {
      FlightSimulation_B.Abs = FlightSimulation_P.Saturation_UpperSat_l;
    } else if (FlightSimulation_U.Mass_kg <
               FlightSimulation_P.Saturation_LowerSat_a) {
      FlightSimulation_B.Abs = FlightSimulation_P.Saturation_LowerSat_a;
    } else {
      FlightSimulation_B.Abs = FlightSimulation_U.Mass_kg;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Gain: '<S17>/g_mps2' */
    FlightSimulation_B.UnaryMinus = FlightSimulation_P.g *
      FlightSimulation_B.Abs;

    /* Product: '<S17>/Divide' */
    FlightSimulation_B.Divide[0] = FlightSimulation_B.Add_f[0] /
      FlightSimulation_B.UnaryMinus;
    FlightSimulation_B.Divide[1] = FlightSimulation_B.Add_f[1] /
      FlightSimulation_B.UnaryMinus;
    FlightSimulation_B.Divide[2] = FlightSimulation_B.Add_f[2] /
      FlightSimulation_B.UnaryMinus;

    /* Outport: '<Root>/nx' */
    FlightSimulation_Y.nx = FlightSimulation_B.Divide[0];

    /* Outport: '<Root>/ny' */
    FlightSimulation_Y.ny = FlightSimulation_B.Divide[1];
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Sum: '<S21>/Add' incorporates:
     *  Integrator: '<S14>/p_radps'
     *  Integrator: '<S14>/q_radps'
     *  Integrator: '<S14>/r_radps'
     *  Product: '<S21>/Product'
     *  Product: '<S21>/Product1'
     *  Product: '<S21>/Product2'
     *  Product: '<S21>/Product3'
     *  Product: '<S21>/Product4'
     *  Product: '<S21>/Product5'
     */
    FlightSimulation_B.TrigonometricFunction_o2_f[0] =
      FlightSimulation_X.q_radps * FlightSimulation_B.w_mps;
    FlightSimulation_B.TrigonometricFunction_o2_f[1] =
      FlightSimulation_X.r_radps * FlightSimulation_B.u_mps;
    FlightSimulation_B.TrigonometricFunction_o2_f[2] =
      FlightSimulation_X.p_radps * FlightSimulation_B.v_mps;
    FlightSimulation_B.dv2[0] = FlightSimulation_X.r_radps *
      FlightSimulation_B.v_mps;
    FlightSimulation_B.dv2[1] = FlightSimulation_X.p_radps *
      FlightSimulation_B.w_mps;
    FlightSimulation_B.dv2[2] = FlightSimulation_X.q_radps *
      FlightSimulation_B.u_mps;

    /* SignalConversion generated from: '<S14>/Product' incorporates:
     *  Integrator: '<S14>/p_radps'
     *  Integrator: '<S14>/q_radps'
     *  Integrator: '<S14>/r_radps'
     *  SignalConversion generated from: '<S18>/Product'
     */
    FlightSimulation_B.rad2deg[0] = FlightSimulation_X.p_radps;
    FlightSimulation_B.rad2deg[1] = FlightSimulation_X.q_radps;
    FlightSimulation_B.rad2deg[2] = FlightSimulation_X.r_radps;
    for (iU = 0; iU < 3; iU++) {
      /* Sum: '<S15>/Add' incorporates:
       *  Constant: '<S17>/Constant'
       *  Math: '<S17>/Math Function'
       *  Math: '<S23>/Math Function'
       *  Product: '<S15>/Divide'
       *  SignalConversion generated from: '<S17>/Product'
       *  Sum: '<S17>/Sum'
       *  Sum: '<S21>/Add'
       */
      FlightSimulation_B.VB_dot_mps2[iU] = (((FlightSimulation_B.MathFunction_c
        [3 * iU + 1] * FlightSimulation_P.Constant_Value_hz +
        FlightSimulation_B.MathFunction_c[3 * iU] *
        FlightSimulation_P.Constant_Value_hz) +
        FlightSimulation_B.MathFunction_c[3 * iU + 2] *
        FlightSimulation_B.UnaryMinus) + FlightSimulation_B.Add_f[iU]) /
        FlightSimulation_B.Abs -
        (FlightSimulation_B.TrigonometricFunction_o2_f[iU] -
         FlightSimulation_B.dv2[iU]);

      /* Product: '<S14>/Product' incorporates:
       *  Constant: '<Root>/Constant1'
       */
      FlightSimulation_B.TrigonometricFunction_o1[iU] =
        (FlightSimulation_P.Inertia[iU + 3] * FlightSimulation_B.rad2deg[1] +
         FlightSimulation_P.Inertia[iU] * FlightSimulation_B.rad2deg[0]) +
        FlightSimulation_P.Inertia[iU + 6] * FlightSimulation_B.rad2deg[2];
    }

    /* Sum: '<S14>/Sum' incorporates:
     *  Integrator: '<S14>/q_radps'
     *  Integrator: '<S14>/r_radps'
     *  Product: '<S20>/Product'
     *  Product: '<S20>/Product3'
     *  Sum: '<S20>/Add'
     */
    FlightSimulation_B.TrigonometricFunction_o2_f[0] = FlightSimulation_B.Add_f
      [3] - (FlightSimulation_X.q_radps *
             FlightSimulation_B.TrigonometricFunction_o1[2] -
             FlightSimulation_X.r_radps *
             FlightSimulation_B.TrigonometricFunction_o1[1]);

    /* Gain: '<Root>/rad2deg' incorporates:
     *  SignalConversion generated from: '<S18>/Product'
     */
    FlightSimulation_B.rad2deg[0] *= FlightSimulation_P.rad2deg_Gain_e;

    /* Sum: '<S14>/Sum' incorporates:
     *  Integrator: '<S14>/p_radps'
     *  Integrator: '<S14>/r_radps'
     *  Product: '<S20>/Product1'
     *  Product: '<S20>/Product4'
     *  Sum: '<S20>/Add'
     */
    FlightSimulation_B.TrigonometricFunction_o2_f[1] = FlightSimulation_B.Add_f
      [4] - (FlightSimulation_X.r_radps *
             FlightSimulation_B.TrigonometricFunction_o1[0] -
             FlightSimulation_X.p_radps *
             FlightSimulation_B.TrigonometricFunction_o1[2]);

    /* Gain: '<Root>/rad2deg' incorporates:
     *  SignalConversion generated from: '<S18>/Product'
     */
    FlightSimulation_B.rad2deg[1] *= FlightSimulation_P.rad2deg_Gain_e;

    /* Sum: '<S14>/Sum' incorporates:
     *  Integrator: '<S14>/p_radps'
     *  Integrator: '<S14>/q_radps'
     *  Product: '<S20>/Product2'
     *  Product: '<S20>/Product5'
     *  Sum: '<S20>/Add'
     */
    FlightSimulation_B.TrigonometricFunction_o2_f[2] = FlightSimulation_B.Add_f
      [5] - (FlightSimulation_X.p_radps *
             FlightSimulation_B.TrigonometricFunction_o1[1] -
             FlightSimulation_X.q_radps *
             FlightSimulation_B.TrigonometricFunction_o1[0]);

    /* Gain: '<Root>/rad2deg' incorporates:
     *  SignalConversion generated from: '<S18>/Product'
     */
    FlightSimulation_B.rad2deg[2] *= FlightSimulation_P.rad2deg_Gain_e;

    /* Product: '<S14>/Divide' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    rt_mldivide_U1d3x3_U2d_9O8lG8_l(FlightSimulation_P.Inertia,
      FlightSimulation_B.TrigonometricFunction_o2_f, FlightSimulation_B.Divide_c);

    /* Outport: '<Root>/p_degps' */
    FlightSimulation_Y.p_degps = FlightSimulation_B.rad2deg[0];

    /* Outport: '<Root>/q_degps' */
    FlightSimulation_Y.q_degps = FlightSimulation_B.rad2deg[1];

    /* Outport: '<Root>/r_degps' */
    FlightSimulation_Y.r_degps = FlightSimulation_B.rad2deg[2];
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    for (iU = 0; iU < 3; iU++) {
      /* Product: '<S18>/Product' incorporates:
       *  Math: '<S23>/Math Function'
       *  SignalConversion generated from: '<S18>/Product'
       */
      FlightSimulation_B.VI_mps[iU] = 0.0;
      FlightSimulation_B.VI_mps[iU] += FlightSimulation_B.MathFunction_c[iU] *
        FlightSimulation_B.u_mps;
      FlightSimulation_B.VI_mps[iU] += FlightSimulation_B.MathFunction_c[iU + 3]
        * FlightSimulation_B.v_mps;
      FlightSimulation_B.VI_mps[iU] += FlightSimulation_B.MathFunction_c[iU + 6]
        * FlightSimulation_B.w_mps;

      /* Trigonometry: '<S22>/Trigonometric Function' */
      FlightSimulation_B.TrigonometricFunction_o1[iU] = sin
        (FlightSimulation_B.rad2deg1[iU]);
      FlightSimulation_B.TrigonometricFunction_o2_f[iU] = cos
        (FlightSimulation_B.rad2deg1[iU]);

      /* Gain: '<Root>/rad2deg1' incorporates:
       *  SignalConversion generated from: '<S22>/Trigonometric Function'
       */
      FlightSimulation_B.rad2deg1[iU] *= FlightSimulation_P.rad2deg1_Gain_c;
    }

    /* Outport: '<Root>/Phi_deg' */
    FlightSimulation_Y.Phi_deg = FlightSimulation_B.rad2deg1[0];

    /* Outport: '<Root>/Theta_deg' */
    FlightSimulation_Y.Theta_deg = FlightSimulation_B.rad2deg1[1];

    /* Outport: '<Root>/Psi_deg' */
    FlightSimulation_Y.Psi_deg = FlightSimulation_B.rad2deg1[2];
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Abs: '<S22>/Abs' */
    FlightSimulation_B.Abs = fabs(FlightSimulation_B.TrigonometricFunction_o2_f
      [1]);

    /* Relay: '<S22>/Relay' */
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
      FlightSimulation_DW.Relay_Mode = ((FlightSimulation_B.Abs >=
        FlightSimulation_P.Relay_OnVal) || ((!(FlightSimulation_B.Abs <=
        FlightSimulation_P.Relay_OffVal)) && FlightSimulation_DW.Relay_Mode));
    }

    if (FlightSimulation_DW.Relay_Mode) {
      /* Relay: '<S22>/Relay' */
      FlightSimulation_B.Relay = FlightSimulation_P.Relay_YOn;
    } else {
      /* Relay: '<S22>/Relay' */
      FlightSimulation_B.Relay = FlightSimulation_P.Relay_YOff;
    }

    /* End of Relay: '<S22>/Relay' */

    /* Switch: '<S22>/Switch' incorporates:
     *  Constant: '<S22>/Constant'
     *  Product: '<S22>/Product'
     */
    if (FlightSimulation_B.Relay > FlightSimulation_P.Switch_Threshold) {
      /* Signum: '<S22>/Sign' */
      if (FlightSimulation_B.TrigonometricFunction_o2_f[1] < 0.0) {
        FlightSimulation_B.UnaryMinus = -1.0;
      } else if (FlightSimulation_B.TrigonometricFunction_o2_f[1] > 0.0) {
        FlightSimulation_B.UnaryMinus = 1.0;
      } else if (FlightSimulation_B.TrigonometricFunction_o2_f[1] == 0.0) {
        FlightSimulation_B.UnaryMinus = 0.0;
      } else {
        FlightSimulation_B.UnaryMinus = (rtNaN);
      }

      /* End of Signum: '<S22>/Sign' */
      FlightSimulation_B.UnaryMinus *= FlightSimulation_P.Constant_Value_f;
    } else {
      FlightSimulation_B.UnaryMinus =
        FlightSimulation_B.TrigonometricFunction_o2_f[1];
    }

    /* End of Switch: '<S22>/Switch' */

    /* MATLAB Function: '<S22>/MATLAB Function' incorporates:
     *  Integrator: '<S14>/p_radps'
     *  Integrator: '<S14>/q_radps'
     *  Integrator: '<S14>/r_radps'
     *  MATLAB Function: '<S22>/MATLAB Function2'
     *  SignalConversion generated from: '<S24>/ SFunction '
     */
    FlightSimulation_B.degrad1 = FlightSimulation_B.TrigonometricFunction_o1[1] /
      FlightSimulation_B.UnaryMinus;
    FlightSimulation_B.Abs = FlightSimulation_X.q_radps *
      FlightSimulation_B.TrigonometricFunction_o1[0];
    FlightSimulation_B.degrad = FlightSimulation_X.r_radps *
      FlightSimulation_B.TrigonometricFunction_o2_f[0];
    FlightSimulation_B.y_c = (FlightSimulation_B.Abs *
      FlightSimulation_B.degrad1 + FlightSimulation_X.p_radps) +
      FlightSimulation_B.degrad * FlightSimulation_B.degrad1;

    /* MATLAB Function: '<S22>/MATLAB Function1' incorporates:
     *  Integrator: '<S14>/q_radps'
     *  Integrator: '<S14>/r_radps'
     *  SignalConversion generated from: '<S25>/ SFunction '
     */
    FlightSimulation_B.y_h = FlightSimulation_X.q_radps *
      FlightSimulation_B.TrigonometricFunction_o2_f[0] -
      FlightSimulation_X.r_radps * FlightSimulation_B.TrigonometricFunction_o1[0];

    /* MATLAB Function: '<S22>/MATLAB Function2' incorporates:
     *  SignalConversion generated from: '<S26>/ SFunction '
     */
    FlightSimulation_B.y = (FlightSimulation_B.Abs + FlightSimulation_B.degrad) /
      FlightSimulation_B.UnaryMinus;

    /* Sqrt: '<S19>/Sqrt' incorporates:
     *  Math: '<S19>/Math Function'
     *  Math: '<S19>/Math Function1'
     *  Sum: '<S19>/Add'
     */
    FlightSimulation_B.UnaryMinus = sqrt(FlightSimulation_B.VI_mps[0] *
      FlightSimulation_B.VI_mps[0] + FlightSimulation_B.VI_mps[1] *
      FlightSimulation_B.VI_mps[1]);

    /* Gain: '<S19>/Gain1' incorporates:
     *  Gain: '<S19>/Gain'
     *  Trigonometry: '<S19>/Trigonometric Function'
     */
    FlightSimulation_B.Gain1 = rt_atan2d_snf(FlightSimulation_P.Gain_Gain *
      FlightSimulation_B.VI_mps[2], FlightSimulation_B.UnaryMinus) *
      FlightSimulation_P.Gain1_Gain;

    /* Outport: '<Root>/Gamma_deg' */
    FlightSimulation_Y.Gamma_deg = FlightSimulation_B.Gain1;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Gain: '<Root>/mps2kt2' */
    FlightSimulation_B.mps2kt2 = FlightSimulation_P.mps2kt2_Gain *
      FlightSimulation_B.UnaryMinus;

    /* Outport: '<Root>/GSpeed_kt' */
    FlightSimulation_Y.GSpeed_kt = FlightSimulation_B.mps2kt2;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Gain: '<S19>/Gain2' incorporates:
     *  Trigonometry: '<S19>/Trigonometric Function1'
     */
    FlightSimulation_B.Gain2 = FlightSimulation_P.Gain2_Gain * rt_atan2d_snf
      (FlightSimulation_B.VI_mps[1], FlightSimulation_B.VI_mps[0]);

    /* Outport: '<Root>/Track_deg' */
    FlightSimulation_Y.Track_deg = FlightSimulation_B.Gain2;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Gain: '<S17>/Gain' */
    FlightSimulation_B.nz = FlightSimulation_P.Gain_Gain_i *
      FlightSimulation_B.Divide[2];

    /* Outport: '<Root>/nz' */
    FlightSimulation_Y.nz = FlightSimulation_B.nz;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Outport: '<Root>/Thrust_N' */
    FlightSimulation_Y.Thrust_N = FlightSimulation_B.T_N;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Outport: '<Root>/AlphaDot_radps' */
    FlightSimulation_Y.AlphaDot_radps = FlightSimulation_B.AlphaDot_radps;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Product: '<S2>/Divide' incorporates:
     *  Gain: '<S12>/Gamma*R'
     *  Sqrt: '<S12>/Sqrt1'
     */
    FlightSimulation_B.Mach = FlightSimulation_B.TAS_mps / sqrt
      (FlightSimulation_P.GammaR_Gain * FlightSimulation_B.Sqrt1);

    /* Sum: '<S13>/Add2' incorporates:
     *  Constant: '<S13>/Constant2'
     *  Gain: '<S13>/(Gamma-1)//2'
     *  Math: '<S13>/Math Function2'
     */
    FlightSimulation_B.UnaryMinus = FlightSimulation_B.Mach *
      FlightSimulation_B.Mach * FlightSimulation_P.Gamma12_Gain +
      FlightSimulation_P.Constant2_Value_b;

    /* Math: '<S13>/Math Function3' incorporates:
     *  Constant: '<S13>/Gamma//(Gamma-1)'
     */
    if ((FlightSimulation_B.UnaryMinus < 0.0) &&
        (FlightSimulation_P.GammaGamma1_Value > floor
         (FlightSimulation_P.GammaGamma1_Value))) {
      FlightSimulation_B.UnaryMinus = -rt_powd_snf
        (-FlightSimulation_B.UnaryMinus, FlightSimulation_P.GammaGamma1_Value);
    } else {
      FlightSimulation_B.UnaryMinus = rt_powd_snf(FlightSimulation_B.UnaryMinus,
        FlightSimulation_P.GammaGamma1_Value);
    }

    /* End of Math: '<S13>/Math Function3' */

    /* Sum: '<S13>/Add4' incorporates:
     *  Constant: '<S13>/Constant2'
     *  Constant: '<S13>/P0_Pa'
     *  Product: '<S13>/Divide5'
     *  Product: '<S13>/Divide6'
     *  Sum: '<S13>/Add3'
     */
    FlightSimulation_B.UnaryMinus = (FlightSimulation_B.UnaryMinus -
      FlightSimulation_P.Constant2_Value_b) * FlightSimulation_B.Divide1_h /
      FlightSimulation_P.P0_Pa_Value + FlightSimulation_P.Constant2_Value_b;

    /* Math: '<S13>/Math Function4' incorporates:
     *  Constant: '<S13>/(Gamma-1)//Gamma'
     */
    if ((FlightSimulation_B.UnaryMinus < 0.0) &&
        (FlightSimulation_P.Gamma1Gamma_Value > floor
         (FlightSimulation_P.Gamma1Gamma_Value))) {
      FlightSimulation_B.UnaryMinus = -rt_powd_snf
        (-FlightSimulation_B.UnaryMinus, FlightSimulation_P.Gamma1Gamma_Value);
    } else {
      FlightSimulation_B.UnaryMinus = rt_powd_snf(FlightSimulation_B.UnaryMinus,
        FlightSimulation_P.Gamma1Gamma_Value);
    }

    /* End of Math: '<S13>/Math Function4' */

    /* Gain: '<Root>/mps2kt' incorporates:
     *  Constant: '<S13>/Constant2'
     *  Gain: '<S13>/2*a0^2//(Gamma-1)'
     *  Sqrt: '<S13>/Sqrt2'
     *  Sum: '<S13>/Add5'
     */
    FlightSimulation_B.mps2kt = sqrt((FlightSimulation_B.UnaryMinus -
      FlightSimulation_P.Constant2_Value_b) * FlightSimulation_P.ua02Gamma1_Gain)
      * FlightSimulation_P.mps2kt_Gain;

    /* Outport: '<Root>/KCAS' */
    FlightSimulation_Y.KCAS = FlightSimulation_B.mps2kt;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Outport: '<Root>/Mach' */
    FlightSimulation_Y.Mach = FlightSimulation_B.Mach;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Gain: '<Root>/m2ft' incorporates:
     *  Integrator: '<S18>/ZI_m'
     */
    FlightSimulation_B.m2ft = FlightSimulation_P.m2ft_Gain *
      FlightSimulation_X.ZI_m;

    /* Outport: '<Root>/PresAlt_ft' */
    FlightSimulation_Y.PresAlt_ft = FlightSimulation_B.m2ft;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Outport: '<Root>/Beta_deg' */
    FlightSimulation_Y.Beta_deg = FlightSimulation_B.Beta_deg;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Gain: '<Root>/mps2kt1' */
    FlightSimulation_B.mps2kt1 = FlightSimulation_P.mps2kt1_Gain *
      FlightSimulation_B.TAS_mps;

    /* Outport: '<Root>/KTAS' */
    FlightSimulation_Y.KTAS = FlightSimulation_B.mps2kt1;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Outport: '<Root>/v_mps' */
    FlightSimulation_Y.v_mps = FlightSimulation_B.v_mps;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Outport: '<Root>/Alpha_deg' */
    FlightSimulation_Y.Alpha_deg = FlightSimulation_B.Alpha_deg;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Outport: '<Root>/w_mps' */
    FlightSimulation_Y.w_mps = FlightSimulation_B.w_mps;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Outport: '<Root>/u_mps' */
    FlightSimulation_Y.u_mps = FlightSimulation_B.u_mps;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Integrator: '<S18>/XI_m' */
    FlightSimulation_B.XI_m = FlightSimulation_X.XI_m;

    /* Outport: '<Root>/X_m' */
    FlightSimulation_Y.X_m = FlightSimulation_B.XI_m;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }

    /* Integrator: '<S18>/YI_m1' */
    FlightSimulation_B.YI_m1 = FlightSimulation_X.YI_m;

    /* Outport: '<Root>/Y_m' */
    FlightSimulation_Y.Y_m = FlightSimulation_B.YI_m1;
    if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    }
  }

  if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    real_T *lastU;

    /* Update for Derivative: '<S2>/Derivative' */
    if (FlightSimulation_DW.TimeStampA == (rtInf)) {
      FlightSimulation_DW.TimeStampA = FlightSimulation_M->Timing.t[0];
      lastU = &FlightSimulation_DW.LastUAtTimeA;
    } else if (FlightSimulation_DW.TimeStampB == (rtInf)) {
      FlightSimulation_DW.TimeStampB = FlightSimulation_M->Timing.t[0];
      lastU = &FlightSimulation_DW.LastUAtTimeB;
    } else if (FlightSimulation_DW.TimeStampA < FlightSimulation_DW.TimeStampB)
    {
      FlightSimulation_DW.TimeStampA = FlightSimulation_M->Timing.t[0];
      lastU = &FlightSimulation_DW.LastUAtTimeA;
    } else {
      FlightSimulation_DW.TimeStampB = FlightSimulation_M->Timing.t[0];
      lastU = &FlightSimulation_DW.LastUAtTimeB;
    }

    *lastU = FlightSimulation_B.TrigonometricFunction1;

    /* End of Update for Derivative: '<S2>/Derivative' */
    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        (((FlightSimulation_M->Timing.clockTick0+
           FlightSimulation_M->Timing.clockTickH0* 4294967296.0) * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(FlightSimulation_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        (((FlightSimulation_M->Timing.clockTick1+
           FlightSimulation_M->Timing.clockTickH1* 4294967296.0) * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(FlightSimulation_M)) {
    rt_ertODEUpdateContinuousStates(&FlightSimulation_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++FlightSimulation_M->Timing.clockTick0)) {
      ++FlightSimulation_M->Timing.clockTickH0;
    }

    FlightSimulation_M->Timing.t[0] = rtsiGetSolverStopTime
      (&FlightSimulation_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      FlightSimulation_M->Timing.clockTick1++;
      if (!FlightSimulation_M->Timing.clockTick1) {
        FlightSimulation_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void FlightSimulation_derivatives(void)
{
  XDot_FlightSimulation_T *_rtXdot;
  _rtXdot = ((XDot_FlightSimulation_T *) FlightSimulation_M->derivs);

  /* Derivatives for Integrator: '<S16>/PHI_rad' */
  _rtXdot->PHI_rad = FlightSimulation_B.y_c;

  /* Derivatives for Integrator: '<S16>/THETA_rad' */
  _rtXdot->THETA_rad = FlightSimulation_B.y_h;

  /* Derivatives for Integrator: '<S16>/PSI_rad' */
  _rtXdot->PSI_rad = FlightSimulation_B.y;

  /* Derivatives for Integrator: '<S15>/u_mps' */
  _rtXdot->u_mps = FlightSimulation_B.VB_dot_mps2[0];

  /* Derivatives for Integrator: '<S15>/w_mps' */
  _rtXdot->w_mps = FlightSimulation_B.VB_dot_mps2[2];

  /* Derivatives for Integrator: '<S15>/v_mps' */
  _rtXdot->v_mps = FlightSimulation_B.VB_dot_mps2[1];

  /* Derivatives for Integrator: '<S18>/ZI_m' */
  _rtXdot->ZI_m = FlightSimulation_B.VI_mps[2];

  /* Derivatives for Integrator: '<S14>/p_radps' */
  _rtXdot->p_radps = FlightSimulation_B.Divide_c[0];

  /* Derivatives for Integrator: '<S14>/r_radps' */
  _rtXdot->r_radps = FlightSimulation_B.Divide_c[2];

  /* Derivatives for Integrator: '<S14>/q_radps' */
  _rtXdot->q_radps = FlightSimulation_B.Divide_c[1];

  /* Derivatives for Integrator: '<S18>/XI_m' */
  _rtXdot->XI_m = FlightSimulation_B.VI_mps[0];

  /* Derivatives for Integrator: '<S18>/YI_m1' */
  _rtXdot->YI_m = FlightSimulation_B.VI_mps[1];
}

/* Model initialize function */
void FlightSimulation_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  FlightSimulation_P.Saturation_UpperSat = rtInf;
  FlightSimulation_P.LimittoTropopause1_UpperSat = rtInf;
  FlightSimulation_P.Saturation_UpperSat_l = rtInf;

  /* initialize real-time model */
  (void) memset((void *)FlightSimulation_M, 0,
                sizeof(RT_MODEL_FlightSimulation_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&FlightSimulation_M->solverInfo,
                          &FlightSimulation_M->Timing.simTimeStep);
    rtsiSetTPtr(&FlightSimulation_M->solverInfo, &rtmGetTPtr(FlightSimulation_M));
    rtsiSetStepSizePtr(&FlightSimulation_M->solverInfo,
                       &FlightSimulation_M->Timing.stepSize0);
    rtsiSetdXPtr(&FlightSimulation_M->solverInfo, &FlightSimulation_M->derivs);
    rtsiSetContStatesPtr(&FlightSimulation_M->solverInfo, (real_T **)
                         &FlightSimulation_M->contStates);
    rtsiSetNumContStatesPtr(&FlightSimulation_M->solverInfo,
      &FlightSimulation_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&FlightSimulation_M->solverInfo,
      &FlightSimulation_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&FlightSimulation_M->solverInfo,
      &FlightSimulation_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&FlightSimulation_M->solverInfo,
      &FlightSimulation_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&FlightSimulation_M->solverInfo, (&rtmGetErrorStatus
      (FlightSimulation_M)));
    rtsiSetRTModelPtr(&FlightSimulation_M->solverInfo, FlightSimulation_M);
  }

  rtsiSetSimTimeStep(&FlightSimulation_M->solverInfo, MAJOR_TIME_STEP);
  FlightSimulation_M->intgData.y = FlightSimulation_M->odeY;
  FlightSimulation_M->intgData.f[0] = FlightSimulation_M->odeF[0];
  FlightSimulation_M->intgData.f[1] = FlightSimulation_M->odeF[1];
  FlightSimulation_M->intgData.f[2] = FlightSimulation_M->odeF[2];
  FlightSimulation_M->contStates = ((X_FlightSimulation_T *) &FlightSimulation_X);
  rtsiSetSolverData(&FlightSimulation_M->solverInfo, (void *)
                    &FlightSimulation_M->intgData);
  rtsiSetSolverName(&FlightSimulation_M->solverInfo,"ode3");
  rtmSetTPtr(FlightSimulation_M, &FlightSimulation_M->Timing.tArray[0]);
  rtmSetTFinal(FlightSimulation_M, -1);
  FlightSimulation_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  FlightSimulation_M->Sizes.checksums[0] = (1443550694U);
  FlightSimulation_M->Sizes.checksums[1] = (906183119U);
  FlightSimulation_M->Sizes.checksums[2] = (3918522659U);
  FlightSimulation_M->Sizes.checksums[3] = (305713297U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    FlightSimulation_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(FlightSimulation_M->extModeInfo,
      &FlightSimulation_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(FlightSimulation_M->extModeInfo,
                        FlightSimulation_M->Sizes.checksums);
    rteiSetTPtr(FlightSimulation_M->extModeInfo, rtmGetTPtr(FlightSimulation_M));
  }

  /* block I/O */
  (void) memset(((void *) &FlightSimulation_B), 0,
                sizeof(B_FlightSimulation_T));

  /* states (continuous) */
  {
    (void) memset((void *)&FlightSimulation_X, 0,
                  sizeof(X_FlightSimulation_T));
  }

  /* states (dwork) */
  (void) memset((void *)&FlightSimulation_DW, 0,
                sizeof(DW_FlightSimulation_T));

  /* external inputs */
  (void)memset(&FlightSimulation_U, 0, sizeof(ExtU_FlightSimulation_T));

  /* external outputs */
  (void)memset(&FlightSimulation_Y, 0, sizeof(ExtY_FlightSimulation_T));

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    FlightSimulation_DW.obj.matlabCodegenIsDeleted = true;
    FlightSimulation_DW.obj.isInitialized = 0L;
    FlightSimulation_DW.obj.SampleTime = -1.0;
    FlightSimulation_DW.obj.matlabCodegenIsDeleted = false;
    FlightSimulation_DW.objisempty = true;
    FlightSimulation_DW.obj.SampleTime =
      FlightSimulation_P.AnalogInput_SampleTime;
    obj = &FlightSimulation_DW.obj;
    FlightSimulation_DW.obj.isSetupComplete = false;
    FlightSimulation_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(54UL);
    FlightSimulation_DW.obj.isSetupComplete = true;
  }

  /* InitializeConditions for Integrator: '<S16>/PHI_rad' */
  FlightSimulation_X.PHI_rad = FlightSimulation_P.PHI_rad_IC;

  /* InitializeConditions for Integrator: '<S16>/THETA_rad' */
  FlightSimulation_X.THETA_rad = FlightSimulation_P.THETA_rad_IC;

  /* InitializeConditions for Integrator: '<S16>/PSI_rad' */
  FlightSimulation_X.PSI_rad = FlightSimulation_P.PSI_rad_IC;

  /* InitializeConditions for Integrator: '<S15>/u_mps' */
  FlightSimulation_X.u_mps = FlightSimulation_P.u_mps_IC;

  /* InitializeConditions for Integrator: '<S15>/w_mps' */
  FlightSimulation_X.w_mps = FlightSimulation_P.w_mps_IC;

  /* InitializeConditions for Integrator: '<S15>/v_mps' */
  FlightSimulation_X.v_mps = FlightSimulation_P.v_mps_IC;

  /* InitializeConditions for Integrator: '<S18>/ZI_m' */
  FlightSimulation_X.ZI_m = FlightSimulation_P.ZI_m_IC;

  /* InitializeConditions for Integrator: '<S14>/p_radps' */
  FlightSimulation_X.p_radps = FlightSimulation_P.p_radps_IC;

  /* InitializeConditions for Integrator: '<S14>/r_radps' */
  FlightSimulation_X.r_radps = FlightSimulation_P.r_radps_IC;

  /* InitializeConditions for Derivative: '<S2>/Derivative' */
  FlightSimulation_DW.TimeStampA = (rtInf);
  FlightSimulation_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S14>/q_radps' */
  FlightSimulation_X.q_radps = FlightSimulation_P.q_radps_IC;

  /* InitializeConditions for Integrator: '<S18>/XI_m' */
  FlightSimulation_X.XI_m = FlightSimulation_P.XI_m_IC;

  /* InitializeConditions for Integrator: '<S18>/YI_m1' */
  FlightSimulation_X.YI_m = FlightSimulation_P.YI_m1_IC;
}

/* Model terminate function */
void FlightSimulation_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &FlightSimulation_DW.obj;
  if (!FlightSimulation_DW.obj.matlabCodegenIsDeleted) {
    FlightSimulation_DW.obj.matlabCodegenIsDeleted = true;
    if ((FlightSimulation_DW.obj.isInitialized == 1L) &&
        FlightSimulation_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
      MW_AnalogIn_Close
        (FlightSimulation_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */
}
