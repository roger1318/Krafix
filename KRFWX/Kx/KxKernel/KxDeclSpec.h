////////////////////////////////////////////////////////////////////////////////
// 
//  Filename: KxDeclSpec.h
// 
//  Contents: Dll Export Settings of Project Kx
// 
////////////////////////////////////////////////////////////////////////////////
//  DATE        DESCRIPTION
//  2018-04-08  Initial implementation
////////////////////////////////////////////////////////////////////////////////

#ifndef KX_DECLSPEC_H
#define KX_DECLSPEC_H

#if !defined(_WIN32) || defined(KX_STATIC_LIB) 
// =========================== Non=Windows Platform ===========================
#if defined(__linux) || defined(__ANDROID__)   
#define KX_EXPORT         __attribute__ ((visibility ("default")))
#define KX_EXPORT_STATIC  __attribute__ ((visibility ("default")))
#define KX_EXPORT_GLOBAL  __attribute__ ((visibility ("default")))
#elif defined(__APPLE_CC__) && 0
// Disabled as there are problems with template code compiling correctly
// Using push/pop semantic in zlib.h  
//    #define KX_EXPORT         __attribute__ ((visibility ("default")))
//    #define KX_EXPORT_STATIC  __attribute__ ((visibility ("default")))
//    #define KX_EXPORT_GLOBAL  __attribute__ ((visibility ("default")))
#elif defined(__sun)
#define KX_EXPORT         __global
#define KX_EXPORT_STATIC  __global
#define KX_EXPORT_GLOBAL  __global
#else
#define KX_EXPORT
#define KX_EXPORT_STATIC
#define KX_EXPORT_GLOBAL
#endif
#else
// ============================= Windows Platform =============================
#pragma warning( disable: 4251)
#if defined(Kx_EXPORTS)
// --------------------- Export from Kx Project ---------------------
#define KX_EXPORT        __declspec(dllexport)
#define KX_EXPORT_STATIC
#define KX_EXPORT_GLOBAL __declspec(dllexport)
#else
// ---------------- Import into Referencing Projects ----------------
#define KX_EXPORT 
#define KX_EXPORT_STATIC __declspec(dllimport)
#define KX_EXPORT_GLOBAL __declspec(dllimport)
#endif // Kx_EXPORTS

#endif // !defined(_WIN32) || defined(KX_STATIC_LIB)

#endif // KX_DECLSPEC_H 
