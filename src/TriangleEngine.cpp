#include <SDL3/SDL.h>
#include <stdio.h>
#include <glad/glad.h>
#include <Defines.h>
#include <Math/Triangle3D.h>
#include <Math/Vector3.h>

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

	Vector3 p1 = Vector3();
	Vector3 p2 = Vector3(-1.0f, 0.0f, 0.0f);
	Vector3 p3 = Vector3(0.0f, 1.0f, 0.0f);
	Triangle3D t(p1, p2, p3);
	Vector2 uv = t.get_uv_coords(Vector3(-0.5f, 1.0f, 0.0f));

	printf("U: %f, V: %f", uv.x, uv.y);


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