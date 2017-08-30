#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){

  font.load("proggy.ttf", 55, true, true);


  ofSetWindowShape(375, 667);
  for(int x = 0; x <= 5; x++){
    for(int y = 0; y <= 6; y++){

      Tile newtile;

      newtile.setLetter(ofRandom(25));
      newtile.setPosition(x, y);
      tiles.push_back(newtile);

    }
  }

}

//--------------------------------------------------------------
void ofApp::update(){
  for(Tile t : tiles){
    //cout << t.letter << endl;
  }


}

//--------------------------------------------------------------
void ofApp::draw(){

  ofBackground(50);

  for(Tile t : tiles){

    position pos = t.getPosition();

    cout << pos.x << " " << pos.y << endl;

    //ofScale(0.3, 0.3);
    int a = pos.x * tileSize;
    int b = pos.y * tileSize + 50;

    //gif.pages[t.getLetter()].draw(a,b);
    ofSetColor(0);
    ofNoFill();
    ofDrawRectangle(a, b, 75, 75);
    ofSetColor(255);
    ofFill();
    ofDrawRectangle(a, b, 75, 75);
    ofSetColor(0);
    string l = alphabet[t.getLetter()];
    font.drawString(l, a+20, b+55);
  //  ofScale(0, 0);

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
