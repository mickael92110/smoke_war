#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <gtkmm.h>


class Fenetre : public Gtk::Window {
    public :
        Fenetre();
    private :
        // Gtk::Button bouton;
        Gtk::Image background;
        Gtk::Button choix1;
        Gtk::Button choix2;
        Gtk::Button choix3;
        Gtk::VBox boiteV;
        Gtk::HBox boiteH;

};

#endif
