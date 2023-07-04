// See https://aka.ms/new-console-template for more information

using System;
using System.Windows.Forms;

/*
class MyForm : System.Windows.Forms.Form
{
}

namespace SimpleWindow
{
    class MainApp
    {
        static void Main(string[] args)
        { 
            //System.Windows.Forms.Application.Run(new MainApp());
            MyForm form = new MyForm();
            form.Click += new EventHandler(
                (sender, EventArgs) =>
                {
                    Application.Exit();
                }
                );
            Application.Run(form);
        }
    }
}
*/

namespace UsingApplication
{
    class MainApp : Form
    {
        static void Main(string[] args)
        {
            MainApp form = new MainApp();
            int clickCount = 0;
            form.Click += new EventHandler(
                (sender, events) =>
                {
                    clickCount++;
                    Console.WriteLine($"Click! Window... {clickCount}");
                    //Application.Exit();
                }
                );
            form.DoubleClick += new EventHandler(
                (sender, e) => 
                {
                    Console.WriteLine("double Click ! window Close !!");
                    Application.Exit();
                }
                );

            Console.WriteLine("Starting Window Application...");
            Application.Run(form);
            Console.WriteLine("Exiting Window Application...");
        }        
    }
}