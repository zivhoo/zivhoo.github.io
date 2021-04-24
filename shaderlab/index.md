# ShaderLab


```
Shader "path1/path2/ShaderName"
{
  Properties
  {
    _Int("Int",int)             = 0
    _Float("Float", float)      = 0
    _Range("Range", Range(0,1)) = 0
    _Color("Color", Color)      = (1,1,1,1)
    _Vector("Vector", vector)   = (1,1,1,1)
    _MainTex("Texture", 2D)     = ""{}
    _3D("3D Texture", 3D)       = ""{}
    _Cube("Cube Texture", Cube) = ""{}
  }

  SubShader
  {
    Pass{

    }
  }

  SubShader
  {

  }

  Fallback "Diffuse"
}
```
_Object2World  == unity_ObjectToWorld

UnityObjectToClipPos(vertex)  
UnityObjectToWorldNormal(normal)  

UnityWorldSpaceViewDir(worldPos)

## 语义
| 顶点输入语义 | 描述 |
| --- | --- |
|POSITION| 是顶点位置，通常为 float3 或 float4。|
|NORMAL| 是顶点法线，通常为 float3。|
|TEXCOORD0...TEXCOORD3| 是第n个 UV 坐标，通常为 float2、float3 或 float4。|
|TANGENT| 是切线矢量（用于法线贴图），通常为 float4。|
|COLOR| 是每顶点颜色，通常为 float4。|
|uint vid : SV_VertexID（`顶点参数`）|顶点着色器可以接收具有“顶点编号”（为无符号整数）的变量。需要添加 #pragma target 3.5 编译指令。|


| 顶点输出语义 | 描述 |
| --- | --- |
|SV_POSITION|顶点的最终裁剪空间位置 float4 类型|
|TEXCOORD0~n|用于指示任意高精度数据，如纹理坐标和位置。|
|COLOR0~n|用于低精度 0 到 1 范围的数据。|

| 只能当片元输入参数 | 描述 |
| --- | --- |
|UNITY_VPOS_TYPE screenPos : VPOS|像素的位置。 需要#pragma target 3.0 编译指令。|
|VFACE|片元着色器可以接收一种指示渲染表面是面向摄像机还是背对摄像机的变量。VFACE 语义输入变量将包含表示正面三角形的正值，以及表示背面三角形的负值。需要#pragma target 3.0 编译指令。|

| 片元输出 | 描述 |
| --- | --- |
|SV_Target|片元（像素）着色器会输出颜色|
|SV_TargetN|这些是着色器写入的附加颜色。这在一次渲染到多个渲染目标（称为“多渲染目标”渲染技术，简称 MRT）时使用。SV_Target0 等同于 SV_Target。|
|SV_Depth|像素着色器深度输出|
