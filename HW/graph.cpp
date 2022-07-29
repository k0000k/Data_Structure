#include "graph.h"

using namespace std;

void Graph::LoadMatrix(string &filename)
{
	ifstream ifs;
	ifs.open(filename);

	if (ifs.is_open())
	{
		bool first = true;
		while (!ifs.eof())
		{
			string str;
			int temp_num;
			vector<int> temp;
			getline(ifs, str);
			stringstream stream(str);

			while (stream >> temp_num)
			{
				if (first == true)
				{
					n = temp_num;
				}
				else
				{
					temp.push_back(temp_num);
				}
			}
			if (first == true)
			{
				first = false;
			}
			else
			{
				graph.push_back(temp);
			}
		}
		ifs.close();
	}
}

int Graph::GetSize()
{
	return n;
}

void Graph::PrintMatrix()
{
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = 0; j <= n - 1; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

int choose(int n, vector<int> dist, vector<bool> visited)
{
	int result = 0;
	int min = 999;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false && min >= dist[i])
		{
			min = dist[i];
			result = i;
		}
	}

	return result;
}

void Graph::PrintShortestPathWeight(int s)
{
	vector<int> dist;
	vector<bool> visited;

	for (int i = 0; i < n; i++)
	{
		visited.push_back(false);
		dist.push_back(graph[s][i]);
	}

	visited[s] = true;
	dist[s] = 0;

	for (int i = 0; i < n - 2; i++)
	{

		int u = choose(n, dist, visited);
		visited[u] = true;

		for (int j = 0; j < n; j++)
		{
			if (visited[j] == false && dist[u] + graph[u][j] < dist[j])
			{
				dist[j] = dist[u] + graph[u][j];
			}
		}
	}

	for (int k = 0; k < n; k++)
	{
		cout << dist[k] << endl;
	}
}

void trace_path(vector<int> from, vector<int> &path, int i, int s)
{
	if (i == s)
	{
		path.push_back(s);
		return;
	}

	path.push_back(from[i]);
	return trace_path(from, path, from[i], s);
}

void Graph::PrintShortestPath(int s)
{
	vector<int> dist;
	vector<bool> visited;

	vector<int> from;

	for (int i = 0; i < n; i++)
	{
		from.push_back(s);
	}

	for (int i = 0; i < n; i++)
	{
		visited.push_back(false);
		dist.push_back(graph[s][i]);
	}

	visited[s] = true;
	dist[s] = 0;

	for (int i = 0; i < n - 2; i++)
	{

		int u = choose(n, dist, visited);
		visited[u] = true;

		for (int j = 0; j < n; j++)
		{
			if (visited[j] == false && dist[u] + graph[u][j] < dist[j])
			{
				dist[j] = dist[u] + graph[u][j];
				from[j] = u;
			}
		}
	}

	for (int i = 1; i < n; i++)
	{
		vector<int> path;
		path.push_back(i);
		trace_path(from, path, i, s);

		for (int j = path.size() - 2; j >= 0; j--)
		{
			cout << path[j] << " ";
		}
		cout << endl;
	}
}
