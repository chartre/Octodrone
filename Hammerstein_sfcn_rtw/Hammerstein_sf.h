/*
 * Hammerstein_sf.h
 *
 * Code generation for model "Hammerstein_sf".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Sat Jun 22 17:30:24 2013
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_Hammerstein_sf_h_
#define RTW_HEADER_Hammerstein_sf_h_
#ifndef Hammerstein_sf_COMMON_INCLUDES_
# define Hammerstein_sf_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#define S_FUNCTION_NAME                Hammerstein_sf
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#if !defined(MATLAB_MEX_FILE)
#include "rt_matrx.h"
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif                                 /* Hammerstein_sf_COMMON_INCLUDES_ */

#include "Hammerstein_sf_types.h"

/* Block signals (auto storage) */
typedef struct {
  real_T LinearModel;                  /* '<S1>/LinearModel' */
  real_T Pwlinear1;                    /* '<S1>/Pwlinear1' */
  real_T Pwlinear;                     /* '<S1>/Pwlinear' */
} BlockIO_Hammerstein;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S1>/Pwlinear'
   *   '<S1>/Pwlinear1'
   */
  real_T pooled1[2];

  /* Pooled Parameter (Expression: Ts)
   * Referenced by:
   *   '<S1>/Pwlinear'
   *   '<S1>/Pwlinear1'
   */
  real_T pooled2;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S1>/Pwlinear'
   *   '<S1>/Pwlinear1'
   */
  real_T pooled3[2];

  /* Pooled Parameter (Expression: NumReg)
   * Referenced by:
   *   '<S1>/Pwlinear'
   *   '<S1>/Pwlinear1'
   */
  real_T pooled4;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S1>/Pwlinear'
   *   '<S1>/Pwlinear1'
   */
  real_T pooled5[2];

  /* Pooled Parameter (Expression: NumUnits)
   * Referenced by:
   *   '<S1>/Pwlinear'
   *   '<S1>/Pwlinear1'
   */
  real_T pooled6;

  /* Computed Parameter: Pwlinear1_P4_Size
   * Referenced by: '<S1>/Pwlinear1'
   */
  real_T Pwlinear1_P4_Size[2];

  /* Expression: LinearCoef
   * Referenced by: '<S1>/Pwlinear1'
   */
  real_T Pwlinear1_P4;

  /* Computed Parameter: Pwlinear1_P5_Size
   * Referenced by: '<S1>/Pwlinear1'
   */
  real_T Pwlinear1_P5_Size[2];

  /* Expression: OutputOffset
   * Referenced by: '<S1>/Pwlinear1'
   */
  real_T Pwlinear1_P5;

  /* Computed Parameter: Pwlinear1_P6_Size
   * Referenced by: '<S1>/Pwlinear1'
   */
  real_T Pwlinear1_P6_Size[2];

  /* Expression: OutputCoef
   * Referenced by: '<S1>/Pwlinear1'
   */
  real_T Pwlinear1_P6[10];

  /* Computed Parameter: Pwlinear1_P7_Size
   * Referenced by: '<S1>/Pwlinear1'
   */
  real_T Pwlinear1_P7_Size[2];

  /* Expression: Translation
   * Referenced by: '<S1>/Pwlinear1'
   */
  real_T Pwlinear1_P7[10];

  /* Computed Parameter: Pwlinear_P4_Size
   * Referenced by: '<S1>/Pwlinear'
   */
  real_T Pwlinear_P4_Size[2];

  /* Expression: LinearCoef
   * Referenced by: '<S1>/Pwlinear'
   */
  real_T Pwlinear_P4;

  /* Computed Parameter: Pwlinear_P5_Size
   * Referenced by: '<S1>/Pwlinear'
   */
  real_T Pwlinear_P5_Size[2];

  /* Expression: OutputOffset
   * Referenced by: '<S1>/Pwlinear'
   */
  real_T Pwlinear_P5;

  /* Computed Parameter: Pwlinear_P6_Size
   * Referenced by: '<S1>/Pwlinear'
   */
  real_T Pwlinear_P6_Size[2];

  /* Expression: OutputCoef
   * Referenced by: '<S1>/Pwlinear'
   */
  real_T Pwlinear_P6[10];

  /* Computed Parameter: Pwlinear_P7_Size
   * Referenced by: '<S1>/Pwlinear'
   */
  real_T Pwlinear_P7_Size[2];

  /* Expression: Translation
   * Referenced by: '<S1>/Pwlinear'
   */
  real_T Pwlinear_P7[10];
} ConstParam_Hammerstein;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *In1;                         /* '<Root>/In1' */
} ExternalUPtrs_Hammerstein;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *Out1;                        /* '<Root>/Out1' */
} ExternalOutputs_Hammerstein;

/* Constant parameters (auto storage) */
extern const ConstParam_Hammerstein Hammerstein_ConstP;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Modelos/ Modelo/Hammerstein-Wiener Model1')    - opens subsystem Modelos/ Modelo/Hammerstein-Wiener Model1
 * hilite_system('Modelos/ Modelo/Hammerstein-Wiener Model1/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Modelos/ Modelo'
 * '<S1>'   : 'Modelos/ Modelo/Hammerstein-Wiener Model1'
 */
#endif                                 /* RTW_HEADER_Hammerstein_sf_h_ */
