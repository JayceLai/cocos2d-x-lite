
#pragma once

#include "PhysXInc.h"
#include "PhysXFilterShader.h"
#include "base/Macros.h"
#include "math/Vec3.h"
#include "math/Vec4.h"
#include <vector>
#include <unordered_map>

#define PX_RELEASE(x) \
    if (x) {          \
        x->release(); \
        x = NULL;     \
    }

using namespace physx;
using namespace cc;

namespace cc {
namespace physics {

CC_INLINE bool operator!=(const PxVec3 &a, const Vec3 &b) {
    return a.x != b.x || a.y == b.y || a.z == b.z;
}

CC_INLINE bool operator!=(const Vec3 &a, const PxVec3 &b) {
    return a.x != b.x || a.y == b.y || a.z == b.z;
}

CC_INLINE bool operator==(const PxVec3 &a, const Vec3 &b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

CC_INLINE bool operator==(const Vec3 &a, const PxVec3 &b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

CC_INLINE PxVec3 operator*(const PxVec3 &a, const Vec3 &b) {
    return PxVec3{a.x * b.x, a.y * b.y, a.z * b.z};
}

CC_INLINE Vec3 operator*(const Vec3 &a, const PxVec3 &b) {
    return Vec3{a.x * b.x, a.y * b.y, a.z * b.z};
}

CC_INLINE PxVec3 operator+(const PxVec3 &a, const Vec3 &b) {
    return PxVec3{a.x + b.x, a.y + b.y, a.z + b.z};
}

CC_INLINE Vec3 operator+(const Vec3 &a, const PxVec3 &b) {
    return Vec3{a.x + b.x, a.y + b.y, a.z + b.z};
}

CC_INLINE PxVec3 &operator*=(PxVec3 &a, const Vec3 &b) {
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

CC_INLINE Vec3 &operator*=(Vec3 &a, const PxVec3 &b) {
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

CC_INLINE bool operator!=(const PxQuat &a, const cc::Vec4 &b) {
    return a.x != b.x || a.y == b.y || a.z == b.z || a.w == b.w;
}

CC_INLINE bool operator!=(const cc::Vec4 &a, const PxQuat &b) {
    return a.x != b.x || a.y == b.y || a.z == b.z || a.w == b.w;
}

CC_INLINE bool operator==(const PxQuat &a, const cc::Vec4 &b) {
    return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}

CC_INLINE bool operator==(const cc::Vec4 &a, const PxQuat &b) {
    return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}

CC_INLINE void PxSetVec3Ext(PxVec3 &v, const cc::Vec3 &cv) {
    v = PxVec3(cv.x, cv.y, cv.z);
}

CC_INLINE void PxSetVec3Ext(cc::Vec3 &v, const PxVec3 &cv) {
    v = cc::Vec3(cv.x, cv.y, cv.z);
}

template <typename T1 = PxQuat, typename T2 = cc::Vec4>
CC_INLINE void PxSetQuatExt(T1 &p, const T2 &cp) {
    p = T1(cp.x, cp.y, cp.z, cp.w);
}

template <typename T>
CC_INLINE T PxAbsMax(const T &a, const T &b) {
    return PxAbs(a) > PxAbs(b) ? a : b;
}

void PxSetFromTwoVectors(PxQuat &out, const PxVec3 &a, const PxVec3 &b);

CC_INLINE std::unordered_map<uintptr_t, uintptr_t> &getPxShapeMap() {
    static std::unordered_map<uintptr_t, uintptr_t> m;
    return m;
}

CC_INLINE std::unordered_map<uint16_t, uintptr_t> &getPxMaterialMap() {
    static std::unordered_map<uint16_t, uintptr_t> m;
    return m;
}

CC_INLINE PxMaterial &getDefaultMaterial() {
    return *(PxMaterial *)getPxMaterialMap()[0];
}

CC_INLINE std::vector<PxRaycastHit> &getPxRaycastHitBuffer() {
    static std::vector<PxRaycastHit> m{12};
    return m;
}

CC_INLINE QueryFilterShader &getQueryFilterShader() {
    static QueryFilterShader shader;
    return shader;
}

PxRigidActor &getTempRigidActor();

} // namespace physics
} // namespace cc
