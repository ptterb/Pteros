#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    
    // Allocate images
    grabber.initGrabber(vWidth, vHeight);
    colorImage.allocate(vWidth, vHeight);
    grayImage.allocate(vWidth, vHeight);
    grayDiff.allocate(vWidth, vHeight);
    
    // Set up teams
    teamSection team1;
    team1.ident = 1;
    team1.x = 50;
    team1.y = 320;
    team1.w = 150;
    team1.h = 150;
    team1.color = ofColor(255,0,0);
    team1.brightTotal = 0;
    team1.pteroX = 50;
    team1.pteroY = 320;
    team1.pteroFile.loadImage("ptero1.png");
    
    teamSection team2;
    team2.ident = 2;
    team2.x = 250;
    team2.y = 320;
    team2.w = 150;
    team2.h = 150;
    team2.color = ofColor(0,255,0);
    team2.brightTotal = 0;
    team2.pteroX = 250;
    team2.pteroY = 320;
    team2.pteroFile.loadImage("ptero2.png");
    
    teamSection team3;
    team3.ident = 3;
    team3.x = 450;
    team3.y = 320;
    team3.w = 150;
    team3.h = 150;
    team3.color = ofColor(0,0,255);
    team3.brightTotal = 0;
    team3.pteroX = 450;
    team3.pteroY = 320;
    team3.pteroFile.loadImage("ptero3.png");
    
    teams.push_back(team1);
    teams.push_back(team2);
    teams.push_back(team3);
    
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    if (start == true){
        // Update the grabber, update the filter
        grabber.update();
        
        if (grabber.isFrameNew()){
            
            colorImage.setFromPixels(grabber.getPixelsRef());
            colorImage.mirror(false, true);
            
            grayImage = colorImage;
            
            // Run differencing between last frame and this one
            grayDiff.absDiff(grayImage, lastImage);
            
            lastImage = grayImage;
            
            ofPixelsRef diffPix = grayDiff.getPixelsRef();
            
            // Loop through teams' sections and check how much movement there is
            for (int i = 0; i < teams.size(); i++){
                
                teams.at(i).brightSum = 0.0f;
                
                // Check for average brightness in the difference image
                for (int x = teams.at(i).x; x < teams.at(i).x + teams.at(i).w; x++){
                    for (int y = teams.at(i).y ; y < teams.at(i).y + teams.at(i).h; y++){
                        ofColor tempColor = diffPix.getColor(x,y);
                        
                        teams.at(i).brightSum += tempColor.getBrightness();
                    }
                }
                
                teams.at(i).brightAvg = teams.at(i).brightSum / (teams.at(i).w * teams.at(i).h);
                
                // If the movement is above a given threshold, add that value to total
                if (teams.at(i).brightAvg > 5.0f) {
                    teams.at(i).brightTotal += teams.at(i).brightAvg;
                    
                    // subtract the value from the pteroY to move up the screen
                    teams.at(i).pteroY -= teams.at(i).brightAvg * .1;
                }
                
                
                // Check for a winner
                if (teams.at(i).pteroY <= 10){
                    string team;
                    switch (teams.at(i).ident) {
                        case 1:
                            team = "Red";
                            break;
                            
                        case 2:
                            team = "Green";
                            break;
                            
                        case 3:
                            team = "Blue";
                            break;
                            
                        default:
                            break;
                    }
                    
                    winner = team + " team wins!!!";
                    won = true;
                    
                    
                }
            }
            
            
            
        }
        
        // DEBUG
        for (int i = 0; i < teams.size(); i++){
            ofLogNotice() << teams.at(i).ident << " " << teams.at(i).pteroY;
        }
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    // DEBUG
    if (debug){
        grayDiff.draw(0, 0);
    }
    else {
        colorImage.draw(0, 0);
    }

    
    // Draw elements to screen while race is on
    if (won == false) {
        if (start == false){
            ofDrawBitmapString("Press 'g' to start", 640/2, 480/2);
        }
        else {
            for (int i = 0; i < teams.size(); i++){
                ofSetColor(teams.at(i).color);
                ofNoFill();
                ofRect(teams.at(i).x, teams.at(i).y, teams.at(i).w, teams.at(i).h);
                ofSetColor(255, 255, 255);
                
                teams.at(i).pteroFile.draw(teams.at(i).pteroX, teams.at(i).pteroY);
            }
        }
        
    }
    // Declare winner
    else {
        ofDrawBitmapString(winner, 640/2, 480/2);
    }

    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    // 'D' key to switch between full color mode and difference mode
    switch (key) {
        case 'd':
            debug = !debug;
            break;
            
        case 'g':
            start = !start;
            break;
            
        default:
            break;
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}