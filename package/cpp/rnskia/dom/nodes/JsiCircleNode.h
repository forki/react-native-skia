#pragma once

#include "JsiDomDrawingNode.h"
#include "CircleProp.h"

namespace RNSkia {

class JsiCircleNode : public JsiDomDrawingNode, public JsiDomNodeCtor<JsiCircleNode> {
public:
  JsiCircleNode(std::shared_ptr<RNSkPlatformContext> context) :
  JsiDomDrawingNode(context, "skCircle") {}
    
protected:
  void draw(JsiDrawingContext* context) override {
    if (!_circleProp->hasValue() || !_r->hasValue()) {
      getContext()->raiseError(std::runtime_error("Expected circle node to have a cx, cy or c \
                                                  and r properties."));
    }
    auto paint = *context->getPaint();
    context->getCanvas()->drawCircle(*_circleProp->getDerivedValue(),
                                     _r->getValue()->getAsNumber(),
                                     paint);
  }
  
  void defineProperties(NodePropsContainer* container) override {
    JsiDomDrawingNode::defineProperties(container);
    _circleProp = container->defineProperty(std::make_shared<CircleProp>());
    _r = container->defineProperty(std::make_shared<NodeProp>(PropNameR));
  }
  
private:
  std::shared_ptr<CircleProp> _circleProp;
  std::shared_ptr<NodeProp> _r;
};

}