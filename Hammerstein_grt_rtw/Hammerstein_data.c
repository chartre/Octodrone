/*
 * Hammerstein_data.c
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

/* Block parameters (auto storage) */
Parameters_Hammerstein Hammerstein_P = {
  0.95520909191040437,                 /* Computed Parameter: LinearModel_A
                                        * Referenced by: '<S1>/LinearModel'
                                        */
  1.0,                                 /* Computed Parameter: LinearModel_C
                                        * Referenced by: '<S1>/LinearModel'
                                        */
  0.0,                                 /* Expression: X0
                                        * Referenced by: '<S1>/LinearModel'
                                        */

  /*  Computed Parameter: Pwlinear1_P1_Size
   * Referenced by: '<S1>/Pwlinear1'
   */
  { 1.0, 1.0 },
  0.06,                                /* Expression: Ts
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */

  /*  Computed Parameter: Pwlinear1_P2_Size
   * Referenced by: '<S1>/Pwlinear1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: NumReg
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */

  /*  Computed Parameter: Pwlinear1_P3_Size
   * Referenced by: '<S1>/Pwlinear1'
   */
  { 1.0, 1.0 },
  10.0,                                /* Expression: NumUnits
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */

  /*  Computed Parameter: Pwlinear1_P4_Size
   * Referenced by: '<S1>/Pwlinear1'
   */
  { 1.0, 1.0 },
  0.0041046635484367575,               /* Expression: LinearCoef
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */

  /*  Computed Parameter: Pwlinear1_P5_Size
   * Referenced by: '<S1>/Pwlinear1'
   */
  { 1.0, 1.0 },
  -0.02804435063640871,                /* Expression: OutputOffset
                                        * Referenced by: '<S1>/Pwlinear1'
                                        */

  /*  Computed Parameter: Pwlinear1_P6_Size
   * Referenced by: '<S1>/Pwlinear1'
   */
  { 10.0, 1.0 },

  /*  Expression: OutputCoef
   * Referenced by: '<S1>/Pwlinear1'
   */
  { 0.049412577440588572, 0.037412695525189582, -0.013855151902690495,
    0.043654912328849112, -0.13314006314000829, 0.13679471602541377,
    -0.0485044627370597, 0.014397439943738828, -0.086621504654136941,
    -0.0053941332533863524 },

  /*  Computed Parameter: Pwlinear1_P7_Size
   * Referenced by: '<S1>/Pwlinear1'
   */
  { 1.0, 10.0 },

  /*  Expression: Translation
   * Referenced by: '<S1>/Pwlinear1'
   */
  { 15.832778908250022, 13.7342083264422, 10.320129925856286, 7.5011583594627194,
    2.9390386213145105, 0.84623968114451376, -3.4795365065330883,
    -6.5048393625263223, -9.44668430471862, -15.634316306375393 },

  /*  Computed Parameter: Pwlinear_P1_Size
   * Referenced by: '<S1>/Pwlinear'
   */
  { 1.0, 1.0 },
  0.06,                                /* Expression: Ts
                                        * Referenced by: '<S1>/Pwlinear'
                                        */

  /*  Computed Parameter: Pwlinear_P2_Size
   * Referenced by: '<S1>/Pwlinear'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: NumReg
                                        * Referenced by: '<S1>/Pwlinear'
                                        */

  /*  Computed Parameter: Pwlinear_P3_Size
   * Referenced by: '<S1>/Pwlinear'
   */
  { 1.0, 1.0 },
  10.0,                                /* Expression: NumUnits
                                        * Referenced by: '<S1>/Pwlinear'
                                        */

  /*  Computed Parameter: Pwlinear_P4_Size
   * Referenced by: '<S1>/Pwlinear'
   */
  { 1.0, 1.0 },
  -0.37854916458388282,                /* Expression: LinearCoef
                                        * Referenced by: '<S1>/Pwlinear'
                                        */

  /*  Computed Parameter: Pwlinear_P5_Size
   * Referenced by: '<S1>/Pwlinear'
   */
  { 1.0, 1.0 },
  -0.330538710088571,                  /* Expression: OutputOffset
                                        * Referenced by: '<S1>/Pwlinear'
                                        */

  /*  Computed Parameter: Pwlinear_P6_Size
   * Referenced by: '<S1>/Pwlinear'
   */
  { 10.0, 1.0 },

  /*  Expression: OutputCoef
   * Referenced by: '<S1>/Pwlinear'
   */
  { 0.2095227906259346, 0.45596414604848895, -2.9117276752627288,
    3.3051518696356523, -0.0012704606603276185, 0.0018036724653006382,
    -2.5995349218860411, 2.4191918120790583, -0.47760164420147666,
    -0.17913758524281748 },

  /*  Computed Parameter: Pwlinear_P7_Size
   * Referenced by: '<S1>/Pwlinear'
   */
  { 1.0, 10.0 },

  /*  Expression: Translation
   * Referenced by: '<S1>/Pwlinear'
   */
  { 1.1225240009047588, 0.6108756671535277, 0.31287906583077518,
    0.29138174125517852, -0.0677515420237256, -0.00938351236428661,
    -0.30042635723557465, -0.31982188367656222, -0.60457516275663026,
    -0.16514140233265545 }
};
