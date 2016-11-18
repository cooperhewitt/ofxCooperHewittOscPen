#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

class ofxCooperHewittOscPen {

public:

	ofxCooperHewittOscPen();
	~ofxCooperHewittOscPen();

	void setup(int port);

	string getPenMessages();

protected:

	struct tagEvent {
		string readerID;
		string penID;
		string visitID;
		string objectType;
		string tagID;
		string timeSInceSetup;
		float progress;
	};

	struct penEvent {
		string readerID;
		string penID;
		string visitID;
		float progress;
	};

	struct penStatusEvent {
		string readerID;
		string penID;
		string visitID;
		bool isTimeout;
	};
	ofxOscReceiver oscReceiver;

};
