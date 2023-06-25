using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace Sudoku_Solver
{
    public partial class Form1 : Form
    {
        private readonly Random _r = new Random();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            dataGridView1.Rows.Add(9);
            dataGridView1.EditingControlShowing += dataGridView1_EditingControlShowing;

        }

        private void dataGridView1_EditingControlShowing(object sender, DataGridViewEditingControlShowingEventArgs e)
        {
            TextBox textBox = e.Control as TextBox;
            if (textBox != null)
            {
                textBox.KeyPress -= textBox_KeyPress;
                textBox.KeyPress += textBox_KeyPress;
            }
        }

        private void textBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            TextBox textBox = (TextBox)sender;

            // Check if the pressed key is not a numeric key (1 to 9)
            if (e.KeyChar < '1' || e.KeyChar > '9')
            {
                // Key pressed is not a numeric key (1 to 9)
                // Cancel the input by setting Handled property to true
                e.Handled = true;
            }
            else if (e.KeyChar == '\b' || e.KeyChar == 127) // Backspace or Delete character
            {
                textBox.Text = String.Empty;
            }
            else if (textBox.Text.Length >= 1)
            {
                // The cell already contains one character
                // Cancel the input by setting Handled property to true
                textBox.Text = e.KeyChar.ToString();
                e.Handled = true;
            }
            SendKeys.Send("{TAB}");
        }

        private void btnNew_Click(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();
            dataGridView1.Rows.Add(9);
        }

        private void dataGridView1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawLine(new Pen(Color.Black, 2), 75, 0, 75, 228);
            e.Graphics.DrawLine(new Pen(Color.Black, 2), 152, 0, 152, 228);
            e.Graphics.DrawLine(new Pen(Color.Black, 2), 0, 75, 228, 75);
            e.Graphics.DrawLine(new Pen(Color.Black, 2), 0, 153, 228, 153);
        }

        private void btnSolution_Click(object sender, EventArgs e)
        {
            Solver solver = new Solver(dataGridView1);
            Cell[,] grid = solver.Solve();
            DisplaySolution(grid);
        }

        private void DisplaySolution(Cell[,] grid)
        {
            for (int x=0; x < 9; x++)
            {
                for (var y=0; y < 9; y++)
                {
                    dataGridView1.Rows[x].Cells[y].Value = grid[x, y].value;
                    if (grid[x, y].given)
                    {
                        dataGridView1.Rows[x].Cells[y].Style.ForeColor = Color.Black;
                    }
                    else
                    {
                        dataGridView1.Rows[x].Cells[y].Style.ForeColor = Color.Blue;
                    }
                }
            }
        }
    }
}