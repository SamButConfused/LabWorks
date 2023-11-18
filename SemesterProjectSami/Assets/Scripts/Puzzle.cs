using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public static class StepCounter
{
    public static int sc = 0;
}

public class Puzzle : MonoBehaviour
{
    public int ID; // the number must correspond to this "bone"

    public void Awake() => GetComponent<BoxCollider2D>().enabled = true;

    // the current and empty cell are interchanged
    private void replaceBlocks(int x, int y, int XX, int YY)
    {
        StepCounter.sc++;
        GameObject.FindGameObjectWithTag("stepCounter").GetComponent<UnityEngine.UI.Text>().text = "Score: " + StepCounter.sc.ToString();

        GameController.grid[x, y].transform.position = GameController.position[XX, YY];
        GameController.grid[XX, YY] = GameController.grid[x, y];
        GameController.grid[x, y] = null;
        GameController.GameFinish();
    }

    void OnMouseDown() // this is retarded
    {
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                if (GameController.grid[x, y])
                {
                    if (GameController.grid[x, y].GetComponent<Puzzle>().ID == ID)
                    {
                        if (y > 0 && GameController.grid[x, y - 1] == null)
                        {
                            replaceBlocks(x, y, x, y - 1);
                        }
                        else if (y < 3 && GameController.grid[x, y + 1] == null)
                        {
                            replaceBlocks(x, y, x, y + 1);
                        }

                        if (x > 0 && GameController.grid[x - 1, y] == null)
                        {
                            replaceBlocks(x, y, x - 1, y);
                        }
                        else if (x < 3 && GameController.grid[x + 1, y] == null)
                        {
                            replaceBlocks(x, y, x + 1, y);
                        }

                        return;
                    }
                }
            }
        }
    }
}
