#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofEvents.h"

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

class ofxCooperHewittOscPen {

public:

	ofxCooperHewittOscPen();
	~ofxCooperHewittOscPen();

	void setup(int port);
	void getPenMessages();

	ofEvent <std::string> onReader;
	ofEvent <int> onAllReaders;
	ofEvent <penEvent> onPen;
	ofEvent <penStatusEvent> onPenDone;
	ofEvent <penStatusEvent> onPenCancel;
	ofEvent <tagEvent> onTag;

protected:

	ofxOscReceiver oscReceiver;

};
