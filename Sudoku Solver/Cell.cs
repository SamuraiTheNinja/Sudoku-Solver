using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sudoku_Solver
{
    internal class Cell
    {
        public Cell[] row;
        public Cell[] col;
        public Cell[] square;
        public string comment = string.Empty;
        public int value;
        public bool given;
        public List<int> available;
        public Point myLocation;

        public Cell(int value, bool given, Point myLocation)
        {
            this.value = value;
            this.given = given;
            row = new Cell[9];
            col = new Cell[9];
            square = new Cell[9];
            available = Enumerable.Range(1, 9).ToList();
            if (given)
                comment = $"{DateTime.Now} | Given";
            this.myLocation = myLocation;
        }

        public void SetAvailable()
        {
            if (value != -1)
            {
                available.Clear();
                return;
            }
            CheckNeighbors(row);
            CheckNeighbors(col);
            CheckNeighbors(square);
        }

        private void CheckNeighbors(Cell[] neighbors)
        {
            foreach (Cell cell in neighbors)
            {
                if (available.Contains(cell.value))
                {
                    available.Remove(cell.value);
                }
            }
        }

        public void SolveByScanning()
        {
            if (available.Count == 1)
            {
                value = available[0];
                available.Clear();
                comment = $"{DateTime.Now} | Solved by scanning";
            }
        }

        public void SolveByMissingNumbers()
        {
            CheckForMissingValues(square);
            CheckForMissingValues(row);
            CheckForMissingValues(col);
        }

        private void CheckForMissingValues(Cell[] neighbors)
        {
            List<int> valuesMissing = Enumerable.Range(1, 9).ToList();

            foreach (Cell cell in neighbors)
            {
                if (valuesMissing.Contains(cell.value))
                {
                    valuesMissing.Remove(cell.value);
                }
            }

            if (valuesMissing.Count >= 3)
                return;

            foreach (int missingValue in valuesMissing)
            {
                List<Cell> canHoldMissingValue = new List<Cell>();
                foreach (Cell cell in neighbors)
                {
                    if (cell.value == -1)
                        continue;
                    if (cell.available.Contains(missingValue))
                    {
                        canHoldMissingValue.Add(cell);
                    }
                }

                if (canHoldMissingValue.Count == 1)
                {
                    canHoldMissingValue[0].value = missingValue;
                    canHoldMissingValue[0].comment = $"{DateTime.Now} | Solved by checking for missing values";
                }
                    
            }
        }

        public void SolveByOnlyAvailable()
        {
            CheckIfOnlyAvailable(row);
            CheckIfOnlyAvailable(col);
            CheckIfOnlyAvailable(square);
        }

        private void CheckIfOnlyAvailable(Cell[] neighbors)
        {
            foreach (int numAvailable in available)
            {
                List<Cell> containsSameAvailableNumber = new List<Cell>();
                foreach (Cell cell in neighbors)
                {
                    if (cell.available.Contains(numAvailable))
                        containsSameAvailableNumber.Add(cell);
                }
                if (!containsSameAvailableNumber.Any())
                {
                    value = numAvailable;
                    comment = $"{DateTime.Now} | Solved by checking if only available number";
                    available.Clear();
                }    
            }
        }
    }
}
