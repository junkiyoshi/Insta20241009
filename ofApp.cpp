#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofNoFill();
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 1.44);

	ofSetLineWidth(2);
	ofColor color;
	for (int i = 0; i < 1000; i++) {
		
		color.setHsb(ofMap(i, 0, 1000, 0, 255), 255, 230);
		auto noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));

		for (int k = 0; k < 10; k++) {

			auto location = glm::vec3(
				ofMap(ofNoise(noise_seed.x, (ofGetFrameNum() + k) * 0.005), 0, 1, -200, 200),
				ofMap(ofNoise(noise_seed.y, (ofGetFrameNum() + k) * 0.005), 0, 1, -200, 200),
				ofMap(ofNoise(noise_seed.z, (ofGetFrameNum() + k) * 0.005), 0, 1, -200, 200));
			auto next = glm::vec3(
				ofMap(ofNoise(noise_seed.x, (ofGetFrameNum() + k + 1) * 0.005), 0, 1, -200, 200),
				ofMap(ofNoise(noise_seed.y, (ofGetFrameNum() + k + 1) * 0.005), 0, 1, -200, 200),
				ofMap(ofNoise(noise_seed.z, (ofGetFrameNum() + k + 1) * 0.005), 0, 1, -200, 200));

			if (location.x > 120) { location.x = 120; }
			if (location.x < -120) { location.x = -120; }
			if (next.x > 120) { next.x = 120; }
			if (next.x < -120) { next.x = -120; }

			if (location.y > 120) { location.y = 120; }
			if (location.y < -120) { location.y = -120; }
			if (next.y > 120) { next.y = 120; }
			if (next.y < -120) { next.y = -120; }

			if (location.z > 120) { location.z = 120; }
			if (location.z < -120) { location.z = -120; }
			if (next.z > 120) { next.z = 120; }
			if (next.z < -120) { next.z = -120; }

			if (location.y > 0 && location.y < 100) { location.y = 100; }
			if (location.y < 0 && location.y > -100) { location.y = -100; }
			if (next.y > 0 && next.y < 100) { next.y = 100; }
			if (next.y < 0 && next.y > -100) { next.y = -100; }

			ofSetColor(0, ofMap(k, 0, 10, 0, 255));
			ofDrawLine(location, next);
		}

		
	}

	ofSetColor(0);
	ofSetLineWidth(1.5);
	ofDrawBox(glm::vec3(0, 110, 0), 241, 21, 241);
	ofDrawBox(glm::vec3(0, -110, 0), 241, 21, 241);

	this->cam.end();

	/*
	int start = 250;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}