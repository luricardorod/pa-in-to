//
// pch.h
// Encabezado para archivos de inclusi�n est�ndar del sistema.
//
// Lo usa el sistema de compilaci�n para generar el encabezado precompilado. Tenga en cuenta que
// pch.h no se incluyen autom�ticamente en todos los archivos cpp
// que forman parte del proyecto.
//

#include <jni.h>
#include <errno.h>

#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#include <EGL/egl.h>
#include <GLES/gl.h>

#include <android/sensor.h>

#include <android/log.h>
#include "android_native_app_glue.h"
