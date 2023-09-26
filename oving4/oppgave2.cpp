#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    Gtk::Box box;
    Gtk::Label firstname_label;
    Gtk::Entry firstname;
    Gtk::Label lastname_label;
    Gtk::Entry lastname;
    Gtk::Button button;
    Gtk::Label label;

    Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
        button.set_label("Combine names");
        firstname_label.set_text("First name");
        lastname_label.set_text("Last name");
        box.pack_start(firstname_label);
        box.pack_start(firstname);
        box.pack_start(lastname_label);
        box.pack_start(lastname);
        box.pack_start(button);
        box.pack_start(label);

        add(box);   // Add vbox to window
        show_all(); // Show all widgets

        button.signal_clicked().connect([this]() {
            if (!firstname.get_text().empty() && !lastname.get_text().empty()) {
                label.set_text("Names combined: "+ firstname.get_text() + " " + lastname.get_text());
            } else {
                label.set_text("No names given.");
            }
        });
    }
};

int main() {
    auto app = Gtk::Application::create();
    Window window;
    return app->run(window);
}
