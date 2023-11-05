using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Collection;

interface ILab8QueuePartBasicLevel
{
    public int A { get; set; }
    public int B { get; set; }
    public int C { get; set; }

    /// <summary>
    /// Method returns list of elements, that can be divided by A, B or C in ascending order
    /// </summary>
    /// <param name="N">Lenght of sequence (number of elements)</param>
    /// <returns>List of elements, that can be divided by A, B or C in ascending order</returns>
    public List<int> GetSequence(int N);
}

public class CombinationsQueue : ILab8QueuePartBasicLevel
{
    private Queue<int> queue;

    public int A { get; set; }
    public int B { get; set; }
    public int C { get; set; }


    public CombinationsQueue(int a, int b, int c)
    {
        A = a; B = b; C = c; queue = new Queue<int>();
    }

    public List<int> GetSequence(int N)
    {

        for (int i = 1; queue.Count < N; i++)
        {
            if (IsDivisibleByABS(i))
            {
                queue.Enqueue(i);
            }
            
        }
       
        return queue.ToList();
    }

    private bool IsDivisibleByABS(int number)
    {
        return number % A == 0 || number % B == 0 || number % C == 0;
    }
}