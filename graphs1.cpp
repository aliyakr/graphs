#include <iostream>
#include <ctime>
#include <queue>

using namespace std;

//queue <int> turn;//Это наша очередь, хранящая номера вершин
//int used[6];//массив, хранящий состояние вершины("сгорела","не сгорела")


int FillMatrix(int matr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matr[i][j] = rand() % 2;
		}
	}
	return matr[2][2];
}

	int MinPath(int a1, int a2, int matr[3][3])
	{
    queue <int> turn;
		int used[3];
		for (int i = 0; i < 3; i++)
		{
			used[i] = -1;
		}
		turn.push(a1);
		used[0] = a1;

		int count = 0;
		int min = -1;


    while(!turn.empty()){
		for (int k = 0; k < 3; k++){
      
			int ind = turn.front();
			
			for (int i = 0; i < 3; i++) {
				if ((ind == used[i]) and (k != 0))
				{
					turn.pop();
					ind = turn.front();
					i = 0;
				}
			}

			used[k] = ind;
			turn.pop();//удаляем его
       int c = 0;
			for (int i = 0; i < 3; i++)//смотрим, с какими вершинами смежна вершина ind
			{
				if ((matr[ind][i] == 1)&(ind != i))
				{
          
					if (i == a2)
					{
						min = count + 1;
						return min;
					}
						turn.push(i);//добавляем в очередь вершину i
            c++;
					
				}
			}
      if (c == 0)
      {
        cout << "no path" << endl;
        break;
      }

      count++;

		 }
    }
  
		
		return min;

	}

 int MaxPath(int a1, int a2, int matr[3][3])
	{
    queue <int> turn;
		int used[3];
		for (int i = 0; i < 3; i++)
		{
			used[i] = -1;
		}
		turn.push(a1);
		used[0] = a1;

		int count = 0;
		int max = -1;

		for (int k = 0; k < 3; k++){
      

			int ind = turn.front();
      if (ind == a2)
      {
        turn.pop();
          if (turn.empty())
          {
            return max;
          }
          else {
        ind = turn.front();
          }
      }
			
			for (int i = 0; i < 3; i++) {

        
				if (((ind == used[i]) and (k != 0)) | (ind == a2))
				{
					turn.pop();
          if (turn.empty())
          {
            return max;
          }
          else{
					ind = turn.front();
					i = 0;
          }
				}
			}

			used[k] = ind;
			turn.pop();//удаляем его
       int c = 0;
			for (int i = 0; i < 3; i++)//смотрим, с какими вершинами смежна вершина ind
			{
				if ((matr[ind][i] == 1)&(ind != i))
				{
          
					if (i == a2)
					{
						max = count + 1;
					}
						turn.push(i);//добавляем в очередь вершину i
            c++;
					
				}
			}
      if (c == 0)
      {
        cout << MinPath(a1, a2, matr) << endl;
        break;
      }

      count++;

		 }
    
		
		return max;

	}
	
	


int main()
{
	setlocale(LC_ALL, "Russian");

  srand(time(0));
		int m[3][3];
		FillMatrix(m);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << m[i][j] << "\t";
			}
			cout << endl;
		}
	
	int a1, a2;
	cout << "Find min and max from ";
	cin >> a1;
	cout << " to ";
	cin >> a2;

	if ((a1 > 2) | (a2 > 2) | (a1 < 0) | (a2 < 0))
	{
		cout << "Try another time \n";
		exit(1);
	}

	cout << "Min path: " << MinPath(a1, a2, m) << endl;
  cout << "Max path: " << MaxPath(a1, a2, m) << endl;


	return 0;
}

