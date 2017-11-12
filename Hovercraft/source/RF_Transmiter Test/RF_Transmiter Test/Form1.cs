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

namespace RF_Transmiter_Test
{
    public partial class Form1 : Form
    {
        String Mesazhi;
        private SerialPort Porti;
        public Form1()
        {
            InitializeComponent();
            init();
        }

        private void Ndizu_Click(object sender, EventArgs e)
        {
            Porti.WriteLine("Ngritu.");
            Mesazhi = "Ngritu";
            Teksti();
        }

        private void Ndalu_Click(object sender, EventArgs e)
        {
            Porti.WriteLine("Ulu.");
            Mesazhi = "Ulu";
            Teksti();
        }

        private void init ()
        {
            try
            {
                Porti = new SerialPort();
                Porti.BaudRate = 9600;
                Porti.PortName = "COM5";
                Porti.Open();
            }
            catch (Exception)
            {
                MessageBox.Show("Porti i zgjedhur gabim");
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Porti.WriteLine("Para.");
            Mesazhi = "Para";
            Teksti();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Porti.WriteLine("Ndalu.");
            Mesazhi = "Ndalu";
            Teksti();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Porti.WriteLine("Majtas.");
            Mesazhi = "Majtas";
            Teksti();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Porti.WriteLine("Djathtas.");
            Mesazhi = "Djathtas";
            Teksti();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Porti.WriteLine("Drejt.");
            Mesazhi = "Drejt";
            Teksti();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Porti.WriteLine("En.");
            Mesazhi = "Startim komunikimi";
            Teksti();
        }
        private void Teksti()
        {
            try
            {
                textBox1.Text = Mesazhi;
            }
            catch (TimeoutException)
            {
                textBox1.Text = "Timeour";
            }
        }

        private void textBox2_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Q)
            {
                Porti.WriteLine("Ngritu.");
                Mesazhi = "Ngritu";
                Teksti();
            }
            if (e.KeyCode == Keys.W)
            {
                Porti.WriteLine("Para.");
                Mesazhi = "Para";
                Teksti();
            }
            if (e.KeyCode == Keys.E)
            {
                Porti.WriteLine("Ulu.");
                Mesazhi = "Ulu";
                Teksti();
            }
            if (e.KeyCode == Keys.A)
            {
                Porti.WriteLine("Majtas.");
                Mesazhi = "Majtas";
                Teksti();
            }
            if (e.KeyCode == Keys.S)
            {
                Porti.WriteLine("Drejt.");
                Mesazhi = "Drejt";
                Teksti();
            }
            if (e.KeyCode == Keys.D)
            {
                Porti.WriteLine("Djathtas.");
                Mesazhi = "Djathtas";
                Teksti();
            }
            if (e.KeyCode == Keys.V)
            {
                Porti.WriteLine("Ndalu.");
                Mesazhi = "Ndalu";
                Teksti();
            }
        }
    }
}
