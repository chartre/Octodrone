/*
 * Modelo.c
 *
 * Code generation for model "Modelo".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Sat Jun 22 16:57:22 2013
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Modelo.h"
#include "Modelo_private.h"

/* Block signals (auto storage) */
BlockIO_Modelo Modelo_B;

/* Block states (auto storage) */
D_Work_Modelo Modelo_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_Modelo Modelo_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_Modelo Modelo_Y;

/* Real-time model */
RT_MODEL_Modelo Modelo_M_;
RT_MODEL_Modelo *const Modelo_M = &Modelo_M_;

/* Model step function */
void Modelo_step(void)
{
  real_T rtb_Sum;

  /* DiscreteStateSpace: '<S2>/LinearModel' */
  {
    Modelo_B.LinearModel = Modelo_P.LinearModel_C[0]*
      Modelo_DWork.LinearModel_DSTATE[0] + Modelo_P.LinearModel_C[1]*
      Modelo_DWork.LinearModel_DSTATE[1]
      + Modelo_P.LinearModel_C[2]*Modelo_DWork.LinearModel_DSTATE[2];
  }

  /* Level2 S-Function Block: '<S2>/Pwlinear1' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[0];
    ssSetOutputPortSignal(rts, 0, &Modelo_Y.Vx);
    sfcnOutputs(rts, 0);
  }

  /* Outport: '<Root>/X' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
   */
  Modelo_Y.X = Modelo_DWork.DiscreteTimeIntegrator1_DSTATE;

  /* DiscreteStateSpace: '<S3>/LinearModel' */
  {
    Modelo_B.LinearModel_d = Modelo_P.LinearModel_C_o*
      Modelo_DWork.LinearModel_DSTATE_j;
  }

  /* Level2 S-Function Block: '<S3>/Pwlinear1' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[1];
    ssSetOutputPortSignal(rts, 0, &Modelo_Y.Vy);
    sfcnOutputs(rts, 0);
  }

  /* Outport: '<Root>/Y' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   */
  Modelo_Y.Y = Modelo_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Level2 S-Function Block: '<S2>/Pwlinear' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[2];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S3>/Pwlinear' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_Sum = Modelo_Y.Vy + Modelo_P.Constant_Value;

  /* Update for DiscreteStateSpace: '<S2>/LinearModel' */
  {
    real_T xtmp = Modelo_B.Pwlinear;
    xtmp += (Modelo_P.LinearModel_A[0])*Modelo_DWork.LinearModel_DSTATE[0]
      + (Modelo_P.LinearModel_A[1])*Modelo_DWork.LinearModel_DSTATE[1]
      + (Modelo_P.LinearModel_A[2])*Modelo_DWork.LinearModel_DSTATE[2];
    Modelo_DWork.LinearModel_DSTATE[2] = Modelo_DWork.LinearModel_DSTATE[1];
    Modelo_DWork.LinearModel_DSTATE[1] = Modelo_DWork.LinearModel_DSTATE[0];
    Modelo_DWork.LinearModel_DSTATE[0] = xtmp;
  }

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
  Modelo_DWork.DiscreteTimeIntegrator1_DSTATE +=
    Modelo_P.DiscreteTimeIntegrator1_gainval * Modelo_Y.Vx;

  /* Update for DiscreteStateSpace: '<S3>/LinearModel' */
  {
    Modelo_DWork.LinearModel_DSTATE_j = Modelo_B.Pwlinear_a +
      Modelo_P.LinearModel_A_p*Modelo_DWork.LinearModel_DSTATE_j;
  }

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  Modelo_DWork.DiscreteTimeIntegrator_DSTATE +=
    Modelo_P.DiscreteTimeIntegrator_gainval * rtb_Sum;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Modelo_M->rtwLogInfo, (Modelo_M->Timing.t));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.06s, 0.0s] */
    if ((rtmGetTFinal(Modelo_M)!=-1) &&
        !((rtmGetTFinal(Modelo_M)-Modelo_M->Timing.t[0]) > Modelo_M->Timing.t[0]
          * (DBL_EPSILON))) {
      rtmSetErrorStatus(Modelo_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Modelo_M)) {
      rtmSetErrorStatus(Modelo_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Modelo_M->Timing.clockTick0)) {
    ++Modelo_M->Timing.clockTickH0;
  }

  Modelo_M->Timing.t[0] = Modelo_M->Timing.clockTick0 *
    Modelo_M->Timing.stepSize0 + Modelo_M->Timing.clockTickH0 *
    Modelo_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Modelo_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Modelo_M, 0,
                sizeof(RT_MODEL_Modelo));
  rtsiSetSolverName(&Modelo_M->solverInfo,"FixedStepDiscrete");
  Modelo_M->solverInfoPtr = (&Modelo_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Modelo_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Modelo_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Modelo_M->Timing.sampleTimes = (&Modelo_M->Timing.sampleTimesArray[0]);
    Modelo_M->Timing.offsetTimes = (&Modelo_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Modelo_M->Timing.sampleTimes[0] = (0.06);

    /* task offsets */
    Modelo_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Modelo_M, &Modelo_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Modelo_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Modelo_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Modelo_M, 9.9599999999999991);
  Modelo_M->Timing.stepSize0 = 0.06;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Modelo_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Modelo_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Modelo_M->rtwLogInfo, (NULL));
    rtliSetLogT(Modelo_M->rtwLogInfo, "tout");
    rtliSetLogX(Modelo_M->rtwLogInfo, "");
    rtliSetLogXFinal(Modelo_M->rtwLogInfo, "");
    rtliSetSigLog(Modelo_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Modelo_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Modelo_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Modelo_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Modelo_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &Modelo_Y.Vx,
        &Modelo_Y.X,
        &Modelo_Y.Vy,
        &Modelo_Y.Y
      };

      rtliSetLogYSignalPtrs(Modelo_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4,
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "Modelo/Vx",
        "Modelo/X",
        "Modelo/Vy",
        "Modelo/Y" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          4,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(Modelo_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[3] = &rt_LoggedOutputWidths[3];
    }

    rtliSetLogY(Modelo_M->rtwLogInfo, "yout");
  }

  Modelo_M->solverInfoPtr = (&Modelo_M->solverInfo);
  Modelo_M->Timing.stepSize = (0.06);
  rtsiSetFixedStepSize(&Modelo_M->solverInfo, 0.06);
  rtsiSetSolverMode(&Modelo_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &Modelo_B), 0,
                sizeof(BlockIO_Modelo));

  /* states (dwork) */
  (void) memset((void *)&Modelo_DWork, 0,
                sizeof(D_Work_Modelo));

  /* external inputs */
  (void) memset((void *)&Modelo_U, 0,
                sizeof(ExternalInputs_Modelo));

  /* external outputs */
  (void) memset((void *)&Modelo_Y, 0,
                sizeof(ExternalOutputs_Modelo));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Modelo_M->NonInlinedSFcns.sfcnInfo;
    Modelo_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Modelo_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Modelo_M->Sizes.numSampTimes);
    Modelo_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(Modelo_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,Modelo_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Modelo_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Modelo_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Modelo_M));
    rtssSetStepSizePtr(sfcnInfo, &Modelo_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Modelo_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Modelo_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &Modelo_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &Modelo_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Modelo_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &Modelo_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Modelo_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Modelo_M->solverInfoPtr);
  }

  Modelo_M->Sizes.numSFcns = (4);

  /* register each child */
  {
    (void) memset((void *)&Modelo_M->NonInlinedSFcns.childSFunctions[0], 0,
                  4*sizeof(SimStruct));
    Modelo_M->childSfunctions = (&Modelo_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    Modelo_M->childSfunctions[0] = (&Modelo_M->NonInlinedSFcns.childSFunctions[0]);
    Modelo_M->childSfunctions[1] = (&Modelo_M->NonInlinedSFcns.childSFunctions[1]);
    Modelo_M->childSfunctions[2] = (&Modelo_M->NonInlinedSFcns.childSFunctions[2]);
    Modelo_M->childSfunctions[3] = (&Modelo_M->NonInlinedSFcns.childSFunctions[3]);

    /* Level2 S-Function Block: Modelo/<S2>/Pwlinear1 (sfunpwlinear) */
    {
      SimStruct *rts = Modelo_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Modelo_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Modelo_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Modelo_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Modelo_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, Modelo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Modelo_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Modelo_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Modelo_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Modelo_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Modelo_B.LinearModel);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Modelo_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Modelo_Y.Vx));
        }
      }

      /* path info */
      ssSetModelName(rts, "Pwlinear1");
      ssSetPath(rts, "Modelo/ Modelo/Hammerstein-Wiener Model/Pwlinear1");
      ssSetRTModel(rts,Modelo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Modelo_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Modelo_P.Pwlinear1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Modelo_P.Pwlinear1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Modelo_P.Pwlinear1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Modelo_P.Pwlinear1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)Modelo_P.Pwlinear1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)Modelo_P.Pwlinear1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)Modelo_P.Pwlinear1_P7_Size);
      }

      /* registration */
      sfunpwlinear(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.06);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Modelo/<S3>/Pwlinear1 (sfunpwlinear) */
    {
      SimStruct *rts = Modelo_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Modelo_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Modelo_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Modelo_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Modelo_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, Modelo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Modelo_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Modelo_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Modelo_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Modelo_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Modelo_B.LinearModel_d);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Modelo_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Modelo_Y.Vy));
        }
      }

      /* path info */
      ssSetModelName(rts, "Pwlinear1");
      ssSetPath(rts, "Modelo/ Modelo/Hammerstein-Wiener Model1/Pwlinear1");
      ssSetRTModel(rts,Modelo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Modelo_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Modelo_P.Pwlinear1_P1_Size_l);
        ssSetSFcnParam(rts, 1, (mxArray*)Modelo_P.Pwlinear1_P2_Size_p);
        ssSetSFcnParam(rts, 2, (mxArray*)Modelo_P.Pwlinear1_P3_Size_f);
        ssSetSFcnParam(rts, 3, (mxArray*)Modelo_P.Pwlinear1_P4_Size_k);
        ssSetSFcnParam(rts, 4, (mxArray*)Modelo_P.Pwlinear1_P5_Size_k);
        ssSetSFcnParam(rts, 5, (mxArray*)Modelo_P.Pwlinear1_P6_Size_n);
        ssSetSFcnParam(rts, 6, (mxArray*)Modelo_P.Pwlinear1_P7_Size_d);
      }

      /* registration */
      sfunpwlinear(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.06);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Modelo/<S2>/Pwlinear (sfunpwlinear) */
    {
      SimStruct *rts = Modelo_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Modelo_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Modelo_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Modelo_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Modelo_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, Modelo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Modelo_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Modelo_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Modelo_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Modelo_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Modelo_U.RefPitch);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Modelo_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Modelo_B.Pwlinear));
        }
      }

      /* path info */
      ssSetModelName(rts, "Pwlinear");
      ssSetPath(rts, "Modelo/ Modelo/Hammerstein-Wiener Model/Pwlinear");
      ssSetRTModel(rts,Modelo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Modelo_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Modelo_P.Pwlinear_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Modelo_P.Pwlinear_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Modelo_P.Pwlinear_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Modelo_P.Pwlinear_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)Modelo_P.Pwlinear_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)Modelo_P.Pwlinear_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)Modelo_P.Pwlinear_P7_Size);
      }

      /* registration */
      sfunpwlinear(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.06);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Modelo/<S3>/Pwlinear (sfunpwlinear) */
    {
      SimStruct *rts = Modelo_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Modelo_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Modelo_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Modelo_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Modelo_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, Modelo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Modelo_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Modelo_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Modelo_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Modelo_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Modelo_U.RefRoll);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Modelo_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Modelo_B.Pwlinear_a));
        }
      }

      /* path info */
      ssSetModelName(rts, "Pwlinear");
      ssSetPath(rts, "Modelo/ Modelo/Hammerstein-Wiener Model1/Pwlinear");
      ssSetRTModel(rts,Modelo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Modelo_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Modelo_P.Pwlinear_P1_Size_e);
        ssSetSFcnParam(rts, 1, (mxArray*)Modelo_P.Pwlinear_P2_Size_n);
        ssSetSFcnParam(rts, 2, (mxArray*)Modelo_P.Pwlinear_P3_Size_c);
        ssSetSFcnParam(rts, 3, (mxArray*)Modelo_P.Pwlinear_P4_Size_p);
        ssSetSFcnParam(rts, 4, (mxArray*)Modelo_P.Pwlinear_P5_Size_g);
        ssSetSFcnParam(rts, 5, (mxArray*)Modelo_P.Pwlinear_P6_Size_i);
        ssSetSFcnParam(rts, 6, (mxArray*)Modelo_P.Pwlinear_P7_Size_d);
      }

      /* registration */
      sfunpwlinear(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.06);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Modelo_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Modelo_M), Modelo_M->Timing.stepSize0, (&rtmGetErrorStatus(Modelo_M)));

  /* Level2 S-Function Block: '<S2>/Pwlinear1' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S3>/Pwlinear1' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S2>/Pwlinear' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S3>/Pwlinear' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscreteStateSpace: '<S2>/LinearModel' */
  Modelo_DWork.LinearModel_DSTATE[0] = Modelo_P.LinearModel_X0[0];
  Modelo_DWork.LinearModel_DSTATE[1] = Modelo_P.LinearModel_X0[1];
  Modelo_DWork.LinearModel_DSTATE[2] = Modelo_P.LinearModel_X0[2];

  /* Level2 S-Function Block: '<S2>/Pwlinear1' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
  Modelo_DWork.DiscreteTimeIntegrator1_DSTATE =
    Modelo_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for DiscreteStateSpace: '<S3>/LinearModel' */
  Modelo_DWork.LinearModel_DSTATE_j = Modelo_P.LinearModel_X0_k;

  /* Level2 S-Function Block: '<S3>/Pwlinear1' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  Modelo_DWork.DiscreteTimeIntegrator_DSTATE =
    Modelo_P.DiscreteTimeIntegrator_IC;

  /* Level2 S-Function Block: '<S2>/Pwlinear' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[2];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S3>/Pwlinear' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[3];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void Modelo_terminate(void)
{
  /* Level2 S-Function Block: '<S2>/Pwlinear1' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/Pwlinear1' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/Pwlinear' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/Pwlinear' (sfunpwlinear) */
  {
    SimStruct *rts = Modelo_M->childSfunctions[3];
    sfcnTerminate(rts);
  }
}
