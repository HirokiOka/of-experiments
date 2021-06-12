#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  light.setSpotlight();
  light.setPosition(-400, 400, 800);
  light.enable();

  material.setAmbientColor(ofColor(127, 63, 31));
  material.setDiffuseColor(ofColor(0, 127, 255));
  material.setSpecularColor(ofColor(255, 255, 0, 255));
  material.setShininess(120);
  material.setEmissiveColor(ofColor(97, 0, 0));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofEnableDepthTest();
  ofSetColor(31, 127, 255);
  material.begin();
  camera.begin();

  box.set(200);
  box.setPosition(-120, 0, 0);
  box.draw();

  sphere.set(100, 8);
  sphere.setPosition(120, 0, 0);
  sphere.draw();
  camera.end();
  material.end();
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
