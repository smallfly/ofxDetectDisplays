#pragma once

#include "ofMain.h"

//--------------------------------------------------------------
struct DisplayInfo
{
    string UID;
    bool isPrimary;
    int left;
    int top;
	int width;
	int height;
};

//--------------------------------------------------------------
class ofxDetectDisplays
{
public:
    static ofxDetectDisplays* sharedInstance();
    
    ofxDetectDisplays();
    ~ofxDetectDisplays();
    
    int detectDisplays();
    void clearDisplays();

    int getNumDisplays();
    ofRectangle getDisplayBounds(int displayID);
	int getPrimaryDisplayID();
    bool isDisplayPrimary(int displayID);
    bool isMirroringEnabled();

    const vector<DisplayInfo*> & getDisplays();

    bool placeWindowOnDisplay(int displayID, bool borderless = false);
    bool fullscreenWindowOnDisplay(int displayID);
    
    ofEvent<void> displayConfigurationChanged;

private:
    vector<DisplayInfo*> displays;

	string utf8_encode(const std::wstring &wstr);
};

//--------------------------------------------------------------
ofxDetectDisplays& ofxDetectDisplaysSharedInstance();
