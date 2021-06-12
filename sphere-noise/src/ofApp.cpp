#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofBackground(0);

  ofIcoSpherePrimitive sphere;
  sphere.setRadius(100);
  sphere.setResolution(5);
  mesh = sphere.getMesh();

  light.setPosition(-400, 400, 800);
  light.enable();

  material.setAmbientColor(ofColor(127, 127, 255));
  material.setDiffuseColor(ofColor(0, 127, 255));
  material.setSpecularColor(ofColor(255, 255, 0, 127));
  material.setShininess(120);
}

//--------------------------------------------------------------
void ofApp::update(){
  float div = 400.0;
  float size = 340.0;

  for (int i = 0; i < mesh.getVertices().size(); ++i) {
    glm::vec3 loc = mesh.getVertices()[i];
    float noise = ofMap(ofNoise(loc.x / div, loc.y / div, loc.z / div, ofGetElapsedTimef()), 0, 1, size / 2.0, size);
    glm::vec3 newLoc = glm::normalize(loc) * noise;
    mesh.setVertex(i, newLoc);
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofEnableDepthTest();
  material.begin();
  cam.begin();

  ofRotateXDeg(ofGetElapsedTimef() * 10.0);
  ofRotateYDeg(ofGetElapsedTimef() * 15.0);

  mesh.draw();
  material.end();
  cam.end();
  ofDisableDepthTest();
}
