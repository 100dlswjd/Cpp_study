// See https://aka.ms/new-console-template for more information

using Microsoft.VisualBasic;
using System;
using System.Windows.Forms;

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