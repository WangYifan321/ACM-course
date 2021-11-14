//优化后的非常可乐代码
#include <stdio.h>
#include <queue>
  using namespace std;
  struct State
  {
      int v[3];
      int step; //because this step of pre and cur are maybe the same
  };
  int volume[3];
 int BFS()
 {
       int map[105][105] = {0};  //initialize and for mark
     queue<State> q;
     State cur, pre;
     int i, j;
     //initialize the node and push it into the queue
     cur.v[0] = volume[0];
     cur.v[1] = 0;
     cur.v[2] = 0;
     cur.step = 0;
     q.push(cur);
     map[0][0] = 1;
     while (!q.empty())
     {
         pre = q.front();
         q.pop();
         //printf("\nstep = %d\n", pre.step);
         //printf("pre: %d %d %d\n", pre.v[0], pre.v[1], pre.v[2]);
         /*
         v[i] -> v[j], when v[i] have water
         we should consider that when u pull water from v[i] to v[j], v[j] maybe will arive the volume
         */
         for (i = 0; i < 3 && pre.v[i] > 0; i++)
         {
             for (j = 0; j < 3; j++)
             {
                 if (i != j)
                 {
                     cur = pre;
                     cur.step = pre.step + 1;
                     //when v[j] arrive its volume
                     if (cur.v[i] + cur.v[j] < volume[j])
                     {
                         cur.v[j] = cur.v[i] + cur.v[j];
                         cur.v[i] = 0;
                     }
                     else
                     {
                         cur.v[i] = cur.v[i] - (volume[j] - cur.v[j]);
                         cur.v[j] = volume[j];
                     }
                     //judge whether u have traversed the state
                     if (map[cur.v[1]][cur.v[2]] == 0)
                     {
                         if (cur.v[0] == volume[0] / 2 && cur.v[1] == volume[0] / 2)
                             return cur.step;
                         q.push(cur);
                         //printf("cur: %d %d %d\n", cur.v[0], cur.v[1], cur.v[2]);
                         map[cur.v[1]][cur.v[2]] = 1;
                     }
                 }
             }
         }
     }
     return 0;
 }
 int main()
 {
     int result;
     while (scanf("%d %d %d", &volume[0], &volume[1], &volume[2]) != EOF && (volume[0] || volume[1] || volume[2]))
     {
         if (volume[1] < volume[2])
         {
             int temp = volume[1];
             volume[1] = volume[2];
             volume[2] = temp; 
         }
         result = BFS();
         if (volume[0] % 2 != 0)
             puts("NO");
         else if (result == 0)
             puts("NO");
         else
             printf("%d\n", BFS());
     }
     return 0;
 }