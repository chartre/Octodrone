/*
 * Hammerstein_mid.h
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
 *
 * SOURCES: Hammerstein_sf.c
 */

#include "simstruc.h"
#include "Hammerstein_sf.h"
#if defined(MATLAB_MEX_FILE) || defined(RT_MALLOC)

static int_T RegNumInputPorts(SimStruct *S, int_T nInputPorts)
{
  _ssSetNumInputPorts(S,nInputPorts);
  return TRUE;
}

static int_T RegNumOutputPorts(SimStruct *S, int_T nOutputPorts)
{
  _ssSetNumOutputPorts(S,nOutputPorts);
  return TRUE;
}

static int_T FcnSetErrorStatus(const SimStruct *S, DTypeId arg2)
{
  static char msg[256];
  if (strlen(ssGetModelName(S)) < 128) {
    sprintf(msg,
            "S-function %s does not have a tlc file. It cannot use macros that access regDataType field in simstruct.",
            ssGetModelName(S));
  } else {
    sprintf(msg,
            "A S-function does not have a tlc file. It cannot use macros that access regDataType field in simstruct.");
  }

  ssSetErrorStatus(S, msg);
  return 0;
}

#endif

/* Instance data for model: Hammerstein */
void *Hammerstein_malloc(SimStruct *rts)
{
  /* Local SimStruct for the generated S-Function */
  LocalS *lS = (LocalS *) malloc(sizeof(LocalS));
  rt_VALIDATE_MEMORY(rts,lS);
  (void) memset((char *) lS, 0,
                sizeof(LocalS));
  ssSetUserData(rts, lS);

  /* block I/O */
  {
    void *b = malloc(sizeof(BlockIO_Hammerstein));
    rt_VALIDATE_MEMORY(rts,b);
    ssSetLocalBlockIO(rts, b);
    (void) memset(b, 0,
                  sizeof(BlockIO_Hammerstein));
  }

  /* model checksums */
  ssSetChecksumVal(rts, 0, 1875070921U);
  ssSetChecksumVal(rts, 1, 2097754143U);
  ssSetChecksumVal(rts, 2, 1963821520U);
  ssSetChecksumVal(rts, 3, 4202890453U);

  {
    /* child S-Function registration */
    ssSetNumSFunctions(rts, 2);

    /* register each child */
    {
      SimStruct *childSFunctions;
      SimStruct **childSFunctionPtrs;
      childSFunctions = (SimStruct *) malloc(2 * sizeof(SimStruct));
      rt_VALIDATE_MEMORY(rts,childSFunctions);
      (void) memset((void *)childSFunctions, 0,
                    2*sizeof(SimStruct));
      childSFunctionPtrs = (SimStruct **) malloc(2 * sizeof(SimStruct *));
      rt_VALIDATE_MEMORY(rts,childSFunctionPtrs);
      _ssSetSFunctions(rts, childSFunctionPtrs);
      _ssSetSFunction(rts, 0, &childSFunctions[0]);
      _ssSetSFunction(rts, 1, &childSFunctions[1]);

      /* Level2 S-Function Block: Hammerstein/<S1>/Pwlinear1 (sfunpwlinear) */
      {
        SimStruct *childS = ssGetSFunction(rts, 0);

        /* timing info */
        time_T *sfcnPeriod;
        time_T *sfcnOffset;
        int_T *sfcnTsMap;
        sfcnPeriod = (time_T *) malloc(1 * sizeof(time_T));
        rt_VALIDATE_MEMORY(rts,sfcnPeriod);
        sfcnOffset = (time_T *) malloc(1 * sizeof(time_T));
        rt_VALIDATE_MEMORY(rts,sfcnOffset);
        sfcnTsMap = (int_T *) malloc(1 * sizeof(int_T ));
        rt_VALIDATE_MEMORY(rts,sfcnTsMap);
        (void) memset((void*)sfcnPeriod, 0,
                      sizeof(time_T)*1);
        (void) memset((void*)sfcnOffset, 0,
                      sizeof(time_T)*1);
        ssSetSampleTimePtr(childS, &sfcnPeriod[0]);
        ssSetOffsetTimePtr(childS, &sfcnOffset[0]);
        _ssSetSampleTimeTaskIDPtr(childS, sfcnTsMap);

        /* Set up the mdlInfo pointer */
# ifdef USE_RTMODEL

        {
          struct _ssBlkInfo2 *blkInfo2 = (struct _ssBlkInfo2 *) malloc(sizeof(
              struct _ssBlkInfo2));
          rt_VALIDATE_MEMORY(rts,blkInfo2);
          ssSetBlkInfo2Ptr(childS, blkInfo2);
        }

        ssSetRTWSfcnInfo(childS, ssGetRTWSfcnInfo(rts));

# else

        _ssSetMdlInfoPtr(childS, ssGetMdlInfoPtr(rts));

# endif                                /* USE_RTMODEL */

        /* Allocate memory of model methods 2 */
        {
          struct _ssSFcnModelMethods2 *methods2 = (struct _ssSFcnModelMethods2 *)
            malloc(sizeof(struct _ssSFcnModelMethods2));
          rt_VALIDATE_MEMORY(rts,methods2);
          ssSetModelMethods2(childS, methods2);
        }

        /* Allocate memory of model methods 3 */
        {
          struct _ssSFcnModelMethods3 *methods3 = (struct _ssSFcnModelMethods3 *)
            malloc(sizeof(struct _ssSFcnModelMethods3));
          rt_VALIDATE_MEMORY(rts,methods3);
          ssSetModelMethods3(childS, methods3);
        }

        /* Allocate memory for states auxilliary information */
        {
          struct _ssStatesInfo2 *statesInfo2 = (struct _ssStatesInfo2 *) malloc
            (sizeof(struct _ssStatesInfo2));
          rt_VALIDATE_MEMORY(rts,statesInfo2);
          ssSetStatesInfo2(childS, statesInfo2);
        }

        ssSetRegNumInputPortsFcn(childS, (_ssRegNumInputPortsFcn)
          RegNumInputPorts);
        ssSetRegNumInputPortsFcnArg(childS,childS);

        /* inputs */
        {
          struct _ssPortInputs *inputPortInfo =
            (struct _ssPortInputs *) calloc(1, sizeof(struct _ssPortInputs));
          rt_VALIDATE_MEMORY(rts,inputPortInfo);
          _ssSetNumInputPorts(childS, 1);
          ssSetPortInfoForInputs(childS, &inputPortInfo[0]);

          /* port 0 */
          {
            ssSetInputPortRequiredContiguous(childS, 0, 1);
            _ssSetInputPortSignal(childS, 0, &((BlockIO_Hammerstein *)
              ssGetLocalBlockIO(rts))->LinearModel);
            _ssSetInputPortNumDimensions(childS, 0, 1);
            ssSetInputPortWidth(childS, 0, 1);
          }
        }

        ssSetRegNumOutputPortsFcn(childS, (_ssRegNumOutputPortsFcn)
          RegNumOutputPorts);
        ssSetRegNumOutputPortsFcnArg(childS,childS);

        /* outputs */
        {
          struct _ssPortOutputs *outputPortInfo = (struct _ssPortOutputs *)
            calloc(1, sizeof(struct _ssPortOutputs));
          rt_VALIDATE_MEMORY(rts,outputPortInfo);
          ssSetPortInfoForOutputs(childS, &outputPortInfo[0]);
          _ssSetNumOutputPorts(childS, 1);

          /* port 0 */
          {
            _ssSetOutputPortNumDimensions(childS, 0, 1);
            ssSetOutputPortWidth(childS, 0, 1);
            _ssSetOutputPortSignal(childS, 0, ((real_T *) &((BlockIO_Hammerstein
              *) ssGetLocalBlockIO(rts))->Pwlinear1));
          }
        }

        /* path info */
        _ssSetModelName(childS, "sfunpwlinear");
        _ssSetPath(childS, "Hammerstein/Hammerstein-Wiener Model1/Pwlinear1");
        if (ssGetRTModel(rts) == (NULL)) {
          _ssSetParentSS(childS, rts);
          _ssSetRootSS(childS, ssGetRootSS(rts));
        } else {
          ssSetRTModel(childS,ssGetRTModel(rts));
          _ssSetParentSS(childS, (NULL));
          _ssSetRootSS(childS, childS);
        }

        ssSetVersion(childS, SIMSTRUCT_VERSION_LEVEL2);

        /* parameters */
        {
          mxArray **sfcnParams = (mxArray **) malloc(7 * sizeof(mxArray *));
          rt_VALIDATE_MEMORY(rts,sfcnParams);
          _ssSetSFcnParamsCount(childS, 7);
          _ssSetSFcnParamsPtr(childS, &sfcnParams[0]);

#if defined(MATLAB_MEX_FILE)

          {
            uint_T *attribs;
            attribs = (uint_T *) mxCalloc(7, sizeof(uint_T));
            mexMakeMemoryPersistent(attribs);
            ssSetSFcnParamAttribsPtr(childS, &attribs[0]);
            (void) memset((void *)&attribs[0], 0,
                          7 * sizeof(uint_T));
          }

#endif

#if defined(MATLAB_MEX_FILE)

          {
            mxArray *param;
            int_T i;
            real_T *vals;
            param = mxCreateDoubleMatrix(1,1,mxREAL);
            mexMakeArrayPersistent(param);
            vals = (real_T *) &Hammerstein_ConstP.pooled2;
            for (i=0;i< 1 * 1;i++) {
              mxGetPr(param)[i] = vals[i];
            }

            _ssSetSFcnParam(childS, 0, param);
            param = mxCreateDoubleMatrix(1,1,mxREAL);
            mexMakeArrayPersistent(param);
            vals = (real_T *) &Hammerstein_ConstP.pooled4;
            for (i=0;i< 1 * 1;i++) {
              mxGetPr(param)[i] = vals[i];
            }

            _ssSetSFcnParam(childS, 1, param);
            param = mxCreateDoubleMatrix(1,1,mxREAL);
            mexMakeArrayPersistent(param);
            vals = (real_T *) &Hammerstein_ConstP.pooled6;
            for (i=0;i< 1 * 1;i++) {
              mxGetPr(param)[i] = vals[i];
            }

            _ssSetSFcnParam(childS, 2, param);
            param = mxCreateDoubleMatrix(1,1,mxREAL);
            mexMakeArrayPersistent(param);
            vals = (real_T *) &Hammerstein_ConstP.Pwlinear1_P4;
            for (i=0;i< 1 * 1;i++) {
              mxGetPr(param)[i] = vals[i];
            }

            _ssSetSFcnParam(childS, 3, param);
            param = mxCreateDoubleMatrix(1,1,mxREAL);
            mexMakeArrayPersistent(param);
            vals = (real_T *) &Hammerstein_ConstP.Pwlinear1_P5;
            for (i=0;i< 1 * 1;i++) {
              mxGetPr(param)[i] = vals[i];
            }

            _ssSetSFcnParam(childS, 4, param);
            param = mxCreateDoubleMatrix(10,1,mxREAL);
            mexMakeArrayPersistent(param);
            vals = (real_T *) Hammerstein_ConstP.Pwlinear1_P6;
            for (i=0;i< 10 * 1;i++) {
              mxGetPr(param)[i] = vals[i];
            }

            _ssSetSFcnParam(childS, 5, param);
            param = mxCreateDoubleMatrix(1,10,mxREAL);
            mexMakeArrayPersistent(param);
            vals = (real_T *) Hammerstein_ConstP.Pwlinear1_P7;
            for (i=0;i< 1 * 10;i++) {
              mxGetPr(param)[i] = vals[i];
            }

            _ssSetSFcnParam(childS, 6, param);
          }

#else

          _ssSetSFcnParam(childS, 0, (mxArray*)Hammerstein_ConstP.pooled1);
          _ssSetSFcnParam(childS, 1, (mxArray*)Hammerstein_ConstP.pooled3);
          _ssSetSFcnParam(childS, 2, (mxArray*)Hammerstein_ConstP.pooled5);
          _ssSetSFcnParam(childS, 3, (mxArray*)
                          Hammerstein_ConstP.Pwlinear1_P4_Size);
          _ssSetSFcnParam(childS, 4, (mxArray*)
                          Hammerstein_ConstP.Pwlinear1_P5_Size);
          _ssSetSFcnParam(childS, 5, (mxArray*)
                          Hammerstein_ConstP.Pwlinear1_P6_Size);
          _ssSetSFcnParam(childS, 6, (mxArray*)
                          Hammerstein_ConstP.Pwlinear1_P7_Size);

#endif

        }

        (childS)->regDataType.arg1 = ((void *)(childS));
        (childS)->regDataType.registerFcn = ((OldRegisterDataType)
          FcnSetErrorStatus);
        (childS)->regDataType.getSizeFcn = ((GetDataTypeSize)FcnSetErrorStatus);
        (childS)->regDataType.getZeroFcn = ((GetDataTypeZero)FcnSetErrorStatus);
        (childS)->regDataType.getNameFcn = ((GetDataTypeName)FcnSetErrorStatus);
        (childS)->regDataType.getIdFcn = ((GetDataTypeId)FcnSetErrorStatus);

        /* registration */
#if defined(MATLAB_MEX_FILE)

        {
          int_T i;
          mxArray *plhs[1];
          mxArray *prhs[4];
          double *pr;
          int_T *intS = (int_T *)&childS;
          int_T addrlen = sizeof(SimStruct *);
          int_T m = addrlen/sizeof(int_T) + 1;
          prhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
          prhs[1] = mxCreateDoubleMatrix(m,1,mxREAL);
          pr = mxGetPr(prhs[1]);
          for (i = 0; i < m - 1; i++) {
            pr[i] = (double)intS[i];
          }

          pr[i] = (double)SIMSTRUCT_VERSION_LEVEL2;
          prhs[2] = mxCreateDoubleMatrix(0,0,mxREAL);
          prhs[3] = mxCreateDoubleMatrix(1,1,mxREAL);

          /* Reset port dimensions info functions because the S-function
           * and accelerator mex-files explicitly set their dimensions,
           * i.e., they are not dynamically sized. For this case, the
           * mex-file is responsible for the dimensions info memory
           * and Simulink should not free it. This is achieved by
           * setting the following two methods to NULL.
           */
          ssSetRegInputPortDimensionInfoFcn(childS, (NULL));
          ssSetRegOutputPortDimensionInfoFcn(childS, (NULL));

          /*
           * Setup function pointers and call mdlInitializeSizes via
           * simulink.c
           */
          mexCallMATLAB(1, plhs, 4, prhs, "sfunpwlinear");
          mxDestroyArray(plhs[0]);
          mxDestroyArray(prhs[0]);
          mxDestroyArray(prhs[1]);
          mxDestroyArray(prhs[2]);
          mxDestroyArray(prhs[3]);
        }

#else

        sfunpwlinear(childS);
        sfcnInitializeSizes(childS);

#endif

        sfcnInitializeSampleTimes(childS);

        /* adjust sample time */
        ssSetSampleTime(childS, 0, 0.06);
        ssSetOffsetTime(childS, 0, 0.0);
        sfcnTsMap[0] = ssGetSampleTimeTaskIDPtr(rts)[0];

        /* set compiled values of dynamic vector attributes */
        ssSetNumNonsampledZCs(childS, 0);

        /* Update connectivity flags for each port */
        _ssSetInputPortConnected(childS, 0, 1);
        _ssSetOutputPortConnected(childS, 0, 1);
        _ssSetOutputPortBeingMerged(childS, 0, 0);

        /* Update the BufferDstPort flags for each input port */
        _ssSetInputPortBufferDstPort(childS, 0, -1);
      }

      /* Level2 S-Function Block: Hammerstein/<S1>/Pwlinear (sfunpwlinear) */
      {
        SimStruct *childS = ssGetSFunction(rts, 1);

        /* timing info */
        time_T *sfcnPeriod;
        time_T *sfcnOffset;
        int_T *sfcnTsMap;
        sfcnPeriod = (time_T *) malloc(1 * sizeof(time_T));
        rt_VALIDATE_MEMORY(rts,sfcnPeriod);
        sfcnOffset = (time_T *) malloc(1 * sizeof(time_T));
        rt_VALIDATE_MEMORY(rts,sfcnOffset);
        sfcnTsMap = (int_T *) malloc(1 * sizeof(int_T ));
        rt_VALIDATE_MEMORY(rts,sfcnTsMap);
        (void) memset((void*)sfcnPeriod, 0,
                      sizeof(time_T)*1);
        (void) memset((void*)sfcnOffset, 0,
                      sizeof(time_T)*1);
        ssSetSampleTimePtr(childS, &sfcnPeriod[0]);
        ssSetOffsetTimePtr(childS, &sfcnOffset[0]);
        _ssSetSampleTimeTaskIDPtr(childS, sfcnTsMap);

        /* Set up the mdlInfo pointer */
# ifdef USE_RTMODEL

        {
          struct _ssBlkInfo2 *blkInfo2 = (struct _ssBlkInfo2 *) malloc(sizeof(
              struct _ssBlkInfo2));
          rt_VALIDATE_MEMORY(rts,blkInfo2);
          ssSetBlkInfo2Ptr(childS, blkInfo2);
        }

        ssSetRTWSfcnInfo(childS, ssGetRTWSfcnInfo(rts));

# else

        _ssSetMdlInfoPtr(childS, ssGetMdlInfoPtr(rts));

# endif                                /* USE_RTMODEL */

        /* Allocate memory of model methods 2 */
        {
          struct _ssSFcnModelMethods2 *methods2 = (struct _ssSFcnModelMethods2 *)
            malloc(sizeof(struct _ssSFcnModelMethods2));
          rt_VALIDATE_MEMORY(rts,methods2);
          ssSetModelMethods2(childS, methods2);
        }

        /* Allocate memory of model methods 3 */
        {
          struct _ssSFcnModelMethods3 *methods3 = (struct _ssSFcnModelMethods3 *)
            malloc(sizeof(struct _ssSFcnModelMethods3));
          rt_VALIDATE_MEMORY(rts,methods3);
          ssSetModelMethods3(childS, methods3);
        }

        /* Allocate memory for states auxilliary information */
        {
          struct _ssStatesInfo2 *statesInfo2 = (struct _ssStatesInfo2 *) malloc
            (sizeof(struct _ssStatesInfo2));
          rt_VALIDATE_MEMORY(rts,statesInfo2);
          ssSetStatesInfo2(childS, statesInfo2);
        }

        ssSetRegNumInputPortsFcn(childS, (_ssRegNumInputPortsFcn)
          RegNumInputPorts);
        ssSetRegNumInputPortsFcnArg(childS,childS);

        /* inputs */
        {
          struct _ssPortInputs *inputPortInfo =
            (struct _ssPortInputs *) calloc(1, sizeof(struct _ssPortInputs));
          rt_VALIDATE_MEMORY(rts,inputPortInfo);
          _ssSetNumInputPorts(childS, 1);
          ssSetPortInfoForInputs(childS, &inputPortInfo[0]);

          /* port 0 */
          {
            ssSetInputPortRequiredContiguous(childS, 0, 1);
            _ssSetInputPortSignal(childS, 0, &*((const real_T**)
              ssGetInputPortSignalPtrs(rts, 0))[0]);
            _ssSetInputPortNumDimensions(childS, 0, 1);
            ssSetInputPortWidth(childS, 0, 1);
          }
        }

        ssSetRegNumOutputPortsFcn(childS, (_ssRegNumOutputPortsFcn)
          RegNumOutputPorts);
        ssSetRegNumOutputPortsFcnArg(childS,childS);

        /* outputs */
        {
          struct _ssPortOutputs *outputPortInfo = (struct _ssPortOutputs *)
            calloc(1, sizeof(struct _ssPortOutputs));
          rt_VALIDATE_MEMORY(rts,outputPortInfo);
          ssSetPortInfoForOutputs(childS, &outputPortInfo[0]);
          _ssSetNumOutputPorts(childS, 1);

          /* port 0 */
          {
            _ssSetOutputPortNumDimensions(childS, 0, 1);
            ssSetOutputPortWidth(childS, 0, 1);
            _ssSetOutputPortSignal(childS, 0, ((real_T *) &((BlockIO_Hammerstein
              *) ssGetLocalBlockIO(rts))->Pwlinear));
          }
        }

        /* path info */
        _ssSetModelName(childS, "sfunpwlinear");
        _ssSetPath(childS, "Hammerstein/Hammerstein-Wiener Model1/Pwlinear");
        if (ssGetRTModel(rts) == (NULL)) {
          _ssSetParentSS(childS, rts);
          _ssSetRootSS(childS, ssGetRootSS(rts));
        } else {
          ssSetRTModel(childS,ssGetRTModel(rts));
          _ssSetParentSS(childS, (NULL));
          _ssSetRootSS(childS, childS);
        }

        ssSetVersion(childS, SIMSTRUCT_VERSION_LEVEL2);

        /* parameters */
        {
          mxArray **sfcnParams = (mxArray **) malloc(7 * sizeof(mxArray *));
          rt_VALIDATE_MEMORY(rts,sfcnParams);
          _ssSetSFcnParamsCount(childS, 7);
          _ssSetSFcnParamsPtr(childS, &sfcnParams[0]);

#if defined(MATLAB_MEX_FILE)

          {
            uint_T *attribs;
            attribs = (uint_T *) mxCalloc(7, sizeof(uint_T));
            mexMakeMemoryPersistent(attribs);
            ssSetSFcnParamAttribsPtr(childS, &attribs[0]);
            (void) memset((void *)&attribs[0], 0,
                          7 * sizeof(uint_T));
          }

#endif

#if defined(MATLAB_MEX_FILE)

          {
            mxArray *param;
            int_T i;
            real_T *vals;
            param = mxCreateDoubleMatrix(1,1,mxREAL);
            mexMakeArrayPersistent(param);
            vals = (real_T *) &Hammerstein_ConstP.pooled2;
            for (i=0;i< 1 * 1;i++) {
              mxGetPr(param)[i] = vals[i];
            }

            _ssSetSFcnParam(childS, 0, param);
            param = mxCreateDoubleMatrix(1,1,mxREAL);
            mexMakeArrayPersistent(param);
            vals = (real_T *) &Hammerstein_ConstP.pooled4;
            for (i=0;i< 1 * 1;i++) {
              mxGetPr(param)[i] = vals[i];
            }

            _ssSetSFcnParam(childS, 1, param);
            param = mxCreateDoubleMatrix(1,1,mxREAL);
            mexMakeArrayPersistent(param);
            vals = (real_T *) &Hammerstein_ConstP.pooled6;
            for (i=0;i< 1 * 1;i++) {
              mxGetPr(param)[i] = vals[i];
            }

            _ssSetSFcnParam(childS, 2, param);
            param = mxCreateDoubleMatrix(1,1,mxREAL);
            mexMakeArrayPersistent(param);
            vals = (real_T *) &Hammerstein_ConstP.Pwlinear_P4;
            for (i=0;i< 1 * 1;i++) {
              mxGetPr(param)[i] = vals[i];
            }

            _ssSetSFcnParam(childS, 3, param);
            param = mxCreateDoubleMatrix(1,1,mxREAL);
            mexMakeArrayPersistent(param);
            vals = (real_T *) &Hammerstein_ConstP.Pwlinear_P5;
            for (i=0;i< 1 * 1;i++) {
              mxGetPr(param)[i] = vals[i];
            }

            _ssSetSFcnParam(childS, 4, param);
            param = mxCreateDoubleMatrix(10,1,mxREAL);
            mexMakeArrayPersistent(param);
            vals = (real_T *) Hammerstein_ConstP.Pwlinear_P6;
            for (i=0;i< 10 * 1;i++) {
              mxGetPr(param)[i] = vals[i];
            }

            _ssSetSFcnParam(childS, 5, param);
            param = mxCreateDoubleMatrix(1,10,mxREAL);
            mexMakeArrayPersistent(param);
            vals = (real_T *) Hammerstein_ConstP.Pwlinear_P7;
            for (i=0;i< 1 * 10;i++) {
              mxGetPr(param)[i] = vals[i];
            }

            _ssSetSFcnParam(childS, 6, param);
          }

#else

          _ssSetSFcnParam(childS, 0, (mxArray*)Hammerstein_ConstP.pooled1);
          _ssSetSFcnParam(childS, 1, (mxArray*)Hammerstein_ConstP.pooled3);
          _ssSetSFcnParam(childS, 2, (mxArray*)Hammerstein_ConstP.pooled5);
          _ssSetSFcnParam(childS, 3, (mxArray*)
                          Hammerstein_ConstP.Pwlinear_P4_Size);
          _ssSetSFcnParam(childS, 4, (mxArray*)
                          Hammerstein_ConstP.Pwlinear_P5_Size);
          _ssSetSFcnParam(childS, 5, (mxArray*)
                          Hammerstein_ConstP.Pwlinear_P6_Size);
          _ssSetSFcnParam(childS, 6, (mxArray*)
                          Hammerstein_ConstP.Pwlinear_P7_Size);

#endif

        }

        (childS)->regDataType.arg1 = ((void *)(childS));
        (childS)->regDataType.registerFcn = ((OldRegisterDataType)
          FcnSetErrorStatus);
        (childS)->regDataType.getSizeFcn = ((GetDataTypeSize)FcnSetErrorStatus);
        (childS)->regDataType.getZeroFcn = ((GetDataTypeZero)FcnSetErrorStatus);
        (childS)->regDataType.getNameFcn = ((GetDataTypeName)FcnSetErrorStatus);
        (childS)->regDataType.getIdFcn = ((GetDataTypeId)FcnSetErrorStatus);

        /* registration */
#if defined(MATLAB_MEX_FILE)

        {
          int_T i;
          mxArray *plhs[1];
          mxArray *prhs[4];
          double *pr;
          int_T *intS = (int_T *)&childS;
          int_T addrlen = sizeof(SimStruct *);
          int_T m = addrlen/sizeof(int_T) + 1;
          prhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
          prhs[1] = mxCreateDoubleMatrix(m,1,mxREAL);
          pr = mxGetPr(prhs[1]);
          for (i = 0; i < m - 1; i++) {
            pr[i] = (double)intS[i];
          }

          pr[i] = (double)SIMSTRUCT_VERSION_LEVEL2;
          prhs[2] = mxCreateDoubleMatrix(0,0,mxREAL);
          prhs[3] = mxCreateDoubleMatrix(1,1,mxREAL);

          /* Reset port dimensions info functions because the S-function
           * and accelerator mex-files explicitly set their dimensions,
           * i.e., they are not dynamically sized. For this case, the
           * mex-file is responsible for the dimensions info memory
           * and Simulink should not free it. This is achieved by
           * setting the following two methods to NULL.
           */
          ssSetRegInputPortDimensionInfoFcn(childS, (NULL));
          ssSetRegOutputPortDimensionInfoFcn(childS, (NULL));

          /*
           * Setup function pointers and call mdlInitializeSizes via
           * simulink.c
           */
          mexCallMATLAB(1, plhs, 4, prhs, "sfunpwlinear");
          mxDestroyArray(plhs[0]);
          mxDestroyArray(prhs[0]);
          mxDestroyArray(prhs[1]);
          mxDestroyArray(prhs[2]);
          mxDestroyArray(prhs[3]);
        }

#else

        sfunpwlinear(childS);
        sfcnInitializeSizes(childS);

#endif

        sfcnInitializeSampleTimes(childS);

        /* adjust sample time */
        ssSetSampleTime(childS, 0, 0.06);
        ssSetOffsetTime(childS, 0, 0.0);
        sfcnTsMap[0] = ssGetSampleTimeTaskIDPtr(rts)[0];

        /* set compiled values of dynamic vector attributes */
        ssSetNumNonsampledZCs(childS, 0);

        /* Update connectivity flags for each port */
        _ssSetInputPortConnected(childS, 0, 1);
        _ssSetOutputPortConnected(childS, 0, 1);
        _ssSetOutputPortBeingMerged(childS, 0, 0);

        /* Update the BufferDstPort flags for each input port */
        _ssSetInputPortBufferDstPort(childS, 0, -1);
      }
    }
  }

  return (NULL);
}
