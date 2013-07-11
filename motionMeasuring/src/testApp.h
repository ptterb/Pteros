#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"


struct teamSection {
    int ident;

    int x;
    int y;
    int w;
    int h;
    
    ofColor color;

    float brightSum;
    float brightAvg;
    // TODO KEEP TRACK OF THE TOTAL BRIGHTNESS AND DISPLAY AS A GRAPH
    float brightTotal;
    
    float pteroX;
    float pteroY;
    ofImage pteroFile;
    
};



class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        int vWidth = 640;
        int vHeight = 480;
        ofVideoGrabber grabber;
        ofxCvColorImage colorImage;
        ofxCvGrayscaleImage grayImage;
        ofxCvGrayscaleImage lastImage;
        ofxCvGrayscaleImage grayDiff;

        float brightSum;
        float brightAvg;
    
    vector<teamSection> teams;
    
    string winner;
    bool won = false;
    bool debug = false;
    bool start = false;

};
