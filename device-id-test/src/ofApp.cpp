#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  devices = vidGrabber.listDevices();
  for (int i = 0; i < devices.size(); i++) {
    if (devices[i].bAvailable) {
      ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
    } else {
      ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable";
    }
  }

  vidGrabber.setDeviceID(0);
  vidGrabber.setDesiredFrameRate(30);
  vidGrabber.initGrabber(640, 480);

}

//--------------------------------------------------------------
void ofApp::update(){
  vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  vidGrabber.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  switch (key) {
    case '0':
      vidGrabber.close();
      vidGrabber.setDeviceID(0);
      vidGrabber.initGrabber(640, 480);
      ofLogNotice() << "device: 0" << endl;
      break;
    case '1':
      vidGrabber.close();
      vidGrabber.setDeviceID(1);
      vidGrabber.initGrabber(640, 480);
      ofLogNotice() << "device: 1" << endl;
      break;
    case '2':
      vidGrabber.close();
      vidGrabber.setDeviceID(2);
      vidGrabber.initGrabber(640, 480);
      ofLogNotice() << "device: 2" << endl;
      break;
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
