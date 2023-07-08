#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0, 100, 0);
	ofSetVerticalSync(true);
  womanModel.load("woman-model/source/model/model3.obj", 20);
  womanModel.setScale(0.9, 0.9, 0.9);
	light.setPosition(0, 0, 600);
	womanModel.setPosition((float)ofGetWidth() / 2, (float)ofGetHeight() * 2/3  , 280);
	//womanModel.setRotation(0, 180, 1, 0, 0);
	

	ofEnableDepthTest();
	light.enable();

}

//--------------------------------------------------------------
void ofApp::update(){
  womanModel.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(255, 255);
  womanModel.drawFaces();
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
