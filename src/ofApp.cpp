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
    t.updateTile();
  }
}

//--------------------------------------------------------------
void ofApp::draw(){

  ofBackground(50);

  for(Tile t : tiles){

    position pos = t.getPosition();
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

int ofApp::getTilePlaceInVect(int x, int y){

  int i = 0;
  int out = 0;
    for(Tile t : tiles){
      i++;
    if(t.getTilePosition().x == x && t.getTilePosition().y == y){
      out = i;
    }
  }
  return(out);
}

position ofApp::getPos(int x, int y){
  position pos;
  pos.x = (x)/75;
  pos.y = (y-50)/75;
  return(pos);
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

  int a = getPos(x, y).x;
  int b = getPos(x, y).y;

  int t = getTilePlaceInVect(a, b);
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
