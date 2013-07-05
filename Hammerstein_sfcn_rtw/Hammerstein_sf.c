/*
 * Hammerstein_sf.c
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
#include <math.h>
#include "Hammerstein_sf.h"
#include "Hammerstein_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *Hammerstein_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/* Initial conditions for root system: '<Root>' */
#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  BlockIO_Hammerstein *_rtB;
  _rtB = ((BlockIO_Hammerstein *) ssGetLocalBlockIO(S));

  /* InitializeConditions for DiscreteStateSpace: '<S1>/LinearModel' */
  ((real_T*) ssGetDWork(S, 0))[0] = 0.0;

  /* Level2 S-Function Block: '<S1>/Pwlinear1' (sfunpwlinear) */
  {
    SimStruct *rts = ssGetSFunction(S, 0);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/Pwlinear' (sfunpwlinear) */
  {
    SimStruct *rts = ssGetSFunction(S, 1);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Start for root system: '<Root>' */
#define MDL_START

static void mdlStart(SimStruct *S)
{
  /* instance underlying S-Function data */
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  if defined(MATLAB_MEX_FILE)

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

#  endif

  Hammerstein_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
    BlockIO_Hammerstein *_rtB;
    _rtB = ((BlockIO_Hammerstein *) ssGetLocalBlockIO(S));

    /* Level2 S-Function Block: '<S1>/Pwlinear1' (sfunpwlinear) */
    {
      SimStruct *rts = ssGetSFunction(S, 0);
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Level2 S-Function Block: '<S1>/Pwlinear' (sfunpwlinear) */
    {
      SimStruct *rts = ssGetSFunction(S, 1);
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  BlockIO_Hammerstein *_rtB;
  _rtB = ((BlockIO_Hammerstein *) ssGetLocalBlockIO(S));

  /* DiscreteStateSpace: '<S1>/LinearModel' */
  {
    ((BlockIO_Hammerstein *) ssGetLocalBlockIO(S))->LinearModel = 1.0*((real_T*)
      ssGetDWork(S, 0))[0];
  }

  /* Level2 S-Function Block: '<S1>/Pwlinear1' (sfunpwlinear) */
  {
    SimStruct *rts = ssGetSFunction(S, 0);
    sfcnOutputs(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Outport: '<Root>/Out1' */
  ((real_T *)ssGetOutputPortSignal(S, 0))[0] = _rtB->Pwlinear1;

  /* Level2 S-Function Block: '<S1>/Pwlinear' (sfunpwlinear) */
  {
    SimStruct *rts = ssGetSFunction(S, 1);
    sfcnOutputs(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  BlockIO_Hammerstein *_rtB;
  _rtB = ((BlockIO_Hammerstein *) ssGetLocalBlockIO(S));

  /* Update for DiscreteStateSpace: '<S1>/LinearModel' */
  {
    ((real_T*) ssGetDWork(S, 0))[0] = ((BlockIO_Hammerstein *) ssGetLocalBlockIO
                                       (S))->Pwlinear + 0.95520909191040437*
      ((real_T*) ssGetDWork(S, 0))[0];
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
static void mdlTerminate(SimStruct *S)
{
  BlockIO_Hammerstein *_rtB;
  _rtB = ((BlockIO_Hammerstein *) ssGetLocalBlockIO(S));

  /* Level2 S-Function Block: '<S1>/Pwlinear1' (sfunpwlinear) */
  {
    SimStruct *rts = ssGetSFunction(S, 0);
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/Pwlinear' (sfunpwlinear) */
  {
    SimStruct *rts = ssGetSFunction(S, 1);
    sfcnTerminate(rts);
  }

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

  /* child S-function code */
  if (_ssGetSFunctions(S) ) {
    /* Level2 S-Function Block: '<S1>/Pwlinear1' (sfunpwlinear) */
    {
      SimStruct *rts = ssGetSFunction(S, 0);
      if (rts != (NULL) ) {
        rt_FREE(ssGetSampleTimePtr(rts));
        rt_FREE(ssGetOffsetTimePtr(rts));
        rt_FREE(ssGetSampleTimeTaskIDPtr(rts));

#if defined(MATLAB_MEX_FILE)

        {
          uint_T *attribs = ssGetSFcnParamAttribsPtr(rts);
          mxFree(attribs);
        }

#endif

#if defined(MATLAB_MEX_FILE)

        {
          {
            mxDestroyArray(_ssGetSFcnParam(rts, 0));
          }

          {
            mxDestroyArray(_ssGetSFcnParam(rts, 1));
          }

          {
            mxDestroyArray(_ssGetSFcnParam(rts, 2));
          }

          {
            mxDestroyArray(_ssGetSFcnParam(rts, 3));
          }

          {
            mxDestroyArray(_ssGetSFcnParam(rts, 4));
          }

          {
            mxDestroyArray(_ssGetSFcnParam(rts, 5));
          }

          {
            mxDestroyArray(_ssGetSFcnParam(rts, 6));
          }
        }

#endif

        {
          mxArray **ptr = (mxArray **) ssGetSFcnParamsPtr(rts);
          rt_FREE(ptr);
        }

        /* Destroy model methods 3 */
        {
          struct _ssSFcnModelMethods3 *methods3 = ssGetModelMethods3(rts);
          rt_FREE(methods3);
        }

        /* Destroy model methods 2 */
        {
          struct _ssSFcnModelMethods2 *methods2 = ssGetModelMethods2(rts);
          rt_FREE(methods2);
        }

        /* Destroy state auxilliary information */
        {
          struct _ssStatesInfo2 *statesInfo2 = ssGetStatesInfo2(rts);
          rt_FREE(statesInfo2);
        }

        {
        }

        rt_FREE(ssGetPortInfoForInputs(rts));
        rt_FREE(ssGetPortInfoForOutputs(rts));
      }
    }

    /* Level2 S-Function Block: '<S1>/Pwlinear' (sfunpwlinear) */
    {
      SimStruct *rts = ssGetSFunction(S, 1);
      if (rts != (NULL) ) {
        rt_FREE(ssGetSampleTimePtr(rts));
        rt_FREE(ssGetOffsetTimePtr(rts));
        rt_FREE(ssGetSampleTimeTaskIDPtr(rts));

#if defined(MATLAB_MEX_FILE)

        {
          uint_T *attribs = ssGetSFcnParamAttribsPtr(rts);
          mxFree(attribs);
        }

#endif

#if defined(MATLAB_MEX_FILE)

        {
          {
            mxDestroyArray(_ssGetSFcnParam(rts, 0));
          }

          {
            mxDestroyArray(_ssGetSFcnParam(rts, 1));
          }

          {
            mxDestroyArray(_ssGetSFcnParam(rts, 2));
          }

          {
            mxDestroyArray(_ssGetSFcnParam(rts, 3));
          }

          {
            mxDestroyArray(_ssGetSFcnParam(rts, 4));
          }

          {
            mxDestroyArray(_ssGetSFcnParam(rts, 5));
          }

          {
            mxDestroyArray(_ssGetSFcnParam(rts, 6));
          }
        }

#endif

        {
          mxArray **ptr = (mxArray **) ssGetSFcnParamsPtr(rts);
          rt_FREE(ptr);
        }

        /* Destroy model methods 3 */
        {
          struct _ssSFcnModelMethods3 *methods3 = ssGetModelMethods3(rts);
          rt_FREE(methods3);
        }

        /* Destroy model methods 2 */
        {
          struct _ssSFcnModelMethods2 *methods2 = ssGetModelMethods2(rts);
          rt_FREE(methods2);
        }

        /* Destroy state auxilliary information */
        {
          struct _ssStatesInfo2 *statesInfo2 = ssGetStatesInfo2(rts);
          rt_FREE(statesInfo2);
        }

        {
        }

        rt_FREE(ssGetPortInfoForInputs(rts));
        rt_FREE(ssGetPortInfoForOutputs(rts));
      }
    }

    rt_FREE(ssGetSFunction(S, 0))
      rt_FREE(_ssGetSFunctions(S));
  }

  if (ssGetUserData(S) != (NULL) ) {
    rt_FREE(ssGetLocalBlockIO(S));
  }

  rt_FREE(ssGetUserData(S));

#endif

}

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "Hammerstein_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 1);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 1))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 0, 0.06);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 1))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortSampleTime(S, 0, 0.06);
    ssSetInputPortOffsetTime(S, 0, 0.0);
    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 1)) {
    return;
  }

  /* '<S1>/LinearModel': DSTATE */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);
  ssSetDWorkUsedAsDState(S, 0, 1);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 0);

  /* Number of expected parameters */
#if defined(MATLAB_MEX_FILE)

  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {

#if defined(MDL_CHECK_PARAMETERS)

    mdlCheckParameters(S);

#endif                                 /* MDL_CHECK_PARAMETERS */

    if (ssGetErrorStatus(S) != (NULL) ) {
      return;
    }
  } else {
    return;                            /* Parameter mismatch will be reported by Simulink */
  }

#endif                                 /* MATLAB_MEX_FILE */

  /* Options */
  ssSetOptions(S, (SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE |
                   SS_OPTION_PORT_SAMPLE_TIMES_ASSIGNED ));

#if SS_SFCN_FOR_SIM

  {
    ssSupportsMultipleExecInstances(S, false);
    ssRegisterMsgForNotSupportingMultiExecInst(S,
      "<diag_root><diag id=\"Simulink:blocks:BlockDoesNotSupportMultiExecInstances\"><arguments><arg type=\"encoded\">SABhAG0AbQBlAHIAcwB0AGUAaQBuAC8ASABhAG0AbQBlAHIAcwB0AGUAaQBuAC0AVwBpAGUAbgBlAHIAIABNAG8AZABlAGwAMQAvAFAAdwBsAGkAbgBlAGEAcgAxAAAA</arg><arg type=\"encoded\">PABfAF8AaQBpAFMAUwBfAF8APgA8AC8AXwBfAGkAaQBTAFMAXwBfAD4AAAA=</arg><arg type=\"encoded\">PABfAF8AaQB0AGUAcgBCAGwAawBfAF8APgA8AC8AXwBfAGkAdABlAHIAQgBsAGsAXwBfAD4AAAA=</arg></arguments></diag>\n</diag_root>");
    ssHasStateInsideForEachSS(S, false);
  }

#endif

}

/* Function to initialize sample times. */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  /* task periods */
  ssSetSampleTime(S, 0, 0.06);

  /* task offsets */
  ssSetOffsetTime(S, 0, 0.0);
}

#if defined(MATLAB_MEX_FILE)
# include "fixedpoint.c"
# include "simulink.c"
#else
# undef S_FUNCTION_NAME
# define S_FUNCTION_NAME               Hammerstein_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
