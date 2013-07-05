/*
 * Hammerstein_sid.h
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

/* statically allocated instance data for model: Hammerstein */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static BlockIO_Hammerstein sfcnB;
      void *b = (real_T *) &sfcnB;
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
        static SimStruct childSFunctions[2];
        static SimStruct *childSFunctionPtrs[2];
        (void) memset((void *)&childSFunctions[0], 0,
                      sizeof(childSFunctions));
        _ssSetSFunctions(rts, &childSFunctionPtrs[0]);
        _ssSetSFunction(rts, 0, &childSFunctions[0]);
        _ssSetSFunction(rts, 1, &childSFunctions[1]);

        /* Level2 S-Function Block: Hammerstein/<S1>/Pwlinear1 (sfunpwlinear) */
        {
          SimStruct *childS = ssGetSFunction(rts, 0);

          /* timing info */
          static time_T sfcnPeriod[1];
          static time_T sfcnOffset[1];
          static int_T sfcnTsMap[1];
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
            static struct _ssBlkInfo2 _blkInfo2;
            struct _ssBlkInfo2 *blkInfo2 = &_blkInfo2;
            ssSetBlkInfo2Ptr(childS, blkInfo2);
          }

          ssSetRTWSfcnInfo(childS, ssGetRTWSfcnInfo(rts));

# else

          _ssSetMdlInfoPtr(childS, ssGetMdlInfoPtr(rts));

# endif                                /* USE_RTMODEL */

          /* Allocate memory of model methods 2 */
          {
            static struct _ssSFcnModelMethods2 methods2;
            ssSetModelMethods2(childS, &methods2);
          }

          /* Allocate memory of model methods 3 */
          {
            static struct _ssSFcnModelMethods3 methods3;
            ssSetModelMethods3(childS, &methods3);
          }

          /* Allocate memory for states auxilliary information */
          {
            static struct _ssStatesInfo2 statesInfo2;
            ssSetStatesInfo2(childS, &statesInfo2);
          }

          /* inputs */
          {
            static struct _ssPortInputs inputPortInfo[1];
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

          /* outputs */
          {
            static struct _ssPortOutputs outputPortInfo[1];
            ssSetPortInfoForOutputs(childS, &outputPortInfo[0]);
            _ssSetNumOutputPorts(childS, 1);

            /* port 0 */
            {
              _ssSetOutputPortNumDimensions(childS, 0, 1);
              ssSetOutputPortWidth(childS, 0, 1);
              _ssSetOutputPortSignal(childS, 0, ((real_T *)
                &((BlockIO_Hammerstein *) ssGetLocalBlockIO(rts))->Pwlinear1));
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
            static mxArray *sfcnParams[7];
            _ssSetSFcnParamsCount(childS, 7);
            _ssSetSFcnParamsPtr(childS, &sfcnParams[0]);

#if defined(MATLAB_MEX_FILE)

            {
              static uint_T attribs[7];
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

          /* registration */
          sfunpwlinear(childS);
          sfcnInitializeSizes(childS);
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
          static time_T sfcnPeriod[1];
          static time_T sfcnOffset[1];
          static int_T sfcnTsMap[1];
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
            static struct _ssBlkInfo2 _blkInfo2;
            struct _ssBlkInfo2 *blkInfo2 = &_blkInfo2;
            ssSetBlkInfo2Ptr(childS, blkInfo2);
          }

          ssSetRTWSfcnInfo(childS, ssGetRTWSfcnInfo(rts));

# else

          _ssSetMdlInfoPtr(childS, ssGetMdlInfoPtr(rts));

# endif                                /* USE_RTMODEL */

          /* Allocate memory of model methods 2 */
          {
            static struct _ssSFcnModelMethods2 methods2;
            ssSetModelMethods2(childS, &methods2);
          }

          /* Allocate memory of model methods 3 */
          {
            static struct _ssSFcnModelMethods3 methods3;
            ssSetModelMethods3(childS, &methods3);
          }

          /* Allocate memory for states auxilliary information */
          {
            static struct _ssStatesInfo2 statesInfo2;
            ssSetStatesInfo2(childS, &statesInfo2);
          }

          /* inputs */
          {
            static struct _ssPortInputs inputPortInfo[1];
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

          /* outputs */
          {
            static struct _ssPortOutputs outputPortInfo[1];
            ssSetPortInfoForOutputs(childS, &outputPortInfo[0]);
            _ssSetNumOutputPorts(childS, 1);

            /* port 0 */
            {
              _ssSetOutputPortNumDimensions(childS, 0, 1);
              ssSetOutputPortWidth(childS, 0, 1);
              _ssSetOutputPortSignal(childS, 0, ((real_T *)
                &((BlockIO_Hammerstein *) ssGetLocalBlockIO(rts))->Pwlinear));
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
            static mxArray *sfcnParams[7];
            _ssSetSFcnParamsCount(childS, 7);
            _ssSetSFcnParamsPtr(childS, &sfcnParams[0]);

#if defined(MATLAB_MEX_FILE)

            {
              static uint_T attribs[7];
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

          /* registration */
          sfunpwlinear(childS);
          sfcnInitializeSizes(childS);
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
  }
}
