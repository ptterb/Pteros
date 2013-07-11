#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    model.loadModel("Pterodactyl/Pterodactyl.obj");

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    cam.begin();
    
    ofBackground(50, 50, 50, 0);
    ofSetColor(255, 255, 255, 255);
    
    model.setPosition(ofGetWidth()*2/6, (float)ofGetHeight() * 0.75 , 0);
    model.draw(OF_MESH_FILL); //same as model.drawFaces();
    model.setPosition(ofGetWidth()*3/6, (float)ofGetHeight() * 0.75 , 0);
    model.draw(OF_MESH_POINTS); // same as model.drawVertices();
    model.setPosition(ofGetWidth()*4/6, (float)ofGetHeight() * 0.75 , 0);
    model.draw(OF_MESH_WIREFRAME); // same as model.drawWireframe();
    
    cam.end();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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