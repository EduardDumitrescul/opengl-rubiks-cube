#include "01-01-square/square-app.h"

int main(int argc, char* argv[]) {
	SquareApp* squareApp = SquareApp::getInstance();
	squareApp->run(argc, argv);
}

