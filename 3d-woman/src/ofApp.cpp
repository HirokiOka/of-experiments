#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
  womanModel.load("woman-model/source/model/model3.obj", 20);
  //womanModel.setScale(0.9, 0.9, 0.9);
	light.setPosition(0, 0, 800);
  //light.setAmbientColor(100);

	womanModel.setPosition((float)ofGetWidth() / 2, (float)ofGetHeight() * 5 / 7 , 380);
	womanModel.setRotation(0, 40, 80, 100, 20);
	//womanModel.setRotation(0, 180, 0, 100, 20);

  /*
  */
	ofEnableDepthTest();
	light.enable();
  ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);

}

//--------------------------------------------------------------
void ofApp::update(){
  womanModel.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(255);
  float xnoise = 0.0;
  float ynoise = 0.0;
  float xstart = 0.0;
  for (int j = 0; j < ofGetHeight() * 2; j+=4) {
    ynoise += 0.08;
    xnoise = xstart;
    for (int i = 0; i < ofGetWidth() * 2; i+=4) {
      xnoise += 0.08;
      float noiseFactor = ofNoise(xnoise, ynoise);
      ofSetColor(10 * noiseFactor, 255);
      ofDrawCircle(i * noiseFactor, j * noiseFactor, 1 * noiseFactor);
    }
  }
  //womanModel.drawFaces();
  ofSetColor(0, 255);
  womanModel.drawVertices();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if(key == 'x'){
      img.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
      img.save("screenshot.png");
  }
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
