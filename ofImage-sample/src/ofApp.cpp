#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  ofEnableSmoothing();
  ofEnableBlendMode(OF_BLENDMODE_ADD);
  myImage.load("lenna.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(255);
  myImage.draw(20, 20);
  ofPixels pixels = myImage.getPixels();

  int w = myImage.getWidth();
  int h = myImage.getHeight();

  for (int i = 0; i < w; i += 8) {
    for (int j = 0; j < h; j+= 8) {
      int valueR = pixels[j * 3 * w + i * 3];
      int valueG = pixels[j * 3 * w + i * 3 + 1];
      int valueB = pixels[j * 3 * w + i * 3 + 2];

      ofSetColor(255, 0, 0, 63);
      ofDrawCircle(w + i, 20 + j, 10 * valueR /255);

      ofSetColor(0, 255, 0, 63);
      ofDrawCircle(w + i, 20 + j, 10 * valueG /255);

      ofSetColor(0, 0, 255, 63);
      ofDrawCircle(w + i, 20 + j, 10 * valueB /255);

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
