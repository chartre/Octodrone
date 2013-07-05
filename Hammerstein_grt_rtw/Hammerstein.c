/*
 * Hammerstein.c
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
#include "Hammerstein.h"
#include "Hammerstein_private.h"

/* Block signals (auto storage) */
BlockIO_Hammerstein Hammerstein_B;

/* Block states (auto storage) */
D_Work_Hammerstein Hammerstein_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_Hammerstein Hammerstein_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_Hammerstein Hammerstein_Y;

/* Real-time model */
RT_MODEL_Hammerstein Hammerstein_M_;
RT_MODEL_Hammerstein *const Hammerstein_M = &Hammerstein_M_;

/* Model step function */
void Hammerstein_step(void)
{
  /* DiscreteStateSpace: '<S1>/LinearModel' */
  {
    Hammerstein_B.LinearModel = Hammerstein_P.LinearModel_C*
      Hammerstein_DWork.LinearModel_DSTATE;
  }

  /* Level2 S-Function Block: '<S1>/Pwlinear1' (sfunpwlinear) */
  {
    SimStruct *rts = Hammerstein_M->childSfunctions[0];
    ssSetOutputPortSignal(rts, 0, &Hammerstein_Y.Out1);
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S1>/Pwlinear' (sfunpwlinear) */
  {
    SimStruct *rts = Hammerstein_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* Update for DiscreteStateSpace: '<S1>/LinearModel' */
  {
    Hammerstein_DWork.LinearModel_DSTATE = Hammerstein_B.Pwlinear +
      Hammerstein_P.LinearModel_A*Hammerstein_DWork.LinearModel_DSTATE;
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(Hammerstein_M->rtwLogInfo, (Hammerstein_M->Timing.t));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.06s, 0.0s] */
    if ((rtmGetTFinal(Hammerstein_M)!=-1) &&
        !((rtmGetTFinal(Hammerstein_M)-Hammerstein_M->Timing.t[0]) >
          Hammerstein_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(Hammerstein_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Hammerstein_M)) {
      rtmSetErrorStatus(Hammerstein_M, "Simulation finished");
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
  if (!(++Hammerstein_M->Timing.clockTick0)) {
    ++Hammerstein_M->Timing.clockTickH0;
  }

  Hammerstein_M->Timing.t[0] = Hammerstein_M->Timing.clockTick0 *
    Hammerstein_M->Timing.stepSize0 + Hammerstein_M->Timing.clockTickH0 *
    Hammerstein_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Hammerstein_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Hammerstein_M, 0,
                sizeof(RT_MODEL_Hammerstein));
  rtsiSetSolverName(&Hammerstein_M->solverInfo,"FixedStepDiscrete");
  Hammerstein_M->solverInfoPtr = (&Hammerstein_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Hammerstein_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Hammerstein_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Hammerstein_M->Timing.sampleTimes = (&Hammerstein_M->
      Timing.sampleTimesArray[0]);
    Hammerstein_M->Timing.offsetTimes = (&Hammerstein_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    Hammerstein_M->Timing.sampleTimes[0] = (0.06);

    /* task offsets */
    Hammerstein_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Hammerstein_M, &Hammerstein_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Hammerstein_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Hammerstein_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Hammerstein_M, 9.9599999999999991);
  Hammerstein_M->Timing.stepSize0 = 0.06;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Hammerstein_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Hammerstein_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Hammerstein_M->rtwLogInfo, (NULL));
    rtliSetLogT(Hammerstein_M->rtwLogInfo, "tout");
    rtliSetLogX(Hammerstein_M->rtwLogInfo, "");
    rtliSetLogXFinal(Hammerstein_M->rtwLogInfo, "");
    rtliSetSigLog(Hammerstein_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Hammerstein_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Hammerstein_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Hammerstein_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Hammerstein_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &Hammerstein_Y.Out1
      };

      rtliSetLogYSignalPtrs(Hammerstein_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "Hammerstein/Out1" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
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

      rtliSetLogYSignalInfo(Hammerstein_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(Hammerstein_M->rtwLogInfo, "yout");
  }

  Hammerstein_M->solverInfoPtr = (&Hammerstein_M->solverInfo);
  Hammerstein_M->Timing.stepSize = (0.06);
  rtsiSetFixedStepSize(&Hammerstein_M->solverInfo, 0.06);
  rtsiSetSolverMode(&Hammerstein_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &Hammerstein_B), 0,
                sizeof(BlockIO_Hammerstein));

  /* states (dwork) */
  (void) memset((void *)&Hammerstein_DWork, 0,
                sizeof(D_Work_Hammerstein));

  /* external inputs */
  Hammerstein_U.In1 = 0.0;

  /* external outputs */
  Hammerstein_Y.Out1 = 0.0;

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Hammerstein_M->NonInlinedSFcns.sfcnInfo;
    Hammerstein_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Hammerstein_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Hammerstein_M->Sizes.numSampTimes);
    Hammerstein_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(Hammerstein_M)
      [0]);
    rtssSetTPtrPtr(sfcnInfo,Hammerstein_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Hammerstein_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Hammerstein_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Hammerstein_M));
    rtssSetStepSizePtr(sfcnInfo, &Hammerstein_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Hammerstein_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Hammerstein_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Hammerstein_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &Hammerstein_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Hammerstein_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Hammerstein_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Hammerstein_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Hammerstein_M->solverInfoPtr);
  }

  Hammerstein_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&Hammerstein_M->NonInlinedSFcns.childSFunctions[0], 0,
                  2*sizeof(SimStruct));
    Hammerstein_M->childSfunctions =
      (&Hammerstein_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    Hammerstein_M->childSfunctions[0] =
      (&Hammerstein_M->NonInlinedSFcns.childSFunctions[0]);
    Hammerstein_M->childSfunctions[1] =
      (&Hammerstein_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: Hammerstein/<S1>/Pwlinear1 (sfunpwlinear) */
    {
      SimStruct *rts = Hammerstein_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Hammerstein_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Hammerstein_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Hammerstein_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Hammerstein_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, Hammerstein_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Hammerstein_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Hammerstein_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Hammerstein_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Hammerstein_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Hammerstein_B.LinearModel);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Hammerstein_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Hammerstein_Y.Out1));
        }
      }

      /* path info */
      ssSetModelName(rts, "Pwlinear1");
      ssSetPath(rts, "Hammerstein/Hammerstein-Wiener Model1/Pwlinear1");
      ssSetRTModel(rts,Hammerstein_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Hammerstein_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Hammerstein_P.Pwlinear1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Hammerstein_P.Pwlinear1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Hammerstein_P.Pwlinear1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Hammerstein_P.Pwlinear1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)Hammerstein_P.Pwlinear1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)Hammerstein_P.Pwlinear1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)Hammerstein_P.Pwlinear1_P7_Size);
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

    /* Level2 S-Function Block: Hammerstein/<S1>/Pwlinear (sfunpwlinear) */
    {
      SimStruct *rts = Hammerstein_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Hammerstein_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Hammerstein_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Hammerstein_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Hammerstein_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, Hammerstein_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Hammerstein_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Hammerstein_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Hammerstein_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Hammerstein_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &Hammerstein_U.In1);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Hammerstein_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Hammerstein_B.Pwlinear));
        }
      }

      /* path info */
      ssSetModelName(rts, "Pwlinear");
      ssSetPath(rts, "Hammerstein/Hammerstein-Wiener Model1/Pwlinear");
      ssSetRTModel(rts,Hammerstein_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Hammerstein_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Hammerstein_P.Pwlinear_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Hammerstein_P.Pwlinear_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Hammerstein_P.Pwlinear_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Hammerstein_P.Pwlinear_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)Hammerstein_P.Pwlinear_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)Hammerstein_P.Pwlinear_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)Hammerstein_P.Pwlinear_P7_Size);
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
  rt_StartDataLoggingWithStartTime(Hammerstein_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Hammerstein_M), Hammerstein_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Hammerstein_M)));

  /* Level2 S-Function Block: '<S1>/Pwlinear1' (sfunpwlinear) */
  {
    SimStruct *rts = Hammerstein_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/Pwlinear' (sfunpwlinear) */
  {
    SimStruct *rts = Hammerstein_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscreteStateSpace: '<S1>/LinearModel' */
  Hammerstein_DWork.LinearModel_DSTATE = Hammerstein_P.LinearModel_X0;

  /* Level2 S-Function Block: '<S1>/Pwlinear1' (sfunpwlinear) */
  {
    SimStruct *rts = Hammerstein_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/Pwlinear' (sfunpwlinear) */
  {
    SimStruct *rts = Hammerstein_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void Hammerstein_terminate(void)
{
  /* Level2 S-Function Block: '<S1>/Pwlinear1' (sfunpwlinear) */
  {
    SimStruct *rts = Hammerstein_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/Pwlinear' (sfunpwlinear) */
  {
    SimStruct *rts = Hammerstein_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}
