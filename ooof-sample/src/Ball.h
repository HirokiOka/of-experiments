#pragma once

#include "ofMain.h"

class Ball {
  private:
    glm::vec2 pos;
    float radius;
    glm::vec2 speed;
    float phase;
    float phaseSpeed;
    float strechedRadius;
    ofColor color;

  public:
    Ball();
    void draw();
    void update();
    void setRadius(float radius);
    float getRadius();
    void setPos(glm::vec2 pos);
    glm::vec2 getPos();
    void setSpeed(glm::vec2 speed);
    glm::vec2 getSpeed();
};
