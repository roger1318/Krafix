////////////////////////////////////////////////////////////////////////////////
// 
//  Filename: KxDeclSpec.h
// 
//  Contents: Dll Export Settings of Project KxOGL
// 
////////////////////////////////////////////////////////////////////////////////
//  DATE        DESCRIPTION
//  2018-04-08  Initial implementation
////////////////////////////////////////////////////////////////////////////////

#ifndef KXOGL_DECLSPEC_H
#define KXOGL_DECLSPEC_H

#if !defined(_WIN32) || defined(KX_STATIC_LIB)
// =========================== Non=Windows Platform ===========================
#define KXOGL_EXPORT
#define KXOGL_EXPORT_STATIC
#define KXOGL_EXPORT_GLOBAL
#else
// ============================= Windows Platform =============================
#if defined(KxOGL_EXPORTS)
// ------------------- Export from KxOGL Project --------------------
#define KXOGL_EXPORT        __declspec(dllexport)
#define KXOGL_EXPORT_STATIC
#define KXOGL_EXPORT_GLOBAL __declspec(dllexport)
#else
// ---------------- Import into Referencing Projects ----------------
#define KXOGL_EXPORT
#define KXOGL_EXPORT_STATIC __declspec(dllimport)
#define KXOGL_EXPORT_GLOBAL __declspec(dllimport)
#endif // KxOGL_EXPORTS

#endif // !defined(_WIN32) || defined(KX_STATIC_LIB) 

#endif // KXOGL_DECLSPEC_H 
