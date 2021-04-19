
#pragma once

#include "base/TypeDef.h"
#include <cstdint>

namespace cc {
namespace physics {
class ILifecycle {
public:
    virtual ~ILifecycle() = default;
    virtual void onEnable() = 0;
    virtual void onDisable() = 0;
    virtual void onDestroy() = 0;
};
} // namespace physics
} // namespace cc
