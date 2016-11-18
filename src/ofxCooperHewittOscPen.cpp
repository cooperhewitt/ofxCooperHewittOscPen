#include "ofMain.h"
#include "ofxCooperHewittOscPen.h"

const int NUM_TAG_ARGS = 7;
const int NUM_PEN_ARGS = 4;
const int NUM_PEN_STATUS_ARGS = 4;
const string TAG_OSC_ADDRESS = "/tag";
const string PEN_OSC_ADDRESS = "/pen";
const string PEN_DONE_OSC_ADDRESS = "/pen-done";
const string PEN_CANCEL_OSC_ADDRESS = "/pen-cancel";
const string READER_OSC_ADDRESS = "/reader";
const string ALL_READERS_ADDRESS = "/readers";

ofxCooperHewittOscPen::ofxCooperHewittOscPen() {	
}

ofxCooperHewittOscPen::~ofxCooperHewittOscPen() {

}

void ofxCooperHewittOscPen::setup(int port)
{
	oscReceiver.setup(port);
}

void ofxCooperHewittOscPen::getPenMessages()
{
	while (oscReceiver.hasWaitingMessages()) {
		ofxOscMessage m;
		oscReceiver.getNextMessage(&m);

		ofLogNotice("ofxCooperHewittOscPen") << m.getAddress();

		if ((m.getAddress() == TAG_OSC_ADDRESS) && (m.getNumArgs() == NUM_TAG_ARGS)) {
			tagEvent tag = {
				m.getArgAsString(0),
				m.getArgAsString(1),
				m.getArgAsString(2),
				m.getArgAsString(3),
				m.getArgAsString(4),
				m.getArgAsString(5),
				m.getArgAsFloat(6)
			};
			ofLogNotice("ofxCooperHewittOscPen") << "Reading Tag: " << tag.tagID << " for Visit: " << tag.visitID << endl;
			ofNotifyEvent(onTag, tag, this);
		}
		
		else if ((m.getAddress() == PEN_OSC_ADDRESS) && (m.getNumArgs() == NUM_PEN_ARGS)) {
			penEvent pen = {
				m.getArgAsString(0),
				m.getArgAsString(1),
				m.getArgAsString(2),
				m.getArgAsFloat(3),
			};
			ofLogNotice("ofxCooperHewittOscPen") << "Reading Pen: " << pen.penID << endl;
			ofNotifyEvent(onPen, pen, this);

		}

		else if ((m.getAddress() == PEN_DONE_OSC_ADDRESS) && (m.getNumArgs() == NUM_PEN_STATUS_ARGS)) {
			penStatusEvent penStatus = {
				m.getArgAsString(0),
				m.getArgAsString(1),
				m.getArgAsString(2),
				m.getArgAsInt32(3)
			};
			ofLogNotice("ofxCooperHewittOscPen") << "Done reading pen: " << penStatus.penID << endl;
		}

		else if ((m.getAddress() == PEN_CANCEL_OSC_ADDRESS) && (m.getNumArgs() == NUM_PEN_STATUS_ARGS)) {
			penStatusEvent penStatus = {
				m.getArgAsString(0),
				m.getArgAsString(1),
				m.getArgAsString(2)
			};
			ofLogNotice("ofxCooperHewittOscPen") << "Canceled reading pen: " << penStatus.penID << endl;
		}

		else if (m.getAddress() == READER_OSC_ADDRESS) {
			string readerID = m.getArgAsString(0);
			ofLogNotice("ofxCooperHewittOscPen") << "Reader ID: " << readerID << endl;
			ofNotifyEvent(onReader, readerID, this);
		}
		
		else if (m.getAddress() == ALL_READERS_ADDRESS) {
			int numReaders = m.getArgAsInt32(0);
			ofLogNotice("ofxCooperHewittOscPen") << "Numbr of readers: " << numReaders << endl;
		}
	}

}
