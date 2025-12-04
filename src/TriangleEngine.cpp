#include <pch.h>

int main() {
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
		printf("Failed to initialize SDL3.");
		return 1;
	};

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

	const char* title = "Triangle Engine";
	u32 width = 800;
	u32 height = 600;

	SDL_Window* window = SDL_CreateWindow(title, width, height, SDL_WINDOW_OPENGL);

	if (!window) {
		printf("Failed to create SDL3 Window.");
		return 1;
	}

	SDL_GL_CreateContext(window);


	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		printf("Failed to initialize GLAD");
		return 1;
	}

	bool running = true;
	SDL_Event event;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
				running = false;
			}
		}
	}

	return 0;
}