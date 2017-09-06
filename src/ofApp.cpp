#include "ofApp.h"
#include <iostream>
#include <fstream>
#include <string>

//--------------------------------------------------------------
void ofApp::setup(){
  //create wordlist
  string line;
  //load file
  ifstream file("wordlist");
  if(file.is_open())
  {
    //push each line into vector
    while(getline(file, line)){
      masterlist.push_back(line);
    }
    cout << masterlist.size() << " words added.";
  }
  //create temp wordlist
  resetWords();
  //load font
  font.load("proggy.ttf", 100, true, true);
  tileSize = ofGetScreenWidth()/5;
  //populate world
  for(int x = 0; x < 5; x++){
    for(int y = 0; y < 7; y++){

      Tile newtile;
      //random letter
      cout << "Adding tile: " << newtile.getLetter() << endl;

      tiles.push_back(newtile);
      tiles.back().setPosition(x, y);
      tiles.back().setLetter(ofRandom(25));
      world[y][x] = &tiles.back();

    }
  }
  updateWorld();
}
//fall tiles
void ofApp::updateWorld(){
  for(int y = 6; y > 0; y--){
    for(int x = 0; x < 5; x++){
      cout << world[y][x]->letter << endl;
    }
  }
  for( Tile t : tiles){
    cout << ":" << t.letter << endl;
  }
}
//reset words creates a vector of wordlist pointers
void ofApp::resetWords(){
  words.clear();

  for(int i = 0; i < masterlist.size(); i++){
    words.push_back(&masterlist[i]);
  }
}
//returns true if word is in list
bool ofApp::checkWord(vector<Tile*> word){

  string checkword;
  bool out = false;
  //create string to check from input string pointer vector
  for(Tile* l : word){
    checkword.append(alphabet[l->getLetter()]);
  }
  cout << "Checking word: " << checkword << endl;
  //scan every word - slow
  for(string* w : words){
    cout << *w << endl;

    if(checkword == *w){
      //found word - break loop
      cout << "Match: " << *w << endl;
      out = true;
      break;
    }
  }
  if(!out){
    cout << "Word not found" << endl;
  }
  return(out);
}
//--------------------------------------------------------------
void ofApp::update(){

}
//--------------------------------------------------------------
void ofApp::draw(){

  ofScale(0.3, 0.3);
  ofBackground(50);
  ofSetColor(255);
  ofNoFill();
  ofDrawRectangle(0, 0, tileSize*5, tileSize*9);
  //draw tiles
  for(int y = 0; y < 7; y++){
    for(int x = 0; x < 5; x++){
    //world[y][x]->drawTile(alphabet, font);
    //  cout << ":" << world[y][x];
    }
    //cout << endl;
  }

  ofScale(0, 0);
}

Tile *ofApp::getTilePlaceInVect(int a, int b){
  Tile *out;

  for(int y = 0; y < 7; y++){
    for(int x = 0; x < 5; x++){

      Tile *t = world[y][x];
      position pos = t->getPosition();

      if(pos.x == a && pos.y == b){
        out = t;
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



}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
  gesturing = true;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

  initialPos.x = x;
  initialPos.y = y;

  int a = getPos(x, y).x;
  int b = getPos(x, y).y;
  if(a < 5 && b < 7){
    Tile *t = getTilePlaceInVect(a, b);
    cout << t->getLetter() << endl;
    if(!t->isHidden()){
      t->setHidden(true);
      cout << t->isHidden() << endl;

      word.push_back(t);
    }
  }
  for(int i = 0; i < word.size(); i++){
    int l = word[i]->getLetter();
    cout << alphabet[l];
  }
  cout << endl;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  if(gesturing){
    gesturing = false;
    finalPos.x = x;
    finalPos.y = y;
  }
  int dx = finalPos.x - initialPos.x;
  int dy = finalPos.y - initialPos.y;
//  cout << dx << " " << dy << endl;

  if(abs(dx) > 100 && abs(dx) > abs(dy) && dx < 0){
    cout << "Swipe left" << endl;
    Tile* t = word.back();
    word.pop_back();
    t->setHidden(false);

  }
  if(abs(dx) > 100 && abs(dx) > abs(dy) && dx > 0){

    cout << "Swipe right" << endl;
    if(checkWord(word)){
      cout << word[0] << endl;
      for(int i = 0; i < word.size(); i++){
        cout << ". " << word[i] << endl;

        word[i]->getLetter();
        word[i]->setLetter(26);

      }
      updateWorld();
    }
  }
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
