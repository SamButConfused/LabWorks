using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameController : MonoBehaviour
{
    public GameObject[] cells;
    private GameObject[] random_cells;
    private GameObject[] r_cells;
    private int[,] r_grid;
    public static GameObject[,] grid;
    public static Vector3[,] position;
    public int[] checkmas;

    public float startPosX;
    public float startPosY;
    public float offsetX;
    public float offsetY;

    private int sum = 0;
    private int zero = 0;
    private int h;
    private int v;

    private static GameObject txt;
    private Component[] boxes;
    private Component[] p_script;

    void Start()
    {
        r_grid = new int[4, 4];
        txt = GameObject.FindGameObjectWithTag("congratulations");
        boxes = GetComponentsInChildren<BoxCollider2D>();
        p_script = GetComponentsInChildren<Puzzle>();
        checkmas = new int[16];
        random_cells = new GameObject[cells.Length];
        r_cells = new GameObject[cells.Length];
        float posXreset = startPosX;
        position = new Vector3[4, 4];

        for (int y = 0; y < 4; y++)
        {
            startPosY -= offsetY;
            for (int x = 0; x < 4; x++)
            {
                startPosX += offsetX;
                position[x, y] = new Vector3(startPosX, startPosY, 0);
            }
            startPosX = posXreset;

        }

        randomPuzzle(true);
    }

    void Update()
    {

    }

    public void StartNewGame()
    {
        txt.GetComponent<Text>().color = new Color(0, 0, 0, 0);
        randomPuzzle(true);
    }

    public void ExitGame()
    {
        Application.Quit();
    }

    public void possibility(int[] mas) // number is even - has solution odd - no solution
    {
        for (int i = 0; i < 16; i++)
        {
            if (mas[i] == 0)
            {
                zero = i / 4 + 1;
            }
            else
                for (int k = i; k < 16; k++)
                {
                    if (mas[i] > mas[k] && mas[k] != 0)
                    {
                        sum++;
                    }
                }
        }

        if ((zero + sum) % 2 != 0) // if no solution, recreate puzzle
        {
            createPuzzle();
        }
    }

    void createPuzzle()
    {
        if (transform.childCount > 0)
        {
            for (int j = 0; j < transform.childCount; j++)
            {
                Destroy(transform.GetChild(j).gameObject);
            }
        }

        int i = 0;
        int ii = 0; // i really need to work on my variable names
        grid = new GameObject[4, 4];
        h = Random.Range(0, 3);
        v = Random.Range(0, 3);

        GameObject clone = new GameObject();
        grid[h, v] = clone; // place empty object in a random cell

        float posXreset = startPosX;

        for (int y = 0; y < 4; y++)
        {

            for (int x = 0; x < 4; x++)
            {

                if (grid[x, y] == null)
                {
                    startPosX += offsetX;
                    grid[x, y] = Instantiate(random_cells[i], position[x, y], Quaternion.identity) as GameObject;
                    grid[x, y].name = "ID-" + i;
                    checkmas[ii] = grid[x, y].GetComponent<Puzzle>().ID;
                    grid[x, y].transform.parent = transform;
                    i++;
                    ii++;
                }
                else
                {
                    checkmas[ii] = 0;
                    ii++;
                }
            }
        }

        foreach (BoxCollider2D box2d in boxes)
            box2d.enabled = true;
        foreach (Puzzle puz in p_script)
            puz.enabled = true;

        Destroy(clone);
        for (int q = 0; q < cells.Length; q++)
        {
            Destroy(random_cells[q]);
        }

        possibility(checkmas);
    }

    void randomPuzzle(bool r_s)
    {
        if (r_s == true)
        {
            int[] tmp = new int[cells.Length];

            for (int i = 0; i < cells.Length; i++)
            {
                tmp[i] = 1;
            }

            int c = 0;
            while (c < cells.Length)
            {
                int r = Random.Range(0, cells.Length);
                if (tmp[r] == 1)
                {
                    random_cells[c] = Instantiate(cells[r], new Vector3(0, 10, 0), Quaternion.identity) as GameObject;
                    r_cells[c] = random_cells[c];
                    tmp[r] = 0;
                    c++;
                }
            }
        }

        createPuzzle();
    }

    static public void GameFinish()
    {
        int i = 1;
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                if (grid[x, y] && grid[x, y].GetComponent<Puzzle>().ID == i)
                    i++;
                else
                    i--;
            }
        }

        if (i == 15)
        {
            for (int y = 0; y < 4; y++)
            {
                for (int x = 0; x < 4; x++)
                {
                    if (grid[x, y])
                        Destroy(grid[x, y].GetComponent<Puzzle>());
                }
            }

            txt.GetComponent<Text>().color = new Color(0, 0, 0, 1);
            Debug.Log("Game ended!");
        }
    }
}
