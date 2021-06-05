#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  sampleRate = 44100;
  amp = 0.5;
  pan = 0.5;
  phase = 0;
  frequency = 440;

  //settings
  ofSoundStreamSettings settings;
  settings.setOutListener(this);
  settings.sampleRate = sampleRate;
  settings.numOutputChannels = 2;
  settings.numInputChannels = 0;
  settings.bufferSize = 512;
  soundStream.setup(settings);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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

void ofApp::audioRequested(float* output, int bufferSize, int nChannels) {
  float sample;
  float phaseDiff;

  phaseDiff = TWO_PI * frequency / sampleRate;

  for (int i = 0; i < bufferSize; i++) {
    phase += phaseDiff;
    while (phase > TWO_PI) {
      phase -= TWO_PI;
    }

    sample = sin(phase);
    output[i * nChannels] = sample * pan * amp;
    output[i * nChannels + 1] = sample * pan * amp;
  }
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
