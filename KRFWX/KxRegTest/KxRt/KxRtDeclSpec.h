////////////////////////////////////////////////////////////////////////////////
// 
//  Filename: KxRtDeclSpec.h
// 
//  Contents: Dll Export Settings of Project KxRt
// 
////////////////////////////////////////////////////////////////////////////////
//  DATE        DESCRIPTION
//  2018-04-11  Initial implementation
////////////////////////////////////////////////////////////////////////////////

#ifndef KXRT_DECLSPEC_H
#define KXRT_DECLSPEC_H

#if !defined(_WIN32) || defined(KX_STATIC_LIB)
// =========================== Non=Windows Platform ===========================
#define KXRT_EXPORT
#define KXRT_EXPORT_STATIC
#define KXRT_EXPORT_GLOBAL
#else
// ============================= Windows Platform =============================
#if defined(KxRt_EXPORTS)
// ------------------- Export from KxRt Project --------------------
#define KXRT_EXPORT        __declspec(dllexport)
#define KXRT_EXPORT_STATIC
#define KXRT_EXPORT_GLOBAL __declspec(dllexport)
// Define nothing to USE the DLL version of KX or KXOGL
#else
// ---------------- Import into Referencing Projects ----------------
#define KXRT_EXPORT
#define KXRT_EXPORT_STATIC __declspec(dllimport)
#define KXRT_EXPORT_GLOBAL __declspec(dllimport)
#endif // KxRt_EXPORTS

#endif // !defined(_WIN32) || defined(KX_STATIC_LIB) 

#endif // KXRT_DECLSPEC_H 
