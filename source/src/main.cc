#include <iostream>
#include <saucer/smartview.hpp>

int main() {
  auto app = saucer::application::init({
      // Instantiate application
      .id = "hello-world", // Choose a suitable ID for your program
  });

  saucer::smartview smartview{{
      // Instantiate smartview
      .application = app,
  }};

  smartview.set_title("Hello World!"); // Set the window title to "Hello World!"
  smartview.set_dev_tools(true);

  // Expose a synchronous native function "add_ten" using the default serializer
  smartview.expose("add_ten", [](int i) { return i + 10; });

  smartview.set_file("source/front-end/index.html");

  smartview.show();

  app->run();

  return 0;
}
