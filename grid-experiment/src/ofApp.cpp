#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0, 0, 200);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(0, 0, 200);
  int width = ofGetWidth();
  int height = ofGetHeight();

  ofSetColor(255, 0, 0);
  for (size_t i = offsetX; i < width - offsetX; i+=10) {
    for (size_t j = offsetX; j < height - offsetY; j+=10) {
      int x = i * ofNoise(i, j);
      int y = j;
      int s = 4;
      ofDrawRectangle(x, y, s, s);

    }
  }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
