#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  //ofBackgroundHex(0x000000);
  ofBackground(255);
  //ofEnableBlendMode(OF_BLENDMODE_ADD);
  ofSetVerticalSync(true);
  //ofLog(OF_LOG_NOTICE, "width:" + ofToString(ofGetWidth()));
  //ofLog(OF_LOG_NOTICE, "height:" + ofToString(ofGetHeight()));

  gui.setup();
  gui.add(threshold.setup("threshold", 40, 10, 255));

  vidGrabber.setDeviceID(1);
  vidGrabber.initGrabber(initW, initH);

  colorImg.allocate(initW ,initH);
  grayImg.allocate(cropW, initH);
  grayBg.allocate(cropW, initH);
  grayDiff.allocate(cropW, initH);

  renderImg.allocate(initW, initH, OF_IMAGE_COLOR);
  bLearnBackground = true;

  ofLog(OF_LOG_NOTICE, "imgPixSize:" + ofToString(colorImg.getPixels().size()));

  box2d.init();
  box2d.setGravity(0, 0);
  box2d.enableEvents();
  box2d.createBounds(0, 0, cropW, colorImg.height);
  box2d.setFPS(30);
  box2d.checkBounds(true);

  /*
	ofAddListener(box2d.contactStartEvents, this, &ofApp::contactStart);
	ofAddListener(box2d.contactEndEvents, this, &ofApp::contactEnd);
  */

  int maxParticles = 5000;
  particleSystem.init(box2d.getWorld());
  particleSystem.setMaxParticles(maxParticles);
  particleSystem.setRadius(2);

  sound.loadSound("pianoC.mp3");

  for(int i=0; i<maxParticles; i++) {
    particleSystem.addParticle(colorImg.width/4 + ofRandom(-20, 20), ofRandom(-50, 50));
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  box2d.update();
  vidGrabber.update();
  /*
  for (int i = 0; i < circles.size();i++) {
    circles[i]->update();
  }
  */
  if (vidGrabber.isFrameNew()) {
    renderImg.setFromPixels(vidGrabber.getPixels());
    renderImg.mirror(false, true);
    renderImg.crop(initW/2-cropW/2, 0, cropW, initH);
    colorImg.setFromPixels(renderImg.getPixels());
    grayImg = colorImg;
    if (bLearnBackground) {
      grayBg = grayImg;
      bLearnBackground = false;
    }
    grayDiff.absDiff(grayBg, grayImg);
    grayDiff.threshold(threshold);
    contourFinder.findContours(grayDiff, 20, (colorImg.width*colorImg.height)/ 3, 10, false);
    for (int i = 0; i < contourCircles.size(); i++) {
      contourCircles[i]->destroy();
    }
    contourCircles.clear();
    for (int i = 0; i < contourFinder.nBlobs; i++) {
      for (int j = 0; j < contourFinder.blobs[i].pts.size(); j+=4) {
        glm::vec2 pos = contourFinder.blobs[i].pts[j];
        auto circle = make_shared<ofxBox2dCircle>();
        circle->setup(box2d.getWorld(), pos.x, pos.y, 4);
        contourCircles.push_back(circle);
      }
    }
  }
  /*
	if((int)ofRandom(0, 50) == 0) {
        auto c = make_shared<ofxBox2dCircle>();
        c->setPhysics(1, 0.5, 0.9);
        c->setup(box2d.getWorld(), colorImg.width/4 + ofRandom(-30, 30), 10, 5);
        circles.push_back(c);
	}
  */
}

//--------------------------------------------------------------
void ofApp::draw(){

  //Target: 1080 * 1920
  //135, 240
  //9, 16
  //Mac: 2560*1600
  //ouchi Display: 1920 * 1080
  ofSetColor(255);
  ofPushMatrix();
  //ofScale((float)ofGetWidth() / (float)grayDiff.width, (float)ofGetHeight() / (float)grayDiff.height);
  ofScale((float)ofGetWidth() / (float)colorImg.width, (float)ofGetHeight() / (float)colorImg.height);
  if (imgOn) {
    colorImg.draw(0, 0);
  }
  //col == 0 ? ofSetColor(20, 20, 200) : ofSetColor(200, 10, 10);
  ofSetColor(0);
  particleSystem.updateMesh();
  particleSystem.draw();
  /*
  contourFinder.draw();
  for (int i = 0; i < contourCircles.size(); i++) {
    contourCircles[i]->draw();
  }
	for(size_t i=0; i<circles.size(); i++) {
		circles[i]->draw();
	}
  */
  ofPopMatrix();
  gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  switch (key) {
    case ' ':
      bLearnBackground = true;
      break;
    case 'b':
      imgOn = (imgOn ? false : true);
      break;
    case 's':
      sound.setSpeed(ofRandom(0.5, 2.0));
      sound.play();
      break;
    case 'g':
      col = 1;
      box2d.setGravity(0, 2);
      break;
    case 'n':
      col = 0;
      box2d.setGravity(0, 0);
      break;
  }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

void ofApp::contactStart(ofxBox2dContactArgs &e) {
        sound.setSpeed(ofRandom(0.5, 2.0));
        sound.play();
	if(e.a != NULL && e.b != NULL) { 
		if(e.a->GetType() == b2Shape::e_circle && e.b->GetType() == b2Shape::e_circle) {
        sound.setSpeed(ofRandom(0.5, 2.0));
        sound.play();
      }
	}
}

void ofApp::contactEnd(ofxBox2dContactArgs &e) {
	if(e.a != NULL && e.b != NULL) { 
  }
		
}
