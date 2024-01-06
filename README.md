# Nonogram Checker

The functions for this problem can be found in `functii_nomogram.c`.

## Input

- Read the number of rows and columns.
- Start reading instructions for rows and columns as follows:
  - In `nr_grupuri_l[]`, the number of groups for each row
  - In `linii[][]`, the dimensions of the groups for each row
  - In `nr_grupuri_c[]`, the number of groups for each column
  - In `coloane[][]`, the dimensions of the groups for each column
- After that, read the matrix `grid[][]`.

## Verification (Function: `verif()`)

- **Verification for Rows:**
  - Traverse the matrix elements row by row. For each row:
    - When encountering the value `1`, increment the `dimensiune` variable to keep track of the size of the group of 1s.
    - Upon encountering a zero, check if the size of the group matches the size read from the keyboard and stored in `linii[][]`.
    - After finishing a row, check if the row ends with 1. If it does, consider that an additional group is created.
    - Finally, verify if the number of groups corresponds.

- **Verification for Columns:**
  - Similar to the process for rows.

- **Return Values:**
  - If the function fails any check, it returns `0` (indicating an incorrect grid).
  - If the function passes all tests, it returns `1` (indicating a correct grid).

## Output

- If the function returns `1`, the grid is correct, and we print "Correct".
- If the function returns `0`, indicating an incorrect grid, we print "Error".## Example Usage
