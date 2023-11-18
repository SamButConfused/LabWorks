using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CheckWin : MonoBehaviour
{
    private int sum = 0;
    private int zero = 0;
    int[] row_board = new int[16] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 14, 0 };

    public void Start()
    {
    }

    public int[] Shuffle(bool check) // if there is no solution in game, shuffle counts
    {
        int tmp;

        if (check) // TODO cleanup
        {
            return row_board;
        }
        else
        {
            for (int i = 15; i > 0; i--)
            {
                int j = Random.Range(0, 16);
                tmp = row_board[i];
                row_board[i] = row_board[j];
                row_board[j] = tmp;
            }

            return row_board;
        }
    }

    public void possibility(int[] mas) // check if player can win the game
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

        if ((zero + sum) % 2 == 0)
        {
            Debug.Log("There is a solution");
            Shuffle(true);
        }
        else
        {
            Debug.Log("There is no solution... Reshuffling... ");
            Shuffle(false);
        }
    }
}
