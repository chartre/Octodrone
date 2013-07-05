/*
 * Modelo_data.c
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

/* Block parameters (auto storage) */
Parameters_Modelo Modelo_P = {
  /*  Computed Parameter: LinearModel_A
   * Referenced by: '<S2>/LinearModel'
   */
  { 0.93619577792142716, -0.0, -0.0 },

  /*  Computed Parameter: LinearModel_C
   * Referenced by: '<S2>/LinearModel'
   */
  { 0.0, 0.0, 1.0 },

  /*  Expression: X0
   * Referenced by: '<S2>/LinearModel'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Pwlinear1_P1_Size
   * Referenced by: '<S2>/Pwlinear1'
   */
  { 1.0, 1.0 },
  0.06,                                /* Expression: Ts
                                        * Referenced by: '<S2>/Pwlinear1'
                                        */

  /*  Computed Parameter: Pwlinear1_P2_Size
   * Referenced by: '<S2>/Pwlinear1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: NumReg
                                        * Referenced by: '<S2>/Pwlinear1'
                                        */

  /*  Computed Parameter: Pwlinear1_P3_Size
   * Referenced by: '<S2>/Pwlinear1'
   */
  { 1.0, 1.0 },
  12.0,                                /* Expression: NumUnits
                                        * Referenced by: '<S2>/Pwlinear1'
                                        */

  /*  Computed Parameter: Pwlinear1_P4_Size
   * Referenced by: '<S2>/Pwlinear1'
   */
  { 1.0, 1.0 },
  -0.088554512880991254,               /* Expression: LinearCoef
                                        * Referenced by: '<S2>/Pwlinear1'
                                        */

  /*  Computed Parameter: Pwlinear1_P5_Size
   * Referenced by: '<S2>/Pwlinear1'
   */
  { 1.0, 1.0 },
  0.017779836827578582,                /* Expression: OutputOffset
                                        * Referenced by: '<S2>/Pwlinear1'
                                        */

  /*  Computed Parameter: Pwlinear1_P6_Size
   * Referenced by: '<S2>/Pwlinear1'
   */
  { 12.0, 1.0 },

  /*  Expression: OutputCoef
   * Referenced by: '<S2>/Pwlinear1'
   */
  { 0.07627755002993615, 0.026118452557009283, -0.37530322779531206,
    0.020718540647233427, 0.044544936252952069, 0.27358738753624512,
    -0.30986111878987282, -0.11503489160731149, 0.0401765823697828,
    0.24062057656159233, 0.05176001552689849, -0.019715179359648227 },

  /*  Computed Parameter: Pwlinear1_P7_Size
   * Referenced by: '<S2>/Pwlinear1'
   */
  { 1.0, 12.0 },

  /*  Expression: Translation
   * Referenced by: '<S2>/Pwlinear1'
   */
  { 13.100440261829927, 10.750187015480893, 9.36690448652481, 9.4701375742937177,
    6.3894423832248046, 1.6138287974253407, 0.297953925902821,
    -2.7910296318480756, -1.9719815542830741, -5.1622485862369238,
    -10.401103700413209, -12.751035076726279 },
  0.06,                                /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S1>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator1'
                                        */
  0.95520909191040437,                 /* Computed Parameter: LinearModel_A_p
                                        * Referenced by: '<S3>/LinearModel'
                                        */
  1.0,                                 /* Computed Parameter: LinearModel_C_o
                                        * Referenced by: '<S3>/LinearModel'
                                        */
  0.0,                                 /* Expression: X0
                                        * Referenced by: '<S3>/LinearModel'
                                        */

  /*  Computed Parameter: Pwlinear1_P1_Size_l
   * Referenced by: '<S3>/Pwlinear1'
   */
  { 1.0, 1.0 },
  0.06,                                /* Expression: Ts
                                        * Referenced by: '<S3>/Pwlinear1'
                                        */

  /*  Computed Parameter: Pwlinear1_P2_Size_p
   * Referenced by: '<S3>/Pwlinear1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: NumReg
                                        * Referenced by: '<S3>/Pwlinear1'
                                        */

  /*  Computed Parameter: Pwlinear1_P3_Size_f
   * Referenced by: '<S3>/Pwlinear1'
   */
  { 1.0, 1.0 },
  10.0,                                /* Expression: NumUnits
                                        * Referenced by: '<S3>/Pwlinear1'
                                        */

  /*  Computed Parameter: Pwlinear1_P4_Size_k
   * Referenced by: '<S3>/Pwlinear1'
   */
  { 1.0, 1.0 },
  0.0041046635484367575,               /* Expression: LinearCoef
                                        * Referenced by: '<S3>/Pwlinear1'
                                        */

  /*  Computed Parameter: Pwlinear1_P5_Size_k
   * Referenced by: '<S3>/Pwlinear1'
   */
  { 1.0, 1.0 },
  -0.02804435063640871,                /* Expression: OutputOffset
                                        * Referenced by: '<S3>/Pwlinear1'
                                        */

  /*  Computed Parameter: Pwlinear1_P6_Size_n
   * Referenced by: '<S3>/Pwlinear1'
   */
  { 10.0, 1.0 },

  /*  Expression: OutputCoef
   * Referenced by: '<S3>/Pwlinear1'
   */
  { 0.049412577440588572, 0.037412695525189582, -0.013855151902690495,
    0.043654912328849112, -0.13314006314000829, 0.13679471602541377,
    -0.0485044627370597, 0.014397439943738828, -0.086621504654136941,
    -0.0053941332533863524 },

  /*  Computed Parameter: Pwlinear1_P7_Size_d
   * Referenced by: '<S3>/Pwlinear1'
   */
  { 1.0, 10.0 },

  /*  Expression: Translation
   * Referenced by: '<S3>/Pwlinear1'
   */
  { 15.832778908250022, 13.7342083264422, 10.320129925856286, 7.5011583594627194,
    2.9390386213145105, 0.84623968114451376, -3.4795365065330883,
    -6.5048393625263223, -9.44668430471862, -15.634316306375393 },
  0.06,                                /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */

  /*  Computed Parameter: Pwlinear_P1_Size
   * Referenced by: '<S2>/Pwlinear'
   */
  { 1.0, 1.0 },
  0.06,                                /* Expression: Ts
                                        * Referenced by: '<S2>/Pwlinear'
                                        */

  /*  Computed Parameter: Pwlinear_P2_Size
   * Referenced by: '<S2>/Pwlinear'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: NumReg
                                        * Referenced by: '<S2>/Pwlinear'
                                        */

  /*  Computed Parameter: Pwlinear_P3_Size
   * Referenced by: '<S2>/Pwlinear'
   */
  { 1.0, 1.0 },
  12.0,                                /* Expression: NumUnits
                                        * Referenced by: '<S2>/Pwlinear'
                                        */

  /*  Computed Parameter: Pwlinear_P4_Size
   * Referenced by: '<S2>/Pwlinear'
   */
  { 1.0, 1.0 },
  -0.053058302641768459,               /* Expression: LinearCoef
                                        * Referenced by: '<S2>/Pwlinear'
                                        */

  /*  Computed Parameter: Pwlinear_P5_Size
   * Referenced by: '<S2>/Pwlinear'
   */
  { 1.0, 1.0 },
  -0.079016565822876819,               /* Expression: OutputOffset
                                        * Referenced by: '<S2>/Pwlinear'
                                        */

  /*  Computed Parameter: Pwlinear_P6_Size
   * Referenced by: '<S2>/Pwlinear'
   */
  { 12.0, 1.0 },

  /*  Expression: OutputCoef
   * Referenced by: '<S2>/Pwlinear'
   */
  { -0.19832536928175737, 0.29779151299574191, -0.15340991485027355,
    0.20337075443822403, 0.49876164737946033, 0.589523940821774,
    -0.18077517662936118, -0.035597295492340267, -0.976308321160495,
    0.12225297464951192, -0.598017079228082, 0.41311241937537752 },

  /*  Computed Parameter: Pwlinear_P7_Size
   * Referenced by: '<S2>/Pwlinear'
   */
  { 1.0, 12.0 },

  /*  Expression: Translation
   * Referenced by: '<S2>/Pwlinear'
   */
  { 0.77943067731144855, 0.66655174613358026, -0.17029673563619527,
    0.38259787912288773, 0.25092725123883536, -0.37957998009039323,
    -0.09473639847108406, -0.17726636436631915, -0.38295482334780956,
    -0.7447670914223733, -0.6895983704409222, -0.71173187412289229 },
  -0.006,                              /* Expression: -0.006
                                        * Referenced by: '<S1>/Constant'
                                        */

  /*  Computed Parameter: Pwlinear_P1_Size_e
   * Referenced by: '<S3>/Pwlinear'
   */
  { 1.0, 1.0 },
  0.06,                                /* Expression: Ts
                                        * Referenced by: '<S3>/Pwlinear'
                                        */

  /*  Computed Parameter: Pwlinear_P2_Size_n
   * Referenced by: '<S3>/Pwlinear'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: NumReg
                                        * Referenced by: '<S3>/Pwlinear'
                                        */

  /*  Computed Parameter: Pwlinear_P3_Size_c
   * Referenced by: '<S3>/Pwlinear'
   */
  { 1.0, 1.0 },
  10.0,                                /* Expression: NumUnits
                                        * Referenced by: '<S3>/Pwlinear'
                                        */

  /*  Computed Parameter: Pwlinear_P4_Size_p
   * Referenced by: '<S3>/Pwlinear'
   */
  { 1.0, 1.0 },
  -0.37854916458388282,                /* Expression: LinearCoef
                                        * Referenced by: '<S3>/Pwlinear'
                                        */

  /*  Computed Parameter: Pwlinear_P5_Size_g
   * Referenced by: '<S3>/Pwlinear'
   */
  { 1.0, 1.0 },
  -0.330538710088571,                  /* Expression: OutputOffset
                                        * Referenced by: '<S3>/Pwlinear'
                                        */

  /*  Computed Parameter: Pwlinear_P6_Size_i
   * Referenced by: '<S3>/Pwlinear'
   */
  { 10.0, 1.0 },

  /*  Expression: OutputCoef
   * Referenced by: '<S3>/Pwlinear'
   */
  { 0.2095227906259346, 0.45596414604848895, -2.9117276752627288,
    3.3051518696356523, -0.0012704606603276185, 0.0018036724653006382,
    -2.5995349218860411, 2.4191918120790583, -0.47760164420147666,
    -0.17913758524281748 },

  /*  Computed Parameter: Pwlinear_P7_Size_d
   * Referenced by: '<S3>/Pwlinear'
   */
  { 1.0, 10.0 },

  /*  Expression: Translation
   * Referenced by: '<S3>/Pwlinear'
   */
  { 1.1225240009047588, 0.6108756671535277, 0.31287906583077518,
    0.29138174125517852, -0.0677515420237256, -0.00938351236428661,
    -0.30042635723557465, -0.31982188367656222, -0.60457516275663026,
    -0.16514140233265545 }
};
