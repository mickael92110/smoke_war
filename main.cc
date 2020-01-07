#include "Fenetre.hh"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  ExampleWindow window;

  //Shows the window and returns when it is closed.
  return app->run(window);
}

// set_title("Smoke Wars");
// set_icon_from_file("icon.jpeg");
// set_border_width(10);
// resize(1080, 608);
// set_position(Gtk::WIN_POS_CENTER);
//
// //Gtk::VBox boiteV(false,10);
// boiteV.pack_start(background);
// //Gtk::HBox boiteH(true);
// boiteV.pack_end(boiteH);
// boiteH.pack_start(choix1);
// boiteH.pack_start(choix2);
// boiteH.pack_start(choix3);
//
// add(boiteV);
//
// show_all();
