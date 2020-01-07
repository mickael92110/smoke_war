#include "Fenetre.hh"







//Exemple fenetre pop-up

// ExampleWindow::ExampleWindow()
// : m_ButtonBox(Gtk::ORIENTATION_VERTICAL),
//   m_Button_Info("Show Info MessageDialog"),
//   m_Button_Question("Show Question MessageDialog")
// {
//   set_title("Gtk::MessageDialog example");
//
//   add(m_ButtonBox);
//
//   m_ButtonBox.pack_start(m_Button_Info);
//   m_Button_Info.signal_clicked().connect(sigc::mem_fun(*this,
//               &ExampleWindow::on_button_info_clicked) );
//
//   m_ButtonBox.pack_start(m_Button_Question);
//   m_Button_Question.signal_clicked().connect(sigc::mem_fun(*this,
//               &ExampleWindow::on_button_question_clicked) );
//
//   show_all_children();
// }
//
// ExampleWindow::~ExampleWindow()
// {
// }
//
// void ExampleWindow::on_button_info_clicked()
// {
//   Gtk::MessageDialog dialog(*this, "This is an INFO MessageDialog");
//   dialog.set_secondary_text(
//           "And this is the secondary text that explains things.");
//
//   dialog.run();
// }
//
// void ExampleWindow::on_button_question_clicked()
// {
//   Gtk::MessageDialog dialog(*this, "This is a QUESTION MessageDialog",
//           false /* use_markup */, Gtk::MESSAGE_QUESTION,
//           Gtk::BUTTONS_OK_CANCEL);
//   dialog.set_secondary_text(
//           "And this is the secondary text that explains things.");
//
//   int result = dialog.run();
//
//   //Handle the response:
//   switch(result)
//   {
//     case(Gtk::RESPONSE_OK):
//     {
//       std::cout << "OK clicked." << std::endl;
//       break;
//     }
//     case(Gtk::RESPONSE_CANCEL):
//     {
//       std::cout << "Cancel clicked." << std::endl;
//       break;
//     }
//     default:
//     {
//       std::cout << "Unexpected button clicked." << std::endl;
//       break;
//     }
//   }
// }



//Exemple zone de texte

ExampleWindow::ExampleWindow()
: m_VBox(Gtk::ORIENTATION_HORIZONTAL,30),
  m_Button_Quit("_Quit", true),
  m_Button_Buffer1("Naruto"),
  m_Button_Buffer2("Sasuke"),
  m_Button_Buffer3("Sakura"),
  m_Button_Buffer4("Kakashi")
{
  set_title("Smoke Wars");
  set_border_width(5);
  set_default_size(900, 800);

  add(m_VBox);

  //Add the TreeView, inside a ScrolledWindow, with the button underneath:
  m_ScrolledWindow.add(m_TextView);

  m_VBox.pack_start(m_ButtonBox1, Gtk::PACK_SHRINK);

  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  m_VBox.pack_start(m_ScrolledWindow);

  //Add buttons:
  m_VBox.pack_start(m_ButtonBox2, Gtk::PACK_SHRINK);

  m_ButtonBox1.pack_start(m_Button_Buffer1, Gtk::PACK_SHRINK);
  m_ButtonBox1.pack_start(m_Button_Buffer2, Gtk::PACK_SHRINK);
  m_ButtonBox1.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);

  m_ButtonBox2.pack_start(m_Button_Buffer3, Gtk::PACK_SHRINK);
  m_ButtonBox2.pack_start(m_Button_Buffer4, Gtk::PACK_SHRINK);

  m_ButtonBox1.set_border_width(5);
  m_ButtonBox1.set_spacing(5);
  m_ButtonBox1.set_layout( Gtk::BUTTONBOX_SPREAD);
  m_ButtonBox1.set_orientation(Gtk::ORIENTATION_VERTICAL);

  m_ButtonBox2.set_border_width(5);
  m_ButtonBox2.set_spacing(5);
  m_ButtonBox2.set_layout( Gtk::BUTTONBOX_SPREAD);
  m_ButtonBox2.set_orientation(Gtk::ORIENTATION_VERTICAL);


  //Connect signals:
  m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_button_quit) );
  m_Button_Buffer1.signal_clicked().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_button_buffer1) );
  m_Button_Buffer2.signal_clicked().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_button_buffer2) );
  m_Button_Buffer3.signal_clicked().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_button_buffer3) );
  m_Button_Buffer4.signal_clicked().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_button_buffer4) );

  fill_buffers();
  //on_button_buffer1();
  show_all_children();
}

void ExampleWindow::fill_buffers()
{
  m_refTextBuffer1 = Gtk::TextBuffer::create();
  m_refTextBuffer1->set_text("Hi, I'm Naruto");

  m_refTextBuffer2 = Gtk::TextBuffer::create();
  m_refTextBuffer2->set_text("Hi, I'm Sasuke");

  m_refTextBuffer3 = Gtk::TextBuffer::create();
  m_refTextBuffer3->set_text("Hi, I'm Sakura");

  m_refTextBuffer4 = Gtk::TextBuffer::create();
  m_refTextBuffer4->set_text("Hi, I'm Kakasi");

}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_button_quit()
{
  hide();
}

void ExampleWindow::on_button_buffer1()
{
  m_TextView.set_buffer(m_refTextBuffer1);
}

void ExampleWindow::on_button_buffer2()
{
  m_TextView.set_buffer(m_refTextBuffer2);
}

void ExampleWindow::on_button_buffer3()
{
  m_TextView.set_buffer(m_refTextBuffer3);
}

void ExampleWindow::on_button_buffer4()
{
  m_TextView.set_buffer(m_refTextBuffer4);
}
