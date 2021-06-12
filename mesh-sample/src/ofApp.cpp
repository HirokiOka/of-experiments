#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofBackground(0);
  ofPlanePrimitive plane;
  plane.set(1000, 1000, 100, 100);
  mesh = plane.getMesh();

}

//--------------------------------------------------------------
void ofApp::update(){
  float div = 400.0;
  float scale = 300.0;
  float speed = 0.25;
  for (int i = 0; i < mesh.getVertices().size(); ++i) {
    glm::vec3 pos = mesh.getVertices()[i];
    pos.z = ofNoise(pos.x / div, pos.y / div, ofGetElapsedTimef() * speed) * scale;
    mesh.setVertex(i, pos);
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  ofRotateXDeg(-45);
  mesh.drawWireframe();
  cam.end();

}
