#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

  gif.load("font.gif");

  ofSetWindowShape(375, 667);
  for(int x = 0; x <= 6; x++){
    for(int y = 0; y <= 8; y++){

      Tile newtile;

      newtile.setLetter(5);
      newtile.setPosition(x, y);
      tiles.push_back(newtile);

    }
  }

}

//--------------------------------------------------------------
void ofApp::update(){
  for(t : tiles){
    cout << t.letter << endl;
  }
}

//--------------------------------------------------------------
void ofApp::draw(){

  ofBackground(50);

  for(t : tiles){

    t.drawTile(gif);

  }

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

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
