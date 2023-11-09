/*
 * FlightSimulation.h
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

#ifndef RTW_HEADER_FlightSimulation_h_
#define RTW_HEADER_FlightSimulation_h_
#include <math.h>
#include <string.h>
#ifndef FlightSimulation_COMMON_INCLUDES_
#define FlightSimulation_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_AnalogIn.h"
#endif                                 /* FlightSimulation_COMMON_INCLUDES_ */

#include "FlightSimulation_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T MathFunction_c[9];            /* '<S23>/Math Function' */
  real_T TmpSignalConversionAtSFunct[9];/* '<S22>/MATLAB Function2' */
  real_T A[9];
  real_T Add_f[6];                     /* '<S17>/Add' */
  real_T dv[6];
  real_T dv1[6];
  real_T rad2deg1[3];                  /* '<Root>/rad2deg1' */
  real_T TrigonometricFunction_o1[3];  /* '<S23>/Trigonometric Function' */
  real_T TrigonometricFunction_o2_f[3];/* '<S22>/Trigonometric Function' */
  real_T dv2[3];
  real_T u_mps;                        /* '<S15>/u_mps' */
  real_T w_mps;                        /* '<S15>/w_mps' */
  real_T TrigonometricFunction1;       /* '<S2>/Trigonometric Function1' */
  real_T Alpha_deg;                    /* '<S2>/rad2deg1' */
  real_T v_mps;                        /* '<S15>/v_mps' */
  real_T Beta_deg;                     /* '<S2>/rad2deg' */
  real_T ft_to_m;                      /* '<S1>/ft²_to_m²' */
  real_T ft_to_m_b;                    /* '<S1>/ft_to_m' */
  real_T AlphaDot_radps;               /* '<S2>/Derivative' */
  real_T ft_to_m2;                     /* '<S1>/ft_to_m   2' */
  real_T Cos;                          /* '<S4>/Cos' */
  real_T T_N;                          /* '<S4>/Divide' */
  real_T Sin;                          /* '<S4>/Sin' */
  real_T Divide[3];                    /* '<S17>/Divide' */
  real_T VB_dot_mps2[3];               /* '<S15>/Add' */
  real_T Divide_c[3];                  /* '<S14>/Divide' */
  real_T rad2deg[3];                   /* '<Root>/rad2deg' */
  real_T VI_mps[3];                    /* '<S18>/Product' */
  real_T Relay;                        /* '<S22>/Relay' */
  real_T Gain1;                        /* '<S19>/Gain1' */
  real_T mps2kt2;                      /* '<Root>/mps2kt2' */
  real_T Gain2;                        /* '<S19>/Gain2' */
  real_T nz;                           /* '<S17>/Gain' */
  real_T Mach;                         /* '<S2>/Divide' */
  real_T mps2kt;                       /* '<Root>/mps2kt' */
  real_T m2ft;                         /* '<Root>/m2ft' */
  real_T mps2kt1;                      /* '<Root>/mps2kt1' */
  real_T XI_m;                         /* '<S18>/XI_m' */
  real_T YI_m1;                        /* '<S18>/YI_m1' */
  real_T y;                            /* '<S22>/MATLAB Function2' */
  real_T y_h;                          /* '<S22>/MATLAB Function1' */
  real_T y_c;                          /* '<S22>/MATLAB Function' */
  real_T TAS_mps;                      /* '<S2>/Saturation' */
  real_T UnaryMinus;                   /* '<S1>/Unary Minus' */
  real_T degrad;                       /* '<S1>/deg->rad' */
  real_T degrad1;                      /* '<S1>/deg->rad1' */
  real_T q_bar_Pa;                     /* '<S1>/Divide' */
  real_T MathFunction1_kg;             /* '<S4>/Math Function1' */
  real_T Sqrt1;                        /* '<S12>/Sqrt1' */
  real_T Divide1_h;                    /* '<S12>/Divide1' */
  real_T Product5;                     /* '<S20>/Product5' */
  real_T Product3;                     /* '<S20>/Product3' */
  real_T Gain_k;                       /* '<S19>/Gain' */
  real_T Abs;                          /* '<S22>/Abs' */
  uint32_T Gain;                       /* '<Root>/Gain' */
} B_FlightSimulation_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input' */
  real_T TimeStampA;                   /* '<S2>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S2>/Derivative' */
  real_T TimeStampB;                   /* '<S2>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S2>/Derivative' */
  real_T Divide_DWORK4;                /* '<S17>/Divide' */
  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_D;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_o;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_i;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_d;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_g;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_f;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_e;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFo_es;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_B;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_m;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_n;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFo_ih;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_P;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFo_od;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFo_gs;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFo_im;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_c;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFo_dw;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_a;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFo_ii;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFo_fg;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_h;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFor_j;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFo_f4;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQOutportLogging_InsertedFo_mn;   /* synthesized block */

  boolean_T Relay_Mode;                /* '<S22>/Relay' */
  boolean_T objisempty;                /* '<Root>/Analog Input' */
} DW_FlightSimulation_T;

/* Continuous states (default storage) */
typedef struct {
  real_T PHI_rad;                      /* '<S16>/PHI_rad' */
  real_T THETA_rad;                    /* '<S16>/THETA_rad' */
  real_T PSI_rad;                      /* '<S16>/PSI_rad' */
  real_T u_mps;                        /* '<S15>/u_mps' */
  real_T w_mps;                        /* '<S15>/w_mps' */
  real_T v_mps;                        /* '<S15>/v_mps' */
  real_T ZI_m;                         /* '<S18>/ZI_m' */
  real_T p_radps;                      /* '<S14>/p_radps' */
  real_T r_radps;                      /* '<S14>/r_radps' */
  real_T q_radps;                      /* '<S14>/q_radps' */
  real_T XI_m;                         /* '<S18>/XI_m' */
  real_T YI_m;                         /* '<S18>/YI_m1' */
} X_FlightSimulation_T;

/* State derivatives (default storage) */
typedef struct {
  real_T PHI_rad;                      /* '<S16>/PHI_rad' */
  real_T THETA_rad;                    /* '<S16>/THETA_rad' */
  real_T PSI_rad;                      /* '<S16>/PSI_rad' */
  real_T u_mps;                        /* '<S15>/u_mps' */
  real_T w_mps;                        /* '<S15>/w_mps' */
  real_T v_mps;                        /* '<S15>/v_mps' */
  real_T ZI_m;                         /* '<S18>/ZI_m' */
  real_T p_radps;                      /* '<S14>/p_radps' */
  real_T r_radps;                      /* '<S14>/r_radps' */
  real_T q_radps;                      /* '<S14>/q_radps' */
  real_T XI_m;                         /* '<S18>/XI_m' */
  real_T YI_m;                         /* '<S18>/YI_m1' */
} XDot_FlightSimulation_T;

/* State disabled  */
typedef struct {
  boolean_T PHI_rad;                   /* '<S16>/PHI_rad' */
  boolean_T THETA_rad;                 /* '<S16>/THETA_rad' */
  boolean_T PSI_rad;                   /* '<S16>/PSI_rad' */
  boolean_T u_mps;                     /* '<S15>/u_mps' */
  boolean_T w_mps;                     /* '<S15>/w_mps' */
  boolean_T v_mps;                     /* '<S15>/v_mps' */
  boolean_T ZI_m;                      /* '<S18>/ZI_m' */
  boolean_T p_radps;                   /* '<S14>/p_radps' */
  boolean_T r_radps;                   /* '<S14>/r_radps' */
  boolean_T q_radps;                   /* '<S14>/q_radps' */
  boolean_T XI_m;                      /* '<S18>/XI_m' */
  boolean_T YI_m;                      /* '<S18>/YI_m1' */
} XDis_FlightSimulation_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Mass_kg;                      /* '<Root>/Mass_kg' */
  real_T Elevator_deg;                 /* '<Root>/Elevator_deg' */
  real_T Aileron_deg;                  /* '<Root>/Aileron_deg' */
  real_T Rudder_deg;                   /* '<Root>/Rudder_deg' */
  real_T Throttle;                     /* '<Root>/Throttle' */
} ExtU_FlightSimulation_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T KCAS;                         /* '<Root>/KCAS' */
  real_T Mach;                         /* '<Root>/Mach' */
  real_T KTAS;                         /* '<Root>/KTAS' */
  real_T Beta_deg;                     /* '<Root>/Beta_deg' */
  real_T Alpha_deg;                    /* '<Root>/Alpha_deg' */
  real_T AlphaDot_radps;               /* '<Root>/AlphaDot_radps' */
  real_T u_mps;                        /* '<Root>/u_mps' */
  real_T v_mps;                        /* '<Root>/v_mps' */
  real_T w_mps;                        /* '<Root>/w_mps' */
  real_T p_degps;                      /* '<Root>/p_degps' */
  real_T q_degps;                      /* '<Root>/q_degps' */
  real_T r_degps;                      /* '<Root>/r_degps' */
  real_T Phi_deg;                      /* '<Root>/Phi_deg' */
  real_T Theta_deg;                    /* '<Root>/Theta_deg' */
  real_T Psi_deg;                      /* '<Root>/Psi_deg' */
  real_T X_m;                          /* '<Root>/X_m' */
  real_T Y_m;                          /* '<Root>/Y_m' */
  real_T PresAlt_ft;                   /* '<Root>/PresAlt_ft' */
  real_T GSpeed_kt;                    /* '<Root>/GSpeed_kt' */
  real_T Gamma_deg;                    /* '<Root>/Gamma_deg' */
  real_T Track_deg;                    /* '<Root>/Track_deg' */
  real_T nx;                           /* '<Root>/nx' */
  real_T ny;                           /* '<Root>/ny' */
  real_T nz;                           /* '<Root>/nz' */
  real_T Thrust_N;                     /* '<Root>/Thrust_N' */
} ExtY_FlightSimulation_T;

/* Parameters (default storage) */
struct P_FlightSimulation_T_ {
  real_T C_D0;                         /* Variable: C_D0
                                        * Referenced by: '<S5>/Constant6'
                                        */
  real_T C_Dalpha;                     /* Variable: C_Dalpha
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T C_DdeltaE;                    /* Variable: C_DdeltaE
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T C_L0;                         /* Variable: C_L0
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T C_Lalpha;                     /* Variable: C_Lalpha
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T C_Lalphadot;                  /* Variable: C_Lalphadot
                                        * Referenced by: '<S6>/Gain2'
                                        */
  real_T C_LdeltaE;                    /* Variable: C_LdeltaE
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T C_Lq;                         /* Variable: C_Lq
                                        * Referenced by: '<S6>/Gain3'
                                        */
  real_T C_Ybeta;                      /* Variable: C_Ybeta
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T C_YdeltaA;                    /* Variable: C_YdeltaA
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T C_YdeltaR;                    /* Variable: C_YdeltaR
                                        * Referenced by: '<S7>/Gain2'
                                        */
  real_T C_Yp;                         /* Variable: C_Yp
                                        * Referenced by: '<S7>/Gain3'
                                        */
  real_T C_Yr;                         /* Variable: C_Yr
                                        * Referenced by: '<S7>/Gain4'
                                        */
  real_T C_lbeta;                      /* Variable: C_lbeta
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T C_ldeltaA;                    /* Variable: C_ldeltaA
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T C_ldeltaR;                    /* Variable: C_ldeltaR
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real_T C_lp;                         /* Variable: C_lp
                                        * Referenced by: '<S8>/Gain3'
                                        */
  real_T C_lr;                         /* Variable: C_lr
                                        * Referenced by: '<S8>/Gain4'
                                        */
  real_T C_m0;                         /* Variable: C_m0
                                        * Referenced by: '<S9>/Constant9'
                                        */
  real_T C_malpha;                     /* Variable: C_malpha
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T C_malphadot;                  /* Variable: C_malphadot
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T C_mdeltaE;                    /* Variable: C_mdeltaE
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T C_mq;                         /* Variable: C_mq
                                        * Referenced by: '<S9>/Gain3'
                                        */
  real_T C_nbeta;                      /* Variable: C_nbeta
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T C_ndeltaA;                    /* Variable: C_ndeltaA
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T C_ndeltaR;                    /* Variable: C_ndeltaR
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real_T C_np;                         /* Variable: C_np
                                        * Referenced by: '<S10>/Gain3'
                                        */
  real_T C_nr;                         /* Variable: C_nr
                                        * Referenced by: '<S10>/Gain4'
                                        */
  real_T Inertia[9];                   /* Variable: Inertia
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T S_ft2;                        /* Variable: S_ft2
                                        * Referenced by: '<S1>/Wingspan_ft²'
                                        */
  real_T T_max_N;                      /* Variable: T_max_N
                                        * Referenced by: '<S4>/Max_Thrust_N'
                                        */
  real_T V_ref_mps;                    /* Variable: V_ref_mps
                                        * Referenced by: '<S4>/V_ref_mps'
                                        */
  real_T b_ft;                         /* Variable: b_ft
                                        * Referenced by: '<S1>/b_ft'
                                        */
  real_T eta_T_deg;                    /* Variable: eta_T_deg
                                        * Referenced by: '<S4>/eta_T_deg'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by: '<S17>/g_mps2'
                                        */
  real_T mean_c_ft;                    /* Variable: mean_c_ft
                                        * Referenced by: '<S1>/mean_c_ft'
                                        */
  real_T n_rho;                        /* Variable: n_rho
                                        * Referenced by: '<S4>/n_rho'
                                        */
  real_T n_v;                          /* Variable: n_v
                                        * Referenced by: '<S4>/n_v'
                                        */
  real_T rho_ref_kgpm3;                /* Variable: rho_ref_kgpm3
                                        * Referenced by: '<S4>/rho_ref_kgpm³'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: 0.01
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T PHI_rad_IC;                   /* Expression: 0
                                        * Referenced by: '<S16>/PHI_rad'
                                        */
  real_T THETA_rad_IC;                 /* Expression: 0
                                        * Referenced by: '<S16>/THETA_rad'
                                        */
  real_T PSI_rad_IC;                   /* Expression: 0
                                        * Referenced by: '<S16>/PSI_rad'
                                        */
  real_T u_mps_IC;                     /* Expression: 0
                                        * Referenced by: '<S15>/u_mps'
                                        */
  real_T w_mps_IC;                     /* Expression: 0
                                        * Referenced by: '<S15>/w_mps'
                                        */
  real_T rad2deg1_Gain;                /* Expression: 180/pi
                                        * Referenced by: '<S2>/rad2deg1'
                                        */
  real_T degrad_Gain;                  /* Expression: pi/180
                                        * Referenced by: '<S1>/deg->rad'
                                        */
  real_T v_mps_IC;                     /* Expression: 0
                                        * Referenced by: '<S15>/v_mps'
                                        */
  real_T Saturation_UpperSat;          /* Expression: Inf
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0.1
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T rad2deg_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S2>/rad2deg'
                                        */
  real_T degrad1_Gain;                 /* Expression: pi/180
                                        * Referenced by: '<S1>/deg->rad1'
                                        */
  real_T Constant30_Value;             /* Expression: 0
                                        * Referenced by: '<S11>/Constant30'
                                        */
  real_T Constant29_Value;             /* Expression: 1
                                        * Referenced by: '<S11>/Constant29'
                                        */
  real_T Constant31_Value;             /* Expression: 0
                                        * Referenced by: '<S11>/Constant31'
                                        */
  real_T ft_to_m_Gain;                 /* Expression: 0.092903
                                        * Referenced by: '<S1>/ft²_to_m²'
                                        */
  real_T Constant_Value;               /* Expression: 288.15
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T ZI_m_IC;                      /* Expression: 0
                                        * Referenced by: '<S18>/ZI_m'
                                        */
  real_T constant_Gain;                /* Expression: -1
                                        * Referenced by: '<S2>/constant'
                                        */
  real_T LimittoTropopause_UpperSat;   /* Expression: 11000
                                        * Referenced by: '<S12>/Limit to Tropopause'
                                        */
  real_T LimittoTropopause_LowerSat;   /* Expression: 0
                                        * Referenced by: '<S12>/Limit to Tropopause'
                                        */
  real_T k_Gain;                       /* Expression: -0.0065
                                        * Referenced by: '<S12>/k'
                                        */
  real_T uT0_Gain;                     /* Expression: 1/288.15
                                        * Referenced by: '<S12>/1//T0'
                                        */
  real_T gkR_Value;                    /* Expression: -9.80665/(-0.0065*287)
                                        * Referenced by: '<S12>/-g//(k*R)'
                                        */
  real_T P0_Pa_Gain;                   /* Expression: 101325
                                        * Referenced by: '<S12>/P0_Pa'
                                        */
  real_T gR_Value;                     /* Expression: -9.80665/(287)
                                        * Referenced by: '<S12>/-g//R'
                                        */
  real_T Constant1_Value;              /* Expression: 11000
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T LimittoTropopause1_UpperSat;  /* Expression: inf
                                        * Referenced by: '<S12>/Limit to Tropopause1'
                                        */
  real_T LimittoTropopause1_LowerSat;  /* Expression: 0
                                        * Referenced by: '<S12>/Limit to Tropopause1'
                                        */
  real_T R_Gain;                       /* Expression: 287
                                        * Referenced by: '<S12>/R'
                                        */
  real_T Constant_Value_h;             /* Expression: 2
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T degrad2_Gain;                 /* Expression: pi/180
                                        * Referenced by: '<S1>/deg->rad2'
                                        */
  real_T p_radps_IC;                   /* Expression: 0
                                        * Referenced by: '<S14>/p_radps'
                                        */
  real_T ft_to_m_Gain_a;               /* Expression: 0.3048
                                        * Referenced by: '<S1>/ft_to_m'
                                        */
  real_T Constant32_Value;             /* Expression: 2
                                        * Referenced by: '<S1>/Constant32'
                                        */
  real_T r_radps_IC;                   /* Expression: 0
                                        * Referenced by: '<S14>/r_radps'
                                        */
  real_T Constant33_Value;             /* Expression: 2
                                        * Referenced by: '<S1>/Constant33'
                                        */
  real_T ft_to_m2_Gain;                /* Expression: 0.3048
                                        * Referenced by: '<S1>/ft_to_m   2'
                                        */
  real_T Constant35_Value;             /* Expression: 2
                                        * Referenced by: '<S1>/Constant35'
                                        */
  real_T q_radps_IC;                   /* Expression: 0
                                        * Referenced by: '<S14>/q_radps'
                                        */
  real_T Constant34_Value;             /* Expression: 2
                                        * Referenced by: '<S1>/Constant34'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant4'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant5'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: Inf
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: 0.1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Constant_Value_hz;            /* Expression: 0
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T rad2deg_Gain_e;               /* Expression: 180/pi
                                        * Referenced by: '<Root>/rad2deg'
                                        */
  real_T rad2deg1_Gain_c;              /* Expression: 180/pi
                                        * Referenced by: '<Root>/rad2deg1'
                                        */
  real_T Relay_OnVal;                  /* Expression: .001
                                        * Referenced by: '<S22>/Relay'
                                        */
  real_T Relay_OffVal;                 /* Expression: 0
                                        * Referenced by: '<S22>/Relay'
                                        */
  real_T Relay_YOn;                    /* Expression: 0
                                        * Referenced by: '<S22>/Relay'
                                        */
  real_T Relay_YOff;                   /* Expression: 1
                                        * Referenced by: '<S22>/Relay'
                                        */
  real_T Constant_Value_f;             /* Expression: 0.001
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S22>/Switch'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S19>/Gain1'
                                        */
  real_T mps2kt2_Gain;                 /* Expression: 1/0.51444444
                                        * Referenced by: '<Root>/mps2kt2'
                                        */
  real_T Gain2_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S19>/Gain2'
                                        */
  real_T Gain_Gain_i;                  /* Expression: -1
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T Constant2_Value_b;            /* Expression: 1
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T GammaR_Gain;                  /* Expression: 287*1.4
                                        * Referenced by: '<S12>/Gamma*R'
                                        */
  real_T Gamma12_Gain;                 /* Expression: (1.4-1)/2
                                        * Referenced by: '<S13>/(Gamma-1)//2'
                                        */
  real_T GammaGamma1_Value;            /* Expression: 1.4/(1.4-1)
                                        * Referenced by: '<S13>/Gamma//(Gamma-1)'
                                        */
  real_T P0_Pa_Value;                  /* Expression: 101325
                                        * Referenced by: '<S13>/P0_Pa'
                                        */
  real_T Gamma1Gamma_Value;            /* Expression: (1.4-1)/1.4
                                        * Referenced by: '<S13>/(Gamma-1)//Gamma'
                                        */
  real_T ua02Gamma1_Gain;              /* Expression: (2*340.262^2)/(1.4-1)
                                        * Referenced by: '<S13>/2*a0^2//(Gamma-1)'
                                        */
  real_T mps2kt_Gain;                  /* Expression: 1/0.51444444
                                        * Referenced by: '<Root>/mps2kt'
                                        */
  real_T m2ft_Gain;                    /* Expression: -1/0.3048
                                        * Referenced by: '<Root>/m2ft'
                                        */
  real_T mps2kt1_Gain;                 /* Expression: 1/0.51444444
                                        * Referenced by: '<Root>/mps2kt1'
                                        */
  real_T XI_m_IC;                      /* Expression: 0
                                        * Referenced by: '<S18>/XI_m'
                                        */
  real_T YI_m1_IC;                     /* Expression: 0
                                        * Referenced by: '<S18>/YI_m1'
                                        */
  uint16_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_FlightSimulation_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_FlightSimulation_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[12];
  real_T odeF[3][12];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_FlightSimulation_T FlightSimulation_P;

/* Block signals (default storage) */
extern B_FlightSimulation_T FlightSimulation_B;

/* Continuous states (default storage) */
extern X_FlightSimulation_T FlightSimulation_X;

/* Block states (default storage) */
extern DW_FlightSimulation_T FlightSimulation_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_FlightSimulation_T FlightSimulation_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_FlightSimulation_T FlightSimulation_Y;

/* Model entry point functions */
extern void FlightSimulation_initialize(void);
extern void FlightSimulation_step(void);
extern void FlightSimulation_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FlightSimulation_T *const FlightSimulation_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FlightSimulation'
 * '<S1>'   : 'FlightSimulation/AeroModel'
 * '<S2>'   : 'FlightSimulation/AtmosphericModel'
 * '<S3>'   : 'FlightSimulation/EoM_6DoF'
 * '<S4>'   : 'FlightSimulation/PropulsionModel'
 * '<S5>'   : 'FlightSimulation/AeroModel/C_D'
 * '<S6>'   : 'FlightSimulation/AeroModel/C_L'
 * '<S7>'   : 'FlightSimulation/AeroModel/C_Y'
 * '<S8>'   : 'FlightSimulation/AeroModel/C_l'
 * '<S9>'   : 'FlightSimulation/AeroModel/C_m'
 * '<S10>'  : 'FlightSimulation/AeroModel/C_n'
 * '<S11>'  : 'FlightSimulation/AeroModel/Transformation_matrix'
 * '<S12>'  : 'FlightSimulation/AtmosphericModel/ISA'
 * '<S13>'  : 'FlightSimulation/AtmosphericModel/TAS2CAS'
 * '<S14>'  : 'FlightSimulation/EoM_6DoF/BodyRates'
 * '<S15>'  : 'FlightSimulation/EoM_6DoF/BodyVelocities'
 * '<S16>'  : 'FlightSimulation/EoM_6DoF/EulerRates'
 * '<S17>'  : 'FlightSimulation/EoM_6DoF/ExtForcesMoments'
 * '<S18>'  : 'FlightSimulation/EoM_6DoF/InertialData'
 * '<S19>'  : 'FlightSimulation/EoM_6DoF/TrajectoryData'
 * '<S20>'  : 'FlightSimulation/EoM_6DoF/BodyRates/CrossProduct'
 * '<S21>'  : 'FlightSimulation/EoM_6DoF/BodyVelocities/CrossProduct'
 * '<S22>'  : 'FlightSimulation/EoM_6DoF/EulerRates/EulerRates'
 * '<S23>'  : 'FlightSimulation/EoM_6DoF/EulerRates/LBE_rotation'
 * '<S24>'  : 'FlightSimulation/EoM_6DoF/EulerRates/EulerRates/MATLAB Function'
 * '<S25>'  : 'FlightSimulation/EoM_6DoF/EulerRates/EulerRates/MATLAB Function1'
 * '<S26>'  : 'FlightSimulation/EoM_6DoF/EulerRates/EulerRates/MATLAB Function2'
 * '<S27>'  : 'FlightSimulation/EoM_6DoF/EulerRates/LBE_rotation/MATLAB Function'
 * '<S28>'  : 'FlightSimulation/EoM_6DoF/EulerRates/LBE_rotation/MATLAB Function1'
 * '<S29>'  : 'FlightSimulation/EoM_6DoF/EulerRates/LBE_rotation/MATLAB Function2'
 * '<S30>'  : 'FlightSimulation/EoM_6DoF/EulerRates/LBE_rotation/MATLAB Function3'
 * '<S31>'  : 'FlightSimulation/EoM_6DoF/EulerRates/LBE_rotation/MATLAB Function4'
 * '<S32>'  : 'FlightSimulation/EoM_6DoF/EulerRates/LBE_rotation/MATLAB Function5'
 * '<S33>'  : 'FlightSimulation/EoM_6DoF/EulerRates/LBE_rotation/MATLAB Function6'
 * '<S34>'  : 'FlightSimulation/EoM_6DoF/EulerRates/LBE_rotation/MATLAB Function7'
 * '<S35>'  : 'FlightSimulation/EoM_6DoF/EulerRates/LBE_rotation/MATLAB Function8'
 */
#endif                                 /* RTW_HEADER_FlightSimulation_h_ */
