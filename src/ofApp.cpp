#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){



  font.load("proggy.ttf", 55, true, true);


  ofSetWindowShape(960, 1704);
  for(int x = 0; x < 5; x++){
    for(int y = 0; y < 7; y++){

      Tile newtile;

      newtile.setLetter(ofRandom(25));
      newtile.setPosition(x, y);
      world[y][x] = newtile;

    }
  }

  niltile.setLetter(-1);

}

//--------------------------------------------------------------
void ofApp::update(){
  for(int y = 0; y < 7; y++){
    for(int x = 0; x < 5; x++){
      world[y][x].updateTile();
    }
  }

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofScale(0.5, 0.5);

  ofBackground(50);

  ofSetColor(0);
  ofNoFill();
  ofDrawRectangle(0, 0, 960, 1704);

  for(int y = 0; y < 7; y++){
    for(int x = 0; x < 5; x++){
      Tile t = world[y][x];

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
      string l = alphabet[t.letter];
      font.drawString(l, a+20, b+55);
    //  ofScale(0, 0);*/
    }
  }
}

Tile *ofApp::getTilePlaceInVect(int a, int b){
  Tile *out;
  for(int y = 0; y < 7; y++){
    for(int x = 0; x < 5; x++){
      Tile t = world[y][x];
      position pos = t.getPosition();

      if(pos.x == x && pos.y == y){

        out = &t;

      }
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

  for(int y = 0; y < 7; y++){
    for(int x = 0; x < 5; x++){
      cout << world[y][x].letter << " ";
    }
    cout << endl;
  }

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

  getTilePlaceInVect(a, b)->toggleVisibility();


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
