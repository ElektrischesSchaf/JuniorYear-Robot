using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
namespace _0306
{
    public partial class Form1 : Form
    {
        private SerialPort myport;
        public Form1()
        {
            InitializeComponent();
            init();
        }      
      
        private void init()
        {
            try
            {
                myport = new SerialPort();
                myport.BaudRate = 9600;
                myport.PortName = "COM4";
                myport.Open();
            }
            catch(Exception)
            {
                MessageBox.Show("Error");
            }         
        }                 

    
        private void press(object sender, KeyPressEventArgs e)
        {

            //connection test
            if (e.KeyChar == 'q' || e.KeyChar == 'Q')
            { myport.WriteLine("q"); }
            //the first link
            if (e.KeyChar == 'y' || e.KeyChar == 'Y')
            { myport.WriteLine("y"); }
            if (e.KeyChar == 'u' || e.KeyChar == 'U')
            { myport.WriteLine("u"); }

            //second link
            if (e.KeyChar == 'h' ||e.KeyChar=='H')
            { myport.WriteLine("h"); }
            if (e.KeyChar == 'j' ||e.KeyChar=='J')
            {myport.WriteLine("j");  }

            //third link
            if (e.KeyChar == 'n'||e.KeyChar=='N')
            {   myport.WriteLine("n");   }
            if (e.KeyChar=='m'||e.KeyChar=='M')
            { myport.WriteLine("m"); }

            //return origin
            if(e.KeyChar=='a'||e.KeyChar=='A')
            { myport.WriteLine("a"); }

            //the put slide
            if(e.KeyChar=='o'||e.KeyChar=='O')
            { myport.WriteLine("o"); }
            if(e.KeyChar=='p'||e.KeyChar=='P')
            { myport.WriteLine("p"); }
            if (e.KeyChar =='i'|| e.KeyChar == 'I')
            { myport.WriteLine("i"); }
            if (e.KeyChar == 'k' || e.KeyChar == 'K')
            { myport.WriteLine("k"); }
            if (e.KeyChar == 'l' || e.KeyChar == 'L')
            { myport.WriteLine("l"); } 
            //change speed
            if (e.KeyChar == 't' || e.KeyChar == 'T')
            { myport.WriteLine("t"); }
            if (e.KeyChar == 'g' || e.KeyChar == 'G')
            { myport.WriteLine("g"); }
            if (e.KeyChar == 'b' || e.KeyChar == 'B')
            { myport.WriteLine("b"); }

            //forward
            if (e.KeyChar == 'e' || e.KeyChar == 'E')
            { myport.WriteLine("e"); }
            //stop
            if (e.KeyChar == 'd' || e.KeyChar == 'D')
            { myport.WriteLine("d"); }
            //back
            if (e.KeyChar == 'c' || e.KeyChar == 'C')
            { myport.WriteLine("c"); }
            //left
            if (e.KeyChar == 's' || e.KeyChar == 'S')
            { myport.WriteLine("s"); }
            //right
            if (e.KeyChar == 'f' || e.KeyChar == 'F')
            { myport.WriteLine("f"); }
            if (e.KeyChar == 'w' || e.KeyChar == 'W')
            { myport.WriteLine("w");}
            if (e.KeyChar == 'r' || e.KeyChar == 'R')
            { myport.WriteLine("r"); }
            if (e.KeyChar == 'x' || e.KeyChar == 'X')
            { myport.WriteLine("x"); }
            if (e.KeyChar == 'v' || e.KeyChar == 'V')
            { myport.WriteLine("v"); }
           
            //
            if (e.KeyChar == 'z' || e.KeyChar == 'Z')
            { myport.WriteLine("z"); }
          
        }

        private void up(object sender, KeyEventArgs e)
        {
           // myport.WriteLine("0");
        }
    }
}
