#pragma once

#include "NodeProp.h"
#include "PointProp.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

#include <SkPoint.h>

#pragma clang diagnostic pop

namespace RNSkia {

static PropId PropNameCx = JsiPropId::get("cx");
static PropId PropNameCy = JsiPropId::get("cy");
static PropId PropNameC = JsiPropId::get("c");

class CircleProp:
public DerivedProp<SkPoint> {
public:
  CircleProp(): DerivedProp<SkPoint>() {
    _c = addProperty(std::make_shared<PointProp>(PropNameC));
    _cx = addProperty(std::make_shared<NodeProp>(PropNameCx));
    _cy = addProperty(std::make_shared<NodeProp>(PropNameCy));
  }
  
  void updateDerivedValue() override {
    if (_c->hasValue()) {
      setDerivedValue(_c->getDerivedValue());
    } else if (_cx->hasValue() && _cy->hasValue()) {
      setDerivedValue(SkPoint::Make(_cx->getValue()->getAsNumber(),
                                    _cy->getValue()->getAsNumber()));
    }
  }
  
private:
  std::shared_ptr<PointProp> _c;
  std::shared_ptr<NodeProp> _cx;
  std::shared_ptr<NodeProp> _cy;
};

}