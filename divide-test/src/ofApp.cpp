#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetVerticalSync(true);
  width = ofGetWidth();
  height = ofGetHeight();
  vidGrabber.setDeviceID(0);
  vidGrabber.setup(camWidth, camHeight, true);
  
}

//--------------------------------------------------------------
void ofApp::update(){
  vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofPixels pixels = vidGrabber.getPixels();
  float cFac = abs(sin(ofGetElapsedTimef()) * 0.8) + 1;
  int pixSize = 16;
  ofBackground(0);
  for (int j = 0; j < camHeight; j+=pixSize) {
    for (int i = 0; i < camWidth; i+=pixSize) {
      float tFac = abs(tan(ofGetElapsedTimef() * (i + j) * 0.002));
      unsigned char r = pixels[(j * camWidth + i) * 3];
      unsigned char g = pixels[(j * camWidth + i) * 3 + 1];
      unsigned char b = pixels[(j * camWidth + i) * 3 + 2];

      ofPushStyle();
      float hue3 = (r + g + b) / 3.0 * cFac;
      ofColor rCol = ofColor(0);
      rCol.setHsb(hue3, hue3, 255);
      ofSetColor(rCol);
      //std::cout << "rCol: " << endl;
      if (rCol.r == 0) {
        ofSetColor(r, g, b);
      }
      ofDrawRectangle(i, j, pixSize*tFac, pixSize*tFac);
      ofPopStyle();
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
