#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
//
// Buffer Definitions: 
//
// cbuffer PS_REG_B0
// {
//
//   float4 g_intensity;                // Offset:    0 Size:    16
//   float4 g_gnd;                      // Offset:   16 Size:    16
//   float4 g_sky;                      // Offset:   32 Size:    16
//
// }
//
// cbuffer PS_REG_B1
// {
//
//   float4 g_up_dir;                   // Offset:    0 Size:    16
//
// }
//
// cbuffer PS_REG_B2
// {
//
//   float4 g_a;                        // Offset:    0 Size:    16 [unused]
//   float4 g_d;                        // Offset:   16 Size:    16 [unused]
//   float4 g_s;                        // Offset:   32 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// g_diffuse_texture_sampler_state    sampler      NA          NA    0        1
// g_diffuse_texture                 texture  float4          2d    0        1
// PS_REG_B0                         cbuffer      NA          NA    0        1
// PS_REG_B1                         cbuffer      NA          NA    1        1
// PS_REG_B2                         cbuffer      NA          NA    2        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float       
// TEXCOORD                 0   xyz         1     NONE   float   xyz 
// TEXCOORD                 1   xyz         2     NONE   float   xyz 
// TEXCOORD                 2   xyz         3     NONE   float   xyz 
// TEXCOORD                 3   xy          4     NONE   float   xy  
// TEXCOORD                 4     z         4     NONE   float     z 
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_TARGET                0   xyzw        0   TARGET   float   xyzw
//
//
// Constant buffer to DX9 shader constant mappings:
//
// Target Reg Buffer  Start Reg # of Regs        Data Conversion
// ---------- ------- --------- --------- ----------------------
// c0         cb0             0         3  ( FLT, FLT, FLT, FLT)
// c3         cb1             0         1  ( FLT, FLT, FLT, FLT)
// c4         cb2             2         1  ( FLT, FLT, FLT, FLT)
//
//
// Sampler/Resource to DX9 shader sampler mappings:
//
// Target Sampler Source Sampler  Source Resource
// -------------- --------------- ----------------
// s0             s0              t0               
//
//
// Level9 shader bytecode:
//
    ps_2_0
    def c5, 4, 0.5, 0, 0
    dcl t0.xyz
    dcl t1.xyz
    dcl t2.xyz
    dcl t3.xyz
    dcl_2d s0
    texld r0, t3, s0
    nrm r1.xyz, t1
    nrm r2.xyz, t2
    nrm r3.xyz, t0
    dp3_sat r1.w, r3, r2
    add r2.w, r1.w, r1.w
    mad r2.xyz, r2.w, r3, -r2
    dp3 r2.w, r3, c3
    mad r2.w, r2.w, c5.y, c5.y
    dp3_sat r1.x, r1, r2
    pow r2.x, r1.x, c4.w
    mul r1.xyz, r2.x, c4
    mul r2.xyz, r0, c0
    mad r1.xyz, r2, r1.w, r1
    mul_sat r1.w, r1.w, c5.x
    mul r1.w, r1.w, t3.z
    mul r1.xyz, r1, r1.w
    mov r2.xyz, c1
    add r2.xyz, -r2, c2
    mad r2.xyz, r2.w, r2, c1
    mad r0.xyz, r0, r2, r1
    mov oC0, r0

// approximately 30 instruction slots used (1 texture, 29 arithmetic)
ps_4_0
dcl_constantbuffer cb0[3], immediateIndexed
dcl_constantbuffer cb1[1], immediateIndexed
dcl_constantbuffer cb2[3], immediateIndexed
dcl_sampler s0, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_input_ps linear v1.xyz
dcl_input_ps linear v2.xyz
dcl_input_ps linear v3.xyz
dcl_input_ps linear v4.xy
dcl_input_ps linear v4.z
dcl_output o0.xyzw
dcl_temps 3
dp3 r0.x, v2.xyzx, v2.xyzx
rsq r0.x, r0.x
mul r0.xyz, r0.xxxx, v2.xyzx
dp3 r0.w, v3.xyzx, v3.xyzx
rsq r0.w, r0.w
mul r1.xyz, r0.wwww, v3.xyzx
dp3 r0.w, v1.xyzx, v1.xyzx
rsq r0.w, r0.w
mul r2.xyz, r0.wwww, v1.xyzx
dp3_sat r0.w, r2.xyzx, r1.xyzx
add r1.w, r0.w, r0.w
mad r1.xyz, r1.wwww, r2.xyzx, -r1.xyzx
dp3 r1.w, r2.xyzx, cb1[0].xyzx
mad r1.w, r1.w, l(0.500000), l(0.500000)
dp3_sat r0.x, r0.xyzx, r1.xyzx
log r0.x, r0.x
mul r0.x, r0.x, cb2[2].w
exp r0.x, r0.x
mul r0.xyz, r0.xxxx, cb2[2].xyzx
sample r2.xyzw, v4.xyxx, t0.xyzw, s0
mul r1.xyz, r2.xyzx, cb0[0].xyzx
mad r0.xyz, r1.xyzx, r0.wwww, r0.xyzx
mul r0.w, r0.w, l(4.000000)
min r0.w, r0.w, l(1.000000)
mul r0.w, r0.w, v4.z
mul r0.xyz, r0.xyzx, r0.wwww
add r1.xyz, -cb0[1].xyzx, cb0[2].xyzx
mad r1.xyz, r1.wwww, r1.xyzx, cb0[1].xyzx
mad o0.xyz, r2.xyzx, r1.xyzx, r0.xyzx
mov o0.w, r2.w
ret 
// Approximately 31 instruction slots used
#endif

const BYTE g_P3N3T2_PS[] =
{
     68,  88,  66,  67, 108, 120, 
     21,  90,   3, 208,  89,  86, 
    254, 138,  90,  82, 188, 199, 
     82, 176,   1,   0,   0,   0, 
     68,  10,   0,   0,   6,   0, 
      0,   0,  56,   0,   0,   0, 
     72,   2,   0,   0, 100,   6, 
      0,   0, 224,   6,   0,   0, 
     88,   9,   0,   0,  16,  10, 
      0,   0,  65, 111, 110,  57, 
      8,   2,   0,   0,   8,   2, 
      0,   0,   0,   2, 255, 255, 
    188,   1,   0,   0,  76,   0, 
      0,   0,   3,   0,  40,   0, 
      0,   0,  76,   0,   0,   0, 
     76,   0,   1,   0,  36,   0, 
      0,   0,  76,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   3,   0,   0,   0, 
      0,   0,   2,   0,   2,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   2, 255, 255, 
     81,   0,   0,   5,   5,   0, 
     15, 160,   0,   0, 128,  64, 
      0,   0,   0,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   0,   0,   7, 176, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   1,   0,   7, 176, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   2,   0,   7, 176, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   3,   0,   7, 176, 
     31,   0,   0,   2,   0,   0, 
      0, 144,   0,   8,  15, 160, 
     66,   0,   0,   3,   0,   0, 
     15, 128,   3,   0, 228, 176, 
      0,   8, 228, 160,  36,   0, 
      0,   2,   1,   0,   7, 128, 
      1,   0, 228, 176,  36,   0, 
      0,   2,   2,   0,   7, 128, 
      2,   0, 228, 176,  36,   0, 
      0,   2,   3,   0,   7, 128, 
      0,   0, 228, 176,   8,   0, 
      0,   3,   1,   0,  24, 128, 
      3,   0, 228, 128,   2,   0, 
    228, 128,   2,   0,   0,   3, 
      2,   0,   8, 128,   1,   0, 
    255, 128,   1,   0, 255, 128, 
      4,   0,   0,   4,   2,   0, 
      7, 128,   2,   0, 255, 128, 
      3,   0, 228, 128,   2,   0, 
    228, 129,   8,   0,   0,   3, 
      2,   0,   8, 128,   3,   0, 
    228, 128,   3,   0, 228, 160, 
      4,   0,   0,   4,   2,   0, 
      8, 128,   2,   0, 255, 128, 
      5,   0,  85, 160,   5,   0, 
     85, 160,   8,   0,   0,   3, 
      1,   0,  17, 128,   1,   0, 
    228, 128,   2,   0, 228, 128, 
     32,   0,   0,   3,   2,   0, 
      1, 128,   1,   0,   0, 128, 
      4,   0, 255, 160,   5,   0, 
      0,   3,   1,   0,   7, 128, 
      2,   0,   0, 128,   4,   0, 
    228, 160,   5,   0,   0,   3, 
      2,   0,   7, 128,   0,   0, 
    228, 128,   0,   0, 228, 160, 
      4,   0,   0,   4,   1,   0, 
      7, 128,   2,   0, 228, 128, 
      1,   0, 255, 128,   1,   0, 
    228, 128,   5,   0,   0,   3, 
      1,   0,  24, 128,   1,   0, 
    255, 128,   5,   0,   0, 160, 
      5,   0,   0,   3,   1,   0, 
      8, 128,   1,   0, 255, 128, 
      3,   0, 170, 176,   5,   0, 
      0,   3,   1,   0,   7, 128, 
      1,   0, 228, 128,   1,   0, 
    255, 128,   1,   0,   0,   2, 
      2,   0,   7, 128,   1,   0, 
    228, 160,   2,   0,   0,   3, 
      2,   0,   7, 128,   2,   0, 
    228, 129,   2,   0, 228, 160, 
      4,   0,   0,   4,   2,   0, 
      7, 128,   2,   0, 255, 128, 
      2,   0, 228, 128,   1,   0, 
    228, 160,   4,   0,   0,   4, 
      0,   0,   7, 128,   0,   0, 
    228, 128,   2,   0, 228, 128, 
      1,   0, 228, 128,   1,   0, 
      0,   2,   0,   8,  15, 128, 
      0,   0, 228, 128, 255, 255, 
      0,   0,  83,  72,  68,  82, 
     20,   4,   0,   0,  64,   0, 
      0,   0,   5,   1,   0,   0, 
     89,   0,   0,   4,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  89,   0,   0,   4, 
     70, 142,  32,   0,   2,   0, 
      0,   0,   3,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   0,   0,   0,   0, 
     85,  85,   0,   0,  98,  16, 
      0,   3, 114,  16,  16,   0, 
      1,   0,   0,   0,  98,  16, 
      0,   3, 114,  16,  16,   0, 
      2,   0,   0,   0,  98,  16, 
      0,   3, 114,  16,  16,   0, 
      3,   0,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      4,   0,   0,   0,  98,  16, 
      0,   3,  66,  16,  16,   0, 
      4,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      0,   0,   0,   0, 104,   0, 
      0,   2,   3,   0,   0,   0, 
     16,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  18,  16,   0,   2,   0, 
      0,   0,  70,  18,  16,   0, 
      2,   0,   0,   0,  68,   0, 
      0,   5,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  70,  18,  16,   0, 
      2,   0,   0,   0,  16,   0, 
      0,   7, 130,   0,  16,   0, 
      0,   0,   0,   0,  70,  18, 
     16,   0,   3,   0,   0,   0, 
     70,  18,  16,   0,   3,   0, 
      0,   0,  68,   0,   0,   5, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      1,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
     70,  18,  16,   0,   3,   0, 
      0,   0,  16,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  70,  18,  16,   0, 
      1,   0,   0,   0,  70,  18, 
     16,   0,   1,   0,   0,   0, 
     68,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
    114,   0,  16,   0,   2,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,  70,  18, 
     16,   0,   1,   0,   0,   0, 
     16,  32,   0,   7, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   7, 130,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  50,   0,   0,  10, 
    114,   0,  16,   0,   1,   0, 
      0,   0, 246,  15,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     16,   0,   0,   8, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  70, 130,  32,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  50,   0,   0,   9, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,  63, 
      1,  64,   0,   0,   0,   0, 
      0,  63,  16,  32,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     47,   0,   0,   5,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   8, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  58, 128, 
     32,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,  25,   0, 
      0,   5,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   8, 114,   0, 
     16,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  70, 130,  32,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70,  16,  16,   0, 
      4,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   8, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  50,   0, 
      0,   9, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  64,  51,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  42,  16,  16,   0, 
      4,   0,   0,   0,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,  10, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70, 130,  32, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     50,   0,   0,  10, 114,   0, 
     16,   0,   1,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  50,   0, 
      0,   9, 114,  32,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5, 130,  32,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 116,   0,   0,   0, 
     31,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,   0,   0,  28,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  82,  68,  69,  70, 
    112,   2,   0,   0,   3,   0, 
      0,   0,  12,   1,   0,   0, 
      5,   0,   0,   0,  28,   0, 
      0,   0,   0,   4, 255, 255, 
      0,   1,   0,   0,  60,   2, 
      0,   0, 188,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 220,   0, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  12,   0,   0,   0, 
    238,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 248,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   2,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    103,  95, 100, 105, 102, 102, 
    117, 115, 101,  95, 116, 101, 
    120, 116, 117, 114, 101,  95, 
    115,  97, 109, 112, 108, 101, 
    114,  95, 115, 116,  97, 116, 
    101,   0, 103,  95, 100, 105, 
    102, 102, 117, 115, 101,  95, 
    116, 101, 120, 116, 117, 114, 
    101,   0,  80,  83,  95,  82, 
     69,  71,  95,  66,  48,   0, 
     80,  83,  95,  82,  69,  71, 
     95,  66,  49,   0,  80,  83, 
     95,  82,  69,  71,  95,  66, 
     50,   0, 238,   0,   0,   0, 
      3,   0,   0,   0,  84,   1, 
      0,   0,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 248,   0,   0,   0, 
      1,   0,   0,   0, 196,   1, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,   1,   0,   0, 
      3,   0,   0,   0, 232,   1, 
      0,   0,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 156,   1,   0,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    168,   1,   0,   0,   0,   0, 
      0,   0, 184,   1,   0,   0, 
     16,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    168,   1,   0,   0,   0,   0, 
      0,   0, 190,   1,   0,   0, 
     32,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    168,   1,   0,   0,   0,   0, 
      0,   0, 103,  95, 105, 110, 
    116, 101, 110, 115, 105, 116, 
    121,   0,   1,   0,   3,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    103,  95, 103, 110, 100,   0, 
    103,  95, 115, 107, 121,   0, 
    220,   1,   0,   0,   0,   0, 
      0,   0,  16,   0,   0,   0, 
      2,   0,   0,   0, 168,   1, 
      0,   0,   0,   0,   0,   0, 
    103,  95, 117, 112,  95, 100, 
    105, 114,   0, 171, 171, 171, 
     48,   2,   0,   0,   0,   0, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0, 168,   1, 
      0,   0,   0,   0,   0,   0, 
     52,   2,   0,   0,  16,   0, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0, 168,   1, 
      0,   0,   0,   0,   0,   0, 
     56,   2,   0,   0,  32,   0, 
      0,   0,  16,   0,   0,   0, 
      2,   0,   0,   0, 168,   1, 
      0,   0,   0,   0,   0,   0, 
    103,  95,  97,   0, 103,  95, 
    100,   0, 103,  95, 115,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  54, 
     46,  51,  46,  57,  54,  48, 
     48,  46,  49,  54,  51,  56, 
     52,   0, 171, 171,  73,  83, 
     71,  78, 176,   0,   0,   0, 
      6,   0,   0,   0,   8,   0, 
      0,   0, 152,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0, 164,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,   7,   7, 
      0,   0, 164,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   7,   7, 
      0,   0, 164,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      3,   0,   0,   0,   7,   7, 
      0,   0, 164,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      4,   0,   0,   0,   3,   3, 
      0,   0, 164,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      4,   0,   0,   0,   4,   4, 
      0,   0,  83,  86,  95,  80, 
     79,  83,  73,  84,  73,  79, 
     78,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0, 171, 
    171, 171,  79,  83,  71,  78, 
     44,   0,   0,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     83,  86,  95,  84,  65,  82, 
     71,  69,  84,   0, 171, 171
};
