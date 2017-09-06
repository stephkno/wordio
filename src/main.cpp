#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
//960, 1704
	ofSetupOpenGL(600,1704, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new ofApp());

}
