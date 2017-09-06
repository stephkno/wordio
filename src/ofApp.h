#pragma once

#include "ofMain.h"
#include "ofxGif.h"

struct position
{
  int x;
  int y;
};

class Tile
{
  public:
		int letter;

    int x = 0;
    int y = 0;

    int xv;
    int yv;

    int destx;
    int desty;

    int xhome;
    int yhome;

    int tileSize = ofGetScreenWidth()/5;

    bool hidden = false;

		void setLetter(int l){
      cout << " Setting letter to: " << l << endl;
			letter = l;
		}
    int getLetter(){
      return(letter);
    }
    void setHidden(bool b){ hidden = b; }

    bool isHidden(){
      bool out = false;
      if(hidden){
        out = true;
      }
      return(out);
    }
    position getTilePosition(){
      position pos;
      pos.x = x;
      pos.y = y;
      return(pos);
    }
		void setPosition(int a, int b){
			//destx = a;
			//desty = b;
      x = a;
      y = b;
		}
    void updateTile(){
    //  cout << x << " " << y << endl;

  }
    void drawTile(string alphabet[26], ofTrueTypeFont font){
      cout << "L: " << letter << endl;
      //string l = alphabet[letter];
      //if(!hidden){
    //    ofSetColor(0);
    //    ofNoFill();
        //ofDrawCircle(x*tileSize+(tileSize/2), y*tileSize+50+(tileSize/2)+10, (tileSize/2)-10);
    //    ofSetColor(255);
    //    ofFill();
        //ofDrawCircle(x*tileSize+(tileSize/2), y*tileSize+50+(tileSize/2)+10, (tileSize/2)-10);
    //    ofSetColor(0);
       //font.drawString(l, (x*tileSize)+tileSize/2.5, (y*tileSize)+(tileSize-18));

    //  }

    }
    position getPosition(){

      position pos;
      pos.x = x;
      pos.y = y;


      return(pos);
    }

    void moveBy(int a, int b){
      x += a;
      y += b;
    }


};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    position getPos(int x, int y);
    void resetWords();
    Tile * getTilePlaceInVect(int x, int y);
    bool checkWord(vector<Tile*> word);
    void updateWorld();

		string alphabet[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
		 "s", "t", "u", "v", "w", "x", "y", "z"};

		int index;
		Tile niltile;
    Tile * npointer;
    ofImage img;
    int tileSize = 75;
    ofTrueTypeFont font;
    vector <Tile*> word;
    vector <Tile> tiles;
    vector <string> masterlist;
    vector <string*> words;
    position initialPos;
    position finalPos;
    bool gesturing = false;

    Tile * world[7][5] = {
      {npointer, npointer, npointer, npointer, npointer},
      {npointer, npointer, npointer, npointer, npointer},
      {npointer, npointer, npointer, npointer, npointer},
      {npointer, npointer, npointer, npointer, npointer},
      {npointer, npointer, npointer, npointer, npointer},
      {npointer, npointer, npointer, npointer, npointer},
      {npointer, npointer, npointer, npointer, npointer}
    };
};
