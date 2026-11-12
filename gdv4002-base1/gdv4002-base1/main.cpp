#include "Engine.h"


// Function prototypes


// Global Variables


int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		fprintf(stderr, "Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	//
	// Setup game scene objects here
	//

	GameObject2D* player1 = addObject("player1", glm::vec2(1.0f, 1.0f));
	GameObject2D* player2 = addObject("player2", glm::vec2(-1.0f, -1.0f));

	player1->size = glm::vec2(0.25f, 0.25f);
	player2->size = glm::vec2(0.25f, 0.25f);

	TextureProperties prop;
	player1->textureID = fiLoadTexture("Resources\\Textures\\player1_ship.png", prop.NearestFilterTexture());
	player2->textureID = fiLoadTexture("Resources\\Textures\\player1_ship.png", prop.NearestFilterTexture());

	GameObject2D* player1Object = getObject("player1");
	GameObject2D* player2Object = getObject("player2");
	
	//
	// Set callback functions
	//
	

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}
