#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofSetWindowTitle("torus sample");
  ofBackground(239);
  ofSetLineWidth(2);
  ofEnableDepthTest();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  this->cam.begin();
  ofRotateX(90);
  ofRotate(ofGetFrameNum() * 3);

  int v_span = 1;
  int u_span = 30;

  ofMesh face, line;
  line.setMode(ofPrimitiveMode::OF_PRIMITIBE_LINES);

  for (int v = 0; v <= 360; v += v_span) {
    bool flag = true;
    int u_start = ofMap(ofNoise(200 * cos(v * DEG_TO_RAD) * 0.002, 200 * sin(v * DEG_TO_RAD) * 0.002, ofGetFrameNum() * 0.003), 0, 1, -360, 360);
    int next_u = ofMap(ofNoise(200 * cos((v + v_span) * DEG_TO_RAD) * 0.002, 200 * ((v + v_span) * 

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
