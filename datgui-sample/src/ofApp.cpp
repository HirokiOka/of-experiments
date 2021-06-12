#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

  ofxDatGuiComponent* component;
  
  for (int i = 0; i < 5; ++i) {
    plotters[i] = new ofxDatGuiValuePlotter("wave", 0, 1);
    plotters[i]->setDrawMode(ofxDatGuiGraph::LINES);
    component = plotters[i];
    component -> setPosition(0, i * 100);
    components.push_back(component);
  }
}

//--------------------------------------------------------------
void ofApp::update(){

  float current_frame = ofGetFrameNum();
  float val = sin(current_frame);

  for (int i = 0; i < components.size(); ++i) {
    plotters[i] -> setValue(val);
    components[i]->update();
  }

}

//--------------------------------------------------------------
void ofApp::draw(){

  for (int i = 0; i < components.size(); ++i) {
    components[i]->draw();
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
