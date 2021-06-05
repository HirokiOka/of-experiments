#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);

  vidGrabber.initGrabber(320, 240);
  colorImg.allocate(320, 240);
  grayImage.allocate(320, 240);
  grayBg.allocate(320, 240);
  grayDiff.allocate(320, 240);
  bLearnBackground = true;
  threshold = 100;
}

//--------------------------------------------------------------
void ofApp::update(){
  bool bNewFrame = false;
  vidGrabber.update();
  bNewFrame = vidGrabber.isFrameNew();
  if (bNewFrame) {
    colorImg.setFromPixels(vidGrabber.getPixels());
    grayImage = colorImg;
    if (bLearnBackground == true) {
      grayBg = grayImage;
      bLearnBackground = false;
  }
    grayDiff.absDiff(grayBg, grayImage);
    grayDiff.threshold(threshold);
    contourFinder.findContours(grayDiff, 20, (340 * 240) / 3, 10, true);
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  colorImg.draw(10, 10);
  grayImage.draw(340, 10);
  grayBg.draw(10, 260);
  grayDiff.draw(340, 260);
  contourFinder.draw(340, 500);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  switch (key) {
    case ' ':
      bLearnBackground = true;
      break;
    case '+':
      threshold++;
      if (threshold > 255) threshold = 255;
      break;
    case '-':
      threshold--;
      if (threshold < 0) threshold = 0;
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
