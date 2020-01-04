#include "Fenetre.hh"

Fenetre::Fenetre(): background("back.jpg"),choix1("choix1"),choix2("choix2"),choix3("choix3"),boiteV(false,0),boiteH(true){
  set_title("Smoke Wars");
  set_icon_from_file("icon.jpeg");
  resize(1080, 608);
  set_position(Gtk::WIN_POS_CENTER);

  //Gtk::VBox boiteV(false,10);
  boiteV.pack_start(background);
  //Gtk::HBox boiteH(true);
  boiteV.pack_end(boiteH);
  boiteH.pack_start(choix1);
  boiteH.pack_start(choix2);
  boiteH.pack_start(choix3);

  add(boiteV);

  show_all();

}
