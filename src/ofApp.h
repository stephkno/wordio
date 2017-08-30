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

    int x;
    int y;

    int xv;
    int yv;

    int destx;
    int desty;

    int xhome;
    int yhome;

		void setLetter(int l){
			letter = l;
		}
		void setPosition(int a, int b){
			destx = a;
			desty = b;
		}

    position getPosition(){

      position pos;
      pos.x = x;
      pos.y = y;

      return(pos);
    }

    char getLetter(){
      return(letter);
    }
		void drawTile(ofxGIF::fiGifLoader tiles, int a, int b){



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

		string alphabet[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
		 "s", "t", "u", "v", "w", "x", "y", "z"};

		int index;
		ofxGIF::fiGifLoader gif;
		Tile testtile;
    vector <Tile> tiles;
    ofImage img;
    int tileSize = 75;
    ofTrueTypeFont font;


};
