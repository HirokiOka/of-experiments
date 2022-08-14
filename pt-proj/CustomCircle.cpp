#include "CustomCircle.h"

void CustomCircle::draw() {
  float radius = getRadius();
  ofPushMatrix();
  ofTranslate(getPosition().x, getPosition().y);
  ofFill();
  ofSetColor(0, 0, 255, 200);
  ofDrawCircle(0, 0, radius);
  ofPopMatrix();
}
