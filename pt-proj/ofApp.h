#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxBox2dParticleSystem.h"
#include "ofxOpenCv.h"
#include "ofxGui.h"
#include "CustomCircle.h"


using namespace ofxBox2dParticleSystem;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

    void contactStart(ofxBox2dContactArgs &e);
    void contactEnd(ofxBox2dContactArgs &e);

		ofxBox2d box2d;
    vector <shared_ptr<ofxBox2dCircle>> contourCircles;

    ParticleSystem particleSystem;

    ofVideoGrabber vidGrabber;
    ofxCvColorImage colorImg;
    ofxCvGrayscaleImage grayImg;
    ofxCvGrayscaleImage grayBg;
    ofxCvGrayscaleImage grayDiff;
    ofImage renderImg;
    ofxCvContourFinder contourFinder;
    int col = 0;
    bool bLearnBackground;
    //int threshold;
    ofxFloatSlider threshold;
    ofxPanel gui;

    int initW = 320;
    int initH = 240;
    int cropW = 135;

    ofSoundPlayer sound;
    bool linging = false;
    bool imgOn = true;
    vector		<shared_ptr<ofxBox2dCircle> >	circles;
};
