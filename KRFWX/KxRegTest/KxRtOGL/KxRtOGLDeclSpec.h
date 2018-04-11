////////////////////////////////////////////////////////////////////////////////
// 
//  Filename: KxRtOGLDeclSpec.h
// 
//  Contents: Dll Export Settings of Project KxRtOGL
// 
////////////////////////////////////////////////////////////////////////////////
//  DATE        DESCRIPTION
//  2018-04-11  Initial implementation
////////////////////////////////////////////////////////////////////////////////

#ifndef KxRTOGL_DECLSPEC_H
#define KxRTOGL_DECLSPEC_H

#if !defined(_WIN32) || defined(KX_STATIC_LIB)
// =========================== Non=Windows Platform ===========================
#define KxRTOGL_EXPORT
#define KxRTOGL_EXPORT_STATIC
#define KxRTOGL_EXPORT_GLOBAL
#else
// ============================= Windows Platform =============================
#if defined(KxRtOGL_EXPORTS)
// ------------------- Export from KxRtOGL Project --------------------
#define KxRTOGL_EXPORT        __declspec(dllexport)
#define KxRTOGL_EXPORT_STATIC
#define KxRTOGL_EXPORT_GLOBAL __declspec(dllexport)
// Define nothing to USE the DLL version of KX or KXOGL
#else
// ---------------- Import into Referencing Projects ----------------
#define KxRTOGL_EXPORT
#define KxRTOGL_EXPORT_STATIC __declspec(dllimport)
#define KxRTOGL_EXPORT_GLOBAL __declspec(dllimport)
#endif // KxRtOGL_EXPORTS

#endif // !defined(_WIN32) || defined(KX_STATIC_LIB) 

#endif // KxRTOGL_DECLSPEC_H 
