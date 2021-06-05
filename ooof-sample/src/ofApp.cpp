#include "ofApp.h"
#include "Ball.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  ofSetCircleResolution(32);
  ofEnableAlphaBlending();
  ofSetFrameRate(30);

}

//--------------------------------------------------------------
void ofApp::update(){
  for (int i = 0; i < balls.size(); i++) {
    balls[i].update();
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  for (int i = 0; i < balls.size(); i++) {
    balls[i].draw();
  }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
  switch (key) {
    case 'f':
      ofToggleFullscreen();
      break;
    case 'r':
      balls.clear();
  }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  int bSize = balls.size();
  if (bSize < 1) {
    Ball b = Ball();
    float radius = ofGetHeight() / 3;
    b.setRadius(radius);
    b.setSpeed(glm::vec2(0, 0));
    b.setPos(glm::vec2(mouseX, mouseY));
    balls.push_back(b);
  }
  
  for (int i = 0; i < bSize; i++) {
    glm::vec2 pos = balls[i].getPos();
    float radius = balls[i].getRadius();
    float dist = ofDist(pos.x, pos.y, mouseX, mouseY);

    if (dist < radius) {
      balls[i].setRadius(radius*0.6);
      balls[i].setPos(glm::vec2(pos.x - radius * 0.7, pos.y));
      balls[i].setSpeed(glm::vec2(ofRandom(-radius / 150, radius / 150),
            ofRandom(-radius / 150, radius / 150)));
      Ball b1 = Ball();
      b1.setRadius(radius * 0.6);
      b1.setPos(glm::vec2(pos.x + radius * 0.7, pos.y));
      b1.setSpeed(glm::vec2(ofRandom(-radius / 150, radius / 150),
          ofRandom(-radius / 150, radius / 150)));
      balls.push_back(b1);

      Ball b2 = Ball();
      b2.setRadius(radius * 0.6);
      b2.setPos(glm::vec2(pos.x + radius * 0.7, pos.y));
      b2.setSpeed(glm::vec2(ofRandom(-radius / 150, radius / 150),
          ofRandom(-radius / 150, radius / 150)));
      balls.push_back(b2);

      Ball b3 = Ball();
      b3.setRadius(radius * 0.6);
      b3.setPos(glm::vec2(pos.x + radius * 0.7, pos.y));
      b3.setSpeed(glm::vec2(ofRandom(-radius / 150, radius / 150),
          ofRandom(-radius / 150, radius / 150)));
      balls.push_back(b3);
    }
  }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
