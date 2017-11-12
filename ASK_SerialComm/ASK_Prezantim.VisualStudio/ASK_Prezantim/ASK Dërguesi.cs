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

namespace ASK_Prezantim
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            getAvailablePorts();
        }

        void getAvailablePorts()
        {
            String[] ports = SerialPort.GetPortNames();
            comboBox1.Items.AddRange(ports);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (comboBox1.Text == "")
            {
                MessageBox.Show("Nuk e keni zgjedhur portin");
            }
            else
            {
                serialPort1.PortName = comboBox1.Text;
                serialPort1.Open();
                button1.Enabled = true;
                button2.Enabled = false;
                button3.Enabled = true;
                textBox1.Enabled = true;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            serialPort1.Close();
            button1.Enabled = false;
            button2.Enabled = true;
            button3.Enabled = false;
            textBox1.Enabled = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox2.Text = Convert.ToString(textBox1.TextLength);
            textBox3.Text = Convert.ToString(textBox1.TextLength * 8);
            textBox4.Text = Convert.ToString(textBox1.TextLength * 2);
            serialPort1.WriteLine(textBox1.Text + ".");
            textBox1.Text = "";
        }
    }
}
