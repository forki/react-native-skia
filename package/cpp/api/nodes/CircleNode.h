#pragma once

#include "Node.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#pragma clang diagnostic pop

namespace RNSkia {

    using namespace facebook;


    class CircleNode: public Node {
    public:
        CircleNode(jsi::Runtime &runtime, jsi::Object &props): Node(runtime, props) {}

        std::string name() {
            return "CircleNode";
        }

        void render(SkCanvas* canvas, SkPaint& parentPaint) {
            auto cx = materializeNumber("cx");
            auto cy = materializeNumber("cy");
            auto r = materializeNumber("r");
            auto paint = processPaint(parentPaint);
            canvas->drawCircle(cx, cy, r, paint);
        }
    };
} // namespace RNSkia