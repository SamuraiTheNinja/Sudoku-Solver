using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sudoku_Solver
{
    internal class Solver
    {
        private Cell[,] grid;
        private readonly DataGridView dataGridView;

        public Solver(DataGridView dataGridView)
        {
            this.dataGridView = dataGridView;
            this.grid = new Cell[9, 9];
            BuildGrid();
            AssignCellRelatives();
            bool stophere = true;
        }

        private void AssignCellRelatives()
        {
            for (int x = 0; x < 9; x++)
            {
                for (int y = 0; y < 9; y++)
                {
                    for (int i = 0; i < 9; i++)
                    {
                        grid[x, y].row[i] = grid[x, i];
                        grid[x, y].col[i] = grid[i, y];
                    }
                    AssignSquare(x, y);
                }
            }
        }

        private void AssignSquare(int x, int y)
        {
            int starting_x = (x / 3) * 3;
            int starting_y = (y / 3) * 3;

            int index = 0;
            for (int i = starting_x; i < starting_x + 3; i++)
            {
                for (var j = starting_y; j < starting_y + 3; j++)
                {
                    grid[x, y].square[index] = grid[i, j];
                    index++;
                }
            }

        }

        private void BuildGrid()
        {
            int x = 0;
            foreach (DataGridViewRow row in dataGridView.Rows)
            {
                int y = 0;
                foreach (DataGridViewCell cell in row.Cells)
                {
                    try
                    {
                        grid[x, y] = new Cell(int.Parse(cell.Value.ToString()), true, new Point(x, y));
                    }
                    catch
                    {
                        grid[x, y] = new Cell(-1, false, new Point(x, y));
                    }
                    y++;
                }
                x++;
            }
        }

        private bool IsBoardSolved()
        {
            for (int x = 0; x < 9; x++)
            {
                for (int y = 0; y < 9; y++)
                {
                    if (grid[x, y].value == -1)
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        public Cell[,] Solve()
        {
            while (!IsBoardSolved())
            {
                for (int x = 0; x < 9; x++)
                {
                    for (int y = 0; y < 9; y++)
                    {
                        Cell cell = grid[x, y];
                        cell.SetAvailable();
                        cell.SolveByScanning();
                        cell.SolveByMissingNumbers();

                    }
                }
            }
            return grid;
        }
    }
}
