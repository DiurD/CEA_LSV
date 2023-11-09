/*
 * FlightSimulation_data.c
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

/* Block parameters (default storage) */
P_FlightSimulation_T FlightSimulation_P = {
  /* Variable: C_D0
   * Referenced by: '<S5>/Constant6'
   */
  0.027,

  /* Variable: C_Dalpha
   * Referenced by: '<S5>/Gain'
   */
  0.121,

  /* Variable: C_DdeltaE
   * Referenced by: '<S5>/Gain1'
   */
  0.0,

  /* Variable: C_L0
   * Referenced by: '<S6>/Constant1'
   */
  0.307,

  /* Variable: C_Lalpha
   * Referenced by: '<S6>/Gain'
   */
  4.41,

  /* Variable: C_Lalphadot
   * Referenced by: '<S6>/Gain2'
   */
  1.7,

  /* Variable: C_LdeltaE
   * Referenced by: '<S6>/Gain1'
   */
  0.43,

  /* Variable: C_Lq
   * Referenced by: '<S6>/Gain3'
   */
  3.9,

  /* Variable: C_Ybeta
   * Referenced by: '<S7>/Gain'
   */
  -0.393,

  /* Variable: C_YdeltaA
   * Referenced by: '<S7>/Gain1'
   */
  0.0,

  /* Variable: C_YdeltaR
   * Referenced by: '<S7>/Gain2'
   */
  0.187,

  /* Variable: C_Yp
   * Referenced by: '<S7>/Gain3'
   */
  -0.075,

  /* Variable: C_Yr
   * Referenced by: '<S7>/Gain4'
   */
  0.214,

  /* Variable: C_lbeta
   * Referenced by: '<S8>/Gain'
   */
  -0.0923,

  /* Variable: C_ldeltaA
   * Referenced by: '<S8>/Gain1'
   */
  0.229,

  /* Variable: C_ldeltaR
   * Referenced by: '<S8>/Gain2'
   */
  0.0147,

  /* Variable: C_lp
   * Referenced by: '<S8>/Gain3'
   */
  -0.484,

  /* Variable: C_lr
   * Referenced by: '<S8>/Gain4'
   */
  0.0798,

  /* Variable: C_m0
   * Referenced by: '<S9>/Constant9'
   */
  0.04,

  /* Variable: C_malpha
   * Referenced by: '<S9>/Gain'
   */
  -0.613,

  /* Variable: C_malphadot
   * Referenced by: '<S9>/Gain2'
   */
  -7.27,

  /* Variable: C_mdeltaE
   * Referenced by: '<S9>/Gain1'
   */
  -1.122,

  /* Variable: C_mq
   * Referenced by: '<S9>/Gain3'
   */
  -12.4,

  /* Variable: C_nbeta
   * Referenced by: '<S10>/Gain'
   */
  0.0587,

  /* Variable: C_ndeltaA
   * Referenced by: '<S10>/Gain1'
   */
  -0.0216,

  /* Variable: C_ndeltaR
   * Referenced by: '<S10>/Gain2'
   */
  -0.0645,

  /* Variable: C_np
   * Referenced by: '<S10>/Gain3'
   */
  -0.0278,

  /* Variable: C_nr
   * Referenced by: '<S10>/Gain4'
   */
  -0.0937,

  /* Variable: Inertia
   * Referenced by: '<Root>/Constant1'
   */
  { 1285.3154278811999, 0.0, -0.0, 0.0, 1824.9309767174, 0.0, -0.0, 0.0,
    2666.8939310573 },

  /* Variable: S_ft2
   * Referenced by: '<S1>/Wingspan_ft²'
   */
  174.0,

  /* Variable: T_max_N
   * Referenced by: '<S4>/Max_Thrust_N'
   */
  4690.0,

  /* Variable: V_ref_mps
   * Referenced by: '<S4>/V_ref_mps'
   */
  30.0,

  /* Variable: b_ft
   * Referenced by: '<S1>/b_ft'
   */
  36.0,

  /* Variable: eta_T_deg
   * Referenced by: '<S4>/eta_T_deg'
   */
  0.0,

  /* Variable: g
   * Referenced by: '<S17>/g_mps2'
   */
  9.80665,

  /* Variable: mean_c_ft
   * Referenced by: '<S1>/mean_c_ft'
   */
  4.9,

  /* Variable: n_rho
   * Referenced by: '<S4>/n_rho'
   */
  1.0,

  /* Variable: n_v
   * Referenced by: '<S4>/n_v'
   */
  -1.0,

  /* Variable: rho_ref_kgpm3
   * Referenced by: '<S4>/rho_ref_kgpm³'
   */
  1.225,

  /* Expression: 0.01
   * Referenced by: '<Root>/Analog Input'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S16>/PHI_rad'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S16>/THETA_rad'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S16>/PSI_rad'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S15>/u_mps'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S15>/w_mps'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S2>/rad2deg1'
   */
  57.295779513082323,

  /* Expression: pi/180
   * Referenced by: '<S1>/deg->rad'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S15>/v_mps'
   */
  0.0,

  /* Expression: Inf
   * Referenced by: '<S2>/Saturation'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S2>/Saturation'
   */
  0.1,

  /* Expression: 180/pi
   * Referenced by: '<S2>/rad2deg'
   */
  57.295779513082323,

  /* Expression: pi/180
   * Referenced by: '<S1>/deg->rad1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S11>/Constant30'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S11>/Constant29'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S11>/Constant31'
   */
  0.0,

  /* Expression: 0.092903
   * Referenced by: '<S1>/ft²_to_m²'
   */
  0.092903,

  /* Expression: 288.15
   * Referenced by: '<S12>/Constant'
   */
  288.15,

  /* Expression: 0
   * Referenced by: '<S18>/ZI_m'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S2>/constant'
   */
  -1.0,

  /* Expression: 11000
   * Referenced by: '<S12>/Limit to Tropopause'
   */
  11000.0,

  /* Expression: 0
   * Referenced by: '<S12>/Limit to Tropopause'
   */
  0.0,

  /* Expression: -0.0065
   * Referenced by: '<S12>/k'
   */
  -0.0065,

  /* Expression: 1/288.15
   * Referenced by: '<S12>/1//T0'
   */
  0.00347041471455839,

  /* Expression: -9.80665/(-0.0065*287)
   * Referenced by: '<S12>/-g//(k*R)'
   */
  5.2568480300187614,

  /* Expression: 101325
   * Referenced by: '<S12>/P0_Pa'
   */
  101325.0,

  /* Expression: -9.80665/(287)
   * Referenced by: '<S12>/-g//R'
   */
  -0.034169512195121952,

  /* Expression: 11000
   * Referenced by: '<S12>/Constant1'
   */
  11000.0,

  /* Expression: inf
   * Referenced by: '<S12>/Limit to Tropopause1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/Limit to Tropopause1'
   */
  0.0,

  /* Expression: 287
   * Referenced by: '<S12>/R'
   */
  287.0,

  /* Expression: 2
   * Referenced by: '<S1>/Constant'
   */
  2.0,

  /* Expression: pi/180
   * Referenced by: '<S1>/deg->rad2'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S14>/p_radps'
   */
  0.0,

  /* Expression: 0.3048
   * Referenced by: '<S1>/ft_to_m'
   */
  0.3048,

  /* Expression: 2
   * Referenced by: '<S1>/Constant32'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S14>/r_radps'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S1>/Constant33'
   */
  2.0,

  /* Expression: 0.3048
   * Referenced by: '<S1>/ft_to_m   2'
   */
  0.3048,

  /* Expression: 2
   * Referenced by: '<S1>/Constant35'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S14>/q_radps'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S1>/Constant34'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant5'
   */
  0.0,

  /* Expression: Inf
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Saturation'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S17>/Constant'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<Root>/rad2deg'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<Root>/rad2deg1'
   */
  57.295779513082323,

  /* Expression: .001
   * Referenced by: '<S22>/Relay'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S22>/Relay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S22>/Relay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S22>/Relay'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S22>/Constant'
   */
  0.001,

  /* Expression: 0.5
   * Referenced by: '<S22>/Switch'
   */
  0.5,

  /* Expression: -1
   * Referenced by: '<S19>/Gain'
   */
  -1.0,

  /* Expression: 180/pi
   * Referenced by: '<S19>/Gain1'
   */
  57.295779513082323,

  /* Expression: 1/0.51444444
   * Referenced by: '<Root>/mps2kt2'
   */
  1.9438445092340779,

  /* Expression: 180/pi
   * Referenced by: '<S19>/Gain2'
   */
  57.295779513082323,

  /* Expression: -1
   * Referenced by: '<S17>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S13>/Constant2'
   */
  1.0,

  /* Expression: 287*1.4
   * Referenced by: '<S12>/Gamma*R'
   */
  401.79999999999995,

  /* Expression: (1.4-1)/2
   * Referenced by: '<S13>/(Gamma-1)//2'
   */
  0.19999999999999996,

  /* Expression: 1.4/(1.4-1)
   * Referenced by: '<S13>/Gamma//(Gamma-1)'
   */
  3.5000000000000004,

  /* Expression: 101325
   * Referenced by: '<S13>/P0_Pa'
   */
  101325.0,

  /* Expression: (1.4-1)/1.4
   * Referenced by: '<S13>/(Gamma-1)//Gamma'
   */
  0.28571428571428564,

  /* Expression: (2*340.262^2)/(1.4-1)
   * Referenced by: '<S13>/2*a0^2//(Gamma-1)'
   */
  578891.14322000009,

  /* Expression: 1/0.51444444
   * Referenced by: '<Root>/mps2kt'
   */
  1.9438445092340779,

  /* Expression: -1/0.3048
   * Referenced by: '<Root>/m2ft'
   */
  -3.280839895013123,

  /* Expression: 1/0.51444444
   * Referenced by: '<Root>/mps2kt1'
   */
  1.9438445092340779,

  /* Expression: 0
   * Referenced by: '<S18>/XI_m'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S18>/YI_m1'
   */
  0.0,

  /* Computed Parameter: Gain_Gain_o
   * Referenced by: '<Root>/Gain'
   */
  32768U
};
