#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

class ofxCooperHewittOscPen {

public:

	ofxCooperHewittOscPen();
	~ofxCooperHewittOscPen();

	string getPenMessages();

protected:

	ofxOscReceiver oscReceiver;

};
