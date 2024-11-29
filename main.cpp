#include "App.h"

int main(int argc, char* argv[]) {
	std::shared_ptr<App> app = App::getInstance();
	app->run(argc, argv);
}

