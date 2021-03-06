/*
 * Copyright 2017 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * This file was autogenerated from GrDitherEffect.fp; do not modify.
 */
#include "GrDitherEffect.h"
#if SK_SUPPORT_GPU
#include "glsl/GrGLSLColorSpaceXformHelper.h"
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramBuilder.h"
#include "SkSLCPP.h"
#include "SkSLUtil.h"
class GrGLSLDitherEffect : public GrGLSLFragmentProcessor {
public:
    GrGLSLDitherEffect() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrDitherEffect& _outer = args.fFp.cast<GrDitherEffect>();
        (void)_outer;
        fragBuilder->codeAppendf(
                "half value;\nhalf range;\n@switch (%d) {\n    case 0:\n        range = "
                "0.0039215686274509803;\n        break;\n    case 1:\n        range = "
                "0.015873015873015872;\n        break;\n    default:\n        range = "
                "0.066666666666666666;\n        break;\n}\n@if (sk_Caps.integerSupport) {\n    "
                "uint x = uint(sk_FragCoord.x);\n    uint y = uint(sk_FragCoord.y);\n    uint m = "
                "(((((y & 1) << 5 | (x & 1) << 4) | (y & 2) << 2) | (x & 2) << 1) | (y & 4) >> 1) "
                "| (x & 4) >> 2;\n    value = float(float(half(m)) / 64.0) - 0.4921875;\n} else "
                "{\n    half4 modValues = half4(mod(sk_FragCoord.xyxy, float4(half4(2.0, 2.0, 4.0, "
                "4.0))));\n    half4 stepValues = half4(step(float4(modValues), float4(half4(1.0, "
                "1.0, 2.0, 2.0))));\n    value = float(dot(stepValues, half4(0.5, 0.25, 0.125, "
                "0.0625))) - 0.46875;\n}\n%s = half4(clamp(float3(%s.xyz + value * range), 0.0, "
                "float(%s.w)), %s.w);\n",
                _outer.rangeType(), args.fOutputColor,
                args.fInputColor ? args.fInputColor : "half4(1)",
                args.fInputColor ? args.fInputColor : "half4(1)",
                args.fInputColor ? args.fInputColor : "half4(1)");
    }

private:
    void onSetData(const GrGLSLProgramDataManager& pdman,
                   const GrFragmentProcessor& _proc) override {}
};
GrGLSLFragmentProcessor* GrDitherEffect::onCreateGLSLInstance() const {
    return new GrGLSLDitherEffect();
}
void GrDitherEffect::onGetGLSLProcessorKey(const GrShaderCaps& caps,
                                           GrProcessorKeyBuilder* b) const {
    b->add32(fRangeType);
}
bool GrDitherEffect::onIsEqual(const GrFragmentProcessor& other) const {
    const GrDitherEffect& that = other.cast<GrDitherEffect>();
    (void)that;
    if (fRangeType != that.fRangeType) return false;
    return true;
}
GrDitherEffect::GrDitherEffect(const GrDitherEffect& src)
        : INHERITED(src.optimizationFlags()), fRangeType(src.fRangeType) {
    this->initClassID<GrDitherEffect>();
}
std::unique_ptr<GrFragmentProcessor> GrDitherEffect::clone() const {
    return std::unique_ptr<GrFragmentProcessor>(new GrDitherEffect(*this));
}
GR_DEFINE_FRAGMENT_PROCESSOR_TEST(GrDitherEffect);
#if GR_TEST_UTILS
std::unique_ptr<GrFragmentProcessor> GrDitherEffect::TestCreate(GrProcessorTestData* testData) {
    float range = testData->fRandom->nextRangeF(0.001f, 0.05f);
    return std::unique_ptr<GrFragmentProcessor>(new GrDitherEffect(range));
}
#endif
#endif
