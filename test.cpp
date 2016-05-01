#include <stdio.h>
#include <assert.h>

#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <dlfcn.h>

#include <EGL/egl.h>

extern "C" {

EGLBoolean eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    using T = EGLBoolean (*)(EGLDisplay, EGLSurface);
    static thread_local T func = nullptr;
    if (!func) {
        func = (T)dlsym(RTLD_NEXT, __func__);
        assert(func);
    }

    fprintf(stdout, "before %s\n", __func__);

    EGLBoolean ret = func(dpy, surface);

    fprintf(stdout, "after %s\n", __func__);

    return ret;
}

}
