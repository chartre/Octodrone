/*
 * Hammerstein.h
 *
 * Code generation for model "Hammerstein".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Sat Jun 22 16:55:03 2013
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_Hammerstein_h_
#define RTW_HEADER_Hammerstein_h_
#ifndef Hammerstein_COMMON_INCLUDES_
# define Hammerstein_COMMON_INCLUDES_
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#endif                                 /* Hammerstein_COMMON_INCLUDES_ */

#include "Hammerstein_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T LinearModel;                  /* '<S1>/LinearModel' */
  real_T Pwlinear;                     /* '<S1>/Pwlinear' */
} BlockIO_Hammerstein;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T LinearModel_DSTATE;           /* '<S1>/LinearModel' */
} D_Work_Hammerstein;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
} ExternalInputs_Hammerstein;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExternalOutputs_Hammerstein;

/* Parameters (auto storage) */
struct Parameters_Hammerstein_ {
  real_T LinearModel_A;                /* Computed Parameter: LinearModel_A
                                        * Referenced by: '<S1>/LinearModel'
                                        */
  real_T LinearModel_C;                /* Computed Parameter: LinearModel_C
                                        * Referenced by: '<S1>/LinearModel'
                                        */
  real_T LinearModel_X0;               /* Expression: X0
                                        * Referenced by: '<S1>/LinearModel'
                                        */
  real_T Pwlinear1_P1_Size[2];         /* Computed Parameter: Pwlinear1_P1_Size
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */
  real_T Pwlinear1_P1;                 /* Expression: Ts
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */
  real_T Pwlinear1_P2_Size[2];         /* Computed Parameter: Pwlinear1_P2_Size
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */
  real_T Pwlinear1_P2;                 /* Expression: NumReg
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */
  real_T Pwlinear1_P3_Size[2];         /* Computed Parameter: Pwlinear1_P3_Size
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */
  real_T Pwlinear1_P3;                 /* Expression: NumUnits
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */
  real_T Pwlinear1_P4_Size[2];         /* Computed Parameter: Pwlinear1_P4_Size
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */
  real_T Pwlinear1_P4;                 /* Expression: LinearCoef
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */
  real_T Pwlinear1_P5_Size[2];         /* Computed Parameter: Pwlinear1_P5_Size
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */
  real_T Pwlinear1_P5;                 /* Expression: OutputOffset
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */
  real_T Pwlinear1_P6_Size[2];         /* Computed Parameter: Pwlinear1_P6_Size
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */
  real_T Pwlinear1_P6[10];             /* Expression: OutputCoef
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */
  real_T Pwlinear1_P7_Size[2];         /* Computed Parameter: Pwlinear1_P7_Size
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */
  real_T Pwlinear1_P7[10];             /* Expression: Translation
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */
  real_T Pwlinear_P1_Size[2];          /* Computed Parameter: Pwlinear_P1_Size
                                        * Referenced by: '<S1>/Pwlinear'
                                        */
  real_T Pwlinear_P1;                  /* Expression: Ts
                                        * Referenced by: '<S1>/Pwlinear'
                                        */
  real_T Pwlinear_P2_Size[2];          /* Computed Parameter: Pwlinear_P2_Size
                                        * Referenced by: '<S1>/Pwlinear'
                                        */
  real_T Pwlinear_P2;                  /* Expression: NumReg
                                        * Referenced by: '<S1>/Pwlinear'
                                        */
  real_T Pwlinear_P3_Size[2];          /* Computed Parameter: Pwlinear_P3_Size
                                        * Referenced by: '<S1>/Pwlinear'
                                        */
  real_T Pwlinear_P3;                  /* Expression: NumUnits
                                        * Referenced by: '<S1>/Pwlinear'
                                        */
  real_T Pwlinear_P4_Size[2];          /* Computed Parameter: Pwlinear_P4_Size
                                        * Referenced by: '<S1>/Pwlinear'
                                        */
  real_T Pwlinear_P4;                  /* Expression: LinearCoef
                                        * Referenced by: '<S1>/Pwlinear'
                                        */
  real_T Pwlinear_P5_Size[2];          /* Computed Parameter: Pwlinear_P5_Size
                                        * Referenced by: '<S1>/Pwlinear'
                                        */
  real_T Pwlinear_P5;                  /* Expression: OutputOffset
                                        * Referenced by: '<S1>/Pwlinear'
                                        */
  real_T Pwlinear_P6_Size[2];          /* Computed Parameter: Pwlinear_P6_Size
                                        * Referenced by: '<S1>/Pwlinear'
                                        */
  real_T Pwlinear_P6[10];              /* Expression: OutputCoef
                                        * Referenced by: '<S1>/Pwlinear'
                                        */
  real_T Pwlinear_P7_Size[2];          /* Computed Parameter: Pwlinear_P7_Size
                                        * Referenced by: '<S1>/Pwlinear'
                                        */
  real_T Pwlinear_P7[10];              /* Expression: Translation
                                        * Referenced by: '<S1>/Pwlinear'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Hammerstein {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[1];
    SimStruct childSFunctions[2];
    SimStruct *childSFunctionPtrs[2];
    struct _ssBlkInfo2 blkInfo2[2];
    struct _ssSFcnModelMethods2 methods2[2];
    struct _ssSFcnModelMethods3 methods3[2];
    struct _ssStatesInfo2 statesInfo2[2];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
    } Sfcn1;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_Hammerstein Hammerstein_P;

/* Block signals (auto storage) */
extern BlockIO_Hammerstein Hammerstein_B;

/* Block states (auto storage) */
extern D_Work_Hammerstein Hammerstein_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_Hammerstein Hammerstein_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_Hammerstein Hammerstein_Y;

/* Model entry point functions */
extern void Hammerstein_initialize(void);
extern void Hammerstein_step(void);
extern void Hammerstein_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Hammerstein *const Hammerstein_M;

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
#endif                                 /* RTW_HEADER_Hammerstein_h_ */
